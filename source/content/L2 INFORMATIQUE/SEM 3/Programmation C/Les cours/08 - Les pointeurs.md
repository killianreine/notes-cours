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

# Déclaration et initialisation
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
