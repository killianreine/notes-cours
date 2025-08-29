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