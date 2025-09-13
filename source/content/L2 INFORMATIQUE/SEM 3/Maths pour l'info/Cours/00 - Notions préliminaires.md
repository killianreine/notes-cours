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


