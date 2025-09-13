# Rappels et généralités sur les ensembles
## Définitions et représentations

>[!cite] Définition
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

>[!cite] Définition
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

