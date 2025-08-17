Lors du cours n°2, nous avions parlé des types des variables en C, je fais surtout référence au type `char` qui représente un caractère [[02 - Premiers pas#Le type caractère]].  

>[!note] Rappel
>Le type `char` permet de stocker des caractères, et puisqu'ils sont stockés dans l'ordinateur sous forme d'entier, on peut alors aussi utiliser `char` pour stocker un entier.

Un problème se pose alors...  
Une variable de type `char` ne peut stocker **qu'un seul et unique caractère**, comment peut-on faire pour stocker des mots entiers ? Voire des phrases entières ?  
On cherche un moyen de stocker plusieurs lettre dans un même objet. Justement, on sait déjà le faire, par le biais des **==tableaux==**.

Il y a toujours un problème, une chaîne de caractères est plus qu'un tableau, elle doit être manipulable directement, hors ceci n'est possible **que si on connait sa taille**.

# Déclaration
Ici, rien ne change vraiment de déclaration d'un tableau :

```c
char chaine[t]="...";
```
Où 
- `t` représente la taille de la chaîne de caractères.
- `"..."` la chaîne de caractère que l'on stocke

<u>Exemple :</u>  
On souhaite stocker le mot `informatique` dans une chaine de caractères nommée `domaine`, on va alors créer un tableau de caractères et stocker le mot.
```c
char domaine[] = "informatique";
```

Voici ci dessous, une version schématique simple qui vous permet de comprendre comment `informatique` est stocké.
![[informatiqueMOT.svg]]
