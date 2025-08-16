# Généralités sur les variables

>[!cite] Définition
>- Une **==variable==** permet de stocker une donnée. Elle possède un **nom** qui permet de l'identifier et un **type** qui permet de savoir ce que l'on a stocké : nombre, caractère, ...
>- Une **==donnée==** est une information que l'on range dans une variable. 

## Déclaration d'une variable
En JavaScript il est possible de déclarer une variable de plusieurs manières.
### Les constantes avec `const`
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

>[!warning]
>Une constante doit être initialisée **en même temps** que la définition de la variable !

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

>[!warning]
>- Il ne peux pas exister d'autres variables possédant le même nom qu'une constante.
>- Une constante ne peux pas être "recréée".
>- Une constante ne peux pas être réaffectée.
>- Une constante doit être définie et initialisée en même temps.

### Le mot clé `let`
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

La portée d'une variable définie avec le mot clé `let` dépend du bloc dans lequel elle a été déclarée.

<u>Exemple :</u> `exemple5.js`  
$\boxed{\text{Utilisation des variables avec \texttt{let}}}$
```js
// Création d'une variable
let y = 14;
console.log("Y définie en dehors d'un bloc : " + y);

function test(){
	// Création d'une autre variable du même nom
    let y = 20;
    console.log("Y définie dans la fonction : " + y);
}

// Les tests
console.log("Avant l'appel de la fonction : " + y);
test();
console.log("Après l'appel de la fonction : " + y);
```
```
Y définie en dehors d'un bloc : 14
Avant l'appel de la fonction : 14
---
Y définie dans la fonction : 20
Après l'appel de la fonction : 14
```
Ce qu'il se passe n'est pas très compliqué à comprendre. On défini en dehors de tout bloc une variable `y` elle a donc une portée globale, accessible partout dans le code.  
Dans la fonction `test` on créé à nouveau une autre variable qui s'appelle aussi `y` et on lui donne une valeur différente, ainsi, puisque les variables définies avec `let` ont une portée qui dépend du bloc dans lequel elle se trouve :
- **Dans la fonction `test`**, c'est `y=20` qui sera utilisé
- **Hors de la fonction**, `y=20` n'existe plus car on est sorti du bloc mais `y=14` est globale, donc on retourne avec celle ci.
### Le mot clé `var`
Le mot clé `var` permet de déclaré une variable et d'**éventuellement** lui donner une valeur.  La portée d'une variable déclarée avec `var` est le _contexte d'exécution_ courant, c'est-à-dire : **la fonction** qui contient la déclaration **ou le contexte global** pour le cas échéant.  
Si on affecte une variable **sans utiliser `var`** alors, cela va créer une variable globale