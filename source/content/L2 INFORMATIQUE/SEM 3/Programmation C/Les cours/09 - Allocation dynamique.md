# La mémoire
## Introduction
La mémoire est un élément fondamental pour tout système informatique. Elle permet de **stocker** et de **récupérer** et de **restituer** des données ainsi que des instructions nécessaire à l'exécution des programmes. Sans elle, le processeur *(CPU)* ne pourrait pas traiter les informations ni exécuter les programmes efficacement.  
La mémoire est un composant essentiel, présent dans les ordinateurs, consoles, GPS et autres.  
On différencie plusieurs types de mémoires dans un ordinateur, organisées de façon hiérarchique selon leur vitesse, leur coût et leur capacité.

## Types de mémoires
### La mémoire vive RAM
La **==mémoire vive RAM==** *Randam-Access Memory* est l’espace de stockage temporaire où un appareil informatique enregistre, de façon volatile, les données en cours de traitement.

>[!cite] Définition
>En informatique, **==volatile==** signifie que les données stockées disparaissent dès que l’appareil est éteint ou redémarré.

Elle permet de stocker les données temporaires et les programmes **en cours d'exécution**. L'accès au contenu dans la mémoire est rapide mais limité en taille.

### La mémoire morte ROM
La **==mémoire morte ROM==** *Read-Only Monitor* est une mémoire **non volatile** c'est à dire que les données stockées ne disparaissent pas. Ces dernières sont définies lors de la programmation de la mémoire, c'est à dire pendant la fabrication. En fait, ces données peuvent être lues plusieurs fois par l'utilisateur mais ne peuvent pas être modifiées. Généralement c'est là où est contenu le **firmware** *(BIOS, UEFI)*.

>[!info] Remarque
>Le **firmware** est un logiciel intégré directement dans un composant matériel (comme une carte mère, une imprimante, un routeur ou un smartphone).
> - Il sert d’intermédiaire entre le matériel et les logiciels plus complexes : il contient les instructions de base nécessaires pour faire fonctionner l’appareil.  
> - Contrairement aux programmes classiques, le firmware est stocké dans une mémoire non volatile (ROM, EEPROM, ou flash), ce qui signifie qu’il reste présent même quand l’appareil est éteint.  
> - On peut parfois le **mettre à jour** pour corriger des bugs, améliorer les performances ou ajouter de nouvelles fonctionnalités.

### La mémoire cache
La **==mémoire cache==** *ou antémémoire* permet d'enregistrer temporairement des copies de données et instructions beaucoup utilisées. Cette dernière est très rapide car intégrée au processeur *CPU*. Elle possède plusieurs niveau : L1, L2 et L3.  

<div>
<svg id="MemMem" class="diagramMem" viewBox="0 0 1400 570" xmlns="http://www.w3.org/2000/svg">
  <defs>
    <marker id="mEndMem" markerWidth="15" markerHeight="15" refX="8" refY="3" orient="auto">
      <path d="M0,0 L8,3 L0,6 Z"/>
    </marker>
  </defs>
  <!-- Titre -->
  <text x="30" y="40" class="titleMem">Hiérarchie de la mémoire cache et du stockage</text>
  <text x="30" y="68" class="smallMem">Plus près du CPU = plus rapide & plus petite capacité • Plus loin = plus lent & plus grande capacité</text>
  <!-- CPU -->
  <rect x="40" y="140" width="160" height="400" class="boxMem cpuMem"/>
  <text x="120" y="300" text-anchor="middle" class="labelMem">CPU</text>
  <text x="120" y="323" text-anchor="middle" class="smallMem">Cœurs, unités d’exécution</text>
  <line x1="200" y1="230" x2="290" y2="230" class="arrowMem" marker-end="url(#mEndMem)"/>
  <line x1="200" y1="290" x2="290" y2="290" class="arrowMem" marker-end="url(#mEndMem)"/>
  <line x1="200" y1="350" x2="290" y2="350" class="arrowMem" marker-end="url(#mEndMem)"/>
  <line x1="200" y1="410" x2="290" y2="410" class="arrowMem" marker-end="url(#mEndMem)"/>
  <!-- Caches -->
  <rect x="290" y="200" width="220" height="60" class="boxMem cacheMem"/>
  <text x="400" y="225" text-anchor="middle" class="labelMem">Cache L1i (instructions)</text>
  <text x="400" y="245" text-anchor="middle" class="smallMem">~32–64 KiB / cœur • ~1 ns</text>
  <rect x="290" y="260" width="220" height="60" class="boxMem cacheMem"/>
  <text x="400" y="285" text-anchor="middle" class="labelMem">Cache L1d (données)</text>
  <text x="400" y="305" text-anchor="middle" class="smallMem">~32–64 KiB / cœur • ~1 ns</text>
  <rect x="290" y="320" width="220" height="60" class="boxMem cacheMem"/>
  <text x="400" y="345" text-anchor="middle" class="labelMem">Cache L2</text>
  <text x="400" y="365" text-anchor="middle" class="smallMem">~256 KiB–2 MiB / cœur • ~3–5 ns</text>
  <rect x="290" y="380" width="220" height="60" class="boxMem cacheMem"/>
  <text x="400" y="405" text-anchor="middle" class="labelMem">Cache L3 (partagé)</text>
  <text x="400" y="425" text-anchor="middle" class="smallMem">~4–64 MiB • ~10–20 ns</text>
  <!-- RAM -->
  <line x1="510" y1="230" x2="590" y2="230" class="arrowMem" marker-end="url(#mEndMem)"/>
  <line x1="510" y1="290" x2="590" y2="290" class="arrowMem" marker-end="url(#mEndMem)"/>
  <line x1="510" y1="350" x2="590" y2="350" class="arrowMem" marker-end="url(#mEndMem)"/>
  <line x1="510" y1="410" x2="590" y2="410" class="arrowMem" marker-end="url(#mEndMem)"/>
  <rect x="590" y="210" width="260" height="160" class="boxMem ramMem"/>
  <text x="720" y="270" text-anchor="middle" class="labelMem">Mémoire principale (RAM)</text>
  <text x="720" y="293" text-anchor="middle" class="smallMem">DRAM • GiB–centaines de GiB</text>
  <text x="720" y="316" text-anchor="middle" class="smallMem">~50–100 ns • Débit élevé</text>
  <!-- Stockage -->
  <line x1="720" y1="370" x2="720" y2="390" class="arrowMem" marker-end="url(#mEndMem)"/>
  <rect x="590" y="390" width="260" height="100" class="boxMem ssdMem"/>
  <text x="720" y="420" text-anchor="middle" class="labelMem">Stockage (SSD / HDD)</text>
  <text x="720" y="443" text-anchor="middle" class="smallMem">Non volatile • To</text>
  <text x="720" y="463" text-anchor="middle" class="smallMem">SSD : ~10–100 µs • HDD : ~1–10 ms</text>
  <!-- Axes indicatifs -->
  <line x1="260" y1="140" x2="260" y2="530" class="axisMem"/>
  <text x="220" y="160" class="smallMem" transform="rotate(-90,250,160)">Latence ↑</text>
  <line x1="280" y1="530" x2="900" y2="530" class="axisMem"/>
  <text x="890" y="525" class="smallMem" text-anchor="end">Capacité ↑</text>
  <!-- Notes -->
  <text x="30" y="563" class="smallMem">
    Remarque : tailles et latences indicatives, variables selon l’architecture. Les caches L1/L2 sont par cœur, L3 est généralement partagé.
  </text>
</svg>
</div>

- **Axe vertical (vers le haut, marqué "Latence ↑")**  
    → Plus on monte, plus la **latence** (temps d’accès) est faible.
    - Les caches L1 sont accessibles en ~1 ns.
    - La RAM demande ~50–100 ns.
    - Un SSD peut demander de 10–100 µs.
    - Un HDD peut prendre jusqu’à plusieurs ms.
- **Axe horizontal (vers la droite, marqué "Capacité ↑")**  
    → Plus on va vers la droite, plus la **capacité de stockage** est grande.
    - Les caches L1 ont seulement 32–64 KiB par cœur.
    - La L2 monte jusqu’à 2 MiB par cœur.
    - La L3 (partagée) peut aller jusqu’à quelques dizaines de MiB.
    - La RAM monte à plusieurs GiB.
    - Le stockage (SSD/HDD) atteint des To.
### Mémoire secondaire (stockage de masse)
Cela représente tous les disques durs, les clés USB, SSD, les supports externes qui ne sont pas volatile car ne perdent pas leur données même débranchées *(oue bon on repassera pour les clés USB, genre vous avez jamais perdus vos données...)*. Ces mémoires non volatiles restent tout de même moins rapide que la RAM.

# Allocations automatique et statique
Lors de la création d'une variable à l'intérieur d'une fonction, on avait vaguement expliqué que cette dernière est stockée dans un espace mémoire qui lui est allouée. Il faut savoir que jusqu'ici on distinguait deux types d'allocation de mémoire : **==automatique==** et **==statique==**. 
## Allocation automatique
L'**==allocation automatique==** est le mécanisme par lequel la mémoire est automatiquement réservée par le compilateur lorsqu'une fonction est appelée. Cette dernière concerne les variables locales et les paramètres de fonction en général.  
La mémoire est allouée sur la **pile** *stack* et est **libérée automatiquement** à la fin de l'exécution de la fonction. Ainsi l'espace mémoire est détruit à la sortie de la fonction donc n'existe plus en dehors de celle ci, c'est d'ailleurs pour cette raison que l'on ne peux pas retourner l'adresse d'une variable locale à une fonction.  
En dehors de la fonction, la variable n'existe plus, elle est "détruite". 

<u>Exemple :</u>  
```c
int* maFonction(){
	int var = 14;
	return &var;
}
```
```bash
warning: function returns address of local variable [-Wreturn-local-addr]
    6 |         return &var;
      |                ^~~~
```
Puisque la variable `var` est une variable locale, cette dernière n'existe qu'à l'intérieur de celle ci. Là vous renvoyez un pointeur vers quelque chose qui n'existe plus, on appelle cela un **pointeur pendu** *(dangling pointer)*. Le comportement du programme est donc indéfinit.

## Allocation statique
L'**==allocation statique==** consiste à réserver la mémoire lors de la compilation, c'est à dire avant l'exécution du programme. La taille et l'emplacement de cette mémoire sont connues à l'avance et ne changement pendant *toute la durée du programme !*  
Ce genre d'allocation est utilisée pour les variables globales, variables statiques et les constantes.  
La variable allouée de manière statique existe pendant toute la durée du programme, elle est créée une seule et unique fois et est réutilisée à chaque appel.  
Contrairement à une variable locale, l'adresse mémoire d'une variable statique peut donc être renvoyée. Cela permet de conserver l’état d’une variable entre les appels

<u>Exemple :</u>  
```c
int x = 14;

void increment(){
	static int x = 5; // alloc. statique avec portée locale
	x++;
	printf("%d\n", x);
}

int main(){
	fonction(); 
    fonction();
    return 0;
}
```
```
6
7
```

L'inconvénient majeur est que si on utilise plus la variable, elle occupe de la place en mémoire pour rien... 

# La pile et le tas
La mémoire d'un ordinateur est une succession d'octets *(8 bits)*, organisés les uns à le suite des autres et accessible via une adresse. En langage C *(et C++)*, la mémoire pour stocker des variables est organisée en $2$ catégories : **la pile *stack*** et **le tas *heap***. Dans la plupart des langages compilés la pile représente l'endroit ou est stocké les variables locales et les paramètres des fonctions. 
## La pile *stack*
La **==pile==** *(stack en anglais)* est la zone de la mémoire réservée ) l'**allocation automatique** des variables locales et des paramètres de fonctions. En fait, lors de l'appel d'une fonction, un **cadre** *stack frame* est créé pour stocker ses variables locales, paramètres et adresse de retour. Et, lorsque la fonction se termine, *le cadre est automatiquement détruit*. 

<div>
<style>
  .stack {
    position: relative;
    width: 200px;
    border: 2px solid #000;
    border-radius: 5px;
    background: #f0f0f0;
    padding: 10px 0;
     margin: 0px auto;
  }
  .stack::after {
    content: "Top";
    position: absolute;
    right: -50px;
    top: 10px;
    font-weight: bold;
  }
  .stack::before {
    content: "Bottom";
    position: absolute;
    right: -80px;
    bottom: 10px;
    font-weight: bold;
  }
  .frame {
    margin: 5px auto;
    width: 160px;
    border: 2px solid #000;
    border-radius: 4px;
    padding: 5px;
    text-align: center;
    transition: transform 0.2s, background-color 0.2s;
    cursor: pointer;
  }
  .frame:hover {
    transform: scale(1.05);
    background-color: #ffe0b3;
  }
  .func-name {
    font-weight: bold;
  }
  .frame-detail {
    font-size: 12px;
  }
  .funcC { background-color: #ffffcc; }
  .funcB { background-color: #ccccff; }
  .funcA { background-color: #ccffcc; }
  .main { background-color: #ffcccc; }
  /*Thème sombre...*/
  [saved-theme="dark"] .stack {
    position: relative;
    width: 200px;
    border: 2px solid #fff;
    border-radius: 5px;
    background: #1e1e1e;
    padding: 10px 0;
    margin: 0px auto;
  }
  [saved-theme="dark"] .stack::after {
    content: "Top";
    position: absolute;
    right: -50px;
    top: 10px;
    font-weight: bold;
    color: #fff;
  }
  [saved-theme="dark"] .stack::before {
    content: "Bottom";
    position: absolute;
    right: -80px;
    bottom: 10px;
    font-weight: bold;
    color: #fff;
  }
  [saved-theme="dark"] .frame {
    margin: 5px auto;
    width: 160px;
    border: 2px solid #fff;
    border-radius: 4px;
    padding: 5px;
    text-align: center;
    transition: transform 0.2s, background-color 0.2s;
    cursor: pointer;
    color: #fff;
  }
  [saved-theme="dark"] .frame:hover {
    transform: scale(1.05);
    background-color: #555555;
  }
  [saved-theme="dark"] .func-name {
    font-weight: bold;
  }
  [saved-theme="dark"] .frame-detail {
    font-size: 12px;
  }
  [saved-theme="dark"] .funcC { background-color: #666633; }
  [saved-theme="dark"] .funcB { background-color: #333366; }
  [saved-theme="dark"] .funcA { background-color: #336633; }
  [saved-theme="dark"] .main { background-color: #663333; }
</style>
<div class="stack">
  <div class="frame funcC">
    <div class="func-name">fonction3()</div>
    <div class="frame-detail">Paramètres <br/> Variables locales</div>
    <div class="frame-detail">Adresse de retour</div>
  </div>
  <div class="frame funcB">
    <div class="func-name">fonction2()</div>
    <div class="frame-detail">Paramètres <br/> Variables locales</div>
    <div class="frame-detail">Adresse de retour</div>
  </div>
  <div class="frame funcA">
    <div class="func-name">fonction1()</div>
    <div class="frame-detail">Paramètres <br/> Variables locales</div>
    <div class="frame-detail">Adresse de retour</div>
  </div>
  <div class="frame main">
    <div class="func-name">main()</div>
    <div class="frame-detail">Paramètres <br/> Variables locales</div>
    <div class="frame-detail">Adresse de retour</div>
  </div>
</div>
</div>

En fait, lorsqu'une fonction est appelée le cadre créé est **empilé** *(push)* sur la pile, et à la sortie de cette dernière le cadre est **dépilé** *(pop)* libérant ainsi automatiquement la mémoire.

Il y a quand même quelques inconvénient car la pile possède une **taille limitée**, risque donc d'un <span class="error-inline">stack overflow</span> si trop d'appels imbriqués ou alors des données en trop grosse quantités *(tableaux trop grand par ex.)*.

Il faut savoir que la pile est basée sur le principe **LIFO** *Last In First Out* autrement dit Dernier arrivé premier sorti. On peut la voir comme une pile d'assiettes où l'on peut empiler/dépiler une seule assiette à la fois et ces dernières peuvent être de tailles différentes.  
Dépiler = effacer de la mémoire !

## Les tas *heap*
Le **==tas==** *(heap en anglais)* quant à lui c'est la zone mémoire utilisée pour l'allocation dynamique, en gros pour la mémoire dont la taille et la durée de vie sont décidées à l'exécution du programme. Contrairement à la pile, **la mémoire allouée doit être libérée <b><u>manuellement</u></b> par le programmeur**. *La mémoire peut être libérée par un "ramasse miette" dans certains langage comme Java*.  
Le fonctionnement du tas est bien différent de celui de la pile :
- Lorsqu'on demande de la mémoire dynamique *(avec `malloc` en C qu'on verra dans un instant)* le système va alors réserver un bloc dans le tas.
- La mémoire **reste allouée tant que le programme ne la libère pas !**
- La libération se fait avec une certaine instruction ou alors via le ramasse miette *(garbage collector en anglais)* dans d'autres langages.

>[!warning]
>L'accès au tas reste néanmoins plus lent que pour la pile car c'est **une structure moins structurée**. Il faut gérer manuellement et faire particulièrement attention au <span class="error-inline">Buffer Overflow</span> *dépassement/fuite de mémoire* mais aussi à la fragmentation...

>[!info] Remarque
>```bash
>$ ulimit -a
>```
>Permet de visualiser facilement les valeurs de tailles de la pile et du tas.
>```
>data seg size            (kbytes, -d)  unlimited
>...
>stack size               (kbytes, -s)  8192
>```
>Ici la pile est limitée à environ $8Mo$ et peut provoquer des <span class="error-inline">Segmentation Fault</span> en cas de dépassement.

# Allocation dynamique en C
## Réserver une zone mémoire
### La fonction `malloc`
En programmation C, la fonction `malloc` permet d'allouer dynamiquement un bloc mémoire d'une certaine taille *(en octets)* pendant l'exécution du programme. Cette dernière provient de la bibliothèque `<stdlib.h>`.

Voici le prototype de la fonction : 
```c
#include <stdlib.h>
void* malloc(size_t size);
```
- Elle prend en paramètre une taille `size` qui correspond à la taille à allouée en octets.
- Elle retourne un pointeurs vers le bloc alloué.

>[!info] Remarque
>Si `malloc` échoue, elle renverra `NULL`.

Comme `malloc` renvoie un `void *`, il est nécessaire de **caster** le pointeur vers le type voulu. C'était l'objet d'une partie de cours qui remonte à loin oui... [[02 - Premiers pas#Caster une variable en C]].  
C'est lorsque l'on utilisait :
```
(type_var) var;
```

<u>Exemple :</u>  
On souhaite caster `void*` en `int*` pout allouer un espace mémoire pour un entier.
```c
int *p:
p = (int *) malloc(sizeof(int));
```

On peut ensuite manipuler cette entier l'afficher et lui donner une variable. Il est aussi utile de savoir si l'allocation a fonctionnée dans le cas contraire cela permettrait de renvoyer une erreur et de terminer le programme.  
On a dit que si `malloc` échouait il renvoyait `NULL` alors c'est ceci qu'il faut tester pour savoir si l'allocation s'est bien déroulée.
```c
if (p == NULL){
	printf("Erreur d'allocation");
	return 1;
}
```

L'exemple complet en donnant par la suite la valeur $42$ à la mémoire est donné par : 
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p;

    p = (int *)malloc(sizeof(int)); // alloue un entier

    if (p == NULL) {
        printf("Allocation mémoire échouée.\n");
        return 1;
    }

    *p = 42; // utilisation de la mémoire
    printf("%d\n", *p);

    free(p); // libération de la mémoire
    return 0;
}
```
```
42
```

<u>Exemple :</u>  
On souhaite allouer une zone mémoire pour un mot de $7$ caractères plus le marqueur de fin de chaine `\0`.
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *p;

    p = (char *)malloc(8*sizeof(char));

    if (p == NULL) {
        printf("Allocation mémoire échouée.\n");
        return 1;
    }

    strcpy(p, "Bonjour"); // utilisation de la mémoire
    printf("%s\n", p);    // affichage du mot stocké

    free(p); // libération de la mémoire
    return 0;
}
```
En fait en utilisant : 
```c
(char *)malloc(8*sizeof(char));
```
On alloue une zone mémoire permettant de stocker au plus 7 caractères ainsi que le marqueur de fin de chaîne `\0`. Ensuite on l'utilise avec `strcpy()` de la bibliothèque `<string.h>` on l'affiche et on libère la zone mémoire grâce à `free`.

### La fonction `calloc`
La fonction `calloc` (*contiguous allocation en anglais*) sert à allouer de la mémoire dynamiquement comme `malloc`,  
mais avec deux différences :
- Elle prend **deux arguments** (nombre d’éléments, taille de chaque élément).
- Elle **initialise** la mémoire allouée à **0** (contrairement à `malloc` qui laisse des valeurs indéfinies).

Le prototype de la fonction est le suivant :
```c
#include <stdlib.h>
void *calloc(size_t n, size_t size);
```
- `n` le nombre d'éléments
- `size` la taille en octet de chaque éléments
- Elle retourne un pointeur vers la mémoire allouée ou alors `NULL` si elle échoue.

<u>Exemple :</u>  
```c
char *p = (char*)malloc(8*sizeof(char));
```
La mémoire **n’est pas initialisée**, elle contient des **valeurs aléatoires**.  
Alors que :
```c
char *p = (char*)calloc(8, sizeof(char));
```
- Alloue **8 octets** aussi (8 × taille d’un char).
- Mais **initialise tous les octets à 0**.

>[!tip]
>- Utilise `malloc` si tu vas **remplir toi-même** la mémoire immédiatement.
>- Utilise `calloc` si tu veux **des zéros par défaut**, comme pour un tableau de `char` ou un tableau d’entiers.

|Caractéristique|`malloc(8*sizeof(char))`|`calloc(8, sizeof(char))`|
|---|---|---|
|Taille allouée|8 octets|8 octets|
|Initialisation|Non (valeurs indéterminées)|Oui (tous les octets à 0)|
|Arguments|1 (taille totale)|2 (nombre d’éléments, taille)|
|Vitesse|Légèrement plus rapide|Légèrement plus lent (initialisation)|
## Libérer la mémoire
**Pourquoi libérer la mémoire ?**  
Quand on utilise `malloc`, `calloc` ou `realloc`, la mémoire est réservée dans le **tas** *(heap)*.  
Cette mémoire **n’est pas libérée automatiquement** quand la variable sort de portée c'est à dire que si on ne la libère pas, on crée une **fuite mémoire**. 

Pour se faire on utilise la fonction `free` dont le prototype est le suivant :
```c
#include <stdlib.h>
void free(void *ptr);
```
- Elle prend en paramètre le pointeur vers le bloc alloué avec  `malloc`, `calloc` et `realloc`
- La fonction `free` comme son nom l'indique, elle rend la mémoire allouée précédemment au système.
Après avoir libéré le pointeur, ce dernier devient *dangling pointeur* en gros il pointe vers une zone invalide.

**Bonnes pratiques**  
- ✅ Toujours faire `free()` pour chaque `malloc()`.
- ✅ Remettre le pointeur à `NULL` après `free`.
  ```c
	free(p);
	p = NULL; // empêche l'accès accidentil 
    ```
- ✅ Ne **jamais** faire `free()` deux fois sur le même pointeur (`double free` = erreur grave). 
- ✅ Ne pas utiliser la mémoire après `free` (*dangling pointer*).

Vous pouvez remonter un peu pour reprendre l'exemple de l'allocation d'un espace mémoire pour un entier pour voir la libération.

### Utiliser la mémoire après libération
Quand tu appelles `free(ptr)` :

- Le bloc mémoire est **marqué comme libre** et remis au système (ou à l’allocateur mémoire).
- Mais le **contenu n’est pas effacé immédiatement** → les anciennes valeurs peuvent rester temporairement.
- Le pointeur `ptr` devient **dangling** (*dangling pointer* = il pointe vers un espace qui n’est plus à toi).
Donc, si tu accèdes à `*ptr` après `free(ptr)`, le comportement est **indéfini** (UB = Undefined Behavior).  
Cela peut donner :
- des données "fantômes" (anciennes valeurs encore visibles),
- un crash (<span class="error-inline">segmentation fault</span>),
- ou même des résultats différents d’une exécution à l’autre.

<u>Exemple :</u>
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = (int *)malloc(sizeof(int));
    *p = 99;

    free(p);  // libération

    // Mauvais ! utilisation après free
    printf("%d\n", *p);  

    return 0;
}
```
```
204563
```
Ici il sort une valeur indéfinie qui sera différente à chaque exécution.

### Libérer deux fois la même zone
C’est ce qu’on appelle un **double free**.
```c
int *p = malloc(sizeof(int));
free(p);   // ✅ correct
free(p);   // ❌ double free → comportement indéfini
```
- La première fois : `p` est libéré correctement.
- La deuxième fois : `p` pointe toujours vers la même adresse, mais cette mémoire **n’appartient plus au programme** → donc **comportement indéfini**.
Résultats possibles :
- Plantage immédiat (<span class="error-inline">segmentation fault</span>).
- Plantage plus tard dans le programme.
- Rien (silencieux) mais corruption mémoire cachée → le pire, car difficile à déboguer...

>[!info] Remarque
>Le fait de mettre le pointeur à `NULL` après la libération fait que si on libère deux fois la même zone, cela n'aura aucun effet.

## Allocation d'un tableau
Bon en fait allouer un tableau vous savez le faire, on l'a même comparé avec `malloc` et `calloc`. En fait lorsqu'on utilise `malloc` pour allouer un tableau à `n` éléments.  
Si `malloc(sizeof(int))` alloue la mémoire pour un seul entier alors si je multiplie cette taille par `n`, on va allouer la taille pour un tableau de `n` entiers.
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5; // taille du tableau
    int *tab;

    // Allocation dynamique d'un tableau à 5 éléments
    tab = (int *)malloc(n * sizeof(int));

    if (tab == NULL) {
        printf("Erreur d'allocation.\n");
        return 1;
    }

    // Remplissage du tableau
    for (int i = 0; i < n; i++) {
        tab[i] = i * 10;
    }

    // Affichage
    for (int i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    free(tab); // Libération de la mémoire
    tab = NULL;

    return 0;
}
```
```
0 10 20 30 40 
```

>[!tip]
>Les deux instructions suivantes sont équivalentes :
>```c
>if(tab==NULL){ ... };
>```
>```c
>if(!tab){ ... };
>```

## Allocation d'une matrice
Supposons que l’on veut une matrice `m x n` (m lignes, n colonnes) d’entiers.  
On a vu juste avant que pour allouer l'espace mémoire pour  un tableau de `m` valeurs  il suffisait d'écrire :
```c
int *tab = (int*)malloc(m*sizeof(int));
```
Et, on sait qu'une matrice $m \times n$ représente simplement un tableau de $m$ éléments qui sont eux même des tableaux de $n$ éléments. Alors pour allouer l'espace mémoire d'une matrice il faut le faire en deux étapes :
- Allouer les $m$ lignes de la matrices.
- Pour chaque ligne créée, lui allouée individuellement un tableau de $n$ éléments.
Ainsi on se retrouve avec ce pseudo code :
```
allouer un tableau de m éléments
Pour chaque élément de ce tableau
	allouer un tableau de n éléments
```
En langage C, on utilise ainsi $n+1$ fois malloc :
```c
// Allouer les m lignes du tableau : 
int *tab = (int*)malloc(m*sizeof(int));

// Pour chaque éléments du tableau, allouer un tableau de n éléments
for(int i = 0; i<m; i++){
	tab[i] = (int*)malloc(n*sizeof(int));
}
```

>[!tip] 
>Pensez à vérifier que chaque allocation mémoire s'est bien passée.

<u>Exemple complet :</u>  
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int m = 3, n = 4;
    int **mat;
    
    // Allocation du tableau de pointeurs pour les lignes
    mat = (int **)malloc(m * sizeof(int *));
    if (!mat) {
        printf("Erreur d'allocation\n");
        return 1;
    }

    // Allocation de chaque ligne
    for (int i = 0; i < m; i++) {
        mat[i] = (int *)malloc(n * sizeof(int));
        if (!mat[i]) {
            printf("Erreur d'allocation ligne %d\n", i);
            return 1;
        }
    }
    
    // Remplissage et utilisation de la matrice
    
    // Libération de la mémoire
    for (int i = 0; i < m; i++)
        free(mat[i]);
    free(mat);
    
    mat=NULL;

    return 0;
}
```
Pour libérer la matrice, il faut commencer par libérer les sous tableaux avant de libérer le tableau global.
- Si tu `free(mat)` **avant** *(libère la matrice globale)*, tu détruis la “tablette de pointeurs” → plus de moyen de retrouver les lignes.
- Donc il faut **libérer les blocs pointés** avant le tableau de pointeurs lui-même.

# Réallouer la mémoire
`realloc` permet de **modifier la taille d’un bloc mémoire déjà alloué**.
- On peut **agrandir** ou **réduire** le bloc.
- Si la nouvelle taille est plus grande, le contenu existant est **préservé**, mais la mémoire supplémentaire n’est **pas initialisée**.

Prototype de la fonction `realloc`
```c
#include <stdlib.h>
void *realloc(void *ptr, size_t new_size);
```
- `ptr` : pointeur vers un bloc déjà alloué avec `malloc`, `calloc` ou `realloc`.
- `new_size` : nouvelle taille en octets.
- Retourne le pointeur vers le nouveau bloc, ou `NULL` si échec.

<u>Exemple :</u>  
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *tab = (int *)malloc(3 * sizeof(int));

    if (!tab) return 1;

    tab[0] = 1; tab[1] = 2; tab[2] = 3;

    // Agrandir le tableau à 5 éléments
    int *temp = (int *)realloc(tab, 5 * sizeof(int));
    if (!temp) {
        printf("Erreur de réallocation\n");
        free(tab);  // libérer l'ancien bloc
        return 1;
    }
    tab = temp;

    tab[3] = 4; tab[4] = 5;

    for (int i = 0; i < 5; i++)
        printf("%d ", tab[i]);
    printf("\n");

    free(tab);
    return 0;
}
```
```
1 2 3 4 5 
```

1. **Toujours utiliser un pointeur temporaire** pour `realloc` :
```c
int *temp = realloc(tab, new_size);
if (!temp) {
    // l'ancien tab est toujours valide
}
```
2. **Contenu existant préservé** : les premiers `min(old_size, new_size)` octets restent identiques.
3. **Nouvelles zones non initialisées** : si `new_size > old_size`, les nouvelles cases contiennent des valeurs indéterminées.
4. Si `ptr == NULL`, `realloc(ptr, size)` se comporte comme `malloc(size)`.
5. Si `new_size == 0`, `realloc` se comporte comme `free(ptr)` et retourne souvent `NULL`.