Lors du cours n°2, nous avions parlé des types des variables en C, je fais surtout référence au type `char` qui représente un caractère [[02 - Premiers pas#Le type caractère]].  

>[!note] Rappel
>Le type `char` permet de stocker des caractères, et puisqu'ils sont stockés dans l'ordinateur sous forme d'entier, on peut alors aussi utiliser `char` pour stocker un entier.

Un problème se pose alors...  
Une variable de type `char` ne peut stocker **qu'un seul et unique caractère**, comment peut-on faire pour stocker des mots entiers ? Voire des phrases entières ?  
On cherche un moyen de stocker plusieurs lettre dans un même objet. Justement, on sait déjà le faire, par le biais des **==tableaux==**.

Il y a toujours un problème, une chaîne de caractères est plus qu'un tableau, elle doit être manipulable directement, hors ceci n'est possible **que si on connait sa taille**.

# Déclaration
Ici, rien ne change vraiment de déclaration d'un tableau :

```c
char chaine[t]="...";
```
Où 
- `t` représente la taille de la chaîne de caractères.
- `"..."` la chaîne de caractère que l'on stocke

<u>Exemple :</u>  
On souhaite stocker le mot `informatique` dans une chaine de caractères nommée `domaine`, on va alors créer un tableau de caractères et stocker le mot.
```c
char domaine[] = "informatique";
```

Voici ci dessous, une version schématique simple qui vous permet de comprendre comment `informatique` est stocké.
![[informatiqueMOT.svg]]
En fait, lors de la création de la variable  `domaine` qui contient la chaîne de caractère "informatique", cela va créer un tableau de caractères `char` contenant chaque lettre du mot **et le caractère nul** `\0` qui permet de marquer la fin de la chaîne de caractères.  
Ainsi, dans notre exemple un tableau de 13 éléments est créé, il peut être schématisé *grossièrement* de la manière suivante :
```
[ i, n, f, o, r, m, a, t, i, q, u, e, \0]
```
Chaque caractère est stocké dans un **espace mémoire** consécutive (s'incrémente de 1 pour chaque caractère). On l'aperçoit sur notre image au dessus : 

| Caractère  | Adresse mémoire |
| ---------- | --------------- |
| `i`        | `0x1000`        |
| `n`        | `0x1001`        |
| `f`        | `0x1002`        |
| $$\vdots$$ | $$\vdots$$      |
| `e`        | `0x100B`        |
| `\0`       | `0x100C`        |

En gros, chaque lettre de type `char` en C est stocké sur $1$ bit, et l'adresse mémoire entre deux caractères est simplement incrémenté de $1$. On utilise `\0` comme marque de fin de chaîne car sans lui, le programme ne pourrait pas savoir où s'arrête la chaîne de caractères.

# Initialisation
## Initialisation explicite
L’**==initialisation explicite==** consiste à définir **chaque caractère du tableau** et éventuellement le caractère nul `'\0'`, obligatoire pour une chaîne de caractères.

<u>Exemple :</u>  
```c
char chaine[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
```
## Initialisation implicite
L'**==initialisation implicite==** c'est en fait ce qu'on a vu pour la [[07 - Chaînes de caractères#Déclaration]], on utilise un littéral de chaîne entre guillemets :

<u>Exemple :</u>  
```c
char chaine[] = "Hello";
```

On peut aussi déclarer un tableau à plus d'éléments que ce qu'on initialise, dans ce cas les éléments non initialisés auront des valeurs dites indéterminées (ou nulles si le tableau est déclaré globalement).

<u>Exemple :</u>  
```c
char chaine[20] = "Salut";
```

| Aspect            | Initialisation explicite         | Initialisation implicite                    |
| ----------------- | -------------------------------- | ------------------------------------------- |
| Définition        | Chaque caractère + `'\0'` manuel | Littéral de chaîne (`"..."`)                |
| Ajout de `'\0'`   | manuel                           | Automatique                                 |
| Taille du tableau | Fixe, définie par l’utilisateur  | Déduite automatiquement **si non précisée** |
| Facilité          | Moins pratique                   | Plus simple et sûre                         |
# Manipulation des chaînes de caractères
## Accès aux éléments
Grâce à la première partie de ce cours [[#Déclaration]], on sait qu'une chaîne de caractères en C représente simplement un tableau de caractères.  
Il est alors possible d'accéder aux éléments d'une chaîne de caractères de la même manière que pour des tableaux classiques.  
Alors, en considérant une chaîne de caractères `chaine` d'une taille $\texttt{t} \in \mathbb{N}^*$,  si on souhaite accéder au $\texttt{n}-$ième élément avec $\texttt{n} \in [1;\texttt{t}]$ alors on utilisera la forme suivante : 
```c
char elementN = chaine[n-1]
```

<u>Exemple :</u>  
En reprenant l'exemple précédant avec le mot `informatique`, si on souhaite avoir accès à la lettre `m` alors on exécutera le code suivant : 
```c
#include <stdio.h>

int main() {
    char domaine[] = "informatique";
    char m = domaine[5];
    printf("6e lettre du domaine : %c", m);
    return 0;
}
```
```
6e lettre du domaine : m
```

>[!info] Rappel
>Une chaîne de caractères est un tableau d'éléments de type `char` cela implique que pour y accéder on utilise des entiers appelés **indices**.  
>Les indices commencent à 0 qui correspond au premier caractère de la chaine jusqu'à $t-1$ pour le dernier caractère de la chaîne. Et, le `\0` caractère nul pour marquer la fin de la chaîne est l'élément d'indice $t$.

Ainsi en considérant une chaîne de $t$ éléments, voici les indices de manière schématique.
![[indicesMot.svg]]
On voit donc que pour un mot de taille $t$, un tableau de taille `t+1` sera créé pour stocker chaque caractère du mot en entier et un emplacement mémoire supplémentaire est ajouté pour stocker le caractère de fin de chaîne `\0`. C'est pour cela que pour un mot de taille $t$, le tableau qui stocke le mot sera de taille $t+1$.

## Affichage
Mais comment on peut afficher une chaîne de caractères en langage C. On doit vraiment faire comme avec les tableaux classique en parcourant le tableau élément par élément et l'afficher un à un ?

Alors c'est une solution que l'on va regarder, mais ce n'est pas la plus simple ! Il existe plusieurs méthodes pour afficher une chaîne de caractères.  
Vous le savez déjà mais pour afficher des informations dans la console on utilise `printf` et quand on a besoin d'afficher un certain type de donnée on utilise des **formats** notés `%...`. Et bien sachez qu'il existe un format <u>réservé aux chaînes de caractères</u> ! Plutôt pratique non ? C'est le format `%s`.

<u>Exemple :</u>  
```c
#include <stdio.h>

int main(){
	char chaine[] = "j'écrit un truc pour le kiff";
	
	// Affichage en utilisant le format %s
	printf("%s\n", chaine);
	return 0;
}
```
```
j'écrit un truc pour le kiff
```

C'est la solution la plus simple pour afficher une chaîne de caractère.  
On peut aussi faire ce que l'on a vu pendant le cours 6 sur les tableaux, on parcourt chaque élément du tableau grâce à une boucle `for` puis on affiche chaque caractère un à un.  

>[!warning]
>Dans ces cas là, on a besoin de la taille du tableau pour pouvoir savoir au bout de combien d'itérations on arrête.

On utilise alors une méthode du package `<string.h>`, la méthode `strlen(chaine)` qui permet de donner la taille de la chaîne de caractères **sans inclure le marqueur de fin de chaine `\0`**.

<u>Exemple :</u>  
```c
#include <stdio.h>
#include <string.h>

int main(){
	char chaine[] = "j'écrit un truc pour le kiff";
	// Utilisation de strlen
	int taille = strlen(chaine);
	
	for(int i=0; i<taille; i++){
	    printf("%c", chaine[i]);
	}
	printf("\n");
	return 0;
}
```

>[!info] Remarque
>On peut aussi utiliser `sizeof()` que l'on a déjà eu l'occasion de parler pour avoir la taille mémoire **totale** du tableau, ce qui inclus le marqueur de fin de chaine `\0`.

```c
#include <stdio.h>

int main(){
	char chaine[] = "j'écrit un truc pour le kiff";
	// Utilisation de sizeof
	int taille = sizeof(chaine);
	
	for(int i=0; i<taille; i++){
	    printf("%c", chaine[i]);
	}
	printf("\n");
	return 0;
}
```
```
j'écrit un truc pour le kiff·
```

Le caractère de marqueur de fin de chaîne `\0` revient en fait a mettre un $0$ dans l'emplacement mémoire qui lui est dédié. Et, comme ce n'est pas un caractère imprimable comme `a` par exemple, il peut être représenté par différent symbole, ici pour mon compilateur ce sera `·` *le point médian*.

Ainsi, la différence entre `strlen` et `sizeof` est que l'un d'eux inclus `\0` dans la taille de la chaîne, cela peut donc rendre certains programme faux par exemple pour programmer un pendu, si on utilise `sizeof`, on vas devoir trouver un mot à $t$ caractères, alors qu'en vrai, c'est un mot à $t-1$ caractères. Du coup si vous utilisez `sizeof` il faut penser au $-1$.

On peut aussi utiliser une boucle `while` pour afficher la chaîne de caractères, elle s'arrête alors quand on trouve le marqueur de fin `\0`.

<u>Exemple :</u>  
```c
#include <stdio.h>

int main(){
	char chaine[] = "j'écrit un truc pour le kiff";
	
	int i=0;
	while(chaine[i]!='\0'){
	    printf("%c", chaine[i]);
	    i++;
	}
	
	printf("\n");
	return 0;
}
```
```
j'écrit un truc pour le kiff
```

>[!info] Remarque
>On peut utiliser `putchar(char)` à la place du `printf` pour afficher un charactère. *la fonction est valide avec une boucle `while` et avec une boucle `for` aussi.*

```c
#include <stdio.h>

int main(){
	char chaine[] = "j'écrit un truc pour le kiff";
	
	int i=0;
	while(chaine[i]!='\0'){
	   putchar(chaine[i]);
	    i++;
	}
	
	printf("\n");
	return 0;
}
```
```
j'écrit un truc pour le kiff
```

>[!warning]
>Il faut bien faire attention, un tableau de caractères et une chaînes de caractères ne représentent pas la même chose.

```c
char chaine[12] = {'i', 'n', 'f', 'o', 'r', 'm', 'a', ...}
```
est un tableau de $12$ caractères sans marqueur de fin de chaînes `\0`, on ne peux pas utiliser le format `%s` pour l'afficher avec `printf` car dans ce cas,  `%s` attend une chaîne avec `\0`, ce qui n'est pas le cas ici.

| Caractéristique          | Tableau de caractères | Chaîne de caractères                          |
| ------------------------ | --------------------- | --------------------------------------------- |
| Terminaison              | Pas forcément `'\0'`  | Toujours `'\0'`                               |
| Taille                   | Fixe (déclarée)       | Fixe ou déduite automatiquement avec littéral |
| Compatible avec `%s`     | Non                   | Oui                                           |
## Lecture
### La fonction `scanf`
#### Présentation et utilisation
La fonction `scanf` permet de lire des saisies de données que se soit des lettres, chiffres, ou alors des chaînes de caractères entières.  
Malgré tout, elle possède quelques inconvénient à ne pas négliger pour ne pas être surpris.

Pour bien commencer, étudions le prototype de la fonction `scanf`. Pour rappel, le prototype d'une fonction consiste juste à donner le type de retour de la fonction, son nom et ses arguments.

```c
int scanf(const char* format, ...);
```

Oui, le prototype de ma fonction `scanf` est un peu perturbant, il prend **au moins 1** paramètre. Les `...` signifient qu'il peut en prendre un nombre variable. On appelle cela une **==fonction variadique==**, c'est lorsqu'une fonction peut prendre un nombre variable de paramètres. Comme la fameuse fonction `printf` qui prend en paramètre au moins une chaîne de caractères puis ensuite $0$ ou $n$ paramètres supplémentaires correspondant aux données à afficher si il y en a.

Pour en revenir au prototype de `scanf`,  
- Le paramètre `format` désigne simplement le type des variables à saisir, par exemple `%d` pour un entier.
- La fonction renvoie un entier `int`, c'est le nombre de variables affectées par la saisie, ça permet en fait de vérifier si la saisie s'est déroulée correctement.
- En cas d'erreur la fonction retourne `EOF`. *explications plus bas* [[#^EOF]]

<u>Exemple :</u>  
Un exemple assez basique pour l'utilisation de `scanf`. On demande à l'utilisateur de saisir son âge puis on l'affiche.
```c
#include <stdio.h>

int main() {
    int age;
    printf("Entrez votre age : ");
    scanf("%d", &age);
    printf("\nVous avez %d ans.", age);
    return 0;
}
```
```
Entrez votre age : 20
Vous avez 20 ans.
```

Il y a quelques petites choses à voir sur ce code. 
- Dans l'utilisation de `scanf` pourquoi on met `&age` pourquoi il y a un `&` ?
- Comment on peut savoir si la donnée que l'utilisateur entre est valide ?

Pour comprendre pourquoi il y a un `&` dans l'utilisation de `scanf` il suffit de comprendre ce que fait réellement la fonction.   
Quand on utilise la fonction `scanf` c'est pour stocker des saisies utilisateurs dans une variable et l'utiliser plus tard. Ainsi, lorsqu'on utilise `scanf` *(on va prendre notre exemple comme référence)* pour afficher l'âge de l'utilisateur, lors de la saisie utilisateur, après validation, la fonction `scanf` recopie la saisie dans **l'adresse mémoire** de la variable âge qui doit être spécifiée dans la fonction.  
C'est pour cette raison le `&`, en fait quand on utilise `scanf("%d", &age)` on souhaite recopier la saisie utilisateur dans l'adresse mémoire créée pour la variable âge. Pour ce faire, on ajoute `&` avant âge.

Maintenant comment savoir si les données saisies par l'utilisateur sont correctes ?  
Regardons ce qu'il se passe si à la place de taper un entier, on tape une chaîne de charactères. *On reprend le même code que l'exemple précédant*
```
Entrez votre age : mot
Vous avez 31415 ans.
```

Alors là c'est étonnant, mais qu'est-ce que c'est ?  
En fait on a rentré une chaîne de charactères au lieu d'un entier comme spécifié avec le format `%d` alors la fonction `scanf` échoue et **ne modifie pas** la variable âge. La valeur de cette dernière reste indéfinie *l'entier $31415$ est aléatoire, lors d'une autre exécution, un autre nombre sera affiché c'est pour cette raison que l'on parle de valeur indéfinie.*

Il y a déjà quelques paragraphes, j'expliquais que la fonction `scanf` renvoie un entier, le nombre de variables affectées par la saisie. Et bien voilà comment vérifier la saisie utilisateur. Dans notre exemple on vas vérifier si une variable exactement a été affectée par la saisie si c'est le cas on renvoie l'âge sinon on renvoie un message d'erreur.

<u>Exemple :</u>  
```c
#include <stdio.h>

int main() {
    int age;
    int result; // Variable pour stockée le résultat de scanf
    printf("Entrez votre age : ");
    result = scanf("%d", &age);
    if(result==1)
        printf("Saisie valide, Vous avez %d ans.", age);
    else 
	    printf("\nErreur de saisie.\n");
    return 0;
}
```
```
Entrez votre age : 20
Saisie valide, Vous avez 20 ans.

Entrez votre age : mot
Erreur de saisie.
```

Aussi, on a dit qu'en cas d'erreur, la fonction `scanf` renvoie `EOF`. Cela mérite quelques explications. ^EOF

Pour clarifier un peu,  
la fonction `scanf` ne renvoie pas toujours `EOF` *End Of File*, c'est seulement si une erreur d'entrée/sortie se produit ou alors si on atteint la fin d'un fichier, par exemple `Ctrl+Z` sur Windows. *Notion expliquée lors du cours sur les fichiers*. Si la saisie utilisateur ne correspond pas au format attendu, la fonction `scanf` renverra $0$. 
#### Limites

### La fonction `fgets`
### La fonction `gets`