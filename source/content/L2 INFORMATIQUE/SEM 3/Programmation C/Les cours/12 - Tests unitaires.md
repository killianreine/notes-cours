# Introduction
## Qu'est-ce qu'un test unitaire ?
Un **==test unitaire==** est une méthode de test qui consiste à vérifier qu'une **unité/partie** de code *(le plus souvent un fonction, un module)* fonctionne correctement. L'idée est de tester chaque composante de manière isolée pour s'assurer qu'il produit le résultat final souhaité.  
Les tests unitaires sont effectués pendant la phase de développement *(phase de programmation)* d'une application, d'un logiciel.
L'objectif de ces test unitaires et de détecter rapidement les erreurs dans des parties spécifiques du code. Ce genre de tests sont très avantageux, ils permettent un débogage du code plus simple, un maintenance de code plus sûre et une documentation vivante du comportement du code que l'on attend.

## En C, ça dit quoi ?
Pour **automatiser** les tests unitaires en C il existe ce qu'on appelle des **frameworks**. 

|Framework|Particularités|
|---|---|
|**Unity**|Léger, simple, très utilisé pour les systèmes embarqués.|
|**CUnit**|Interface simple, génération de rapports HTML/XML.|
|**Check**|Permet des tests avec fork, isolation de tests pour éviter les crashs.|
|**Google Test (C++)**|Si C est utilisé avec du C++ pour tests unitaires.|

# Structure d'un test unitaire
On aura besoin de la bibliothèque `<assert.h>` pour effectuer des assertions.

Pour effectuer un test unitaire, le plus souvent on suit quelques petites étapes de mises en place et d'exécution.
1. **Setup** : On initialise les données/variables nécessaires  
   *Exemple : allouer de la mémoire, initialiser des variables, créer des structures.*
2. **Exécution** : On appelle la fonction a tester
3. **Assertion** : On vérifie si le résultat obtenu est le bon
4. **Nettoyage** *(ou Teardown en anglais)*, on libère les ressources si nécessaire
```
Setup -> Exercise -> Assertion -> Teardown
```


On effectue un test unitaire avec la fonction :
```c
#include <assert.h>
assert(expression);
```
Qui permet de vérifier si `expression` est vraie. Dans le cas contraire, le programme s'arrête avec un message d'erreur et la ligne.

$\boxed{\text{Rechercher les occurrences d'un éléments dans un tableau}}$  
Dans ce cours je vous propose un exemple concret d'algorithme à tester. L'objectif de notre programme est de coder une fonction qui s'appellera `rechercher_occurence` elle prendra en paramètre un pointeur vers un tableau d'entier  et un entier. Elle retournera le nombre d'occurrences de cet entier dans le tableau. 