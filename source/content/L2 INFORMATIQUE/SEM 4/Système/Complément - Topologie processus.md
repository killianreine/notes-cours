## Topologie des processus

En programmation système, notamment en `C` sous UNIX/Linux, la topologie des processus fait référence à la manière dont les processus sont organisés et interconnectés.

### Topologie en ligne

La topologie en ligne est plutôt logique, on la représente de la manière suivante :

```
P1 → P2 → P3 → ... → Pn
```

où Pi avec `i` un entier positif qui désigne le i-ème processus.
<br/>Dans une topologie en ligne chaque processus vas créer un fils.

```c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NB_FILS 4

int main() {
    pid_t pid;

    for (int i = 0; i < NB_FILS ; i++) {
        pid = fork();

        if (pid > 0) {
            // On se trouve dans le processus père
            wait(NULL);
            printf("Processus %d terminé, PID = %d, PPID = %d\n", i, getpid(), getppid());
            break;
        } else if (pid == 0) {
            // On se trouve dans le processus fils
            continue;
        } else {
            perror("fork");
            return 1;
        }
    }

    if (pid == 0) {
        // Dernier processus (ne crée pas de fils)
        printf("Dernier processus (n°%d), PID = %d, PPID = %d\n", NB_FILS, getpid(), getppid());
    }

    return 0;
}
```
```
Dernier processus (n°4), PID = 28586, PPID = 28585
Processus 3 terminé, PID = 28585, PPID = 28584
Processus 2 terminé, PID = 28584, PPID = 28583
Processus 1 terminé, PID = 28583, PPID = 28582
Processus 0 terminé, PID = 28582, PPID = 28574
```

Voici ce qu'il se passe :

- On définit une variable pour stocker la valeur du `pid`.
- On boucle `NB_FILS` fois avec un `for`
    - Création d'un fils
    - Si le `pid==-1` erreur
    - Si le `pid==0` on est dans le fils on fait rien
    - Si le `pid>0` on est dans le père alors ce dernier doit attendre la fin de son fils pour continuer
- Enfin, on s'occupe du processus en fin de ligne, on affiche juste qu'il existe et que c'est le dernier de la ligne.

On obtiendra ainsi la chaine suivante :
<br/>*On prend les deux erniers chiffres de chaque `pid` pour aller plus vite...*
```
82 → 83 → 84 → 85 → 86
```

### Topologie en étoile

```
     P2
      ↑
 P3 ← P1 → P2
     ...
```

Le père est le processus central, il créé plusieurs fils, il doit attendre que tous se terminent et il se terminera après. En gros le père vas créer `n` fils qui seront tous directement relié à lui.

```c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NB_FILS 4

int main() {
    pid_t pid;

    for (int i = 0; i < NB_FILS; i++) {
        pid = fork();
        if (pid == 0) {
            printf("Fils %d, PID = %d, PPID = %d\n", i+1, getpid(), getppid());
            return 0; // Le fils termine
        }
    }

    // Le parent attend la fin de tous ses fils
    for (int i = 0; i < NB_FILS; i++) {
        wait(NULL);
    }
    
    printf("Mes fils se sont bien terminés, je peux me terminer aussi !\n");

    return 0;
}
```
```
Fils 1, PID = 1415, PPID = 1414
Fils 2, PID = 1416, PPID = 1414
Fils 3, PID = 1417, PPID = 1414
Fils 4, PID = 1418, PPID = 1414
Mes fils se sont bien terminés, je peux me terminer aussi !
```

Voilà ce qu'il se passe :

- Le père créé chaque fils un par un à l'aide de la première boucle `for`
- Chaque fils affiche son identité et se termine
- Le deuxième `for` indique au père qu'il doit attendre que ses fils terminent pour pouvoir finir.
- Le père indique que ses fils ont terminés et termine à son tour.