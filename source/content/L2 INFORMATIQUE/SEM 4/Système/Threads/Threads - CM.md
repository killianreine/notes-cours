# SYSTÈME D'EXPLOITATION - THREADS
>[!cite] Définitions
>- Un **==thread==**, c’est une suite d’instructions que l’ordinateur exécute étape par étape, à l’intérieur d’un programme. Un programme simple n’a qu’un seul thread.
>- On parle de **==programme multi-thread==** quand il utilise **au moins deux threads** qui peuvent fonctionner en même temps, chacun faisant une tâche différente.

Dans un programme multithread, l'exécution des threads peut être :
- Concurrente
  Lorsqu'on a plusieurs threads qui s'exécute en même temps, mais qu'en fait le processeur alterne entre les deux.
- Parallèle
  Lorsque les threads s'exécutent en même temps, chacun sur un cœur de processeur différent.

>[!info] Remarque
>Chaque thread d’un processus possède son propre contexte : son identifiant unique, sa pile d’exécution ou stack, son pointeur d’instruction, son registre de processeur. Mais comme tous les threads font partie du même processus, ils partagent le même espace d’adressage virtuel :
>- le même code,
>- les mêmes bibliothèques partagées,
>- les mêmes descripteurs de fichiers ouverts

Puisque le contexte d'un thread est plus petit que celui d'un processus il est donc plus rapide pour le système de créer un thread que de créer un processus.

Les threads n'ont pas la hiérarchie **père fils** ainsi un thread ne dépend pas de celui qui l'a créé. Seul le premier thread créé à une distinction. Ainsi, :
- n'importe quel thread peut tuer
- n'importe quel thread peut attendre la fin d'un autre au sein d'un même processus

En langage `C` on utilise la bibliothèque `<pthread.h>`.
>[!warning] Attention
>Pour pouvoir compiler il ne faut pas oublier de lier la bibliothèque avec `-pthread`.

```c
#include<pthread.h>
```
Ainsi la ligne de compilation :
```
gcc -pthread fichier.c
```

## Création d'un thread
Il est possible de créer un thread depuis n'importe quel thread du programme avec `pthread_create` :
```c
int pthread_create(pthread_t *thread, 
				   const pthread_attr_t *attr,
                   void *(*fct)(void *), 
                   void *arg);
```
- `*thread` pointeur vers l'identifiant du thread créé
- `*attr` pointeur vers une structure d'attribut du thread
  $\Longrightarrow$ `NULL` pour les attributs par défaut
- `*(*fct)(void *)` la fonction que le thread exécutera. Prend `void*` en argument et renvoie un `void*`
  *Quand le thread arrive à la fin de la fonction, il aura terminé ses tâches.*
- `*arg` arguments à passer à la fonction `fct`

Les renvois possible : 
- `0` le thread a bien été créé
- `>0` code d'erreur

>[!info] Remarque
>- En linux, `pthread_t` est un entier long `unsigned long` qui permet d'avoir jusqu'à 4 milliards de threads en même temps.
>- Dans les autres système, c'est encore flou et en évolution...

**EXEMPLE** création de 5 threads.
```c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NB_THREAD 5

void* routine_thread(void* arg) {
    int numThread = *(int*)arg;
    printf("Bonjour depuis le thread %d\n", numThread);
    return NULL;
}

int main(void) {
    pthread_t threads[NB_THREAD];
    int indices[NB_THREAD]; 

    for (int i = 0; i < NB_THREAD; i++) {
        indices[i] = i;
        int retour = pthread_create(&threads[i], NULL, 
							        routine_thread, &indices[i]);
        if (retour != 0) {
            fprintf(stderr, "%s\n", strerror(retour));
            exit(1);
        }
    }
    for (int i = 0; i < NB_THREAD; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
```

```
Bonjour depuis le thread 0
Bonjour depuis le thread 1
Bonjour depuis le thread 2
Bonjour depuis le thread 3
Bonjour depuis le thread 4
```

>On utilise un tableau statique `indice[NB_THREAD]` pour stocker une copie stable de `i`. 

Si on utilise pas le tableau : 
```c
for (int i = 0; i < NB_THREAD; i++) {
    pthread_create(&threads[i], NULL, routine_thread, &i); // ❌ ERREUR
}
```
- Ici on a toujours la même adresse pour `i` donc les threads reçoivent le même pointeur. 

## Attributs d'un thread
Un thread possède plusieurs attributs regroupés dans une structure de donnée spécifique qui dépend du système d'exploitation.
Elle est représentée par le type `pthread_attr_t`. 
>[!tip] 
>- Si les attributs par défaut suffisent, on passe un type vide à la création du thread.
>```c
>ptread_create(-, NULL, -, -);
>```
>- Dans le cas contraire, il faudra définir la structure puis la remplir.

## Fin d'un thread
Pour terminer un thread on utilise la fonction suivante :
```c
#include<pthread.h>
void pthread_exit(void* retour);
```
- valeur de retour *optionnelle* que les autres threads peuvent récupérer avec la fonction `pthread_join`.

**Pourquoi utiliser `pthread_exit` ?**
On utilise `pthread_exit` pour :
- quitter un thread sans terminer le programme
- retourner une valeur aux autres threads
- terminer un thread lorsque cela n'arrive pas à la fin de sa fonction

**EXEMPLE** terminer un thread, puis récupérer la valeur qu'il a retourné.
```c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* routine_thread(void* arg) {
    int* result = malloc(sizeof(int));
    *result = 42;
    pthread_exit((void*)result);
    // équivaut à : return result;
}

int main(void) {
    pthread_t t;
    int* retour;

    pthread_create(&t, NULL, routine_thread, NULL);
    pthread_join(t, (void**)&retour);

    printf("Valeur retournée par le thread : %d\n", *retour);
    free(retour); // Libérer la mémoire
    return 0;
}
```

```
Valeur retournée par le thread : 42
```

## Capturer la fin d'un thread
La fonction que nous venons d'utiliser `pthread_join` est en fait une fonction bloquante, en gros tant que le thread spécifié en argument n'a pas terminé, on attend.
**Signature de la fonction**
```c
#include<pthread.h>
int pthread_join(pthread_t thread, void** retour);
```
- `thread` l'identifiant du thread que l'on veut attendre.
- `retour` un pointeur vers un pointeur qui reçoit la valeur retournée par le thread via `pthread_exit`. 

>[!tip]
>Si on ne veut pas récupérer de valeur :
>```c
>pthread_join(-, NULL);
>```

**EXEMPLE complet**
*On reprend l'exemple précédant en ajoutant des vérifications*
```c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void* routine_thread(void* arg) {
    int* result = malloc(sizeof(int));
    *result = 42;
    return result;
}

int main(void) {
    pthread_t t;
    int* retour; // Variable de stockage du retour du thread
    int r;
    
	// Le thread a bien été créé ?
    if(r=pthread_create(&t, NULL, routine_thread, NULL)!=0){
        fprintf(stderr, "%s\n", strerror(r));
        exit(1);
    }

	// On attends jusqu'à récupérer une valeur
    pthread_join(t, (void**)&retour);
    
	// Le retour existe ?
    if(retour != PTHREAD_CANCELED){
        printf("Valeur retournée par le thread : %d\n", *retour);
    }
    free(retour); // Libérer la mémoire
    return 0;
}
```

## Détachement d'un thread
On peut créer des threads qui s'auto libèrent à la fin de leur exécution. Par contre, on ne peut plus les attendre avec `pthread_join`. 
En gros, quand on a pas besoin d'attendre un thread on peut le détacher, il disparaît automatiquement du système quand il termine puis il libère immédiatement des ressources privées donc pas d'état zombie.
```c
#include<pthread.h>
int pthread_detach(pthread_t thread);
```

**EXEMPLE**
```c
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* routine_thread(void* arg) {
    printf("Thread détaché : je travaille...\n");
    sleep(2);
    printf("Thread détaché : terminé.\n");
    return NULL;
}

int main() {
    pthread_t thread;

    pthread_create(&thread, NULL, routine_thread, NULL);
    pthread_detach(thread); // ✅ On détache le thread

    printf("Main : pas besoin de l’attendre.\n");
    sleep(3); // Attendre un peu pour voir le thread travailler

    return 0;
}
```

```
Main : pas besoin de l'attendre.
Thread détaché : je travaille...
Thread détaché : terminé.
```

## Problème : Émancipation d'un thread
L'émancipation c'est le fait de libérer un thread donc avec `pthread_detach`. Une fois cela fait :
- le thread devient invisible aux yeux du programme
- il se nettoiera seul à la fin de son exécution
- le programme principal n'a **aucun moyen de savoir quand il se termine ni de récupérer sa valeur de retour**.

Il peut donc se produire des comportements imprévisible si on utilise mal `pthread_detach` :
- Le thread détaché peut ne pas avoir le temps de finir. Si le programme finit avant lui il est brutalement stoppé.
**EXEMPLE**
```c
pthread_t t;
pthread_create(&t, NULL, fct, NULL);
pthread_detach(t);
return 0; // Le thread peut ne pas avoir le temps finir !
```

>[!warning]
>Si un thread n'est ni détaché ni rejoint, il devient **zombie**, en gros ça veut dire qu'il a terminé, mais que ses ressources ne sont pas libérées. Cela peut provoquer des fuites de mémoires.

>[!tip]
>On utilise `pthread_detach` quand :
>- On n'a pas besoin du résultat du thread
>- On ne veut pas l'attendre
>- One est certain qu'il n'interagit plus avec le reste du programme une fois lancé.

## Égalité d'ID de threads
```c
#include<pthread.h>
int pthread_equal(pthread_t thread1, pthread_t thread2);
```
- `0` les threads sont différents
- `>0` les threads ont le même identifiant

## ID du thread courant
```c
#include<pthread.h>
int pthread_self(void);
```
Cela permet ensuite de comparer avec `pthread_equal` une identité associée à une tache à accomplir.

|       Fonction       | processus |      thread      |
| :------------------: | :-------: | :--------------: |
|       Création       |  `fork`   | `pthread_create` |
|       Attendre       |  `wait`   |  `pthread_join`  |
|       Terminer       |  `exit`   |  `pthread_exit`  |
| récupérer le courant | `getpid`  |  `pthread_self`  |
>[!warning]
>Les processus possèdent une hiérarchie père, fils, petit-fils tandis que les threads d'un processus donné sont **tout au même niveau**.

## Annulation d'un thread
Un thread `T1` peut demander l'annulation d'un autre thread `T2`.
- Si `T2` accepte, alors c'est comme si il appelait : `pthread_exit(PTHREAD_CANCELED);`
- `T2` peut aussi refuser ou repousser la demande jusqu'à un point d'annulation.
```c
#include<pthread.h>
int pthread_cancel(pthread_t thread);
```
- `0` tout est ok
- `>0` erreur *exemple un thread inexistant `ESRCH`*

Mais comment ça fonctionne dans la pratique ?
- Le thread courant fait une demande d'annulation au thread spécifié en argument qui peut ou non capter cette demande.
```c
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* routine(void* arg) {
    printf("Thread démarré\n");

    for (int i = 0; i < 10; i++) {
        printf("Travail %d\n", i);
        sleep(1);
        pthread_testcancel();
    }

    printf("Thread terminé normalement\n");
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, routine, NULL);

    sleep(3); // Attendre un peu
    pthread_cancel(thread); // Demande d'annulation
    
    void* status;
    pthread_join(thread, &status);
    
    if (status == PTHREAD_CANCELED) {
        printf("Thread annulé\n");
    } else {
        printf("Thread terminé normalement\n");
    }
    return 0;
}
```

```
Thread démarré
Travail 0
Travail 1
Travail 2
Travail 3
Thread annulé
```
- Ici le thread affiche un message 10 fois.
- Le programme fait une demande d'annulation après 3 secondes et puisqu'on re définit un point d'annulation à la fin de chaque boucle, au moment de la demande, le thread concerné va en fait faire le tour de boucle courant puis s'annuler lorsqu'il rencontrer `pthread_testcancel`. Cette instruction c'est comme si le thread se demandais si on lui a envoyé une demande d'annulation. 

```c
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* routine(void* arg) {
    printf("Thread démarré\n");
	// Désactiver annulation
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
    for (int i = 0; i < 10; i++) {
        printf("Travail %d\n", i);
        sleep(1);
    }

    printf("Thread terminé normalement\n");
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, routine, NULL);
    
    for (int i = 0; i < 10; i++) {
        sleep(1);
        pthread_cancel(thread); // Demande d'annulation
    }

    void* status;
    pthread_join(thread, &status);

    if (status == PTHREAD_CANCELED) {
        printf("Thread annulé\n");
    } else {
        printf("Thread terminé normalement\n");
    }
    return 0;
}
```

```
Thread démarré
Travail 0
Travail 1
Travail 2
Travail 3
Travail 4
Travail 5
Travail 6
Travail 7
Travail 8
Travail 9
Thread terminé normalement
Thread terminé normalement
```
- Ici le thread vas aller jusqu'au bout de ses tâches.

## Fonction d'initialisation partagée
La **fonction d'initialisation partagée** est un mécanisme utile pour s'assurer qu'un bloc de code d'initialisation n'est exécuté <u>une seule fois</u>, même si plusieurs threads y accèdent en même temps.
On utilise la fonction suivante :
```c
#include<pthread.h>
int pthread_once(pthread_once_t *once_control, void (*routine)(void));
```
- `once_control` c'est un contrôle de synchronisation statique
  généralement `PTHREAD_ONCE_INIT`
  Ce contrôle doit être partagé par tous les threads qui doivent appeler `routine`
- `routine` pointeur vers une fonction sans argument et sans valeur de retour

**EXEMPLE**
```c
#include <pthread.h>
#include <stdio.h>

pthread_once_t once_control = PTHREAD_ONCE_INIT;

void initialisation_unique() {
    printf("Initialisation partagée effectuée.\n");
}

void* routine(void* arg) {
    pthread_once(&once_control, initialisation_unique);
    printf("Thread %ld continue...\n", (long)arg);
    return NULL;
}

int main() {
    pthread_t threads[3];
    for (long i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, routine, (void*)i);
    }
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
```

```
Initialisation partagée effectuée.
Thread 0 continue...
Thread 1 continue...
Thread 2 continue...
```

>[!info] Remarque
>Cette fonction renvoie **toujours** `0`.

Au premier appel avec un argument `once_control` donné, on appelle la fonction `routine` et il y a modification de la variable `once` pour enregistrer le fait que l'initialisation a été réalisée.
Les appels suivants avec **ce même argument `once_init` son ignorés**.
## Zone d'exclusion mutuelle
La zone d'exclusion mutuelle *(mutex, = MUTual EXclusion)* est un concept fondamental en programmation concurrente. On utilise ce concept pour gérer l'accès concurrent des ressources partagées afin d'éviter les conditions de course et d'assurer l'intégralité des données. 

Un programme multithread implique :
- des sous-programmes concurrents
- mémoire commune
Il faut donc organiser les accès pour éviter que plusieurs threads utilisent une ressource en même temps.

En langage `C`, on synchronise l'accès aux ressources partagées dans un programme multithread principalement à l'aide des **verrous** MUTEX. 

### Initialisation d'un mutex
On peut initialiser un mutex de deux manières :
- statique
  On initialise le mutex à la compilation avec la constante `PTHREAD_MUTEX_INITIALIZER`
  ```c
	#include<pthread.h>
	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
	```
- dynamique
  En utilisant la fonction suivante :
  ```c
	#include<pthread.h>
	int pthread_mutex_init(
		pthread_mutex_t* mutex,
		const pthread_mutexattr_t* attributs
	);
	```

>[!info] Remarque
>- Les mutex doivent être déclarés dans des **variables globales** ou **locale statique**. 
>- `NULL` peut être utilisé pour les attributs si on souhaite avoir les attributs par défaut.

### Destruction d'un mutex
```c
#include<pthread.h>
int pthread_mutex_destroy(pthread_mutex_t* mutex);
```

>[!warning] 
>Si le mutex est dans l'état verrouillé alors l'erreur `EBUSY` est renvoyée.

### Verrouillage / déverrouillage d'un mutex
```c
#include<pthread.h>
int pthread_mutex_lock (pthread_mutex_t* mutex) 
int pthread_mutex_unlock (pthread_mutex_t* mutex)
```

**Verrouillage asynchrone**
Aussi appelé *verrouillage non bloquant*, il consiste à essayer de prendre un verrou sans attendre s'il est déjà occupé :
```c
#include<pthread.h>
int pthread_mutex_trylock(pthread_mutex_t* mutex);
```
- renvoie `EBUSY` si mutex déjà verrouillé
- `0` si tout vas bien
- A utiliser de manière modéré car consommateur de temps cpu par rapport à des attentes conditionnelles.

**EXEMPLE**
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* thread_fonction(void* arg) {
    int thread_num = *((int*)arg);

    if (pthread_mutex_trylock(&mutex) == 0) {
        printf("Thread [%d] : verrou acquis\n", thread_num);
        sleep(2); // Simule un travail
        pthread_mutex_unlock(&mutex);
        printf("Thread [%d] : verrou relâché\n", thread_num);
    } else {
        printf("Thread [%d] : verrou déjà pris, ne bloque pas\n", thread_num);
    }

    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    pthread_create(&t1, NULL, thread_fonction, &id1);
    sleep(1); // Laisse le temps à t1 de prendre le verrou
    pthread_create(&t2, NULL, thread_fonction, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
```

```
Thread [1] : verrou acquis
Thread [2] : verrou déjà pris, ne bloque pas
Thread [1] : verrou relâché
```

### Exemple complet MUTEX
Nous on veut que `n` threads incrémente un 10.000 fois compteur. Ainsi la valeur final de ce compteur sera $nThread \times 10000$.
Mais en fait, pourquoi on utilise un mutex pour faire ça ? On veut éviter le phénomène appelé **condition de course**.

Une **condition de course** survient lorsqu'au moins deux thread accèdent en même temps à une ressource partagée et que :
- au moins un de ces accès et une écriture et
- il n'y a pas de mécanisme de synchronisation *(mutex par exemple)*
Cela signifie que le résultat du programme **dépend de l’ordre d’exécution imprévisible des threads**, ce qui peut entraîner des **comportements incorrects**.

 **⚠️ Dans notre exemple, sans mutex :**
Voici le code critique :
```
compteur++;
```

Cette instruction a l’air simple, mais elle se traduit en plusieurs étapes machines :
1. Lire la valeur de `compteur` (ex: 10)
2. Incrémenter localement (→ 11)
3. Écrire la nouvelle valeur (11) dans `compteur`

**🧨 Que se passe-t-il si deux threads font ça en même temps ?**
**Imaginons** :
- `Thread1` lit `compteur = 10`
- `Thread2` lit aussi `compteur = 10`
- `Thread1` incrémente et écrit `11`
- `Thread2` incrémente _sa copie_ de 10 et écrit aussi `11`

Ainsi la valeur de compteur après l'incrémentation sera `11` au lieu de `12`.
🔴 **Résultat attendu :** 12  
🔴 **Résultat obtenu :** 11  
⛔ **1 incrément perdu**
>[!info] Remarque
>Plus il y a de threads et d’opérations, **plus les erreurs deviennent fréquentes**

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

```
Thread 1 terminé
Thread 2 terminé
Thread 3 terminé
Thread 4 terminé
Compteur final attendu : 400000
Compteur final obtenu  : 400000
```

Explications détaillées du programme :
- <u>Objectif :</u> Un certain nombre de thread incrémentent simultanément une variable `compteur`, pour éviter les conflits d'accès, un mutex est utilisé pour synchroniser l'accès à la variable compteur.

>- Déclaration des constantes `NB_THREAD` et `NB_INCREMENTS`
>- Déclaration de la variable partagée entre les threads
>- On initialise le verrou qui vas assurer qu'un seul thread **à la fois** modifie la variable `compteur`.

>Chaque threads vas exécuter ma fonction
>`void* incrementer(void* arg)`
>Puisque chaque thread reçoit un argument `arg` contenant son id (ici de 1 à4) alors on récupère ce dernier puis on le caste en le déréférençant.

>Chaque thread vas ensuite effectuer 10000 incréments
>Le mutex est utilisé pour verrouillé l'accès au compteur pendant l'incrémentation, pour éviter qu'un thread intervienne au même moment.

## Données privées d'un thread ?
>On l'a pas vu en TP donc je pense que ça tombera pas.