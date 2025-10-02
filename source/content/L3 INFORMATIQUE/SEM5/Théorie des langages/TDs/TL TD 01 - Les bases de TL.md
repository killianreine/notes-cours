>[!warning]
>Pour ce TD, nous travaillerons avec l'alphabet $\Sigma = \{a, b\}$.

<div class="consigne_exo">
  <div class="exo-header">
    <span class="exo-num">1</span>
    <span>Soient \(X=\{ab, bab\}\) et \(Y=\{aba, bba\}\).</span>
  </div>
  <ol class="exo-questions">
    <li>Représenter \(X\) et \(Y\) sous forme arborescente.</li>
    <li>Calculer \(X \cdot Y\) et \(Y \cdot X\) et donner leur représentation sous forme arborescente.</li>
    <li>Que remarque-on sur les deux représentations précédentes ?</li>
  </ol>
</div>

<div class="graphTikzTD1">
    <div class="tikz-block">
    <script type="text/tikz">
\begin{tikzpicture}[->, >=stealth, node distance=1.8cm, every node/.style={circle, draw, minimum size=10mm}]
    % Racine
    \node (eps) {$\varepsilon$};
    % Niveau 1
    \node (a) [below left=of eps] {a};
    \node (b) [below right=of eps] {b};
    % Niveau 2
    \node (ab) [below=of a] {ab};
    \node (ba) [below=of b] {ba};
    % Niveau 3
    \node (bab) [below=of ba] {bab};
    % Arêtes
    \draw (eps) -- (a) node[midway, left] {a};
    \draw (eps) -- (b) node[midway, right] {b};
    \draw (a) -- (ab) node[midway, left] {b};
    \draw (b) -- (ba) node[midway, right] {a};
    \draw (ba) -- (bab) node[midway, right] {b};
    % Doubles cercles pour mots acceptés
    \node[draw, circle, double, minimum size=10mm, right=0cm of ab] {};
    \node[draw, circle, double, minimum size=10mm, right=0cm of bab] {};
\end{tikzpicture}
    </script>
  </div>
  </div>
  
  
