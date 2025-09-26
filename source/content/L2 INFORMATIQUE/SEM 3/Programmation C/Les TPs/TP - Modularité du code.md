# Application directe au cours
On souhaite écrire un programme en langage C permettant de dessiner des formes géométriques comme le carré, le rectangle et le triangle. Nous allons utiliser un module personnalisé *(une bibliothèque)*.   
Voici un rendu de ce que l'on souhaite : 
```
* * * *
* * * *
* * * *
  
* * * *
* * * *
* * * *
* * * *

*  
* *
* * *
* * * *
```
Vous allez commencez par créer trois fichiers pour que l'arborescence de votre projet ressemble à ceci : 
```
|- main.c
|- dessinerForme.h
|- dessinerForme.c
```

Puis voici le contenu de base de votre fichier `dessinerForme.h`
```c
#ifndef DESSINER_FORME_H
#define DESSINER_FORME_H

// Prototype de vos fonctions permettant de dessiner les formes

#endif
```

1. Dans le fichier `dessinerForme.h` déclarez le prototype des fonctions permettant de dessiner un carré, un rectangle et un triangles.
2. Vous allez devoir vous rendre dans le fichier `dessinerForme.c` et trouver comment relier le fichier `dessinerForme.h` pour pouvoir implémenter les fonctions déclarées précédemment.
3. Implémenter chaque fonction de `dessinerForme.h` dans `dessinerForme.c`.  
   **N'oubliez pas de compiler et d'exécuter votre programme**  
   ```bash
   gcc main.c dessinerForme.c -o prog
   ./prog
   ```
   *Pour implémentez les fonctions, utilisez simplement les `printf()` pour afficher les formes, ce sera bien plus simple... Car nous n'avons pas encore vu les chaînes de caractères.*
4. Le fichier `main.c` lui contient simplement la fonction `main()` donc le point d'entrée de votre programme.