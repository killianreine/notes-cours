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
La SDL c’est-à-dire la Simple DirectMedia Layer est une bibliothèque multimédia. Elle permet un accès de bas-niveau à l’audio, au clavier, à la souris, au joystick, aux graphiques… Cela veut dire qu’elle permet d’afficher des fenêtres, d’afficher des images, de jouer des sons, de gérer le clavier…