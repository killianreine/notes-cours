En langage `C`, les opérateurs jouent un rôle essentiel dans l'écriture d'expressions permettant de manipuler des données. Parmi eux, les **opérateurs arithmétiques** permettent d'effectuer des calculs tels que l'addition, la soustraction, la multiplication, la division ou encore le modulo, constituant ainsi la base des traitements numériques dans un programme.

# Définition générale

En langage C, un opérateur est un symbole qui indique une opération à effectuer sur une ou plusieurs valeurs *(appelées opérandes)*. Les opérateurs permettent de manipuler des données, de réaliser des calculs, de comparer des valeurs, et d'effectuer diverses opérations logiques ou bit à bit.

Il existe diverses catégories d'opérateurs que nous allons voir plus en détails juste après : 

- Opérateurs arithmétiques
- Opérateurs logiques
- Opérateurs de comparaison, d'affectation
- ...

# Opérateurs arithmétiques

Les **opérateurs arithmétiques** permettent d'effectuer des calculs mathématiques de base. En langage `C`, on applique ses opérations sur les types numériques `int`, `float`, `double`.

| Opérateur | Description |
| :---: | :---: |
| `+` | Addition |
| `-` | Soustraction |
| `*` | Multiplication |
| `/` | Division |
| `%` | Modulo |

## L'addition `+`

Permet d'additionner deux valeurs. L'opération fonctionne avec les types numériques.

###### Exemple

```c
int a = 5, b = 3;
int somme = a + b; // résultat : 8
```

## La soustraction

Permet de soustraire deux valeurs numériques.

###### Exemple

```c
int a = 5.5, b = 3.2;
int diff = a - b; // résultat : 2.3
```

## La multiplication

Permet de calculer le produit de deux valeurs numériques.

###### Exemple

```c
int a = 5, b = 3;
int prod = a * b; // résultat : 15
```

## La division

Permet d'effectuer la division de deux valeurs numériques.

>[!WARNING]
> La division n'a pas le même comportement selon les types des valeurs numériques divisées.

- Si on divise **deux entiers** `int`, on obtient une ***division entière*** *(i.e. le reste est ignoré)*.
- Si <u>une des valeurs</u> est de type `float` ou `double` cette fois on obtient une ***division réelle***.

###### Exemples

```c
int a = 7, b = 2;
int divE = a / b; // résultat : 3

float x = 7.0, y = 2.0;
float divR = x / y; // résultat : 3.5
```

>[!WARNING]
> `int / int = int` même si le résultat n'est pas un entier !

## Le modulo

Le modulo représente le **reste d'une division entière**, en conséquence, il ne fonctionne qu'*avec les divisions entières* (`int`).

>[!tip]
>Modulo = reste d'une **division entière**.

###### Exemple

```c
int a = 10, b = 3;
int reste = a % b; // résultat : 1
```

Si vous ne vous souvenez pas de ce que représente le modulo, la division entière. On peut étudier d'un peu plus près notre exemple.

On a : 

- `a=10`
- `b=3`

Ce que l'on veut c'est déterminer le reste de `a/b` une division entière. On l'appelle aussi **division euclidienne**. On cherche en réalité une manière d'écrire `a` autrement tel que : 

$$ a = bq+r$$

où 

- $a$ représente le divisé
- $b$ le diviseur
- $q$ le quotient
- $r$ le reste

Et on sait très bien que : $10 = 3 \times 2 + 1$ ainsi le quotient vaut $2$ et le reste $1$ d'où `a%b=1`.

>[!TIP]  
> Le modulo est une opération très pratique pour déterminer si un nombre est **pair**.  
> Si un nombre modulo 2 donne un reste nul, alors il est pair.  
>
>**n est pair $\Longleftrightarrow$ n % 2 = 0**

# Opérateurs d'affectation

Un **opérateur d'affectation** permet de donner une valeur à une variable. <br> L'opérateur principal est `=` *(affectation simple)*, mais il existe des versions qui combinent affectation et opérateur arithmétique.

###### Exemple 

```c
int variable;
variable = 14; // Variable reçoit la valeur 14
```

## Opérateurs d'affectation composés

| Opérateur | Équivalent | Interprétation |
| :---: | :---: | --- |
| `+=` | `a=a+b` | Ajoute `b` à `a` |
| `-=` | `a=a-b` | Retire `b` à `a` |
| `*=` | `a=a*b` | Multiplie `a` par `b` |
| `/=` | `a=a/b` | Divise `a` par `b` (si $b \neq 0$) |
| `%=` | `a=a%b` | Affecte le reste de `a/b` |

###### Exemples

```c
int a = 10;
a += 5;   // a vaut 15

int b = 20;
b /= 4;   // b vaut 5
```

>[!WARNING] 
> - Ces opérateurs modifient **directement** la variable.
> - Pensez à vérifier le type de la variable (division entière, modulo).
> - Ne pas les utiliser si cela nuit à la lisibilité de votre code.

>[!TIP]
>- Initialiser une variable avant de lui appliquer un opérateur composé.
>- Vous pouvez favoriser les opérateurs composés pour rendre le code plus compact et plus lisible. *Tout en ne sacrifiant pas la clarté...*

# Les opérateurs unitaires

Les **opérateurs unitaires** permettent de modifier une variable d'*une seul unité*, soit en l'incrémentant ($+1$) soit en la décrémentant ($-1$), ou encore avec la négation logique ou arithmétique.

## L'incrémentation `++`

L'opérateur d'incrémentation permet d'ajouter $1$ à une variable. On peut la mettre avant ou après la variable.

- **Préfixe** `++a` l'incrémentation a lieu **avant l'utilisation** de la variable.
- **Postfixe** `a++` l'incrémentation a lieu **après l'utilisation** de la variable.

###### Exemples

```c
int x = 5;
int xprim = ++x;  // x devient 6, xprim = 6

int y = 5;
int yprim = y++;  // y devient 6, yprim = 5
```

Autrement dit, pour l'exemple avec la variable `yprim`, on peut dire qu'elle prend la valeur de `y` *avant l'incrémentation*. En opposition, `xprim` lui prend la valeur de `x` après l'incrémentation comptabilisée.

## La décrémentation `--`

La décrémentation permet de retirer 1 à une variable. <br>
*Cet opérateur possède les mêmes caractéristiques que l'incrémentation*

- **Préfixe** `--a` la décrémentation a lieu **avant l'utilisation** de la variable.
- **Postfixe** `a--` la décrémentation a lieu **après l'utilisation** de la variable.

###### Exemples

```c
int x = 5;
int xprim = --x;  // x devient 4, xprim = 4

int y = 5;
int yprim = y--;  // y devient 4, yprim = 5
```

## Opérateur logique de négation `!`

L'opération **logique de négation** `!` inverse la valeur d'une expression booléenne.

- Si la valeur est **vraie** (différente de 0), le résultat sera faux (0).
- Si la valeur est **fausse** (égale à 0), le résultat sera vrai (1).

Pour information, le langage `C` ne possède pas de type booléen (jusqu'à C99) de manière native. Nous verrons un peu plus tard comment contrer cette contrainte.

# Opérateurs de comparaison

Les opérateurs de comparaison permettent de **comparer deux valeurs**. Ils renvoient un résultat **booléen** : 

- `1` si la comparaison est vraie.
- `0` sinon.

Voici un tableau qui permet de récapituler la liste des opérateurs de comparaison.

| Opérateur | Signification |
| :---: | --- |
| `==` | égal |
| `!=` | différent |
| `>` | supérieur strict |
| `>=` | supérieur ou égal |
| `<` | inférieur strict |
| `<=` | inférieur ou égal |

###### Exemples

```c
#include <stdio.h>

int main() {
    int a = 5, b = 3;

    printf("a == b : %d\n", a == b); // 0
    printf("a != b : %d\n", a != b); // 1
    printf("a > b  : %d\n", a > b);  // 1
    printf("a <= b : %d\n", a <= b); // 0

    return 0;
}
```

><u>À retenir :</u><br>
>Les opérateurs de comparaisons renvoient **toujours `0` ou `1`**. Ils peuvent être utilisés seul ou bien combiné avec les opérateurs logiques.

# Opérateur logique

Les **opérateurs logiques** permettent de combiner les expressions booléennes *(= conditions)* pour n'en former qu'une seule. Ils renvoient une valeur booléenne : 

- `0` si faux
- `1` si vrai

| Opérateur | Signification |
| :---: | --- |
| `&&` | **ET** |
| `\|\|` | **OU** |
| `!` | **NON** |

###### Exemples

```c
a<b && b!=0
// a inférieur a b ET b différent de 0
```

## Table de vérité des opérateurs

### Table du ET logique `&&`

| `A` | `B` | `A && B` |
| :---: |:---: | :---: |
| 0 | 0 | 0 |
| 1 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 1 | 1 |

### Table du OU logique `||`

| `A` | `B` | `A \|\| B` |
| :---: |:---: | :---: |
| 0 | 0 | 0 |
| 1 | 0 | 1 |
| 0 | 1 | 1 |
| 1 | 1 | 1 |

### Table du NON logique `!`

| `A` | `!A` |
| :---: |:---: | 
| 0 | 1 | 
| 1 | 0 | 

>[!WARNING]
> Les opérateurs logiques admettent un ordre de priorité par défaut : NON $\rightarrow$ ET $\rightarrow$ OU. Ainsi pour "contrer" ses priorités on peut utiliser les parenthèses. 

# Priorité et associativité des opérateurs

En programmation `C`, une expression contenant plusieurs opérations est évaluée selon un ordre précis. <br> Cet ordre est déterminé par : 

- La priorité des opérateurs
- L'associativité (gauche/droite ou droite/gauche) lorsque plusieurs opérateurs ont la même priorité.

## Définitions

On appelle **priorité** le niveau qui détermine quel opérateur est évalué en premier. Plus la priorité est haute, plus l’opérateur est appliqué tôt.

L'**associativité** règle qui détermine dans quel ordre (de gauche à droite ou de droite à gauche) sont évalués les opérateurs de même priorité.

| Priorité | Opérateur(s)                              | Type                              | Associativité        |
|:--------:|-------------------------------------------|-----------------------------------|----------------------|
| 1        | `()`                                       | Parenthèses (groupement)          | Gauche → droite      |
| 2        | `++` `--` *(postfixes)*                   | Incrémentation/décrémentation     | Gauche → droite      |
| 3        | `++` `--` *(préfixes)*, `+` `-` *(unaire)*, `!`, `~` | Unaires                   | Droite → gauche       |
| 4        | `*` `/` `%`                                | Multiplication, division, modulo  | Gauche → droite      |
| 5        | `+` `-`                                    | Addition, soustraction            | Gauche → droite      |
| 6        | `<` `<=` `>` `>=`                          | Comparaisons                      | Gauche → droite      |
| 7        | `==` `!=`                                  | Égalité, inégalité                | Gauche → droite      |
| 8        | `&&`                                       | ET logique                        | Gauche → droite      |
| 9        | `\|\|`                                     | OU logique                        | Gauche → droite      |
| 10       | `=` `+=` `-=` `*=` ...                     | Affectations                      | Droite → gauche      |
| 11       | `,`                                        | Virgule                           | Gauche → droite      |

>[!TIP]
> Les parenthèses possèdent la priorité **la plus haute**, utilises les pour forcer l'ordre d'évaluation.

###### Exemple

```c
int x = 2 + 3 * 4;  // x = 2 + (3 * 4) = 14
int x = (2 + 3) * 4;  // x = 5 * 4 = 20
```

###### Exemple d'associativité droite/gauche

```c
int a = 14;
int b = 250;
int c;

c = a = b;  // a prend la valeur de b donc a=250, puis c prend la valeur de a donc c = 250
```

En gros l'associativité ici on peut la voir comme étant `c=(a=b)` donc on affecte à `a` la valeur de `b`, puis cette nouvelle valeur est affectée à `c`.

# L'opérateur `~` 

Tu as remarqué ? J'ai glissé un opérateur inconnu dans le tableau ci dessus. 

L'opérateur `~` représente en fait le **NON BINAIRE**, autrement dit, il inverse tous les bits de l'opérande.

- Les `1` deviennent des `0`
- Les `0` deviennent des `1`

###### Exemple

```c
int a = 4; // En binaire 4 = 00000100
int b = ~a; // En binaire b = 11111011
```

Mais en langage `C`, les entiers sont représentés en **complément à deux** ainsi `~5=-6`. De manière générale : `~a=-(a+1)`.

## Le complément à 2

Principe : 

- Le bit le plus à gauche : le signe 

   - 0 pour un nombre positif
   - 1 pour un nombre négatif

- Pour représenter un nombre négatif, on écrit en binaire, on inverse tous les bits puis on ajout 1.

Si on représente 5 en complément à 2 sur 8 bits,

- nombre positif donc premier bit nul
- $5=0101$

Ainsi $5=00000101$.

Si on l'inverse : 

- Le premier bit passe à $1$ et on inverse tous les bits : $11111010$ 
- On ajoute $1$, ainsi $-5=11111011$.