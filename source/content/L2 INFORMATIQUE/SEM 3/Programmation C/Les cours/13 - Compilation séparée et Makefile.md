# Quelques rappels
Un programme en langage C peut être réparti sur *plusieurs fichier* chaque fichier peut alors être compilé séparément puis connecté au fichier principal avec l'édition des liens ([[01 - Introduction#Langage compilé]]).  
Comme on l'a déjà dit en programmation C, les programmes ont une structures :
- Le **programme** peut être répartit sur plusieurs fichiers que l'on appelle **==module==**.
- Le **fichier** lui contient une liste de déclaration.
- Les **déclarations** quant à elles font référence aux déclarations et définitions de fonctions, variables, type, ... ainsi qu'au directive au préprocesseur *genre `#include` `#define`, ...*.  

Les différentes *parties* d'un programme peuvent être placée dans plusieurs fichiers différents *(= module)* et reliés par des interfaces *(les fichier `.h` )* [[05 - Retour sur les fonctions#Organisation et utilisation des fichiers `.h` personnalisés]]. Car la notion de *module* n'existe pas en langage C, c'est pour cette raison qu'on l'associe ici au terme *fichier*.

Les fonctions et les variables préfixées du mot clé `static` sont **locales au fichier**, c'est à dire qu'elles sont visibles uniquement dans le fichier dans lequel elles ont été créées. En gros dans les autres fichiers c'est comme si elles n'existaient pas. Alors que les fonctions et les variables globales **visibles dans tous les fichiers** doivent être **définie une seule fois**.

# Compilation séparée
La compilation séparée permet en fait de **fragmenter** un grand programmes en différentes parties appelées **==modules==** qui peuvent être compilées seules, les unes des autres. 

>[!warning]
>Toute fonction ou variables <u>doit être définie avant d'être utilisée</u> !

On peut *"étendre"* une fonction et une variable pour pouvoir l'utiliser dans d'autres fichiers que celui dans lequel il a été définie, on utilise alors le mot clé `extern`.