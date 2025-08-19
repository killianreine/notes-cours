# Généralités sur les pointeurs
>[!cite] Définition
>Un **==pointeur==** est une variable qui contient l'adresse mémoire d'une autre variable d'un type donné.

![[pointeurdefinition.svg]]

**Expliquons ce schéma**  
On considère un pointeur `p` de type `t` et une variable `x` de valeur `v`. En fait la variable `x` est une adresse mémoire `0x1000` qui contient la valeur `v`. En fait le pointeur `p` lui il va **stocker l'adresse mémoire** de la variable `x` au lieu de stocker la valeur stockée dans la variable. Le pointeur sera de type `t*` et la variable `x` de type `t`.