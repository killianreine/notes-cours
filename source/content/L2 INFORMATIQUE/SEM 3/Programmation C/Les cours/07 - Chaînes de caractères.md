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

<div>
<svg width="900" height="100" xmlns="http://www.w3.org/2000/svg">
  <!-- Boxes for each character -->
  <g>
    <!-- Box 0 -->
    <rect x="10" y="20" width="60" height="50" class="char-box"/>
    <text x="35" y="50" class="char-text" text-anchor="middle">i</text>
    <text x="35" y="85" class="addr-text" text-anchor="middle">0x1000</text>
    <!-- Box 1 -->
    <rect x="70" y="20" width="60" height="50" class="char-box"/>
    <text x="95" y="50" class="char-text" text-anchor="middle">n</text>
    <text x="95" y="85" class="addr-text" text-anchor="middle">0x1001</text>
    <!-- Box 2 -->
    <rect x="130" y="20" width="60" height="50" class="char-box"/>
    <text x="155" y="50" class="char-text" text-anchor="middle">f</text>
    <text x="155" y="85" class="addr-text" text-anchor="middle">0x1002</text>
    <!-- Box 3 -->
    <rect x="190" y="20" width="60" height="50" class="char-box"/>
    <text x="215" y="50" class="char-text" text-anchor="middle">o</text>
    <text x="215" y="85" class="addr-text" text-anchor="middle">0x1003</text>
    <!-- Box 4 -->
    <rect x="250" y="20" width="60" height="50" class="char-box"/>
    <text x="275" y="50" class="char-text" text-anchor="middle">r</text>
    <text x="275" y="85" class="addr-text" text-anchor="middle">0x1004</text>
    <!-- Box 5 -->
    <rect x="310" y="20" width="60" height="50" class="char-box"/>
    <text x="335" y="50" class="char-text" text-anchor="middle">m</text>
    <text x="335" y="85" class="addr-text" text-anchor="middle">0x1005</text>
    <!-- Box 6 -->
    <rect x="370" y="20" width="60" height="50" class="char-box"/>
    <text x="395" y="50" class="char-text" text-anchor="middle">a</text>
    <text x="395" y="85" class="addr-text" text-anchor="middle">0x1006</text>
    <!-- Box 7 -->
    <rect x="430" y="20" width="60" height="50" class="char-box"/>
    <text x="455" y="50" class="char-text" text-anchor="middle">t</text>
    <text x="455" y="85" class="addr-text" text-anchor="middle">0x1007</text>
    <!-- Box 8 -->
    <rect x="490" y="20" width="60" height="50" class="char-box"/>
    <text x="515" y="50" class="char-text" text-anchor="middle">i</text>
    <text x="515" y="85" class="addr-text" text-anchor="middle">0x1008</text>
    <!-- Box 9 -->
    <rect x="550" y="20" width="60" height="50" class="char-box"/>
    <text x="575" y="50" class="char-text" text-anchor="middle">q</text>
    <text x="575" y="85" class="addr-text" text-anchor="middle">0x1009</text>
    <!-- Box 10 -->
    <rect x="610" y="20" width="60" height="50" class="char-box"/>
    <text x="635" y="50" class="char-text" text-anchor="middle">u</text>
    <text x="635" y="85" class="addr-text" text-anchor="middle">0x100A</text>
    <!-- Box 11 -->
    <rect x="670" y="20" width="60" height="50" class="char-box"/>
    <text x="695" y="50" class="char-text" text-anchor="middle">e</text>
    <text x="695" y="85" class="addr-text" text-anchor="middle">0x100B</text>
    <!-- Box 12 (null terminator) -->
    <rect x="730" y="20" width="60" height="50" class="char-box" fill="#e0e0e0" stroke="#a0a0a0"/>
    <text x="755" y="50" class="char-text" text-anchor="middle">\0</text>
    <text x="755" y="85" class="addr-text" text-anchor="middle">0x100C</text>
  </g>
</svg>
</div>

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

<div>
<svg xmlns="http://www.w3.org/2000/svg" width="100%" height="190" viewBox="0 0 1000 200">
  <g id="cells" transform="translate(20,40)">
    <!-- Cell 0 -->
    <rect x="0" y="0" width="60" height="60" class="cell" />
    <text x="30" y="40" text-anchor="middle" class="label"></text>
    <text x="30" y="90" text-anchor="middle" class="index">0</text>
    <!-- Cell 1 -->
    <rect x="80" y="0" width="60" height="60" class="cell" />
    <text x="110" y="40" text-anchor="middle" class="label"></text>
    <text x="110" y="90" text-anchor="middle" class="index">1</text>
    <!-- Cell 2 -->
    <rect x="160" y="0" width="60" height="60" class="cell" />
    <text x="190" y="40" text-anchor="middle" class="label"></text>
    <text x="190" y="90" text-anchor="middle" class="index">2</text>
    <!-- Dots -->
    <circle cx="260" cy="30" r="3.5" class="dots" />
    <circle cx="280" cy="30" r="3.5" class="dots" />
    <circle cx="300" cy="30" r="3.5" class="dots" />
    <!-- Cell t-2 -->
    <rect x="340" y="0" width="60" height="60" class="cell" />
    <text x="370" y="40" text-anchor="middle" class="label"></text>
    <text x="370" y="90" text-anchor="middle" class="index">t−2</text>
    <!-- Cell t-1 -->
    <rect x="420" y="0" width="60" height="60" class="cell" />
    <text x="450" y="40" text-anchor="middle" class="label"></text>
    <text x="450" y="90" text-anchor="middle" class="index">t−1</text>
    <!-- Cell \0 -->
    <rect x="500" y="0" width="60" height="60" class="cell" />
    <text x="530" y="40" text-anchor="middle" class="label">\0</text>
    <text x="530" y="90" text-anchor="middle" class="index">t</text>
  </g>
  <!-- Brace -->
  <path class="brace" d="M 20 130 C 20 150, 20 150, 40 150 L 580 150 C 600 150, 600 150, 600 130" />
  <text x="300" y="170" text-anchor="middle" class="index brace-text">tableau de taille t+1</text>
</svg>
</div>

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
>On peut utiliser `putchar(char)` à la place du `printf` pour afficher un caractère. *la fonction est valide avec une boucle `while` et avec une boucle `for` aussi.*

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
Regardons ce qu'il se passe si à la place de taper un entier, on tape une chaîne de caractères. *On reprend le même code que l'exemple précédant*
```
Entrez votre age : mot
Vous avez 31415 ans.
```

Alors là c'est étonnant, mais qu'est-ce que c'est ?  
En fait on a rentré une chaîne de caractères au lieu d'un entier comme spécifié avec le format `%d` alors la fonction `scanf` échoue et **ne modifie pas** la variable âge. La valeur de cette dernière reste indéfinie *l'entier $31415$ est aléatoire, lors d'une autre exécution, un autre nombre sera affiché c'est pour cette raison que l'on parle de valeur indéfinie.*

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

#### Utilisation avancée
On peut aussi lire plusieurs données **en même temps** avec la fonction `scanf`, c'est pour cette raison qu'elle possède un nombre de paramètres variables.

<u>Exemple :</u>  
On souhaite lire un mot puis un nombre.
```c
#include <stdio.h>

int main() {
    char prenom[100];
    int age;
    
    printf("Entrez votre prénom et votre âge : ");
    scanf("%s%d", prenom, &age);
    printf("Salut %s, tu as %d ans", prenom, age);
    return 0;
}
```
```
Entrez votre prénom et votre âge : Paul 45
Salut Paul, tu as 45 ans
```
#### Limites
##### Lecture limitée

<u>Exemple :</u>  
On souhaite que l'utilisateur entre son nom et son prénom pour l'afficher. 
```c
#include <stdio.h>

int main() {
    char identite[100];
    printf("Entrez votre prénom et nom : ");
    scanf("%s", identite);
    printf("\nSalut tu t'appelles : %s", identite);
    return 0;
}
```
```
Entrez votre prénom et nom : Paul Durant
Salut tu t'appelles : Paul
```

Bon je pense que tu as quelques questions à poser : 
- Pourquoi dans l'utilisation de `scanf`, cette fois on met pas le `&` de l'adresse mémoire devant identité ?
- Pourquoi le résultat de la saisie est simplement `Paul` et pas `Paul Durant` comme tapé au dessus ?

On y vient, un peu de patience !  
En fait, dans notre cas on souhaite passer une chaîne de caractères à notre fonction `scanf`, et on a expliqué qu'en fin de compte c'est un tableau de `char`. Et en langage C, lorsque l'on passe un tableau en paramètre d'une fonction, ce dernier est **automatiquement converti en pointeur** vers le premier élément de ce dernier.  
Pour simplifier, quand on passe un tableau en paramètre de fonction c'est la même chose que si on passait l'adresse mémoire du premier élément du tableau. *La notion de pointeur arrive...* D'où le fait qu'ici on a pas besoin de `&`. 

Un second problème se dresse devant nous, on a tapé `Paul Durant` et le programme a affiché `Paul` uniquement. Que s'est-il passé pour `Durant` ?  
La fonction `scanf` s'arrête de lire une saisie utilisateur si elle tombe sur un espace, une tabulation ou i on appui sur entrée. Alors le second mot, ici `Durant` n'est donc pas récupéré.  
Alors il n'est pas désintégré, au contraire même il est toujours en mémoire dans ce qu'on appelle **==un buffer==**,c e qui signifie que la prochaine fois que l'on appellera la fonction `scanf`, elle lira toute seule `Durant` qui est "resté en plan" dans la mémoire.  
*Observons à l'aide d'un exemple*

<u>Exemple :</u>  
*On reprend le même que précédemment et on utilise 2 fois `scanf`*
```c
#include <stdio.h>

int main() {
    char identite[100];
    printf("Entrez votre prénom et nom : ");
    scanf("%s", identite);
    printf("\nSalut tu t'appelle : %s", identite);

	// Seconde utilisation
    printf("\nEntrez votre nouveau prénom et nom : ");
    scanf("%s", &identite);
    printf("\nSalut maintenant tu est : %s\n", identite);
    return 0;
}
```
```
Entrez votre prénom et nom : Paul Durant
Salut tu t'appelle : Paul

Entrez votre nouveau prénom et nom : 
Salut maintenant tu est : Durant
```
On remarque bien que lors de la seconde utilisation de `scanf`, l'utilisateur ne saisit rien, c'est la fonction elle même qui va lire le mot laissé dans la mémoire puis l'affiche.
##### Dépassement de mémoire
Le dépassement de mémoire est un vrai cauchemar pour tout développeur, pour comprendre ce concept plus que fondamental, nous allons l'expliquer avec un exemple et des schémas visuels semblables aux précédents. 

Création d'une variable `domaine` d'une taille définie, ici $6$.
```c
char domaine[6];
```
Cela signifie alors que l'on peut stocker un prénom de $5$ lettres, car le dernier emplacement mémoire de la chaîne est réservé au marqueur de fin de chaîne `\0` **à ne pas oublier !**.  

<div>
<svg xmlns="http://www.w3.org/2000/svg" width="1000" height="190" viewBox="0 0 1000 200">
  <g id="cells" transform="translate(20,40)">
    <!-- Cell 0 -->
    <rect x="0" y="0" width="60" height="60" class="cell" />
    <text x="30" y="40" text-anchor="middle" class="label"></text>
    <text x="30" y="90" text-anchor="middle" class="index">0</text>
    <!-- Cell 1 -->
    <rect x="80" y="0" width="60" height="60" class="cell" />
    <text x="110" y="40" text-anchor="middle" class="label"></text>
    <text x="110" y="90" text-anchor="middle" class="index">1</text>
    <!-- Cell 2 -->
    <rect x="160" y="0" width="60" height="60" class="cell" />
    <text x="190" y="40" text-anchor="middle" class="label"></text>
    <text x="190" y="90" text-anchor="middle" class="index">2</text>
    <!-- Cell 3 -->
    <rect x="240" y="0" width="60" height="60" class="cell" />
    <text x="270" y="40" text-anchor="middle" class="label"></text>
    <text x="270" y="90" text-anchor="middle" class="index">3</text>
    <!-- Cell 4 -->
    <rect x="320" y="0" width="60" height="60" class="cell" />
    <text x="350" y="40" text-anchor="middle" class="label"></text>
    <text x="350" y="90" text-anchor="middle" class="index">4</text>
    <!-- Cell 5 (\0) -->
    <rect x="400" y="0" width="60" height="60" class="cell" />
    <text x="430" y="40" text-anchor="middle" class="label">\0</text>
    <text x="430" y="90" text-anchor="middle" class="index">5</text>
  </g>
  <!-- Brace -->
  <path class="brace" d="M 20 130 C 20 150, 20 150, 40 150 L 460 150 C 480 150, 480 150, 480 130" />
  <text x="250" y="170" text-anchor="middle" class="index brace-text">tableau de taille 6</text>
</svg>
</div>

Considérons maintenant le code suivant avec l'exécution associée.
```c
#include <stdio.h>

int main() {
    char domaine[6];
    
    printf("Entrez votre domaine d'étude : ");
    scanf("%s", domaine);
    printf("Domaine : %s", domaine);
    return 0;
}
```
```
Entrez votre domaine d'étude : informatique
Domaine : informatique
```

À première vue, rien ne semble s'être produit. Malheureusement si, on vient de faire ce qu'on appelle un *buffer overflow* ou dépassement de mémoire en français.  
Ce que nous avions fais c'était créer un tableau pouvant stocker des mots allant jusqu'à 5 lettres. Or ici, on lit le mot `informatique` qui contient $12$ lettre.  
De manière visuelle, on obtient ceci : 

<div>
<svg xmlns="http://www.w3.org/2000/svg" width="850" height="200" viewBox="0 0 850 220">
  <g id="slots" transform="translate(-30,40)">
    <!-- Slots 0 à 5 -->
    <rect x="0" y="0" width="50" height="50" class="slot"/>
    <text x="25" y="32" text-anchor="middle" class="char">i</text>
    <text x="25" y="75" text-anchor="middle" class="index">0</text>
    <rect x="70" y="0" width="50" height="50" class="slot"/>
    <text x="95" y="32" text-anchor="middle" class="char">n</text>
    <text x="95" y="75" text-anchor="middle" class="index">1</text>
    <rect x="140" y="0" width="50" height="50" class="slot"/>
    <text x="165" y="32" text-anchor="middle" class="char">f</text>
    <text x="165" y="75" text-anchor="middle" class="index">2</text>
    <rect x="210" y="0" width="50" height="50" class="slot"/>
    <text x="235" y="32" text-anchor="middle" class="char">o</text>
    <text x="235" y="75" text-anchor="middle" class="index">3</text>
    <rect x="280" y="0" width="50" height="50" class="slot"/>
    <text x="305" y="32" text-anchor="middle" class="char">r</text>
    <text x="305" y="75" text-anchor="middle" class="index">4</text>
    <rect x="350" y="0" width="50" height="50" class="slot"/>
    <text x="375" y="32" text-anchor="middle" class="char">m</text>
    <text x="375" y="75" text-anchor="middle" class="index">5</text>
    <!-- Overflow 6 à 12 -->
    <rect x="420" y="0" width="50" height="50" class="slot-overflow"/>
    <text x="445" y="32" text-anchor="middle" class="char-overflow">a</text>
    <text x="445" y="75" text-anchor="middle" class="index-overflow">6</text>
    <rect x="490" y="0" width="50" height="50" class="slot-overflow"/>
    <text x="515" y="32" text-anchor="middle" class="char-overflow">t</text>
    <text x="515" y="75" text-anchor="middle" class="index-overflow">7</text>
    <rect x="560" y="0" width="50" height="50" class="slot-overflow"/>
    <text x="585" y="32" text-anchor="middle" class="char-overflow">i</text>
    <text x="585" y="75" text-anchor="middle" class="index-overflow">8</text>
    <rect x="630" y="0" width="50" height="50" class="slot-overflow"/>
    <text x="655" y="32" text-anchor="middle" class="char-overflow">q</text>
    <text x="655" y="75" text-anchor="middle" class="index-overflow">9</text>
    <rect x="700" y="0" width="50" height="50" class="slot-overflow"/>
    <text x="725" y="32" text-anchor="middle" class="char-overflow">u</text>
    <text x="725" y="75" text-anchor="middle" class="index-overflow">10</text>
    <rect x="770" y="0" width="50" height="50" class="slot-overflow"/>
    <text x="795" y="32" text-anchor="middle" class="char-overflow">e</text>
    <text x="795" y="75" text-anchor="middle" class="index-overflow">11</text>
    <rect x="840" y="0" width="50" height="50" class="slot-overflow"/>
    <text x="865" y="32" text-anchor="middle" class="char-overflow">\0</text>
    <text x="865" y="75" text-anchor="middle" class="index-overflow">12</text>
  <!-- Brace tableau prévu -->
  <path class="brace-main" d="M 0 100 C 0 115, 0 115, 15 115 L 365 115 C 380 115, 380 115, 380 100" />
  <text x="190" y="135" text-anchor="middle" class="brace-main-text">tableau de taille 6</text>
  <!-- Brace globale -->
  <path class="brace-global" d="M 0 140 C 0 155, 0 155, 15 155 L 865 155 C 880 155, 880 155, 880 140" />
  <text x="430" y="175" text-anchor="middle" class="brace-global-text">taille réelle du tableau 13</text>
  </g>
</svg>
</div>

En gros le tableau de base est trop petit pour stocker le mot informatique ainsi on le voit en rouge, le dépassement de mémoire.  
Cela peut être dangereux car si il n'est pas contrôlé, l'utilisateur peut écrire ce qu'il veut dans la mémoire. Il peut surtout insérer du code en mémoire et faire en sorte qu'il soit exécuté par le programme. C'est l'**attaque par buffer overflow**, une attaque pirate très difficile à faire.  
Pour plus d'informations sur le dépassement et ses dangers : https://fr.wikipedia.org/wiki/D%C3%A9passement_de_tampon
### La fonction `gets`
La fonction `gets` permet de lire une **ligne entière** de l'entrée standard jusqu'au retour à la ligne `\n` et de stocker cette dernière dans un tableau fourni.

<u>Exemple :</u>  
```c
#include <stdio.h>

int main() {
    char line[100]; 

    printf("Entrez une chaîne de caractères : ");
    gets(line); 
    printf("Vous avez entré : %s\n", line); // Affichage

    return 0;
}
```
```
Entrez une chaîne de caractères : une chaîne simple
Vous avez entré : Une chaîne simple
```

Inutile de passer encore énormément de temps sur `gets`, elle pose les mêmes problèmes que `scanf` : **le dépassement de mémoire**. 

>[!info] Remarque
>Depuis la norme C11, `gets` a été supprimée de la norme C.
### La fonction `fgets`
La fonction `fgets` permet de récupérer une chaîne de caractères à partir d'un flux (le plus souvent, `stdin`). 

Prototype de la fonction
```c
char *fgets(char *var, int t, FILE *stream);
```
- `var` la variable qui va permettre de stocker la chaîne de caractères lue.
- `t` la taille de la chaîne à stocker.
- `stream` le flux sur lequel on récupère la chaîne (`stdin`, fichier, ...)

Il faut savoir que la fonction `fgets` arrête la lecture lorsqu'elle rencontre `\n`, la fin du flux, ou alors après `t-1` caractères lus (`\0` le dernier caractère).

>[!warning]
>La fonction `fgets` inclus `\n` dans la chaîne lue si celle ci est rencontrée avant la limite.

<u>Exemple :</u>  
```c
#include <stdio.h>

int main() {
    char buffer[100];

    printf("Entrez une chaîne de caractères : ");
    fgets(buffer, sizeof(buffer), stdin); // Lecture sécurisée de la chaîne
    printf("Vous avez entré : %s\n", buffer);

    return 0;
}
```
```
Entrez une chaine de caractères : Apprendre la prog C
Vous avez entré : Apprendre la prog C
```

| Critère               | `scanf`                                                                | `gets`                                             | `fgets`                                                                                               |
| --------------------- | ---------------------------------------------------------------------- | -------------------------------------------------- | ----------------------------------------------------------------------------------------------------- |
| Usage principal       | Lire un mot (jusqu’au premier espace)                                  | Lire une ligne complète                            | Lire une ligne complète ou partie                                                                     |
| Limitation de lecture | Ne lit qu’un mot, pas les espaces                                      | Aucun contrôle sur la taille                       | Limité à `n-1` caractères                                                                             |
| Sécurité              | **Peu sûr** : peut dépasser le buffer si l’utilisateur tape trop       | **Très dangereux** : risque de débordement mémoire | **Sûr** si `n` correct                                                                                |
| Gestion du `\n`       | Le `\n` reste dans le buffer                                           | Supprime le `\n`automatiquement                    | Conserve le `\n` si présent (à retirer manuellement si nécessaire)                                    |
| Remarques             | Utiliser avec spécificateur de longueur : `%99s` pour un buffer de 100 | Obsolète et **déconseillé**, supprimé depuis C11   | Recommandé pour la lecture de chaînes. Supprimer le `\n` et vider le flux si la ligne est trop longue |
## Fonctions de manipulation
### Copier
En programmation C, on peut avoir besoin de copier une chaîne de caractère et il existe 2 méthodes possibles. 

#### Parcourir et recopier
Ce qui semble le plus intuitif pour commencer c'est de parcourir la chaîne a copier et copier chaque élément un à un dans une seconde chaîne.

<u>Exemple :</u>
```c
#include <stdio.h>

int main() {
    char chaine[] = "Bonjour le monde";
    char copie[100];
    
    int i = 0;
    while(chaine[i]!='\0') {
        copie[i]=chaine[i];
        i++;
    }
    chaine[i]='\0';
    printf("Chaine : %s \n|| Copie : %s", chaine, copie);
    return 0;
}
```
```
Chaine : Bonjour le monde 
|| Copie : Bonjour le monde
```

>[!warning] 
>Ne pas oublier d'ajouter le `\0` ) à la fin de la chaine.

#### La fonction `strcpy`
La fonction `strcpy` de la bibliothèque `<string.h>` permet de copier une chaîne `origine` (`\0` inclus) dans une chaîne `dest`.
```c
char* strcpy(char *dest, const char *origine)
```
- elle renvoie un pointeur vers la chaîne copiée. 

```c
#include <stdio.h>
#include <string.h>

int main() {
    char chaine[] = "Bonjour le monde";
    char copie[100];
    
    strcpy(copie, chaine);
    printf("Chaine : %s \n|| Copie : %s", chaine, copie);
    return 0;
}
```
```
Chaine : Bonjour le monde 
|| Copie : Bonjour le monde
```
### Concaténer
>[!cite] Définition
>On considère deux chaînes de caractères `ch1` et `ch2` le terme **==concaténer==** revient à assembler les deux chaînes l'une après l'autre.
#### Fonction `strcat`
```c
char *strcat(char *destination, const char *origine);
```
- On ajoute `origine` à la fin de `destination`
- La fonction renvoie un pointeur vers le premier caractère de `destination`

Il faut faire attention, la fonction `strcat` ne vérifie pas si la taille du tableau `destination` est assez grande pour ajouter `origine` à la fin, **pensez à trouver une alternative !**. <span class="error-inline">Buffer overflow</span> ! 

```c
#include <stdio.h>
#include <string.h>

int main() {
    char ch[50] = "Bonjour, ";
    char ajout[] = "monde !";

    strcat(ch, ajout);  // ajoute ajout à la fin de ch
    printf("%s\n", ch);

    return 0;
}
```
```
Bonjour, monde !
```

On peut réfléchir à une solution pour concaténer les chaînes de caractères sans avoir de dépassement de mémoire. *La solution suivante vient d'une réflexion personnelle ce n'est pas forcément la meilleure chose à faire...*

Si on considère $ch_1$ et $ch_2$ deux chaînes de tailles $t_1$ et $t_2$ respectivement (sans avoir de tableau trop grand) donnée par la fonction `strlen()`. Alors La taille du tableau $ch_1+ch_2$ est donné par $(t_1+t_2)+1$ en comptant le caractère nul.

<u>Exemple :</u> 
```c
#include <stdio.h>
#include <string.h>

int main() {
    char ch[] = "Bonjour ";
    char ajout[] = "tout le monde !";

    int taille_ch = strlen(ch);
    int taille_ajout = strlen(ajout);
    int taille_totale = taille_ch + taille_ajout + 1; // +1 pour le caractère nul

    char resultat[taille_totale];
    strcpy(resultat, ch);     // copie ch dans resultat
    strcat(resultat, ajout);  // ajoute ajout à la fin de resultat

    printf("%s\n", resultat);

    return 0;
}
```
```
Bonjour tout le monde !
```

Voici l'algorithme de la solution proposée pour éviter les dépassements mémoire.
```
concaténation
	Définition et initialisation implicite
	Récupérer les tailles respectives 
	Calcul taille totale

	Définition d'un tableau de résultat de taille_totale
	On copie origine dans resultat
	On concatène ajout dans resultat

	On affiche résultat
fin
```
Bon ok, je sais c'est un peu plus long mais bon là pas de dépassement mémoire.

#### Fonction `strncat`
En langage C, la fonction `strncat` (définie dans `<string.h>`) permet de **concaténer (ajouter)** une chaîne de caractères à la fin d’une autre, en limitant le nombre de caractères copiés.

```c
char *strncat(char *destination, const char *origine, size_t n);
```
- **`destination`** : la chaîne de destination (doit être assez grande pour contenir le résultat).
- **`origine`** : la chaîne à ajouter.
- **`n`** : le nombre maximum de caractères à copier depuis `origine`.
Elle renvoie aussi un pointeur vers `destination`.

>[!warning]
>- Il faut que le tableau `destination` soit assez grand pour contenir la chaîne finale + `\0` (le caractère de fin de chaîne).
>- `strncat` ajoute toujours `\0` à la fin.

<u>Exemple :</u>
```c
#include <stdio.h>
#include <string.h>

int main() {
    char dest[20] = "Bonjour";
    char src[] = "_le monde !";

    // On ajoute seulement les 5 premiers caractères de src
    strncat(dest, src, 5);

    printf("Résultat : %s\n", dest)
    return 0;
}
```
```
Bonjour_le m
```

On peut illustrer la concaténation de l'exemple précédant de la manière suivante : 

<div>
<svg xmlns="http://www.w3.org/2000/svg" width="800" height="400" viewBox="0 0 1200 600">
  <defs>
    <marker id="arrowhead" markerWidth="10" markerHeight="7" refX="10" refY="3.5" orient="auto">
      <polygon points="0 0, 10 3.5, 0 7" fill="#660493"/>
    </marker>
  </defs>
  <!-- Séparateur horizontal -->
  <line x1="20" y1="280" x2="1180" y2="280" class="panel-line"/>
  <!-- ===== AVANT ===== -->
  <text x="30" y="30" class="title">AVANT</text>
  <text x="30" y="70" class="subtitle">dest[20] = "Bonjour"</text>
  <g transform="translate(30,85)">
    <!-- Dest initial -->
    <rect x="0" y="0" width="50" height="50" class="cell"/><text x="25" y="32" text-anchor="middle" class="label">B</text><text x="25" y="65" text-anchor="middle" class="index">0</text>
    <rect x="50" y="0" width="50" height="50" class="cell"/><text x="75" y="32" text-anchor="middle" class="label">o</text><text x="75" y="65" text-anchor="middle" class="index">1</text>
    <rect x="100" y="0" width="50" height="50" class="cell"/><text x="125" y="32" text-anchor="middle" class="label">n</text><text x="125" y="65" text-anchor="middle" class="index">2</text>
    <rect x="150" y="0" width="50" height="50" class="cell"/><text x="175" y="32" text-anchor="middle" class="label">j</text><text x="175" y="65" text-anchor="middle" class="index">3</text>
    <rect x="200" y="0" width="50" height="50" class="cell"/><text x="225" y="32" text-anchor="middle" class="label">o</text><text x="225" y="65" text-anchor="middle" class="index">4</text>
    <rect x="250" y="0" width="50" height="50" class="cell"/><text x="275" y="32" text-anchor="middle" class="label">u</text><text x="275" y="65" text-anchor="middle" class="index">5</text>
    <rect x="300" y="0" width="50" height="50" class="cell"/><text x="325" y="32" text-anchor="middle" class="label">r</text><text x="325" y="65" text-anchor="middle" class="index">6</text>
    <rect x="350" y="0" width="50" height="50" class="cell"/><text x="375" y="32" text-anchor="middle" class="label">\0</text><text x="375" y="65" text-anchor="middle" class="index">7</text>
    <!-- cases vides -->
    <rect x="400" y="0" width="50" height="50" class="vide"/><text x="425" y="65" text-anchor="middle" class="index">8</text>
    <rect x="450" y="0" width="50" height="50" class="vide"/><text x="475" y="65" text-anchor="middle" class="index">9</text>
    <rect x="500" y="0" width="50" height="50" class="vide"/><text x="525" y="65" text-anchor="middle" class="index">10</text>
    <rect x="550" y="0" width="50" height="50" class="vide"/><text x="575" y="65" text-anchor="middle" class="index">11</text>
    <rect x="600" y="0" width="50" height="50" class="vide"/><text x="625" y="65" text-anchor="middle" class="index">12</text>
    <rect x="650" y="0" width="50" height="50" class="vide"/><text x="675" y="65" text-anchor="middle" class="index">13</text>
    <rect x="700" y="0" width="50" height="50" class="vide"/><text x="725" y="65" text-anchor="middle" class="index">14</text>
    <rect x="750" y="0" width="50" height="50" class="vide"/><text x="775" y="65" text-anchor="middle" class="index">15</text>
    <rect x="800" y="0" width="50" height="50" class="vide"/><text x="825" y="65" text-anchor="middle" class="index">16</text>
    <rect x="850" y="0" width="50" height="50" class="vide"/><text x="875" y="65" text-anchor="middle" class="index">17</text>
    <rect x="900" y="0" width="50" height="50" class="vide"/><text x="925" y="65" text-anchor="middle" class="index">18</text>
    <rect x="950" y="0" width="50" height="50" class="vide"/><text x="975" y="65" text-anchor="middle" class="index">19</text>
  </g>
  <!-- src AVANT -->
  <text x="30" y="190" class="subtitle">src[] = "_le monde !"</text>
  <g transform="translate(30,205)">
    <rect x="0" y="0" width="50" height="50" class="src"/><text x="25" y="32" text-anchor="middle" class="src-label">_</text>
    <rect x="50" y="0" width="50" height="50" class="src"/><text x="75" y="32" text-anchor="middle" class="src-label">l</text>
    <rect x="100" y="0" width="50" height="50" class="src"/><text x="125" y="32" text-anchor="middle" class="src-label">e</text>
    <rect x="150" y="0" width="50" height="50" class="src"/><text x="175" y="32" text-anchor="middle" class="src-label"> </text>
    <rect x="200" y="0" width="50" height="50" class="src"/><text x="225" y="32" text-anchor="middle" class="src-label">m</text>
    <rect x="250" y="0" width="50" height="50" class="cell"/><text x="275" y="32" text-anchor="middle" class="label">o</text>
    <rect x="300" y="0" width="50" height="50" class="cell"/><text x="325" y="32" text-anchor="middle" class="label">n</text>
    <rect x="350" y="0" width="50" height="50" class="cell"/><text x="375" y="32" text-anchor="middle" class="label">d</text>
    <rect x="400" y="0" width="50" height="50" class="cell"/><text x="425" y="32" text-anchor="middle" class="label">e</text>
    <rect x="450" y="0" width="50" height="50" class="cell"/><text x="475" y="32" text-anchor="middle" class="label"> </text>
    <rect x="500" y="0" width="50" height="50" class="cell"/><text x="525" y="32" text-anchor="middle" class="label">!</text>
    <rect x="550" y="0" width="50" height="50" class="cell"/><text x="575" y="32" text-anchor="middle" class="label">\0</text>
  </g>
  <!-- ===== APRÈS ===== -->
  <text x="30" y="310" class="title">APRÈS</text>
  <text x="30" y="350" class="subtitle">dest[20] = "Bonjour_le m"</text>
  <g transform="translate(30,365)">
    <rect x="0" y="0" width="50" height="50" class="cell"/><text x="25" y="32" text-anchor="middle" class="label">B</text><text x="25" y="65" text-anchor="middle" class="index">0</text>
    <rect x="50" y="0" width="50" height="50" class="cell"/><text x="75" y="32" text-anchor="middle" class="label">o</text><text x="75" y="65" text-anchor="middle" class="index">1</text>
    <rect x="100" y="0" width="50" height="50" class="cell"/><text x="125" y="32" text-anchor="middle" class="label">n</text><text x="125" y="65" text-anchor="middle" class="index">2</text>
    <rect x="150" y="0" width="50" height="50" class="cell"/><text x="175" y="32" text-anchor="middle" class="label">j</text><text x="175" y="65" text-anchor="middle" class="index">3</text>
    <rect x="200" y="0" width="50" height="50" class="cell"/><text x="225" y="32" text-anchor="middle" class="label">o</text><text x="225" y="65" text-anchor="middle" class="index">4</text>
    <rect x="250" y="0" width="50" height="50" class="cell"/><text x="275" y="32" text-anchor="middle" class="label">u</text><text x="275" y="65" text-anchor="middle" class="index">5</text>
    <rect x="300" y="0" width="50" height="50" class="cell"/><text x="325" y="32" text-anchor="middle" class="label">r</text><text x="325" y="65" text-anchor="middle" class="index">6</text>
    <rect x="350" y="0" width="50" height="50" class="src"/><text x="375" y="32" text-anchor="middle" class="src-label">_</text><text x="375" y="65" text-anchor="middle" class="index">7</text>
    <rect x="400" y="0" width="50" height="50" class="src"/><text x="425" y="32" text-anchor="middle" class="src-label">l</text><text x="425" y="65" text-anchor="middle" class="index">8</text>
    <rect x="450" y="0" width="50" height="50" class="src"/><text x="475" y="32" text-anchor="middle" class="src-label">e</text><text x="475" y="65" text-anchor="middle" class="index">9</text>
    <rect x="500" y="0" width="50" height="50" class="src"/><text x="525" y="32" text-anchor="middle" class="src-label"> </text><text x="525" y="65" text-anchor="middle" class="index">10</text>
    <rect x="550" y="0" width="50" height="50" class="src"/><text x="575" y="32" text-anchor="middle" class="src-label">m</text><text x="575" y="65" text-anchor="middle" class="index">11</text>
    <rect x="600" y="0" width="50" height="50" class="cell"/><text x="625" y="32" text-anchor="middle" class="label">\0</text><text x="625" y="65" text-anchor="middle" class="index">12</text>
    <!-- cases vides -->
    <rect x="650" y="0" width="50" height="50" class="vide"/><text x="675" y="65" text-anchor="middle" class="index">13</text>
    <rect x="700" y="0" width="50" height="50" class="vide"/><text x="725" y="65" text-anchor="middle" class="index">14</text>
    <rect x="750" y="0" width="50" height="50" class="vide"/><text x="775" y="65" text-anchor="middle" class="index">15</text>
    <rect x="800" y="0" width="50" height="50" class="vide"/><text x="825" y="65" text-anchor="middle" class="index">16</text>
    <rect x="850" y="0" width="50" height="50" class="vide"/><text x="875" y="65" text-anchor="middle" class="index">17</text>
    <rect x="900" y="0" width="50" height="50" class="vide"/><text x="925" y="65" text-anchor="middle" class="index">18</text>
    <rect x="950" y="0" width="50" height="50" class="vide"/><text x="975" y="65" text-anchor="middle" class="index">19</text>
  </g>
  <!-- src inchangé -->
  <text x="30" y="470" class="subtitle">src[]</text>
  <g transform="translate(30,485)">
    <rect x="0" y="0" width="50" height="50" class="src"/><text x="25" y="32" text-anchor="middle" class="src-label">_</text>
    <rect x="50" y="0" width="50" height="50" class="src"/><text x="75" y="32" text-anchor="middle" class="src-label">l</text>
    <rect x="100" y="0" width="50" height="50" class="src"/><text x="125" y="32" text-anchor="middle" class="src-label">e</text>
    <rect x="150" y="0" width="50" height="50" class="src"/><text x="175" y="32" text-anchor="middle"
	    class="src-label"> </text>
    <rect x="200" y="0" width="50" height="50" class="src"/><text x="225" y="32" text-anchor="middle" class="src-label">m</text>
    <rect x="250" y="0" width="50" height="50" class="cell"/><text x="275" y="32" text-anchor="middle" class="label">o</text>
    <rect x="300" y="0" width="50" height="50" class="cell"/><text x="325" y="32" text-anchor="middle" class="label">n</text>
    <rect x="350" y="0" width="50" height="50" class="cell"/><text x="375" y="32" text-anchor="middle" class="label">d</text>
    <rect x="400" y="0" width="50" height="50" class="cell"/><text x="425" y="32" text-anchor="middle" class="label">e</text>
    <rect x="450" y="0" width="50" height="50" class="cell"/><text x="475" y="32" text-anchor="middle" class="label"> </text>
    <rect x="500" y="0" width="50" height="50" class="cell"/><text x="525" y="32" text-anchor="middle" class="label">!</text>
    <rect x="550" y="0" width="50" height="50" class="cell"/><text x="575" y="32" text-anchor="middle" class="label">\0</text>
  </g>
  <!-- Flèches montrant la copie -->
  <text x="30" y="570" class="note">5 caractères copiés depuis src vers dest (indices 7 à 11)</text>
  <line x1="55" y1="485" x2="400" y2="415" class="arrow"/>
  <line x1="105" y1="485" x2="450" y2="415" class="arrow"/>
  <line x1="155" y1="485" x2="500" y2="415" class="arrow"/>
  <line x1="205" y1="485" x2="550" y2="415" class="arrow"/>
  <line x1="255" y1="485" x2="600" y2="415" class="arrow"/>
</svg>
</div>

### Comparer 
En **C**, on ne peut pas comparer des chaînes avec les opérateurs `==` ou `!=` comme en Python ou Java, car une chaîne est représentée par un **tableau de caractères** (donc une adresse mémoire). Pour comparer le **contenu**, on utilise la fonction **`strcmp`** (ou ses variantes) de `<string.h>`.

L'objet de cette partie, est de présenter le prototype des fonctions de comparaison, les détailler brièvement et montrer un exemple simple. 
#### Fonction `strcmp`
```c
int strcmp(const char *ch1, const char *ch2);
```
- Renvoie un entier selon le résultat de la comparaison.
- Prend en paramètres de chaînes de caractères.

| Valeur de retour | Siginification                   |
| ---------------- | -------------------------------- |
| `0`              | Les deux chaînes sont identiques |
| `<0`             | `ch1` plus petit que `ch2`       |
| `>0`             | `ch1` plus grand que `ch2`       |
<u>Exemple :</u>
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Bonjour";
    char str2[] = "Bonjour";
    char str3[] = "Bonsoir";

    if (strcmp(str1, str2) == 0) {
        printf("str1 et str2 sont identiques\n");
    } else {
        printf("str1 et str2 sont différents\n");
    }

    if (strcmp(str1, str3) == 0) {
        printf("str1 et str3 sont identiques\n");
    } else {
        printf("str1 et str3 sont différents\n");
    }

    return 0;
}
```
```
str1 et str2 sont identiques
str1 et str3 sont différents 
```
#### La fonction `strncmp`
Elle permet en fait de comparer les $N$ premiers caractères.

```c
int strncmp(const char *ch1, const char *ch2, size_t n );
```
- Elle renvoie un entier résultant de la comparaison
- Elle prend en argument les deux chaînes `ch1` et `ch2` puis `n` le nombre de caractères à comparer.

<u>Exemple :</u>
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Bonjour";
    char str2[] = "Bonbon";

    if (strncmp(str1, str2, 3) == 0) {
        printf("Les 3 premiers caractères sont identiques\n");
    } else {
        printf("Les 3 premiers caractères sont différents\n");
    }

    return 0;
}
```
```
Les 3 premiers caractères sont identiques.
```

#### Comparaison manuelle
Comme toutes les manipulations vues sur les chaînes, on peut aussi n'utiliser aucune des fonctions vues et faire notre propre fonction de comparaison en utilisant une boucle.

<u>Exemple :</u>
```c
#include <stdio.h>

int main() {
    char str1[] = "Bonjour";
    char str2[] = "Bonjour";
    int i = 0, identique = 1;

    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            identique = 0;
            break;
        }
        i++;
    }

    if (identique) {
        printf("Les chaînes sont identiques\n");
    } else {
        printf("Les chaînes sont différentes\n");
    }

    return 0;
}
```
```
Les chaînes sont identiques
```
On compare les deux chaînes en les parcourant selon un indice commun `i` pour accéder à l'élément à la position `i` de chaque chaîne. On boucle tant qu'au moins une des chaînes n'est pas terminée, c'est à dire tant que l'on ne rencontre pas le marqueur de fin de chaîne `\0`.  
Si les éléments courant des chaînes sont différent on met identique à $0$ et on stoppe la boucle. En gros ça veut dire que les chaînes ne sont pas identiques. Dans le cas échéant, on incrémente l'indice et on boucle une autre fois.
### Rechercher
En C, pour **rechercher un caractère ou une sous-chaîne dans une chaîne**, on utilise principalement les fonctions de `<string.h>` ou on peut le faire manuellement.
#### La fonction `strchr`
Le fonction `strchr` de la bibliothèque `<string.h>` permet de localiser la première occurrence d'un caractère dans une chaîne de caractères.
```c
char *strchr(char * chaine, int car);
```
- Elle prend en paramètres :
	- Une chaîne de caractères `chaine`, c'est là ou on effectue la recherche
	- Un entier qui correspond au caractère recherché *pour rappel `char` est aussi un entier, le code ASCII du caractère*
- Elle renvoie un pointeur vers l'occurrence du caractère. Le cas échéant, la fonction renverra `NULL`.

>[!info] Remarque
>Si `car = \0` alors la fonction renverra un pointeur vers la fin de la chaîne.

<u>Exemple :</u>  
On récupère la première occurrence de la lettre `o` et on affiche la sous-chaîne à partir de ce dernier.
```c
#include <stdio.h>
#include <string.h>

int main() {
    const char *texte = "Bonjour le monde";
    char *ptr; // Le pointeur vers l'occurrence

    ptr = strchr(texte, 'o');

    if (ptr != NULL) {
        printf("Caractère trouvé : '%c'\n", *ptr);
        printf("Sous-chaîne à partir du 'o' : \"%s\"\n", ptr);
    } else {
        printf("Caractère non trouvé\n");
    }

    return 0;
}
```
```
Caractère trouvé : 'o'
Sous-chaîne à partir du 'o' : "onjour le monde"
```

$\boxed{\text{Si pas d'occurence trouvée}}$  
Jusque là c'est assez simple, on a pris un exemple dans lequel la lettre `o` était présente dans la chaîne. Et puis même si ce dernier n'était pas présent, c'est le bloc `else` qui aurait pris le relai et affiché que le caractère n'a pas été trouvé.

Mais maintenant, on considère la chaîne `informatique` et on cherche l'occurrence de la lettre `b`, sans savoir si cette dernière est présente dans le mot. On va alors rechercher avec `strchr` sans vérifier si le pointeur existe.  
L'objectif est de comprendre ce qu'il va se passer pour ne pas le reproduire.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char *chaine = "informatique";
    char *ptr;

    // Recherche du premier 'z'
    ptr = strchr(chaine, 'z');

        printf("Caractère trouvé : '%c'\n", *ptr);
        printf("Sous-chaîne à partir du 'o' : \"%s\"\n", ptr);

    return 0;
}
```
```
Segmentation fault
```
Qu-est-ce que ça veut dire ? Comment cela s'est-il produit ? 

On cherche la lettre `z` dans le chaîne `informatique` naturellement, cette dernière n'apparaît pas dans le mot alors lors de l'utilisation de la fonction `strchr` le pointeur `ptr` sera égal à `NULL`.  
Ensuite **sans vérifier l'existence du pointeur** vous souhaitez afficher le caractère trouvé. Puisqu'ici `ptr=NULL` vous essayez d'accéder à l'adresse `0x0` ce qui est interdit en C, l'erreur <span class="error-inline">segmentation fault</span> *erreur d'exécution* se produit.

C'est pour cette raison qu'il faut ***vérifier l'existence du pointeur avant d'exploiter les résultats*** puisque s'il n'existent pas, ça risque de faire planter votre code dans la majeure partie des cas.

- ***SOLUTION*** 
```c
if(*ptr){
	// Code a exécuter si occurrence trouvée
} else {
	// Code a exécuté si occurence absente
}
```

#### La fonction `strstr`
Elle permet cette fois de **rechercher une sous-chaîne** au lieu d'un simple caractère (avec `strchr`).
```c
char *strstr(char *ch, char *motif);
```
Elle permet de rechercher `motif` dans la chaîne `ch`.  
Elle retourne :
- Un pointeur vers la première occurrence de `motif` si elle existe
- `NULL` le cas échéant

>[!info] Remarque
>```c
>ptr = strstr(chaine, "");
>```
>Renverra en fait la chaîne de caractère `chaine`.

<u>Exemple :</u>  
```c
#include <stdio.h>
#include <string.h>

int main() {
    char *chaine = "informatique";
    char *ptr;

    // Recherche d'une sous-chaîne qui n'existe pas
    ptr = strstr(chaine, "zzz");
    if(ptr){
        printf("Motif trouvé : \"%s\"\n", ptr);
    }else{
        printf("Motif absent ici....");
    }

    return 0;
}
```
```
Motif absent ici....
```

>[!tip] Astuce
>Les deux écritures suivantes en C sont strictement équivalentes :
>```c
>if(ptr) === if(ptr != NULL)
>``` 
### Découper
La fonction `strtok` permet de découper une chaîne de caractères en morceaux selon des séparateurs. 
```c
char *strtok(char *chaine, char *sep);
```
On découpe la chaîne `chaine` en fonction du séparateur `sep`. 

Le fonctionnement de cette fonction est un peu plus complexe à comprendre mais penchons nous quand même dessus, histoire de savoir ce qu'il se passe.

<div>
<svg xmlns="http://www.w3.org/2000/svg" width="700" height="800" viewBox="0 0 800 800">
  <defs>
    <marker id="arrowhead" markerWidth="12" markerHeight="8" refX="12" refY="4" orient="auto">
      <polygon points="0 0, 12 4, 0 8" fill="#1f4e79"/>
    </marker>
  </defs>
  <!-- Titre principal -->
  <text x="400" y="40" text-anchor="middle" class="title">Fonctionnement de <tspan class="code">strtok(s, " ")</tspan></text>
  <text x="400" y="65" text-anchor="middle" class="subtitle">avec <tspan class="code">s = "le mon de"</tspan></text>
  <text x="400" y="85" text-anchor="middle" class="txtLeg">⚠️ <tspan class="code">strtok</tspan> MODIFIE la chaîne : chaque séparateur trouvé est remplacé par <tspan class="code">\0</tspan></text>
  <!-- ===== ÉTAT INITIAL ===== -->
  <rect x="20" y="110" width="760" height="140" class="step-bg"/>
  <text x="40" y="140" class="subtitle">État initial (buffer s en mémoire)</text>
  <g transform="translate(70,160)">
    <rect x="0" y="0" width="60" height="60" class="cell"/><text x="30" y="38" text-anchor="middle" class="label">l</text><text x="30" y="75" text-anchor="middle" class="index">0</text>
    <rect x="60" y="0" width="60" height="60" class="cell"/><text x="90" y="38" text-anchor="middle" class="label">e</text><text x="90" y="75" text-anchor="middle" class="index">1</text>
    <rect x="120" y="0" width="60" height="60" class="cell"/><text x="150" y="38" text-anchor="middle" class="label">␣</text><text x="150" y="75" text-anchor="middle" class="index">2</text>
    <rect x="180" y="0" width="60" height="60" class="cell"/><text x="210" y="38" text-anchor="middle" class="label">m</text><text x="210" y="75" text-anchor="middle" class="index">3</text>
    <rect x="240" y="0" width="60" height="60" class="cell"/><text x="270" y="38" text-anchor="middle" class="label">o</text><text x="270" y="75" text-anchor="middle" class="index">4</text>
    <rect x="300" y="0" width="60" height="60" class="cell"/><text x="330" y="38" text-anchor="middle" class="label">n</text><text x="330" y="75" text-anchor="middle" class="index">5</text>
    <rect x="360" y="0" width="60" height="60" class="cell"/><text x="390" y="38" text-anchor="middle" class="label">␣</text><text x="390" y="75" text-anchor="middle" class="index">6</text>
    <rect x="420" y="0" width="60" height="60" class="cell"/><text x="450" y="38" text-anchor="middle" class="label">d</text><text x="450" y="75" text-anchor="middle" class="index">7</text>
    <rect x="480" y="0" width="60" height="60" class="cell"/><text x="510" y="38" text-anchor="middle" class="label">e</text><text x="510" y="75" text-anchor="middle" class="index">8</text>
    <rect x="540" y="0" width="60" height="60" class="delimFinal"/><text x="570" y="38" text-anchor="middle">\0</text><text x="570" y="75" text-anchor="middle" class="index">9</text>
  </g>
  <!-- ===== APPEL 1 ===== -->
  <rect x="20" y="270" width="760" height="140" class="step-bg"/>
  <text x="40" y="300" class="subtitle">1) Premier appel : <tspan class="code">strtok(s, " ")</tspan></text>
  <g transform="translate(70,320)">
    <rect x="0" y="0" width="60" height="60" class="cell"/><text x="30" y="38" text-anchor="middle" class="label">l</text><text x="30" y="75" text-anchor="middle" class="index">0</text>
    <rect x="60" y="0" width="60" height="60" class="cell"/><text x="90" y="38" text-anchor="middle" class="label">e</text><text x="90" y="75" text-anchor="middle" class="index">1</text>
    <rect x="120" y="0" width="60" height="60" class="delim-modified"/><text x="150" y="38" text-anchor="middle" class="nulltxt">\0</text><text x="150" y="75" text-anchor="middle" class="index">2</text>
    <rect x="180" y="0" width="60" height="60" class="cell"/><text x="210" y="38" text-anchor="middle" class="label">m</text><text x="210" y="75" text-anchor="middle" class="index">3</text>
    <rect x="240" y="0" width="60" height="60" class="cell"/><text x="270" y="38" text-anchor="middle" class="label">o</text><text x="270" y="75" text-anchor="middle" class="index">4</text>
    <rect x="300" y="0" width="60" height="60" class="cell"/><text x="330" y="38" text-anchor="middle" class="label">n</text><text x="330" y="75" text-anchor="middle" class="index">5</text>
    <rect x="360" y="0" width="60" height="60" class="cell"/><text x="390" y="38" text-anchor="middle" class="label">␣</text><text x="390" y="75" text-anchor="middle" class="index">6</text>
    <rect x="420" y="0" width="60" height="60" class="cell"/><text x="450" y="38" text-anchor="middle" class="label">d</text><text x="450" y="75" text-anchor="middle" class="index">7</text>
    <rect x="480" y="0" width="60" height="60" class="cell"/><text x="510" y="38" text-anchor="middle" class="label">e</text><text x="510" y="75" text-anchor="middle" class="index">8</text>
    <rect x="540" y="0" width="60" height="60" class="delimFinal"/><text x="570" y="38" text-anchor="middle">\0</text><text x="570" y="75" text-anchor="middle" class="index">9</text>
    <!-- Boîte de retour -->
    <rect x="610" y="15" width="80" height="30" class="ret-box"/>
    <text x="650" y="35" text-anchor="middle" class="ret-text">"le"</text>
  </g>
  <!-- ===== APPEL 2 ===== -->
  <rect x="20" y="430" width="760" height="140" class="step-bg"/>
  <text x="40" y="460" class="subtitle">2) Deuxième appel : <tspan class="code">strtok(NULL, " ")</tspan></text>
  <g transform="translate(70,480)">
    <rect x="0" y="0" width="60" height="60" class="cell"/><text x="30" y="38" text-anchor="middle" class="label">l</text><text x="30" y="75" text-anchor="middle" class="index">0</text>
    <rect x="60" y="0" width="60" height="60" class="cell"/><text x="90" y="38" text-anchor="middle" class="label">e</text><text x="90" y="75" text-anchor="middle" class="index">1</text>
    <rect x="120" y="0" width="60" height="60" class="delim-modified"/><text x="150" y="38" text-anchor="middle" class="nulltxt">\0</text><text x="150" y="75" text-anchor="middle" class="index">2</text>
    <rect x="180" y="0" width="60" height="60" class="cell"/><text x="210" y="38" text-anchor="middle" class="label">m</text><text x="210" y="75" text-anchor="middle" class="index">3</text>
    <rect x="240" y="0" width="60" height="60" class="cell"/><text x="270" y="38" text-anchor="middle" class="label">o</text><text x="270" y="75" text-anchor="middle" class="index">4</text>
    <rect x="300" y="0" width="60" height="60" class="cell"/><text x="330" y="38" text-anchor="middle" class="label">n</text><text x="330" y="75" text-anchor="middle" class="index">5</text>
    <rect x="360" y="0" width="60" height="60" class="delim-modified"/><text x="390" y="38" text-anchor="middle" class="nulltxt">\0</text><text x="390" y="75" text-anchor="middle" class="index">6</text>
    <rect x="420" y="0" width="60" height="60" class="cell"/><text x="450" y="38" text-anchor="middle" class="label">d</text><text x="450" y="75" text-anchor="middle" class="index">7</text>
    <rect x="480" y="0" width="60" height="60" class="cell"/><text x="510" y="38" text-anchor="middle" class="label">e</text><text x="510" y="75" text-anchor="middle" class="index">8</text>
    <rect x="540" y="0" width="60" height="60" class="delimFinal"/><text x="570" y="38" text-anchor="middle">\0</text><text x="570" y="75" text-anchor="middle" class="index">9</text>
    <!-- Boîte de retour -->
    <rect x="610" y="15" width="90" height="30" class="ret-box"/>
    <text x="655" y="35" text-anchor="middle" class="ret-text">"mon"</text>
  </g>
  <!-- ===== APPEL 3 ===== -->
  <rect x="20" y="590" width="760" height="140" class="step-bg"/>
  <text x="40" y="620" class="subtitle">3) Troisième appel : <tspan class="code">strtok(NULL, " ")</tspan></text>
  <g transform="translate(70,640)">
    <rect x="0" y="0" width="60" height="60" class="cell"/><text x="30" y="38" text-anchor="middle" class="label">l</text><text x="30" y="75" text-anchor="middle" class="index">0</text>
    <rect x="60" y="0" width="60" height="60" class="cell"/><text x="90" y="38" text-anchor="middle" class="label">e</text><text x="90" y="75" text-anchor="middle" class="index">1</text>
    <rect x="120" y="0" width="60" height="60" class="delim-modified"/><text x="150" y="38" text-anchor="middle" class="nulltxt">\0</text><text x="150" y="75" text-anchor="middle" class="index">2</text>
    <rect x="180" y="0" width="60" height="60" class="cell"/><text x="210" y="38" text-anchor="middle" class="label">m</text><text x="210" y="75" text-anchor="middle" class="index">3</text>
    <rect x="240" y="0" width="60" height="60" class="cell"/><text x="270" y="38" text-anchor="middle" class="label">o</text><text x="270" y="75" text-anchor="middle" class="index">4</text>
    <rect x="300" y="0" width="60" height="60" class="cell"/><text x="330" y="38" text-anchor="middle" class="label">n</text><text x="330" y="75" text-anchor="middle" class="index">5</text>
    <rect x="360" y="0" width="60" height="60" class="delim-modified"/><text x="390" y="38" text-anchor="middle" class="nulltxt">\0</text><text x="390" y="75" text-anchor="middle" class="index">6</text>
    <rect x="420" y="0" width="60" height="60" class="cell"/><text x="450" y="38" text-anchor="middle" class="label">d</text><text x="450" y="75" text-anchor="middle" class="index">7</text>
    <rect x="480" y="0" width="60" height="60" class="cell"/><text x="510" y="38" text-anchor="middle" class="label">e</text><text x="510" y="75" text-anchor="middle" class="index">8</text>
    <rect x="540" y="0" width="60" height="60" class="delimFinal"/><text x="570" y="38" text-anchor="middle">\0</text><text x="570" y="75" text-anchor="middle" class="index">9</text>
    
    <!-- Boîte de retour -->
    <rect x="610" y="15" width="80" height="30" class="ret-box"/>
    <text x="650" y="35" text-anchor="middle" class="ret-text">"de"</text>
    
  </g>
  <!-- ===== FIN ===== -->
  <rect x="20" y="750" width="760" height="50" class="step-bg"/>
  <text x="40" y="780" class="subtitle">4) Quatrième appel : <tspan class="code">strtok(NULL, " ") → NULL</tspan></text>
  <rect x="550" y="760" width="80" height="30" class="ret-box" style="fill: #ffebee; stroke: #d32f2f;"/>
  <text x="590" y="780" text-anchor="middle" class="ret-text" style="fill: #d32f2f;">NULL</text>
  <text x="635" y="780" class="note">(plus de jetons)</text>
  <!-- Légende dans le coin supérieur droit -->
<g transform="translate(650, 10)">
  <rect x="0" y="0" width="35" height="22" class="cell"/>
  <text x="45" y="16" class="txtLeg" text-anchor="start">Caractère normal</text>

  <rect x="0" y="30" width="35" height="22" class="delim-modified"/>
  <text x="45" y="46" class="txtLeg" text-anchor="start">Séparateur → '\0'</text>
</g>
</svg>
</div>

On considère une chaîne de caractères `s` et un délimiteur `d` tels que : 
```c
char* s[] = "le mon de";
char* d[] = " ";
```
Pour suivre l'évolution du token `t` tel que : 
```c
char* token = strtok(s, d);
```

>[!cite] Définition
>Un **token** (anglais) ou **jeton** (français) est une **sous-chaîne extraite d’une chaîne plus grande**, séparée par des **délimiteurs**.

- Premier appel `strtok(s, d)`
La fonction `strtok` commence au début de `le mon de`. Elle va alors lire successivement les lettres `l` puis `e` qui ne correspondent pas au délimiteur.  
Elle trouve ensuite un espace, qu'elle va donc remplacer par `\0`.  
La variable `token` pointe alors vers la chaîne `le`, et la chaîne initiale devient donc : 
```
"le\0mon de"
```

- Deuxième appel : `strtok(NULL, d)`
La fonction `strtok` reprend la lecture **après `\0`**, elle continue de lire les lettres `m`, `o`, `n` pour tomber à nouveau sur un délimiteur qu'elle remplace aussi par `\0`.  
Résultat, `token` pointe désormais vers `mon` et la chaîne initiale est encore modifiée :
```
"le\0mon\0de"
```

- Troisième appel : `strtok(NULL, d)`
La fonction reprend la lecture après le `\0` qu'elle vient de mettre à la place du délimiteur. Elle rencontre alors les caractères `d` et `e`, puis arrive à la fin de la chaîne en rencontrant le marqueur de fin de chaîne.  
Résultat `token` pointe vers `de` et la chaîne n'est pas modifiée, `strtok` ne va pas modifier `\0` par `\0` ce serait inutile.

- Quatrième appel : `strtok(NULL, d)`
Plus de token, la fonction retourne `NULL` puisqu'elle a finit de lire la chaîne.
# Sensibilité à la casse
Ah, la **==sensibilité à la casse==** en C est un point important : par défaut, **les comparaisons de chaînes (`strcmp`, `strtok`, etc.) distinguent les majuscules et minuscules**.
```c
strcmp("Chat", "chat") // renvoie != 0, donc elles sont considérées différentes
```

Pour **ignorer la casse**, il y a plusieurs techniques selon ce que tu veux faire mais nous allons voir la plus simple.
- Convertir les chaînes en minuscules ou majuscules
Avec `tolower` ou `toupper` sur chaque caractère. 

<u>Exemple :</u>
```c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void to_lower(char *s) {
    for(int i = 0; s[i]; i++) {
        s[i] = tolower((char) s[i]);
    }
}

int main() {
    char s1[] = "Chat";
    char s2[] = "chat";

    to_lower(s1);
    to_lower(s2);

    if(strcmp(s1, s2) == 0) {
        printf("Égal (insensible à la casse)\n");
    }
}
```
*Certaines des écritures sont encore un peu floues pour vous, c'est normal, nous y reviendrons plus tard...*

# Suivant 
- Cours suivant : [[08 - Les pointeurs]]