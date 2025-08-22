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
	printf("La valeur de content est : %d" content);
	
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