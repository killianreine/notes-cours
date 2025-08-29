# Introduction
Les objets déjà évoqués dans les cours précédents *(tableau, fonction, variable)* ont tous un point commun, il correspondent tous à une inscription localisée dans la mémoire vive *(ou RAM)*, on appelle ça l'**==adresse==**. L'adresse représente un nombre et il correspond en fait à un emplacement de la mémoire. 
# Généralités sur les pointeurs
## Définition
>[!cite] Définition
>Un **==pointeur==** est une variable qui contient l'adresse mémoire d'une autre variable d'un type donné. Ils permettent de définir des **structures dynamiques**, autrement dit des structures qui évoluent au cours du temps. 

<div>
<svg xmlns="http://www.w3.org/2000/svg" width="510" height="140" viewBox="0 0 480 140">
  <defs>
    <!-- Flèche -->
    <marker id="arrowhead" markerWidth="9" markerHeight="6" refX="8" refY="3" orient="auto">
      <polygon points="0 0, 9 3, 0 6" class="arrow-fill"/>
    </marker>
  </defs>
  <!-- Mémoire : pointeur p -->
  <g id="ptr-p" transform="translate(20,20)">
    <rect x="0" y="0" width="160" height="80" class="cell"/>
    <text x="80" y="22" text-anchor="middle" class="label">pointeur (p)</text>
    <line x1="10" y1="36" x2="150" y2="36" class="brace"/>
    <text x="15" y="55" class="index">type: t*</text>
    <text x="15" y="70" class="index">contient: 0x1000</text>
  </g>
  <!-- Mémoire : variable x -->
  <g id="var-x" transform="translate(300,20)">
    <rect x="0" y="0" width="150" height="80" class="cell"/>
    <text x="75" y="22" text-anchor="middle" class="label">variable (x)</text>
    <line x1="10" y1="36" x2="140" y2="36" class="brace"/>
    <text x="15" y="55" class="index">valeur: v</text>
    <text x="15" y="70" class="index">adresse: 0x1000</text>
  </g>
  <!-- Flèche du pointeur vers la variable -->
  <path d="M 180 55 C 220 55, 260 55, 300 55" class="arrow" marker-end="url(#arrowhead)"/>
  <!-- Accolades explicatives -->
  <path class="brace" d="M 10 110 C 10 120, 10 120, 20 120 L 170 120 C 190 120, 190 120, 190 110" />
  <text x="100" y="133" text-anchor="middle" class="index brace-text">p stocke une adresse (0x1000)</text>
  <path class="brace" d="M 290 110 C 290 120, 290 120, 310 120 L 440 120 C 460 120, 460 120, 460 110" />
  <text x="375" y="133" text-anchor="middle" class="index brace-text">x est la case mémoire ciblée</text>
</svg>
</div>

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

# Pointeurs et fonctions
## Passage de paramètres à une fonction
En langage C, les fonctions reçoivent par défaut les copies des variables. En fait ce que ça veut dire c'est que si vous avez une variable définie hors de la fonction et que vous la passez en paramètres d'une fonction, et que vous la modifiez dans celle ci. Et bien à la fin de la fonction, cette même variable aura la même valeur avant/après la fonction car cette dernière ne sera pas modifié.  
Car **par défaut les fonctions reçoivent les copies des variables passées en arguments**.  
$\boxed{\text{Solution}}$ Si vous voulez envoyez une variable en argument d'une fonction, la modifier pendant l'exécution de la fonction puis la reprendre ensuite modifier, il va donc falloir opter par **==le passage d'adresse==** via les pointeurs.
### Passage par valeur
Le passage de paramètres par valeur, vous le connaissez déjà c'est celui qu'on utilise depuis le cours [[05 - Retour sur les fonctions]]. 

<u>Exemple :</u>  
```c
void fct(int a, int b){
	a = b+2;
}
```
Ici, les paramètres `a` et `b` à renseigner dans la fonction `fct` sont passées par valeur. Et, comme expliqué au dessus, par défaut lors de passage de paramètre par valeur en C, en fait la fonction reçoit une copie des deux variables.  
Voyons ce qu'il se passe pour l'état de la variable `a` modifiée pendant la fonction : 
```c
#include <stdio.h>

void fct(int a, int b){
	a = b+2;
}

int main(){
	int a = 14, b = 5;
	printf("a avant la fonction : %d\n", a);
	fct(a,b);
	printf("a après la fonction : %d\n", a);
	return 0;
}
```
```
a avant la fonction : 14
a après la fonction : 14
```
Et voilà, c'était quand même prévisible. Puisque dans une fonction le passage de paramètres par valeur donne en fait une copie des variables données à la fonction, et bien les variables `a` et `b` vont être des copies que l'on appellera grossièrement `cA` et `cB` pour plus de simplicité.  
Ainsi dans la fonction pendant les manipulations des variables renseignées en paramètres, ce sont les copies `cA` et `cB` qui seront modifiées. Et comme `a != cA` alors la variable `a` n'est pas modifiée. Et, si on affiche l'état de la variable `a` dans la fonction elle sera modifiée **mais uniquement dans la fonction**.
```c
void fct(int a, int b){
	a = b+2;
	printf("Valeur de a : %d\n", a);
}
```
```
Valeur de a : 7
```
### Passage par adresse
Nous, on souhaite pouvoir avoir une variable d'un certain nom valide, ici `var` ayant un état avant la fonction. Que pendant l'exécution de cette dernière l'état de la variable soit changée. Et pouvoir récupérer l'état de cette variable à la fin de la fonction sans le perdre comme avec le *passage par valeur*.  
Prenons en compte le code suivant : 
```c
void echangerValeur(int a, int b){
	int tempo = a;
	a = b;
	b = tempo;
}
```
Si on exécute cette fonction directement, les variables `a` et `b` seront échangée **dans la vision de la fonction** mais sortie de cette dernière, `a` et `b` auront leur valeur initiale. En fait, la fonction a **manipuler des copies** de ces variables.  
En langage C, **le ==passage par adresse==** consiste à transmettre à une fonction **l’adresse (= le pointeur)** d’une variable au lieu de sa valeur. Cela permet à la fonction de **modifier directement la variable d’origine**, contrairement au passage par valeur *qui ne modifie qu’une copie locale*.  
Ainsi, la fonction précédente en utilisant la passage d'adresses devient :
```c
void echangerAdresse(int *a, int *b){
	int tempo = *a;
	*a = *b;
	*b = tempo;
}
```

Testons maintenant ces deux fonctions pour voir ce qu'il se passe.
```c
#include <stdio.h>

void echangerValeur(int a, int b){
	int tempo = a;
	a = b;
	b = tempo;
}

void echangerAdresse(int *a, int *b){
	int tempo = *a;
	*a = *b;
	*b = tempo;
}

int main(){
	int a = 14, b = 5;
	
	int *a_ = &a;
	int *b_ = &b;
	
	printf("FONCTION PASSAGE PAR VALEUR\n");
	printf("| AVANT : a = %d ; b = %d \n", a, b);
	echangerValeur(a, b);
	printf("| APRES : a = %d ; b = %d\n\n", a, b);
	
	printf("FONCTION PASSAGE PAR ADRESSE\n");
	printf("| AVANT : a = %d ; b = %d\n", a, b);
	echangerAdresse(a_, b_);
	printf("| APRES : a = %d ; b = %d", a, b);
}
```
```
FONCTION PASSAGE PAR VALEUR
| AVANT : a = 14 ; b = 5 
| APRES : a = 14 ; b = 5

FONCTION PASSAGE PAR ADRESSE
| AVANT : a = 14 ; b = 5
| APRES : a = 5 ; b = 14
```

Bon c'est bien gentil, on a vu un exemple d'utilisation. Maintenant il nous faut quelques explications pour savoir le refaire.  
Pour ce faire, on code une fonction `function` qui prend en paramètre deux pointeurs `*ptr1` et `*ptr2` d'un type `type`. La fonction renvoie une valeur du type `type_re`.  
Ainsi, le prototype général d'une telle fonction sera donné par : 
```c
type_r function(type *ptr1, type *ptr2);
```
Ceci reste le plus basique,  
On considère maintenant que cette fonction a été codée et qu'elle ait une utilité. Voyons maintenant comment on l'appelle. Et, il existe deux manières principales de le faire :  

$\boxed{\text{Méthode 1}}$  
```c
type_r function(type *ptr1, type *ptr2){
	// Bloc de code de la fonction
	return ...;
}

int main(){
	type var1 = ...;
	type var2 = ...;
	
	// Appel de la fonction 
	function(&var1, &var2);
}
```
Ici, on passe directement les adresses des variables sans passer par des pointeurs.

$\boxed{\text{Méthode 2}}$  
```c
type_r function(type *ptr1, type *ptr2){
	// Bloc de code de la fonction
	return ...;
}

int main(){
	type var1 = ...;
	type var2 = ...;
	
	type *ptr1 = &var1;
	type *ptr2 = &var2;
	
	// Appel de la fonction 
	function(ptr1, ptr2);
}
```
Alors ici, on passe par l'utilisation de pointeur. On peut se demander pourquoi lors de l'appel à la fonction on ne met pas les `*` aux pointeurs.  
En fait si on met `*`, ça signifie que l'on veut déréférencer *(= accéder à la valeur)* la variable. Alors que lorsqu'on enlève `*` on passe directement l'adresse mémoire de la variable pointée. 

```c
#include <stdio.h>

int main(){
	int a = 14;
	int *ptr = &a;

    printf("%p\n", ptr);
    printf("%d", *ptr);
    
	return 0;
}
```
```
0x7fff0d282a64
14
```

>[!tip]
>Soit `ptr` un pointeur vers une variable d'un certain type.
>- `ptr` permet d'avoir accès à l'adresse mémoire de la variable pointée.
>- `*ptr` permet d'avoir le contenu de la variable pointée.
## Retourner une adresse
En C, on peut **retourner une adresse** depuis une fonction, mais il faut être **très prudent** : certaines adresses ne sont pas valides une fois la fonction terminée.  
Concentrons nous sur des applications simples pour commencer. 

On souhaite coder une fonction `somme` qui prend deux paramètres entiers `a` et `b` et qui retourne une adresse contenant le résultat de la somme de `a` et `b`.

Le code sans utiliser de pointeurs, vous le connaissez : 
```c
int somme(int a, int b){
	return a+b;
}
```

Pour le faire avec des pointeurs il existe plusieurs solutions, dans cette partie de cours nous n'en verrons qu'une seule, l'autre sera vue lors du cours sur les **==allocations dynamique==**.  
Nous ce que l'on veut faire c'est don que notre fonction `somme` renvoie une adresse vers le résultat de la somme.

Faisons le de manière naïve,
```c
int* somme(int a, int b){
	return &(a+b);
}
```
**On utilisera le `main` suivant pour les tests, et la correction**
```c
int main(){
	int a = 14, b = 4;
	int *ptr = somme(a, b);
	printf("Résultat : %d\n", *ptr);
	return 0;
}
```

Voici ce qu'il se passe lorsque l'on décide d'exécuter le programme :
```bash
ERROR!
/tmp/WfNsb31sJ9/main.c: In function 'somme':
/tmp/WfNsb31sJ9/main.c:4:12: error: lvalue required as unary '&' operand
    3 |     return &(a+b);
      |            ^
```
Olala mais qu'est-ce que ça veut dire tout ça là.  
Bon okay ça mérite quand même des explications.

En fait, ici on obtient le message d'erreur exact du compilateur. L'opérateur `&` attend ce que le compilateur appelle une `lvalue` *location value* c'est à dire quelque chose qui a une adresse mémoire fixe, comme une variable déclarée. Or dans notre cas, `a+b` est une variable temporaire permettant d'avoir le résultat de la somme calculée à ce moment là, c'est ce qu'on appelle une `rvalue`.  
Ainsi `&(a+b)` est **illégal** et renvoie directement une erreur lors de la compilation.

Nous ce que l'on cherche c'est à retourner une adresse mémoire qui persiste même après l'exécution de la fonction. En gros qu'on puisse accéder au résultat de la fonction via pointeur.  
On peut utiliser une variable dite `static`, ce mot clé permet de créer une **==variable persistante==** c'est à dire qu'après l'exécution de la fonction l'adresse mémoire qui lui a été dédiée reste valide pour tout le reste du code.

>[!warning]
>Pour déclarer et initialiser une variable persistante il faut le faire en deux temps : 
>- Déclaration
>- Initialisation

On va donc créer une variable entière `int` appelée `resultat` pour stocker le résultat de la somme `a+b`
```c
static int resultat;   // Déclaration seule
resultat = a + b;      // Initialisation ensuite
```

Ainsi, on peut donc renvoyer le résultat qui pendant et après la fonction gardera son adresse.
```c
int *somme(int a, int b){
	static int resultat;
	restultat = a + b;
	
	// On retour l'adresse du résultat
	return &resultat;
}
```
```
Résultat : 18
```
## Manipulation de chaînes
Cette section vise à renforcer ce que vous savez déjà, c'est à dire manipuler des chaînes de caractères, vues au cours précédant. Hors cette fois on rajoute la notion de pointeur.  
Voici l'objectif de l'exercice : $\boxed{\text{La fonction de concaténation}}$. Et oui, il va falloir créer une fonction prenant en paramètre deux chaînes de caractères et renvoie leur concaténation.  
C'est à dire une chaîne contenant la première chaîne à laquelle on a ajouté la seconde à la fin. Et, petite subtilité, il faut que les chaines de caractères soient données lors de l'exécution par l'utilisateur ET, le séparateur entre les deux chaînes sera `#`.  
On pourra demandé à l'utilisateur d'entrer deux chaînes séparées par le séparateur `#`.

>Essayez de faire l'exercice seul dans votre coin avant de regarder une correction possible ci dessous...  
>**La correction proposée est une correction possible, elle n'est pas forcément la meilleure**

Pour faire cette exercice de manière rigoureuse nous allons découper le problème en différentes étapes. Ici il y en a deux principales : 
- La fonction `main` qui gère la saisie utilisateur + l'affichage du résultat
- La fonction `concatenation` 

$\boxed{\text{La fonction \texttt{concatenation}}}$  
Pour commencer il faut déterminer le prototype de la fonction. C'est à dire le type de renvoie, les paramètres qu'elle prend, son utilité, ...  
À vrai dire, on a déjà répondu a toutes ces questions indirectement. La fonction concaténer va donc prendre en arguments trois chaînes de caractères : 
- Les deux chaînes à concaténer 
- La chaîne pour stocker le résultat

Et, elle ne renverra rien, puisque la variable résultat sera modifié dans la fonction. Le prototype de la fonction `concatener` va donc être la suivante : 
```c
void concatenation(char *chaine1, char *chaine2, char *resultat);
```
L'objectif et de modifier résultat pour obtenir le résultat de la concaténation des deux chaînes.  Tout ça en utilisant l'**arithmétique des pointeurs**.
```c
void concatenation(char *chaine1, char *chaine2, char *resultat) {
    // Pointeur pour parcourir resultat
    char *p = resultat;

    // Copier chaine1
    while (*chaine1 != '\0') {
        *p = *chaine1;
        p++;
        chaine1++;
    }

    // Copier chaine2
    while (*chaine2 != '\0') {
        *p = *chaine2;
        p++;
        chaine2++;
    }

    // Terminer la chaîne
    *p = '\0';
}
```

Les variables `i` et `j` représentent respectivement la taille des `chaine1` et `chaine2`.  
On utilise alors une boucle `while` pour copier la seconde chaine. Une boucle `for` pouvait aussi faire l'affaire, ceci est un choix arbitraire.   
De manière algorithmique on a alors :
```
debut concatenation
	initialisation des tailles des deux chaînes
	Copie de la première chaîne
	Copie de la seconde chaîne
	Ajout du marqueur de fin de chaîne \0
fin
```

$\boxed{\text{La fonction \texttt{main}}}$  
La fonction `main`, elle va permettre de faire plusieurs choses :
- Déclarer les variables pour les chaînes et les initialiser 
- Demander à l'utilisateur d'entrer deux chaînes
- De traiter les deux chaînes
- D'appeler la fonction `concatenation`
- D'afficher le résultat
Les variables à déclarées sont les trois chaînes : `chaine1`, `chaine2`, `resultat` ainsi qu'une chaîne temporaire `saisieUser` pour stocker la saisie utilisateur brute sans l'avoir découpée.
```c
char chaine1[50], chaine2[50];
char saisieUser[100];
char resultat[100];
```

>[!info] Remarque
>On a choisit de lire des chaînes jusqu'à 50 caractères chacune mais c'est aussi un choix arbitraire. Vous pouvez mettre autre chose.

Occupons nous maintenant de la **saisie utilisateur**.  
En fait, ce que l'on doit faire c'est : 
1. Demander à l'utilisateur de rentrer deux chaînes en pensant à mettre `#` entre deux
2. Lire la saisie et la stockée de manière brute dans une variable
3. Scinder en deux la saisie avec le séparateur et stockée celle ci dans les chaînes correspondantes

Pour la première étape, il suffit d'un `printf` pour donner une consigne à l'utilisateur.
```c
printf("Entrez deux chaînes séparées par # : ");
```

Ensuite, je ne sais pas si vous vous rappelés mais dans le cours [[07 - Chaînes de caractères#Lecture]] on avait vu quelques fonctions pour la lecture d'une saisie utilisateur comme `scanf`, `gets` et `fgets` et on en avait conclu que la plus sécurisée était `fgets` qui permettait de gérer le nombre de caractères lus :
```c
#include <string.h>

fgets(saisieUser, 100, stdin);
```

Enfin, on va utiliser ce bon vieux `strtok` que l'on a vu au cours précédant, en pensant à stocker les deux parties de chaînes dans les variables correspondantes : 
```c
char *token = strtok(saisieUser, "#");
if (token != NULL) {
    strcpy(chaine1, token);
    token = strtok(NULL, "#");
    if (token != NULL) {
        strcpy(chaine2, token);
    } else {
        chaine2[0] = '\0';
    }
}
```

Maintenant il ne reste plus qu'à appeler la fonction `concatenation` et à afficher le résultat final :
```c
concatenation(chaine1, chaine2, resultat);
printf("Résultat : %s\n", resultat);
```

On obtient alors le code final avec les bibliothèques correctement importées.
```c
#include <stdio.h>
#include <string.h>

void concatenation(char *chaine1, char *chaine2, char *resultat) {
    // Pointeur pour parcourir resultat
    char *p = resultat;

    // Copier chaine1
    while (*chaine1 != '\0') {
        *p = *chaine1;
        p++;
        chaine1++;
    }

    // Copier chaine2
    while (*chaine2 != '\0') {
        *p = *chaine2;
        p++;
        chaine2++;
    }

    // Terminer la chaîne
    *p = '\0';
}

int main() {
    char saisieUser[100];
    char chaine1[50], chaine2[50];
    char resultat[100];

    printf("Entrez deux chaînes séparées par # : ");
    fgets(saisieUser, 100, stdin);

    // Découpage avec strtok
    char *token = strtok(saisieUser, "#");
    if (token != NULL) {
        strcpy(chaine1, token);
        token = strtok(NULL, "#");
        if (token != NULL) {
            strcpy(chaine2, token);
        } else {
            chaine2[0] = '\0';
        }
    }

    // Concaténation
    concatenation(chaine1, chaine2, resultat);
    printf("Résultat : %s\n", resultat);

    return 0;
}
```
```
./concat
Entrez deux chaînes séparées par # : Bonjour le monde # tout entier
Résultat : Bonjour le monde  tout entier
```

# Suivant 
- Cours suivant : [[09 - Allocation dynamique]]