# Introduction
## Qu'est-ce qu'un fichier en informatique
Un **==fichier==** est une unité de stockage d'informations sur un support *(clé USB, disque dur, SSD, ...)*. Un fichier peut contenir plusieurs types de données : 
- **fichier texte**, lisible par un humain (comme les fichiers `.txt`)
- **fichiers binaires**, données codées, lisible par un programme (comme i, fichier `.exe` ou une image `.jpg`)

En langage C, on distingue donc deux formes de fichiers :
1. Les fichiers textes  
   Ils sont constitués de caractères, terminés par un caractère de fin de ligne `\n` en linux, `\r\n` sur Windows.
2. Les fichiers binaires  
   Les données sont enregistrées sous leur forme brute *(= non transformée en caractères)*

## Pourquoi utiliser des fichiers
Jusqu'à maintenant et comme expliqué dans le cours [[09 - Allocation dynamique]] lorsque vous écrivez un programme en C, les données comme les tableaux, les variables, les structures sont stockées dans la **mémoire vive** *(RAM)* et elle disparaissent dès que le programme se termine.  
Les fichiers permettraient alors de 
- **sauvegarder des données** avant la fin du programme pour pouvoir les réutiliser plus tard sans qu'elles ne soient détruite à la fin du programme.
- **échanger des informations** entre différents programmes
- **stocker de grande quantités de données** qui ne peuvent pas toujours être gardées en mémoire.

<u>Exemple :</u>  
- Un éditeur de texte sauvegarde votre saisie dans un fichier `.txt`. 
- Une application de gestion sauvegarde vos données dans un fichier `.dat` ou `.csv`.

## Types d'accès aux fichiers
Avant de commencer à manipuler des fichiers, faut-il déjà savoir comprendre comment on peut y accéder...
- **Accès séquentiel**  
  On lit/écrit les données les unes après les autres dans l'ordre. On peut voir ceci comme lire un roman page par page. Ce genre d'accès est très utile pour les fichiers texte.
- **Accès direct (ou aléatoire)**  
  On peut accéder à une position donnée dans le fichier. Bien plus utile pour les fichiers binaires. Par exemple ouvrir une vidéo et avancer à une certaine durée.

## Les fichiers et le système d'exploitation
Le système d'exploitation gère les fichiers grâce aux informations suivantes :
- Le **nom** du fichier
- Le **chemin** d'accès du fichier
- Le **type** de fichier *(texte, binaire, exécutable, ...)*
- Les **droits d'accès** *(lecture, écriture, exécution)*

>[!info] Remarque
>En langage C, pour travailler avec un fichier, on ne passe pas directement par son nom. On utilise ce qu'on appelle un **==pointeur de fichier==** qui permet de faire le lien entre le programme C et le fichier fourni par le système d'exploitation.

## Cycle de vie d'un fichier en C
Lorsqu’on veut utiliser un fichier, il y a plusieurs étapes **logiques** à suivre :
1. **Ouverture du fichier** : le programme demande au système d’exploitation de préparer le fichier pour lecture/écriture.
2. **Traitement du fichier** : lecture ou écriture des données.
3. **Fermeture du fichier** : libération des ressources et sauvegarde correcte.

<div class="card">
  <svg viewBox="0 0 1200 940" role="img" aria-labelledby="title desc">
  <title id="title">Diagramme : cycle de vie d'un fichier</title>
  <desc id="desc">Du début du programme à la fermeture du fichier, avec décisions d'erreur et boucle de traitement.</desc>
  <defs>
    <marker id="arrow" markerWidth="10" markerHeight="10" refX="8" refY="5" orient="auto" markerUnits="strokeWidth">
      <path d="M0,0 L10,5 L0,10 z" fill="currentColor"/>
    </marker>
  </defs>
  <!-- Start -->
  <g class="nodeCycle" transform="translate(460,40)">
    <rect class="terminatorCycle" width="280" height="70" rx="35"/>
    <text class="textCycle" x="140" y="42" text-anchor="middle">Début du programme</text>
  </g>
  <!-- Ask open -->
  <g class="nodeCycle" transform="translate(440,140)">
    <rect class="boxCycle" width="320" height="90"/>
    <text class="titleCycle" x="160" y="32" text-anchor="middle">Demander l'ouverture du fichier</text>
    <text class="textCycle" x="160" y="58" text-anchor="middle">Choisir chemin, mode, droits</text>
  </g>
  <!-- Decision open -->
  <g class="nodeCycle" transform="translate(480,270)">
    <polygon class="decisionCycle" points="160,0 320,70 160,140 0,70"/>
    <text class="titleCycle" x="160" y="60" text-anchor="middle">Ouverture réussie ?</text>
    <text class="textCycle" x="160" y="84" text-anchor="middle">(fichier, permissions, etc.)</text>
  </g>
  <!-- Error handling -->
  <g class="nodeCycle" transform="translate(120,420)">
    <rect class="dangerCycle" width="300" height="110"/>
    <text class="titleCycle" x="150" y="30" text-anchor="middle">Gérer l'échec d'ouverture</text>
    <text class="textCycle" x="150" y="54" text-anchor="middle">Vérifier chemin/droits,</text>
    <text class="textCycle" x="150" y="74" text-anchor="middle">créer le fichier si besoin,</text>
    <text class="textCycle" x="150" y="94" text-anchor="middle">afficher un message</text>
  </g>
  <!-- Processing -->
  <g class="nodeCycle" transform="translate(780,420)">
    <rect class="boxCycle" width="300" height="110"/>
    <text class="titleCycle" x="150" y="30" text-anchor="middle">Traiter le fichier</text>
    <text class="textCycle" x="150" y="54" text-anchor="middle">Lire / Écrire / Mettre à jour</text>
    <text class="textCycle" x="150" y="74" text-anchor="middle">Accès séquentiel ou direct</text>
    <text class="textCycle" x="150" y="94" text-anchor="middle">Gestion des erreurs I/O</text>
  </g>
  <!-- Continue decision -->
  <g class="nodeCycle" transform="translate(780,570)">
    <polygon class="decisionCycle" points="150,0 300,70 150,140 0,70"/>
    <text class="titleCycle" x="150" y="60" text-anchor="middle">Fin du traitement ?</text>
    <text class="textCycle" x="150" y="84" text-anchor="middle">(données épuisées / action finie)</text>
  </g>
  <!-- Close -->
  <g class="nodeCycle" transform="translate(460,720)">
    <rect class="boxCycle" width="280" height="80"/>
    <text class="titleCycle" x="140" y="34" text-anchor="middle">Fermer le fichier</text>
    <text class="textCycle" x="140" y="58" text-anchor="middle">Libérer les ressources</text>
  </g>
  <!-- End -->
  <g class="nodeCycle" transform="translate(460,820)">
    <rect class="terminatorCycle" width="280" height="70" rx="35"/>
    <text class="textCycle" x="140" y="42" text-anchor="middle">Fin du programme</text>
  </g>
  <!-- Legend -->
  <g class="legendCycle" transform="translate(20,20)">
    <rect class="legendBoxCycle" x="0" y="0" width="360" height="120" rx="12"/>
    <text class="titleCycle" x="16" y="24">Légende</text>
    <g transform="translate(16,40)">
      <rect class="boxCycle" width="24" height="16" rx="4"/>
      <text class="textCycle" x="34" y="13">Étape de traitement</text>
    </g>
    <g transform="translate(16,64)">
      <rect class="terminatorCycle" width="24" height="16" rx="8"/>
      <text class="textCycle" x="34" y="13">Début/Fin</text>
    </g>
    <g transform="translate(16,88)">
      <polygon class="decisionCycle" points="0,8 12,16 24,8 12,0"/>
      <text class="textCycle" x="34" y="13">Point de décision</text>
    </g>
    <g transform="translate(200,40)">
      <rect class="dangerCycle" width="24" height="16" rx="4"/>
      <text class="textCycle" x="34" y="13">Gestion d'erreur</text>
    </g>
  </g>
  <!-- Main flow arrows -->
  <path class="arrowCycle" d="M600,110 L600,140" marker-end="url(#arrow)"/>
  <path class="arrowCycle" d="M640,230 L640,270" marker-end="url(#arrow)"/>
  <!-- Error path -->
  <path class="arrowCycle errorCycle" d="M480,340 L270,340 L270,420" marker-end="url(#arrow)"/>
  <text class="textCycle" x="370" y="332" font-size="14" text-anchor="middle">Non</text>
  <!-- Success path -->
  <path class="arrowCycle okCycle" d="M800,340 L930,340 L930,420" marker-end="url(#arrow)"/>
  <text class="textCycle" x="865" y="332" font-size="14" text-anchor="middle">Oui</text>
  <!-- Retry loop -->
  <path class="arrowCycle warnCycle" d="M120, 480 L50,480 L50,380 L50,185 L440,185" marker-end="url(#arrow)"/>
  <text class="textCycle" x="75" y="180" font-size="12">Corriger et réessayer</text>
  <!-- Processing to decision -->
  <path class="arrowCycle" d="M930,530 L930,570" marker-end="url(#arrow)"/>
  <!-- End processing -->
  <path class="arrowCycle" d="M780,640 L600,640 L600,720" marker-end="url(#arrow)"/>
  <text class="textCycle" x="690" y="632" font-size="14" text-anchor="middle">Oui, terminé</text>
  <!-- Continue processing loop -->
  <path class="arrowCycle" d="M1080,640 L1150,640 L1150,475 L1080,475" marker-end="url(#arrow)"/>
  <text class="textCycle" x="1120" y="660" font-size="14" text-anchor="middle">Non, continuer</text>
  <!-- Final arrow -->
  <path class="arrowCycle" d="M600,800 L600,820" marker-end="url(#arrow)"/>
</svg>
</div>

# Les fichiers texte
En C, manipuler des fichiers permet de **lire et écrire des données sur le disque** au lieu de seulement utiliser la mémoire vive. Les fonctions principales se trouvent dans la bibliothèque standard `<stdio.h>`.

## Ouvrir un fichier
Pour ouvrir un fichier en langage C on utilise la fonction `fopen` dont le prototype est le suivant : 
```c
#include <stdio.h>
FILE* fopen(const char* nomFichier, const char* mode);
```
- Elle prend en paramètres
	- Le nom du fichier
	- Le mode dans lequel on souhaite l'ouvrir
- Elle renvoie un pointeur vers le fichier ouvert.

>[!warning]
>Pensez à vérifier que le fichier c'est bien ouvert. *C'est les mêmes sortes de vérifications que l'on faisait dans le cours 09 sur les allocations dynamiques.*

```c
if(!fichier) {
	// Gestion en cas d'erreur
	printf(...);
	return 1;
}
```

Les différents modes d'ouverture d'un fichier :

<table class="tableFichierFormat">
  <thead class="theadFichierFormat">
    <tr class="trFichierFormat">
      <th class="thFichierFormat">Mode</th>
      <th class="thFichierFormat">Description</th>
      <th class="thFichierFormat">Précision</th>
    </tr>
  </thead>
  <tbody class="tbodyFichierFormat">
    <tr class="trFichierFormat">
      <td class="tdFichierFormat">"r"</td>
      <td class="tdFichierFormat">Lecture</td>
      <td class="tdFichierFormat">Le fichier <strong>doit exister</strong></td>
    </tr>
    <tr class="trFichierFormat">
      <td class="tdFichierFormat">"w"</td>
      <td class="tdFichierFormat">Écriture</td>
      <td class="tdFichierFormat">Créer le fichier si il n'existe pas ou écrase le contenu existant</td>
    </tr>
    <tr class="trFichierFormat">
      <td class="tdFichierFormat">"a"</td>
      <td class="tdFichierFormat">Ajout</td>
      <td class="tdFichierFormat">Ajoute à la fin du fichier</td>
    </tr>
    <tr class="trFichierFormat">
      <td class="tdFichierFormat">"r+"</td>
      <td class="tdFichierFormat">Lecture et écriture</td>
      <td class="tdFichierFormat"></td>
    </tr>
    <tr class="trFichierFormat">
      <td class="tdFichierFormat">"w+"</td>
      <td class="tdFichierFormat">Lecture et écriture</td>
      <td class="tdFichierFormat">Écrase le fichier</td>
    </tr>
    <tr class="trFichierFormat">
      <td class="tdFichierFormat">"a+"</td>
      <td class="tdFichierFormat">Lecture et ajout</td>
      <td class="tdFichierFormat"></td>
    </tr>
  </tbody>
</table>

<u>Exemple :</u>
```c
// Ouverture d'un fichier en écriture
FILE* fichier = fopen("fichier.txt", "w");
if(!fichier){
	printf("Le fichier n'a pas été ouvert...\n");
	return 1;
}
```

## Écrire dans un fichier
Pour écrire dans un fichier en programmation C il existe deux fonctions `fprintf` ou alors `fputs`. Regardons le comportement des deux fonctions.
### La fonction `fprintf`
La fonction `fprintf`est une fonction utilisée pour écrire des données formatées dans un flux, typiquement un fichier.

Prototype de la fonction
```c
#include <stdio.h>
int fprintf(FILE* stream, char* chaine, ...);
```
- Elle prend en paramètres 
	- `stream` le flux dans lequel on souhaite écrire : fichier ouvert avec `fopen` ou même `stdout` pour afficher à l'écran.
	- `chaine` chaîne de caractères à afficher, avec du formatage si il faut introduire des variables, comme avec `printf`.
	- `...` c'est le nombre d'arguments variables selon si vous avez utilisé du formatage.
- Elle retourne un entier, qui est **le nombre de caractères écrits**, si il y a une erreur, la fonction renvoie un nombre négatif !

<u>Exemple :</u>  
```c
// On a ouvert le fichier
fprintf(fichier, "Bonjour le monde");
```
On écrit *"Bonjour le monde"* **suivit d'un retour à la ligne `\n`** dans le fichier pointé par le pointeur `fichier`.

>[!info] Remarque
>Les deux syntaxes suivantes sont strictement équivalentes : 
>```c
>printf("Bonjour le monde");
>```
>```c
>fprintf(stdout, "Bonjour le monde");
>```

### La fonction `fputs`
La fonction `fputs` permet d'écrire une chaîne de caractères **sans format** dans un flux. Elle est plus simple d'uitilisation que `fprintf` mais elle ne permet pas de faire du formatage... 

Prototype de la fonction
```c
#include <stdio.h>
int fputs(const char* chaine, FILE* stream);
```
- Elle prend en paramètres 
	- `stream` le flux dans lequel on souhaite écrire : fichier, `stdout`, ...
	- `chaine` chaîne de caractères à afficher, **sans format**.
- Elle retourne un nombre positif en cas de succès, sinon `EOF` en cas d'erreur.

Contrairement à `fprintf`, la fonction `fputs` n'ajoute pas automatiquement de saut de ligne, il faut donc le faire à la main.

<u>Exemple :</u>  
```c
// On a ouvert le fichier
fprintf("Bonjour le monde", fichier);
```
On écrit *"Bonjour le monde"* **sans retour à la ligne** dans le fichier.

>[!info] Remarque
>La fonction `fputc` permet d'écrire un seul caractère. 
>```c
>int fputc(int c, FILE *stream);
>```
## Lecture dans un fichier
Pour lire des données dans un fichier, il existe plusieurs méthodes que nous allons étudier.

### La fonction `fscanf`
La fonction `fscanf` est utilisée pour **lire des données formatées depuis un flux** *(souvent un fichier)*. C’est un peu l’inverse de `fprintf` en gros.

Le prototype de la fonction est donnée par 
```c
#include <stdio.h>
int fscanf(FILE *stream, const char *format, ...);
```
- Elle prend en paramètres
	- Le flux dans lequel on souhaite lire
	- Le format de la ou des informations lues
- Elle renvoie le nombre d'éléments lus **correctement**, ou elle renvoie `EOF` *End Of File* si la fin du fichier est atteinte avant toute la lecture.

<u>Exemple :</u>  
On souhaite lire des données `nom age taille` dans cet ordre tant que le fichier existe. Sachant que le fichier ressemble à :
```txt
Alice 25 1.68
Bob 30 1.75
```

```c
#include <stdio.h>

int main() {
    FILE *f = fopen("data.txt", "r"); // ouvrir le fichier en lecture
    if (f == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return 1;
    }

    char name[50];
    int age;
    float height;

    while (fscanf(f, "%s %d %f", name, &age, &height) == 3) {
        printf("Nom: %s, Age: %d, Taille: %.2f\n", name, age, height);
    }

    fclose(f);
    return 0;
}
```
```
Nom: Alice, Age: 25, Taille: 1.68
Nom: Bob, Age: 30, Taille: 1.75
```

>[!info] Remarques
>- Comme `scanf`, `fscanf` **lit en fonction des espaces** (espace, tabulation, retour à la ligne).
> - Toujours utiliser l’**adresse des variables** (`&age`, `&height`) pour stocker les valeurs.
> - Retourne **le nombre d’éléments lus**, utile pour vérifier la lecture correcte.
> - Pour lire une **ligne entière** sans formatage, `fgets` est souvent préférable.

### La fonction `fgets`
*Copie de la partie de cours [[07 - Chaînes de caractères#La fonction `fgets`]]*  
La fonction `fgets` permet de récupérer une chaîne de caractères à partir d'un flux (le plus souvent, `stdin`). 

Prototype de la fonction
```c
#include <stdio.h>
char *fgets(char *var, int t, FILE *stream);
```
- `var` la variable qui va permettre de stocker la chaîne de caractères lue.
- `t` la taille de la chaîne à stocker.
- `stream` le flux sur lequel on récupère la chaîne (`stdin`, fichier, ...)

Il faut savoir que la fonction `fgets` arrête la lecture lorsqu'elle rencontre `\n`, la fin du flux, ou alors après `t-1` caractères lus (`\0` le dernier caractère).

>[!warning]
>La fonction `fgets` inclus `\n` dans la chaîne lue si celle ci est rencontrée avant la limite.

<u>Exemple :</u>  
```c
// Lire une ligne dans le fichier
char ligne[100];
fgets(ligne, 100, fichier); // lit une ligne
printf("%s", ligne);
```

### La fonction `fgetc`
La fonction `fgetc` elle permet de lire **un caractère** depuis un flux *(fichier par ex)*.

Prototype de la fonction `fgetc`
```c
#include <stdio.h>
int fgetc(FILE *stream);
```
- **`stream`** : le flux à partir duquel lire *(fichier ouvert avec `fopen`, `stdin`, etc.)*.
- Retourne le **caractère lu** *(sous forme de `int`)*, ou `EOF` si la fin du fichier est atteinte ou s’il y a une erreur.

> [!info] Remarque
> On utilise `int` pour pouvoir représenter tous les caractères et `EOF` ($= -1$).

<u>Exemple :</u>  
On a un fichier `test.txt` qui contient bonjour, on le lit et on affiche un caractère par un caractère.
```c
#include <stdio.h>

int main() {
    FILE *f = fopen("test.txt", "r"); 
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return 1;
    }

    int c;
    while ((c = fgetc(f)) != EOF) { // Lire le fichier jusqu'à la fin
        putchar(c); // Afficher le caractère
    }

    fclose(f); // Fermeture du fichier
    return 0;
}
```
```
Bonjour
```

## Fermeture du fichier
La fonction `fclose` est essentielle en C pour **fermer un flux ouvert** *(fichier)*. Chaque fois que tu ouvres un fichier avec `fopen`, il faut le fermer avec `fclose` pour **libérer les ressources** et s’assurer que tout le contenu est bien écrit.

Prototype de la fonction
```c
#include <stdio.h>
int fclose(FILE *stream);
```
- `stream` le flux/fichier à fermer (retourné par `fopen`).
- Retourne `0` si la fermeture s’est bien passée, `EOF` en cas d’erreur *(i.e. $-1$).

# Les fichiers binaires
## Mode d'ouverture
<table class="tableFichierFormat">
  <thead class="theadFichierFormat">
    <tr class="trFichierFormat">
      <th class="thFichierFormat">Mode</th>
      <th class="thFichierFormat">Description</th>
      <th class="thFichierFormat">Précision</th>
    </tr>
  </thead>
  <tbody class="tbodyFichierFormat">
    <tr class="trFichierFormat">
      <td class="tdFichierFormat">"rb"</td>
      <td class="tdFichierFormat">Lecture binaire</td>
      <td class="tdFichierFormat">Le fichier <strong>doit exister</strong></td>
    </tr>
    <tr class="trFichierFormat">
      <td class="tdFichierFormat">"wb"</td>
      <td class="tdFichierFormat">Écriture binaire</td>
      <td class="tdFichierFormat">Créer le fichier s'il n'existe pas ou écrase le contenu existant</td>
    </tr>
    <tr class="trFichierFormat">
      <td class="tdFichierFormat">"ab"</td>
      <td class="tdFichierFormat">Ajout binaire</td>
      <td class="tdFichierFormat">Ajoute à la fin du fichier</td>
    </tr>
    <tr class="trFichierFormat">
      <td class="tdFichierFormat">"r+b"</td>
      <td class="tdFichierFormat">Lecture et écriture binaire</td>
      <td class="tdFichierFormat"></td>
    </tr>
    <tr class="trFichierFormat">
      <td class="tdFichierFormat">"w+b"</td>
      <td class="tdFichierFormat">Lecture et écriture binaire</td>
      <td class="tdFichierFormat">Écrase le fichier</td>
    </tr>
    <tr class="trFichierFormat">
      <td class="tdFichierFormat">"a+b"</td>
      <td class="tdFichierFormat">Lecture et ajout binaire</td>
      <td class="tdFichierFormat"></td>
    </tr>
  </tbody>
</table>

## Lecture
Pour lire dans une fichier binaire on utilise la fonction `fread` qui permet de lire des blocs de données depuis un fichier ouvert. Elle est souvent utilisée pour lire des données binaires, mais peut aussi être utilisée pour lire des structures.

Prototype de la fonction
```c
#include <stdio.h>
size_t fread(void *ptr, size_t size, size_t nbelem, FILE *stream);
```
- Elle prend en paramètres
	- `ptr` : Pointeur vers la zone mémoire où les données lues seront stockées.
	- `size` : Taille, en octets, de chaque élément à lire.
	- `nbelem` : Nombre d’éléments à lire.
	- `stream` : Pointeur vers le fichier ouvert en lecture *(ou lecture/écriture)*.
- Elle renvoie le nombre d'éléments lu qui peut être inférieur à `nbelem` si la fin du fichier est atteinte `FEOF`, ou si il y a une erreur.

<u>Exemple :</u>  
On lit 5 entiers que l'on stocke dans un tableau.
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f = fopen("exemple.bin", "rb"); // ouverture en mode binaire lecture
    if (!f) {
        perror("Erreur ouverture fichier");
        return 1;
    }

    int tab[5]; // lire 5 entiers
    size_t n = fread(tab, sizeof(int), 5, f);

    printf("Nombre d'éléments lus : %zu\n", n);

    for (size_t i = 0; i < n; i++) {
        printf("tab[%zu] = %d\n", i, tab[i]);
    }

    fclose(f);
    return 0;
}
```

>[!warning]
>`fread` ne met **pas** de caractère nul à la fin si vous lisez du texte. Pour les chaînes de caractères, il faut gérer la terminaison soi-même.

## Écrire
Pour écrire dans un fichier binaire, on utilise la fonction `fwrite` qui permet d’écrire des blocs de données dans un fichier ouvert. Elle est souvent utilisée pour écrire des données binaires, mais peut aussi être utilisée pour écrire des structures.

Prototype de la fonction
```c
#include <stdio.h>
size_t fwrite(const void *ptr, size_t size, size_t nbelem, FILE *stream);
```
- Elle prend en paramètres :
    - `ptr` : Pointeur vers les données en mémoire à écrire dans le fichier.
    - `size` : Taille, en octets, de chaque élément à écrire.
    - `nbelem` : Nombre d’éléments à écrire.
    - `stream` : Pointeur vers le fichier ouvert en écriture _(ou lecture/écriture)_.
- Elle renvoie le nombre d'éléments écrits *qui peut être inférieur à `nbelem` en cas d’erreur.*

<u>Exemple :</u>  
On écrit 5 entiers depuis un tableau dans un fichier binaire.
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f = fopen("exemple.bin", "wb"); // ouverture en mode binaire écriture
    if (!f) {
        perror("Erreur ouverture fichier");
        return 1;
    }

    int tab[5] = {10, 20, 30, 40, 50}; // écrire 5 entiers
    size_t n = fwrite(tab, sizeof(int), 5, f);

    printf("Nombre d'éléments écrits : %zu\n", n);

    fclose(f);
    return 0;
}
```

>[!warning]  
>`fwrite` écrit **les octets tels quels** dans le fichier. Pour les fichiers texte, il vaut mieux utiliser `fprintf` ou `fputs`.

- 
  ```c
    feof(FILE *f)
    ```
    permet de savoir si la fin du fichier est atteinte.
- 
  ```c
    ferror(FILE* f)
    ```
    Permet de savoir si il y eue une erreur de lecture écriture.

<u>Exemple :</u>  
Vérifier le nombre d'éléments lus après `fread`.
```c
size_t n = fread(buffer, sizeof(int), 5, f);
if (n < 5) {
    if (feof(f)) {
        printf("Fin de fichier atteinte.\n");
    } else if (ferror(f)) {
        perror("Erreur lecture fichier");
    }
}
```

