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
                printf(". ");
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
# Tableaux dynamiques