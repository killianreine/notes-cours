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

