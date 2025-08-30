# Introduction
## Qu'est-ce qu'un test unitaire ?
Un **==test unitaire==** est une méthode de test qui consiste à vérifier qu'une **unité/partie** de code *(le plus souvent un fonction, un module)* fonctionne correctement. L'idée est de tester chaque composante de manière isolée pour s'assurer qu'il produit le résultat final souhaité.  
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

Pour effectuer une assertion on utilise la syntaxe suivante : 
```c
assert(test); // Si vrai passe sinon échoue
```

<u>Exemple :</u>  
On souhaite Vérifier le retour d'une fonction `somme` qui prend en paramètres deux entiers et qui renvoie la somme des deux. Pour l'exemple nous allons exprès nous tromper quelque part dans le code pour voir ce qu'il se passe : 
```c
#include <stdio.h>
#include <assert.h>

int somme(int a, int b) {
    return a - b;
}

// Test unitaire
void test_somme() {
    // Setup
    int a = 2, b = 3;
    
    // Exercise
    int resultat = somme(a, b);
    
    // Assertion
    assert(resultat == 5); 
    
    // Teardown : rien à nettoyer dans cet exemple
    printf("Test de somme passé !\n");
}

int main() {
    test_somme();  // Exécuter le test
    return 0;
}
```
```bash
test_somme: Assertion `resultat == 5' failed.
Aborted
```