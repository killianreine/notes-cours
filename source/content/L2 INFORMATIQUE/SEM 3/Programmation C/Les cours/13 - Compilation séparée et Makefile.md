# Quelques rappels
Un programme en langage C peut être réparti sur *plusieurs fichier* chaque fichier peut alors être compilé séparément puis connecté au fichier principal avec l'édition des liens ([[01 - Introduction#Langage compilé]]).  
Comme on l'a déjà dit en programmation C, les programmes ont une structures :
- Le **programme** peut être répartit sur plusieurs fichiers que l'on appelle **==module==**.
- Le **fichier** lui contient une liste de déclaration.
- Les **déclarations** quant à elles font référence aux déclarations et définitions de fonctions, variables, type, ... ainsi qu'au directive au préprocesseur *genre `#include` `#define`, ...*.  

Les différentes *parties* d'un programme peuvent être placée dans plusieurs fichiers différents *(= module)* et reliés par des interfaces *(les fichier `.h` )*. Car la notion de *module* n'existe pas en langage C, c'est pour cette raison qu'on l'associe ici au terme *fichier*.

Les fonctions et les variables préfixées du mot clé `static` sont **locales au fichier**, c'est à dire qu'elles sont visibles uniquement dans le fichier dans lequel elles ont été créées. En gros dans les autres fichiers c'est comme si elles n'existaient pas. Alors que les fonctions et les variables globales **visibles dans tous les fichiers** doivent être **définie une seule fois**.

# Compilation séparée et rôle des fichiers `.h`
La compilation séparée permet en fait de **fragmenter** un grand programmes en différentes parties appelées **==modules==** qui peuvent être compilées seules, les unes des autres. 

>[!warning]
>Toute fonction ou variables <u>doit être définie avant d'être utilisée</u> !

On peut *"étendre"* une fonction et une variable pour pouvoir l'utiliser dans d'autres fichiers que celui dans lequel il a été définie, on utilise alors le mot clé `extern`.

Lorsque l’on découpe un programme en plusieurs fichiers, il faut bien distinguer deux types de fichiers :

- **Les fichiers source** `.c`
    - Contiennent les **définitions** de fonctions et de variables.  
    - Ce sont eux qui sont compilés pour générer des fichiers objets (`.o` ou `.obj`).
- **Les fichiers d’en-tête** `.h` 
    - Contiennent les **déclarations** *(prototypes de fonctions, déclarations de variables externes, définitions de types, macros…)*.  
    - Ils servent d’**interface** entre les différents modules.  
    - Un fichier `.c` qui a besoin d’utiliser une fonction ou une variable définie ailleurs doit **inclure** *(`#include`)* le fichier `.h` correspondant.

>[!info] Remarques
>- Un `.c` **définit** les choses.  
>- Un `.h` **annonce** ce qui existe, pour qu’on puisse l’utiliser ailleurs.

- *Reprise du cours suivant !* [[05 - Retour sur les fonctions#Organisation et utilisation des fichiers `.h` personnalisés]]

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

>[!tip]
>Le nom des paramètres de chaque prototype n'est pas obligatoire ainsi, notre fichier `.h` aurait aussi pu ressembler à : 
>
>```c
>#ifndef DESSINER_FORME_H
>#define DESSINER_FORME_H
>
>void carre(int);
>
>void rectangle(int, int);
>
>void triangleQuelconque(int, int, int);
>void triangleIsocele(int, int);
>void triangleEquilateral(int);
>
>#endif
>```

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

# Makefile
## Rôle d'une makefile
Un projet en C peut avoir **plusieurs fichiers sources**.  
Les compiler un par un, puis faire le linkage à la main à chaque fois serait long et source d’erreurs.

`make` est un programme qui lit un fichier spécial appelé **Makefile** et qui sait :
- quelles étapes de compilation exécuter,
- dans quel ordre,
- et seulement si c’est nécessaire *(il ne recompile pas ce qui n’a pas changé)*.

## Structurer son propre makefile
Un makefile est constitué de règles strictes et précises généralement sous la forme suivante : 
```
cible: dépendance
	commandes à exécuter
```

En reprenant notre ancienne étude de cas sur les formes géométriques. On redonne ci dessous la structure de l'arborescence des fichiers. 
```less
projet_dessiner_des_formes_cours5_1/
├── main.c                  // Fonction main()
├── dessinerForme.c         // Définitions des fonctions
└── dessinerForme.h         // Prototypes des fonctions (header .h personnalisé)
```
- **`main.c`** : contient `main()` et utilise les fonctions de `dessinerForme.c`.
- **`dessinerForme.c`** : contient les **définitions** des fonctions.
- **`dessinerForme.h`** : contient les **prototypes**.

Pour commencer créer un fichier nommé `makefile` dans le dossier de votre projet :
```less
projet_dessiner_des_formes_cours5_1/
├── makefile
├── main.c                  // Fonction main()
├── dessinerForme.c         // Définitions des fonctions
└── dessinerForme.h         // Prototypes des fonctions (header .h personnalisé)
```

- Le fichier `makefile`
```makefile
# Nom du compilateur
CC = gcc

# Option de compilation
CFLAGS = -Wall -Wextra

# Nom de l'executable
EXEC = prog

# Liste des fichiers sources
SRC = main.c dessinerForme.c
# Conversion auto en fichier objet
OBJ = $(SRC:.c=.o)

# Règle principale
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

# Règle générique pour compiler un .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers compilés
clean:
	rm -f $(OBJ) $(EXEC)
```

**Les explications du makefile**
```makefile
CC = gcc
```
est une variable standard qui permet de savoir quel compilateur on utilise, ici en C on utilise gcc. Si on souhaite changer et mettre `clang` il faudra simplement remplacer `gcc` par `clang`.
```makefile
CFLAGS = -Wall -Wextra
```
`CFLAGS` contient **les options de compilation** pour le compilateur.
- `-Wall` permet d'activer presque tous les avertissements.
- `-Wextra` active les avertissements supplémentaires.
```makefile
EXEC = prog
```
Permet de donner un nom à l'exécutable que `make` va devoir créer, ici on l'a appeler `prog`.
```makefile
SRC = main.c dessinerForme.c
```
Dans la variable `SRC` on liste tous les fichiers sources du projets.
```makefile
OBJ = $(SRC:.c=.o)
```
Transforme automatiquement la liste des `.c` en `.o`.

- Utilisation du makefile
```
make
```
Il va générer les fichiers `.o` et l'exécutable `prog`, il suffira ensuite d'exécuter le programme avec la commande suivante qui elle ne change pas de d'habitude : 
```
./prog
```
Pour le nettoyage : suppression fichiers objets `.o` et exécutable.
```
make clean
```
**LA RÈGLE PRINCIPALE**
```makefile
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)
```
Ici, on dit que le programme `prog` a besoin des dépendances `.o` créées et on exécute l'instruction suivante :
```bash
gcc -Wall -Wextra main.o dessinerForme.o -o prog
```
En fait l'instruction elle est donnée mais via les différentes variables qui stocke mes informations. 

>[!warning]
>Chaque variable utilisée doit être mise comme ceci : `$(var)` **et la tabulation est OBLIGATOIRE**.

**RÈFLE GÉNÉRIQUE `.c → .o`**
```makefile
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
```
- Le `%` est un **joker** *(caractère générique)*.
- Cette ligne signifie : *Pour fabriquer n’importe quel fichier `.o` à partir de son fichier `.c` correspondant…*

Dans notre exemple :
- `main.o` dépend de `main.c`
- `dessinerForme.o` dépend de `dessinerForme.c`
Autrement dit, on **déclare une règle unique qui fonctionne pour tous les fichiers `.c`** du projet.
```makefile
	$(CC) $(CFLAGS) -c $< -o $@
```
Correspond à ces instructions pour notre projet. Mais **sans avoir à l’écrire pour chaque fichier** grâce au `%`.
```bash
gcc -Wall -Wextra -c main.c -o main.o
gcc -Wall -Wextra -c dessinerForme.c -o dessinerForme.o
```
- `-c`  
  dit au compilateur de **compiler en fichier objet seulement**. Sans `-c`, gcc essaierait de créer un exécutable immédiatement, ce qu’on ne veut pas à cette étape.
- `$<`  
  Représente **la première dépendance** de la règle. Pour `main.o: main.c`, `$<` = `main.c`.
- `$@`
  Représente **la cible** de la règle. Pour `main.o: main.c`, `$@` = `main.o`.