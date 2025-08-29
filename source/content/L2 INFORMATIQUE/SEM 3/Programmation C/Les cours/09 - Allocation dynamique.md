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
<style>
  body {
    font-family: system-ui, "Segoe UI", Arial, sans-serif;
    background: #fff;
    color: #111827;
    margin: 20px;
  }
  .container {
    position: relative;
    width: 1400px;
    height: 570px;
    user-select: none;
  }
  h1 {
    font-weight: 700;
    font-size: 28px;
    margin: 0 0 8px 30px;
    opacity: 0;
    animation: fadeUp 0.6s ease forwards;
    animation-delay: 0.1s;
  }
  .subtitle {
    font-weight: 500;
    font-size: 13px;
    color: #374151;
    margin-left: 30px;
    margin-bottom: 20px;
    opacity: 0;
    animation: fadeUp 0.6s ease forwards;
    animation-delay: 0.3s;
  }
  /* Boxes */
  .box {
    border-radius: 16px;
    border: 2px solid #111827;
    background: #fff;
    position: absolute;
    box-sizing: border-box;
    opacity: 0;
    transform: translateY(20px);
    animation: fadeUp 0.6s ease forwards;
  }
  .cpu {
    background: #fef3c7;
    width: 160px;
    height: 400px;
    left: 40px;
    top: 140px;
    animation-delay: 0.5s;
  }
  .cache {
    background: #e0f2fe;
    width: 220px;
    height: 60px;
    border-radius: 16px;
    border: 2px solid #111827;
    position: absolute;
  }
  /* Cadre englobant L1 */
  .l1-group {
    position: absolute;
    top: 195px; /* un peu au-dessus de L1i */
    left: 285px; /* un peu à gauche de L1i */
    width: 230px; /* un peu plus large que L1 caches */
    height: 130px; /* hauteur pour englober L1i + L1d + espace */
    border-radius: 20px;
    border: 2px solid #111827;
    background: transparent;
    opacity: 0;
    transform: translateY(20px);
    animation: fadeUp 0.6s ease forwards;
    animation-delay: 0.55s;
  }
  #l1i { top: 200px; left: 290px; animation-delay: 0.6s; }
  #l1d { top: 260px; left: 290px; animation-delay: 0.7s; }
  #l2 { top: 320px; left: 290px; animation-delay: 0.8s; }
  #l3 { top: 380px; left: 290px; animation-delay: 0.9s; }
  .ram {
    background: #e2e8f0;
    width: 260px;
    height: 160px;
    left: 590px;
    top: 210px;
    animation-delay: 1s;
  }
  .ssd {
    background: #f5f3ff;
    width: 260px;
    height: 100px;
    left: 590px;
    top: 390px;
    animation-delay: 1.1s;
  }
  /* Text inside boxes */
  .label {
    font-weight: 600;
    font-size: 16px;
    color: #111827;
    text-align: center;
    margin: 0;
    line-height: 1.2;
    opacity: 0;
    animation: fadeUp 0.5s ease forwards;
  }
  .small {
    font-weight: 500;
    font-size: 13px;
    color: #374151;
    text-align: center;
    margin: 0;
    margin-top: 4px;
    opacity: 0;
    animation: fadeUp 0.5s ease forwards;
  }
  /* CPU text */
  .cpu-text {
    position: absolute;
    width: 160px;
    left: 40px;
    top: 300px;
    text-align: center;
  }
  .cpu-text .label {
    animation-delay: 1.2s;
  }
  .cpu-text .small {
    animation-delay: 1.3s;
  }
  /* Cache text */
  /* Position text centered vertically and horizontally inside each cache box */
  .cache-text {
    position: absolute;
    width: 220px;
    left: 290px;
    color: #111827;
    font-size: 16px;
    font-weight: 600;
    text-align: center;
    opacity: 0;
    animation: fadeUp 0.5s ease forwards;
  }
  #l1i-text { top: 215px; animation-delay: 1.0s; }
  #l1d-text { top: 275px; animation-delay: 1.1s; }
  #l2-text { top: 335px; animation-delay: 1.2s; }
  #l3-text { top: 395px; animation-delay: 1.3s; }
  .cache-text .small {
    font-weight: 500;
    font-size: 13px;
    color: #374151;
    margin-top: 4px;
  }
  /* RAM text */
  .ram-text {
    position: absolute;
    width: 260px;
    left: 590px;
    top: 270px;
    text-align: center;
  }
  .ram-text p {
    opacity: 0;
    animation: fadeUp 0.5s ease forwards;
  }
  .ram-text p:nth-child(1) { animation-delay: 1.4s; }
  .ram-text p:nth-child(2) { animation-delay: 1.5s; }
  .ram-text p:nth-child(3) { animation-delay: 1.6s; }
  /* Storage text */
  .ssd-text {
    position: absolute;
    width: 260px;
    left: 590px;
    top: 420px;
    text-align: center;
  }
  .ssd-text p {
    opacity: 0;
    animation: fadeUp 0.5s ease forwards;
  }
  .ssd-text p:nth-child(1) { animation-delay: 1.7s; }
  .ssd-text p:nth-child(2) { animation-delay: 1.8s; }
  .ssd-text p:nth-child(3) { animation-delay: 1.9s; }
  /* Arrows container */
  svg.arrows {
    position: absolute;
    top: 0;
    left: 0;
    pointer-events: none;
  }
  /* Axis lines */
  svg.axis {
    position: absolute;
    top: 0;
    left: 0;
    pointer-events: none;
  }
  /* Axis text */
  .axis-text {
    font-weight: 500;
    font-size: 13px;
    fill: #374151;
  }
  /* Notes */
  .notes {
    font-weight: 500;
    font-size: 13px;
    color: #374151;
    margin-top: 20px;
    margin-left: 30px;
    width: 1340px;
    opacity: 0;
    animation: fadeUp 0.6s ease forwards;
    animation-delay: 2s;
  }
  /* Animations */
  @keyframes fadeUp {
    from {
      opacity: 0;
      transform: translateY(20px);
    }
    to {
      opacity: 1;
      transform: translateY(0);
    }
  }
  /* Animation for drawing lines */
  line {
    stroke-dasharray: 1000;
    stroke-dashoffset: 1000;
    animation: drawLine 1s ease forwards;
  }
  /* Different delays for each arrow line */
  svg.arrows line:nth-child(2) { animation-delay: 1.0s; }
  svg.arrows line:nth-child(3) { animation-delay: 1.1s; }
  svg.arrows line:nth-child(4) { animation-delay: 1.2s; }
  svg.arrows line:nth-child(5) { animation-delay: 1.3s; }
  svg.arrows line:nth-child(6) { animation-delay: 1.4s; }
  svg.arrows line:nth-child(7) { animation-delay: 1.5s; }
  svg.arrows line:nth-child(8) { animation-delay: 1.6s; }
  svg.arrows line:nth-child(9) { animation-delay: 1.7s; }
  svg.arrows line:nth-child(10) { animation-delay: 1.8s; }
  @keyframes drawLine {
    to {
      stroke-dashoffset: 0;
    }
  }
</style>
  <div class="container">
    <h1>Hiérarchie de la mémoire cache et du stockage</h1>
    <div class="subtitle">Plus près du CPU = plus rapide &amp; plus petite capacité • Plus loin = plus lent &amp; plus grande capacité</div>
    <!-- CPU box and text -->
    <div class="box cpu"></div>
    <div class="cpu-text" style="top: 300px; left: 40px;">
      <p class="label">CPU</p>
      <p class="small">Cœurs, unités d’exécution</p>
    </div>
    <!-- Cadre englobant L1 caches -->
    <div class="l1-group"></div>
    <!-- Cache boxes -->
    <div id="l1i" class="box cache"></div>
    <div id="l1i-text" class="cache-text" style="left: 290px;">
      <p class="label">Cache L1i (instructions)</p>
      <p class="small">~32–64 KiB / cœur • ~1 ns</p>
    </div>
    <div id="l1d" class="box cache"></div>
    <div id="l1d-text" class="cache-text" style="left: 290px;">
      <p class="label">Cache L1d (données)</p>
      <p class="small">~32–64 KiB / cœur • ~1 ns</p>
    </div>
    <div id="l2" class="box cache"></div>
    <div id="l2-text" class="cache-text" style="left: 290px;">
      <p class="label">Cache L2</p>
      <p class="small">~256 KiB–2 MiB / cœur • ~3–5 ns</p>
    </div>
    <div id="l3" class="box cache"></div>
    <div id="l3-text" class="cache-text" style="left: 290px;">
      <p class="label">Cache L3 (partagé)</p>
      <p class="small">~4–64 MiB • ~10–20 ns</p>
    </div>
    <!-- RAM box and text -->
    <div class="box ram"></div>
    <div class="ram-text">
      <p class="label">Mémoire principale (RAM)</p>
      <p class="small">DRAM • GiB–centaines de GiB</p>
      <p class="small">~50–100 ns • Débit élevé</p>
    </div>
    <!-- Storage box and text -->
    <div class="box ssd"></div>
    <div class="ssd-text">
      <p class="label">Stockage (SSD / HDD)</p>
      <p class="small">Non volatile • To</p>
      <p class="small">SSD : ~10–100 µs • HDD : ~1–10 ms</p>
    </div>
    <!-- SVG for arrows -->
    <svg class="arrows" width="1400" height="570" xmlns="http://www.w3.org/2000/svg" style="position:absolute; top:0; left:0;">
      <defs>
        <marker id="arrowhead" markerWidth="10" markerHeight="10" refX="8" refY="3" orient="auto" markerUnits="strokeWidth">
          <path d="M0,0 L8,3 L0,6 Z" fill="#111827" />
        </marker>
      </defs>
      <!-- Arrows from CPU to caches -->
      <line x1="200" y1="230" x2="290" y2="230" stroke="#111827" stroke-width="2" marker-end="url(#arrowhead)" />
      <line x1="200" y1="290" x2="290" y2="290" stroke="#111827" stroke-width="2" marker-end="url(#arrowhead)" />
      <line x1="200" y1="350" x2="290" y2="350" stroke="#111827" stroke-width="2" marker-end="url(#arrowhead)" />
      <line x1="200" y1="410" x2="290" y2="410" stroke="#111827" stroke-width="2" marker-end="url(#arrowhead)" />
      <!-- Arrows from caches to RAM -->
      <line x1="510" y1="230" x2="590" y2="230" stroke="#111827" stroke-width="2" marker-end="url(#arrowhead)" />
      <line x1="510" y1="290" x2="590" y2="290" stroke="#111827" stroke-width="2" marker-end="url(#arrowhead)" />
      <line x1="510" y1="350" x2="590" y2="350" stroke="#111827" stroke-width="2" marker-end="url(#arrowhead)" />
      <line x1="510" y1="410" x2="590" y2="410" stroke="#111827" stroke-width="2" marker-end="url(#arrowhead)" />
      <!-- Arrow from RAM to Storage -->
      <line x1="720" y1="370" x2="720" y2="390" stroke="#111827" stroke-width="2" marker-end="url(#arrowhead)" />
    </svg>
    <!-- SVG for axes -->
    <svg class="axis" width="1400" height="570" xmlns="http://www.w3.org/2000/svg" style="position:absolute; top:0; left:0;">
      <!-- Vertical axis -->
      <line x1="260" y1="140" x2="260" y2="530" stroke="#6b7280" stroke-width="1" stroke-dasharray="5 6" />
      <text x="220" y="160" fill="#374151" font-weight="500" font-size="13" transform="rotate(-90 250 160)">Latence ↑</text>
      <!-- Horizontal axis -->
      <line x1="280" y1="530" x2="900" y2="530" stroke="#6b7280" stroke-width="1" stroke-dasharray="5 6" />
      <text x="890" y="525" fill="#374151" font-weight="500" font-size="13" text-anchor="end">Capacité ↑</text>
    </svg>
    <!-- Notes -->
    <p class="notes">
      Remarque : tailles et latences indicatives, variables selon l’architecture. Les caches L1/L2 sont par cœur, L3 est généralement partagé.
    </p>
  </div>
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