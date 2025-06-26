Bon c'est vrai, si on fait un petit récap ce qu'on a déjà abordé depuis le début de ce cours : 
- Les bases du C
   - Vocabulaires et spécificités
   - Point d'entrée `main`
   - Structure générale d'une fonction
   - Types usuels
   - Opérateur `sizeof`
   - Fonction `printf` et ses formats
   - Constantes
- Opérateurs arithmétiques
- Opérateurs unitaires
- Opérateurs logiques
- Opérateur d'affectation
- Opérateur `~`

Mais il nous manque des structures essentielles permettant de gérer quel code doit s'exécuter, pourquoi, dans quels cas. Et oui, vous m'avez bien compris. On parle évidemment des **structures de contrôle** et des **boucles**.

# Structures de contrôle

## `if`, `else if` et `else`

Le bloc `if` permet de gérer une condition simple grâce au `if`, et des conditions multiples grâce à `else if` et `else`, qui sont donc facultatif. Ce qui veut dire que si on en a pas besoin, on ne les utilises pas.

***Structure générale***

```c
if (condition) {
   // Instructions à effectuer si condition vrai
}
else if (condition2) {
   // Instructions à effectuer si condition2 vrai
}
else {
   // Instructions à effectuer si aucunes des conditions n'est vraie
}
```

On peut aussi le voir comme : 

```
si <condition>
alors
   // Instructions
sinon si <condition2>
alors
   // Instructions
sinon
  // Instructions
```

>[!WARNING]
>Les conditions doivent **retourner un booléen**
> - $0$ si faux
> - $\neq 0$ si vrai
>
>Vous vous souvenez, `C` ne dispose pas de type booléen de manière native.

###### Exemple

On souhaite savoir si un nombre `n` est inférieur, supérieur ou égal à $0$.

```c
#include <stdio.h>

int main( ){
   int n = 14;
   if (n==0){
      printf("%d est égal à 0", n);
   }
   else if (n<0){
      printf("%d est inférieur à 0", n);
   }
   else{
      printf("%d est supérieur à 0", n);
   }
   return 0;
}
```
```
14 est supérieur à 0
```

>[!TIP]
> On a vu auparavant que si une condition est fausse alors elle est **égale à 0**. Alors dans notre cas, si la valeur `n` est fausse, c'est à dire si elle est nulle alors elle est égale à $0$.

Ainsi, à la place de la première condition, on peut aussi coder : 

```c
if (!n){
   printf("%d est égal à 0", n);
}
```

## `switch`

Le bloc `switch` permet de définir les instructions à réaliser *selon la valeur d'une expression*. 

***Structure générale***

```c
switch (expression) {
    case constante1:
        // instructions
        break;
    case constante2:
        // instructions
        break;
    default:
        // instructions par défaut
}
```

On peut le voir comme le bloc suivant : 

```
Évaluons l'expression E
   CAS : si E = constante1
      ...
      on continue le programme
   CAS : si E = constante2
      ...
      on continue le programme
   DÉFAUT : si E ne représente aucun des cas
      ...
      on continue le programme
```

- L'évaluation de l'expression doit être de type entier ou caractère (`int`, `char`, ...).
- Chaque cas possible `case` doit représenter une *constante*

>[!WARNING]
>On utilise l'instruction `break` pour éviter l'**effet de cascade**.

*Pour mieux comprendre l'effet de cascade, prenons un exemple*

###### Exemple

Une enseignante souhaite attribuer automatiquement à chaque étudiant un commentaire en fonction de leur nombre de frère et sœur :

- Défaut : Famille nombreuse
- 0 : Enfant unique
- 1 : Duo d'enfants
- 2 : Trio d'enfants

```c
#include <stdio.h>

int main( ){
   int n = 0;
   switch (n){
       case 0:
            printf("Enfant unique...");
            break;
        case 2:
            printf("Duo d'enfants");
            break;
        case 3:
            printf("Trio d'enfants");
            break;
        default:
            printf("Famille nombreuse");
   }
}
```
```
Enfant unique
```

L'instruction `break` permet de sortir du bloc `switch` une fois qu'un cas a été exécuté. Sans cette instruction à la fin de chaque case, le programme ne s'arrête pas automatiquement après l'exécution d'un cas valide. Au contraire, il continue à exécuter tous les cas suivants, même si leurs conditions ne sont pas remplies. C'est ce qu'on appelle le ***fall-through***.
 
Ainsi dans l'exemple précédant, si les `break` n'étaient pas présent le programme aurait affiché : 

```
Enfant unique...Duo d'enfantsTrio d'enfantsFamille nombreuse
```
Il aurait en fait affiché le cas dans lequel il est respecté, puis tous les cas suivants même si la valeur de l'expression ne rempli pas les conditions.

>[!NOTE]
> On ne met pas `break` à `default` car c'est le dernier cas *(le cas de base)* dans le bloc `switch` ainsi, après ce dernier on sortira forcément du bloc.

# Les boucles 

## `for`

Le bloc `for` est une **boucle**, ce qui signifie que le code inclus dans ce bloc se répètera un **nombre connu de fois**. 

***Structure de la boucle `for`***

```c
for(initialisation; condition arrêt; incrémentation){
   // Instructions a faire
}
```

###### Exemple

On souhaite afficher les valeurs successives de `i` entre $1$ et $10$.

```c
for (int i = 1; i <= 10; i++) {
    printf("%d ", i);
}
```
```
1 2 3 4 5 6 7 8 9 10
```

### Double boucle `for`

Les doubles boucles for en `C` sont très utilisées pour parcourir des *structures à deux dimensions*, comme les tableaux 2D (matrices), ou pour des traitements imbriqués.

```c
for (init1; cdt1; incr1) {            // Parcourt les lignes
    for (init2; cdt2; incr2) {        // Parcourt les colonnes
        // Instructions
    }
}
```

Et vous savez quoi ? On peut encore réduire ces instructions pour ne faire qu'un seul bloc donc créer les deux boucles simultanément. Regardez comment on peut le faire de manière concise : 

```c
for(init1, init2; cdt1 && cdt2, incr1, incr2){
   // Instructions
}
```

###### Exemple

```c
for (int i = 0, j = 10; i < 5 && j > 5; i++, j--) {
    printf("i = %d, j = %d\n", i, j);
}
```
```
i = 0, j = 10
i = 1, j = 9
i = 2, j = 8
i = 3, j = 7
i = 4, j = 6
```

## `while`

Le bloc `while` permet de boucler des instructions **TANT QU'**une condition est vérifiée. La condition est évaluée avant l'exécution du code. *Si la condition est fausse alors le bloc `while` ne sera <u>jamais</u> exécuté.*

>[!NOTE]
>On utilise une boucle `while` lorsque l'on ne connait pas le nombre d'itérations.

***Structure générale du bloc `while`***

###### Exemple

```c
int i = 1;
while (i <= 5) {
    printf("%d\n", i);
    i++;
}
```
```
1
2
3
4
5
```

## `do while`

La boucle `do while` est équivalente à la boucle `while` sauf que son contenu est **exécuté au moins une fois** avant l'évaluation de la condition.

***Syntaxe générale du bloc `do while`***

```c
do {
    // instructions
} while (condition);
```

- La boucle s'exécute **au moins une fois** même si la condition est fausse.
- Très utile lorsque l'on souhaite tester une condition après l'exécution.

###### Exemple

```c
int x;
do {
    printf("Entrer un nombre positif : ");
    scanf("%d", &x);
} while (x <= 0);
```

Dans cet exemple, on boucle sur les instructions tant que l'utilisateur n'a pas tapé un nombre positif strict.