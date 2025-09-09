On considère un tableau de la forme suivante `X=[e1, e2, ..., en]` avec  $n \in \mathbb{N}^*$.  
où chaque $e_i$ est un entier (positif, nul ou négatif).  
L’algorithme doit **déterminer la plus grande somme possible d’un sous-tableau contigu** de `X`.  
Autrement dit, on cherche :

$$
\underset{1≤g≤d≤n}{max} \; \sum_{i=g}^{d} e_{i}​
$$

où $g$ est l’indice de début et $d$ l’indice de fin du sous-tableau.

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
