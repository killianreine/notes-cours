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