# Enum
## Définition et généralités
Une **énumération** est un type défini par l’utilisateur qui représente un **ensemble de constantes entières symboliques**.
- Chaque nom symbolique correspond à un entier.
- Utile pour améliorer la **lisibilité** et la **maintenance** du code.

Syntaxe de base :
```c
enum nom = { CST1, CST2, ... };
```

<u>Exemple :</u>  
Avec des couleurs :
```c
enum couleur = { ROUGE, VERT, BLEU };
```
- `ROUGE` vaut $1$
- `VERT` vaut $2$
- `BLEU` vaut $3$

```c
enum Jour { LUNDI = 1, MARDI, MERCREDI = 5 };
```
Ici, `LUNDI = 1`, `MARDI = 2` *(auto-incrément)*, `MERCREDI = 5`.

## Utilisation d'une `enum`
```c
#include <stdio.h>

enum Etat { MARCHE, ARRET, PAUSE };

int main() {
    enum Etat machine;
    
    machine = MARCHE;
    printf("Etat = %d\n", machine);  // affiche 0

    machine = PAUSE;
    printf("Etat = %d\n", machine);  // affiche 2

    return 0;
}
```
```
Etat = 0
Etat = 2
```

Pour changer la valeur de la variable on utilise la syntaxe : 
```
var = CONSTANTE
```
Ainsi si on résume les opérations :
```c
enum qqch = { ... };

// Quelque part dans le code
enum qqch nom = CST;

// Changement de constante
nom = AUTRECONSTANTE;
```

>[!info] Remarque
>- Les variables `enum` sont stockées comme **des entiers** en mémoire.
>- On peut donc faire des comparaisons et opérations arithmétiques si nécessaire.

## Avantages
1. **Lisibilité du code :** utiliser `MARCHE` au lieu de `0`.
2. **Maintenance facile :** ajout ou modification des états sans changer les conditions partout.
3. **Débogage plus simple :** les valeurs symboliques donnent un sens immédiat.

# Union
## Définition et généralités
Les **==unions==** permettent de stocker différentes variables **au même espace mémoire**. Utile pour économiser de la mémoire ou pour gérer différents types d’une même donnée.  
Contrairement à `struct`, **une union ne peut contenir qu’une seule valeur à la fois**, car toutes ses variables partagent le même espace mémoire.

```c
union Exemple {
    int entier;
    float flottant;
    char caractere;
};
```
Ici, `entier`, `flottant` et `caractere` partagent la **même zone mémoire**.

## Utilisation
Déclaration et utilisation, le type d'une instance de l'union sera donnée par `union type`. Dans notre cas ce sera `union Donnee`
```c
#include <stdio.h>

union Donnee {
    int entier;
    float flottant;
    char caractere;
};

int main() {
    union Donnee d;

    d.entier = 10;
    printf("entier = %d\n", d.entier);

    d.flottant = 3.14; // écrase la valeur entière
    printf("flottant = %.2f\n", d.flottant);

    d.caractere = 'A'; // écrase la valeur flottante
    printf("caractere = %c\n", d.caractere);

    return 0;
}
```
```
entier = 10
flottant = 3.14
caractere = A
```
- Après avoir stocké une valeur dans `d.entier`, si on écrit dans `d.flottant`, la valeur entière est perdue.
- L’union conserve **seulement la dernière donnée écrite**

## Taille d'une union
La taille d’une union est **égale à la taille du type qui prend le plus d'espace mémoire**.

<u>Exemple :</u>
```c
union Exemple {
    char c;     // 1 octet
    int i;      // 4 octets
    double d;   // 8 octets
};
```
La taille de l'union sera donc $8$.

| Aspect   | `struct`                                | `union`                                            |
| -------- | --------------------------------------- | -------------------------------------------------- |
| Stockage | Chaque membre a sa place                | Tous les membres partagent la même place           |
| Taille   | Somme des tailles des membres           | Taille du membre le plus grand                     |
| Usage    | Stocker plusieurs valeurs simultanément | Stocker une seule valeur parmi plusieurs possibles |

# Champs de bits
