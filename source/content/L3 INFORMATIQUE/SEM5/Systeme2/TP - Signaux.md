# Interception d'un signal
Écrire un programme qui capte le signal `sigusr1` et affiche un message à l'écran lorsque le signal est envoyé au processus :
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
