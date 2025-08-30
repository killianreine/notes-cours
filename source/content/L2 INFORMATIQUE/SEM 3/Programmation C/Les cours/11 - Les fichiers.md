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
