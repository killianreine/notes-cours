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

![[memoireCASH.svg]]

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
<div style="display: flex; gap: 20px; align-items: flex-start; font-family: Arial, sans-serif;">
  <!-- Schéma de la pile à gauche -->
  <div>
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
  <!-- Texte explicatif à droite -->
  <div style="max-width: 500px; line-height: 1.5;">
    En fait, lorsqu'une fonction est appelée le cadre créé est <strong>empilé (push)</strong> sur la pile, et à la sortie de cette dernière le cadre est <strong>dépilé (pop)</strong> libérant ainsi automatiquement la mémoire.<br/><br/>
    
    Il y a quand même quelques inconvénients car la pile possède une <strong>taille limitée</strong>, risque donc d'un <span class="error-inline">stack overflow</span> si trop d'appels imbriqués ou alors des données en trop grande quantité (tableaux trop grands par ex.).
  </div>
</div>
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
</div>
