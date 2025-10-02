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
\begin{tikzpicture}[scale=2, every node/.style={font=\normalsize}]
  % Nœuds
  \node (eps) at (0,2) {$\varepsilon$};
  \node (a) at (-1,1) {$a$};
  \node (b) at (1,1) {$b$};
  \node (ab) at (-1,0) {$ab$};
  \node (ba) at (1,0) {$ba$};
  \node (bab) at (1,-1) {$bab$};
  % Arêtes
  \draw (eps) -- (a);
  \draw (eps) -- (b);
  \draw (a) -- (ab);
  \draw (b) -- (ba);
  \draw (ba) -- (bab);
\end{tikzpicture}
    </script>
  </div>
  </div>
  
  
