# Généralités sur les variables

>[!cite] Définition
>- Une **==variable==** permet de stocker une donnée. Elle possède un **nom** qui permet de l'identifier et un **type** qui permet de savoir ce que l'on a stocké : nombre, caractère, ...
>- Une **==donnée==** est une information que l'on range dans une variable. 

## Déclaration d'une variable
En JavaScript il est possible de déclarer une variable de plusieurs manières.
### Variable statique
On utilise alors le mot clé `const`, toute variable définie avec ce dernier **doit être initialisée pendant la définition** et **ne peut pas être redéfinie**.
```js
const var = valeur ;
```

<u>Exemple :</u> `exemple1.js`
```js
const age = 19;
age = 20;
```
```bash
age = 20;
    ^
TypeError: Assignment to constant variable.
```
Dans cet exemple, puisque la variable `age` est définie avec le mot-clé `const` alors on ne peut pas la redéfinir plus tard (= lui réattribuer une autre valeur), ainsi lorsque l'on souhaite changer la valeur de `age`, une erreur est directement levée.  
L'erreur <span class="error-inline">TypeError</span> apparaîtra lorsque vous essayez de réaffecter une variable définie avec `const`.

<u>Exemple :</u> `exemple2.js`
```js
const age;
age = 19;
```
```bash
const age;
      ^^^
SyntaxError: Missing initializer in const declaration
```
L'erreur suivante indique qu'il manque l'initialisation dans la déclaration avec le mot clé `const`.

>[!tip]
>On dit d'une variable définie avec `const` qu'elle est immuable. En gros qu'elle n'est pas modifiable.

### Variable dynamique
Pour déclarer une **variable dynamique**, on utilise le mot clé `let`. On dit alors que la variable est **==mutable==** donc qu'on peut lui réattribuer d'autres valeurs. 

<u>Exemple :</u> `exemple3.js`
```js
// Définition d'une variable avec let sans initialisation
let age;
console.log("Age avant initialisation : "+age);
  
// Post-initialisation de la variable
age = 14;
console.log("Age après attribution de variable : "+age);

// Réaffectation d'une nouvelle valeur dans la variable age
age = 20;
console.log("Age après modification de variable : "+age);
```
```
Age avant initialisation : undefined
Age après attribution de variable : 14
Age après modification de variable : 20
```

**Quelques différences d'utilisation entre `let` et `const`**

|                                | `let` | `const` |
| ------------------------------ | ----- | ------- |
| Définition seule               | OUI   | NON     |
| Définition + initialisation    | OUI   | OUI     |
| Initialisation post-définition | OUI   | NON     |
| Réaffectation d'une variable   | OUI   | NON     |
