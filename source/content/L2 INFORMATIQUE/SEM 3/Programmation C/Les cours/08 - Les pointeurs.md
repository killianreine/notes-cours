# Précisions sur le stockage des variables
En langage C, les variables sont stockées dans des endroits différents de la **mémoire** selon leur type et leur portée. Voici les principaux types de variables : 

| Type de variable   | Stockage<br>Segment mémoire | Durée de vie                                            | Portée                                           |
| ------------------ | --------------------------- | ------------------------------------------------------- | ------------------------------------------------ |
| Locale             | Pile *stack*                | Pendant exécution du bloc                               | Dans le bloc ou elle a été déclarée              |
| Globale / statique | Segment statique            | Pendant exécution de **tout le programme**              | Partout dans le fichier                          |
| Dynamique          | Tas *heap*                  | Jusqu'à libération de la ressource *sera vue plus tard* | Accès via pointeur                               |
| Constante          | Segment constant            | Pendant l'exécution de **tout le programme**            | Peut être locale ou globale selon la déclaration |
