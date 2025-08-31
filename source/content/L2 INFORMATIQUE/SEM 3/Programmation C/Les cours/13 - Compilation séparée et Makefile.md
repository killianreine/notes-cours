# Quelques rappels
Un programme en langage C peut être réparti sur *plusieurs fichier* chaque fichier peut alors être compilé séparément puis connecté au fichier principal avec l'édition des liens ([[01 - Introduction#Langage compilé]]).  
Comme on l'a déjà dit en programmation C, les programmes ont une structures :
- Le **programme** peut être répartit sur plusieurs fichiers que l'on appelle **==module==**.
- Le **fichier** lui contient une liste de déclaration.
- Les **déclarations** quant à elles font référence aux déclarations et définitions de fonctions, variables, type, ... ainsi qu'au directive au préprocesseur *genre `#include` `#define`, ...*.  

Les différentes *parties* d'un programme peuvent être placée dans plusieurs fichiers différents *(= module)* et reliés par des interfaces *(les fichier `.h` : [[05 - Retour sur les fonctions#Organisation et utilisation des fichiers `.h` personnalisés]])*. Car la notion de *module* n'existe pas en langage C, c'est pour cette raison qu'on l'associe ici au terme *fichier*.