>Répertoire `thread`
## Exercice 1
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define GRANDE_BOUCLE 500000000L

void calcul() {
    volatile double x = 0.0;
    for (long i = 0; i < GRANDE_BOUCLE; i++) {
        x += i * 0.0000001;
    }
}

int main() {
    calcul();  // appel 1
    calcul();  // appel 2
    return 0;
}
```

```
gcc -O2 -o seq calcul.c
time ./seq

real    0m2.466s
user    0m2.892s
sys     0m0.000s
```

## Exercice 2
> Affichage des pairs et des impairs

```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 1000

void* afficher_pairs(void* arg) {
    for (int i = 0; i <= MAX; i += 2) {
        printf("Pair  : %d\n", i);
    }
    return NULL;
}

void* afficher_impairs(void* arg) {
    for (int i = 1; i < MAX; i += 2) {
        printf("Impair: %d\n", i);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Créer les threads
    pthread_create(&t1, NULL, afficher_pairs, NULL);
    pthread_create(&t2, NULL, afficher_impairs, NULL);

    // Attendre la fin des threads
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
```

```
gcc -pthread -o pairs_impairs pairs_impairs.c
```

>[!info] Remarque
>Pour faire en sorte que les nombres s'affichent dans l'ordre, on peut importer la bibliothèque `unistd` puis ajouter un `sleep(1)` dans chaque boucle pour que chaque thread est le temps d'afficher l'un après l'autre.

**ET SI ON LE FAISAIT AVEC MUTEX**
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 1000

pthread_mutex_t mutex;
pthread_cond_t cond;
int tour = 0; // 0 = pair, 1 = impair

void* afficher_pairs(void* arg) {
    for (int i = 0; i <= MAX; i += 2) {
        pthread_mutex_lock(&mutex);
        while (tour != 0) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("%d\n", i);
        tour = 1;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* afficher_impairs(void* arg) {
    for (int i = 1; i < MAX; i += 2) {
        pthread_mutex_lock(&mutex);
        while (tour != 1) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("%d\n", i);
        tour = 0;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&t1, NULL, afficher_pairs, NULL);
    pthread_create(&t2, NULL, afficher_impairs, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
```

**🔁 Cycle entre les deux threads :**
1. **Thread Pair** vérifie que c’est son tour (`tour == 0`)
    - Il affiche un nombre pair
    - Change `tour = 1` pour laisser la main à l’autre
    - Envoie le signal : `pthread_cond_signal(&cond)`
    - Libère le mutex
2. **Thread Impair** est en attente sur `pthread_cond_wait(&cond, &mutex)`
    - Le signal le réveille
    - Il reprend quand il peut regagner le mutex
    - Vérifie que c’est bien son tour (`tour == 1`)
    - Affiche un impair
    - Change `tour = 0` pour laisser la main au premier thread
    - Envoie le signal
    - Libère le mutex
3. *et ainsi de suite jusqu'à 1000 ici*

## 3. Modification d'une variable globale
On reprend celui que j'ai expliqué pendant le cours. 
$n$ threads incrémentent `nbMax` fois un compteur avec/sans mutex. On ne mettra la correction qu'avec MUTEX, la condition de course a été expliquée en cours.
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NB_THREADS 4
#define NB_INCREMENTS 100000

int compteur = 0;                    // Variable partagée
pthread_mutex_t mutex;              // Mutex pour protéger compteur

void* incrementer(void* arg) {
    int id = *((int*)arg);

    for (int i = 0; i < NB_INCREMENTS; i++) {
        pthread_mutex_lock(&mutex);   // Verrouillage
        compteur++;
        pthread_mutex_unlock(&mutex); // Déverrouillage
    }

    printf("Thread %d terminé\n", id);
    return NULL;
}

int main() {
    pthread_t threads[NB_THREADS];
    int ids[NB_THREADS];

    // Initialisation du mutex
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        perror("pthread_mutex_init");
        return 1;
    }

    // Création des threads
    for (int i = 0; i < NB_THREADS; i++) {
        ids[i] = i + 1;
        if (pthread_create(&threads[i], NULL, incrementer, &ids[i]) != 0) {
            perror("pthread_create");
            return 1;
        }
    }

    // Attente de la fin des threads
    for (int i = 0; i < NB_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destruction du mutex
    pthread_mutex_destroy(&mutex);

    printf("Compteur final attendu : %d\n", NB_THREADS * NB_INCREMENTS);
    printf("Compteur final obtenu  : %d\n", compteur);

    return 0;
}
```

## 4. Division des tâches
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define N 100000000      // 10000 x 10000
#define NB_THREADS 4

int* mat; // Matrice à 1 dimension

typedef struct {
    int start;
    int end;
} ThreadArgs;

void* compter_zero(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;
    int* compteur = malloc(sizeof(int));
    *compteur = 0;

    for (int i = args->start; i < args->end; i++) {
        if (mat[i] == 0) (*compteur)++;
    }

    pthread_exit((void*)compteur);
}

int main() {
    pthread_t threads[NB_THREADS];
    ThreadArgs args[NB_THREADS];
    int taille_bloc = N / NB_THREADS;

    // Allocation de la matrice
    mat = malloc(N * sizeof(int));
    if (!mat) {
        perror("malloc");
        return 1;
    }

    // Remplissage aléatoire entre 0 et 4
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        mat[i] = rand() % 5;
    }

    // Lancement des threads
    for (int i = 0; i < NB_THREADS; i++) {
        args[i].start = i * taille_bloc;
        args[i].end = (i == NB_THREADS - 1) ? N : args[i].start + taille_bloc;
        pthread_create(&threads[i], NULL, compter_zero, &args[i]);
    }

    // Récupération des résultats
    int total_zeros = 0;
    for (int i = 0; i < NB_THREADS; i++) {
        int* count;
        pthread_join(threads[i], (void**)&count);
        total_zeros += *count;
        free(count);
    }

    printf("Nombre total de zéros : %d\n", total_zeros);
    free(mat);

    return 0;
}
```
