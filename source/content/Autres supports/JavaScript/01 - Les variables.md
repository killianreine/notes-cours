# Généralités sur les variables

>[!cite] Définition
>- Une **==variable==** permet de stocker une donnée. Elle possède un **nom** qui permet de l'identifier et un **type** qui permet de savoir ce que l'on a stocké : nombre, caractère, ...
>- Une **==donnée==** est une information que l'on range dans une variable. 

## Déclaration d'une variable
En JavaScript il est possible de déclarer une variable de plusieurs manières.
### Variable statique
Le mot clé `const` permet de créer une constante accessible **uniquement en lecture**, ce qui signifie qu'après initialisation, cette dernière ne peux pas être modifiée lors de réaffectations futures. 
```js
const var = valeur ;
```

<u>Exemple :</u> `exemple1.js`  
$\boxed{\text{Erreur de réaffectation}}$
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
$\boxed{\text{Erreur d'initialisation post-définition}}$
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

Les variables créées avec le mot clé `const` ont une portée qui dépend de où elle a été créée, c'est à dire que si la variable est créée dans un bloc alors elle ne sera qu'accessible dans ce bloc. Tandis que si elle est créée dans aucun bloc elle aura une portée dite **globale**. 

<u>Exemple :</u> `exemple3.js`
$\boxed{\text{Portée des variables définies avec \texttt{const}}}$
```js
const A = 12;

if(true){
    const B = "LOCALE";
    console.log("Dans le bloc if");
    console.log(A);
    console.log(B);
}

console.log("Hors du bloc if");
console.log(A);
console.log(B);
```
```b
Dans le bloc if
LOCALE
12
Hors du bloc IF
12
```
```bash
console.log(B);
            ^
ReferenceError: B is not defined
```
En fait, dans cette extrait de code, la variable `A` est une constante créée dans aucun bloc de code, sa portée est donc globale, ça signifie qu'elle est accessible <u>n'importe où</u> dans le code. Alors que la variable `B` elle a été créée dans le bloc `if` est est donc locale au `if`, du coup lorsque l'on essaie d'y accéder en dehors du bloc `if`, une erreur est levée.
### Variable dynamique
Pour déclarer une **variable dynamique**, on utilise le mot clé `let`. On dit alors que la variable est **==mutable==** donc qu'on peut lui réattribuer d'autres valeurs. 

<u>Exemple :</u> `exemple4.js`  
$\boxed{\text{Définition, initialisation, modification}}$
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

## Le mot clé `var`
