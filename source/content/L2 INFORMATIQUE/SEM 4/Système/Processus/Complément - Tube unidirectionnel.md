## Utilisation des tubes unidirectionnels 

Un pipe est un mécanisme de communication inter-processus (IPC) permettant à un processus parent et son processus enfant d’échanger des données via un flux unidirectionnel (généralement de l’écriture vers la lecture).
<br/>Un pipe fonctionne comme un tube :

- Une extrémité pour écrire `write`
- Une extrémité pour lire `read`

### Création d'un pipe

Dans notre complément, on appellera `pipefd` le pipe.
<br/>Puisqu'un pipe à deux extrémités, et deux modes alors on vas créer un tableau de deux entiers, un qui représente l'écriture et un autre qui représente la lecture.

```c
int pipefd[2];
pipe(pipefd);
```

On distingue les deux modes :

- `pipefd[0]` est l'extrémité de la lecture
- `pipefd[1]` est l'extrémité de l'écriture

>[!warning]
>Ce qu'il faut aussi retenir c'est que le tube est **unidirectionnel** c'est à dire qu'il ne fonctionne que dans un seul sens.

La communication entre un père et son fils ne fonctionne que dans un sens : *le fils peut écrire dans le tube pour envoyer à son père, mais pas l'inverse*.
<br/> Ainsi, puisque le fils peut écrire des données c'est lui qui utilisera `pipefd[1]` et le père lui utilisera `pipefd[0]` puisqu'il ne peut que lire le pipe.

Retenons le schéma suivant :
```
    Fils               Père
  pipefd[1]   ===>   pipefd[0]  
    écrit               lit   
```

### Exemple d'utilisation

On veut que le fils envoi l'argument passé au programme à son père via un pipe.

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <entier>\n", argv[0]);
        return 1;
    }

    int envoi = atoi(argv[1]);  // Conversion de l'argument en entier
    int pipefd[2]; 
    
    if (pipe(pipefd) == -1) {
        perror("Erreur lors de la création du pipe");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("Erreur lors du fork");
        return 1;
    }

    if (pid == 0) {
        // Processus fils : écrit dans le pipe
        close(pipefd[0]); // On ferme la lecture
        write(pipefd[1], &envoi, sizeof(envoie));
        close(pipefd[1]);
        exit(0); // On termine le fils proprement
    } else {
        // Processus père : lit dans le pipe
        close(pipefd[1]); // On ferme l'écriture
        int recue;
        read(pipefd[0], &recue, sizeof(recue));
        close(pipefd[0]);
        
        wait(NULL); // Attendre la fin du fils
        printf("Valeur reçue : %d\n", recue);
    }

    return 0;
}
```

- `int argc` le nombre d'arguments passé au programme à l'exécution
- `char* argv[]` la liste des arguments passé au programme principal

**ETAPE 1**
<br/>en premier on vérifie si le nombre d'arguments passé n'est pas inférieur à 2 :
- On a le nom de l'exécutable
- L'entier à envoyer au père

Par exemple :
```less
gcc -o executable fichier.c
./prog                          // erreur
./prog 14                       // correct
```
Si on se concentre sur les appels :

- Le premier ne fonctionnerai pas car il n'y a qu'un argument : *le nom de l'exécutable*
- Le second fonctionnerai car il y a bien 2 arguments : *nom de l'executable puis entier que le fils doit envoyer à son père*

**ETAPE 2**
<br/>On récupère l'entier passé au programme.

```c
int envoi = atoi(argv[1]);
```

>[!tip]
>`atoi()` permet de convertir l'argument passé en entier. Puisque pour rappel les arguments passés sont de type `char*` au départ.

**ETAPE 3**
On créer le pipe.

```c
int pipefd[2];
pipe(pipefd);
```

Ainsi, à la création du `pipe`, une des ses extrémités, en locurrence celle de lecture est associé au processus père.

>[!warning]
>Il faut créer le pipe **avant le `fork()`** pour qu'après la création du fils, le pipe soit associé au père et à son fils.

**ETAPE 4**
<br/>Création du fils.

```c
pid_t pid = fork();

// + vérification du fork( )
if(pid==-1){
    printf("erreur de fork()\n");
    return 1; 
}
```

**ETAPE 5**
<br/>Le fils écrit dans le pipe pour envoyer l'entier au père.

```c
if (pid ==0) {
    // Si fork renvoie 0 c'est qu'on est dans le fils
    close(pipefd[0]);                           // On ferme la lecture du pipe car le fils lui en fait qu'écrire
    write(pipefd[1], &envoi, sizeof(envoi));    // Écriture de la variable à envoyer dans le pipe
    close(pipefd[1]);                           // On ferme l'écriture quand on a fini
    exit(0);                                    // On termine le fils proprement
}
```

Si on fait un mini récap
- Puisque le fils se contente d'écrire dans le pipe alors on peut fermer la lecture donc `pipefd[0]`
- On écrit dans le pipe la valeur à envoyer 

```c
write(pipefd[1], *valAEnvoyer, taille_a_ecrire);
```

- On ferme l'écriture car on a terminé
- On termine le fils

**ETAPE 6**
<br/>Le père récupère la valeur envoyée par le fils.

```c
if(pid > 0) {
    close(pipefd[1]);                           // On ferme l'écriture car le père ne fait que lire
    int recue;                                  // On déclare une variable pour stocker le résultat
    read(pipefd[0], &recue, sizeof(recue));     // On récupère la variable envoyée dans le pipe
    close(pipefd[0]);                           // On ferme la lecture car on a terminé
    
    // On attend la fin du fils
    wait(NULL);
    printf("Valeur reçue envoyée par le fils : %d\n", recue);
}
// On termine le programme
return 0;
```