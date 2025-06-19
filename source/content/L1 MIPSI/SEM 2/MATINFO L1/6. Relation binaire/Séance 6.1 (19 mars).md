# Notions associées au chapitre
- Parties d'un ensemble
- Produit cartésien
- Application, ensemble d'application
- Inclusions, intersection, union
- Notation $(x, y) \in E \times F$, $E^n$, ...
- $n-uplets$ et égalités
- Partition d'un ensemble, partition non propre
- Introduction d'une relation binaire
- Graphes, diagramme de Hasse
- Représentation des relations binaires
- Propriétés fondamentales des relations binaire
- Relation d'équivalence, relation d'ordre et leurs attributs (classes, ensemble quotient, ...)
- Propriété d'une relation d'équivalence
- Ordre inverse, ordre produit, ordre lexicographique
- Majoration minoration

# Introduction générale (séance 1)
## Parties d'un ensemble

>[!question]
>Soit $E=\{1, 2, 3\}$ un ensemble: 
>- Donner l'ensemble des parties de $E$ notées $\mathcal{P}(E)$.
>- Pour un ensemble $E$ quelconque, combien de parties possèdera t-il ?

>**Rappel**
>On appelle ==parties== d'un ensemble $E$, généralement notée $\mathcal{P}(E)$ l'ensemble définit par :
>$$\mathcal{P}(E) = \{ A \subseteq E \}$$
>C'est l'ensemble de tout les ensemble $A$ étant inclus **ou égal** à $E$.

>[!success] Correction
>- $\mathcal{P}(E) = \{\{ 1, 2, 3\}, \{1, 2\}, \{1, 3\}, \{2, 3\}, \{1 \}, \{2\}, \{3\}, \emptyset \}$
>- Tout ensemble possède un total de $2^n$ parties différentes ou égal à $E$.

## Ensemble des applications

>[!question]
>Prenons quelques exemples de fonctions **réelles**, c'est à dire $f : \mathbb{R} \to \mathbb{R}$: 
>- $f : x \to x^2$ 
>- $f : x \to x$
>- $f : x \to \cos(x)$
>Que peut-on dire sur ces dernières ?

>[!success] Correction
>Les trois fonctions associent à chaque antécédant une seule et unique image, on parle alors d'**application**. Et, les trois possèdent le même ensemble d'entrée que de sortie.
>Ces trois applications font partie d'un <u>ensemble</u> qui regroupe les applications qui prennent à valeurs dans $\mathbb{R}$ renvoient un réel. On appelle ceci **ensemble des applications de $\mathbb{R}$ dans $\mathbb{R}$**.
>Et on note : 
>$$\mathcal{F}(\mathbb{R},\mathbb{R})$$

>**De manière générale**
>Soit $E$ et $F$ deux ensembles, on appelle ==ensemble des applications== de $E$ dans $F$, l'ensemble de toutes les fonctions qui à chaque élément d'un ensemble d'entrées (= antécédant) $E$ associe une unique éléments de sortie (= image) de $F$. On note $\mathcal{F}(E, F)$.

## Produit cartésien

>[!question]
>Déterminer le produit cartésien de $\{1, 2, 3\}$ avec $\{a, b\}$.

>[!success] Correction
>On a :
>$$\{ (1, a), (1, b), (2, a), (2, b), (3,a), (3,b) \}$$

>**Rappel**
>Soit $E_1, \ldots, E_n$, $n-$ensembles, on note ==produit cartésien== défini par :
>$$\underset{k=1}{\overset{n}{\prod}}E_k = E_1 \times \ldots \times E_n = \{(x1, \ldots, x_n) \mid x_1 \in E_1, \ldots, x_n \in E_n \}$$

## Puissance ensembliste

>[!info]
>On a par définition :
>$$E^n = \underbrace{E \times E \times E \ldots \times E}_{n-fois}$$
>Ainsi, si $x \in E^n$ alors $x$ est un $n-uplet$ de $n$ composantes qui appartiennent toutes à m'ensemble $E$.

## Les $n-uplets$

Soit $X = (x_1, \ldots, x_n)$ et $Y = (y_1, \ldots, y_m)$ deux $n-uplets$, on dit qu'ils sont égaux si :
- $(n=m) \Longrightarrow$ (même nombre de composantes)
- $\forall i \in [1;n]$ on a $x_i=y_i$, chaque composantes des deux $n-uplets$ doivent êtres égales deux à deux.

## Partition d'un ensembles
Soit $E$ un ensemble et $I \subset \mathbb{N}$ un intervalle.
La famille $(F_i)_{i \in I}$ des parties de $E$ est appelée ==partition== de $E$ si elle respecte les conditions suivantes : 
- $\forall i \in I$, on a $F_i \neq \emptyset$ Toutes parties ne peut être vide
- $\underset{i=1}{\bigcup}F_i = E$, L'union de toutes les parties doit donnée l'ensemble $E$ complet.
- $\forall (i, j) \in I^2$ tel que $i \neq j$ avec $F_i \cap F_j = \emptyset$, l'intersection de toutes parties différentes doit donner l'ensemble vide. Aucune partie ne peut posséder les mêmes éléments qu'une autre.

>[!question]
>Réfléchir sur un exemple de partition avec le groupe de classe.

>[!info]
> - Si il existe une partie vide, en gros si on ne respecte pas la première condition mais les autres, alors dans ce cas on parlera de ==partition non propre==.
> - Avec la définition d'une partition, ça veut dire que pour chaque élément $x$ de $E$, il existe une unique partie $F_i$ avec $x \in F_i$.
> 	- Dans le cas où $\exists x \not\in F_i$, la seconde condition n'est pas respectée
> 	- Dans le cas où $x$ appartient à deux parties différentes, la troisième condition n'est pas respectée.

## La notion de relation binaire
Considérons un ensemble $V$ de voitures quelconques qui sont stockées dans un garage automobile. 
1) Déterminer l'ensemble des entrées.
2) Spécifier les caractéristiques possibles entre voitures.
3) Déterminer une partition de $V$, une partition de l'ensemble $C_{prim}$ qui représente l'ensemble des couleurs primaires.
4) En déduire les relations possibles pour ce contexte.
5) Représenter la/les relations trouvées de plusieurs manières (matricielle, graphe, tableau).
```sql
-- Données SQL
-- A déterminer pendant le cours
```
1) Parlons graphes
2) Montrer que la relation $\mathcal{R}$ représente une relation d'équivalence.
	1) Donner les propriétés d'une relation d'équivalence
	2) Déterminer les différentes classes d'équivalences.
	3) Déterminer l'ensemble quotient.
	4) Vous déterminerez avec le tuteur les définitions "françaises" puis mathématiques des différents termes proposés.
3) Pourquoi ce n'est pas une relation d'ordre ?
4) Prenons la relation $\mathcal{T}$ définie par $$\forall v_1, v_2 \in V \times V \Longleftrightarrow v_1 \text{ plus clair que } v_2$$
   Montrer que cette dernière représente une relation d'ordre.
10) $\mathcal{T}$ est d'ordre total ou d'ordre partiel ?
11) La relation $\leq$ est-elle d'ordre total ? Pourquoi ?
	Proposer plusieurs forme de relation $\leq$ (lexicographique, date, taille, ...)
