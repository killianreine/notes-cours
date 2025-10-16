>[!cite] Définition
>On appelle **==design pattern==** un *modèle de conception* *(architecture générale)* permettant de répondre à une problématique récurrente.

# Design pattern FACADE
## Principe
- <u>Objectif :</u> Permet l'utilisation simplifiée d'un système existant.
- <u>Problème :</u> On a besoin d'un nombre limité de caractéristiques d'un système permettant de manipuler uniquement l'utile.

On propose alors de faire une **façade**, en gros c'est une *nouvelle interface* qui va "recouvrir" le système complexe pour ne laisser que les fonction nécessaire.

## Exemple
On souhaite implémenter le fonctionnement d'une Pile en Java. On souhaite simplement pouvoir empiler, dépiler, vider la pile.  
On utilise alors `java.util.ArrayDeque`, sauf que cette classe propose une cinquantaine de méthodes ce qui est beaucoup trop pour ce qu'on veut faire.  
Ainsi, on va créer une classe `Pile`, qui aura ses propres fonctions `empiler`, `depiler` et `vider`.