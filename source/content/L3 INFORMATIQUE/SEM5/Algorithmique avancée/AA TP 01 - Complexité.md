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
  *On rajoute $+1$ car on a $i \leq d$, c'est le **"ou égal"** qui implique le rajout du $1$*. 

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

>[!warning]
>Si $n>d$ il ne se passe rien,  l'instruction ne s'exécute pas !

Maintenant, il faut additionner tous les termes du tableau afin de savoir sur quelle complexité on est. En fait, chaque ligne représente la somme des $i$ allants de $1$ à $n$, puis de $1$ à $n-1$, et ainsi de suite.   
Ainsi la somme des éléments du tableau sera donnée par : 

$$
nb_{exec}=\underbrace{\underset{i=1}{\overset{n}{\sum\limits}}i}_{\text{ligne }g=0}+\underbrace{\underset{i=1}{\overset{n-1}{\sum\limits}}i}_{\text{ligne }g=1}+\underbrace{\underset{i=1}{\overset{n-2}{\sum\limits}}i}_{\text{ligne }g=2}+\underbrace{\underset{i=1}{\overset{n-3}{\sum\limits}}i}_{\text{ligne }g=3}+\ldots+3+1
$$

Ainsi on peut simplifier cette expression car la somme des $i$ allant de $1$ à $n$ est donnée par :

$$
\dfrac{n(n+1)}{2}
$$

Ainsi : 

$$
nb_{exec} = \dfrac{n(n+1)}{2}+\dfrac{n(n-1)}{2}+\dfrac{(n-2)(n-1)}{2}+\dfrac{(n-3)(n-2)}{2}+\ldots+2+1=\underset{k=1}{\overset{n}{\sum\limits}}\dfrac{k(k+1)}{2}
$$

Il faut donc réussir à simplifier cette expression.

$$
\begin{align*}
nb_{exec} &= \underset{k=1}{\overset{n}{\sum\limits}}\dfrac{k(k+1)}{2} \\
&= \dfrac{1}{2}\underset{k=1}{\overset{n}{\sum\limits}}(k(k+1))\\
&= \dfrac{1}{2}\underset{k=1}{\overset{n}{\sum\limits}}(k^2+k)\\
&= \dfrac{1}{2}\underset{k=1}{\overset{n}{\sum\limits}}k²+\underset{k=1}{\overset{n}{\sum\limits}}k \\
&= \dfrac{1}{2}\left( \dfrac{n(n+1)(2n+1)}{6}+\dfrac{n(n+1)}{2} \right) \\
&= \dfrac{1}{2}\left( \dfrac{n(n+1)(2n+1)+3(n(n+1))}{6}\right)\\
&= \dfrac{n(n+1)(2n+1)+3(n(n+1))}{12}\\
&= \Theta(n³)
\end{align*}
$$

On se retrouve alors avec un algorithme de complexité cubique, autant dire que ce n'est pas très efficace en réalité...

Cherchons alors un moyen de réduire la complexité de cette algorithme, pour résoudre le même problème.  
On sait que l'instruction la plus utilisée est `S+=X[i]`.  
On peut éviter de recalculer la somme courante à chaque fois, au lieu de repartir de $0$ à chaque fois pour chaque `(g, d)`, on peut simplement ajouter le nouvel élément `X[d]` à la somme courante.

On obtient alors l'algorithme suivant :
```
maxS = 0;
for (g = 0; g < n; g++) {
    S = 0;
    for (d = g; d < n; d++) {
        S += X[d];
        if (S > maxS) {
            maxS = S;
        }
    }
}
```

Ainsi,
- La première boucle est exécutée $n$ fois
- La seconde boucle est exécutée $n-g$ fois

L'instruction `S += X[d]` est donc exécutée :

$$
\underset{g=0}{\overset{n-1}{\sum\limits}}(n-g) = n+(n-1)+(n-2)+\ldots+2+1=\dfrac{n(n-1)}{2}
$$

fois.  
Le nombre d'exécution de l'instruction est donné par la complexité $\Theta(n^{2})$.

On se demande si il est encore possible d'améliorer l'algorithmes.  
On peut utiliser l'algorithme **diviser pour reigner**, qui consiste à diviser le tableau en $2$ parties puis comparer les deux sommes. Hors cela n'est pas suffisant car si la sous séquences max se trouve au milieu du tableau, on en le saura pas, il faut donc aussi calculer les sommes max aux frontières gauche et aux frointières droite du tableau en partant du milieu.  


On obtient alors le troisième algorithme :
```java
algo(g, d){
  if (g>d) return 0;
  if (g==d) return max (X[g], 0);
  
  // Cas ou il y au moins deux éléments
  int m = (g+d)/2;
  int S1 = algo(g, m)
  int S2 = algo(m+1, d)
  
  // On calcule les deux sommes aux frontières
  // Frontière gauche
  int S3 = 0, S = 0;
  for(int i = m; i >= g; i--){
    S += X[i]
    if(S > S3) S3 = S;
  }  
  // Frontière droite
  int S4 = 0;
  S = 0;
  for(int i = m+1; i<=d; i++){
    S+=X[i];
    if (S>S4) S4=S;
  }
  return max(S1, S2, S3, S4);
}
```

Les compléxités sont données par :
- $T(1) = Cst$
- $T(2) = 2T(\frac{n}{2})+an+b=\Theta(nlog(n))$

On a réussit à partir d'un algo de complexité $n^3$ pour arriver à une complexité de $n log (n)$.  

On se retrouve alors avec $3$ algorithmes que l'on nomera `algo1`, `algo2` et `algo3` respectivement.  
Chacun de complexité :
- $algo_1 = \Theta(n^3)$
- $algo_2=\Theta(n^2)$
- $algo_3 = \Theta(n\times log(n))$

On se demande si il est **encore** possible d'améliorer.  
Et oui, il est encore possible d'améliorer l'algorithme.

On considère $maxS = [a \ldots b]$ la somme de la sous séquences des indices $a$ jusqu'à $b$ et $maxI= la somme maximale qui se termine par $X[i]$.
Au départ, avant de commencer à parcourir le tableau, les deux sommes sont égales, c'est à dire nulle. Ensuite on parcours chaque élément du tableau et garde à chaque fois le max des valeurs.

On obtient l'algorithme suivant : 
```java
algo(X, n){
	maxS = max I = 0
	for(int i = 0; i<n; i++){
		maxI = max(maxI+X[i], 0);
		maxS = max(maxS, maxI);
	}
}
```

Ainsi en étudiant l'algorithme pour sa complexité en fonction de la taille de $X$, on obtient : 
- $T(1)=1$
- $T(n) = n+k = \Theta(n)$

On peut encore se demander si il est possible d'améliorer l'algorithme.  
En fait, la réponse semble plutôt évidente car on est obligé de parcourir au moins une fois les $n$ éléments du tableau pour les comparer et ne pas les oublier. Alors la complexité minimale de l'algorithme est bien donnée par $\theta(n)$.
