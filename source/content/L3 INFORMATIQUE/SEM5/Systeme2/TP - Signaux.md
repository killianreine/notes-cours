# Interception d'un signal
- Écrire un programme qui capte le signal `sigusr1` et affiche un message à l'écran lorsque le signal est envoyé au processus :

```c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

/**
 * La fonction à exécuter lorsqu'un signal est envoyé
 * ==> GESTIONNAIRE DE SIGNAUX
 */
void signal_handler(int n_sig){
    switch (n_sig)
    {
    case SIGUSR1:
        printf("Signal SIGUSR1 reçu !\n");
        break;
    }
    return;
}

int main (){
    printf("Processus PID : %d\n", getpid());

    // Peut recevoir un signal SIGUSR1
    int sig = signal(SIGUSR1, signal_handler);

    // Gestion erreur
    if(sig == SIG_ERR) exit(EXIT_FAILURE);

    // Envoi le signal SIGUSR1 au fils
    kill(getpid(), SIGUSR1);

    while(1) pause();
    return 0;
}
```
```
kill -USR1 [PID]
Signal SIGUSR1 reçu !
```

- Masquer le signal `sigusr1` et afficher les signaux pendants

```c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int sig) {
    if (sig == SIGUSR1) {
        printf("Signal SIGUSR1 reçu et traité !\n");
    }
}

int main() {
    printf("PID du processus : %d\n", getpid());

    /* Installer le gestionnaire */
    if (signal(SIGUSR1, signal_handler) == SIG_ERR) {
        perror("signal");
        exit(EXIT_FAILURE);
    }

    sigset_t mask, pending;     // Création des ensembles signaux masqués et pendants
    sigemptyset(&mask);         // Init
    sigaddset(&mask, SIGUSR1);  // Ajout du signal SIGUSR1

    sigprocmask(SIG_BLOCK, &mask, NULL);    // Bloquer SIGUSR1
    printf("SIGUSR1 est maintenant MASQUÉ\n");

    kill(getpid(), SIGUSR1);
    printf("SIGUSR1 envoyé pendant le masquage\n");

    sleep(1);

    sigpending(&pending);       // ensemble des signaux masqués
    if (sigismember(&pending, SIGUSR1)) {   // Vérifier si SIGUSR1 est un signal masqué
        printf("SIGUSR1 est en attente (pending)\n");
    } else {
        printf("SIGUSR1 n'est PAS en attente\n");
    }

    printf("Démasquage de SIGUSR1...\n");
    sigdelset(&mask, SIGUSR1);

    while(2) pause();

    return 0;
}
```