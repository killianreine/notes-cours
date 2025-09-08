# Introduction générale

## La programmation, c'est quoi ?

La **programmation** est un concept fondamental en informatique puisqu'elle représente l'art et la science de créer des programmes qui définissent à l'ordinateur ce qu'il doit faire. On peut le voir comme une liste de tâches *(= instructions)* codées dans un langage de programmation que l'ordinateur est capable de comprendre et d'exécuter.

>[!NOTE]
>**Langage de programmation** : langage informatique permettant d'écrire des algorithmes et de produire des programmes informatiques.

La programmation permet de créer toutes sortes d'applications, des simples scripts aux systèmes complexes comme les sites web, les jeux vidéo, les applications mobiles et les logiciels d'entreprise.  
Ainsi, un **programme** est une suite d'instructions ordonnées données à l'ordinateur pour qu'il exécute des tâches. *Par exemple des opérations comme addition, soustraction*.

## Parlons langage C

### Historique

Le langage `C` est un langage de programmation impératif inventé dans les années 1970 par Dennis Ritchie. Ce dernier a pour but de réécrire le langage `Unix`. Le langage `C` est basé sur le langage `B` de Ken Thomson (*langage intermédiaire plus simple que l'assembleur*). Le `C`est une suite de fonctions dont une qui est le <u>point d'entrée</u>, la fonction `main()`.

### Langage compilé

Le `C` est un **langage compilé**, en gros le code source où se trouve n'est pas directement un fichier exécutable, il va donc falloir passer votre *fichier source* dans un programme appelé **compilateur** qui traduit le code source en code machine pour pouvoir l'exécuter par la suite.  
**Zoom sur la compilation**
1. ***Traitement par le préprocesseur***  
    Le préprocesseur est la première étape dans la compilation de nombreux langages (*comme `C` et `C++`*). Il permet de préparer le code source à la compilation par le compilateur.
   - <u>Inclusion des fichiers :</u> Le préprocesseur gère les inclusions (`#include`) qui ajoutent le contenu d'autres fichiers en entête.
   - <u>Macros :</u> Définition des macros avec `#define`. 
   - <u>Conditionnels</u>
   - ...

>[!info] Remarque
>Une **macro** est un motif de substitution de texte permettant généralement de simplifier le code.

   ```c
   #define PI 3.14
   ```

2. ***La compilation***  
    La compilation traduit les fichiers générés par le préprocesseur (1) en code assembleur, qui est une suite d'instructions.

3. ***L'assemblage***  
   Transformation du code assembleur en code binaire compréhensible par le processeur. Le fichier produit est appelé **fichier objet**.

4. ***L'édition de lien***  
   L'édition de lien permet de rassembler les fichiers objets, de gérer les bibliothèques utilisées, ... 

>[!WARNING]
> - **Langage interprété**
>
>   Suite d'instructions, lues **lignes par lignes**, ce qui implique que les erreurs sont détectées pendant l'exécution.
>
> - **Langage compilé**
>
>    Suite de fonctions dont une principale `main` qui représente **le point d'entrée du programme**. Les erreurs sont détectées pendant la compilation, on ne peut donc pas exécuter un programme qui n'a pas réussi à compiler.

<div>
<?xml version="1.0" encoding="UTF-8"?>
<svg width="1000" height="500" viewBox="0 0 1200 500" xmlns="http://www.w3.org/2000/svg" role="img" aria-label="Diagramme de compilation et exécution du code C">
  <defs>
    <marker id="arrowhead" markerWidth="12" markerHeight="10" refX="12" refY="5" orient="auto" markerUnits="strokeWidth">
      <path d="M0,0 L12,5 L0,10 z" fill="black" />
    </marker>
    <filter id="shadow" x="-20%" y="-20%" width="140%" height="140%">
      <feDropShadow dx="0" dy="3" stdDeviation="4" flood-color="#000" flood-opacity="0.15"/>
    </filter>
    <linearGradient id="bgGradient" x1="0%" y1="0%" x2="0%" y2="100%">
      <stop offset="0%" style="stop-color:#ffffff;stop-opacity:1" />
      <stop offset="100%" style="stop-color:#f9fafb;stop-opacity:1" />
    </linearGradient>
    <style>
		.box { fill: #f8faff; stroke: #2563eb; }
		.box-preprocess { fill: #fef3c7; stroke: #f59e0b; }
		.box-compile { fill: #dcfce7; stroke: #16a34a; }
		.box-assemble { fill: #fce7f3; stroke: #ec4899; }
		.box-link { fill: #e0e7ff; stroke: #6366f1; }
		.box-exec { fill: #fed7d7; stroke: #ef4444; }
		.box-cpu { fill: #f0f9ff; stroke: #0ea5e9; }
		.title { fill: #1f2937; }
		.subtitle { fill: #6b7280; }
		.small { fill: #374151; }
		.step { fill: #1f2937; }
		.phase-label { fill: #6b7280; }
		.arrow { stroke: black; }
		[saved-theme="dark"] .box { fill: #1e293b; stroke: #3b82f6; }
		[saved-theme="dark"] .box-preprocess { fill: #78350f; stroke: #fbbf24; }
		[saved-theme="dark"] .box-compile { fill: #14532d; stroke: #22c55e; }
		[saved-theme="dark"] .box-assemble { fill: #831843; stroke: #ec4899; }
		[saved-theme="dark"] .box-link { fill: #3730a3; stroke: #818cf8; }
		[saved-theme="dark"] .box-exec { fill: #7f1d1d; stroke: #f87171; }
		[saved-theme="dark"] .box-cpu { fill: #0c4a6e; stroke: #38bdf8; }
		[saved-theme="dark"] .title { fill: #f1f5f9; }
		[saved-theme="dark"] .subtitle { fill: #94a3b8; }
		[saved-theme="dark"] .small { fill: #cbd5e1; }
		[saved-theme="dark"] .step { fill: #f1f5f9; }
		[saved-theme="dark"] .phase-label { fill: #94a3b8; }
		[saved-theme="dark"] .arrow { stroke: #f1f5f9; }
	</style>
  </defs>
  <!-- Title -->
  <text x="40" y="40" class="title">Processus de compilation et d'exécution en C</text>
  <text x="40" y="65" class="subtitle">De l'écriture du code source à l'exécution par le processeur</text>
  <!-- Phase labels -->
  <text x="40" y="110" class="phase-label">Phase de préparation</text>
  <text x="40" y="250" class="phase-label">Phase de liaison</text>
  <text x="40" y="360" class="phase-label">Phase d'exécution</text>
  <!-- Row 1: Source → Preprocessor → Compiler → Assembler -->
  <g transform="translate(40,125)">
    <!-- Source code -->
    <rect x="0" y="0" width="200" height="85" class="box" filter="url(#shadow)"/>
    <text x="15" y="25" class="step">Code source</text>
    <text x="15" y="45" class="small">fichier.c</text>
    <text x="15" y="65" class="small">Langage C lisible</text>
    <!-- Preprocessor -->
    <rect x="250" y="0" width="200" height="85" class="box box-preprocess" filter="url(#shadow)"/>
    <text x="265" y="25" class="step">Préprocesseur</text>
    <text x="265" y="45" class="small">cpp → fichier.i</text>
    <text x="265" y="65" class="small">#include, #define, #ifdef</text>
    <!-- Compiler -->
    <rect x="500" y="0" width="200" height="85" class="box box-compile" filter="url(#shadow)"/>
    <text x="515" y="25" class="step">Compilateur</text>
    <text x="515" y="45" class="small">gcc -S → fichier.s</text>
    <text x="515" y="65" class="small">Code assembleur</text>
    <!-- Assembler -->
    <rect x="750" y="0" width="200" height="85" class="box box-assemble" filter="url(#shadow)"/>
    <text x="765" y="25" class="step">Assembleur</text>
    <text x="765" y="45" class="small">as → fichier.o</text>
    <text x="765" y="65" class="small">Code machine (objet)</text>
  </g>
  <!-- Arrows row 1 -->
  <path d="M240 167 L290 167" class="arrow"/>
  <path d="M450 167 L540 167" class="arrow"/>
  <path d="M700 167 L790 167" class="arrow"/>
  <!-- Row 2: Linker -->
  <g transform="translate(40,265)">
    <rect x="300" y="0" width="400" height="85" class="box box-link" filter="url(#shadow)"/>
    <text x="320" y="28" class="step">Éditeur de liens (Linker)</text>
    <text x="320" y="50" class="small">ld → exécutable final</text>
    <text x="320" y="70" class="small">Résolution des symboles, liaison des bibliothèques</text>
    <!-- Libraries box -->
    <rect x="750" y="0" width="200" height="85" class="box" filter="url(#shadow)"/>
    <text x="765" y="25" class="step">Bibliothèques</text>
    <text x="765" y="45" class="small">libc.a, libm.a</text>
    <text x="765" y="65" class="small">Fonctions système</text>
  </g>
  <!-- Arrows to linker -->
  <path d="M790 210 L740 265" class="arrow"/>
  <path d="M600 210 L600 265" class="arrow"/>
  <path d="M450 210 L450 265" class="arrow"/>
  <path d="M140 210 L350 265" class="arrow"/>
  <!-- Arrow from libraries to linker -->
  <path d="M790 307 L740 307" class="arrow"/>
  <!-- Row 3: Executable → Loader → CPU -->
  <g transform="translate(40,375)">
    <!-- Executable -->
    <rect x="0" y="0" width="220" height="85" class="box box-exec" filter="url(#shadow)"/>
    <text x="15" y="25" class="step">Exécutable</text>
    <text x="15" y="45" class="small">a.out / programme</text>
    <text x="15" y="65" class="small">Format ELF/PE/Mach-O</text>
    <!-- Loader -->
    <rect x="270" y="0" width="250" height="85" class="box box-exec" filter="url(#shadow)"/>
    <text x="285" y="25" class="step">Chargeur (Loader)</text>
    <text x="285" y="45" class="small">Allocation mémoire</text>
    <text x="285" y="65" class="small">Résolution dynamique</text>
    <!-- Runtime -->
    <rect x="570" y="0" width="200" height="85" class="box box-exec" filter="url(#shadow)"/>
    <text x="585" y="25" class="step">Environnement</text>
    <text x="585" y="40" class="step">d'exécution</text>
    <text x="585" y="55" class="small">main(), pile, tas</text>
    <!-- CPU -->
    <rect x="820" y="0" width="180" height="85" class="box box-cpu" filter="url(#shadow)"/>
    <text x="835" y="25" class="step">Processeur</text>
    <text x="835" y="45" class="small">Instructions machine</text>
    <text x="835" y="65" class="small">Registres, ALU</text>
  </g>
  <!-- Arrow from linker to executable -->
  <path d="M350 310 L200 375" class="arrow"/>
<!-- Arrows row 3 (exécution, centrées) -->
<path d="M220 417.5 L310 417.5" class="arrow"/>
<path d="M520 417.5 L610 417.5" class="arrow"/>
<path d="M770 417.5 L860 417.5" class="arrow"/>
  <!-- Command examples -->
  <g transform="translate(40,480)">
    <text x="0" y="0" class="small" font-weight="600">Commandes GCC :</text>
    <text x="120" y="0" class="small">gcc -E file.c (préprocesseur) • gcc -S file.c (compilation) • gcc -c file.c (assemblage) • gcc file.o -o prog (liaison)</text>
  </g>
</svg>
</div>

1. **La phase de préparation**
- Code source  `fichier.c`
  C'est le code écrit par le développeur, il contient les instructions, les boucles, les fonctions, ...
- Préprocesseur  
  Il remplace les `#include`, `#define`, `ifdef`, `ifndef`, ... par les programmes extérieurs au fichiers qui lui sont associés pour son bon fonctionnement.
- Compilateur  
  Traduit le code C en code assembleur,.
- Assembleur  
  Convertit le code assembleur `.s` en code objet (c'est un code binaire, non encore exécutable).
2. **La phase de liaison - LINKING**
- Éditeur de lien *linker, `ld`*  
  Il combine les fichiers objets créés par l'assembleur et ajoute les bibliothèques nécessaires `libc` par exemple. Et il résoud les *symboles*, comme par exemple quelle fonction correspond à `printf`. Puis il produit l'exécutable final.
- Les bibliothèques  
  C'est elles qui contiennent les fonctions systèmes standard `printf`, `scanf`, ...
3. **La phase d'exécution** 
- Exécution et chargement  
  Le format du programme final dépend du système d'exploitation et peut donc être lancé. Pour commencer il est chargé en mémoire grâce au `loader`.
- L'environnement d'exécution  
  C'est là ou est préparé la pile d'exécution `stack`, le tas `heap` et la fonction `main()`.
- Le processeur  
  Lui il exécute les instructions machines en manipulant les registres mémoire et ALU.

>[!info] Remarque
>L’ALU est le circuit électronique qui effectue toutes les opérations **arithmétiques** (addition, soustraction, multiplication, division, etc.) et **logiques** (ET, OU, NON, comparaisons…).

On retiendra alors : 

$$
code_{source} \rightarrow préprocesseur \rightarrow compilateur \rightarrow assembleur \rightarrow linker \rightarrow exectutable \rightarrow loader \rightarrow processeur
$$
## Outils nécessaires
Évidemment avant de commencer ce cours, il faut s'assurer d'avoir tous les outils requis pour pouvoir coder, compiler et exécuter du `C`.

### Installer un éditeur de code
La première chose à faire est de choisir son éditeur de code, ici seul des éditeurs gratuits sont proposés.

#### Visual Studio Code - VS CODE
Lien pour le téléchargement : [https://code.visualstudio.com](https://code.visualstudio.com)
- Disponible sur Linux, OS et Windows
- Léger et rapide
- Possède des extensions puissantes *par exemple, C/C++ de Microsoft*
- Intégration git, débogueur, terminal intégré
- ...
Par contre, VS CODE nécessite quelques réglages au début.

#### CLion - JetBrain (gratuit pour les étudiants)
Lien pour le téléchargement : [https://www.jetbrains.com/edu-products/download/#section=idea](https://www.jetbrains.com/edu-products/download/#section=idea)

>[!NOTE]
> Il faudra s'identifier via votre compte étudiant.

- Disponible sur OS, Linux et Windows
- Puissant et complet
- Débogueur et outils intégré
- Idéal pour les projets

### Compiler son programme `C`

#### Installation de `GCC`

##### Installation sur Linux/Debian

```bash
sudo apt update
sudo apt install build-essential
```
Le package `build-essential` comprend `gcc`, `g++`, `make`, ...

##### Installation sur macOS

```bash
xcode-select --install
```
En gros c'est l'installation de **Xcode Command Line Tools**, qui est un paquet qui inclut `gcc`.

##### Installation sur windows

- Télécharger `MinGW` depuis le lien [suivant](https://sourceforge.net/projects/mingw/)
- Pendant l'installation, vous devez cocher : 

   - `mingw32-gcc-g++`
   - `mingw32-gcc-objc`
   - `mingw32-gcc-make`

- Ensuite, il faudra ajouter le chemin `C:\MinGW\bin` à ta variable d'environnement `PATH`.

###### Ajouter un chemin à sa variable d'environnement `PATH`

- Appuyez sur `Windows + s` et tapez **variables d'environnement**
- Cliquez sur **Modifier les variables d'environnement système**
- Cliquez sur **Variable d'environnement**
- Dans la section **Variables système**, sélectionner `PATH` et cliquez sur **Modifier**
- Cliquez sur **Nouveau** et ajoutez

   ```bash
   C:\MinGW\bin
   ```

- Cliquez sur **OK** jusqu'à ce que toutes les fenêtres se ferment
- Relancer le terminal

##### Vérifier l'installation de `gcc` sur votre machine

Vous pouvez ensuite vérifier avec :
```bash
gcc --version
```

#### Compiler avec `GCC`

1. Écriture du code source  
   Fichier avec l'extension `.c`  
      *Ces fichiers peuvent inclure des header (`#include` ou des `.h` fais soi-même)*
2. Le préprocessing
   - Géré par le préprocesseur `cpp`
   - Il remplace donc les `#include`, `# define`...
   - Produit un fichier temporaire avec tout le contenu déplié (pas encore du code machine)

   La commande : 
   ```bash
   gcc -E nomFichier.c -o nomFichier.i
   ```
3. La compilation

   - Le compilateur transforme le code prétraité `.i` en code assembleur `.s`.
   - Ainsi, chaque fichier `.c` devient un fichier `.s`.

   La commande : 
   ```bash
   gcc -S nomFichier.i -o nomFichier.s
   ```
4. L'assemblage

   L'assembleur transforme les fichiers `.s` en code objet `.o` qui sont des codes binaires, *⚠️ ces codes ne sont **pas encore exécutable**.*
   
   La commande : 
   ```bash
   gcc -c nomFichier.s -o nomFichier.o
   ```
5. Édition de liens (linking)

   - Il prend les fichiers objets `.o` et les **assemble en 1 fichier exécutable**.
   - Production d'un fichier binaire exécutable (par défaut `a.out`)

   La commande : 
   ```bash
   gcc -c nomFichier.o -o nomExecutable
   ```

#### La compilation directe en <u>une seule ligne</u>

```bash
gcc nomFichier.c -o nomExecutable -Wall -Wextra
```
Les lignes `-Wall -Waxtra` permettent d'activer certain avertissements lors de la compilation en langage C.

Bon nous on se contentera de la commande : 
```bash
gcc nomFichier.c -o nomExecutable
```
# Suivant 
- Cours suivant : [[02 - Premiers pas]]
