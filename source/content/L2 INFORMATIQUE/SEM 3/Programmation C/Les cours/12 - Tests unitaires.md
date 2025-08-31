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

## Étude de cas

$\boxed{\text{Rechercher les occurrences d'un éléments dans un tableau}}$  
Dans ce cours je vous propose un exemple concret d'algorithme à tester. L'objectif de notre programme est de coder une fonction qui s'appellera `rechercher_occurrence` elle prendra en paramètre un pointeur vers un tableau d'entier  et un entier. Elle retournera le nombre d'occurrences de cet entier dans le tableau.  
Pour simplifier les choses on représentera les tableaux entre crochets comme en langage Python. En gros voici quelques résultats de notre fonction sur quelques tableau : 
```python
rechercher_occurrence([1, 2, 6, 7, 8, 41, 25], 14) # Renverra 0
rechercher_occurrence([1, 2, 6, 7, 1, 2, 3, 8, 41, 25], 7) # Renverra 1
rechercher_occurrence([1, 2, 6, 7, 1, 2, 3, 8, 41, 25], 2) # Renverra 2
```

Réfléchissons à comment programmer cette fonction.  
Son objectif est donc de parcourir un tableau de `n` entiers et de compter le nombre d'occurrences de l'entier passé en paramètre. Commençons par donner l'algorithme en pseudo code.
```
Entrees :
	tab       - Un pointeur vers un tableau d'entiers
	taille    - Le nombre d'éléments dans le tableau
	nb        - L'entier dont on cherche le nombre d'occurrences dans tab
Sortie :
	Le nombre d'occurrences de nb dans le tableau tab
	
rechercher_occurrence
	occ <- 0
	pour i allant de 0 à sizeTab
	faire
		si tab[i] == nb
		alors
			occ <- occ + 1
		fin si
	fin pour
	retourner occ
fin rechercher_occurrence
```

Expliquons l'algorithme :
- Il prend en entrée 
	- `tab` le pointeur vers le tableau d'entiers
	- `nb` le nombre dont on recherche le nombre d'occurrences dans le tableau `tab`
- Il renvoie le nombre d'occurrence de `nb` dans `tab`
- On commence par déclarer et initialiser les occurrences de `nb` à $0$, c'est le cas de base.
- Ensuite on parcours le tableau et on compte les occurrences
- On renvoie les occurrences

```c
#include <stdio.h>

/**
Fonction rechercher occurence
@param
	int* tab     : Un pointeur vers un tableau d'entiers
	int taille   : La taille du tableau
	int nb       : L'entier dont on cherche les occurences
@return
	int          : le nombre d'occurrences de nb dans tab
*/
int rechercher_occurrence(int* tab, int taille, int nb){
    int occ = 0;
	for(int i = 0; i<taille; i++){
	    if(*(tab+i)==nb){
	        occ++;
	    }
	}
	return occ;
}

int main() {
	// Premier tableau
    int tab[] = { 1, 2, 6, 7, 8, 41, 25 };
    int *ptr = &tab[0];
	
	// Second tableau
    int tab2[] = { 1, 2, 6, 7, 1, 2, 3, 8, 41, 25 };
    int *ptr2 = &tab2[0];
    
    // ###################################################
    // #################### Les tests ####################
    // ###################################################
    
    // Premier test
    int occ14 = rechercher_occurrence(ptr, 7, 14);
    printf("Occurrence de 14 dans tab : %d\n", occ14);
    
    // Second test
    int occ7 = rechercher_occurrence(ptr2, 10, 7);
    printf("Occurrence de 7 dans tab2 : %d\n", occ7);
    
    // Troisème test
    int occ2 = rechercher_occurrence(ptr2, 10, 2);
    printf("Occurrence de 2 dans tab2 : %d\n", occ2);
    return 0;
}
```
```
Occurrence de 14 dans tab : 0
Occurrence de 7 dans tab2 : 1
Occurrence de 2 dans tab2 : 2
```

Le problème, c’est que si un résultat est faux, tu ne le verras que si tu compares manuellement avec ce que tu attends.  
C’est là qu’interviennent les `assert()`.

Pour commencer, on inclus la bibliothèque 
```c
#include <assert.h>
```

Et pour chaque tests que l'on à fait, on supprime les `printf` et on modifie les lignes du dessus par :
```c
assert(rechercher_occurrence(...)==...);
```
Ainsi si le résultat attendu n'est pas le même, le programme sera stoppé d'un coup et une erreur surviendra.

```c
int main() {
	// Premier tableau
    int tab[] = { 1, 2, 6, 7, 8, 41, 25 };
    int *ptr = &tab[0];
	
	// Second tableau
    int tab2[] = { 1, 2, 6, 7, 1, 2, 3, 8, 41, 25 };
    int *ptr2 = &tab2[0];
    
    // ###################################################
    // #################### Les tests ####################
    // ###################################################
    
    assert(rechercher_occurrence(tab, 7, 14) == 0);  // 14 n'est pas présent
    assert(rechercher_occurrence(tab2, 10, 7) == 1); // 7 est présent 1 fois
    assert(rechercher_occurrence(tab2, 10, 2) == 2); // 2 est présent 2 fois
    
    // Ou ajoute un test volontairement faux pour voir ce qu'il se passe
    assert(rechercher_occurrence(tab2, 10, 42) == 2); // 2 est présent 2 fois
    return 0;
}
```
```bash
main.o: /tmp/XqHGhpcCc2/main.c:37: main: Assertion `rechercher_occurrence(tab2, 10, 42) == 2' failed.
Aborted
```
En gros il y a une erreur lors d'une assertion, l'erreur précise laquelle, par la suite c'est à vous de trouver comment régler la fonctionnalité.  
*Bon ici j'avais volontairement mis des valeurs erronées pour voir ce qu'il se passe...*