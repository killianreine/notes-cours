<div>
<div class="td-title">TD1</div>
<div class="td-subtitle">RELATION BINAIRE</div>
<div class="section-title">1 Notions préliminaires</div>
<div class="section-title" style="font-size: 18px; margin-top: 10px;">Théorie des ensembles</div>
<div class="consigne_exo">
    <div class="exo-header">
        <span class="exo-num">1</span>
        <span class="exo-title">Définitions et généralités</span>
    </div>
    <ol class="exo-questions">
        <li>Donner la définition rigoureuse d'un <span class="mot-cle">ensemble</span>.</li>
        <li>Quelles sont les manières de définir un ensemble ?</li>
        <li>Rappeler les opérations sur les ensembles et les définir rigoureusement.</li>
        <li>Si <span class="mot-cle">A est une partie de B</span> que peut-on dire de A par rapport à B hormis que c'est une partie...</li>
        <li>Qu'appelle-t-on <span class="mot-cle">ensembles disjoints</span> ?</li>
        <li>Donner la définition d'un <span class="mot-cle">n-uplet</span>.</li>
        <li>Discutez des différences entre ensembles et n-uplets.</li>
    </ol>
</div>
<div class="consigne_exo">
    <div class="exo-header">
        <span class="exo-num">2</span>
        <span class="exo-title">Inclusion v/s appartenance</span>
    </div>
    <p>Soit \( A = \{0, 1, 7, 5, 6, 9\} \) et \( B = \{1, 8, 4, 2\} \).<br>
    Déterminer si les expressions mathématiques suivantes sont vraies ou fausses.</p>
    <ol class="exo-questions">
        <li>\( \{1, 2\} \in A \)</li>
        <li>\( 0 \in A \)</li>
        <li>\( A \subset B \)</li>
        <li>\( \{1\} \in A \)</li>
        <li>\( \{1\} \subset A \) et \( B \subset \{1\} \)</li>
        <li>\( 14 \subset A \)</li>
        <li>\( \{14\} \in B \)</li>
        <li>\( A \subset A \cup B \)</li>
    </ol>
</div>
<div class="consigne_exo">
    <div class="exo-header">
        <span class="exo-num">3</span>
        <span class="exo-title">Démontrer une propriété</span>
    </div>
    <p>Soient E un ensemble et \( A, B \subseteq E \). On considère la relation \( R_e \) suivante :<br>
    $$
    A R_e B \Leftrightarrow A \subset B
    $$</p>
    <ol class="exo-questions">
        <li>Montrer que \( R_e \) est une <span class="mot-cle">relation d'ordre</span>.</li>
    </ol>
</div>
<div class="consigne_exo">
    <div class="exo-header">
        <span class="exo-num">4</span>
        <span class="exo-title">Propriétés ∩, ∪, ∁</span>
    </div>
    <ol class="exo-questions">
        <li>Déterminer les propriétés des opérations d'union, d'intersection et de complémentaire.</li>
        <li>Comparez avec vos résultats avec vos voisins...</li>
    </ol>
</div>
<div class="consigne_exo">
    <div class="exo-header">
        <span class="exo-num">5</span>
        <span class="exo-title">Égalité des ensembles</span>
    </div>
    <ol class="exo-questions">
        <li>Soit l'ensemble \( C = \{(x, y) \in \mathbb{R}^2 | y = x^2\} \) et l'ensemble \( D = \{(t, t^2) | t \in \mathbb{R}\} \).<br>
        Démontrer que \( C = D \).</li>
        <li>Soit l'ensemble \( E = \{(x, y) \in \mathbb{R}^2 | y^2 = 4x\} \) et l'ensemble \( F = \{(t^2, 2t) | t \in \mathbb{R}\} \).<br>
        Démontrer que \( E = F \).</li>
    </ol>
</div>
<div class="section-title" style="font-size: 18px;">Applications</div>
<div class="consigne_exo">
    <div class="exo-header">
        <span class="exo-num">6</span>
        <span class="exo-title">Bien définie ou non</span>
    </div>
    <ol class="exo-questions">
        <li>Rappeler les définitions d'une <span class="mot-cle">fonction</span> et d'une <span class="mot-cle">Application</span>.</li>
        <li>Déterminer si les applications suivantes sont bien définies. Justifier le cas échéant.
            <ol>
                <li>
                $$ \begin{align*}
                \mathcal{E}_1 : \mathbb{R} &\to \mathbb{R} \\ x &\mapsto \sqrt{x} 
				\end{align*}
				$$</li>
                <li>$$
                \begin{align*}
                 \mathcal{E}_2 : \mathbb{Q} &\to \mathbb{Z} \\ \frac{p}{q}& \mapsto p 
                \end{align*} $$</li>
                <li>$$ \begin{align*}
				\mathcal{E}_3 : \mathbb{R} &\to \{-1, 0, 1\} \\
				x &\mapsto 
\begin{cases} 
-1 & \text{si } x < 0, \\
0  & \text{si } x = 0, \\
1  & \text{si } x > 0.
\end{cases}
\end{align*}
				$$ </li>
                <li> $$ \begin{align*}\\
					\mathcal{E}_4 : \{x \in \mathbb{Z} | x \bmod 2 = 0\} &\to \mathbb{Z} \\ n &\mapsto \frac{n}{2} \\
				\end{align*}
				$$</li>
            </ol>
        </li>
    </ol>
</div>
<div class="consigne_exo">
    <div class="exo-header">
        <span class="exo-num">7</span>
        <span class="exo-title">Sérieux, de la bijectivité...</span>
    </div>
    <p>On considère l'objet mathématique suivant :</p>
        \[f : \mathbb{R} \setminus \{1\} \to \mathbb{R} \]
        \[x \mapsto \frac{x + 1}{x - 1}\] 
    <ol class="exo-questions">
        <li>f est-elle bijective ?<br>
        Vous utiliserez un raisonnement approprié muni d'une rédaction pour répondre à la question posée.</li>
    </ol>
</div>
<div class="section-title">2 Relations binaires</div>
<div class="section-title" style="font-size: 18px; margin-top: 10px;">Graphes</div>
<div class="consigne_exo">
    <div class="exo-header">
        <span class="exo-num">8</span>
        <span class="exo-title">Définitions et généralités</span>
    </div>
    <p>Les relations données par les graphes ci-dessous sont-elles réflexives, symétriques, antisymétriques, transitives ?<br>
    Sont-elles d'ordre ou d'équivalence ?</p>
    <div class="graphTikzTD1">
    <div class="tikz-block">
    <script type="text/tikz">
\begin{tikzpicture}[scale=2]
  % Noeuds
  \node[shape=circle,draw=black] (A) at (0,2) {A};
  \node[shape=circle,draw=black] (B) at (0,4) {B};
  \node[shape=circle,draw=black] (D) at (2,2) {D};
  \node[shape=circle,draw=black] (C) at (2,4) {C};
  % Arêtes
  \path[->,thick] (A) edge node[above] {} (D);
  \path[->,thick] (B) edge node[above] {} (D);
  \path[->,thick] (A) edge[bend right=15] node[above] {} (B);
  \path[->,thick] (B) edge[bend right=15] node[above] {} (A);
  \path[->,thick] (A) edge[loop left] node[left] {} (A);
  \path[->,thick] (B) edge[loop left] node[left] {} (B);
  \path[->,thick] (C) edge[loop right] node[left] {} (C);
  \path[->,thick] (D) edge[loop right] node[left] {} (D);
\end{tikzpicture}
    </script>
  </div>
  <div class="tikz-block">
    <script type="text/tikz">
\begin{tikzpicture}[scale=2]
  % Noeuds
  \node[shape=circle,draw=black] (C) at (0,2) {C};
  \node[shape=circle,draw=black] (B) at (0,4) {B};
  \node[shape=circle,draw=black] (A) at (2,3) {A};
  % Arêtes
  \path[->,thick] (A) edge[bend right=15] node[above] {} (B);
  \path[->,thick] (B) edge[bend right=15] node[above] {} (A);
  \path[->,thick] (A) edge[bend right=15] node[above] {} (C);
  \path[->,thick] (C) edge[bend right=15] node[above] {} (A);
  \path[->,thick] (A) edge[loop right] node[left] {} (A);
  \path[->,thick] (B) edge[loop left] node[left] {} (B);
  \path[->,thick] (C) edge[loop left] node[left] {} (C);
\end{tikzpicture}
    </script>
  </div>
  <div class="tikz-block">
    <script type="text/tikz">
\begin{tikzpicture}[scale=2]
  % Noeuds
  \node[shape=circle,draw=black] (A) at (0,2) {A};
  \node[shape=circle,draw=black] (B) at (1,4) {B};
  \node[shape=circle,draw=black] (C) at (2,2) {C};
  % Arêtes
  \path[->,thick] (A) edge[bend right=15] node[above] {} (B);
  \path[->,thick] (B) edge[bend right=15] node[above] {} (A);
  \path[->,thick] (C) edge[bend right=15] node[above] {} (B);
  \path[->,thick] (B) edge[bend right=15] node[above] {} (C);
  \path[->,thick] (A) edge[bend right=15] node[above] {} (C);
  \path[->,thick] (C) edge[bend right=15] node[above] {} (A);
  \path[->,thick] (A) edge[loop left] node[left] {} (A);
  \path[->,thick] (B) edge[loop left] node[left] {} (B);
  \path[->,thick] (C) edge[loop right] node[left] {} (C);
\end{tikzpicture}
    </script>
  </div>
</div>
</div>
<div class="section-title" style="font-size: 18px; margin-top: 10px;">Propriété des relations</div>
<div class="consigne_exo">
    <div class="exo-header">
        <span class="exo-num">9</span>
        <span class="exo-title">Propriétés de relations</span>
    </div>
    <p>Pour chacune des relations binaires R suivantes, déterminer si elles sont réflexives, symétriques ou transitives. De plus pour les relations qui définissent une relation d'équivalence, décrire leurs classes d'équivalences et leur ensemble quotient.</p>
    <ol class="exo-questions">
        <li>\( \forall a, b \in \mathbb{N}, \; aRb \Leftrightarrow |a - b| \leq 2 \)</li>
        <li>\( \forall a, b \in \mathbb{Q}^*, \; aRb \Leftrightarrow a \cdot b > 0 \)</li>
        <li>\( \forall a, b \in \mathbb{Q}^*, \; aRb \Leftrightarrow \frac{a}{b} \in \mathbb{N}^* \)</li>
        <li>\( \forall a, b \in \mathbb{Q}, \; aRb \Leftrightarrow (a - b) \in \mathbb{N} \)</li>
        <li>\( \forall a, b \in \mathbb{R}, \; aRb \Leftrightarrow a - b = a^2 - b^2 \)</li>
    </ol>
</div>
<div class="consigne_exo">
    <div class="exo-header">
        <span class="exo-num">10</span>
        <span class="exo-title">Relations avancées</span>
    </div>
    <ol class="exo-questions">
        <li>Soit R la relation binaire définie sur \( \mathbb{Z} \) par :
        $$
        \forall (a, b) \in \mathbb{Z}^2, \; aRb \Leftrightarrow a - b \text{ est pair}
        $$
        Montrer que R est une relation d'équivalence et déterminer ses différentes classes d'équivalences.</li>
        <li>Soit \( n \in \mathbb{N}^* \). Soit \( R_n \) une relation binaire définie sur \( \mathbb{Z} \) par :
        $$
         \forall (a, b) \in \mathbb{Z}^2, \; aRb \Leftrightarrow n \text{ divise } a - b 
         $$
        Montrer que \( R_n \) est une relation d'équivalence et déterminer ses différentes classes d'équivalences.</li>
    </ol>
</div>
<div class="consigne_exo">
    <div class="exo-header">
        <span class="exo-num">11</span>
        <span class="exo-title">Utiliser la circularité</span>
    </div>
    <p>Soit R une relation binaire sur un ensemble E. La relation R est dite <span class="mot-cle">circulaire</span> sur E si :<br>
    $$ \forall a, b, c \in E, \; (aRb \land bRc) \Rightarrow cRa $$</p>
    <ol class="exo-questions">
        <li>Montrer que si R est réflexive et circulaire sur E, alors la relation R est une relation d'équivalence sur E.</li>
    </ol>
</div>
<div class="section-title" style="font-size: 18px; margin-top: 10px;">Matrices booléennes et algorithmes</div>
<div class="consigne_exo">
    <div class="exo-header">
        <span class="exo-num">12</span>
        <span class="exo-title">Matrice booléenne et graphes</span>
    </div>
    <p>On considère l'ensemble \( A = \{1, 2, 3\} \) et la relation \( R \subseteq A \times A \) définie par :<br>
    $$ R = \{(1, 1), (1, 2), (2, 3)\}$$</p>
    <ol class="exo-questions">
        <li><strong>Représentation de la relation</strong>
            <ol>
                <li>Représenter R par son graphe orienté.</li>
                <li>Construire la matrice booléenne \( M_R \) de la relation.</li>
            </ol>
        </li>
        <li>Déterminer si R vérifie la réflexivité, symétrie, antisymétrique et la transitivité à partir du graphe, puis de la matrice.</li>
        <li><strong>Modifier la relation</strong>
            <ol>
                <li>Modifier la relation pour la rendre réflexive.</li>
                <li>Ajouter les couples manquant pour rendre la relation symétrique.</li>
                <li>Faire de même pour rendre R transitive.</li>
            </ol>
        </li>
    </ol>
</div>
<div class="consigne_exo">
    <div class="exo-header">
        <span class="exo-num">13</span>
        <span class="exo-title">Plus difficile !</span>
    </div>
    <ol class="exo-questions">
        <li>Soient A et B deux ensembles finis et R une relation définie dans \( A \times B \).<br>
        $$ A = \{a_i, a_{i+1}, \ldots, a_n\} \), \( B = \{b_j, b_{j+1}, \ldots, b_m\} $$
        On rappelle la définition de \( M_R \) la matrice booléenne d'ordre \( (n, m) \) associée à R.<br>
        \[ (M_R)_{ij} = \begin{cases} 1 & \text{si } a_i R b_j \\ 0 & \text{sinon} \end{cases} \]
            <ol>
                <li>Écrire des algorithmes qui ont, en entrée une matrice booléenne associée à une relation binaire sur un ensemble fini et qui précisent si cette relation est réflexive, symétrique ou transitive.<br><br>
                Soient deux relations R et S de \( A \times B \), on rappelle que, \( \forall x, y \in A \times B \) :<br>
                $$ x(R + S)y \Leftrightarrow x(R \cup S)y $$
                $$ x(RS)y \Leftrightarrow x(R \cap S)y $$
                On définit les deux opérations suivantes sur les matrices booléennes P et Q :<br>
                $$ P \lor Q : (P \lor Q)_{ij} = P_{ij} \lor Q_{ij} $$
                $$P \land Q : (P \land Q)_{ij} = P_{ij} \land Q_{ij} $$</li>
                <li>Montrer que \( M_{R+S} = M_R \lor M_S \)</li>
                <li>Montrer que \( M_{RS} = M_R \land M_S \)</li>
                <li>Donner les algorithmes qui calculent \( P \land Q \) et \( P \lor Q \) avec P et Q comme paramètres.</li>
            </ol>
        </li>
        <li>On définit maintenant la composition \( R \circ S \) de deux relations \( R \subset A \times B \) et \( S \subset B \times C \) telle que :<br>
        $$\forall (x, y) \in A \times C, \; x(R \circ S)y \Leftrightarrow \exists z \in B \; | \; xRz \land zSy$$
        On définit aussi le produit booléen \( A \otimes B \) de deux matrices booléennes A d'ordre \( (n, p) \) et B d'ordre \( (p, m) \) par :<br>
        $$(A \otimes B)_{ij} = \bigvee_{k=1}^p a_{ik} \land b_{kj} $$
            <ol>
                <li>Vérifier que \( R \circ (S \circ T) = (R \circ S) \circ T \)</li>
                <li>Montrer que \( M_{R \circ S} = M_R \otimes M_S \)</li>
                <li>Soit \( A = \{a, b, c, d\} \) et \( R \subset A^2 \) une relation sur A définie par \( R = \{(a, b), (b, c), (c, d)\} \).
                    <ol>
                        <li>Écrire la matrice booléenne associée à R et construire son graphe.</li>
                        <li>Construire le graphe de \( R^2 \), donner sa matrice associée et vérifier que la formule du b) permet de la retrouver.</li>
                    </ol>
                </li>
                <li>Écrire un algorithme permettant d'effectuer le produit booléen de deux matrices booléennes.</li>
            </ol>
        </li>
    </ol>
</div>
<div class="section-title" style="font-size: 18px; margin-top: 10px;">Les clôtures</div>
<div class="consigne_exo">
    <div class="exo-header">
        <span class="exo-num">14</span>
        <span class="exo-title">Introduction aux clôtures</span>
    </div>
    <p>On considère l'ensemble \( A = \{a, b, c\} \) et la relation R définie sur A par :<br>
    \( R = \{(a, b), (b, c)\} \)</p>
    <div class="warning-box">
        <strong>Définition :</strong> Lorsqu'une relation R n'a pas une propriété réflexive, symétrique ou transitive, on peut lui ajouter le minimum de couples pour qu'elle le devienne.<br>
        La nouvelle relation s'appelle alors <span class="mot-cle">clôture de R pour la propriété ajoutée</span>.
    </div>
    <ol class="exo-questions">
        <li>Construire le graphe de la relation R.</li>
        <li>La relation R est-elle réflexive ? Symétrique ? Transitive ? Justifiez vos réponses.</li>
        <li>Construire la clôture réflexive de R.</li>
        <li>Construire la clôture symétrique de R.</li>
        <li>Construire la clôture transitive de R.</li>
        <li>Vérifier que la clôture transitive trouvée est bien une relation qui contient R, et qu'elle est la plus petite au sens de la transitivité.</li>
    </ol>
</div>
<div class="consigne_exo">
    <div class="exo-header">
        <span class="exo-num">15</span>
        <span class="exo-title">Presque la fin...</span>
    </div>
    <p>Soit R une relation sur un ensemble fini A. On appelle <span class="mot-cle">clôture propriété</span> de R, la plus petite relation propriété sur A contenant R.</p>
    <ol class="exo-questions">
        <li>Construire les clôtures réflexives, symétriques et transitives de la relation de l'exercice 12.2.c.</li>
        <li>Montrer que la clôture réflexive de R est \( R + I_A \), où \( I_A \) est définie par :<br>
        \( \forall x, y \in A, \; xI_A y \Leftrightarrow x = y \)</li>
        <li>Montrer que la clôture symétrique de R est \( R + R^{-1} \) où \( R^{-1} \) est définie par :<br>
        \( \forall x, y \in A, \; xR^{-1}y \Leftrightarrow yRx \)</li>
        <li>Montrer que la clôture transitive de R est :<br>
        \[ R^+ = \sum_{k=1}^{|A|} R^k \]
        où \( R^k = \underbrace{R \circ R \circ R \circ \ldots \circ R}_{k \text{ fois}} \)<br>
        où \( |A| \) représente le cardinal de A.</li>
        <li>Écrire les algorithmes de calcul des clôtures réflexives, symétriques et transitives.</li>
    </ol>
</div>
</div>
