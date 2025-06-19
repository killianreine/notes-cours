## Exercice 1
Une entreprise emploie 500 personnes qui déjeunent à la cantine à l'un ou à l'autre des deux services avec une probabilité égale de manger au premier ou au second service. Si le gérant veut avoir une probabilité supérieure à $95\%$ de disposer d'assez de couverts, combien devra-t-il en prévoir pour chacun des deux services.

*Avant de commencer à répondre aux questions*
Je récupère les informations importantes de l'exercice :
- effectif total $n=500$ 
- Notons $1$ le fait de "manger au premier service" et $0$ "manger au second service". Ainsi, puisque les probabilités de manger à l'un ou à l'autre des service doivent être égales. Alors, chaque employé a $\frac{1}{2}$ chance de manger au premier ou au second service.
  On note alors
  $$P(0)=P(1)=\frac{1}{2}$$
- On cherche combien de couverts **minimum** le gérant doit-il disposer à chaque service pour en avoir assez. On notera ce nombre $k$.

1. **On numérote les personnes par ordre alphabétique . On note $X_i$ la variable aléatoire valant $1$ si la $ième$ personne mange au premier service sinon $0$. Quelle est la loi de $X_i$ pour $1\leq i\leq500$ ?**
Les deux possibilités le la loi $X_i$ peuvent être vu comme un échec ou une victoire, ainsi $X_i$ suit une loi de Bernoulli de paramètre $P$.
On note :
$$X_i \leadsto Ber(P)$$
Et lorsque l'on a récupéré les infos, on a défini la loi qui dit que :
$$P(X_i=0)=\underbrace{1-P(X_i=0)}_{P(X_i=1)}=\frac{1}{2}$$
Ainsi on a :
$$X_i \leadsto Ber\left(\frac{1}{2}\right)$$

2. **On suppose que les variables aléatoires $X_i$ sont indépendantes pour $1 \leq i \leq 500$. Quelle est la loi exacte de la variable aléatoire** $$S_n = \underset{i=1}{\overset{500}{\sum}}X_i$$
L'hypothèse de la question dit que chaque variable $X_i$ sont indépendantes, cela semble raisonnable dans le cas d'une numérotation par ordre alphabétique.
On rappel que l'on chercher le nombre minimum $k$ de couverts à positionner à chaque services.
Ici, dans notre cas, $S_n$ représente le nombre de personnes qui mangent au premier service. On note alors :
$$P(X_i = 1) = S_n$$
Si $S_n$ détermine le nombre de personnes qui mangent au premier service, alors le restant mangeront au second service, on note alors : $$P(X_i=0)=500-S_n$$
Ainsi on chercher le nombre minimum de couverts $k$ à disposer à chaque service, pour être certain de disposer d'assez de couverts à chaque service.
C'est à dire : $$S_n \leq k \quad et \quad 500-S_n \leq k$$
La loi exacte de la variable aléatoire $X_i$ est alors donnée par : $$P(S_n\leq k \quad et \quad 500-S_n \leq k) \geq 0.95$$
La loi de $S_n$ est une loi binomiale $\mathcal{B}(\underbrace{n}_{effectif}, \underbrace{p}_{proba})=\mathcal{B}(500, \frac{1}{2}$).

3. **Calculer $E(S_n)$ et $Var(S_n)$.**
>==**Rappel**==
>- $E(S_n)$ représente l'espérance.
>- $Var(S_n)$ représente la variance.
>Puisque $S_n$ suit une loi binomiale tel que $X_i \leadsto \mathcal{B}(n, p)$ alors on a : $$E(S_n) = n \times p \quad et \quad Var(S_n)=npq=np(1-p)$$
>où $q$ représente la probabilité "d'échec", autrement dit $q=1-p$.

Ainsi, en utilisant le rappel fourni on a :
$$E(S_n)=500 \times \frac{1}{2}=250 \quad et \quad Var(S_n)=500 \times \frac{1}{2}\times(1-\frac{1}{2})=125$$
4. **Que représente la variable aléatoire $(500-S_n)$ dans le contexte ?**
Comme évoquée précédemment, la variable aléatoire notée $(500-S_n)$ représente en fait le nombre de personnes qui mangent au second service.

5. **Par quelle loi peut-on approcher la loi de $S_n$ ? Préciser ses paramètres.**
On utilise une loi normale de paramètres :
$$S_n^* \leadsto \mathcal{N}(\mu, \sigma^2)=\mathcal{N}(E(S_n), Var(S_n))=\mathcal{N}(250, 125)$$
On peut approcher cette loi à l'aider d'un loi normale centrée et réduite.
>==**Rappel**==
>Lorsque l'on souhaite centrer et réduire une loi normale, alors pour une variable $X$ tel que $$X \leadsto \mathcal{N}(\mu, \sigma^2)$$
>Pour centrer et réduire, afin de suivre une loi normale de paramètre $0$ et $1$, on a : $$\dfrac{X-\mu}{\sqrt{\sigma^2}} \leadsto \mathcal{N}(0, 1)$$

Que l'on vas noter $S_n^*$ défini par :
$$S_n^*=\dfrac{S_n-250}{\sqrt{125}} \leadsto \mathcal{N}(0, 1)$$

6. **Déterminer le paramètre $k$.**
On rappel que l'on cherche :
$$P(S_n\leq k \quad et \quad 500-S_n \leq k) \geq 0.95$$
On a :
- $500-S_n \leq k \Longleftrightarrow S_n \geq 500-k$
Ainsi on obtient alors
$$
P(500-k \leq S_n \leq k) \geq 0.95
$$ 
Ce qui donne en centrant et réduisant, en fin de compte :
$$
P\left(\frac{500-k-250}{\sqrt{125}} \leq S_n^* \leq \dfrac{k-250}{\sqrt{125}}\right)=P\left(\frac{250-k}{\sqrt{125}} \leq S_n^* \leq \dfrac{k-250}{\sqrt{125}}\right)
$$
où :$$\dfrac{S_n-250}{\sqrt{125}} \leadsto \mathcal{N}(0, 1)$$
En négligeant les erreurs d'approximation on cherche $k$ minium tel que : $$\phi\left( \dfrac{250-k}{\sqrt{125}} \right)-\phi\left( \dfrac{k-250}{\sqrt{125}} \right) \geq 0.95$$
>==**Rappel**==
>$$\phi(-x) = 1-\phi(x)$$

Ainsi grâce au rappel effectué on a :
$$2\phi\left( \dfrac{250-k}{\sqrt{125}} \right)-1 \geq 0.95 \Longleftrightarrow \phi\left( \dfrac{250-k}{\sqrt{125}} \right) = \dfrac{0.95+1}{2}=0.975$$
Ainsi on a :$$\phi\left( \dfrac{250-k}{\sqrt{125}} \right) =0.975$$
Par lecture des quantiles de la loi normale, on a $\phi(1.96)=0.975$.
Ainsi on a :
$$k \geq 250+1.96\times \sqrt{125} \Longleftrightarrow k \geq 271.91$$

7. **Interpréter la valeur de $k$ dans le contexte.**
Ainsi, puisque $k \geq 271.91$ pour que le gérant soit certain d'avoir assez de couverts pour les deux services à 95%, il doit placer au moins 272 couverts à chaque services.

## Exercice 2
Soit $X$ une variable aléatoire de loi gaussienne centrée et réduite et $b$ un nombre réel strictement positif fixé.

*Avant de commencer l'exercice*
Je récupère les infos importante.
- $X$ suit une loi gaussienne centrée et réduite $X \leadsto \mathcal{N}(0, 1)$.
- $b$ un réel strictement positif. $b>0$.

1. **Représenter $P(x < X<x+b)$ sur un graphique et faire apparaître la loi de $X$.**
Puisque $X \leadsto \mathcal{N}(0, 1)$ alors on peut représenter graphiquement la densité de la loi gaussienne centrée et réduite. 
![[fdd.png]]
Puisque $X$ suit une **loi gaussienne centrée et réduite** alors elle est de paramètres $(0, 1)=(\mu, \sigma^2)$. Admet une densité de la forme : $$f_d(x) = \dfrac{1}{\sigma\sqrt{2\pi}}e^{-\dfrac{1}{2}\dfrac{(x-\mu)^2}{\sigma^2}}$$
Ici, puisque $X$ suit une loi gaussienne centrée et réduite alors :
$$f_d(x) = \dfrac{1}{1^2\sqrt{2\pi}}e^{-\dfrac{1}{2}\dfrac{(x-0)^2}{1^2}}=\dfrac{1}{1^2\sqrt{2\pi}}e^{\dfrac{x^2}{2}}$$
On note $$h=P(x < X < x+b)$$
Ainsi on a : $$h=\phi(x)-\phi(x+b)$$
Où $\phi$ représente la **fonction de répartition** de $X$.

2. **Déterminer $x$ tel que $P(x < X < x+b)$ soit maximum.**
On cherche $x$ tel que $h'(x)=0$.
C'est à dire :
$$
\begin{align*}
h'(x) &= 0 \\
\phi'(x)-\phi'(x+b) &= 0 \\
f(x)-f(x+b) &=0
\end{align*}
$$
Ce qui revient à dire que $(x+b)^2=x^2$.
En gros on a :
$$
\begin{cases}
x+b &= x \quad \text{ impossible car }b=0 \text{ impossible}
\\ x+b &= -x
\end{cases}
$$
On a alors d'après la seconde ligne :
$2x=-b$ d'où $x=-\frac{b}{2}$.
Donc $h''(x)<0$.

3. **Exprimer cette probabilité maximum en fonction de $\phi$ la fonction de répartition de $X$. Pour quelle valeur de $x$ est-elle égale à $0.95$ ?**
Ainsi, on a :
$$
\begin{align*}
P(x<X<x+b) &= P\left(-\frac{b}{2} < X < -\frac{b}{2}+b\right) &=0.95 \\
&= P\left(-\frac{b}{2} < X < \frac{b}{2}\right) &= 0.95 \\
&= \phi\left( -\frac{b}{2}\right)+\phi\left(\frac{b}{2}\right) &= 0.95 \\
&= 2\phi\left(\frac{b}{2}\right)-1 &= 0.95 \\
\end{align*}
$$
On cherche donc $b$ tel que :
$$
\begin{align*}
2\phi\left(\frac{b}{2}\right)-1 &= 0.95 \\
\phi\left(\frac{b}{2}\right)&= \dfrac{0.95+1}{2} = 0.975
\end{align*}
$$
Par lecture de la table de la loi normale centrée et réduite on a $\frac{b}{2}=1.96$ d'où $b=2 \times 1.96=2.92$.

## Exercice 3
*Lire sur la table du Khi-deux*.
Soit $X$ une variable aléatoire distribuée selon une loi du Khi-deux $X_n^2$.

1. **Déterminer la valeur de $x$ solution de l'équation $P(X \geq x)=0.01$ pour $n=7$.**
On a $X \leadsto \mathcal{X}(7)$. Puisque $X \geq x$, on peut directement lire la table $(0.01, 7)$ 
Et on trouve alors $x=18.475$. 

2. **Déterminer la valeur de $x$ solution de l'équation $P(X \leq x)=0.05$ pour $n=10$.**
On a $X \leadsto \mathcal{X}(10)$. Puisque $X \leq x$ alors, on ne peux pas lire directement sur la table.
Je vais alors calculer $1-P=1-0.05=0.95$ Ainsi je lit la table case $(0.95, 10)$.
Et on trouve alors $x=3.940$.

3. **Déterminer la valeur de $x$ solution de l'équation $P(X \leq x)=0.90$ pour $n=15**
On a $X \leadsto \mathcal{X}(15)$. Puisque $X \leq x$ alors, on ne peux pas lire directement sur la table.
Je vais alors calculer $1-P=1-0.9=0.1$ Ainsi je lit la table case $(0.1, 15)$.
Ainsi, on trouve $x=22.307$.

---
**Point méthode**
*Déterminer la solution d'une équation avec la table de Khi-deux.*
Soit $X$ une variable aléatoire qui suit une loi de Khi-deux de paramètre $n$.
- Pour $P(X \geq x)=\alpha$.
	- Je lis la table $ligne = n$ et $colonne = \alpha$
- Pour $P(X \leq x)=\alpha$
	- Je calcul $a = 1-\alpha$
	- Je lis la table à $ligne=n$ et $colonne = a$
---

## Exercice 4
*Lire sur la table de Student*
Soit $X$ une variable aléatoire distribuée qui suit une loi de Student $T_n$.

1. **Déterminer la valeur $x$ solution de l'équation $P (x \geq x) = 0.01$, pour $n=16$.**
On a $X \leadsto T_n(16)$ et $P(X \geq x)=0.01$.
Je sais que $0.01=\frac{0.02}{2}$ ainsi on lit la table à la ligne $16$ et à la colonne $0.02$.
On obtient $x=2.583$.

2. **Déterminer la valeur $x$ solution de l'équation $P (x \leq x) = 0.05$, pour $n=30$.**
On a $X \leadsto T_n(30)$ et $P(X \geq x)=0.05$.
Je sais que $0.05=\frac{0.1}{2}$, mais je suis dans le cas $X \leq x$ alors la table me donnera $-x$, ce sera à moi d'inverser le signe pour trouver mon inconnue.
En lisant la table à la ligne $30$ et à la colonne $0.1$,
On obtient $-x=1.697 \Longleftrightarrow x=-1.697$.

3. **Déterminer la valeur $x$ solution de l'équation $P (x \leq x) = 0.90$, pour $n=8$.**
On a $X \leadsto T_n(8)$ et $P(X \geq x)=0.90$.
Je sais que $0.90 = \frac{1.8}{2}$, Or $1.8>1$ alors, à la place du $0.9$ de départ on vas prendre $0.1$.
On recommence avec :
- $P(X \leq x) = 0.1$ et $n=8$.
Alors, on sait que $0.1=\frac{0.2}{2}$. On lit la table à la ligne $8$ et à la colonne $0.2$.
Ainsi on obtient $x=1.397$.

---
**Point méthode**
*Déterminer la solution d'une équation avec la table de Student.*
Soit $X$ une variable aléatoire qui suit une loi de Student $T_n$ de paramètre $n$.
- Pour $P(X \geq x)=\alpha$.
	- Je détermine $\beta = 2\alpha$
	- Je lis la table à la $ligne= n$ et $colonne=\beta$ 
- Pour $P(X \leq x)=\alpha$
	-  Je détermine $\beta = 2\alpha$
	- Je détermine $-x$ avec la table à la $ligne= n$ et $colonne=\beta$ 
	- J'inverse le signe pour trouver $x$
- Dans le cas où $\beta = 2\alpha > 1$ alors on recommence le raisonnement avec $\alpha=0.1$ donc en résolvant l'équation $P(X \leq x) = 0.1$.
---
