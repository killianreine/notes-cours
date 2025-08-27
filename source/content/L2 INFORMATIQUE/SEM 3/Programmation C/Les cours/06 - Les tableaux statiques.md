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

# Déclaration d'un tableau en C
## Un tableau sans éléments

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
## Un tableau préremplit

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

## Utiliser une MACROS 
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
# Opérations sur les éléments
## Accès à un élément

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

<u>Exemples :</u>  
On récupère le second élément d'un tableau d'entier et on l'affiche.

```c
#include <stdio.h>

int main(){
	int tab[] = {45, 12, 85, 97, 23};
	int second = tab[1]; // On récupère le second élément de tab
	
	// Affichage
	printf("%d \n", second);
}
```
```
12
```
## Modification d'un élément

On peut avoir besoin de modifier un élément, on utilise alors la forme générale suivante : 

```
tab[indice] = nouvelValeur;
```

On peut le lire comme : *Je modifie la `indice-1`-ième valeur du tableau par `nouvelle valeur`*.
# Remplissage du tableau
## Avant remplissage

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

On peut aussi donner une initialisation d'un tableau sans donner sa taille :

```c
type tab[] = {elem1, elem2, ..., elemN};
```

Ainsi ici `tab` sera de taille `N`.

## Le remplissage

Le remplissage d'un tableau en C peut se faire de différentes manières. On peut vouloir le remplir à la main, le remplir automatiquement avec des valeurs fixes, ou alors avec des valeurs aléatoires.  
Voyons ces trois méthodes de remplissages :

### Remplissage manuel

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

#### Autres méthodes possibles

On peut remplir une liste d'un certain élément avec la syntaxe `{elem}` où `elem` est l'élément que l'on veut stocker dans chaque emplacement du tableau.

<u>Exemple :</u>  
On souhaite stocker $10$ éléments initialisés à $0$.

```c
int tab[10] = { 0 };
```

On peut vérifier :

```c
#include <stdio.h>

int main() {
    int tab[10] = { 0 };
    for (int i=0; i<10; i++) printf("%d ", tab[i]);
    return 0;
}
```
```
0 0 0 0 0 0 0 0 0 0
```

On peut aussi fournir un tableau à $n$ éléments pour initialisé un tableau de $t$ éléments. Et, $n$ peut être :
- égal à $t$  
  Ainsi, toutes les cases du tableau sont remplies par un élément définie
- plus petit que $t$  
  Dans ce cas les $n$ première cases prendront les valeurs du tableau d'initialisation et les autres $0$
- plus grand que $t$  
  Ce qui déclenchera une erreur à la compilation

```c
#include <stdio.h>

int main() {
	// Initialisation de tab avec un tableau plus petit que lui
    int tab[10] = { 0, 1, 2, 3 };
    for (int i=0; i<10; i++) printf("%d ", tab[i]);
    return 0;
}
```
```
0 1 2 3 0 0 0 0 0 0 0
```

ici, le tableau d'initialisation est :

```c
tabInit[] = {0, 1, 2, 3};
```

il est donc de taille $4$ plus petit que `tab` qui est de taille $10$ ainsi, en initialisant `tab` avec `tabInit` alors les $4$ premiers éléments du tableau seront ceux de `tabInit` et les autres $6 \to 10$ seront initialisés à $0$.
### Remplissage automatique
#### Valeurs fixées

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

🔁 Objectif  
Stocker dans un tableau les $n$ premiers multiples d'un entier $k$ donné au programme lors de l'exécution.

🧩 Étapes  
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

./prog 4 5
[ 4, 8, 12, 16, 20 ]

./prog 258 12
[ 258, 516, 774, 1032, 1290, 1548, 1806, 2064, 2322, 2580, 2838, 3096 ]
```

#### Valeurs aléatoires

🔁 Objectif  
Remplir un tableau de taille `n` avec **des valeurs aléatoires comprises dans une certaine plage**, par exemple entre `0` et `99`.  
On garde la logique du programme avec les arguments, mais cette fois **le deuxième argument ne servira que pour la taille du tableau** (le premier argument ne sera plus nécessaire).

🧩 Étapes
1. Récupérer l'argument `n` (taille du tableau)
2. Créer un tableau de taille `n`
3. Le remplir avec des entiers aléatoires (entre 0 et 99)
4. Afficher le tableau

###### L'aléatoire en programmation C ^aleatoire

En langage C, on peut avoir besoin de l'aléatoire pour diverses raisons, simulations de phénomènes par exemple. 

Pour générer un entier de manière aléatoire, on utilise `rand` :

```c
int rand(void);
```

Cette fonction fais partie de `<stdlib.h>` elle va générer un nombre aléatoire entre $0$ et `RAND_MAX` souvent autour de $32 767$. 

On peut contrôler l'intervalle de génération des nombres aléatoires en C, toujours avec la fonction `rand` sauf que dans ces cas là on utilise la syntaxe suivante : 

```
int nbAlea = rand() % borne;
```
Ainsi, on aura :

$$
0 \leq nbAlea \leq borne-1
$$

<u>Exemple :</u>  
Générer un nombre aléatoire entre $0$ et $10$ :

```c
int x = rand() % 11;
```

Si on veut que $x \in [a; b]$  
Alors dans ces cas là, on utilise la forme suivante : 

```c
int x = rannd() % (b-a+1)+a;
```

>[!info] Remarque
>`x=rand() % 12;` va renvoyer par exemple $10$ à la première exécution. Et bien, vous allez voir qu'à chaque autre exécution $10$ sera toujours le nombre renvoyé.

Pour contrer cela, on utilise `srand(time(NULL));` :
```c
#include <time.h>
srand(time(NULL));
```

Cette ligne permettra de faire en sorte que les valeurs aléatoires changent lors de chaque exécution de votre programme.

Suite aux rappels sur l'aléatoire,  
Ainsi le code final donne : 
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Erreur argument : %s <taille>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);  // Taille du tableau
    if (n <= 0) {
        printf("Erreur : la taille doit être un entier positif.\n");
        return 1;
    }

    int tab[n];  // Création du tableau

    srand(time(NULL));  // Initialisation de l'aléatoire

    // Remplissage aléatoire entre 0 et 99
    for (int i = 0; i < n; i++) {
        tab[i] = rand() % 100;
    }

    // Affichage du tableau
    printf("[ ");
    for (int i = 0; i < n - 1; i++) {
        printf("%d, ", tab[i]);
    }
    printf("%d ]\n", tab[n - 1]);

    return 0;
}
```

```
gcc -o prog random.c

./prog 10
[ 12, 87, 5, 63, 22, 94, 18, 49, 10, 73 ]

./prog 5
[ 31, 9, 66, 0, 45 ]
```

# Affichage d'un tableau
Contrairement à un langage comme Python, l'affichage du tableau ne se fait pas nativement. En fait c'est à vous de déterminer comment ce dernier vas s'afficher.
## En python
```python
tableau = [1, 2, 3, 4, 5, 6]
print(tableau)
```
```
[1, 2, 3, 4, 5, 6]
```

## En langage C
```c
#include <stdio.h>

int main(){
	int tableau[4] = {1, 2, 3, 4};
	printf(tableau);
	return 0;
}
```
```less
ERROR!
In function 'main':
error: passing argument 1 of 'printf' from incompatible pointer type [-Wincompatible-pointer-types]
    5 |         printf(tableau);
      |                ^~~~~~~
      |                |
      |                int *
```

Alors oui, une erreur directe.  
Ce que dit l'erreur c'est que l'argument passé dans le `printf` est incompatible. Et, cela affiche que tableau est un `int*`, un **==pointeur==** d'entier *Notion que l'on abordera plus tard...* 

```c
#include <stdio.h>

int main(){
	int tableau[4] = {1, 2, 3, 4};
	printf("%d\n", tableau);
	return 0;
}
```
```
1812024368
```

ici, la programme affiche un entier puisque `%d` dans le format du `printf`. L'entier représente l'identifiant de l'adresse mémoire interprétée comme un entier du tableau.

>[!info] Remarque
>Pour afficher **proprement** une adresse mémoire, on utilise `%p`.

```c
#include <stdio.h>

int main(){
	int tableau[4] = {1, 2, 3, 4};
	printf("%p\n", tableau);
	return 0;
}
```
```
0x7ffd5f5402a0
```

### Affichage personnalisés
Pour afficher un tableau en langage C, il vas donc falloir que vous le parcourriez d'éléments en éléments pour les afficher successivement.  
En principe sans faire aucun formatage supplémentaire, on peut obtenir le visuel suivant : 

```c
#include <stdio.h>

int main(){
	int tableau[4] = {1, 2, 3, 4};
	// Parcours avec une boucle for
	for(int i = 0; i<4; i++){
		printf("%d ", tableau[i]);
	}
	return 0;
}
```
```
1 2 3 4 
```

On peut l'améliorer en ajoutant des virgules entre chaque éléments et en ajoutant les crochets au début et à la fin du tableau comme en python.

```c
#include <stdio.h>

int main(){
	int tableau[4] = {1, 2, 3, 4};
	// Parcours avec une boucle for
	printf("[ ");
	for(int i = 0; i<4; i++){
		printf("%d, ", tableau[i]);
	}
	printf("]");
	return 0;
}
```
```
[ 1, 2, 3, 4, ]
```

Bon okay, c'est presque ça mais c'est bête d'avoir la virgule après le dernier éléments. Pour contrer ça, rien de plus simple, on parcours le tableau jusqu'à l'avant dernier élément ici le troisième. Et **après la boucle `for`**, on affiche le dernier élément du tableau suivit du crochet fermant :

```c
#include <stdio.h>

int main(){
	int tableau[4] = {1, 2, 3, 4};
	// Parcours avec une boucle for
	printf("[ ");
	for(int i = 0; i<3; i++){
		printf("%d, ", tableau[i]);
	}
	printf("%d ]", tableau[3]);
	return 0;
}
```
```
[ 1, 2, 3, 4 ]
```
# Tableaux multidimensionnels

>[!cite] Définition
>On appelle **==tableau a plusieurs dimension==** un ensemble de tableau contenant le même nombre d'éléments. Chaque "sous-tableau" représente ce qu'on peut appeler une ligne.

## Déclaration et initialisation
### Méthode 1

On considère trois tableaux :
- `tab1 = {1, 2, 3, 4}`
- `tab2 = {2, 3, 4, 5}`
- `tab3 = {3, 4, 5, 6}`

Ainsi on peut appeler `tabMultiDim` le tableau : `{ tab1, tab2, tab3 }` qui est aussi égal à :  
`tabMultiDim = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}}`  
Et représenté par : 

<table border="1">
  <tr>
    <th>1</th>
    <th>2</th>
    <th>3</th>
    <th>4</th>
  </tr>
    <tr>
    <th>2</th>
    <th>3</th>
    <th>4</th>
    <th>5</th>
  </tr>
    <tr>
    <th>3</th>
    <th>4</th>
    <th>5</th>
    <th>6</th>
  </tr>
</table>

On voit bien que : 
- Ligne 1 représente `tab1`
- Ligne 2 représente `tab2`
- Ligne 3 représente `tab3`

Dans notre exemple, on a une tableau à deux dimensions de taille $4 \times 3$ que l'on définit et initialise comme ceci : 

>[!info] Remarque
>Le choix de représentation visuel des matrices est choisit de manière uniquement visuel, lors de vos exécution, un tableau ne sera pas affiché comme ceci dans le terminal, **pas comme en Python...**.

```c
#include <stdio.h>

int main(){
    int matriceV2[3][4] = {
    	{1, 2, 3, 4}, // tab1
    	{2, 3, 4, 5}, // tab2
    	{3, 4, 5, 6}, // tab3
    };
    return 0;
}
```
```
[
[1 2 3 4 ]
[2 3 4 5 ]
[3 4 5 6 ]
]
```

De manière générale, on note : 

```
type tabMultiDim[l][c] = {
	{e11, e12, ..., e1c},
	{e21, e22, ..., e2c},
	...
	{el1, el2, ..., elc}
};
```

Où :
- `l` représente le nombre de ligne
- `c` représente le nombre de colonne
- $e_{ij}$ avec $i \in [1; l]$ et $j \in [1; c]$ représente l'élément à la ligne $i$ et colonne $j$.

De manière plus mathématiques, on représente celle ci par : 

$$
tab = \begin{bmatrix} [&e_{11}& e_{12}& \ldots & e_{1c}&] \\ [&e_{21} & e_{22} & \ldots & e_{2c}&]  \\ &\vdots & \vdots &  & \vdots \\ [& e_{l1} &e_{l2}&\ldots& e_{lc} &] \end{bmatrix}
$$

>[!note]
>D'une manière plus grossière, on dit qu'un tableau à deux dimension est une **matrice** ou encore **un tableau de tableau**.

### Méthode 2
On peut initialiser un tableau à plusieurs dimensions d'une autre façon, prenons un tableau de taille $3 \times 3$. On sait que le tableau contient trois sous tableaux de trois éléments donc 9 éléments en tout, on peut alors utiliser un tableau simple de 9 éléments pour initialiser le tableau $3 \times 3$.

```c
int matrice33[3][3]={10, 20, 30, 40, 50, 60, 70, 80, 90};
```
```
[
[ 1 2 3 ],
[ 4 5 6 ],
[ 7 8 9 ],
]
```

On voit alors que les trois premiers éléments du tableau d'initialisation représente la première ligne, les trois suivant la 2e et les trois derniers la troisième. En fait le tableau simple a été découpé en trois et chaque partie représente une ligne.

### Initialisation incomplète
C'est lorsqu'on initialise certains éléments mais pas tous, on a vu avec un tableau unidimensionnel, cela initialise les autres cases par $0$ pour des tableaux d'entiers.

```c
int matrice23[2][3] = {
    {1},   
    {12, 10},     
};
```
```
[
[1  0  0]
[12 10 0]
]
```

```c
int mat[2][3] = {'a'};
```
```
[
[ a     ]
[       ]
[       ]
]
```
Tous les autres éléments **sauf** le premier valent $0$.

## Accès aux valeurs
Pour accéder aux éléments qui se trouvent dans un tableau bidimensionnel, il suffit de récupérer le nom du tableau, le numéro de la ligne et le numéro de la colonne de l'élément à récupérer.
```
tableau[ligne][colonne]
```

Je récupère la variable dans le tableau `tableau` positionné à la ligne `ligne` et la colonne `colonne`.

<u>Exemple :</u>  
On récupère une variable dans une matrice.

```c
#include <stdio.h>

int main(){
	int tableau[3][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	/*
	Matrice 3*5
	[
	[1,  2,  3,  4,  5 ]
	[6,  7,  8,  9,  10],
	[11, 12, 13, 14, 15]
	]
	*/
	// On récupère l'élément de coordonnées (1, 4) dans la tableau.
	int e14 = tableau[1][4];
	printf("Element ligne 2 colonne 4 : %d \n", e14);
	return 0;
}
```
```
Element ligne 2 colonne 4 : 10 
```

## Affichage des tableaux multidimensionnels
Pour rappel, on affiche un tableau à $1$ dimension en le parcourant et en affichant chaque élément un par un. Pour les tableau à plusieurs dimensions, on fait pareil :
- On parcours chaque ligne
- On affiche chaque élément de chaque ligne

On utilise donc autant de boucle for que de dimensions :  
Pour un tableau $2D$
1. Récupérer les sous-tableaux 
2. Parcourir les "colonnes" et afficher

<u>Exemple :</u>  
Affichage d'un tableau à $2$ dimensions.
```c
#include <stdio.h>
#define LIGNE 4
#define COLONNE 3

int main(){
	int tableau[LIGNE][COLONNE] = {{1, 2, 3}, {7, 8, 9}, {1, 5, 7}};
    
    // Parcourir chaque lignes
	for(int l=0; l<LIGNE; l++){
	    // Parcourir chaque élément de chaque ligne
	    for(int c=0; c<COLONNE; c++){
	        //Affichage
	        printf("%d ", tableau[l][c]);
	    }
	    // On passe à la ligne pour chaque nouvelles lignes
	    printf("\n");
	}
	return 0;
}
```
```
1 2 3 
7 8 9 
1 5 7 
0 0 0
```

On peut améliorer en ajoutant des crochets et des virgules pour chaque tableaux.

```c
#include <stdio.h>
#define LIGNE 4
#define COLONNE 3

int main(){
	int tableau[LIGNE][COLONNE] = {{1, 2, 3}, {7, 8, 9}, {1, 5, 7}};
    printf("[\n");
	for(int l=0; l<LIGNE; l++){
	    printf("[ ");
	    for(int c=0; c<COLONNE-1; c++){
	        printf("%d, ", tableau[l][c]);
	    }
	    printf("%d ]\n", tableau[l][COLONNE-1]);
	}
	printf("]");
	return 0;
}
```
```
[
[ 1, 2, 3 ]
[ 7, 8, 9 ]
[ 1, 5, 7 ]
[ 0, 0, 0 ]
]
```

# Gestions d'erreurs

Pour ne pas être trop lourd, nous allons nous contenter d'expliquer quelques erreurs concernant les tableaux statiques, les plus fréquentes.

## Tableau d'init trop grand

Un peu avant dans ce cours, nous avons dit que lorsque l'on initialise un tableau à la main, il peut arriver qu'il soit plus petit, plus grand ou égal au nombre d'éléments voulu dans le tableau créé.  
On a déjà vu ce qu'il se passait lorsque :
- Plus petit
- Égal

Voyons ce qu'il se passe maintenant si on utilise un tableau d'initialisation trop grand :

```c
#include <stdio.h>

int main(){
	// 5 éléments voulu, on initialise avec 9 éléments
	int tab[5] = {45, 12, 85, 97, 23, 48, 58, 200, 11};
	return 0;
}
```
```less
warning: excess elements in array initializer
    4 |         int tab[5] = {45, 12, 85, 97, 23, 48, 58, 200, 11};
      |                                           ^~
```

En français, l'erreur signifie qu'il y a trop d'éléments pour initialiser le tableau.  
L'erreur se répète sur chaque élément suivant dans le tableau : 

```less
warning: excess elements in array initializer
    4 |         int tab[5] = {45, 12, 85, 97, 23, 48, 58, 200, 11};
      |                                           ^~
warning: excess elements in array initializer
    4 |         int tab[5] = {45, 12, 85, 97, 23, 48, 58, 200, 11};
      |                                               ^~
warning: excess elements in array initializer
    4 |         int tab[5] = {45, 12, 85, 97, 23, 48, 58, 200, 11};
      |                                                   ^~~
warning: excess elements in array initializer
    4 |         int tab[5] = {45, 12, 85, 97, 23, 48, 58, 200, 11};
      |                                                        ^~
```

## Initialiser un élément inexistant

Soit `tab` un tableau de $5$ éléments, voyons ce qu'il se passe si on initialise un 6e élément : 

```c
#include <stdio.h>

int main(){
	// 5 éléments voulu, on initialise avec 9 éléments
	int tab[5];
	tab[5] = 41;
	return 0;
}
```

>[!warning] Attention
>🔴 **Comportement indéfini** : le programme peut planter, écrire ailleurs en mémoire, ou ne rien signaler du tout.

## Utiliser une variable de taille

Depuis `C99` on peut utiliser une variable pour stocker la taille du tableau : 

```c
int n = 10;
int tab[n];  // ❌ Pas valide en C90, valide en C99
```

## Débordement

Il peut arriver que lorsque l'on parcours un tableau on puisse déborder (essayer d'accéder à des éléments non existant) : 

```c
for (int i = 0; i <= 10; i++)  // ❌ i <= 10 pour tab[10] → déborde !
    tab[i] = i;
```

# Utilisation des tableaux
## Paramètre de fonction
On peut avoir besoin de passer un ou plusieurs tableaux en paramètres d'une fonction, et il est vrai que ça peut être plus complexe.  
On considère un tableau `tab` d'un certain nombre d'éléments et une fonction `fct` qui prend en paramètre un argument qui est le tableau, voici comment on peut lui donner `tab` comme argument : 
```c
type_retour fct(type[] tab);
```

<u>Exemple :</u>  
On prend un tableau d'un certain nombre et sa taille puis on affiche les éléments.
```c
#include <stdio.h>

void afficherTab(int tab[], int taille){
    for(int i=0; i<taille; i++) printf("%d ", tab[i]);
}

int main(){
    int tab[] = {0, 1, 2, 3, 4, 5};
	afficherTab(tab, 6);
	return 0;
}
```
```
0 1 2 3 4 5
```

## Déterminer la taille du tableau 

Et si on veut déterminer la taille du tableau :
- sans la passer en argument
- sans la stocker dans une variable

Un problème se pose, comment déterminer la taille du tableau sans l'avoir stockée avant.  
On utilise une fonction `sizeof` qui permet de déterminer la taille d'une variable. On l'utilise en $2$ étapes : 
- Déterminer la taille globale du tableau
- Diviser par la taille d'un élément du tableau (le premier souvent)

```c
int tab[] = {0, 1, 2, 3, 4, 5};
int taille = sizeof(tab) / sizeof(tab[0]);
printf("%d", taille);
```
```
6
```

### Erreur importante
Analysons le code suivant : 
```c
#include <stdio.h>

void afficherTab(int tab[]){
    int tailleTab = sizeof(tab)/sizeof(tab[0]);
    printf("Taille du tableau : %d\n", tailleTab);
    for(int i=0; i<tailleTab; i++) printf("%d ", tab[i]);
}

int main(){
    int tab[] = {0, 1, 2, 3, 4, 5};
	afficherTab(tab);
	return 0;
}
```

Voilà ce que fait ce code :
- La fonction `afficherTab`
	- Prend en paramètre un tableau `tab`
	- Elle calcule la taille du tableau (nombre d'éléments)
	- Elle affiche la taille
	- Puis elle parcours le tableau pour afficher les éléments un à un
- La fonction `main` est une application de la fonction `afficherTab`

Voici le résultat lors de **l'exécution** :
```less
In function 'afficherTab':
warning: 'sizeof' on array function parameter 'tab' will return size of 'int *' [-Wsizeof-array-argument]
    4 |     int tailleTab = sizeof(tab)/sizeof(tab[0]);
      |                           ^
note: declared here
    3 | void afficherTab(int tab[]){
      |                  ~~~~^~~~~
Taille du tableau : 2
0 1
```
En fait, ce qu'il se passe c'est que dans la fonction `afficherTab`,  le tableau que l'on passe en paramètre n'est pas vraiment un tableau c'est un pointeur qui pointe vers le premier élément du tableau (*on le reverra plus tard*).   
Le truc c'est que quand on passe un tableau en paramètre de fonction, il se dégrade pour devenir un pointeur.  
Ainsi, sur une machine $64$bits, la taille d'un pointeur est $8$ et la taille d'un entier $4$ ainsi dans tous les cas, on aura : 
```c
int tailleTab = sizeof(tab)/sizeof(tab[0]);
```
Qui renverra 2, c'est pour cette raison que l'on affiche les deux premiers éléments, or notre tableau e fait pas que deux éléments.

**Comment contrer l'erreur**  
Il suffit de calculer la taille du tableau juste après l'initialisation comme on l'a fait au dessus... 
```c
int tab[] = {1, 2, 3};
int tailleTab = sizeof(tab)/sizeof(tab[0]):
// Ou : sizeof(tab)/sizeof(int);
```

>[!info] Remarque
>Vous pouvez diviser la taille globale du tableau par : 
>- Le premier élément du tableau
>- Le type des variables qui se trouvent dans le tableau, ici `int`

<u>Exemple :</u>  
On code une fonction qui permet d'afficher correctement un tableau à 2 dimensions. On utilisera le format d'affichage équivalent à celui de python.  
*i.e. `[ [sous-tab1], [sous-tab2], ..., [sous-tabN] ]`*
```c
#include <stdio.h>

void afficherTab2D(int tab[3][3], int lignes, int colonnes){
    printf("[ ");
    for(int l=0; l<lignes; l++){
        printf("[ ");
        for(int c=0; c<colonnes-1; c++){
            printf("%d, ", tab[l][c]);
        }
        // Condition pour pas afficher la virgule après le dernier élément
        if(l==lignes-1)
            printf("%d ] ", tab[l][colonnes-1]);
        else
            printf("%d ], ", tab[l][colonnes-1]);
    }
    printf("]");
}

int main(){ 
    int tab[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	afficherTab2D(tab, 3, 3);
	return 0;
}
```
```
[ [ 1, 0, 0 ], [ 0, 1, 0 ], [ 0, 0, 1 ] ]
```

# BONUS
## Initialiser une matrice nulle
Pour rappel on appelle matrice nulle, une matrice dont tous les coefficients sont égal à $0$.

>[!warning] Attention
>La méthode d'initialisation ci contre n'est valide **uniquement si on veut mettre toutes les cases d'un tableau à 0** et avec des types simples (`int`, `char`,...).

```c
#include <string.h>
int mat[5][5];
memset(mat, 0, sizeof(mat));
```
```
[
[ 0 0 0 0 0 ],
[ 0 0 0 0 0 ],
[ 0 0 0 0 0 ],
[ 0 0 0 0 0 ],
[ 0 0 0 0 0 ],
]
```

## Quelques fonctions de `math.h`
>[!warning] 
>Penser à l'option `-lm` lors de la compilation

`cos`, `sin`, `tan`, `sqrt`, `asin`, `exp`, `log`, `floor`, ...
# Suivant
- Cours suivant : [[07 - Chaînes de caractères]]