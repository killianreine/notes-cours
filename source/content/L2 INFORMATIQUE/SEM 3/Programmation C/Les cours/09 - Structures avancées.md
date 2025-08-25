# Introduction aux structures 
En C, la **structure** (`struct`) est un type défini par l’utilisateur qui permet de regrouper plusieurs variables (de types possiblement différents) sous un même nom.  
C’est très utile pour représenter des objets ou des entités plus complexes.

## Déclaration d'une structure
Pour déclarer une structure en langage C, on utilise le mot clé `struct` suivit d'une liste de champs `fieldK` avec $\texttt{K} \in [1; n]$ où $n \in \mathbb{N}$ représente le nombre de champs associés à la structure. Les différents **champs peuvent être de types différents**.  
De manière générale, on aura :
```c
struct nomStructure{
	typeF1 field1;
	typeF2 field2;
	...
	typeFK fieldK;
};
```
Ici on créé donc une structure nommée `nomStructure` de `K` champs. 

<u>Exemple :</u>  
On va créer une structure `Etudiant` permettant de stocker le nom, le prénom, l'âge et le domaine d'étude de l'étudiant.
```c
struct Etudiant{
	char nom[100];
	char prenom[100];
	int age;
	char domaine[100];
};
```

Il est possible de déclarer des variables de type `struct Etudiant` en même temps que la création.  
Il suffit en fait de les spécifier juste après l'accolade fermante de la structure, comme ceci :
```c
struct Etudiant{
	char nom[100];
	char prenom[100];
	int age;
	char domaine[100];
}etu1, etu2, etu3;
```
Ainsi les variables `etu1`, `etu2` et `etu3` sont de type `struct Etudiant`et sont directement utilisable.

## Initialisation d'une structure
Lors de la création d'une structure, on peut aussi initialiser ces dernières, c'est à dire donner une valeur à chacun des champs (ou pas) un à un.  
On passera alors par l'instruction de la forme :
```c
nomVarStruct = { valeurField1, valeurField2, ...};
```
Sur notre structure de base `Etudiant` on peut initialiser les trois en même temps : 
```c
struct Etudiant{
	char nom[100];
	char prenom[100];
	int age;
	char domaine[100];
	}etu1 = { "Leroux", "Antoine", 18, "Mathématiques" }, 
	 etu2 = { "Morin", "Mylène", 24, "Économie/Gestion" }, 
	 etu3 = { "Armand", "Quentin", 21, "Informatique Quantique" };
```
Ainsi, dans notre code chacun des $4$ champs associés à chaque structure est associé à une valeur, on peut le voir comme une sorte de dictionnaire : 
```
etu1 : 
	Nom = Leroux
	Prenom = Antoine
	Age = 18
	Domaine = Mathématiques
	
etu2 :
	Nom : Morin
	Prénom : Mylène
	Age : 24
	Domaine : Économie/Gestion
	
etu3 : 
	Nom : Armand
	Prénom : Quentin
	Age : 21
	Domaine : Informatique Quantique
```

>[!info] Remarque
>On est pas obligé d'initialiser chaque champ associé à une structure. 

Regardons ce qu'il se passe dans ces cas là :   
<u>Exemple :</u>  
Dans notre exemple, on reprend un nouvel étudiant, on ne lui donne pas de `nom` ni d'`age`.
```c
struct Etudiant {
    char nom[100];
    char prenom[100];
    int age;
    char domaine[100];
} inconnu = {.prenom = "Brice", .domaine = "Industrie"};
```
Les autres variables `age` et `nom` sont quant à elle mises à $0$.

On peut aussi déclarer et initialiser un instance de la structure en dehors de sa création, dans la fonction d'entrée `main` par exemple dans ce cas on utilise la syntaxe suivante : 
```c
struct nomStructure nomVariable = { ... };
```
Si on reprend le dernier étudiant avec toutes les informations `etu3` cela nous donnerais :
```c
struct Etudiant etu3 = { "Adam", "Quentin", 21, "Informatique Quantique" };
```

Dans le cas où vous n'initialisez pas toutes les champs associés à la structure, on reprend la syntaxe `.champ = ...` vue juste au dessus : 
```c
struct Etudiant inconnu = { .prenom = "Brice", .domaine = "Industrie" };
```

## Accès aux valeurs des champs
### Accès direct 
Pour accéder de **manière directe** aux valeurs des champs associés à une structure en C, on utilise l'opérateur `.champ` utilisé précédemment, ce dernier permettait de donner une valeur à certain champs lors de l'initialisation de ceux-ci. On s'en ressert ici pour accéder à leur valeur : 
```
varStructure.champ
```

<u>Exemple :</u>  
Affichage correct des informations concernant l'étudiant `etu1`.
```c
#include <stdio.h>

struct Etudiant {
    char nom[100];
    char prenom[100];
    int age;
    char domaine[100];
};

int main(){
	struct Etudiant etu1 = { "Leroux", "Antoine", 18, "Mathématiques" };
	
	// Affichage des informations concernant Antoine
	printf("Informations : %s %s\n", etu1.nom, etu1.prenom);
	printf("|- Age : %d\n|- Domaine : %s\n", etu1.age, etu1.domaine);
	return 0;
}
```
```
Informations : Leroux Antoine
|- Age : 18
|- Domaine : Mathématiques
```
### Accès via pointeur
Pour pouvoir accéder à une structure grâce à un pointeur, commençons déjà par relier la structure à notre pointeur. Vous allez voir, cela ne change rien à la manière de relier un pointeur et un entier.
```c
int main(){
	struct Etudiant etu1 = { "Leroux", "Antoine", 18, "Mathématiques" };
	struct Etudiant* ptr = &etu1;
	return 0;
}
```
Rien de bien nouveau, on passe l'adresse mémoire au pointeur de type `struct Etudiant`.

Là ou ça changer c'est pour accéder à la valeur d'un champ via pointeur, à la place d'utiliser `.` on utilise `->` le reste est exactement pareil : 
```c
int main(){
	struct Etudiant etu1 = { "Leroux", "Antoine", 18, "Mathématiques" };
	struct Etudiant* ptr = &etu1;
	
	// Affichage des informations concernant Antoine
	printf("Informations : %s %s\n", ptr->nom, ptr->prenom);
	printf("|- Age : %d\n|- Domaine : %s\n", ptr->age, ptr->domaine);
	return 0;
}
```
```
Informations : Leroux Antoine
|- Age : 18
|- Domaine : Mathématiques
```