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
![[informatiqueMOT.svg]]
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
