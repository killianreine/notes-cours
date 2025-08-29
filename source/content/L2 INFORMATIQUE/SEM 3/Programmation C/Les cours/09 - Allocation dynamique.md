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
<svg class="diagram" viewBox="0 0 1400 570" xmlns="http://www.w3.org/2000/svg">
  <defs>
    <marker id="mEnd" markerWidth="10" markerHeight="10" refX="8" refY="3" orient="auto">
      <path d="M0,0 L8,3 L0,6 Z"/>
    </marker>
  </defs>
  <!-- Titre -->
  <text x="30" y="40" class="title">Hiérarchie de la mémoire cache et du stockage</text>
  <text x="30" y="68" class="small">Plus près du CPU = plus rapide & plus petite capacité • Plus loin = plus lent & plus grande capacité</text>
  <!-- CPU -->
  <rect x="40" y="140" width="160" height="400" class="box cpu"/>
  <text x="120" y="300" text-anchor="middle" class="label">CPU</text>
  <text x="120" y="323" text-anchor="middle" class="small">Cœurs, unités d’exécution</text>
  <line x1="200" y1="230" x2="290" y2="230" class="arrow" marker-end="url(#mEnd)"/>
  <line x1="200" y1="290" x2="290" y2="290" class="arrow" marker-end="url(#mEnd)"/>
  <line x1="200" y1="350" x2="290" y2="350" class="arrow" marker-end="url(#mEnd)"/>
  <line x1="200" y1="410" x2="290" y2="410" class="arrow" marker-end="url(#mEnd)"/>
  <!-- Caches -->
  <rect x="290" y="200" width="220" height="60" class="box cache"/>
  <text x="400" y="225" text-anchor="middle" class="label">Cache L1i (instructions)</text>
  <text x="400" y="245" text-anchor="middle" class="small">~32–64 KiB / cœur • ~1 ns</text>
  <rect x="290" y="260" width="220" height="60" class="box cache"/>
  <text x="400" y="285" text-anchor="middle" class="label">Cache L1d (données)</text>
  <text x="400" y="305" text-anchor="middle" class="small">~32–64 KiB / cœur • ~1 ns</text>
  <rect x="290" y="320" width="220" height="60" class="box cache"/>
  <text x="400" y="345" text-anchor="middle" class="label">Cache L2</text>
  <text x="400" y="365" text-anchor="middle" class="small">~256 KiB–2 MiB / cœur • ~3–5 ns</text>
  <rect x="290" y="380" width="220" height="60" class="box cache"/>
  <text x="400" y="405" text-anchor="middle" class="label">Cache L3 (partagé)</text>
  <text x="400" y="425" text-anchor="middle" class="small">~4–64 MiB • ~10–20 ns</text>
  <!-- RAM -->
  <line x1="510" y1="230" x2="590" y2="230" class="arrow" marker-end="url(#mEnd)"/>
  <line x1="510" y1="290" x2="590" y2="290" class="arrow" marker-end="url(#mEnd)"/>
  <line x1="510" y1="350" x2="590" y2="350" class="arrow" marker-end="url(#mEnd)"/>
  <line x1="510" y1="410" x2="590" y2="410" class="arrow" marker-end="url(#mEnd)"/>
  <rect x="590" y="210" width="260" height="160" class="box ram"/>
  <text x="720" y="270" text-anchor="middle" class="label">Mémoire principale (RAM)</text>
  <text x="720" y="293" text-anchor="middle" class="small">DRAM • GiB–centaines de GiB</text>
  <text x="720" y="316" text-anchor="middle" class="small">~50–100 ns • Débit élevé</text>
  <!-- Stockage -->
  <line x1="720" y1="370" x2="720" y2="390" class="arrow" marker-end="url(#mEnd)"/>
  <rect x="590" y="390" width="260" height="100" class="box ssd"/>
  <text x="720" y="420" text-anchor="middle" class="label">Stockage (SSD / HDD)</text>
  <text x="720" y="443" text-anchor="middle" class="small">Non volatile • To</text>
  <text x="720" y="463" text-anchor="middle" class="small">SSD : ~10–100 µs • HDD : ~1–10 ms</text>
  <!-- Axes indicatifs -->
  <line x1="260" y1="140" x2="260" y2="530" class="axis"/>
  <text x="220" y="160" class="small" transform="rotate(-90,250,160)">Latence ↑</text>
  <line x1="280" y1="530" x2="900" y2="530" class="axis"/>
  <text x="890" y="525" class="small" text-anchor="end">Capacité ↑</text>
  <!-- Notes -->
  <text x="30" y="563" class="small">
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