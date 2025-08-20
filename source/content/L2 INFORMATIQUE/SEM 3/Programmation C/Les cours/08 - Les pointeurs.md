# Introduction
Les objets déjà évoqués dans les cours précédents *(tableau, fonction, variable)* ont tous un point commun, il correspondent tous à une inscription localisée dans la mémoire vive *(ou RAM)*, on appelle ça l'**==adresse==**. L'adresse représente un nombre et il correspond en fait à un emplacement de la mémoire. 
# Généralités sur les pointeurs
## Définition
>[!cite] Définition
>Un **==pointeur==** est une variable qui contient l'adresse mémoire d'une autre variable d'un type donné. Ils permettent de définir des **structures dynamiques**, autrement dit des structures qui évoluent au cours du temps. 

![[pointeurdefinition.svg]]

**Expliquons ce schéma**  
On considère un pointeur `p` de type `t` et une variable `x` de valeur `v`. En fait la variable `x` est une adresse mémoire `0x1000` qui contient la valeur `v`.  
En fait le pointeur `p` lui il va **stocker l'adresse mémoire** de la variable `x` au lieu de stocker la valeur stockée dans la variable. Le pointeur sera de type `t*` et la variable `x` de type `t`.

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
