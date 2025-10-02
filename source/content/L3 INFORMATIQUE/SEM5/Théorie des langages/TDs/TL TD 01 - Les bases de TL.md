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
  
```mermaid
graph TD
  e["ε"] 
  e2["ε"]
  a1["a"]
  a2["a"]
  b1["b"]
  b2["b"]
  b3["b"]
  
  a21["a"]
  a22["a"]
  a23["a"]
  b21["b"]
  b22["b"]
  b23["b"]

  e --- a1
  e --- b1
  a1 --- b2
  b1 --- a2
  a2 --- b3
  
  e2 --- a21
  a21 --- b21
  b21 --- a22
  e2 --- b22
  b22 --- b23 
  b23 --- a23
```
