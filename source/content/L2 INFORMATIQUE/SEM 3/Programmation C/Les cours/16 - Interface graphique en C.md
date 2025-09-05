L'objectif de ce cours est de donner un complément de cours de programmation langage C. Cette fois, on s'intéresse à la programmation graphique en C. Nous allons essayer pendant ce cours de créer plusieurs fenêtres graphique permettant d'afficher différentes informations.

# Introduction
Une **interface graphique** *(GUI - Graphical User Interface)* permet à l’utilisateur d’interagir avec un programme à l’aide de fenêtres, boutons, menus, icônes… Contrairement aux programmes en **mode texte** (console), une application graphique gère des événements comme :
- clic de souris
- saisie clavier
- redimensionnement de fenêtre
- ...

Le langage C est historiquement très utilisé pour les systèmes et les applications performantes.    
Pour créer une interface graphique en C, on n’utilise pas le C seul, mais une **bibliothèque spécialisée** :    
- **GTK** : très populaire, utilisé par GNOME.
- **SDL** : plutôt orientée multimédia/jeux.
- **Ncurses** : pour des interfaces _texte enrichies_ dans le terminal.

# Présentation de SDL
## Introduction à la SDL

La **Simple DirectMedia Layer (SDL)** est une bibliothèque multiplateforme qui permet de créer différents types de projets multimédias. Elle est très connue pour son utilisation dans le développement de **jeux vidéo 2D**, mais ses applications ne se limitent pas à cela.  
Sortie en 1998, la SDL a beaucoup évolué. Sa **version 2**, parue en 2013, a apporté de nombreuses améliorations (gestion améliorée du rendu matériel, support des écrans multiples, meilleure gestion des entrées, etc.), ce qui en fait un outil encore largement utilisé aujourd’hui.

## Pourquoi utiliser la SDL ?
La SDL est un excellent choix pour apprendre la programmation de jeux en C, car elle offre :
- Une interface relativement simple à prendre en main.
- Une bonne flexibilité permettant de réaliser différents types de jeux.
- Un contrôle bas niveau qui aide à comprendre les mécanismes internes (graphismes, sons, entrées clavier/souris/manette).

Grâce à elle, il est possible de réaliser des jeux variés tels que :
- **Tetris**, **Casse-brique**, **Pong**, **Bomberman**.
- Des **Shoot ’em up** (ex. _Space Invaders_).
- Des **jeux de combat**.
- Des **jeux de plateforme** (ex. _Super Mario Bros_).
- Des **RPG 2D** (ex. _Zelda_).

## Compétences nécessaires pour un projet en SDL
Réaliser un jeu complet nécessite plusieurs compétences :
- **Gestion de la carte (Tile Mapping)** : représentation des niveaux à partir de petites images réutilisables.
- **Collisions** : détection et réaction des interactions entre objets.
- **Évènements** : gestion du clavier, de la souris, ou de la manette.
- **Mécaniques spécifiques** : par exemple, un système de combat dans un RPG.
- **Multimédia** : ajout de sons, musiques, animations et effets visuels.
## SDL et moteurs de jeu
Bien que la SDL fournisse les bases (affichage, gestion des entrées, audio, etc.), il est souvent pratique de développer un **moteur de jeu minimaliste** par-dessus. Ce moteur permet de centraliser :
- Le rendu des sprites.
- La gestion des entités.
- Le contrôle des animations.
- La gestion des ressources (images, sons, musiques).

Cela facilite la création de projets plus ambitieux sans tout réimplémenter à chaque fois.