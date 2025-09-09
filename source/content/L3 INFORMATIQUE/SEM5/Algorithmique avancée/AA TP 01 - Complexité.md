On considère un tableau de la forme suivante `X=[e1, e2, ..., en]` avec  $n \in \mathbb{N}^*$.  
où chaque $e_i$ est un entier (positif, nul ou négatif).  
L’algorithme doit **déterminer la plus grande somme possible d’un sous-tableau contigu** de `X`.  
Autrement dit, on cherche :

$$
\underset{1≤g≤d≤n}{max} \; \sum_{i=g}^{d} e_{i}​
$$

où $g$ est l’indice de début et $d$ l’indice de fin du sous-tableau.

<u>Exemple :</u>  
Prenons en compte le tableau $X=[-2, 1, -3, 4, -1, 2, 1, -5, 4]$.  
Regardons ce que devrait renvoyer l’algorithme après la fin du traitement. 
- $[-2] = -2$  
  Pas considéré car $-2 < 0$.
- $[1] = 1$  
  La somme maximale devient $S_{max}=1$
- $[1, -3] = -2$  
  La somme maximale reste $1$
- $[4, -1, 2, 1]=6$  
  La somme max devient $6$
- $[-5]=-5$
- $[4]=4$

Ainsi, à la fin de cet algorithme, il devra renvoyer la sous-séquence $[4, -1, 2, 1]$ qui a pour somme max $6$.

- Premier algorithme proposé pour résoudre le problème

On considère ici que `X` représente le tableau, `maxS` la somme maximale et `S` la somme du sous-tableau courant.
```
maxS = 0
for(g=0 ; g<n; g++){
	for(d=g ; d<n ; d++){
		S = 0
		for(i=g ; i<=d ; i++){
			S += X[i]
			if(maxS < S){
				maxS = S
			}
		}
	}
}
```

On cherche à savoir si notre programme est efficace ou non, pour ce faire il faut que l'on arrive à déterminer la complexité de ce dernier.  
L'instruction qui s'exécutera le plus de fois dans notre code est :
```
S += X[i]
```
Car :
- La boucle `for(g=0 ; g<n ; g++)` sera exécutée `n` fois.
- La boucle `for(d=g ; d<=n ; d++` sera exécutée environ `n-g` fois
- La boucle `for(i=g; i<=d ; i++)` sera exécutée environ `d-g+1` fois.  
  *On rajoute $+1$ car on a $i \leq d$, c'est le **ou égal** qui implique le rajoute du $1$*. 

Ainsi l'instruction `S += i` sera exécutée environ : 

$$
\underset{g=0}{\overset{n-1}{\sum\limits}}\underset{d=g}{\overset{n-1}{\sum\limits}}(d-g+1)
$$

On peut aussi le faire comme M.Balev, avec le fameux tableau :


<div>
    <div class="table-wrap">
      <table class="static-table" aria-label="tableau g sur d statique">
        <thead>
          <tr>
            <th>g \ d</th>
            <th>0</th>
            <th>1</th>
            <th>2</th>
            <th>3</th>
            <th>...</th>
            <th>n-2</th>
            <th>n-1</th>
          </tr>
        </thead>
        <tbody>
          <tr>
            <th scope="row">0</th>
            <td class="num">1</td>
            <td class="num">2</td>
            <td class="num">3</td>
            <td class="num">4</td>
            <td class="num">...</td>
            <td class="num">n-1</td>
            <td class="num">n</td>
          </tr>
          <tr>
            <th scope="row">1</th>
            <td class="dash">-</td>
            <td class="num">1</td>
            <td class="num">2</td>
            <td class="num">3</td>
            <td class="num">...</td>
            <td class="num">n-2</td>
            <td class="num">n-1</td>
          </tr>
          <tr>
            <th scope="row">2</th>
            <td class="dash">-</td>
            <td class="dash">-</td>
            <td class="num">1</td>
            <td class="num">2</td>
            <td class="num">...</td>
            <td class="num">n-3</td>
            <td class="num">n-2</td>
          </tr>
          <tr>
            <th scope="row">3</th>
            <td class="dash">-</td>
            <td class="dash">-</td>
            <td class="dash">-</td>
            <td class="num">1</td>
            <td class="num">...</td>
            <td class="num">n-4</td>
            <td class="num">n-3</td>
          </tr>
          <tr>
            <th scope="row">...</th>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
          </tr>
          <tr>
            <th scope="row">n-2</th>
            <td class="dash">-</td>
            <td class="dash">-</td>
            <td class="dash">-</td>
            <td class="dash">-</td>
            <td class="num">...</td>
            <td class="num">1</td>
            <td class="num">2</td>
          </tr>
          <tr>
            <th scope="row">n-1</th>
            <td class="dash">-</td>
            <td class="dash">-</td>
            <td class="dash">-</td>
            <td class="dash">-</td>
            <td class="num">...</td>
            <td class="dash">-</td>
            <td class="num">1</td>
          </tr>
        </tbody>
      </table>
    </div>
</div>
