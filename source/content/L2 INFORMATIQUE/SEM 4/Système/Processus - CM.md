# SYSTÈME D'EXPLOITATION - PROCESSUS
>[!cite] Définition
>Un ==processus== est un *programme en cours d'exécution*.

Les processus sont **organisés de manière hiérarchique** :
- Un père *parent* qui engendre des fils
- Un ou plusieurs fils *child* créés par le processus père. Mais, qui peuvent engendrer d'autre fils.

<u>Sources :</u>
- [code(quoi)](https://www.codequoi.com/creer-et-tuer-des-processus-fils-en-c/#analyser-le-statut-de-fin-dun-processus-fils)
- [C compiler online](https://www.programiz.com/c-programming/online-compiler/)

## Création d'un processus
L'instruction `fork( )` permet de créer un processus fils. 
```c
pid_t fork(void);
```

>[!tip]
>La fonction `fork` est contenue dans la bibliothèque `<unistd.h>`.

En fait `fork` vas permettre de créer un processus fils qui sera une copie conforme à son père, ainsi le fils aura le même code que le père. Mais on peut avoir besoin de donner des paramètres différents au père et au fils, la fonction `fork` retourne un nombre du type `pid_t` et c'est lui qui permet de différencier le père et le fils.
- Le père reçoit `PID` du fils
- Le fils reçoit `0`
- `-1` en cas d'erreur
Du coup ça implique que si `fork` renvoie `0` alors on est dans le fils, si `fork` renvoie `>0` alors on est dans le père.

**EXEMPLE**
```c
void main(){
	pid_t pid;
	pid = fork();
	if (pid==-1){
		printf("erreur pour fork\n");
		return;
	}
	// Si fork retourne 0 ou >0 alors il a réussi
	printf("fork a réussi - ");
	if(pid == 0) {
		// On est dans le fils
		printf("On est dans le fils\n");
	}
	else if(pid > 0){
		// On est dans le père
		printf("On est dans le père\n");
	}
	return;
}
```

Au moment de la création du fils, les deux processus sont absolument identiques. Ils ont le même code, les mêmes descripteurs de fichiers ouverts, les mêmes données en mémoire, etc. Mais cette mémoire, bien qu’identique, n’est pas partagée entre les deux processus.
- Si le processus père modifie une variable après avoir créer son fils alors ce dernier ne le verra pas.

```c
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// Routine du processus fils :
void routine_fils(pid_t pid, int *nb)
{
	printf("Fils : Coucou! Je suis le fils. PID recu de fork = %d\n", pid);
	printf("Fils : Le nombre est %d\n", *nb);
}

// Routine du processus père :
void routine_pere(pid_t pid, int *nb)
{
	printf("Pere : Je suis le pere. PID recu de fork = %d\n", pid);
	printf("Pere : Le nombre est %d\n", *nb);
	*nb *= 2;
	printf("Pere : Le nombre modifie est %d\n", *nb);
}

int	main(void)
{
	pid_t	pid; // Stocke le retour de fork
	int	nb;      // Stocke un entier

	nb = 42;
	printf("Avant fork, le nombre est %d\n", nb);
	pid = fork();                // Création du processus fils
	if (pid == -1)
		return (EXIT_FAILURE);
	else if (pid == 0)           // Retour de fork est 0, on est dans le fils
		routine_fils(pid, &nb);
	else if (pid > 0)            // Retour de fork > 0, on est dans le père
		routine_pere(pid, &nb);
	return (EXIT_SUCCESS);
}
```

```
Avant fork, le nombre est 42
Pere : Je suis le père. PID recu de fork = 140726
Pere : Le nombre est 42
Pere : Le nombre modifie est 84
Fils : Coucou! Je suis le fils. PID recu de fork = 0
Fils : Le nombre est 42
```

>[!warning] Attention
>Concernant le `fork` :
>- Si il renvoi `-1` alors il y a une erreur
>- Si il renvoi `0` alors on est dans le fils
>- Si il renvoi `>0` alors on est dans le père *il retourne le PID du fils créé*

## Attendre les processus fils
Il faut savoir qu'un processus fils ne s'occupe pas forcément de ses fils. 
Dans l'exemple suivant :
- On force les fils à attendre 1 seconde avant de se terminer
- Le père lui se termine <u>immédiatement</u> 
```c
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void){
    pid_t pid;

    pid = fork();
    if (pid == -1) return 1;
    if (pid == 0){
        printf("Fils : Je suis le fils, mon pid interne est %d.\n", pid);
        sleep(1); // Attendre 1 seconde.
        printf("Fils : Termine !\n");
    }else if (pid > 0){
        printf("Pere : Je suis le pere, le pid de mon fils est %d.\n", pid);
        printf("Pere : Termine !\n");
    }
    return 0;
}
```

On utilise `sleep(..)` pour faire attendre le processus fils un certain nombre de seconde. *ici on met `sleep(1)` pour faire attendre le processus fils 1 seconde.*

```
Pere : Je suis le pere, le pid de mon fils est 145232.
Pere : Termine !
Fils je suis le fils, mon pid interne est 0.
>>> killian@reine-ufrst:~USB/L2INFO/Systeme/coursProcessus
Fils : Termine !
```
On remarque qu'en fait, on nous redonne l'invite de commande **avant même que le fils se termine**. En gros c'est parce que le père se termine du coup comme il ne se préoccupe pas des fils, ainsi le fils devient orphelin et est "adopté" par `init` et son PPID devient 1. 

## Attendre les fils pour éviter les processus zombies

>[!cite] Définition
>On appelle ==**processus zombie**== un processus qui a terminé sa tâche mais qui attends que son père le prenne en compte.

On peut observer un zombie si l'on met le processus père dans une boucle infinie :
```c
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	pid_t pid;
	pid = fork();
	if(pid==-1) return 1;
	if(pid==0){
		printf("Fils : Je suis le fils et mon pid interne est &d\n", pid);
		printf("Fils : Termine !");
	}
	if(pid>0){
		printf("Pere : Je suis le père et le pid de mon fils est ad \n", pid);
		while(1)
			usleep(1);
	}
	return 0;
}
```

>[!info] Rappel
>L'entier `1` correspond à la valeur vraie en langage `C` puisqu'il ne possède pas de booléens de manière native.

Ainsi voici ce qu'il vas se passer :
- Le processus fils vas s'exécuter et se terminer
- Le processus père lui ne se terminera jamais car dans une boucle infinie
Puisque le père ne se finit jamais, alors il ne pourra jamais prendre en compte son fils, ce dernier sera donc **zombie**.

>[!warning] Remarques
>- Tant que le processus père reçoit le statut du fils, ce dernier ne pose pas de problème, si il est zombie il est automatiquement adopté par le processus `init` si il devient orphelin.
>- Or, si un processus père ne se termine jamais et qu'il engendre des fils à intervalle régulier, alors la table des processus peut se retrouver saturer et `fork` peut renvoyer `-1` en cas d'erreur.

Ainsi, pour éviter les processus zombies, le père vas devoir mieux s'occuper de ses fils. Cela est possible grâce à `wait` et `waitpid`.

## Les appels système `wait` et `waitpid`
Nous ce que l'on veut faire c'est suspendre l'exécution du processus père jusqu'à ce que l'état de son fils change. Pour cela on utilise les fonctions `wait` et `waitpid`. 

*Prototype des deux fonctions*
```c
#include<sys/wait.h>
pid_t wait(int *status);
pid_t waitpid(pid_t pid, int *status, int option);
```

La différence est importante entre les deux fonctions, 
- `wait` vas récupérer l'état du premier fils qui a terminé
- alors que `waitpid` vas attendre le fils avec le PID `pid` qu'on lui a fournit en paramètre, en ignorant tous les autres.

Le paramètre `*status`
	est un pointeur qui fait référence à un entier de type `int`, il permet de récupérer l'état du processus afin de savoir si il s'est terminé correctement son exécution ou pas. *ex. interrompu*
Le paramètre `pid`
	C'est l'identifiant du processus fils qu'il faut attendre, pour rappel lorsque l'on utilise la fonction `fork`, le père reçoit le `pid` du fils qu'il vient de créer. 
	On peut aussi mettre `-1` dans ce cas, le processus père attendra que n'importe quel fils termine en premier, exactement comme `wait`.
	Ainsi on a l'égalité suivante :
```c
waitpid(-1, status, 0) == wait(status)
```

Les `option`
	La fonction `waitpid` possède quelques options comme `WNOHANG` qui va en fait forcer `waitpid` à retourner `0` immédiatement si le fils n'a pas finit son exécution. 
	Si on utilise pas `WNOHANG`, ça signifie que si le fils ne finit JAMAIS sa tâche, le processus père sera bloqué.

Les deux fonctions renvoient le PID du fils qui a terminé, ou alors `-1` en cas d'erreur.
La fonction `waitpid` muni de l'option `WNOHANG` peut renvoyer `0` si le fils qu'il attends n'a pas encore terminé (changer d'état).

## Analyser l'état de fin d'un processus fils
les fonctions `wait` et `waitpid` renvoient un statut qui permet d'avoir accès à un certain nombre d'informations concernant la manière selon laquelle le fils a terminé son exécution. En fait, le statut est un entier qui représente le statut de fin mais il indique aussi *pourquoi le fils s'est terminé*. Ainsi, on peut savoir si le fils a terminé toutes ses tâches, s'il a été interrompu on pourra alors récupérer le code de sortie.
Il utilise plusieurs macros pour inspecter le statut.
>[!info] Rappel
>En langage `C`, un **macro** est un motif de substitution du texte permettant de simplifier le code.

- `WIFEXITED(status)` 
	Renvoie `vrai` si le fils s'est terminé normalement.
	- `WEXITSTATUS(status)`
		**À utiliser si `WIFEXITED` a renvoyé vrai**, il renvoie en fait le code de sortie du programme. *Le code de sortie c'est en fait le nombre spécifié au fils lors de son appel à `exit` ou lors du retour dans le main.*
- `WIFSINALED(status)`
	Renvoie `vrai` si le fils a terminé de manière forcée, **par un signal**
	- `WTERMSIG(status)`
		**À utiliser si `WIFTERMSIG` a renvoyé vrai**, il renvoi le numéro du signal qui a provoqué la terminaison du fils.


✅ **Un processus se termine normalement quand il rencontre :**
- `exit()` n’importe où dans le code,
- ou `return` dans la fonction `main()`, qui équivaut en fait à un `exit`. 

>[!warning]
>Les `return` dans les autres fonctions permettent simplement de dire que la fonction est terminée, pas le processus.

## Tuer les processus fils
On peut avoir besoin de tuer les processus fils, pour ce faire, on utilise la fonction `kill` afin d'envoyer un signal au processus fils pour **tout arrêter** <u><b>immédiatement</b></u>.
```c
#include <signal.h>
int kill(pid_t pid, int sig);
```
- `pid_t pid` l'identifiant du fils que l'on souhaite tuer
- `int sig` le signal à envoyer au processus pour le tuer *exemples : `SIGTERM` pour un signal de fin et `SIGKILL` pour un arrêt forcé immédiat*
La fonction `kill` renvoie `0` si tout vas bien sinon `-1`.

Prenons l'exemple suivant : 
- Création de trois fils qui tournent à l'infini 
- On tue les trois fils
- On analyse le signal
```c
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

void routine_fils(void){
	printf("FILS : Hey, je tourne à l'infini !\n");
	while (1){
		continue;
	}
}

void routine_pere(pid_t *pid){
	int status, i;
	printf("PERE : Je suis le père\n");
	i = 0;
	while(i<3){
		kill(pid[i], SIGKILL);
		i++;
	}
	printf("PERE : J'ai tué tous mes fils\n'");
	i=0;
	while(i<3){
		waitpid(pid[i], &status, 0);
		if(WIFEXITED(status)){
			printf("FILS [%d] : a terminé normalement\n");
		}
		else if(WIFSIGNALED(status)){
			printf("FILS [%d] a été interrompu !\n");
			if(WTERMSIG(status)==SIGTERM){
				printf("FILS [%d] a reçu le signal %d SIGTERM\n", pid[i], WTERMSIG(status));
			}
			else if(WTERMSIG(status)==SIGKILL){
				printf("FILS [%d] a reçu le signal %d SIGKILL\n", pid[i], WTERMSIG(status));
			}
		}
		i++;
	}
}

int main(void){
	pid_t pid[3];
	int i = 0;
	while(i < 3){
		pid[i] = fork();
		if(pid[i]==-1){
			return EXIT_FAILURE;
		}
		else if(pid[i]==0){
			routine_fils();
		}
		else if(pid[i]>0){
			printf("FILS #%d cree avec PID = %d\n", i, pid[i]);
		}
		usleep(1000); // Intervalle de temps
		i++;
	}
	routine_pere(pid);
	return EXIT_SUCCESS;
}
```

```
FILS #0 cree avec PID = 1887
FILS : Hey, je tourne à l'infini !
FILS #1 cree avec PID = 1888
FILS : Hey, je tourne à l'infini !
FILS #2 cree avec PID = 1889
FILS : Hey, je tourne à l'infini !
PERE : Je suis le père
PERE : J'ai tué tous mes fils
FILS [443063288] a été interrompu !
FILS [1887] a reçu le signal 9 SIGKILL
FILS [443063288] a été interrompu !
FILS [1888] a reçu le signal 9 SIGKILL
FILS [443063288] a été interrompu !
FILS [1889] a reçu le signal 9 SIGKILL
```

## À retenir
`fork` permet de créer un fils
```c
int res = fork();
if(res == -1){
	// Le fork renvoi une erreur
	printf("erreur de fork()\n");
}
if(res == 0){
	// On est dans le processus fils
	// ROUTINE DU FILS
}
if(res > 0){
	// On est dans le processus père
	// ROUTINE DU PERE
}
```
- `-1` erreur
- `0` dans le fils
- `>0` dans le père

`sleep` et `usleep` permettent de faire attendre un processus un certain temps.
```c
sleep(1); // Attendre 1 seconde
```

`wait` et `waitpid` permettent de faire attendre un processus tant qu'un autre n'a pas terminé.
- `wait` fait attendre un processus jusqu'à ce que n'importe quel autre processus se termine en premier.
- `waitpid` fait attendre un processus jusqu'à ce que le processus au `pid` entré en paramètre se termine.

- `exit` permet de terminer proprement un processus.
- `kill` permet de tuer un processus

## Compléments
- Sur les pipes  : [[Complément - Tube unidirectionnel]]
- Sur les topologies de processus : [[Complément - Topologie processus]]
