# Ce bon vieux `Hello world`

Et oui, ici aussi vous n'y échapperez pas, notre premier programme `C` vas nous permettre d'afficher ce fameux `Hello world` dans la console.

Avant de commencer à coder, réfléchissons un peu. Pour rappel le `C` est une suite de fonction dont une obligatoire la fonction `main( )`, c'est elle qui sera exécutée en premier d'où son appellation *point d'entrée*. Nous allons devoir trouver le moyen d'afficher du texte dans la console.

En programmation `C`, il est aussi impératif de réfléchir à quel genre de "chose" doit renvoyer la fonction, comme par exemple un entier, une chaîne de caractères, un caractère, un booléen, ... Parlons des types usuels.

## Le point d'entrée `main( )`

Lorsqu'un programme commence à s'exécuter il appellera **toujours** `main( )`en premier. C'est une fonction qui permet de diriger les appels aux autres fonctions du programme.

Malgré tout quelques contraintes s'appliquent à `main( )` : 

- Elle ne peut pas être définit comme `static` ou comme `inline`.
- Elle ne peut pas être appelée

Toute fonction en langage `C` possède le même squelette : 

```
typeRetour nomFonction( arguments ) {
   instruction 1;
   instruction 2;
   ...;
   return ...;
}
```

Étudions ce squelette : 

- `typeRetour` représente le type de la donnée que doit renvoyer la fonction. C'est à dire si la fonction doit retourner un entier, un caractère, un tableau, ...
- `nomFonction` représente le nom que vous donnez à la fonction permettant de l'appeler.
- `arguments` représentent les paramètres de la fonction *(une fonction n'a pas forcément de paramètres)*.
- `return` est l'instruction permettant de retourner un résultat.

>[!WARNING]
> Si votre fonction doit retourner un entier et que vous retournez un charactère, la compilation ne fonctionnera pas.

Si on revient à notre fonction `main( )`,

- Par convention, elle retourne `0` donc un entier de type `int` *que l'on détaillera après*.
- On connaît son nom.
- Elle n'a pas besoin d'arguments/paramètres.

Ainsi en suivant le squelette, notre fonction `main( )` devrait ressembler à cela : 

```c
int main( ){ 
   // Instructions de la fonction main( )
   return 0;
}
```

>[!WARNING]
> Sans oublier le `return 0;` puisqu'on définit que la fonction principale revoie un entier.

Ainsi, ce tout petit code nous permet d'introduire des spécificités de la programmation `C`

- Chaque fonction est un bloc délimité entre accolades `{ ... }`.
- Chaque instruction se termine avec un point-virgule `;` *qui permet de spécifier la fin d'une instruction*.

### Écrire des commentaires

En `C` il est possible d'écrire deux sortes de commentaires : 

- Sur une ligne `//...`
- Sur plusieurs lignes `/* ... */`

```c
// Un commentaire sur une ligne
/*
Un commentaire sur 
plusieurs lignes
*/
```

## Afficher des informations dans la console

La fonction `printf(...)` permet d'afficher du texte ou des valeurs à l'écran. Il faut se souvenir que `printf` n'est pas directement utilisable, **elle vient d'une bibliothèque** appelée `stdio.h`. Ainsi cela implique que pour pouvoir utiliser la fonction `printf` il faudra spécifier en entête la bibliothèque. C'est donc là qu'intervient les `#include` évoqués lors du premier cours.

Voici comment inclure la bibliothèque `stdio.h` dans votre fichier `C` et d'afficher ce bon vieux `Hello world`.

Pour rappel : 

- `main( )` est le point d'entrée du programme qui renvoie un entier, `0`.
- Pour afficher une donnée on utilise `printf` issu de la bibliothèque `stdio.h`.

```c
#include<stdio.h>

int main( ){
   printf("Hello world");
   return 0;
}
``` 
```
Hello world
```

Et voilà, votre premier `main` en langage `C`, plutôt cool non ? Bon je suis d'accord, on a pas encore vu grand chose, mais déjà quelle fierté d'avoir son premier code qui fonctionne !!

>[!TIP]
> Les **header** *(= `include`)* se font au début du code, c'est à dire avant toutes les fonctions. La quasi totalité du temps, les premières lignes de vos fichiers `C`seront des `include`.

Grossièrement votre code devrait ressembler au squelette suivant : 

```c
#include<...>
#include<...>
//... 

// Toutes les fonctions

// À la fin, la fonction main
int main( ){ 
   // Instructions
   return 0;
}
```

# Les types usuels

Bon je suis d'accord avec toi, ça fait plusieurs fois que je parle de type. C'est donc le moment idéal pour les introduire un à un. Prenons les plus fréquents pour commencer. Les autres pourront être introduits au moment voulu.

## Le type caractère

Le mot clé `char` désigne un objet de type caractère, ce dernier peut contenir n'importe quel caractère que la machine utilise. Le plus souvent, un objet de type `char` est **codé sur 1 octet** *(= 8 bits)* et les caractères pris en compte sont ceux qui correspondent au codage ASCII.

![Table ASCII](https://external-preview.redd.it/UFrL9aDmRhQqJMxweWAT1sVcVDo-UVJXyYVlGvzqayI.jpg?width=1080&crop=smart&auto=webp&s=2ddd8921d36013b43ded6c68b6b7ede11c58dcba)

>[!TIP]
> Les caractères en `C` peuvent être utilisés **comme des entiers**, il est donc possible de faire des opérations arithmétiques sur eux.

###### Exemple

On considère une variable `a` qui contient le caractère `'a'` et on souhaite afficher la lettre `b` à partir de `a`. On sait grâce à la table ASCII que la différence entre le code de `b` et le code de `a` vaut 1, il faut donc ajouter 1 à la variable contenant `'a'` pour obtenir `b`.

```c
#include<stdio.h>

int main( ){
   char a = 'a';
   char b = a+1;
   printf("%c", b);
}
```
```
b
```

>[!WARNING]
> Une variable de type `char` ne peut contenir **qu'un seul** caractère. Pour pouvoir stocker plusieurs caractères, il faudra utiliser : 
>
> - Un tableau de `char`
> - Un pointeur vers `char`
>
> Ces deux aspects seront évoqués plus tard dans ce cours.

En conséquence, cela implique directement qu'une variable de type `char` contenant plusieurs caractères déclenchera une erreur et empêchera la compilation de votre programme.

> [!tip]
> Un objet de type `char` ne peut contenir qu'un seul caractère, et en réalité chaque caractère représente une valeur numérique qui correspond en fait à son codage dans la table ASCII.

Ainsi, on peut avoir besoin d'afficher la valeur d'une variable de type `char` sous forme de caractère ou sous forme numérique. Cela est évidemment possible en langage `C`.

Voilà comment procéder : 

```c
#include<stdio.h>

int main( ){
   char a = 'A';
   printf("%c", a); // Afficher le caractère
   printf("%d", a); // Afficher la valeur numérique
}
```
```
A
65
```

Où `65` représente le code ASCII de la lettre `A`.

*Pour le moment, ne nous préoccupons pas de `%c` et `%d`, on en reparle un peu après. Pour spoiler un peu on peut les voir comme des formats qui permettent de dire je veux afficher la valeur dans un certain `type` de la variable `truc`.*

## Le type entier

Les **entiers** sont représentés par le mot clé `int`, qui peut être précédé : 

- d'un **attribut de précision** `short` ou `long`
- d'un **attribut de représentatio** `signed` ou `unsigned` 

| Type | Taille (en octets) | Plage de valeur possible | 
| :---: | :---: | --- | 
| `int` | 4 | -2 147 483 648 à 2 147 483 647 |
| `unsigned int` | 4 | 0 à 4 294 967 295 |
| `short` ou `short int` | 2 | -37 768 à 37 767 | 
| `unsigned short` | 2 | 0 à 65 535 | 
| `long` ou `long int` | 4 ou 8 | dépend du pc |
| `unsigned long` | 4 ou 8 | uniquement valeurs positive | 
| `long long` | 8| très grands nombres | 
| `unsigned long long` | 8 | les positifs |

>[!NOTE]
> - `unsigned` pour des valeurs positives.
> - `signed` pour les valeurs positives et négatives.
> - `short` petite taille
> - `long` grande taille
> - La taille des entiers selon le format peut dépendre aussi du système sur Windows par exemple on note certaines différences entre 32 et 64 bits. *Le compilateur peux aussi jouer un rôle.*

###### Exemple

Si on souhaite définir un entier non signé, il suffit de spécifier le type de l'entier choisit, un nom de variable puis une valeur. Dans la pratique si on choisit que la variable `var` contiendra 155 alors, en programmation `C` on écrira : 

```c
unsigned int var = 155;
```

>[!TIP]
> La taille d'un `short int` est comprise entre la taille d'un objet de type `char` et la taille d'un objet de type `int`, on peut aussi le noter : 
> 
> ```c
> sizeof(char) <= sizeof(short int) <= sizeof(int)
> ```

### L'opérateur `sizeof`

L'opération `sizeof` permet de **déterminer la taille** (en octets) d'un *type de données* ou d'une *variable*. Ce dernier se révèle très utilise lorsqu'il faut gérer la mémoire, et pour travailler avec les structures complexes.

#### Utiliser `sizeof` pour un type de données

Il est possible d'obtenir la taille d'un type de donnée spécifié lors de l'appel de l'opérateur.

>[!NOTE]
> Les **types de données** sont `int`, `char`, `float`, ... 

Ainsi, il suffit d'écrire `sizeof(type_de_donnees)`.

###### Exemple

```c
#include<stdio.h>

int main( ){
   printf("Taille d'un entier : %d", sizeof(int));
   printf("Taille d'un caractère : %d", sizeof(char));
   printf("Taille d'un flottant : %d", sizeof(float));
   return 0;
}
```

#### Utiliser `sizeof` sur une variable

```c
#include<stdio.h>

int main( ){
   int a = 1452; 
   printf("Taille de la variable a : %d", sizeof(a));
   return 0;
}
```

Il est évidemment possible de calculer la taille des tableaux et des structures mais nous verrons ces aspects plus tard dans ce cours.

>[!NOTE]
> L'opérateur `sizeof` est évalué à la compilation, ce qui signifie qu'il n'a pas d'impact sur la performance à l'exécution.

## Les types flottants

En langage `C`, le type flottant *(floating-point)* est utilisé pour représenter les nombres réels avec une partie décimale. Il existe **deux types** flottants : 

- `float` précision **simple** 
   - généralement sur 32bits
   - environ 7 chiffres significatifs
- `double` précision **double** 
   - généralement sur 64bits
   - environ 15-16 chiffres significatifs

>[!WARNING]
> Le nombre de **chiffres significatif** représente la précision avec laquelle est donnée un nombre.

Les valeurs minimales et maximales sont définies dans le header `<float.h>` : 
- `FLT_MIN`
- `FLT_MAX` 
- `DBL_MIN`
- `DBL_MAX`
- ...

>[!WARNING]
> - Il est possible de convertir un flottant vers un entier, cela peut néanmoins entraîner une parte de précision. 
> - Les arrondis peuvent entraîner des erreurs à cause de leur représentation en binaire.

###### Exemple

```c
#include <stdio.h>

int main( ){
   float var = 14.5f;
   double val = 14.2;
}
```

>[!TIP]
> Par défaut, les flottant sont de type `double` alors c'est pour cette raison que si il est de type `float` on ajoute un `f` à la fin.

# Portée des variables

La **portée des variables** en `C` *(aussi appelée scope)*, c’est la partie du programme dans laquelle une variable est accessible *(où tu peux l'utiliser)*. Il y a plusieurs types de portée selon où et comment tu déclares ta variable.

## Variable locale

C'est la déclaration **à l'intérieur d'un bloc**. Dans ce cas la variable est dite **LOCALE** et est accessible <u>uniquement</u> dans ce même bloc.

###### Exemple

```c
void maFonction() {
    int x = 5; // portée locale
    printf("%d\n", x); // Pas d'erreur ici
}
printf("%d\n", x); // ❌ Erreur, x n'est pas visible ici
```

## Variable globale

Déclaration en **dehors de toute fonction**, elle est appelée variable **GLOBALE** et est accessible <u>partout dans le fichier</u>.

###### Exemple

```c
int y = 10; // portée globale

void afficher() {
    printf("%d\n", y); // OK
}
```

>[!TIP]
>On peut aussi avoir accès à une variable globale **partout** dans d'autres fichiers en l'exportant avec `extern`.

###### Exemple d'export de variable globale dans d'autres fichiers

- Fichier : `fichier1.c`
```c
int compteur = 0;  // Définition de la variable globale
...
```

- Fichier : `fichier2.c`
```c
extern int compteur;  // Déclaration : "Je sais qu'elle est définie ailleurs"
...
```

# Retour sur `printf( )`...

Je ne sais pas si tu as remarqué mais quand on veut afficher la taille ou la valeur d'une variable par exemple, on précise à l'intérieur de `printf` ce qu'on appelle le **format**. En gros, on dit qu'on souhaite afficher la valeur d'une certaine variable dans un certain format.

On utilise le caractère `%` pour chaque variable suivit de l'initiale associé au format dans lequel on souhaite afficher la variable.

On considère deux variables que l'on souhaite afficher dans un format bien précis alors de manière générale, on utilisera `printf` comme suit : 

```
printf("message %format1 ... %format2", var1, var2);
```

###### Exemple

On souhaite afficher la valeur entière, puis caractère d'une variable. Ainsi on codera : 

```c
#include <stdio.h>

int main( ){
   char lettre = "A";
   printf("Format entier : %d et format caractère : %c.", lettre, lettre);
   return 0;
} 
```
```
Format entier : 65 et format caractère A.
```

***Tableau des principaux formats valides***

| Format | Type de l'argument affiché | Format d'affichage | Exemple |
| :---: | --- | --- | --- |
| `%c` | caractère | ASCII | a G u |
| `%hd` <br> `%hu` <br> `%hX` | entier `short int` (ou caractère) **signé** <br> entier `short int` (ou caractère) **non signé** <br> Affichage en hexadécimal | Base 10 <br> Base 10 <br> Base 16 (hexa) | $-12$ <br> $463$ <br> 90AF |
| `%ld` <br> `%lu` <br> `%lX` | entier `long int` **signé** <br> entier `long int` **non signé** <br> entier `long int` en hexadécimal | Base 10 <br> Base 10 <br> Base 16 (hexa) | $-1289$ <br> $46399$ <br> B4E98A0F |
| `%d`<br> `%X` | entier `int` <br> `int` en hexadécimal | Base 10 <br> Base 16 | $-546$ <br> 9A0F |
| `%le` <br> `%lf` | réel double précision `double` | | $-3.195874$ <br> $-45e-7$ |
| `%e` <br> `%f` | réel simple précision `float` | | $-3.195874$ <br> $-45e-7$ |
| `%s` | chaine de caractères | | Hello world |

Il est aussi possible d'ajouter des options entre `%` et la lettre qui définit le format.

- Ajouter un entier qui précise sur combien de caractère est affiché la variable. Par exemple, si on souhaite afficher une variable entière sur 5 caractère on utilisera le format `%5d`.

>[!WARNING]
> Le texte est aligné automatiquement à droite, alors lorsque la variable s'affiche sur plus de caractère, le nombre fournit est ignoré.

###### Exemple

```c
#include <stdio.h>

int main()
{
    int n = 4;
    printf("Le nombre n vaut %6d et voilà.", n);
    return 0;
}
```

```
Le nombre n vaut      4 et voilà.
```

- Pour aligner à gauche en utilise le signe `-`. 

###### Exemple

```c
#include <stdio.h>

int main()
{
    int n = 4;
    printf("Le nombre n vaut %-6d et voilà.", n);
    return 0;
}
```

```
Le nombre n vaut 4      et voilà.
```

- On peut ajouter deux nombres séparés par un point `.` très utilise sur les réels pour spécifier sur combien de caractère il est affiché puis sa précision.
   
   ```
   %nbChar.precisionFORMAT
   ```

###### Exemple

On souhaite afficher le nombre $12.874$ sur 10 caractères avec une précision après la virgule de 2.

```c
#include <stdio.h>

int main()
{
    int n = 12.874;
    printf("Le nombre n vaut %10.2lf et voilà.", n);
    return 0;
}
```

```
Le nombre n vaut 12.87      et voilà.
```

Il existe aussi des constantes caractères permettant d'effectuer un sout de ligne par exemple.

| constante caractère | signification         |
| :-----------------: | --------------------- |
|        `\n`         | saut de ligne         |
|        `\t`         | tabulation            |
|        `\r`         | retour chariot        |
|        `\f`         | saut de page          |
|        `\'`         | apostrophe            |
|        `\?`         | point d'interrogation |

# Les constantes

Justement et si on parlait des constantes en programmation `C`.

## Généralités

En `C` une constante représente une donnée dont la valeur ne peux pas changer après sa définition. Contrairement aux variables, les constantes garantissent que leur valeur ne changera pas tout au long du programme. <br>
Il existe deux manières de déclarer des constantes : 

- Avec le mot clé `const`
- Avec la directive préprocesseur `#define`

On utilise les constantes pour une meilleure lisibilité, maintenabilité du code et sécurité puisqu'elle empêche la modification de la valeur.

## Initialiser une constante

### En utilisant le mot clé `const`

```c
const int TEINTE = 14;

TEINTE = 130; // Erreur : on ne peut pas modifier une constante
```

- Toute modification impliquera une erreur de compilation
- **La constante doit être initialisée pendant sa déclaration**

   ```c
   const int VITESSE;
   VITESSE = 140; 

   // Erreur à la compilation
   ```

### Avec `#define`

```c
#define PI 3.14159
```

- Dans notre exemple `PI` est une constante symbolique.
- Le préprocesseur remplace chaque occurrence de `PI` par 3.14159 dans le programme.
- Pas de type directement associé *(attention aux erreurs)*

### Quelques conseil

>📌 Voici quelques petits conseils sur l'utilisation des méthodes pour définir et initialiser une constante : 
>
> - Utilisez `const` pour des constantes typées.
> - Utilisez `#define` pour des macros, ou des constantes globales *(valeur fixe, configuration, ...)*

## Les constantes prédéfinies 

Il existe évidemment de multiples constantes prédéfinies, on en a vu quelques unes comme `FLT_MIN` et `FLT_MAX` dans l'entête `<float.h>`.