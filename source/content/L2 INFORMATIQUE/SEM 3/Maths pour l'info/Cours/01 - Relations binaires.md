# Généralités
## Définition de base
>[!cite] Définition <sub>relation binaire</sub>
>Soit $A,B$ deux ensembles.  
>On appelle **==relation==** sur $A \times B$ une partie $\mathcal{R}$ de $A \times B$. On dit aussi que deux éléments $(a,b) \in A \times B$ sont en relation si $(a,b) \in \mathcal{R}$.  
>On notera alors $a \mathcal{R}b$.

>[!info] Remarque
>Si $A=B$ alors $\mathcal{R}$ est une relation sur $A$.

## Représentation d'une relation binaire
### Représentation ensembliste
Considérons une relation $\mathcal{R}$ définie sur un ensemble $E$. Et on ignore la nature de cette dernière. On sait que les couples $(e,b)$, $(m, m)$ et $(h, j)$ respectent la relation avec $e,b,m,h,j \in E$.  
Alors on peut représenter $\mathcal{R}$ comme étant un ensemble en extension :

$$
\mathcal{R} = \{(e,b), (m,m), (h, j)\}
$$

On obtient alors **l'ensemble de tous les couples qui respectent la relation**.

### Représentation matricielle
La représentation matricielle, est très utile pour déterminer les propriétés d'une relation comme la réflexivité ou la symétrie. En fait, la matrice contient uniquement des $0$ ou des $1$, c'est pour cette raison qu'on l'appelle **==matrice booléenne==**.  
La matrice booléenne représente sur un principe de tableau, où chaque ligne/colonne est représenté par les éléments de l'ensemble $E$ et $F$.  
Si on considère une matrice booléenne $\mathcal{M}_{ij}(\{0, 1\})$ alors si $e_{i}\mathcal{R}e_{j}$ alors le coefficient à leur intersection sera $1$, sinon $0$.

En reprenant l'exemple précédant, on obtient le tableau suivant :


|       | e   | b   | m   | h   | j   |
| ----- | --- | --- | --- | --- | --- |
| **e** | 0   | 1   | 0   | 0   | 0   |
| **b** | 0   | 0   | 0   | 0   | 0   |
| **m** | 0   | 0   | 1   | 0   | 0   |
| **h** | 0   | 0   | 0   | 0   | 1   |
| **j** | 0   | 0   | 0   | 0   | 0   |

D'où la matrice : 

$$
\mathcal{M}_{5}(\{1, 0\})=\begin{pmatrix} 0 & 1 & 0 & 0&0 \\ 0&0&0&0&0 \\ 0&0&1&0&0 \\ 0&0&0&0&1 \\ 0&0&0&0&0 \end{pmatrix}
$$

### Représentation à l'aide d'un graphe
Soit $E$ un ensemble et $\mathcal{R}$ une relation définie sur $E$.  
Alors chaque élément respectant la relation $\mathcal{R}$ peut être vu comme un sommet. Où si $S_{1}\mathcal{R}S_{2}$ alors un **arc orienté** sera tracé de $S_{1}$ vers $S_{2}$.