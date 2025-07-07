# Tableaux statiques

>[!cite] Définition
>On appelle **==tableau statique==** un ensemble de variables **du même type** ayant une **taille fixe**[^1] et où chaque élément est indexé par un indice.  
>*Le numéro qui leur ai attribué représente leur position dans le tableau*.

[^1]: Cela veut donc dire que la taille du tableau, donc l'espace mémoire du tableau est allouée par la machine lors de la déclaration de ce dernier.

<u>Exemple :</u>  
On considère une suite de nombres `42, 17, 89, 3, 56, 91, 24, 68`. On représente alors ces nombres dans un tableaux :  

<table border="1">
  <tr>
    <th>42</th>
    <th>17</th>
    <th>89</th>
    <th>3</th>
    <th>56</th>
    <th>91</th>
    <th>24</th>
    <th>68</th>
  </tr>
</table>

On dispose des informations suivantes :  
- La taille du tableau *ici 8*
- L'ordre dans lequel on veut que soit les nombres

>[!warning] Attention
>L'ordre des éléments du tableau reprend l'ordre dans lequel sont donnés les nombres.

## Déclaration d'un tableau en C
### Un tableau sans éléments

On considère un tableau nommé `tab` de `t`-éléments permettant de stoker des variables de type `type`. 
Alors la déclaration d'un tel tableau se fait comme suit :

```
type tab[t] ;
```

On peut le lire comme ceci : *Créer un tableau nommé `tab` de `t` éléments de type `type`.* On voit donc bien que la taille du tableau est défini dès la déclaration.  
**Sans oublier ce fameux `;`**

<u>Exemple :</u>  
On souhaite définir un tableau de $10$ entiers.

```c
int tab_entier[10];
```
### Un tableau préremplit

On considère un tableau nommé `tab` de `t`-éléments permettant de stoker des variables de type `type`, chaque élément du tableau sera noté `e_i` où `i` représente le `i`-ème élément du tableau. 
Alors la déclaration d'un tel tableau se fait comme suit :

```
type tab[t] = { e1, e2, e3, ..., et } ;
```

<u>Exemple :</u>  
On souhaite définir un tableau de $10$ entiers : `1 2 3 4 5 ...`.

```c
int tab_entier[10]={ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
```

### Utiliser une MACROS 
- Rappels sur les macros : [[02 - Premiers pas#Les constantes]]

Imaginons que vous vous lancez le projet de coder un labyrinthe en C, votre programme pourrait ressembler à ceci :  
*Ce code n'est absolument pas fonctionnel*

```c
#include <stdio.h>

void afficher_labyrinthe(int labyrinthe[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (labyrinthe[i][j] == 0)
                printf("█ ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

int main() {
    int labyrinthe[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    printf("Labyrinthe :\n");
    afficher_labyrinthe(labyrinthe);

    return 0;
}
```

Maintenant, vous avez envie d'utiliser votre labyrinthe mais avec d'autres tailles.  
Or ici, si vous changez la taille de votre labyrinthe, il vas falloir changer la déclaration, l'initialisation de votre tableau, changer les fin de boucles.  
Et oue, on a la flemme ! 

On vas donc utiliser une macros, vous savez ces genre de constantes comme ça pour tester sur plusieurs tailles de labyrinthe, il suffira simplement de changer la valeur de cette dernière et c'est réglé !  
Voilà comment on procède : 

- On défini la macros qui représente la taille du tableau *ici 5*
```c
#define TAILLE 5
```

- Les boucles, et définitions se font donc en fonction de `TAILLE` :

```c
#include <stdio.h>

#define TAILLE 5

void afficher_labyrinthe(int labyrinthe[TAILLE][TAILLE]) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            if (labyrinthe[i][j] == 0)
                printf("█ ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

int main() {
    int labyrinthe[TAILLE][TAILLE] = init_matrice(TAILLE);

    printf("Labyrinthe (avec macro) :\n");
    afficher_labyrinthe(labyrinthe);

    return 0;
}
```

Cela nous pousse aussi à créer une fonction pour initialiser la matrice en fonction de la taille souhaitée car, si on garde le code suivant : 

```c
int labyrinthe[TAILLE][TAILLE] = {
    {0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    };
```

Et ben peu importe la valeur de `TAILLE`, les cinq premières lignes et colonnes du tableau seront remplies mais pas les autres.  
D'ailleurs, cela va poser quelques problèmes si le tableau devient plus petit... *On verra cela plus tard*
## Opérations sur les éléments

Bon okay, c'est cool on a créé et initialisé notre tableau, maintenant comment je fais pour accéder, modifier ou encore supprimer un élément dans le tableau.  
On reprend le tableau de la partie précédente et on souhaite accéder à l'élément `e3`. 

Ce que l'on sait c'est que `e3` est le 3e élément du tableau.  
L'accès aux éléments d'un tableau se fait via des numéros aussi appelés **indices**, ils permettent de savoir quel élément du tableau on souhaite récupérer.  

>[!warning] Attention
>Le premier élément d'un tableau est à l'**indice 0**.

Ainsi, on accès au troisième élément comme ceci : 

```c
tab[2] ;
```

De manière générale on note :  

```
tab[i] ;
```

Et on peut le lire comme suit : *Accéder au `i+1`-ème élément du tableau `tab`.*  
`i+1` car le premier élément est à l'indice `0`.

## Remplissage du tableau
### Avant remplissage

On considère un tableau `tab` d'une certaine taille `t` contenant des entiers initialisé comme ceci : 

```c
int tab[t] ;
```

où `t` est définie avant.

Maintenant, on est en droit de se poser une question, y a quoi dans chaque cases de mon tableau ?  
Bah oui, on a créé un tableau d'une certaine taille, ça c'est compris mais on l'a pas remplit.

Voyons ce qu'il se passe lorsque j'essai d'accéder à un élément du tableau sans l'avoir rempli avant.

<u>Exemple :</u>    
On considère le code suivant :

```c
#include <stdio.h>
#define t 4

int main() {
    int tab[t];
    printf("%d\n", tab[3]);
    return 0;
}
```

Voilà ce qu'on fait dans ce code : 
- On utilise la bibliothèque `stdio.h` pour pouvoir utiliser `printf`
- On défini `t=4` une sorte de constante
- Dans la fonction `main`
	- Création d'un tableau de `4` éléments
	- Affichage du $3+1$ème élément du tableau `tab`
	- On retourne 0

Résultat du programme :

```
30863
```

C'est trop bizarre, j'ai pas remplis mon tableau pourtant il contient quand même quelque chose.  
Voyons ce que chaque élément représente :  
*On ajoute simplement une boucle `for` pour permettre de parcourir chaque éléments du tableau et de l'afficher :*

```c
#include <stdio.h>
#define t 4

int main() {
    int tab[4];
    for(int i=0; i<t; i++) printf("tab[%d] : %d\n", i, tab[i]);
    return 0;
}
```

Résultat du programme : 

```
tab[0] : 0
tab[1] : 0
tab[2] : -324399248
tab[3] : 31515
```

On voit donc bien que chaque élément possède une valeur malgré le fait que l'on n'ai pas remplit le tableau.  
De plus, le dernier élément du tableau n'est pas le même que celui donné lors de la première exécution. En fait, c'est normal. Puisque l'on a pas remplit le tableau, ce dernier possède des valeurs dites **indéterminées** qui sont aléatoires.

Les valeurs données aux éléments du tableau dépendent de ce qu'il y avait dans la mémoire juste avant, ou parfois, le compilateur réutilise la mémoire fraichement libérée. Ce comportement est complètement aléatoire c'est pour ça qu'on peut obtenir `0` ou des nombres très grands.

### Le remplissage

Le remplissage d'un tableau en C peut se faire de différentes manières. On peut vouloir le remplir à la main, le remplir automatiquement avec des valeurs fixes, ou alors avec des valeurs aléatoires.  
Voyons ces trois méthodes de remplissages :

#### Remplissage manuel

En fait, le remplissage manuel, on l'a déjà utilisé avant. Au début de ce cours, on avait un tableau qui contenait les éléments suivants : 

<table border="1">
  <tr>
    <th>42</th>
    <th>17</th>
    <th>89</th>
    <th>3</th>
    <th>56</th>
    <th>91</th>
    <th>24</th>
    <th>68</th>
  </tr>
</table>

En fait, en langage C un tableau est une structure que l'on représente entre accolades `{...}` où chaque éléments est séparé par une virgule.  
Alors le tableau ci dessous vas donner la structure suivante : 

```
{ 42, 17, 89, 3, 56, 91, 24, 68 }
```

Ainsi l'initialisation du tableau se fera ainsi : 

```c
int tab[8] = { 42, 17, 89, 3, 56, 91, 24, 68 };
``` 

#### Remplissage automatique
##### Valeurs fixées

Le remplissage manuel, est certes simple mais peut s'avérer terriblement long à faire pour des tableaux de grandes tailles par exemple. Ou encore mieux, si chaque élément du tableau était fixé avec une logique, le remplissage manuel peut se faire automatiser.  
Regardons un cas pratique parmi tant d'autres : 

$\boxed{\text{Étude d'un cas pratique}}$  
On souhaite créer un tableau d'une certaine taille `t` que l'on déterminera de manière arbitraire, ce dernier doit stocker les `t` premiers multiples d'un nombre donné au programme.  
Par exemple si j'exécute : 

```
./prog 4 10
```

Le programme doit afficher les $10$ premiers multiples de $4$.

>Pour ce programme nous allons procéder par étapes :
>- Décomposition des étapes
>- Description du travail à faire
>- Codage
>- Compilation et exécution du programme

<u>Objectif :</u> Stocker dans un tableau les $n$ premiers multiples d'un entier $k$ donné au programme lors de l'exécution.

<u>Division du programme en étapes </u>
- Récupérer les données fournies au programme  
  Penser à valider si elles sont valides (le bon nombre, des entiers, ...)
- Création du tableau
- Remplissage du tableau
- Affichage du résultat

*Récupération des données fournies au programme*  
La première étape vas être de récupérer les informations données au moment de l'exécution au programme. Ici on a deux informations à récupérer :
- L'entier $k$ qui représente le nombre sur lequel on travail
- L'entier $n$ qui détermine la taille du tableau
Donc on doit fournir à notre programme $2$ arguments.  
Et ben enfaite NON ! 

Voyons une exécution : les $10$ premiers multiples de $4$.

```
./prog 4 10
```
Alors ici on a :
- argument 1 : Le nom du fichier exécuté
- argument 2 : Le nombre sur lequel on souhaite travailler
- argument 3 : Le nombre de multiples à stocker

Ainsi, pour pouvoir s'exécuté il faut fournir trois arguments **pas plus, pas moins**.

*Mais où on stocke les arguments et comment on connaît leur nombre ?*  
Et bien puisque les informations sont transmises au programme principale, nous allons les donner à la point d'entrée du programme : la fonction `main`.

La signature de la fonction `main` sera la suivante : 

```c
int main(int argc, char* argv[]);
```
- `argc` le nombre d'arguments fournis au programme
- `argv[]` le tableau qui contient les informations fournies

>[!warning] Attention
>- Tous les éléments de `argv` sont des **chaînes de caractères** (`char *`) même si tu tapes des nombres.
>- Il faut utiliser `atoi()` ou `strtol()` pour convertir `"4"` → `4` (en `int`).

Ce qu'il nous reste à faire pour la première étape : 
- Vérifier que le programme reçoit 3 arguments
- Récupérer les 2 derniers

Algorithme pseudo-code :
```
Si argc est différent de 3
	Déclancher une erreur et stopper le programme
Sinon continuer
```

```c
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Erreur argument : %s <nombre> <taille>\n", argv[0]);
        return 1;
    }
	
	// Récupération des derniers arguments
	// On utilise atoi() pour convertir les arguments en entier !
	int k = atoi(argv[1]);  // Le nombre dont on veut les multiples
    int n = atoi(argv[2]);  // Le nombre de multiples
}
```

*Création du tableau*  
On doit donc créer un tableau de $n$ éléments.

```c
int tab[n];
```

*Remplissage du tableau*  
On remplit le tableau avec des multiples de $k$.  
Pour rappel, on dit que $x$ est un multiple de $k$ lorsque $x$ peut s'écrire $x=ky$ avec $y$ un entier naturel.

Ce qu'il faut donc faire c'est parcourir le tableau créé juste avant et pour chaque élément, multiplier $k$ par son indice courant $+1$. 

>[!note] Note
>Ici on ne compte pas $0$ comme multiple malgré qu'il en soit un.

```c
for(int i=0; i<n; i++) 
	tab[i]=k*(i+1);
```

Ainsi notre tableau contiendra les éléments suivants de manière générale : `{k, 2k, 3k, ..., nk}`.

*Affichage du tableau*  
On fais une simple boucle `for` pour parcourir les éléments un à un et on les affiches. *ici, je vais afficher le tableau entre crochets (comme en python).*

```c
printf("[ ");
for(int i=0; i<n-1; i++) 
	printf("%d, ", tab[i]);
printf("%d ]\n", tab[n-1]);
```

ainsi on obtient le code final suivant : 

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Erreur argument : %s <nombre> <taille>\n", argv[0]);
        return 1;
    }
	
	// Récupération des derniers arguments
	// On utilise atoi() pour convertir les arguments en entier !
	int k = atoi(argv[1]);  // Le nombre dont on veut les multiples
    int n = atoi(argv[2]);  // Le nombre de multiples
    int tab[n];             // Création du tableau
    
    // Remplissage
    for(int i=0; i<n; i++) 
		tab[i]=k*(i+1);
		
	// Affichage
	printf("[ ");
	for(int i=0; i<n-1; i++) 
		printf("%d, ", tab[i]);
	printf("%d ]\n", tab[n-1]);
	return 0;
}
```

On exécute ce code `multiple.c`

```
gcc -o prog multiples.c
./prog 4 10

[ 4, 8, 12, 16, 20, 24, 28, 32, 36, 40 ]
```