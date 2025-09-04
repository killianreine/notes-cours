# Relations

Une **==relation==** notée $\mathcal{R}$ entre deux ensembles $E$ et $F$ est donnée par un sous-ensemble $G$ du produit cartésien $E \times F$.  
- $E$ est l'ensemble de départ
- $F$ l'ensemble d'arrivée
- $G \subseteq E \times F$ est une partie du **produit cartésien $E \times F$**.

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

Ainsi si pour une relation $\mathcal{R}$ quelconque donnée on obtient $G=E \times F$ dans notre exemple, on peut en déduire le graphe de la relation tel que : 

<svg xmlns="http://www.w3.org/2000/svg" width="360" height="220" viewBox="0 0 360 220">
  <defs>
    <marker id="arrow" viewBox="0 0 10 10" refX="10" refY="5"
            markerUnits="strokeWidth" markerWidth="8" markerHeight="6" orient="auto">
      <path d="M 0 0 L 10 5 L 0 10 z" fill="currentColor"/>
    </marker>
    <style>
      /* --- Style clair par défaut --- */
      .node { fill: white; stroke: #333; stroke-width:2; }
      .label { font-family: Arial, Helvetica, sans-serif; font-size:14px; font-weight: bold; fill: #111; }
      .edge { fill: none; stroke: #333; stroke-width:1.6; marker-end: url(#arrow); color: #333; }
      text { pointer-events:none; }
      /* --- Style sombre si parent a [saved-theme="dark"] --- */
      [saved-theme="dark"] .node { fill: #222; stroke: #aaa; }
      [saved-theme="dark"] .label { fill: #f5f5f5; }
      [saved-theme="dark"] .edge { stroke: #aaa; color: #aaa; }
      [saved-theme="dark"] { background: #111; }
    </style>
  </defs>
  <!-- Left: E -->
  <circle class="node" cx="60" cy="40" r="20" />
  <text class="label" x="60" y="45" text-anchor="middle">1</text>
  <circle class="node" cx="60" cy="100" r="20" />
  <text class="label" x="60" y="105" text-anchor="middle">2</text>
  <circle class="node" cx="60" cy="160" r="20" />
  <text class="label" x="60" y="165" text-anchor="middle">3</text>
  <!-- Right: F -->
  <circle class="node" cx="300" cy="70" r="20" />
  <text class="label" x="300" y="75" text-anchor="middle">1</text>
  <circle class="node" cx="300" cy="150" r="20" />
  <text class="label" x="300" y="155" text-anchor="middle">4</text>
  <!-- Edges -->
  <path class="edge" d="M80,40 C150,40 210,70 280,70" />
  <path class="edge" d="M80,42 C150,70 210,120 280,150" />
  <path class="edge" d="M80,100 C150,90 210,80 280,70" />
  <path class="edge" d="M80,102 C150,120 210,130 280,150" />
  <path class="edge" d="M80,160 C150,140 210,100 280,80" />
  <path class="edge" d="M80,162 C150,160 210,150 280,150" />
</svg>

*ce graphe est néanmoins assez spécial car tous les couples d'éléments respectent la relation, on dit alors que $\widehat{R}$ est un graphe biparti complet.*  
- Les graphes : [[MPI Cours 2024-25.pdf]]

Généralement le terme *"La relation $\mathcal{R}$ de $E$ dans $F$"* est noté $\mathcal{R} : E \to F$. Lorsqu'un couple de valeur $(x, y)$ respecte la relation alors on note $x \mathcal{R}y$, pour dire en fait que $(x,y)\in\widehat{R}$. 

>[!info] Remarque
>Si l'ensemble d'arrivée $E$ et l'ensemble d'arrivée $F$ représentent en fait le même ensemble, c'est à dire que $E=F$alors on dit simplement que $\mathcal{R}$ est une relation sur $E$.  

On note $\mathcal{R}(x)$ l'ensemble **des images de $x$** qui représente en fait un ensemble contenant tous les éléments de $F$ tel qu'on a $x \mathcal{R}y$, on note aussi 

$$
\mathcal{R}(x) = \{y \in F \mid x \mathcal{R} y \}
$$

<u>Exemple :</u>  
Pour mieux comprendre on peut utiliser un exemple un peu plus théorique ça fonctionne de la même manière.  
On considère une relation $\mathcal{C}$ un ensemble de voitures $V$ tel que :

$$
\mathcal{C} = \{(v_{1,}v_{2})\in V^{2}\mid v_{1}\text{ et } v_{2}\text{ ont la même couleur} \}
$$
Alors si on prend $v \in V$ une voiture de couleur bleu alors : $\mathcal{C}(v)$ représente simplement l'ensemble de toutes les voitures bleues. Si $v$ était rouge alors son ensemble image représenterait l'ensemble de toutes les voitures rouge.  
L'ensemble noté $\mathcal{C}(B_{leu}\cup R_{ouge})$ va alors représenter l'ensemble de toute les voiture bleue **OU** *(=union)* l'ensemble de toute les voitures rouge.  

*De manière plus générale*  
Soit $\mathcal{R} : E \to F$ alors $\forall X, X' \subset E$ on a :  

$$
\mathcal{R}(X \cup X')=\mathcal{R}(X) \cup \mathcal{R}(X')
$$

Toute relation $\mathcal{R}$ admet ce qu'on appelle une **==relation inverse==** notée $\mathcal{R}^{-1}$ qui représente la relation défini par $\mathcal{R}^{-1} : F \to E$ tel que $\exists x \in E$ tel que $y \mathcal{R}^{-1}x$ alors on a $x \mathcal{R}y$. 