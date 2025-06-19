## Supplément de révisions - K. REINE
### Correction de l'examen - SESSION 2024
> Cette correction peut être erronée car faite à partir de mes connaissances, si vous trouvez des erreurs, n'hésitez pas !

### 1) Algorithmique de codage binaire
Dans cette section, on s'intéresse au codage binaire d'un entier. Pour cela on propose l'algorithme $\mathcal{A}$ ci-dessous. Cet algorithme utilise le type `vecteurBooleen`. On suppose que si `v` est un `vecteurBooleen`, `l(v)` retourne sa longueur (nombre de coordonnées) et `v[i]` permet d'accéder (de modifier, ou même de créer) sa `i`-ème coordonnée, avec $0 \leq i < l(v)$. `vecteurVide()` crée un vecteur booléen vide.

*Algorithme $\mathcal{A}$*
```
Entree :
	k un entier
Sortie :
	un vecteurBooleen
variables :
	n,i deux entiers entiers
	v un vecteurBooleen

debut A
	n <- k; i <- 0; v <- vecteurVide()
	TANT QUE ( n >= 1) FAIRE
		SI (n MOD 2 = 0) ALORS
			v[i] <- 0
		SINON v[i] <- 1
		FIN SI
		n <- n DIV 2; i++
	FIN TANT QUE
	RETOURNER v
fin A
```

1) Montrer que l'algorithme $\mathcal{A}$ se termine. Pour cela vous utiliserez un variant. Lequel ?

Pour commencer, on peut récapituler ce que fait l'algorithme $\mathcal{A}$.
```
INITIALISATION
	n = k
	i = 0
	v = []
BOUCLE TANT QUE n >= 1
FIN lorsque n<1
	SI n pair : v[i]=0
	SI n impair : v[i]=0
	n = quotient divEuclidienne n/2
	i + 1
FIN BOUCLE
Renvoyer le vecteur créé
```

L'algorithme $\mathcal{A}$ admet une boucle `TANT QUE`, c'est sur elle que nous allons "zoomer" pour déterminer un variant de boucle.
>[!tip] Rappel
>Un variant noté $V$ est une valeur entière qui décroit strictement à chaque itération d'un algorithme.

On remarque dans la boucle qu'à chaque itérations, on divisera la variable `n` par `2`. Ainsi, cela revient à dire que dans tous les cas la valeur de `n` à l'itération `i+1` sera toujours plus petite que la valeur de `n` à l'itération `i`. D'où `n` décroit à chaque itérations, alors il y aura forcément un moment où `n<1` alors la boucle `while` s'arrêtera et l'algorithme pourra se terminer en renvoyant le `vecteurBooleen` créé. $$V=n$$
En conclusion, on définit un variant $V=n$ qui permet de montrer qu'à chaque itération il diminue jusqu'à forcément devenir plus petit que $1$, dans ce cas, après un certain nombre d'itérations, la boucle `while` vas se stopper et l'algorithme se terminera en renvoyant le vecteur `v`.

2) L'objectif de l'algorithme $\mathcal{A}$ c'est de retourner un vecteur contenant les chiffres de l'entrée $k$ écrite en binaire. Par définition si `w` est ce vecteur, on doit avoir : $$k=\underset{i=0}{\overset{l(w)-1}{\sum}}w[i] \times2^i$$
   On vas montrer que le vecteur `v` résultat de l'algorithme vérifie bien cette égalité. Pour cela, on va montrer par récurrence sur $i$ l'existence d'un invariant.
   Notons $n_i$ la valeur de $n$ au début de la $i-ème$ itération. 
   Soit alors $$I(i)=2^i \times n_i + \underset{j=0}{\overset{i-1}{\sum}}v[j]\times2^j$$Montrer que la fonction $I$ est un invariant, c'est à dire qu'elle est constante pour tout $i$ lors de l'algorithme. Votre preuve sera par récurrence sur $i$.

Soit $i \in \mathbb{N}$ la $i-ème$ itération de l'algorithme.
Alors : 
- **INITIALISATION**
  Pour $i=0$ alors on a :
  On se trouve avant la boucle `while`, à ce moment là, au début de tout l'algorithme, avant d'entrer dans la boucle, on a :
	$n_0=k$
	$v=[]$
	$i=0$ 
	$$
	\begin{align*}
	I(0) &= 2^0 \times n_0+\underbrace{\underset{j=0}{\overset{0-1}{\sum}}v[j]\times2^j}_{\text{non définie}} \\
	&= 1 \times k + 0 \\
	&= k
	\end{align*}
	$$
	Alors on a $I(n_0)=k$ ainsi l'initialisation est vérifiée et montre que $I$ est un invariant.
- **HÉRÉDITÉ**
	On suppose que $I$ est un invariant pour un $i \in \mathbb{N}$ fixé, en gros on suppose que $I$ est un variant pour toutes les itérations $i$. On chercher à montrer que $I(i+1)$ est aussi un invariant.
	Soit $i$ l'itération $n°i$ alors on sait que :
		$v[i]=n_i MOD 2$
		$n_{i+1} = n_i DIV 2$
	Ainsi on se retrouve avec :
	$$
		\begin{align*}
		I(i+1) &= 2^{i+1} \times \underbrace{n_{i+1}}_{=(n_i DIV2)}+\underset{j=0}{\overset{i}{\sum}}v[j]\times2^j \\
		 &=2^{i+1} \times (n_i DIV 2)+\underset{j=0}{\overset{i}{\sum}}v[j]\times2^j \\
		 &= 2^{i+1} \times (n_i DIV 2)+\underset{j=0}{\overset{i-1}{\sum}}v[j]\times2^j+\underbrace{v[i+1]}_{=(n_i MOD 2)}\times2^{i} \\
		 &= 2^{i+1} \times (n_i DIV 2)+\underset{j=0}{\overset{i-1}{\sum}}v[j]\times2^j+(n_iMOD2)\times2^{i}
		\end{align*}
	$$
	Je peux utiliser les propriétés des divisions euclidiennes.
	Soit $a,b \in \mathbb{N}$ alors $$a=bq+r$$
	où :
	- $q$ est le quotient
	- $r$ le reste
	Dans notre cas :
	- $a=n_i$
	- $b=2$
	- $q=(n_iDIV2)$
	- $r=(n_iMOD2)$
	On cherche la valeur de $(n_iDIV2)$ donc si on repart de la formule de base de la division euclidienne de deux entiers on a : 
	$$
	\begin{align*}
		n_i & = 2 \times(n_iDIV2)+(n_iMOD2) \\
		(n_iDIV2) &= \frac{n_i - (n_iMOD2)}{2}
	\end{align*}
	$$
	D'où :
	$$
	\begin{align*}
	I(i+1)&= 2^{i+1} \times (n_i DIV 2)+\underset{j=0}{\overset{i-1}{\sum}}v[j]\times2^j+(n_iMOD2)\times2^{i} \\
	&= 2^{i+1} \times \frac{n_i-(n_iMOD2)}{2}+\underset{j=0}{\overset{i-1}{\sum}}v[j]\times2^j+(n_iMOD2)\times2^{i} \\
	&= 2^{i} \times 2\times \frac{n_i-(n_iMOD2)}{2}+\underset{j=0}{\overset{i-1}{\sum}}v[j]\times2^j+(n_iMOD2)\times2^{i} \\
	&= 2^{i} \times [n_i-(n_iMOD2)]+\underset{j=0}{\overset{i-1}{\sum}}v[j]\times2^j+(n_iMOD2)\times2^{i} \\
	&= 2^in_i-2^i(n_iMOD2)+\underset{j=0}{\overset{i-1}{\sum}}v[j]\times2^j+(n_iMOD2)\times2^{i} \\
	&= 2^in_i\cancel{-2^i(n_iMOD2)}+\underset{j=0}{\overset{i-1}{\sum}}v[j]\times2^j+\cancel{(n_iMOD2)\times2^{i}} \\
	&= 2^in_i+\underset{j=0}{\overset{i-1}{\sum}}v[j]\times2^j \\
	&= I(i)
	\end{align*}$$

Ainsi notre invariant $I$ reste valide avant pendant et après la boucle `while`. 
Ainsi $I$ est un invariant de l'algorithme $\mathcal{A}$ et on a :
	$$I(l(w))=2^{l(w)}\times n_{l(w)}+\underset{j=0}{\overset{l(w)-1}{\sum}}v[j]2^j=k \quad et \quad k=\underset{j=0}{\overset{l(w)-1}{\sum}}w[j]2^j$$
3) Supposons que $k$ soit une puissance de $2$ avec $k=2^p$ où $p$ est un entier positif. En déduire que le nombre d'itérations de $\mathcal{A}$ est exactement égal à $p+1$.

Puisque $k$ est une puissance de $2$ alors :
- $k=2^p$ avec $p$ positif
On vas alors regarder ce qu'il se passe au début, au milieu et à la fin de l'algorithme $\mathcal{A}$ à chaque itérations.
<u>À chaque itération</u>
- $v[i]=n_i MOD 2$
- $n_i = n_i DIV 2$

Regardons ce qu'il se passe pour l'algorithme $\mathcal{A}$ lorsque l'on prend $k=2^p$ comme entrée.
- Pour $i=0$
  Alors, on se trouve avant la boucle, c'est là où on initialise nos variables.
  Alors :
	- $n_i=2^p$
	- $v[0]=n_0 MOD 2 = 2^p MOD 2 = 0$ ($2^p MOD 2 =0 \quad \forall p \geq 1$)
- Pour $i=1$
	- $n_1 = 2^{p-1}$ 
	- $v[1]=n_1 MOD 2 = 0$
	- $n_2 = n_1 DIV 2 = 2^{p-2}$
- Pour une boucle générale $i \in \mathbb{N}$
	- $n_i=2^{p-i}$
	- $v[i]=n_i MOD 2 = 0$
- Pour $i=p-1$
	- $n_{p-1}=2^{p-(p-1)}=2^1=2$
	- $v[p-1]=n_{p-1}MOD2=2MOD2=0$
- Pour $i=p$
	- $n_p=2^{p-p}=2^0=1$
	- $v[p]=n_p MOD 2 = 1 MOD 2 = 1$
	- $n_{p+1}=1 DIV 2 < 1$
Puisque $n_{p+1}$ devient inférieur à $1$ alors la boucle s'arrête à l'itération $p+1$, ce qui montre bien que pour $k=2^p$ on fait $p+1$ itérations.
Cela montre aussi que :
$$k=2^p \Longrightarrow v=[\underbrace{0, 0, 0, \ldots}_{n-fois}, 1]$$
3) On admettra que si $2^{p-1} \leq k < 2^p$, alors le nombre d'itérations de l'algorithme est égal à $p$. En déduire le complexité de l'algorithme.

On admet que $2^{p-1} \leq k < 2^p$ alors : 
$$
\begin{align*}
2^{p-1} & \leq k &< p \\
p-1 &\leq log_2(k) &< p \\
p & \leq log_2(k)+1 &< p+1
\end{align*}
$$
Puisque on dit que le nombre d'itérations de l'algorithme est égal à $p$, et que $p$ est de l'ordre de $log_2(k)+1$ alors la complexité de l'algorithme $\mathcal{A}$ est donnée par :
$$\Theta(log (k))$$
### Algorithme mystère
Soit l'algorithme suivant *(le type `VecteurBooleen` est défini dans la première question)*
*Algorithme $\mathcal{B}$*
```
Entrees :
	x un entier
	v un vecteurBooleen
Sortie :
	un réel

debut B
	R <- 1; u <- x
	pour (i = 0 -> l(v)-1) faire
		si v[i]=1 alors 
			R <- R*u
		fin si
		u <- u*u
	fin pour
	retourner R
fin B
```

1) **TESTS** Appliquer l'algorithme aux entrées suivantes en donnant bien l'évolution des variables `R` et `u` :
$$(3, [1, 1]) \quad (\frac{1}{2}, [0, 0, 1]) \quad (2, [1, 0, 1])$$
À votre avis, que fait cet algorithme ?

Nous allons commencer par effectuer les tests un par un en détaillant les valeurs de `R` et de `u` lors de l'exécution.
- Pour $(3, [1, 1])$
	- INIT
	  $R=1$ et $u=3$ 
	- Boucle `pour`
	  Elle vas de $0$ à $l(v)-1$ et comme $l(v)=2$, la boucle vas de $0$ jusqu'à $1$.
		- Pour l'itération $i=0$
		  $v[0]=1$ alors $R = R \times u = 1 \times 3 = 3$
		  $u=u^2=3^2=9$
		- Pour l'itération $i=1$
		  $v[1]=1$ alors $R=R \times u=3 \times 9=27$
		- $u=u^2=9^2=81$
	- SORTIE de la boucle
	  à la sortie de la boucle, on se retrouve avec $R=27$ et $u=81$.
	- SORTIE de l'algorithme
	  L'algorithme renvoi la valeur de $R$ qui ici est $27$ ainsi : $$\mathcal{B}(3, [1, 1]) = 27$$
- Pour $(1/2, [0, 0 ,1])$
	- INIT
	  $R=1$ et $u=1/2$
	- Boucle `pour`
	  Elle vas de $0$ à $l(v)-1$, et puisque $l(v)=3$ alors la boucle pour itère pour $i$ de $0$ à $2$.
		- Pour l'itération $i=0$
		  $v[0]=0$ alors la valeur de $R$ ne change pas
		  $u=u^2=(1/2)^2=1/4$
		- Pour l'itération $i=1$
		  $v[1]=0$ alors la valeur de $R$ ne change pas
		  $u=u^2=(1/4)^2=1/16$
		- Pour l'itération $i=2$
		  $v[2]=1$ alors $R=R \times u=1 \times 1/16=1/16$
		  $u=u^2=(1/16)^2$
	- SORTIE de la boucle
	  En sortie de boucle, la valeur de $R=1/16$.
	- SORTIE de l'algorithme
	  L'algorithme renvoi $R$ qui ici vaut $1/16$. d'où $$\mathcal{B}(1/2, [0, 0, 1])=1/16$$

- Pour $(2, [1, 0, 1])$
	- INIT
	  $R=1$ et $u=2$
	- Boucle `pour`
	  Elle vas de $0$ à $2$ puisque $l(v)=3$ donc $l(v)-1=2$.
		- Pour l'itération $i=0$
		  $v[0]=1$ alors $R=R \times u=1 \times 2=2$
		  $u=u^2=2^2=4$
		- Pour l'itération $i=1$
		  $v[1]=0$ alors $R$ reste inchangé.
		  $u=u^2=4^2=16$
		- Pour l'itération $i=2$
		  $v[2]=1$ alors $R=R \times u = 2 \times 16 = 32$
		  $u=u^2=16^2$
	- SORTIE de la boucle
	  En sortie de la boucle pour $R=32$.
	- SORTIE de l'algorithme
	  A la fin, l'algorithme renvoi la valeur de $R$ qui ici est $32$, on note $$\mathcal{B}(2, [1, 0, 1])=32$$
On cherche maintenant à savoir ce que fait cet algorithme. Pour rappel le paramètre $v$ est un `vecteurBooleen` qui donne le code d'un nombre en base $2$ regardons si cette aspect peut nous aider à comprendre.
Pour chaque test :
- $[1, 1]=2^0+2^1=0+2=3$
- $[0, 0, 1]=2^2=4$
- $[1, 0, 1]=2^0+2^2=1+4=5$
Et là, on regarde les sorties des algorithmes et on se rend très vite compte que :
$$\mathcal{B}(3, [1, 1])=27 \Longleftrightarrow 3^{(1,1)_2}=3^3=27$$
$$\mathcal{B}(1/2, [0, 0, 1])=1/16 \Longleftrightarrow 1/2^{(0, 0, 1)_2}=1/2^4=1/16$$
$$\mathcal{B}(2, [1, 0, 1])=32 \Longleftrightarrow 2^{(1,0,1)_2}=2^5=32$$Ainsi, l'algorithme $\mathcal{B}$ permet de calculer la $x$ à la puissance $z$ où $z$ représente le nombre en base $2$ contenu dans le vecteur $v$.

2) Montrer simplement que l'algorithme $\mathcal{B}$ se termine.

L'algorithme $\mathcal{B}$ ne possède aucune boucle infinie (`while`), la seule boucle qu'il possède est une boucle `for` qui vas de $0$ à $l(v)-1$ et puisque la taille du `vecteurBooleen v` est déterminé début de l'algorithme alors la boucle pour se terminera forcément après un nombre fini d'itération, pur être exact au bout de $l(v)$ itérations. Ainsi, l'algorithme $\mathcal{B}$ n'est pas infini, il se finira forcément et renverra une valeur pour $R$.

3) On suppose dans la suite que l'algorithme $\mathcal{B}$ est correct. Donnez la complexité de l'algorithme en fonction de $l(v)$, en utilisant la notation de Landau $\Theta$. On supposera que l'opération de multiplication de $2$ réels est une opération élémentaire.

Si on reprends l'algorithme $\mathcal{B}$, on remarque que peut importe le contenu du vecteur $v$ qu'il ne contienne que des $1$, que des $0$ ou les deux, cela ne changera rien à l'exécution de cet algorithme puisque dans tous les cas la boucle pour itérera de $0$ à $l(v)-1$.
Ainsi le nombre d'itérations est donné par $1+l(v)-1=l(v)$, l'algorithme $\mathcal{B}$ effectuera dans tous les cas $l(v)$ fois la boucle pour.
D'où : $$\Theta(l(v))$$
### Algorithme de calcul d'une puissance

Soit l'algorithme ci-dessous.
*Algorithme $\mathcal{C}$*
```
Entrees :
	x un réel
	k un entier
Sortie :
	reel
Variable :
	vecteurBooleen v

debut C
	v <- A(k)
	retourner B(x ,v)
fin
```

1) Expliquer (sans prouver sa correction) pourquoi l'algorithme $\mathcal{C}$ calcul bien $x^k$. Déduire des deux sections précédentes la complexité de l'algorithme $\mathcal{C}$ en fonction de $k$.

L'algorithme $\mathcal{C}$ :
- Il permet de créer un `vecteurBooleen v` grâce à l'algorithme $\mathcal{A}$. En fait, ici le vecteur vas contenir le codage de l'entier $k$ en binaire.
- Il retourne le réel $x$ élevé à la puissance du nombre codé en base $2$ dans le vecteur $v$ et puisque l'on a défini à l'instant que $v$ contient le codage de $k$ alors l'algorithme $\mathcal{C}$ retourne bien $x^k$.

Si on récupère les deux complexités précédentes :
- $C(\mathcal{A}) = \Theta(log(k))$
- $C(\mathcal{B})=\Theta(l(v))$

On sait que $l(v)$ représente la taille du vecteur $v$ qui représente la taille de l'entrée et qui suit en fait $O(log(k))$ en terme d'ordre de grandeur alors on se retrouve avec :
$$C(\mathcal{C})=C(\mathcal{A})+C(\mathcal{B})=\Theta(log(k))+\Theta(log(k))=\Theta(log(k))$$
La complexité de l'algorithme $\mathcal{C}$ est donnée par $\Theta(log(k))$.