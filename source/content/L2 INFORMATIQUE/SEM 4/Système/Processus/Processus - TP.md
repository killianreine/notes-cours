## 2.1 Processus simples
1. Récupérer le PID d'un processus et le faire attendre 20 secondes
```c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = getpid();         // Obtenir le PID du processus
    printf("Mon PID est : %d\n", pid);
    sleep(20);                    // Attendre 20 secondes
    return 0;
}
```

`getid()` permet d'obtenir le pid du processus en cours d'exécution.

2. Écrire un programme qui affiche la valeur de la variable d'environnement `TERM` puis lance l'exécution de la commande `ls -l`.
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Lire la variable d'environnement TERM
    char *term = getenv("TERM");
    if (term != NULL) {
        printf("La variable TERM est : %s\n", term);
    } else {
        printf("La variable TERM n'est pas définie.\n");
    }

    // Exécuter la commande "ls -l"
    execlp("ls", "ls", "-l", NULL);

    // Si execlp échoue
    perror("execlp a échoué");
    return 1;
}
```
- `getenv` permet de récupérer la variable d'environnement
- `execlp` pour exécuter une commande
```c
#include<unistd.h>
int execlp(const char *cmd, const char *arg0, ..., (char *)NULL);
```
- `cmd` la commande a exécuter
- `arg0, ... argN` liste des arguments à passer à la commande
- `NULL` **La liste des arguments doit se terminer par NULL**

- Le premier `ls` c'est le non de l'exécutable que le programme vas lancer.
- Le second `ls` c'est le nom par lequel le programme pense avoir été lancé. Par convention, on met le nom de la commande.
- le `-l` c'est donc un argument valide avec `ls`
Ainsi ça revient à taper 
```
ls -l
```
On peut aussi le faire comme ceci :
```c
char* args[] = {"ls", "-l", NULL};
execlp("ls", args);
```
## 2.2 Topologies de processus
1. **TOPOLOGIE EN ÉTOILE**
   Écrire un programme permettant à un processus père de créer 4 fils (via itération). Chaque fils dois afficher son identité (`getpid`) puis se terminer. Lorsque tous les fils ont terminé, le père termine à son tour.

```c
#include <unistd.h>
#include <sys/wait.h>

// Création d'une routine pour les fils
void routine_fils(){
    printf("FILS : Coucoucou, je suis le fils %d\n", getpid());
    printf("FILS : Terminé !\n");
    exit(EXIT_SUCCESS); // Le fils termine ici
}

int main(){
	// Création d'un tableau contenant 4 PID
    pid_t pid[4];
    int i;

    // Création des 4 fils
    for(i = 0; i < 4; i++){
        pid[i] = fork();
        if(pid[i] == -1){
            perror("Erreur de fork");
            return EXIT_FAILURE;
        }
        if(pid[i] == 0){
            routine_fils(); // Le fils exécute sa routine puis termine
        }
    }

    // Le père attend tous les fils
    for(i = 0; i < 4; i++){
        waitpid(pid[i], NULL, 0);
    }

    printf("PERE : Tous mes fils sont terminés. Je termine aussi !\n");
    return EXIT_SUCCESS;
}
```

2. **TOPOLOGIE EN LIGNE**
   Faite le même programme pour créer une ligne de processus : le père crée un fils qui crée un fils qui crée un fils... Puis on remonte la ligne pour termine **sans créer de zombies**.
```
Père → Fils1 → Fils2 → Fils3 → Fils4
```
>La flèche signifie *"créer"*. 

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define N 4  // Nombre total de processus (père inclus)

int main() {
    pid_t pid;
    int i;

    for(i = 0; i < N - 1; i++) {
        pid = fork();

        if(pid == -1) {
            perror("Erreur de fork");
            exit(EXIT_FAILURE);
        }

        if(pid == 0) {
            // Fils : continue la chaîne
            printf("Processus %d : Je suis le fils de %d\n", getpid(), getppid());
            continue; // Le fils continue la boucle pour créer un fils à son tour
        } else {
            // Père : attend son fils
            waitpid(pid, NULL, 0);
            // Une fois le fils terminé, il quitte la boucle
            break;
        }
    }

    // Le dernier processus : affiche et termine
    if(pid == 0) {
        // Le dernier fils n’a pas forké, donc on affiche ici
        printf("Dernier processus %d : Je suis tout au bout de la ligne.\n", getpid());
    }

    printf("Processus %d : Terminé.\n", getpid());
    return EXIT_SUCCESS;
}
```

## 2.3 Génération dynamique de processus
1. Créer un processus fils à partir d'un processus père et afficher pour chacun les différentes identités (propriétaire réel, effectif puis groupe réel et effectif).

>[!cite] Définition
>- l'**UID** c'est un nombre unique attribué à chaque utilisateur sur le système. En gros le système utilise l'UID pour savoir qui exécute le processus (ou qui possède tel fichier).
>- **UID réel** indique l'utilisateur d'origine du processus
>- **UID effectif** peut être différent

>[!cite] Définition
>- Le **GID** lui c'est l'identifiant du groupe d'utilisateurs.

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void afficher_identites(const char *nom_processus) {
    printf("%s (PID %d) :\n", nom_processus, getpid());
    printf("UID réel     : %d\n", getuid());
    printf("UID effectif : %d\n", geteuid());
    printf("GID réel     : %d\n", getgid());
    printf("GID effectif : %d\n", getegid());
    printf("\n");
}

int main() {
    pid_t pid = fork();

    if(pid == -1) {
        perror("Erreur de fork");
        exit(EXIT_FAILURE);
    }

    if(pid == 0) {
        // Processus fils
        afficher_identites("Fils");
    } else {
        // Processus père
        afficher_identites("Père");
        wait(NULL); // attendre la fin du fils
    }

    return EXIT_SUCCESS;
}
```

```
Père (PID 16585) :
UID réel     : 1000
UID effectif : 1000
GID réel     : 1000
GID effectif : 1000

Fils (PID 16586) :
UID réel     : 1000
UID effectif : 1000
GID réel     : 1000
GID effectif : 1000
```

2. Écrire un programme `voyelle.c` créant un processus fils qui lit un fichier de caractères *(donné en argument du `main`)* et renvoie au processus père la voyelle la plus utilisée dans le fichier.

Pour communiquer entre les processus, on vas utiliser un `pipe`, en gros il permet au fils d'envoyer des données à un autre processus via un **canal unidirectionnel**. 
Détaillons le fonctionnement d'un `pipe` :
```c
// Création 
int pipefd[2];
pipe(pipefd);
```
- `pipefd[0]` pour la lecture
- `pipefd[1]` pour l'écriture
On créé alors un canal de communication qui ne fonctionne que dans 1 sens d'où unidirectionnel.
```
Processus fils       →       Processus père
   écrit pipefd[1]           lit pipefd[0]
```

>[!warning] Attention
>On crée le tube avant le `fork()` pour qu'il hérite du fils. Ainsi, après le `fork` le père et le fils représentent les deux extrémités du tube.

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <sys/wait.h>

// Fonction secondaire : vérifier si c'est une voyelle
int est_voyelle(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' 
				     || c == 'o' || c == 'u' || c == 'y');
}

// Récupérer l'indice de la voyelle la plus fréquente
int max_compte(int *compte){
    int max_index = 0;
    for(int i = 1; i < 6; i++) {
        if(compte[i] > compte[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage : %s <fichier.txt>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Création du tube unidirectionnel et vérification du bon déroulement
    int pipefd[2];
    if(pipe(pipefd) == -1) {
        perror("Erreur lors de la création du pipe");
        return EXIT_FAILURE;
    }

    // Création du fils
    pid_t pid = fork();

    // En cas d'erreur
    if(pid == -1) {
        perror("Erreur de fork");
        return EXIT_FAILURE;
    }

    if(pid == 0) {
        // Processus fils
        close(pipefd[0]); // Fermer car ne veut pas lire

        // Ouverture du fichier
        FILE *fichier = fopen(argv[1], "r");
        if(!fichier) {
            perror("Erreur d'ouverture du fichier");
            exit(EXIT_FAILURE);
        }

        // Le tableau compteur où index correspond a une voyelle
        int compte[6] = {0}; // a e i o u y
        char c;
        // On lit chaque caractère jusqu'à EndOfFile EOF
        while((c = fgetc(fichier)) != EOF) {
            c = tolower(c);
            switch(c) {
                case 'a': compte[0]++; break;
                case 'e': compte[1]++; break;
                case 'i': compte[2]++; break;
                case 'o': compte[3]++; break;
                case 'u': compte[4]++; break;
                case 'y': compte[5]++; break;
            }
        }
        // Fermeture du fichier
        fclose(fichier);

        // Trouver l'index de la voyelle la plus fréquente
        int max_index = max_compte(compte);

        // Stocke les voyelles dans l'ordre
        char voyelles[] = {'a', 'e', 'i', 'o', 'u', 'y'};
        char resultat = voyelles[max_index];

        // Envoyer la voyelle la plus utilisée au père
        write(pipefd[1], &resultat, sizeof(char));
        close(pipefd[1]); // Fermer l'écriture du pipe
        exit(EXIT_SUCCESS); // Terminer le fils
    } else {
        // Processus père
        close(pipefd[1]); // Fermer l'écriture car père lit

        char plus_utilisee;
        read(pipefd[0], &plus_utilisee, sizeof(char));
        close(pipefd[0]);

        wait(NULL); // Attendre la fin du fils
        // Affichage du résultat
        printf("La voyelle la plus utilisée est : '%c'\n", plus_utilisee);
    }

    return EXIT_SUCCESS;
}
```

## 2.4 Arborescence de processus
Voici la démarche à suivre :
- Représentation récursive de l'arbre
	- Chaque processus engendre **2 fils** si il n'a pas atteint le rang `N` 
	- Chaque fils est une instance du même code appelé avec un rang `N` augmenté
- On vas utiliser les fonctions connues
	- `fork()` pour créer des fils
	- `wait()` pour attendre la fin des fils
	- `getpid()` et `getppid()` afficher les id de processus
- Paramètre `rang`
	- incrémenté à chaque appel récursif
	- la génération s'arrête lorsque `rang==N`

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void creer_arbre(int rang_actuel, int rang_max) {
    printf("Processus PID = %d, PPID = %d, Rang = %d\n", getpid(), getppid(), rang_actuel);
    fflush(stdout); // pour forcer l’affichage 

    if (rang_actuel >= rang_max)
        return;

    pid_t pid1 = fork();
    if (pid1 == 0) {
        // Premier fils
        creer_arbre(rang_actuel + 1, rang_max);
        exit(0);
    }

    pid_t pid2 = fork();
    if (pid2 == 0) {
        // Deuxième fils
        creer_arbre(rang_actuel + 1, rang_max);
        exit(0);
    }

    // Attente des deux fils
    wait(NULL);
    wait(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <rang_max>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int rang_max = atoi(argv[1]); // atoi pour convertir char* en int
    if (rang_max < 0) {
        fprintf(stderr, "Le rang doit être un entier positif.\n");
        return EXIT_FAILURE;
    }

    creer_arbre(0, rang_max); // Démarrage à la racine (au rang 0)

    return EXIT_SUCCESS;
}
```