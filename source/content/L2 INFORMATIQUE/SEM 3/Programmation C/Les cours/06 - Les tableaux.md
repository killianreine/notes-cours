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