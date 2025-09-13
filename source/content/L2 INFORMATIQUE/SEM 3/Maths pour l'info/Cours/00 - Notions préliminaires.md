# Rappels et généralités sur les ensembles
## Définitions et représentations

>[!cite] Définition <sub>ensemble</sub>
>On appelle **==ensemble==** une structure mathématiques **non-ordonnée** qui contient des éléments **distincts**.  

Les ensembles peuvent être décrits de manière différentes. 
- **En extension**, on donne la liste de tous les éléments de l'ensemble.  
  *Par exemple* $E = \{1, 2, 3, 4, 5, 6, 7, 8\}$ 
- **En compréhension**, on donne une propriété  
  *Par exemple* $P=\{x \in \mathbb{N} \mid x\%2==0 \}$ représente l'ensemble des nombres pairs.

>[!info] Remarque
>De manière <u>conventionnelle</u>, donc recommandée,
>- Un ensemble est nommé par une majuscule, souvent $E$.
>- Un ensemble est représenté par des accolades `{ ... }` où chaque éléments est séparé par une virgule.


| Type ensemble    | Exemple            | Nombre d'éléments  |
| ---------------- | ------------------ | ------------------ |
| Ensemble fini    | $\{1, 2, 3\}$      | $n \in \mathbb{N}$ |
| Ensemble infini  | $\mathbb{K}$       | $\infty$           |
| Ensemble vide    | $E=\emptyset=\{\}$ | $0$                |
| Singleton        | $E=\{un\}$         | $1$                |
| Ensemble paire   | $E=\{un, deux\}$   | $2$                |
| Ensemble booléen | $B=\{0, 1\}$       | $2$                |

Ainsi, on obtient la définition suivante :

>[!cite] Définition <sub>singleton</sub>
>On appelle **==singleton==** un ensemble qui ne contient qu'**un seul élément**.

## Opérations sur les ensembles

>[!cite] Définition <sub>inclusion</sub>
>On considère un ensemble quelconque $E$ et $A, B$ deux parties de $E$.  
>L'ensemble $A$ **==est inclus==**  dans l'ensemble $B$ si et seulement si tous les éléments de l'ensemble $A$ sont aussi dans l'ensemble $B$.  
>On note :
>
>$$
>A \subset B \Longleftrightarrow \forall x \in A, \; x \in B
>$$
>Si $A \subset B$ on dit que $A$ **est une ==partie== de** $B$ ou bien que $A$ est un sous ensemble de $B$.

<u>Exemple :</u>  
On considère $A=\{1, 2, 3\}$ et $B=\{1, 2, 5, 7\}$.  
Alors, l'ensemble $A$ n'est pas inclus dans l'ensemble $B$ car $3 \notin B$. On note alors $A \not\subset B$.

>[!cite] Définition <sub>égalité de 2 ensembles</sub>
>Soient $A, B$ deux parties de $E$.  
>Si les ensembles $A$ et $B$ partagent **exactement** les mêmes éléments, alors on dit dans ce cas là que $A$ **==est égal==** à $B$ et on note $A=B$ défini par :  
>$$
>\forall x \Longleftrightarrow x\in A \land x \in B
>$$

>[!tip] Astuce
>Pour montrer que deux ensembles $A$ et $B$ sont égaux, il suffit de montrer l'**inclusion dans les deux sens**. Autrement dit, il faut montrer que $A$ est inclus dans $B$ et que $B$ est inclus dans $A$.  
>On note :  
>$$
>(A=B) \Longleftrightarrow (A \subset B \land B \subset A)
>$$

*Le symbole $\land$ représente le ET-logique.*

<u>Exemple :</u>  
On considère les ensembles suivants :
- $C=\{(x,y) \in \mathbb{R}^{2} \mid y=x^2\}$
- $D=\{(t, t^{2})\mid t \in \mathbb{R}\}$  
Montrer que les ensembles $C$ et  $D$ sont égaux.

>Pour montrer que les ensembles $C$ et $D$ sont égaux, il faut montrer que $C \subset D$ et $D \subset C$.  
>
>**(i) Montrons que $C \subset D$**  
>Soit $X \in C$. Alors $X=(x, y)$ un vecteur de $\mathbb{R}^2$ et $y = x^2$.  
>Puisque $y=x^2$ alors on remplace $y$ dans le vecteur. On obtient $X=(x, x^2)$ avec $x \in\mathbb{R}$, la définition exacte de l'ensemble $D$.  
>Ainsi, on vient de montrer que $C \subset D$.
>
>**(ii) Montrons que $D \subset C$**  
>Soit $T \in D$ alors $T=(t, t^2)$ avec $t  \in \mathbb{R}$.  
>Posons $x=t$ alors il est évident que $y=x^2=t^2$. Ainsi on obtient $T=(x, y)$ avec $y=x^2$.  
>Et, puisque $t \in \mathbb{R}$, $x,y \in \mathbb{R}$.  
>D'où $D \subset C$.
>
>En somme, nous venons de montrer que $C=D$.

>[!cite] Définition <sub>union</sub>
>Soient $E$ un ensemble et $A, B$ deux parties de $E$.  
>L'**==union==** de deux ensembles notée $A \cup B$ représente l'ensemble englobant les éléments de $A$ et les éléments de $B$, on peut dire que c'est **la concaténation** des deux ensembles.  
>On note :  
>$$
>A \cup B = \{ x \in E \mid x \in A \lor x \in B\}
>$$

*Le symbole $\lor$ représente le OU-logique.*

<u>Exemple :</u>  
On considère deux ensembles $A=\{1, 2, 3\}$ et $B=\{4, 7, 1, 6\}$.  
Alors $A \cup B =\{ 1, 2, 3, 4, 6 \}$.

>[!warning] Faites gaffe !
>Un ensemble ne peux pas contenir **plusieurs fois le même élément**, ainsi si un élément *ici $1$* apparaît dans les deux ensembles, lors de l'union, il n'en restera qu'un.

>[!cite] Définition <sub>intersection</sub>
>Soient $E$ un ensemble et $A,B$ deux parties de $E$.  
>Alors on appelle **==intersection==** de $A$ et $B$ noté $A \cap B$ l'ensemble des éléments communs à $A$ et à $B$. En fait l'ensemble résultant contiendra les éléments qui sont dans les deux ensembles.  
>On note :  
>$$
>A \cap B = \{ x \in E \mid x \in A \land x \in B\}
>$$

<u>Exemple :</u>  
On considère deux ensembles $A=\{1, 2, 3\}$ et $B=\{4, 7, 1, 6\}$.  
Alors $A \cap B =\{ 1 \}$.

>[!cite] Définition <sub>différence</sub>
>Soit $E$ un ensemble et $A, B$ deux parties de $E$.  
>La **==différence==** de $A$ par $B$ notée $A \backslash B$ et lue *"$A$ privé de $B$"* représente l'ensemble des éléments de $A$ qui ne sont pas dans $B$.  
>On note :  
>$$
>A \backslash B = \{x \in A \mid x \notin B \}
>$$
>L'ensemble résultant contiendra les éléments qui sont présents uniquement dans $A$.

<u>Exemple :</u>  
Si $A=\{ 1, 2, 3, 4\}$ et $B = \{1, 5, 8 \}$.  
Alors $A \backslash B = \{2, 3, 4\}$, on a enlevé à l'ensemble $A$ les éléments qu'il avait en commun avec $B$.

>[!cite] Définition <sub>complémentaire</sub>
>Soient $E$ un ensemble et $A, B$ deux parties de $E$.  
>On appelle **==complémentaire==** noté $\complement_{E}(A)$ l'ensemble des éléments de $E$ qui n'appartiennent pas à $A$. Ce dernier peut aussi être noté $A^{c}$, $\overline{A}$ ou même encore $E \backslash A$.  
>On note :  
>$$
>\complement_{E}(A) = \{ x \in E \mid x \notin A \}
>$$

<u>Exemple :</u>  
Si $A=\{ 1, 2, 3, 4\}$ et $B = \{1, 5, 8 \}$.  
Alors $\complement_{A}(B) = \{2, 3, 4\}$, on a enlevé à l'ensemble $A$ les éléments qu'il avait en commun avec $B$.

>[!cite] Définition <sub>ensemble disjoint</sub>
>Soit $E$ un ensemble et $A, B$ deux parties de $E$.  
>On dit que $A$ et $B$ sont **==disjoints==** lorsque *"leur intersection est vide"*.  
>On note :  
>$$
>A \cap B= \emptyset
>$$
>Autrement dit, ils ne possèdent aucun éléments en commun.

## Propriétés sur les opérations ensembliste 
### Propriété de l'inclusion
On considère $E, F$ et $G$ trois ensembles.
- L'ensemble vide est une partie de tout ensemble
	- $\emptyset \subset E$ *valable pour tous les ensembles*
- **Réflexivité** $E \subset E$
- **Antisymétrie** $E \subset F \land F \subset E \Longleftrightarrow E=F$
- **Transitivité** $E \subset F \land F \subset G \Longrightarrow E \subset G$

### Propriété de priorité

$$
\complement > \cup,\cap > =, \subset
$$

### Propriété union/intersection
Soient $E$ un ensemble et $A,B,C$ trois parties de $E$.
- **Associativité**  
  $$
  (A \cap B)\cap C=A\cap(B\cap C) \hspace{2cm} (A \cup B)\cup C=A\cup(B\cup C) 
  $$

- **Commutativité**  
  $$
  A \cap B= B\cap A \hspace{2cm} A \cup B =B \cup A
  $$

- **Distributivité**  
  $$
  (A \cap B)\cup C=(A\cup C) \cap (B \cup C) \hspace{2cm} (A \cup B)\cap C=(A\cap C) \cup (B \cap C) 
  $$

### Propriété sur le complémentaire
- Privé un ensemble de lui même $\complement_{E}(E)=\emptyset$
- Privé de rien $\complement_{E}(\emptyset)=E$
- Privé pour réunir $\complement_{E}(A) \cup A = E$
- Privé pour attraper $\complement_{E}(A) \cap A = \emptyset$

# Le produit cartésien

>[!cite] Définition <sub>produit cartésien</sub>
>Soient $n \geq 2$ et $E_{1,}E_{2} , \ldots E_{n}$ $n-$ensembles.  
>On appelle **==produit cartésien==** des ensembles $E_{1,}E_{2} , \ldots E_{n}$ le produit $E_{1} \times E_{2} \times  \ldots \times E_{n}$ défini par :  
>$$
>\underset{k=1}{\overset{n}{\prod}}E_{i}=E_{1} \times E_{2} \times  \ldots \times E_{n} =\{(x_{1}, x_{2}, \ldots, x_{n}) \mid x_{1}\in E_{1}, x_{2}\in E_{2}, \ldots, x_{n}\in E_{n}\}
>$$

<u>Exemple :</u>  
Soient $A=\{1, 2\}$ et $B=\{4, 6\}$.  
Alors $A \times B = \{ (1, 4), (1, 6), (2, 4), (2, 6) \}$.

# Applications

>[!cite] Définition <sub>application</sub>
>Une **==application==** est une règle qui associe à chaque éléments d'un ensemble de départ $E$ **un unique élément** d'un ensemble d'arrivée $F$.  
>On note :  
>$$
>f : E \to F, \quad x \mapsto f(x)
>$$
>- $E$  est l'ensemble de départ
>- $F$ est l'ensemble d'arrivée
>- $f(x)$ est l'image de $x$ par $f$
>- $x$ est aussi appelé antécédent

>[!info] Remarque
>L'ensemble des images est appelé **ensemble image** de $f$ et est noté $\mathcal{I}m(f)$. Tel que $\mathcal{I}m(f) \subseteq F$.

