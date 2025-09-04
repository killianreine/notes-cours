# Relations
# Définitions et généralités
Une **==relation==** notée $\mathcal{R}$ entre deux ensembles $E$ et $F$ est donnée par un sous-ensemble $G$ du produit cartésien $E \times F$.  
- $E$ est l'ensemble de départ
- $F$ l'ensemble d'arrivée
- $G \subseteq E \times F$ est appelé **graphe** de la relation et est noté $\widehat{G}$.

En fait une relation binaire, représente simplement un ensemble de couple $X = (x, y)$ qui respectent la relation avec $x \in E$ et $y \in F$. Ces couples sont alors stockés dans un ensemble $G$.

$\boxed{\text{Le produit cartésien}}$  
Considérons $n \geq 2$ et $E_{1},E_{2},\ldots, E_n$ $n$-ensembles.  
Le **==produit cartésien==** des ensembles $E_{1},E_{2},\ldots, E_n$ est l'ensemble noté $E_{1}\times E_{2}\times\ldots\times E_n$ défini par :

$$
E_{1}\times E_{2}\times\ldots\times E_{n}= \underset{k=1}{\overset{n}{\prod}}E_{k}=\{ (x_{1}, x_{2,}\ldots, x_{n})\mid x_{1}\in E_{1,}x_{2}\in E_{2,}\ldots, x_{n}\in E_n \}
$$

>[!info] Remarque
>La structure $(x_{1}, x_{2,}\ldots, x_{n})$ est appelée $n$-uplet.

<u>Exemple :</u>  
Si on prend deux ensembles $E=\{1, 2, 3\}$ et $F=\{1, 4\}$ alors le produit cartésien $E \times F$ est donné par :

$$
E \times F = \{ (1, 1), (1, 4), (2, 1), (2, 4), (3, 1), (3, 4) \}
$$

>[!info] Remarque
>- L'ordre du listage des couples n'a pas d'importance car un ensemble est une collection d'éléments **unique** et **non ordonnés**.
>- Par contre il faut bien respecter l'ordre des composantes de chaque couple. Dans notre exemple il faut impérativement que le premier élément appartienne à $E$ et le second à $F$.  
>  Lorsque l'on marque $(x, y) \in E \times F$ ça revient à dire $x \in E$ et $y \in F$, d'où l'importance de **respecter l'ordre**.

