# Ce bon vieux `Hello world`

Et oui, ici aussi vous n'y échapperez pas, notre premier programme C vas nous permettre d'afficher ce fameux `Hello world` dans la console.

Avant de commencer à coder, réfléchissons un peu. Pour rappel le C est une suite de fonction dont une obligatoire la fonction `main( )`, c'est elle qui sera exécutée en premier d'où son appellation *point d'entrée*. Nous allons devoir trouver le moyen d'afficher du texte dans la console.

En programmation C, il est aussi impératif de réfléchir à quel genre de "chose" doit renvoyer la fonction, comme par exemple un entier, une chaîne de caractères, un caractère, un booléen, ... autrement dit, quel **type la fonction va renvoyer**.

## Le point d'entrée `main( )`

Lorsqu'un programme commence à s'exécuter il appellera **toujours** `main( )`en premier. C'est une fonction qui permet de diriger les appels aux autres fonctions du programme.  

Voyons ce qu'il se passe pour un programme qui n'utilise pas la fonction `main()`. 

Malgré tout quelques contraintes s'appliquent à `main( )` :   
On considère le code suivant associé à son résultat à la compilation :
```c
#include <stdio.h>

int somme(int a, int b){
	return a+b;
}
```
```bash
...  /usr/lib/gcc/x86_64-linux-gnu/13/../../../x86_64-linux-gnu/Scrt1.o : dans la fonction « _start » :
(.text+0x1b) : référence indéfinie vers « main »
collect2: error: ld returned 1 exit status
```
L'erreur spécifie directement que la fonction `main` est indéfinie, en gros qu'il manque la fonction `main`.

Elle ne peut pas être définit comme `static`.  
En fait, le mot clé `static` possède deux utilités différentes selon le contexte :  
- Placé dans un fichier en global, il permet de *limiter la visibilité* au fichier courant.
- Placé dans une fonction, appliquée à une variable elle lui donne une durée de vie statique.

Ainsi, si on définit la fonction `main`comme étant `static` alors cette dernière sera invisible lors de l'édition des liens, le système sera donc incapable de la retrouver pour démarrer le programme.

- Elle ne peut pas être appelée

Toute fonction en langage `C` possède le même squelette : 

```
typeRetour nomFonction( arguments ) {
   instruction 1;
   instruction 2;
   ...;
   return ...;
}
```

Étudions ce squelette : 

- `typeRetour` représente le type de la donnée que doit renvoyer la fonction. C'est à dire si la fonction doit retourner un entier, un caractère, un tableau, ...
- `nomFonction` représente le nom que vous donnez à la fonction permettant de l'appeler.
- `arguments` représentent les paramètres de la fonction *(une fonction n'a pas forcément de paramètres)*.
- `return` est l'instruction permettant de retourner un résultat.

>[!WARNING]
> Si votre fonction doit retourner un entier et que vous retournez un charactère, la compilation ne fonctionnera pas.

Si on revient à notre fonction `main( )`,

- Par convention, elle retourne `0` donc un entier de type `int` *que l'on détaillera après*.
- On connaît son nom.
- Elle n'a pas besoin d'arguments/paramètres.

Ainsi en suivant le squelette, notre fonction `main( )` devrait ressembler à cela : 

```c
int main( ){ 
   // Instructions de la fonction main( )
   return 0;
}
```

>[!WARNING]
> Sans oublier le `return 0;` puisqu'on définit que la fonction principale revoie un entier.

Ainsi, ce tout petit code nous permet d'introduire des spécificités de la programmation `C`

- Chaque fonction est un bloc délimitée entre accolades `{ ... }`.
- Chaque instruction se termine avec un point-virgule `;` *qui permet de spécifier la fin d'une instruction*.

### Écrire des commentaires

En `C` il est possible d'écrire deux sortes de commentaires : 

- Sur une ligne `//...`
- Sur plusieurs lignes `/* ... */`

```c
// Un commentaire sur une ligne
/*
Un commentaire sur 
plusieurs lignes
*/
```

## Afficher des informations dans la console

La fonction `printf(...)` permet d'afficher du texte ou des valeurs à l'écran. Il faut se souvenir que `printf` n'est pas directement utilisable, **elle vient d'une bibliothèque** appelée `stdio.h`. Ainsi cela implique que pour pouvoir utiliser la fonction `printf` il faudra spécifier en entête la bibliothèque. C'est donc là qu'intervient les `#include` évoqués lors du premier cours.

"Signature" de la fonction `printf` :
```c
printf(const char* format, ...);
```
- La fonction prend comme premier paramètre une chaîne de caractères *entre `"..."`*. Cette dernière peut-être **formatée** ou non.  
  On dit qu'une chaîne est **==formatée==** lorsqu'elle permet d'afficher des données sous un format donné. Le format est spécifié par un symbole pourcentage suivit du format correspondant : `%...`.
- Les autres paramètres sont les valeurs des différents formats spécifié dans la chaîne. Si aucun format, alors aucune valeur/variable à spécifier à la fonction.

Voici comment inclure la bibliothèque `stdio.h` dans votre fichier C et d'afficher ce bon vieux `Hello world`.

Pour rappel : 

- `main( )` est le point d'entrée du programme qui renvoie un entier, `0`.
- Pour afficher une donnée on utilise `printf` issu de la bibliothèque `stdio.h`.

```c
#include<stdio.h>

int main( ){
   printf("Hello world");
   return 0;
}
``` 
```
Hello world
```

Et voilà, votre premier `main` en langage C, plutôt cool non ? Bon je suis d'accord, on a pas encore vu grand chose, mais déjà quelle fierté d'avoir son premier code qui fonctionne !!

>[!TIP]
> Les **header** *(= `include`)* se font au début du code, c'est à dire avant toutes les fonctions. La quasi totalité du temps, les premières lignes de vos fichiers C seront des `include`.

Grossièrement votre code devrait ressembler au squelette suivant : 

```c
#include<...>
#include<...>
//... 

// Toutes les fonctions

// À la fin, la fonction main
int main( ){ 
   // Instructions
   return 0;
}
```

# Les types usuels

Bon je suis d'accord avec toi, ça fait plusieurs fois que je parle de type. C'est donc le moment idéal pour les introduire un à un. Prenons les plus fréquents pour commencer. Les autres pourront être introduits au moment voulu.

## Le type caractère

Le mot clé `char` désigne un objet de type caractère, ce dernier peut contenir n'importe quel caractère que la machine utilise. Le plus souvent, un objet de type `char` est **codé sur 1 octet** *(= 8 bits)* et les caractères pris en compte sont ceux qui correspondent au codage ASCII.

<div>
<table>
        <thead>
            <tr>
                <th>Decimal</th>
                <th>Hex</th>
                <th>Char</th>
                <th class="separator">Decimal</th>
                <th>Hex</th>
                <th>Char</th>
                <th class="separator">Decimal</th>
                <th>Hex</th>
                <th>Char</th>
                <th class="separator">Decimal</th>
                <th>Hex</th>
                <th>Char</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td class="decimal">0</td><td class="hex">00</td><td class="control-char">[NULL]</td>
                <td class="decimal separator">32</td><td class="hex">20</td><td class="control-char">[SPACE]</td>
                <td class="decimal separator">64</td><td class="hex">40</td><td class="char">@</td>
                <td class="decimal separator">96</td><td class="hex">60</td><td class="char">`</td>
            </tr>
            <tr>
                <td class="decimal">1</td><td class="hex">01</td><td class="control-char">[START OF HEADING]</td>
                <td class="decimal separator">33</td><td class="hex">21</td><td class="char">!</td>
                <td class="decimal separator">65</td><td class="hex">41</td><td class="char">A</td>
                <td class="decimal separator">97</td><td class="hex">61</td><td class="char">a</td>
            </tr>
            <tr>
                <td class="decimal">2</td><td class="hex">02</td><td class="control-char">[START OF TEXT]</td>
                <td class="decimal separator">34</td><td class="hex">22</td><td class="char">"</td>
                <td class="decimal separator">66</td><td class="hex">42</td><td class="char">B</td>
                <td class="decimal separator">98</td><td class="hex">62</td><td class="char">b</td>
            </tr>
            <tr>
                <td class="decimal">3</td><td class="hex">03</td><td class="control-char">[END OF TEXT]</td>
                <td class="decimal separator">35</td><td class="hex">23</td><td class="char">#</td>
                <td class="decimal separator">67</td><td class="hex">43</td><td class="char">C</td>
                <td class="decimal separator">99</td><td class="hex">63</td><td class="char">c</td>
            </tr>
            <tr>
                <td class="decimal">4</td><td class="hex">04</td><td class="control-char">[END OF TRANSMISSION]</td>
                <td class="decimal separator">36</td><td class="hex">24</td><td class="char">$</td>
                <td class="decimal separator">68</td><td class="hex">44</td><td class="char">D</td>
                <td class="decimal separator">100</td><td class="hex">64</td><td class="char">d</td>
            </tr>
            <tr>
                <td class="decimal">5</td><td class="hex">05</td><td class="control-char">[ENQUIRY]</td>
                <td class="decimal separator">37</td><td class="hex">25</td><td class="char">%</td>
                <td class="decimal separator">69</td><td class="hex">45</td><td class="char">E</td>
                <td class="decimal separator">101</td><td class="hex">65</td><td class="char">e</td>
            </tr>
            <tr>
                <td class="decimal">6</td><td class="hex">06</td><td class="control-char">[ACKNOWLEDGE]</td>
                <td class="decimal separator">38</td><td class="hex">26</td><td class="char">&</td>
                <td class="decimal separator">70</td><td class="hex">46</td><td class="char">F</td>
                <td class="decimal separator">102</td><td class="hex">66</td><td class="char">f</td>
            </tr>
            <tr>
                <td class="decimal">7</td><td class="hex">07</td><td class="control-char">[BELL]</td>
                <td class="decimal separator">39</td><td class="hex">27</td><td class="char">'</td>
                <td class="decimal separator">71</td><td class="hex">47</td><td class="char">G</td>
                <td class="decimal separator">103</td><td class="hex">67</td><td class="char">g</td>
            </tr>
            <tr>
                <td class="decimal">8</td><td class="hex">08</td><td class="control-char">[BACKSPACE]</td>
                <td class="decimal separator">40</td><td class="hex">28</td><td class="char">(</td>
                <td class="decimal separator">72</td><td class="hex">48</td><td class="char">H</td>
                <td class="decimal separator">104</td><td class="hex">68</td><td class="char">h</td>
            </tr>
            <tr>
                <td class="decimal">9</td><td class="hex">09</td><td class="control-char">[HORIZONTAL TAB]</td>
                <td class="decimal separator">41</td><td class="hex">29</td><td class="char">)</td>
                <td class="decimal separator">73</td><td class="hex">49</td><td class="char">I</td>
                <td class="decimal separator">105</td><td class="hex">69</td><td class="char">i</td>
            </tr>
            <tr>
                <td class="decimal">10</td><td class="hex">0A</td><td class="control-char">[LINE FEED]</td>
                <td class="decimal separator">42</td><td class="hex">2A</td><td class="char">*</td>
                <td class="decimal separator">74</td><td class="hex">4A</td><td class="char">J</td>
                <td class="decimal separator">106</td><td class="hex">6A</td><td class="char">j</td>
            </tr>
            <tr>
                <td class="decimal">11</td><td class="hex">0B</td><td class="control-char">[VERTICAL TAB]</td>
                <td class="decimal separator">43</td><td class="hex">2B</td><td class="char">+</td>
                <td class="decimal separator">75</td><td class="hex">4B</td><td class="char">K</td>
                <td class="decimal separator">107</td><td class="hex">6B</td><td class="char">k</td>
            </tr>
            <tr>
                <td class="decimal">12</td><td class="hex">0C</td><td class="control-char">[FORM FEED]</td>
                <td class="decimal separator">44</td><td class="hex">2C</td><td class="char">,</td>
                <td class="decimal separator">76</td><td class="hex">4C</td><td class="char">L</td>
                <td class="decimal separator">108</td><td class="hex">6C</td><td class="char">l</td>
            </tr>
            <tr>
                <td class="decimal">13</td><td class="hex">0D</td><td class="control-char">[CARRIAGE RETURN]</td>
                <td class="decimal separator">45</td><td class="hex">2D</td><td class="char">-</td>
                <td class="decimal separator">77</td><td class="hex">4D</td><td class="char">M</td>
                <td class="decimal separator">109</td><td class="hex">6D</td><td class="char">m</td>
            </tr>
            <tr>
                <td class="decimal">14</td><td class="hex">0E</td><td class="control-char">[SHIFT OUT]</td>
                <td class="decimal separator">46</td><td class="hex">2E</td><td class="char">.</td>
                <td class="decimal separator">78</td><td class="hex">4E</td><td class="char">N</td>
                <td class="decimal separator">110</td><td class="hex">6E</td><td class="char">n</td>
            </tr>
            <tr>
                <td class="decimal">15</td><td class="hex">0F</td><td class="control-char">[SHIFT IN]</td>
                <td class="decimal separator">47</td><td class="hex">2F</td><td class="char">/</td>
                <td class="decimal separator">79</td><td class="hex">4F</td><td class="char">O</td>
                <td class="decimal separator">111</td><td class="hex">6F</td><td class="char">o</td>
            </tr>
            <tr>
                <td class="decimal">16</td><td class="hex">10</td><td class="control-char">[DATA LINK ESCAPE]</td>
                <td class="decimal separator">48</td><td class="hex">30</td><td class="char">0</td>
                <td class="decimal separator">80</td><td class="hex">50</td><td class="char">P</td>
                <td class="decimal separator">112</td><td class="hex">70</td><td class="char">p</td>
            </tr>
            <tr>
                <td class="decimal">17</td><td class="hex">11</td><td class="control-char">[DEVICE CONTROL 1]</td>
                <td class="decimal separator">49</td><td class="hex">31</td><td class="char">1</td>
                <td class="decimal separator">81</td><td class="hex">51</td><td class="char">Q</td>
                <td class="decimal separator">113</td><td class="hex">71</td><td class="char">q</td>
            </tr>
            <tr>
                <td class="decimal">18</td><td class="hex">12</td><td class="control-char">[DEVICE CONTROL 2]</td>
                <td class="decimal separator">50</td><td class="hex">32</td><td class="char">2</td>
                <td class="decimal separator">82</td><td class="hex">52</td><td class="char">R</td>
                <td class="decimal separator">114</td><td class="hex">72</td><td class="char">r</td>
            </tr>
            <tr>
                <td class="decimal">19</td><td class="hex">13</td><td class="control-char">[DEVICE CONTROL 3]</td>
                <td class="decimal separator">51</td><td class="hex">33</td><td class="char">3</td>
                <td class="decimal separator">83</td><td class="hex">53</td><td class="char">S</td>
                <td class="decimal separator">115</td><td class="hex">73</td><td class="char">s</td>
            </tr>
            <tr>
                <td class="decimal">20</td><td class="hex">14</td><td class="control-char">[DEVICE CONTROL 4]</td>
                <td class="decimal separator">52</td><td class="hex">34</td><td class="char">4</td>
                <td class="decimal separator">84</td><td class="hex">54</td><td class="char">T</td>
                <td class="decimal separator">116</td><td class="hex">74</td><td class="char">t</td>
            </tr>
            <tr>
                <td class="decimal">21</td><td class="hex">15</td><td class="control-char">[NEGATIVE ACKNOWLEDGE]</td>
                <td class="decimal separator">53</td><td class="hex">35</td><td class="char">5</td>
                <td class="decimal separator">85</td><td class="hex">55</td><td class="char">U</td>
                <td class="decimal separator">117</td><td class="hex">75</td><td class="char">u</td>
            </tr>
            <tr>
                <td class="decimal">22</td><td class="hex">16</td><td class="control-char">[SYNCHRONOUS IDLE]</td>
                <td class="decimal separator">54</td><td class="hex">36</td><td class="char">6</td>
                <td class="decimal separator">86</td><td class="hex">56</td><td class="char">V</td>
                <td class="decimal separator">118</td><td class="hex">76</td><td class="char">v</td>
            </tr>
            <tr>
                <td class="decimal">23</td><td class="hex">17</td><td class="control-char">[END OF TRANS. BLOCK]</td>
                <td class="decimal separator">55</td><td class="hex">37</td><td class="char">7</td>
                <td class="decimal separator">87</td><td class="hex">57</td><td class="char">W</td>
                <td class="decimal separator">119</td><td class="hex">77</td><td class="char">w</td>
            </tr>
            <tr>
                <td class="decimal">24</td><td class="hex">18</td><td class="control-char">[CANCEL]</td>
                <td class="decimal separator">56</td><td class="hex">38</td><td class="char">8</td>
                <td class="decimal separator">88</td><td class="hex">58</td><td class="char">X</td>
                <td class="decimal separator">120</td><td class="hex">78</td><td class="char">x</td>
            </tr>
            <tr>
                <td class="decimal">25</td><td class="hex">19</td><td class="control-char">[END OF MEDIUM]</td>
                <td class="decimal separator">57</td><td class="hex">39</td><td class="char">9</td>
                <td class="decimal separator">89</td><td class="hex">59</td><td class="char">Y</td>
                <td class="decimal separator">121</td><td class="hex">79</td><td class="char">y</td>
            </tr>
            <tr>
                <td class="decimal">26</td><td class="hex">1A</td><td class="control-char">[SUBSTITUTE]</td>
                <td class="decimal separator">58</td><td class="hex">3A</td><td class="char">:</td>
                <td class="decimal separator">90</td><td class="hex">5A</td><td class="char">Z</td>
                <td class="decimal separator">122</td><td class="hex">7A</td><td class="char">z</td>
            </tr>
            <tr>
                <td class="decimal">27</td><td class="hex">1B</td><td class="control-char">[ESCAPE]</td>
                <td class="decimal separator">59</td><td class="hex">3B</td><td class="char">;</td>
                <td class="decimal separator">91</td><td class="hex">5B</td><td class="char">[</td>
                <td class="decimal separator">123</td><td class="hex">7B</td><td class="char">{</td>
            </tr>
            <tr>
                <td class="decimal">28</td><td class="hex">1C</td><td class="control-char">[FILE SEPARATOR]</td>
                <td class="decimal separator">60</td><td class="hex">3C</td><td class="char">&lt;</td>
                <td class="decimal separator">92</td><td class="hex">5C</td><td class="char">\</td>
                <td class="decimal separator">124</td><td class="hex">7C</td><td class="char">|</td>
            </tr>
            <tr>
                <td class="decimal">29</td><td class="hex">1D</td><td class="control-char">[GROUP SEPARATOR]</td>
                <td class="decimal separator">61</td><td class="hex">3D</td><td class="char">=</td>
                <td class="decimal separator">93</td><td class="hex">5D</td><td class="char">]</td>
                <td class="decimal separator">125</td><td class="hex">7D</td><td class="char">}</td>
            </tr>
            <tr>
                <td class="decimal">30</td><td class="hex">1E</td><td class="control-char">[RECORD SEPARATOR]</td>
                <td class="decimal separator">62</td><td class="hex">3E</td><td class="char">&gt;</td>
                <td class="decimal separator">94</td><td class="hex">5E</td><td class="char">^</td>
                <td class="decimal separator">126</td><td class="hex">7E</td><td class="char">~</td>
            </tr>
            <tr>
                <td class="decimal">31</td><td class="hex">1F</td><td class="control-char">[UNIT SEPARATOR]</td>
                <td class="decimal separator">63</td><td class="hex">3F</td><td class="char">?</td>
                <td class="decimal separator">95</td><td class="hex">5F</td><td class="char">_</td>
                <td class="decimal separator">127</td><td class="hex">7F</td><td class="control-char">[DEL]</td>
            </tr>
        </tbody>
    </table>
</div>


>[!TIP]
> Les caractères en `C` peuvent être utilisés **comme des entiers**, il est donc possible de faire des opérations arithmétiques sur eux.

<u>Exemple :</u>  
On considère une variable `a` qui contient le caractère `'a'` et on souhaite afficher la lettre `b` à partir de `a`. On sait grâce à la table ASCII que la différence entre le code de `b` et le code de `a` vaut 1, il faut donc ajouter 1 à la variable contenant `'a'` pour obtenir `b`.

```c
#include<stdio.h>

int main( ){
   char a = 'a';
   char b = a+1;
   printf("%c", b);
}
```
```
b
```

>[!WARNING]
> Une variable de type `char` ne peut contenir **qu'un seul et unique** caractère. Pour pouvoir stocker plusieurs caractères, il faudra utiliser : 
>
> - Un tableau de `char`
> - Un pointeur vers `char`
>
> Ces deux aspects seront évoqués plus tard dans ce cours. *cours 6 et 7*

En conséquence, cela implique directement qu'une variable de type `char` contenant plusieurs caractères déclenchera une erreur et empêchera la compilation de votre programme.

> [!tip]
> Un objet de type `char` ne peut contenir qu'un seul caractère, et en réalité chaque caractère représente une valeur numérique qui correspond en fait à son codage dans la table ASCII.

Ainsi, on peut avoir besoin d'afficher la valeur d'une variable de type `char` sous forme de caractère ou sous forme numérique. Cela est évidemment possible en langage `C`.

Voilà comment procéder : 

```c
#include<stdio.h>

int main( ){
   char a = 'A';
   printf("%c", a); // Afficher le caractère
   printf("%d", a); // Afficher la valeur numérique
}
```
```
A
65
```

Où `65` représente le code ASCII de la lettre `A`.

*Pour le moment, ne nous préoccupons pas de `%c` et `%d`, on en reparle un peu après. Pour spoiler un peu on peut les voir comme des formats qui permettent de dire je veux afficher la valeur dans un certain `type` de la variable `truc`.*

## Le type entier

Les **entiers** sont représentés par le mot clé `int`, qui peut être précédé : 

- d'un **attribut de précision** `short` ou `long`
- d'un **attribut de représentatio** `signed` ou `unsigned` 

>[!info] Remarque
>La taille d'une variable dépend aussi de la machine sur laquelle vous codez.

| Type | Taille (en octets) | Plage de valeur possible | 
| :---: | :---: | --- | 
| `int` | 4 | -2 147 483 648 à 2 147 483 647 |
| `unsigned int` | 4 | 0 à 4 294 967 295 |
| `short` ou `short int` | 2 | -37 768 à 37 767 | 
| `unsigned short` | 2 | 0 à 65 535 | 
| `long` ou `long int` | 4 ou 8 | dépend du pc |
| `unsigned long` | 4 ou 8 | uniquement valeurs positive | 
| `long long` | 8| très grands nombres | 
| `unsigned long long` | 8 | les positifs |

>[!NOTE]
> - `unsigned` pour des valeurs positives.
> - `signed` pour les valeurs positives et négatives.
> - `short` petite taille
> - `long` grande taille
> - La taille des entiers selon le format peut dépendre aussi du système sur Windows par exemple on note certaines différences entre 32 et 64 bits. *Le compilateur peux aussi jouer un rôle.*

<u>Exemple :</u>  
Si on souhaite définir un entier non signé, il suffit de spécifier le type de l'entier choisit, un nom de variable puis une valeur. Dans la pratique si on choisit que la variable `var` contiendra 155 alors, en programmation `C` on écrira : 
```c
unsigned int var = 155;
```

>[!TIP]
> La taille d'un `short int` est comprise entre la taille d'un objet de type `char` et la taille d'un objet de type `int`, on peut aussi le noter : 
> 
> ```c
> sizeof(char) <= sizeof(short int) <= sizeof(int)
> ```

### L'opérateur `sizeof`

L'opération `sizeof` permet de **déterminer la taille** (en octets) d'un *type de données* ou d'une *variable*. Ce dernier se révèle très utilise lorsqu'il faut gérer la mémoire, et pour travailler avec les structures complexes.

#### Utiliser `sizeof` pour un type de données

Il est possible d'obtenir la taille d'un type de donnée spécifié lors de l'appel de l'opérateur.

>[!NOTE]
> Les **types de données** sont `int`, `char`, `float`, ... 

Ainsi, il suffit d'écrire `sizeof(type_de_donnees)`.

<u>Exemple :</u>  
```c
#include<stdio.h>

int main( ){
   printf("Taille d'un entier : %d", sizeof(int));
   printf("Taille d'un caractère : %d", sizeof(char));
   printf("Taille d'un flottant : %d", sizeof(float));
   return 0;
}
```

#### Utiliser `sizeof` sur une variable

```c
#include<stdio.h>

int main( ){
   int a = 1452; 
   printf("Taille de la variable a : %d", sizeof(a));
   return 0;
}
```

Il est évidemment possible de calculer la taille des tableaux et des structures mais nous verrons ces aspects plus tard dans ce cours.

>[!NOTE]
> L'opérateur `sizeof` est évalué à la compilation, ce qui signifie qu'il n'a pas d'impact sur la performance à l'exécution.

## Les types flottants

En langage `C`, le type flottant *(floating-point)* est utilisé pour représenter les nombres réels avec une partie décimale. Il existe **deux types** flottants : 

- `float` précision **simple** 
   - généralement sur 32bits
   - environ 7 chiffres significatifs
- `double` précision **double** 
   - généralement sur 64bits
   - environ 15-16 chiffres significatifs

>[!WARNING]
> Le nombre de **chiffres significatif** représente la précision avec laquelle est donnée un nombre.

Les valeurs minimales et maximales sont définies dans le header `<float.h>` : 
- `FLT_MIN`
- `FLT_MAX` 
- `DBL_MIN`
- `DBL_MAX`
- ...

>[!WARNING]
> - Il est possible de convertir un flottant vers un entier, cela peut néanmoins entraîner une parte de précision. 
> - Les arrondis peuvent entraîner des erreurs à cause de leur représentation en binaire.

<u>Exemple :</u>  
```c
#include <stdio.h>

int main( ){
   float var = 14.5f;
   double val = 14.2;
}
```

>[!TIP]
> Par défaut, les flottant sont de type `double` alors c'est pour cette raison que si il est de type `float` on ajoute un `f` à la fin.

# Caster une variable en C
Le terme **“==caster== une variable”** ça veut dire convertir un type de variable en un autre. On utilise ainsi la syntaxe suivante en langage C.
```
(type_var) var
```

<u>Exemple :</u>  
```c
#include <stdio.h>

int main() {
    double x = 5.8;
    int y;

    y = (int) x;  // cast explicite de double vers int

    printf("x = %f\n", x);
    printf("y = %d\n", y);

    return 0;
}
```
```
x = 5.8
y = 5
```
# Portée des variables

La **portée des variables** en `C` *(aussi appelée scope)*, c’est la partie du programme dans laquelle une variable est accessible *(où tu peux l'utiliser)*. Il y a plusieurs types de portée selon où et comment tu déclares ta variable.

## Variable locale

C'est la déclaration **à l'intérieur d'un bloc**. Dans ce cas la variable est dite **LOCALE** et est accessible <u>uniquement</u> dans ce même bloc.

<u>Exemple :</u>  
```c
void maFonction() {
    int x = 5; // portée locale
    printf("%d\n", x); // Pas d'erreur ici
}
printf("%d\n", x); // ❌ Erreur, x n'est pas visible ici
```

## Variable globale

Déclaration en **dehors de toute fonction**, elle est appelée variable **GLOBALE** et est accessible <u>partout dans le fichier</u>.

<u>Exemple :</u>  
```c
int y = 10; // portée globale

void afficher() {
    printf("%d\n", y); // OK
}
```

>[!TIP]
>On peut aussi avoir accès à une variable globale **partout** dans d'autres fichiers en l'exportant avec `extern`.

###### Exemple d'export de variable globale dans d'autres fichiers

- Fichier : `fichier1.c`
```c
int compteur = 0;  // Définition de la variable globale
...
```

- Fichier : `fichier2.c`
```c
extern int compteur;  // Déclaration : "Je sais qu'elle est définie ailleurs"
...
```

# Retour sur `printf( )`...

Je ne sais pas si tu as remarqué mais quand on veut afficher la taille ou la valeur d'une variable par exemple, on précise à l'intérieur de `printf` ce qu'on appelle le **format**. En gros, on dit qu'on souhaite afficher la valeur d'une certaine variable dans un certain format.

On utilise le caractère `%` pour chaque variable suivit de l'initiale associé au format dans lequel on souhaite afficher la variable.

On considère deux variables que l'on souhaite afficher dans un format bien précis alors de manière générale, on utilisera `printf` comme suit : 

```
printf("message %format1 ... %format2", var1, var2);
```

<u>Exemple :</u>  
On souhaite afficher la valeur entière, puis caractère d'une variable. Ainsi on codera : 
```c
#include <stdio.h>

int main( ){
   char lettre = "A";
   printf("Format entier : %d et format caractère : %c.", lettre, lettre);
   return 0;
} 
```
```
Format entier : 65 et format caractère A.
```

***Tableau des principaux formats valides***

| Format | Type de l'argument affiché | Format d'affichage | Exemple |
| :---: | --- | --- | --- |
| `%c` | caractère | ASCII | a G u |
| `%hd` <br> `%hu` <br> `%hX` | entier `short int` (ou caractère) **signé** <br> entier `short int` (ou caractère) **non signé** <br> Affichage en hexadécimal | Base 10 <br> Base 10 <br> Base 16 (hexa) | $-12$ <br> $463$ <br> 90AF |
| `%ld` <br> `%lu` <br> `%lX` | entier `long int` **signé** <br> entier `long int` **non signé** <br> entier `long int` en hexadécimal | Base 10 <br> Base 10 <br> Base 16 (hexa) | $-1289$ <br> $46399$ <br> B4E98A0F |
| `%d`<br> `%X` | entier `int` <br> `int` en hexadécimal | Base 10 <br> Base 16 | $-546$ <br> 9A0F |
| `%le` <br> `%lf` | réel double précision `double` | | $-3.195874$ <br> $-45e-7$ |
| `%e` <br> `%f` | réel simple précision `float` | | $-3.195874$ <br> $-45e-7$ |
| `%s` | chaine de caractères | | Hello world |

Il est aussi possible d'ajouter des options entre `%` et la lettre qui définit le format.

- Ajouter un entier qui précise sur combien de caractère est affiché la variable. Par exemple, si on souhaite afficher une variable entière sur 5 caractère on utilisera le format `%5d`.

>[!WARNING]
> Le texte est aligné automatiquement à droite, alors lorsque la variable s'affiche sur plus de caractère, le nombre fournit est ignoré.

<u>Exemple :</u>  
```c
#include <stdio.h>

int main()
{
    int n = 4;
    printf("Le nombre n vaut %6d et voilà.", n);
    return 0;
}
```
```
Le nombre n vaut      4 et voilà.
```

- Pour aligner à gauche en utilise le signe `-`. 

<u>Exemple :</u>  
```c
#include <stdio.h>

int main()
{
    int n = 4;
    printf("Le nombre n vaut %-6d et voilà.", n);
    return 0;
}
```
```
Le nombre n vaut 4      et voilà.
```

- On peut ajouter deux nombres séparés par un point `.` très utilise sur les réels pour spécifier sur combien de caractère il est affiché puis sa précision.
   
   ```
   %nbChar.precisionFORMAT
   ```

<u>Exemple :</u>  
On souhaite afficher le nombre $12.874$ sur 10 caractères avec une précision après la virgule de 2.
```c
#include <stdio.h>

int main()
{
    int n = 12.874;
    printf("Le nombre n vaut %10.2lf et voilà.", n);
    return 0;
}
```
```
Le nombre n vaut 12.87      et voilà.
```

Il existe aussi des constantes caractères permettant d'effectuer un sout de ligne par exemple.

| constante caractère | signification         |
| :-----------------: | --------------------- |
|        `\n`         | saut de ligne         |
|        `\t`         | tabulation            |
|        `\r`         | retour chariot        |
|        `\f`         | saut de page          |
|        `\'`         | apostrophe            |
|        `\?`         | point d'interrogation |

# Les constantes
Justement et si on parlait des constantes en programmation `C`.

## Généralités
En `C` une constante représente une donnée dont la valeur ne peux pas changer après sa définition. Contrairement aux variables, les constantes garantissent que leur valeur ne changera pas tout au long du programme. <br>
Il existe deux manières de déclarer des constantes : 

- Avec le mot clé `const`
- Avec la directive préprocesseur `#define`

On utilise les constantes pour une meilleure lisibilité, maintenabilité du code et sécurité puisqu'elle empêche la modification de la valeur.

## Initialiser une constante

### En utilisant le mot clé `const`

```c
const int TEINTE = 14;

TEINTE = 130; // Erreur : on ne peut pas modifier une constante
```

- Toute modification impliquera une erreur de compilation
- **La constante doit être initialisée pendant sa déclaration**

   ```c
   const int VITESSE;
   VITESSE = 140; 

   // Erreur à la compilation
   ```

### Avec `#define`

```c
#define PI 3.14159
```
- Dans notre exemple `PI` est une constante symbolique.
- Le préprocesseur remplace chaque occurrence de `PI` par 3.14159 dans le programme.
- Pas de type directement associé *(attention aux erreurs)*

### Quelques conseil

>📌 Voici quelques petits conseils sur l'utilisation des méthodes pour définir et initialiser une constante : 
>
> - Utilisez `const` pour des constantes typées.
> - Utilisez `#define` pour des macros, ou des constantes globales *(valeur fixe, configuration, ...)*

## Les constantes prédéfinies 

Il existe évidemment de multiples constantes prédéfinies, on en a vu quelques unes comme `FLT_MIN` et `FLT_MAX` dans l'entête `<float.h>`.

# Suivant 
- Cours suivant : [[03 - Opérateurs & Arithmétique]]
