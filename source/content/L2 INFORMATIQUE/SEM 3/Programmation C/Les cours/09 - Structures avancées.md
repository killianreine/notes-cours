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

## Modification d'un champ
Il est possible de modifier la valeur attribuée aux différents champs d'une instance de la structure. Dans ce cas là, on distingue aussi deux méthodes **directe** et **indirecte via pointeur**. 
- <u>Directe :</u> On utilise l'opérateur `.` tel que `instance.filed = ...;`
- <u>Indirecte :</u> On utilise l'opérateur `->` tel que `ptr->field = ...;`

<u>Exemple :</u>  
Ici on modifie l'instance `etu2` de la structure des deux manières.
```c
int main(){
	struct Etudiant etu2 = { "Morin", "Mylène", 24, "Économie/Gestion" };
	
	// Modification directe
	etu2.nom = "Dorey";
	etu2.prenom = "Ewen";
	
	// Modification via pointeur
	struct Etudiant* ptr = &etu2;
	ptr->domaine = "Météorologie";
	ptr->age = 22;
	
	// Affichage des informations 
	printf("Informations : %s %s\n", etu2.nom, ptr->prenom);
	printf("|- Age : %d\n|- Domaine : %s\n", ptr->age, etu2.domaine);
	return 0;
}
```
```bash
ERROR!
/tmp/2oSE7IvEf7/main.c: In function 'main':
/tmp/2oSE7IvEf7/main.c:14:18: error: assignment to expression with array type
   14 |         etu2.nom = "Dorey";
      |                  ^
ERROR!
/tmp/2oSE7IvEf7/main.c:15:21: error: assignment to expression with array type
   15 |         etu2.prenom = "Ewen";
      |                     ^
/tmp/2oSE7IvEf7/main.c:19:22: error: assignment to expression with array type
   19 |         ptr->domaine = "Météorologie";
      |                      ^
```
Et oui, vous ne vous attendiez pas à celle ci !  
En fait c'est plutôt logique, on avait vu pendant le cours [[07 - Chaînes de caractères]] que lorsqu'un tableau de caractères est initialisé, il ne peut pas recevoir une nouvelle affectation. Ce qui implique les trois erreurs ici.  
En fait, on utilise `strcopy`.

```c
#include <string.h>

int main(){
	struct Etudiant etu2 = { "Morin", "Mylène", 24, "Économie/Gestion" };
	
	// Modification directe
	strcpy(etu2.nom, "Dorey");
	strcpy(etu2.prenom, "Ewen");
	
	// Modification via pointeur
	struct Etudiant* ptr = &etu2;
	strcpy(ptr->domaine, "Météorologie");
	ptr->age = 22;
	
	// Affichage des informations 
	printf("Informations : %s %s\n", etu2.nom, ptr->prenom);
	printf("|- Age : %d\n|- Domaine : %s\n", ptr->age, etu2.domaine);
	return 0;
}
```
```
Informations : Dorey Ewen
|- Age : 22
|- Domaine : Météorologie
```
# Structures imbriquées
En considérant toujours notre structure `Etudiant`, on souhaite stocker maintenant l'adresse de ces derniers on va alors devoir ajouter un champ. Sauf que pour l'adresse on décide de le stocker sous forme de structure `Adresse`, celle ci contient le numéro de rue `numero`, le nom de la rue `rue`, le code postal `code` et le nom de la ville `ville`.  
On donne alors la structure `Adresse` comme suit :
```c
struct Adresse{
	int numéro;
	char rue[300];
	int code;
	char ville[100];
};
```

Maintenant il faut ajouter le champ `adresse` à notre étudiant : 
```c
struct Etudiant {
    char nom[100];
    char prenom[100];
    int age;
    char domaine[100];
    struct Adresse adresse;
};
```
En fait, pour donner l'adresse à l'étudiant, il faudra donner un **emplacement mémoire** vers l'instance d'`adresse`. Rien de trop chiant, il suffit de définir et d'initialiser une instance de la structure et de la donner à étudiant : 
```c
struct Etudiant etu2 = { "Morin", "Mylène", 24, "Économie/Gestion" };
struct Adresse adr = { 25, "Rue Philippe Lebon", 76600, "Le Havre" };

// Affecter l'adresse à l'étudiant
etu2.adresse = adr;
```
Pour accéder aux champs de l'adresse de l'étudiant, on procède avec les opérateurs `.` ou `->` selon la méthode d'accès sauf qu'ici on le fait sur deux niveaux : une fois pour accéder au champ `adresse` une seconde fois pour accéder à un des champs associés à `adresse`.  
Dans notre cas par exemple, pour accéder au nom de la rue, on utilisera la syntaxe ;
```c
char nomRue[300] = etu2.adresse.rue;
```
Modifions l'affichage de l'étudiant pour afficher maintenant son adresse proprement et simplement.

```c
#include <stdio.h>
#include <string.h>

struct Adresse{
	int numero;
	char rue[300];
	int code;
	char ville[100];
};

struct Etudiant {
    char nom[100];
    char prenom[100];
    int age;
    char domaine[100];
    struct Adresse adresse;
};

int main(){
	struct Etudiant etu2 = { "Morin", "Mylène", 24, "Économie/Gestion" };
	struct Adresse adr = { 25, "Rue Philippe Lebon", 76600, "Le Havre" };
	
	etu2.adresse = adr;
	
	// Affichage des informations 
	printf("Informations : %s %s\n", etu2.nom, etu2.prenom);
	printf("|- Age : %d\n|- Domaine : %s\n", etu2.age, etu2.domaine);
	printf("|- Adresse : %d %s, %d - %s", etu2.adresse.numero, 
	                                      etu2.adresse.rue, 
	                                      etu2.adresse.code, 
	                                      etu2.adresse.ville);
	return 0;
}
```
```
Informations : Morin Mylène
|- Age : 24
|- Domaine : Économie/Gestion
|- Adresse : 25 Rue Philippe Lebon, 76600 - Le Havre
```

On peut pas utiliser un pointeur vers la structure `adresse` de l'étudiant pour que ça aille plus vite ?  
Évidemment, regardez : 
```c
int main(){
	struct Etudiant etu2 = { "Morin", "Mylène", 24, "Économie/Gestion" };
	struct Adresse adr = { 25, "Rue Philippe Lebon", 76600, "Le Havre" };
	
	etu2.adresse = adr;
	// Pointeur vers l'adresse de l'étudiant
	struct Adresse *ptr = &etu2.adresse;
	
	// Modification d'une info de l'adresse : 
	ptr->code = 78540;
	
	// Affichage des informations 
	printf("Informations : %s %s\n", etu2.nom, etu2.prenom);
	printf("|- Age : %d\n|- Domaine : %s\n", etu2.age, etu2.domaine);
	printf("|- Adresse : %d %s, %d - %s", ptr->numero, ptr->rue, ptr->code, ptr->ville);
	return 0;
}
```
```
Informations : Morin Mylène
|- Age : 24
|- Domaine : Économie/Gestion
|- Adresse : 25 Rue Philippe Lebon, 78540 - Le Havre
```

En résumé ici il y a deux manières d'accéder aux informations : 
```c
int codeDirect = etu2.adresse.code;
int codePointeur = ptr->code;
```
De plus si vous modifiez la valeur d'un champ, cela affectera les deux méthodes car elles utilisent en faire exactement la même instance de la structure.

# Tableaux de structures
Les tableaux jouent eux aussi un rôle important. Cette fois au lieu de stocker un caractère, ou un simple entier, chaque emplacement du tableau permettra de stocker une structure entière.  
La définition et la déclaration fonctionne de la même manière que si on manipulait des entiers.  
On reprend la structure `struct Etudiant` ainsi que la structure `Adresse` .

```c
struct Adresse{
	int numero;
	char rue[300];
	int code;
	char ville[100];
};

struct Etudiant {
    char nom[100];
    char prenom[100];
    int age;
    char domaine[100];
    struct Adresse adresse;
};
```

- Création d'un tableau initialement vide de `n` étudiants :
```c
struct Etudiant classe[n];
```