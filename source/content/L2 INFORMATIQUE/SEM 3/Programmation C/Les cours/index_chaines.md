## Table des matières : Les chaînes de caractères en C

1. **Introduction aux chaînes de caractères**
    - Définition d’une chaîne en C
    - Différence entre tableau de caractères et chaîne de caractères
    - Le caractère nul `'\0'`
2. **Déclaration et initialisation**
    - Déclaration d’un tableau de caractères
    - Initialisation implicite et explicite
    - Utilisation des littéraux de chaîne
3. **Accès et manipulation des caractères**
    - Indexation des caractères
    - Parcours avec une boucle
    - Lecture et écriture de caractères individuels
4. **Entrée et sortie de chaînes**
    - `scanf` et ses limites
    - `gets` et ses dangers
    - Utilisation sécurisée de `fgets`
    - Affichage avec `printf`
5. **Fonctions de manipulation de chaînes (bibliothèque `<string.h>`)**
    - Mesurer une chaîne : `strlen`
    - Copier une chaîne : `strcpy`, `strncpy`
    - Concaténer : `strcat`, `strncat`
    - Comparer : `strcmp`, `strncmp`
    - Recherche de caractères et sous-chaînes : `strchr`, `strstr`
6. **Chaînes et pointeurs**
    - Relation entre pointeurs et tableaux de caractères
    - Chaînes comme pointeurs constants
    - Différence entre `char *` et `char[]`
7. **Gestion de la mémoire pour les chaînes**
    - Allocation statique
    - Allocation dynamique avec `malloc` et `free`
    - Copie et libération mémoire
8. **Exemples pratiques**
    - Inverser une chaîne
    - Vérifier si une chaîne est un palindrome
    - Compter les voyelles et consonnes
    - Découper une chaîne (`strtok`)
9. **Erreurs fréquentes et bonnes pratiques**
    - Oublier le caractère nul `'\0'`
    - Dépassements de tampon (buffer overflow)
    - Utilisation correcte de la mémoire
    - Choisir entre tableau statique et allocation dynamique
10. **Conclusion et exercices**
    - Résumé des points clés
    - Exercices d’application progressive
    - Pistes pour aller plus loin (manipulation avancée, Unicode, etc.)