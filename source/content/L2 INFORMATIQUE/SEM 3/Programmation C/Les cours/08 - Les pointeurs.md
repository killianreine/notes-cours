# Introduction
Les objets déjà évoqués dans les cours précédents *(tableau, fonction, variable)* ont tous un point commun, il correspondent tous à une inscription localisée dans la mémoire vive *(ou RAM)*, on appelle ça l'**==adresse==**. L'adresse représente un nombre et il correspond en fait à un emplacement de la mémoire. 
# Généralités sur les pointeurs
## Définition
>[!cite] Définition
>Un **==pointeur==** est une variable qui contient l'adresse mémoire d'une autre variable d'un type donné. Ils permettent de définir des **structures dynamiques**, autrement dit des structures qui évoluent au cours du temps. 

![[pointeurdefinition.svg]]

**Expliquons ce schéma**  
On considère un pointeur `p` de type `t` et une variable `x` de valeur `v`. En fait la variable `x` est une adresse mémoire `0x1000` qui contient la valeur `v`.  
En fait le pointeur `p` lui il va **stocker l'adresse mémoire** de la variable `x` au lieu de stocker directement la valeur de la variable. Le pointeur sera de type `t*` et la variable `x` de type `t`.

## La notion d'adresse
Comme expliqué précédemment, un pointeur permet de stocker l'adresse d'une variable. Il est donc nécessaire de comprendre la notion de variable pour pouvoir continuer.  
Lors de l'exécution d'un programme, ce dernier est stocké en mémoire, et, chaque variable que l'on a défini possède sa propre zone de mémoire qui dépend du type de celle ci.  
En réalité, la mémoire est composée de pleins de cases que l'on appelle **==octets**== *(= 8 bits)*. Une variable peut donc occuper une seule ou plusieurs cases selon son type, sa taille.

<u>Exemple :</u>  
- Une variable de type `char` occupera une seule case.
- Une variable `long` occupera quant à elle 4 cases consécutives.

Chaque case est identifiée par un numéro, c'est **==l'adresse==**. On sait maintenant que l'on peut accéder à une variable de deux manières :
- Grâce à son nom
- Grâce à l'adresse du premier emplacement mémoire alloué à la variable

Ce qui est pratique c'est que vous n'aurez jamais besoin de connaître l'adresse mémoire d'une variable donc jamais à devoir l'écrire d'autant plus que celle ci est **différente lors de chaque exécution** de votre programme. Soit `var` une variable d'un certain type. Alors pour accéder à l'adresse mémoire de celle ci, il suffit de la préfixer d'un *et commercial* `&` :
```c
&var
```

## Retour sur les pointeurs
Bon si je résume, un pointeur permet de stocker l'adresse mémoire d'une variable. Maintenant c'est vrai, on peut se demander si ça a un intérêt parce que là.

- En fait un pointeur permet de manipuler des données pouvant être importante de manière simple. Par exemple au lieu de passer un élément d'une grande taille en paramètre de fonction, on peut simplement donner le pointeur vers cet élément.  
- Vous vous rappelez, on a évoqué la notion de tableau pendant le **cours 6**, en disant qu'ils permettent de stocker un nombre fixe d'éléments du même type. Et bien si on stocke des pointeurs dans les emplacements d'un tableau, on pourra stocker des éléments de différentes tailles, ou même ajouter des éléments au tableau pendant son utilisation.  
  C'est ce qu'on appelle un **==tableau dynamique==** *notion qui sera évoquée dans un autre cours*.
- Enfin, un pointeur permet de créer des **==structures chaînées==** *notion qui sera aussi évoquée plus tard*

## Déclaration et initialisation
Pour définir un pointeur il faut préciser le type de la variable que ce dernier va pointer.  
Ainsi si on considère un pointeur `pointeur` qui pointe une variable de type `type` alors on déclarera le pointeur de la manière suivante :
```c
type *pointeur;
```
Le `type` peut être un type primaire *entier, caractère* qu'un type complexe.

>[!info] Remarque
>Un pointeur peut ne pas être typé.  
>Dans ce cas là on utilise `void *pointeur`. Ce genre d'écriture sert de **pointeur de transition** avant un transtypage qui permettra de définir le type de donnée pointée.  
>*Notion de transtypage requise, sera abordée plus tard*

Le caractère `*` permet de dire au compilateur qu'il s'agit d'un pointeur et non d'une variable ordinaire. Et, en principe comme vous donnez le type de la variable pointée, le compilateur saura aussi par la même occasion le nombre de bloc qui suivent l'adresse pointée *(= l'espace mémoire utilisée par la variable)*.

Maintenant il faut l'initialiser,  
si vous n'initialisez pas votre pointeur il risque de pointer vers n'importe quoi. 
```c
pointeur = &variable;
```

<u>Exemple :</u>
```c
int a = 2;
int *p = &a;
```
Ici le pointeur `p` pointe vers la variable `a`.

## Modification et accès à la variable pointée
L'accès et la modification par le biais d'un pointeur s'avère plus complexe que pour des variables simples. On considère un pointeur `ptr` qui pointe une variable `var` qui elle même permet de stocker l'entier $2$ *(Cf. code au dessus)*.  
En fait, ce que l'on cherche à faire c'est à pouvoir accéder à la valeur stocker dans la variable `a` à partir du pointeur `ptr`.  Et bien c'est pas si compliqué on utilise l'adresse mémoire d'où se trouve la variable.  
Ainsi, on procèdera comme ceci :
```c
#include <stdio.h>

int main(){
	int var = 2;
	int *ptr = &var;
	
	// Récupérer la valeur grâce au pointeur
	int content = *ptr;
	
	// Affichage de la valeur
	printf("La valeur de la variable pointée par ptr est : %d\n", content);
	
	return 0;
}
```
```
La valeur de la variable pointée par ptr est : 2
```

En fait, en considérant une variable `var` qui contient une valeur et un pointeur `ptr` qui pointe vers la variable `var`. Alors pour accéder au contenu de la variable `var` on utilise la forme suivant : 
```c
type contenuVar = *ptr;
```
Alors pourquoi comme ça :
- `var` contient un élément d'un certain type
- `ptr` contient l'adresse mémoire de la variable `var`
- Ainsi, `*ptr` donne accès au contenu de la zone mémoire pointée, donc ici `var`.

Super maintenant tu sais comment accéder au contenu d'une adresse mémoire via un pointeur. La prochaine étape c'est de savoir la modifier et pas de panique c'est pas très dur.  
Si on utilise `*ptr` pour accéder au contenu de l'emplacement mémoire pointé par `ptr` alors on utilise `*ptr` pour modifier le contenu de la case mémoire :
```
*ptr = nouvelleValeur;
```

En reprenant l'exemple précédant, on souhaite stocker $42$ à la place de $2$ :
```c
int main(){
	int var = 2;
	int *ptr = &var;
	
	// Modification du contenu de var via un pointeur
	*ptr = 42;
	
	// Affichage de la valeur
	printf("La valeur de la variable pointée par ptr est : %d\n", *ptr);
	
	return 0;
}
```
```
La valeur de la variable pointée par ptr est : 42
```

C'est super cool maintenant voilà ce que tu sais faire avec un pointeur : 
- Déclarer et initialiser ton pointeur
- Accéder au contenu de l'adresse mémoire grâce à son pointeur
- Modifier le contenu de l'adresse mémoire grâce au pointeur

Et si on faisait un test,  
que se passe t-il si on décide de stocker la valeur du pointeur avant de la modifier, de modifier le pointeur et d'afficher les deux valeurs ? Deux issues s'offrent à nous :
- `content` aura le même contenu que l'adresse mémoire modifiée avec le pointeur
- `content` n'aura pas le même contenu

```c
#include <stdio.h>

int main(){
	int var = 2;
	int *ptr = &var;
	
	// On récupère la valeur de l'adresse mémoire pointée par ptr avant modif
	int content = *ptr;
	
	// Modification du contenu de var via un pointeur
	*ptr = 42;
	
	// Affichage des valeurs
	printf("La valeur de la variable pointée par ptr est : %d\n", *ptr);
	printf("La valeur de content est : %d", content);
	
	return 0;
}
```
```
La valeur de la variable pointée par ptr est : 42
La valeur de content est : 2
```
Les deux résultats sont différents, mais pourquoi ?  
La justification est à comprendre. 
- Initialement, on a une variable `var` qui contient $2$ et un pointeur `ptr` qui contient l'adresse de `var`. Ainsi `*ptr` contient de contenu de l'adresse mémoire de `var` qui ici est $2$.
- À la ligne suivante, 
  ```c
  int content = *ptr;
	```
	Ce qu'il se passe ici c'est que on créé une variable `content` qui récupère comme son nom l'indique, la valeur pointée par `*ptr`.
- À ce moment là on a : 
  ```c
  *ptr = 2;
  content = 2;
    ```
- Ensuite, on décide de modifier la variable `var` via son pointeur en lui affectant une nouvelle valeur, ici $42$.
  ```c
  *ptr = 42;
    ```
    Ce qu'il se passe c'est que `*ptr`, *donc l'adresse (le contenu)* de la variable `var` change et devient $42$. Pour ce qui est de la variable `content` elle n'a aucun lien avec l'adresse mémoire de `var` *(elle possède la sienne)* ainsi, la modification du pointeur de `var` n'a d'incidence que sur lui même et non sur `content` d'où le résultat différent lors de l'affichage final.

$\boxed{\text{Solution au problème}}$  
En fait si on souhaite que `content = ptr`, il faut que `content` soit un pointeur du même type que `ptr` et qu'il pointe vers la même chose que lui c'est à dire la variable `var`.
```c
int *content = ptr;
```
Après cette ligne, `content` reçoit une copie de `ptr`, l'adresse mémoire de la variable `var`.
```c
#include <stdio.h>

int main(){
	int var = 2;
	int *ptr = &var;
	
	// Faire en sorte que content pointe vers la même chose que ptr
	int *content = ptr;
	
	// Modification du contenu de var via un pointeur
	*ptr = 42;
	
	// Affichage des valeurs
	printf("La valeur de la variable pointée par ptr est : %d\n", *ptr);
	printf("La valeur de content est : %d", *content);
	
	return 0;
}
```
```
La valeur de la variable pointée par ptr est : 42
La valeur de content est : 42
```

# Les pointeurs et les tableaux 
## Analogie entre eux
En langage C, la manière dont les pointeurs et les tableaux accèdent à la mémoire est similaire. Le cours [[06 - Les tableaux statiques]], qui permettait d'introduire les notions principales à la création et à l'utilisation de tableaux cachait d'autres aspects.  
On considère la déclaration suivante : 
```c
int tab[3] = { 1, 2, 3 };
```
Ici, on vient donc de créer un tableau de trois entiers.  
Pendant la compilation, le tableau va être vu comme **l'adresse de son premier élément** que l'on note alors `&tab[0]`. Ainsi, un tableau est en fait un pointeur vers sont premier élément.  
Les deux instructions suivantes sont donc équivalentes : 
```c
int *ptr = tab;
int *ptr = &tab[0];
```
Ainsi, cela fait de `ptr` un pointeur qui pointe vers le premier élément du tableau `tab`, ce que le tableau fais lui même sans avoir besoin de pointeurs. 

On peut le vérifier avec un exemple simple.  
<u>Exemple :</u>  
```c
#include <stdio.h>

int main(){
	int tab[] = { 1, 2, 3 };
	int *ptr = tab;
	
	printf("Premier élément du tableau : %d\n", tab[0]);
	printf("Valeur de l'élément pointé par ptr : %d", *ptr);
	
	return 0;
}
```
```
Premier élément du tableau : 1
Valeur de l'élément pointé par ptr : 1
```

## Accès aux éléments du tableau
Je ne sais pas si tu te rappelles mais pour accéder aux éléments d'un tableau on utilisait l'instruction suivante : 
```c
// Accès à l'élément i
int elementI = tab[i];
```
Ici, cela restait relativement simple d'accéder aux éléments d'un tableau. 

Ce que nous voulons c'est accéder à l'élément d'indice `i` dans un tableau en utilisant un pointeur. C'est là qu'intervient l'**arithmétique des pointeurs**. Si initialement le pointeur est sur le premier élément du tableau, alors pour accéder à l'élément `i` il faudra incrémenter ce pointeur jusqu'à cet élément. 

>[!warning]
>En prenant en compte que les **indices commencent à $0$**. 

Soit `ptr` un pointeur sur le premier élément d'un tableau. Alors si on souhaite accéder à l'élément `i` du tableau *(en considérant que le premier élément est d'indice $0$*. Alors on utilisera l'instruction suivante : 
```c
// Accès à l'élément i du tableau via le pointeur ptr
*(ptr + i)
```
Ainsi, les instructions suivantes sont équivalentes : 
```c
tab[i]; 
*(ptr + i);
```

Une question peut venir te hanter *(ou pas)*. Pourquoi faut-il augmenter le pointeur de $1$ pour accéder à l'élément suivant ?  
Reprenons simplement l'un des schéma utilisé lors du cours 6 :  
On avait considéré une chaîne de caractère `informatique` que l'on a dont stocké dans un tableau de 13 éléments pour inclure le marqueur de fin de chaîne `\0`.
![[informatiqueMOT.svg]]
Ainsi, à la création de ce tableau que l'on nommera `tab`, ce dernier pointera sur le premier élément qui ici est la lettre `i`. Les "codes" présents en dessous de chaque case représente l'adresse mémoire *(choisie de manière arbitraire)* et on voit qu'entre deux cases, cette dernière augmente de $1$.  
Oui, on passe de $9$ à $A$ car les adresses mémoires sont en base hexadécimal donc `16` :

| 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   |


| 8   | 9   | 10  | 11  | 12  | 13  | 14  | 15  |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 8   | 9   | A   | B   | C   | D   | E   | F   |


*La base 16 est donnée à la deuxième ligne du tableau, la base du dessus est la base décimal, celle avec laquelle nous comptons par exemple.*

Enfin, si on donne un pointeur `ptr` qui pointe sur le premier élément du tableau, son contenu sera alors donné par `0x1000`, qui est l'adresse mémoire du premier élément du tableau. Ainsi si on augmente le pointeur de $1$ alors `ptr` va valoir `0x1001` soit l'adresse mémoire du second élément du tableau, et ainsi de suite.  
C'est donc pour cela qu'incrémenter le pointeur permet de parcourir le tableau.

Il faut prendre en compte qu'à chaque incrémentation du pointeur, ses déplacements dans la mémoire dépendent de la taille des éléments pointés :
- Si `ptr` est un `char*` alors il avancera de $1$ octet en $1$ octet
- Si `ptr` est un `int*` alors il avancera de $4$ octets en $4$ octets
- Si `ptr` est un `double*` alors il avancera de $8$ octets en $8$ octets

## Parcours d'un tableau
Maintenant que vous avez compris comment récupérer l'élément d'indice `i` d'un tableau, il devient alors plus clair de faire de même pour tous les éléments du tableau en passant par une boucle : 
```c
#include <stdio.h>
 
int main(){
	char *mot = "informatique";
	// Parcours en utilisant l'arithmétique des pointeurs
	for(int i = 0; i<12; i++){
	    printf("Élément d'indice %d : %c \n", i, *(mot+i));
	}
	return 0;
}
```
```
Élément d'indice 0 : i 
Élément d'indice 1 : n 
Élément d'indice 2 : f 
Élément d'indice 3 : o 
Élément d'indice 4 : r 
Élément d'indice 5 : m 
Élément d'indice 6 : a 
Élément d'indice 7 : t 
Élément d'indice 8 : i 
Élément d'indice 9 : q 
Élément d'indice 10 : u 
Élément d'indice 11 : e 
```

## Calculer la taille du tableau
Il est vrai qu'on a déjà vu cet aspect pendant le cours $6$ notamment ici : [[06 - Les tableaux statiques#Déterminer la taille du tableau]] mais c'est exactement pour cette raison que je souhaite préciser les choses avant même que vous fassiez l'erreur !

### Chaîne de caractères

On considère le code suivant :
```c
#include <stdio.h>
 
int main(){
	char tab[] = "informatique";
	char *ptr = tab;
	
	// Calcul de la taille du tableau de différentes manières
	printf("Taille du tableau simple : %d\n", sizeof(tab));
	printf("Taille du tableau à partir du pointeur : %d\n", sizeof(ptr));
	
}
```
```
Taille du tableau simple : 13
Taille du tableau à partir du pointeur : 8
```

Le programme visait à calculer la taille du tableau nommé `tab` dans notre exemple.  
Or l'utilisation de `sizeof` sur le tableau lui même renvoie bien 13 qui est la taille du tableau `tab` en incluant le marqueur de fin de chaîne. Par contre l'utilisation de cette même fonction sur un pointeur renvoi `8` *(ou parfois 4 selon le système)*. Et bien en fait la taille qui est renvoyée par `sizeof` appliquée à un pointeur c'est la taille de l'**adresse mémoire**. c'est donc pour cette raison que `sizeof` renvoi des valeurs différentes lors de deux exécutions.

### Tableau d'entiers
Alors, vous vous doutez bien que si j'ai divisé cette partie en 2 c'est qu'il y a une raison. 

Considérons maintenant le code suivant : 
```c
#include <stdio.h>
 
int main(){
	int tab[] = {1, 2, 3, 4, 5};
	int *ptr = tab;
	
	// Calcul de la taille du tableau de différentes manières
	printf("Taille du tableau simple : %d\n", sizeof(tab));
	printf("Taille du tableau avec le pointeur : %d\n", sizeof(ptr));
	
	return 0;
}
```
```
Taille du tableau simple : 20
Taille du tableau avec le pointeur : 8
```
Là, rien ne vas, la taille du tableau donnée est $20$ alors qu'il ne possède que $5$ éléments et, la taille calculée en utilisant le pointeur est elle aussi erronée.  
Pour ce qui est de l'utilisation du pointeur avec `sizeof` qui donne $8$, c'est la même explication qu'au dessus. 
```c
sizeof(pointeur);
```
Donne la taille de l'adresse mémoire, soit $4$, soit $8$ selon les systèmes.

Maintenant étudions le `sizeof(tab)` qui donne $20$.  
Ce que l'on sait déjà sur les entiers depuis le cours [[02 - Premiers pas#Le type entier]] c'est qu'un entier de type `int` est codé sur $4$ octets. Alors : 
```c
sizeof(int) == 4
```
En gros, ce que je veux dire c'est que la taille d'un entier est $4$.  
On a rappelé au dessus que `tab` représente en fait une sorte de pointeur vers son premier élément qui est de type entier. Sauf que cette fois l'instruction suivante : 
```c
sizeof(tab)
```
Vas parcourir le tableau et donc arriver sur chaque élément un à un. Or elle ne vas pas ajouter au résultat $+1$ à chaque élément dans le tableau non, elle va rajouter **la taille de l'élément** qui ici sont des entiers. Donc pour chaque élément que `sizeof` rencontre on ajoute $4$ à la taille du tableau.  
Puisque `sizeof` rencontre $5$ éléments du tableau jusqu'à la fin de ce dernier, elle ajoute $5 \times 4$ octets pour les $5$ entiers qui chacun sont codés sur chaque entiers on obtient alors `sizeof(tab)=20`.

$\boxed{\text{Solution au problème}}$  
Pour résoudre ce problème, ce n'est pas si compliqué, il suffit de diviser la taille globale du tableau par la taille du premier élément de ce dernier. Puisqu'en C un tableau ne peux contenir qu'un seul type d'éléments à la fois. L'utilisation correcte est donnée par : 
```c
int tailleTab = sizeof(tab)/sizeof(tab[0]);
```
Voici l'exemple corrigé : 
```c
#include <stdio.h>
 
int main(){
	int tab[] = {1, 2, 3, 4, 5}
	printf("Taille du tableau simple : %d\n", sizeof(tab)/sizeof(tab[0]));
	
	return 0;
}
```
```
Taille du tableau simple : 5
```

# Pointeurs et chaîne de caractères
## Quelques rappels 
Les chaînes de caractères ont été introduites pendant le cours [[07 - Chaînes de caractères]] avec un certain nombre d'informations, de fonctions, et d'explication sur les bonnes pratiques et les erreurs possibles. On pense à ce <span class="error-inline">buffer overflow</span> et des dangers qu'il représente.  
Pour rappel la déclaration d'une chaîne de caractères sans utiliser de pointeur se fait comme suit : 
```c
char chaine[] = "blabla";
// équivaut à : char chaine[] = { 'b', 'l', 'a', 'b', 'l', 'a', '\0'};
```
On créé alors un tableau de 7 caractères incluant le **marqueur de fin de chaîne `\0`**.

## Chaîne littérale
C'est un concept à **absolument maîtriser** pour éviter les mauvaises surprises. 

>[!cite] Définition
>On appelle **==littérale==** une chaîne de caractères stockée en mémoire en **lecture seule** *(segment const)*.

On considère le pointeur `ptr` qui est initialisé en pointant vers le littérale `"informatique"`.
```c
char *ptr = "informatique";
```
Ainsi,  
- Le pointeur `ptr` est modifiable, on peut faire en sorte de le faire pointer vers autre chose.
- La chaîne `informatique` est quant a elle immuable, car c'est un littérale elle est donc en **lecture seule**.

Vous êtes quand même d'accord avec moi, vous voulez voir ce qu'il se passe si on essaye de modifier la chaîne de caractères via le pointeur.

On peut évidement parcourir la chaîne via l'arithmétique des pointeurs et afficher chaque lettre comme le montre le code suivant : 
```c
#include <stdio.h>
 
int main(){
	char *domaine = "informatique";
	for(int i = 0; i<12; i++)
	    printf("%c ", *(domaine+i));
    return 0;
}
```
```
i n f o r m a t i q u e
```

<u>Exemple :</u>  
- Modification d'un caractère
```c
#include <stdio.h>
 
int main(){
	char *domaine = "informatique";
	// Modification du 7e caractère
	*(domaine+7)='R';
    
    return 0;
	
}
```
```bash
Segmentation fault
```

En fait, pour pouvoir modifier une chaîne de caractère en utilisant un pointeur, il faut déclarer et initialiser une chaîne de caractères et seulement après faire en sorte que le pointeur vise le premier élément de la chaîne : 
```c
char chaine[] = "informatique";
char *domaine = chaine; // Équivaut à : char *domaine = &chaine[0];
```

Ainsi en affichant avant et après modification de la chaîne avec un pointeur : 
```c
#include <stdio.h>
 
int main(){
    char chaine[] = "informatique";
	char *domaine = chaine;
	
	printf("Avant modification : \n | ");
	for(int i = 0; i<12; i++)
	    printf("%c ", *(domaine+i));
	    
	*(domaine+7)='R';
	
	printf("\nAprès modification : \n | ");
	for(int i = 0; i<12; i++)
	    printf("%c ", *(domaine+i));
    
    return 0;
}
```
```
Avant modification : 
 | i n f o r m a t i q u e 
Après modification : 
 | i n f o r m a R i q u e 
```

<u>Autre exemple :</u>  
On modifie avec des caractères aléatoires entre $32$ et $64$ la chaîne informatique. On fera en sorte qu'il y ai $50\%$ de chance d'avoir une minuscule ou une majuscule.  
- Quelques rappels sur l'aléatoire : [[06 - Les tableaux statiques#L'aléatoire en programmation C aleatoire]]
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char random_letter() {
    if(rand() % 2) // 50% majuscule ou minuscule
        return 'A' + rand() % 26; // lettre majuscule
    else
        return 'a' + rand() % 26; // lettre minuscule
}

int main() {
    srand(time(NULL)); // Pour avoir des valeurs différentes à chaque fois
    char chaine[] = "informatique";
    char *domaine = chaine;

    printf("Avant modification : \n| ");
    for(int i = 0; i < 12; i++)
        printf("%c ", *(domaine + i));

    // Boucle pour la modification random
    char *ptr = domaine; // on utilise un pointeur séparé pour ne pas perdre le début
    while(*ptr != '\0') {
        *ptr = random_letter();
        ptr++;
    }

    printf("\nAprès modification : \n| ");
    for(int i = 0; i < 12; i++)
        printf("%c ", *(domaine + i));

    return 0;
}
```
```
Avant modification : 
| i n f o r m a t i q u e 
Après modification : 
| R x k P z f E N y r u P 
```

## Manipulation de chaînes
Cette section vise à renforcer ce que vous savez déjà, c'est à dire manipuler des chaînes de caractères, vues au cours précédant. Hors cette fois on rajoute la notion de pointeur.  
Voici l'objectif de l'exercice : $\boxed{\text{La fonction de concaténation}}$. Et oui, il va falloir créer une fonction prenant en paramètre deux chaînes de caractères et renvoie leur concaténation.  
C'est à dire une chaîne contenant la première chaîne à laquelle on a ajouté la seconde à la fin. Et, petite subtilité, il faut que les chaines de caractères soient données lors de l'exécution par l'utilisateur ET, le séparateur entre les deux chaînes sera `#`.  
On pourra demandé à l'utilisateur d'entrer deux chaînes séparées par le séparateur `#`.

>Essayez de faire l'exercice seul dans votre coin avant de regarder une correction possible ci dessous...

