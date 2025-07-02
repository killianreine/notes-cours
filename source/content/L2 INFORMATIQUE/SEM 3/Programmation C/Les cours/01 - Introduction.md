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

Le `C` est un **langage compilé**, en gros le code source où se trouve n'est pas directement un fichier exécutable, il va donc falloir passer votre *fichier_source* dans un programme appelé **compilateur** qui traduit le code source en code machine pour pouvoir l'exécuter par la suite.  
**Zoom sur la compilation**
1. ***Traitement par le préprocesseur***  
    Le préprocesseur est la première étape dans la compilation de nombreux langages (*comme `C` et `C++`*). Il permet de préparer le code source à la compilation par le compilateur.
   - <u>Inclusion des fichiers :</u> Le préprocesseur gère les inclusions (`#include`) qui ajoutent le contenu d'autres fichiers en entête.
   - <u>Macros :</u> Définition des macros avec `#define`. 
   - <u>Conditionnels</u>
   - ...

>[!NOTE]
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

```
sudo apt update
sudo apt install build-essential
```
Le package `build-essential` comprend `gcc`, `g++`, `make`, ...

##### Installation sur macOS

```
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

   ```
   C:\MinGW\bin
   ```

- Cliquez sur **OK** jusqu'à ce que toutes les fenêtres se ferment
- Relancer le terminal

##### Vérifier l'installation de `gcc` sur votre machine

Vous pouvez ensuite vérifier avec :
```
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
   ```
   gcc -E nomFichier.c -o nomFichier.i
   ```
3. La compilation

   - Le compilateur transforme le code prétraité `.i` en code assembleur `.s`.
   - Ainsi, chaque fichier `.c` devient un fichier `.s`.

   La commande : 
   ```
   gcc -S nomFichier.i -o nomFichier.s
   ```
4. L'assemblage

   L'assembleur transforme les fichiers `.s` en code objet `.o` qui sont des codes binaires, *⚠️ ces codes ne sont **pas encore exécutable**.*
   
   La commande : 
   ```
   gcc -c nomFichier.s -o nomFichier.o
   ```
5. Édition de liens (linking)

   - Il prend les fichiers objets `.o` et les **assemble en 1 fichier exécutable**.
   - Production d'un fichier binaire exécutable (par défaut `a.out`)

   La commande : 
   ```
   gcc -c nomFichier.o -o nomExecutable
   ```

#### La compilation directe en <u>une seule ligne</u>

```
gcc nomFichier.c -o nomExecutable
```

# Suivant 
- Cours suivant : [[02 - Premiers pas]]
