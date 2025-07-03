# Généralités

## Définition

En langage `C`, une **fonction** est une partie de code *(bloc)* <u>réutilisable</u> qui effectue une tâche spécifique. Cette dernière permet de structurer un programme, de réduire la répétition de code *(= code lourd)* et de faciliter la maintenabilité/maintenance du code.

***Structure générale d'une fonction en `C` :***
```c
typeRetour nomFonction(typeParam1 nomParam1, typeParam2, nomParam2, ...){
   // Corps de la fonction
   instructions;
   return valeurDeRetour;
}
```

>[!NOTE]
>On peut rappeler que chaque instruction se termine par un *point-virgule* `;`.

###### Exemple

On souhaite créer une fonction `multiplication` qui prend en paramètres **2 entiers** `int` et renvoi **le produit**, un entier `int` des paramètres.
<br>Si on récap avant de coder : 

- <u>Nom de la fonction :</u> `produit`
- <u>Paramètres :</u> 2
   - Un entier `int`
   - Un autre entier `int`
- <u>Type de retour :</u> `int`

Ainsi, on obtient la fonction suivante : 

```c
int produit(int val1, int val2){
   int prod = val1 * val2;
   return prod;
}
```

*Et si on essayais de réduire ce code le plus possible ?*
<br>En réfléchissant, on a plusieurs solutions : 

- Des noms de variables plus "simple", car la fonction n'est pas très longue.
- Créer une variable `prod` n'est peut être pas la meilleure idée du siècle car au final on ne lui applique aucun traitement, elle est simplement directement renvoyée. 

Donc on obtient une fonction qui ressemble à ça : 

```c
int produit(int a, int b){
   return a*b;
}
```

Et voilà votre fonction `produit` implémentée de manière simple et rapide.

Bon c'est vrai, ça mange pas de pain et dans des gros programmes il est **fortement déconseillé** de nommer ses variables `a`, `b`, ..., il faut que tu puisses savoir qui correspond à quoi.

## Documentation d'une fonction

Quand tu bosses sur des gros projets il est toujours utile d'ajouter la **documentation** de ta fonction.
<br>La documentation s'est une trace écrite sur plusieurs lignes *(en commentaire)* permettant de décrire ta fonction : 

- Ce qu'elle fait
- Ce qu'elle retourne
- Ses paramètres

Elle est vite remarquable car elle se trouve entre `/**` et `*/`. Oui oui, il y a bien **2 astérisques** au début !

Ici on a une fonction `produit` qui prend deux variables entières et retourne leur produit. *La documentation suivante n'est pas "parfaite" mais c'est celle que j'utilise personnellement.*

```c
/**
  * Fonction produit permettant de calculer le produit de deux variables
  * @param int a : un entier a multiplier
  * @param int b : le multiplicateur
  * @return int
  */
int produit(int a, int b){
   return a*b;
}
```

*Ici c'est juste pour l'exemple, mais évidemment coder une fonction pour calculer le produit de deux variables ça n'a pas grande utilité puisque l'opérateur `*` le permet.*

>[!TIP]
>Quelques conseils que j'adopte personnellement : 
> - Utiliser des noms de variables / fonctions compréhensible, même si ils vous semblent trop long. <br>*Cela vous permettra de comprendre votre code même si vous n'y avez pas touché pendant 1 an.*
> - Commenter vos fonctions, si elles sont assez longue ajouter des commentaires sur une ligne `//....` est vraiment très utile.
> - Pour la relecture/debugge ou autre essayez de structurer votre code en espaçant par exemple les boucles, les conditions ou autre *(Voir exemple EUCLIDE)*.

### Exemple : Algorithme d'Euclide

L'**algorithme d'Euclide** permet de calculer le *plus grand commun diviseur PGCD* entre deux entiers positifs. 

Étudions le principe de cet algorithme : 

> *On supposera (pour que ce soit plus simple) que `b` est le plus grand nombre.*

```
Entrées : 
   entiers A et B
Sortie : 
   Le PGCD de A et B

DEBUT ALGO
  |   SI A < 0 OU B < 0
  |   ALORS
  |      | On retourne un code d'erreur
  |   FIN SI
  |   TANT QUE B n'est pas nul
  |      | A prend la valeur de B
  |      | B prend la valeur du reste de A/B
  |   FIN TANT QUE
  |   On retourne A
FIN ALGO
```

Nous remarquons qu'il y a une **boucle TANT QUE `while`**, et qu'à l'intérieur on change à chaque fois les valeurs de `a` et de `b`. Mais que chaque variable **a besoin de l'autre** pour changer. Il faut donc contrer ce problème : ***Comment changer deux variables lorsque chacune d'elle a besoin que l'autre** reste inchangée ?*

Je m'explique un peu mieux : 
- `a` prend la valeur de `b` *avant qu'il ne soit modifié*, jusqu'ici pas de problèmes.
- `b` prend la valeur de `a/b` *avant modification de `a`*, or si on a déjà changé `a`, et bien `b` prendra systématiquement la valeur du reste de `b/b` qui sera forcément nul et entrainera une erreur sur la valeur du Plus Grand Commun Diviseur.

On va donc utiliser une **variable temporaire**, elle permettra de stocker l'une des deux variables pour pouvoir garder une trace de l'ancienne valeur. Nous allons regarder les deux cas : si la valeur temporaire *(que l'on nommera `temp`)* prend celle de `a` puis de `b`.

***Algorithme d'Euclide*** *`temp` prend la valeur de `a`*

```c
#include<stdio.h>

int algoEuclide(int a, int b){ 
   // Vérifions la valeur de a et de b
   if (a<=0 || b<=0) { 
      printf("Au moins une des valeurs n'est pas valide\n");
      return -1; // Erreur
   }
   // Tant que b est non nul
   while (b != 0){
      int temp = a;
      a = b;
      b = temp%b; // On lui affecte le reste
   }
   return a;
}
```

>[!TIP] 
> En cas d'erreur **j'ai décidé** de retourner `-1` car dans le cas de notre fonction, c'est une valeur qui ne pourra jamais être retournée lorsque tout se passe correctement puisque $a>0$ et $b>0$.
> - Il faut savoir que `-1` est souvent choisi car il est simple et universellement compris dans de nombreux langages de programmation.

Dans notre première version, `temp` permet donc de stocker la valeur de `a` avant sa modification, pratique pour ensuite calculer le reste de la division de l'*ancienne valeur* de `a` et de `b`.

***Algorithme d'Euclide*** *`temp` prend la valeur de `b`*

```c
#include<stdio.h>

int algoEuclide(int a, int b){ 
   // Vérifions la valeur de a et de b
   if (a<=0 || b<=0) { 
      printf("Au moins une des valeurs n'est pas valide\n");
      return -1; // Erreur
   }
   // Tant que b est non nul
   while (b != 0){
      int temp = b;
      b = a%b; // On lui affecte le reste
      a = temp;
   }
   return a;
}
```

Cette fois ci, `temp` a permis de stocker la valeur de `b` juste avant la modification de cette dernière. Ainsi l'ancienne valeur de `b` avant modification a pu être affectée à `a` lorsque l'opération a été effectuée.  
Comme évoqué un peu avant, personnellement, j'ai bien mettre des espaces entre mes initialisations, mon retour final, mes blocs conditions/boucles. Ainsi la structure suivante n'est **pas forcément** la meilleure mais elle permet de mieux relire son code.

```c
#include<stdio.h>

int algoEuclide(int a, int b){ 
   // Vérifions la valeur de a et de b
   if (a<=0 || b<=0) { 
      printf("Au moins une des valeurs n'est pas valide\n");
      return -1; // Erreur
   }

   while (b != 0){
      int temp = b;
      b = a%b; // On lui affecte le reste
      a = temp;
   }

   return a;
}
```

Ici ce n'est que deux ou trois sauts de lignes mais voilà, on aperçoit un peu mieux les "étapes" de la fonction.  
Ou alors, il y a l'inverse, celui qui veux réduire son code au maximum.

>[!WARNING]
>***FORTEMENT DÉCONSEILLÉ***

```c
#include<stdio.h>

int algoEuclide(int a, int b){ 
   if (a<=0 || b<=0) { printf("Au moins une des valeurs n'est pas valide\n"); return -1;}
   while (b != 0){ int temp = b; b = a%b; a = temp; }
   return a;
}
```

Encore dans notre exemple, les boucles ne contiennent pas énormément d'instructions donc reste plus ou moins lisible.  
On peut même pousser jusqu'à l'extrême : 
- enlever le `printf` cela implique que le bloc `if` ne contient qu'une seule instruction. *Dans ce cas les accolades <u>peuvent être enlevées</u>*
- mettre tout sur la même ligne.

```c
// Ce code ci
if (a<=0 || b<=0) return -1;

// Est équivalent au code suivant
if (a<=0 || b<=0){
    return -1;
}
```

Ainsi on obtient : 

```c
#include<stdio.h>

int algoEuclide(int a, int b){ 
   if (a<=0 || b<=0) return -1;
   while (b != 0){ int temp = b; b = a%b; a = temp; }
   return a;
}
```

```c
#include<stdio.h>
int algoEuclide(int a, int b){ if (a<=0 || b<=0) return -1; while (b != 0){ int temp = b; b = a%b; a = temp; } return a; }
```

> Bonne chance pour vous relire dans ces cas là.

>[!NOTE]
> Et oui, contrairement à ce bon vieux PYTHON, le `C` est assez flexible au niveau de la structure du code, jusqu'à le rendre illisible pour l'homme. 

# Déclaration et définition d'une fonction

En programmation `C`, il est **essentiel de déclarer une fonction avant de pouvoir l'utiliser**. Cette règle est fondamentale et s'applique partout dans votre code.  
Par exemple, si vous souhaitez utiliser une fonction appelée `maFonction` à l'intérieur de la fonction principale main, vous devez d'abord déclarer maFonction.

Il existe donc plusieurs solutions : 
- Définir complètement la fonction avant utilisation
- Déclarer le prototype de la fonction, puis définir le corps plus tard 

Voyons les deux cas : 

```c
// Définition complète de la fonction avant main
void maFonction(...) {
    // Instructions
    return;
}

int main() {
    maFonction();
    return 0;
}
```
```c
// Prototype de la fonction
void maFonction(...);

int main() {
    maFonction();
    return 0;
}

// Implémentation de la fonction après main
void maFonction(...) {
    // Instructions
    return;
}
```

Cette règle existe car le compilateur C analyse le code de haut en bas et doit connaître le type de retour et les paramètres d'une fonction avant de pouvoir vérifier si vous l'utilisez correctement.

>[!NOTE]
>Nous avons évoqué cette règle avec une fonction random et le `main`. Mais retenez que ceci est valable pour toute les fonctions entre elles.

Le **prototype** d'une fonction *(aussi appelé signature)* représente l'instruction permettant de donner le type de la fonction, son nom et les paramètres qu'elle doit prendre.  
La **déclaration** d'une fonction peut être vue comme *donner le prototype/ la signature d'une fonction*. Alors que la **définition** c'est *donner le corps de la fonction*.

>[!TIP]
> Le corps d'une fonction c'est son contenu.

###### Exemple

Si on décide de reprendre notre exemple avec l'*algorithme d'Euclide* qui pour rappel permet de déterminer le plus grand commun diviseur PGCD de deux nombres. Voici comment nous pourrions procéder dans la structure du code.

- Déclaration du prototype de la fonction `algoEuclide` pour pouvoir l'utiliser
- Déclaration et définition du point d'entrée `main`
- Définition de la fonction `algoEuclide`

```c
#include<stdio.h>

// Déclaration du prototype de la fonction algoEuclide
int algoEuclide(int a, int b);

int main( ){
   int a = 18;
   int b = 4;
   printf("Le PGCD de %d et %d est : %d.\n", a, b, algoEuclide(a, b));
   return 0;
}

// Définition du corps de la fonction
int algoEuclide(int a, int b){ 
   if (a<=0 || b<=0) return -1;
   while (b != 0){ int temp = b; b = a%b; a = temp; }
   return a;
}
```
```
Le PGCD de 18 et 4 est : 2.
```

On aperçoit très clairement dans cet exemple on utilise la fonction `algoEuclide` dans l'instruction d'affichage `printf` dans le `main` avant même d'avoir défini son corps.

>[!NOTE]
>Cet aspect peut être très utile pour maintenir une structure cohérente dans son programme. Où alors pour ceux qui aiment avoir la fonction `main` en premier dans un fichier.

# Organisation et utilisation des fichiers `.h` personnalisés

Pour rappel, puisque l'on en a déjà parlé un peu avant, les fichiers `.h` en programmation `C` (aussi appelés **headers**) permettent de mieux organiser le code, surtout quand on commence à avoir plusieurs fonctions, structures, etc.  
Ils sont très utiles pour **séparer la déclaration des fonctions de leur définition**, comme dans des projets plus sérieux ou bien structurés.

## Projet guidé pour mieux comprendre

### Introduction au projet

Pour mieux comprendre l'utilisation des fichiers `.h`, nous allons passer par la conception d'un *mini projet* guidé.  
<u>Consigne et objectif du projet :</u>  
On souhaite dessiner des formes *(rectangle, carré, triangle)* et les afficher sur le terminal lors de l'exécution. *On utilisera le caractère `*` pour afficher les formes sur le terminal*.

### Quelques rappels de géométrie

Pour commencer, réfléchissons un peu aux formes que l'on souhaite dessiner : 
<br>Tu n'es pas sans savoir que : 
- Un **carré** est une forme où chaque côté est égal.
- Un **rectangle** est une forme où ses côtés opposés sont égaux.
- Un **triangle** est une forme à 3 côtés où : 
   - Les trois côtés peuvent avoir une longueur différente.
   - Deux côtés peuvent avoir la même longueur (isocèle).
   - Les trois côtés ont la même longueur (équilatéral).

Alors tu vas me dire *"oue ça sert à quoi de savoir ça."*. En fait, ça te permet d'avoir une idée globale des paramètres que va prendre chaque fonctions puis de les lister.
<br>Ainsi on remarque simplement que : 
- La fonction carré ne prend qu'un paramètre la longueur d'un côté.
- La fonction rectangle en prend 2.
- La fonction triangle : 
   - Quelconque : 3 paramètres
   - Isocèle : 2 paramètres
   - Équilatéral : 1 paramètre

Et, chaque fonction ne renvoie rien, elles permettent d'afficher la forme sur le terminal.

Déterminons ainsi le prototype de chacune des fonctions.

```c
void carre(int longueur);

void rectangle(int longueur, int largeur);

void triangleQuelconque(int long1, int long2, int long3);
void triangleIsocele(int long1, int long2);
void triangleEquilateral(int longueur);
```

Au dessus, on a évoqué le fait que les fichiers `.h` permettent de séparer les prototypes et les déclarations des fonctions. Et bien voilà, on a déterminé le prototype de chacune des fonctions que l'on souhaite implémenter. Alors, touts ces prototypes vont se retrouver dans un fichier `.h`.  
Dans notre cas ils font référence à des fonctions permettant de dessiner des formes sur le terminal ainsi on vas appeler le fichier `dessinerForme.h`. Pour spoiler un peu, le fichier associé : `dessinerForme.c` lui contiendra en fait la définition de chacun des prototypes déclarés dans le fichier `.h`. 

- Fichier `dessinerForme.h`
```c
#ifndef DESSINER_FORME_H
#define DESSINER_FORME_H

void carre(int longueur);

void rectangle(int longueur, int largeur);

void triangleQuelconque(int long1, int long2, int long3);
void triangleIsocele(int long1, int long2);
void triangleEquilateral(int longueur);

#endif
```

Bon je te vois venir, *"À quoi ça sert ifndef, define et endif ?"*. J'arrive, j'arrive !  
En fait on utilise `#ifndef`, `#define` et `#endif` dans les fichier headers `.h` pour éviter **l'inclusion multiple** *(= include guards)*. Expliquons l'utilité des trois instructions : 

- 
   ```c
   #ifndef DESSINER_FORME_H
   #define DESSINER_FORME_H
   ```
  Ces deux lignes permettent de dire au processeur : *"Si `DESSINER_FORME_H` n'est pas défini ALORS définit DESSINER_FORME_H"*.  
  En gros, si le fichier n'a **pas encore été inclus** (= `DESSINER_FORME_H` pas défini) alors dans ces cas là on demande au processeur de le définir et d'inclure le contenu.


- 
   ```c
   #endif
   ```
   Permet de terminer la condition commencée avec `#ifndef`.

><u>À retenir :</u>
>```c
>#ifndef CST
>#define CST
>// ...
>#endif
>```
> Si `CST` n'est pas défini alors définit `CST` et inclus le contenu entre `#ifndef` et `#endif`.

>[!NOTE]
>Le nom des paramètres de chaque prototype n'est pas obligatoire ainsi, notre fichier `.h` aurait aussi pu ressembler à : 

```c
#ifndef DESSINER_FORME_H
#define DESSINER_FORME_H

void carre(int);

void rectangle(int, int);

void triangleQuelconque(int, int, int);
void triangleIsocele(int, int);
void triangleEquilateral(int);

#endif
```

Ensuite, on peut définir le corps de chacune des fonctions dans le fichier `dessinerForme.c` correspondant. 

>[!WARNING]
>Sans oublier d'inclure le fichier `dessinerForme.h` puisqu'il contient les signatures des fonctions.

- Fichier `dessinerForme.c`

```c
#include <stdio.h>
#include "dessinerForme.h"

void carre(int longueur) {
    for (int i = 0; i < longueur; i++) {
        for (int j = 0; j < longueur; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void rectangle(int longueur, int largeur) {
    for (int i = 0; i < largeur; i++) {
        for (int j = 0; j < longueur; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void triangleQuelconque(int long1, int long2, int long3) {
    // Pour simplifier, nous allons dessiner un triangle rectangle
    // avec la base et la hauteur égales à long1
    for (int i = 1; i <= long1; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void triangleIsocele(int long1, int long2) {
    // Pour simplifier, nous allons dessiner un triangle isocèle
    // avec la base égale à long1
    int hauteur = long2;
    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < hauteur - i - 1; j++) {
            printf("  "); // espaces pour centrer le triangle
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void triangleEquilateral(int longueur) {
    for (int i = 0; i < longueur; i++) {
        for (int j = 0; j < longueur - i - 1; j++) {
            printf("  "); // espaces pour centrer le triangle
        }
        for (int j = 0; j < i + 1; j++) {
            printf("* ");
        }
        printf("\n");
    }
}
```

- Pour simplifier les dessins des triangles, on dessine des triangles rectangles.

Enfin, il nous reste plus qu'à créer le fichier principal qui contiendra la fonction `main`. Ce fichier est généralement nommé `main.c`.

- Fichier `main.c`

```c
#include <stdio.h>
#include "dessinerForme.h"
int main() {
    printf("Carre:\n");
    carre(5);

    printf("\nRectangle:\n");
    rectangle(5, 3);

    printf("\nTriangle Quelconque:\n");
    triangleQuelconque(5, 5, 5);

    printf("\nTriangle Isocele:\n");
    triangleIsocele(5, 5);

    printf("\nTriangle Equilateral:\n");
    triangleEquilateral(5);
    
    return 0;
}
```

Notre projet touche déjà à se fin. Voici l'arborescence de notre projet : 

```less
projet_dessiner_des_formes_cours5_1/
├── main.c                  // Fonction main()
├── dessinerForme.c         // Définitions des fonctions
└── dessinerForme.h         // Prototypes des fonctions (header .h personnalisé)
```

Il ne reste plus qu'à compiler et exécuter la point d'entrée `main`. Puisque ton programme utilise plusieurs fichiers, il faut **compiler tous les fichiers `.c` en même temps**. 
<br> Ainsi la commande dans le terminal ressemblera à celle ci : 

```
gcc main.c dessinerForme.c -o prog
./prog
```
```
Carre:
* * * * * 
* * * * * 
* * * * * 
* * * * * 
* * * * * 

Rectangle:
* * * * * 
* * * * * 
* * * * * 

Triangle Quelconque:
* 
* * 
* * * 
* * * * 
* * * * * 

Triangle Isocele:
        *
      ***
    *****
  *******
*********

Triangle Equilateral:
        * 
      * * 
    * * * 
  * * * * 
* * * * * 
```

# Surcharge

## Principe

>[!cite] Définition
>On appelle **==surcharge==** *(overloading en anglais)* un mécanisme puissant en programmation.  
>En fait *la surcharge* permet au développeur de définir plusieurs fonctions ayant **le même nom** mais **appelant des paramètres différents**.

<u>Exemple :</u>  
On considère une fonction `lambda` codée en pseudo langage : 

```
lambda(entier : x, flotant : y)
	retourner x+2y

lambda(entier x)
	retourner 2x*x

lambda(chaine c)
	retourner chaine+\n
```

Ici, on définit **3 fois** une fonction appelée `lambda` et chacune des définition possède des arguments de types différents.  
C'est ce qu'on appelle la surcharge.

En langage C, la **surcharge n'existe pas nativement**, en fait le compilateur C ne supporte pas la **résolution de fonction par type de paramètre**.  
Autrement dit, il ne fait pas la différence entre les deux signatures suivantes : 

```c
int addition(int a, int b);
float addition(float a, float b);
```

<u>Exemple :</u>  
Reprenons notre fonction addition avec les types différents du dessus et essayons de les définir et de compiler le programme.  

- Fichier `surcharge.c`

```c
#include <stdio.h>

// Première définition
int addition(int a, int b) {
    return a + b;
}

// Deuxième définition avec le même nom
int addition(float a, float b) { 
    return a + b;
}

int main() {
    printf("%d\n", addition(3, 4));
    return 0;
}
```

**Résultat de la compilation**  
```
error: redefinition of ‘addition’
note: previous definition of ‘addition’ was here
```

*Qui désigne bien une erreur de redéfinition de la fonction `addition`*.

## Comment le contourner ?

Même si la surcharge n’est pas supportée directement, il existe plusieurs **techniques** pour simuler ce comportement :  

### Utiliser des noms différents

C'est la méthode que l'on utilise le plus, MÉTHODE CLASSIQUE.

```c
int addition_int(int a, int b) {
    return a + b;
}

float addition_float(float a, float b) {
    return a + b;
}
```

### Utiliser des macros

- On utilise toujours des noms de fonctions dynamique mais on regroupe ces derniers dans une fonction globale.

Cela permet de rendre le code un peu plus propre. `_Generic` permet de créer une sorte de **surcharge statique**. 

```c
#define addition(a, b) _Generic((a), \
    int: addition_int, \
    float: addition_float \
)(a, b)
```

```c
int addition_int(int a, int b) {
    return a + b;
}

float addition_float(float a, float b) {
    return a + b;
}
```

Lors de l'appel à `addition(a, b)` les paramètres permettront de déterminer si on a voulu appeler l'addition de deux entiers ou l'addition de deux flottants.

# Suivant

- Cours suivant : [[06 - Les tableaux]]