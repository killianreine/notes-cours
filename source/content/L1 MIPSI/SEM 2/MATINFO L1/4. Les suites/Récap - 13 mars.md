---

---
## 1 Les suites arithmétiques
### Définition générale
> ==Définition== *suite arithmétique*
> Soit $(u_n)_{n \in \mathbb{N}}$ une suite.
> On parle de **suite arithmétique** lorsque chaque terme suivant peut se déduire à partir du précédant un ajoutant un réel. Ce réel est souvent appelé **la raison** et est noté $r \in \mathbb{R}$.

Ainsi, en respectant la définition ci-dessus, nous sommes capable de déterminer le terme suivant d'une suite arithmétique.
$$
\Large{u_{n+1} = u_n+r}
$$
### Terme général $u_n$
Pour déterminer le terme général d'une suite arithmétique ($u_n$), rien de trop compliqué :
- On détermine la 'distance' entre le premier terme de la suite, et le terme $n$ à calculer. On notera ce dernier $N$.
- On ajoute alors $N-fois$ la raison $r$ au premier terme de la suite pour obtenir $u_n$.
Si on récapitule un peu.
**(1) On suppose que $u_0$ est le premier terme de la suite.**
	Alors on calcul la distance entre $u_0$ et $u_n$ qui est donnée par $N=n-0=n$ .
	Ainsi, on en déduit que :
	$$
	\Large{
	\begin{align*}
	u_n &= u_0 + \underbrace{r + r + \ldots+r}_{N-fois}
	\\ &= u_0 + Nr
	\\ &= u_0 + nr
	\end{align*}}
	$$
	*Dans le cas ou le premier terme de la suite est $u_0$.*
**(2) Généralisons cette aspect, en supposant que $u_p$ avec $p \in \mathbb{N}$ est le premier terme de la suite $u_n$.**
	Alors on calcul la distance entre $u_p$ et $u_n$ qui est donnée par $N = n-p$ .
	Ainsi, on en déduit que :
	$$
	\Large{
	\begin{align*}
	u_n &= u_p + \underbrace{r + r + \ldots+r}_{N-fois}
	\\ &= u_p + Nr
	\\ &= u_p + (n-p)r
	\end{align*}}
	$$
**On retiendra alors la seconde formule** pour le terme général d'une suite arithmétique, 
c'est à dire :
$$
\Large{u_n = u_p + (n-p)r}
$$
### Somme d'une suite arithmétique
La somme des $n$-premiers termes d'une suite arithmétique notée $S_n$ ou encore $S_{u_n}$ est définie comme suit :
$$
\Large{
\begin{align*}
S_n &= \underset{k=0}{\overset{n}{\sum}}u_k \\
&= u_0 + u_1+\ldots+u_n \\
&= \dfrac{n}{2}(u_p+u_n)
\end{align*}
}
$$
Puisque $(u_n)_{n \in \mathbb{N}}$ est une suite arithmétique alors je connais la forme du terme général (par définition). Ainsi, en le remplaçant on obtient :
$$
\Large{
\begin{align*}
S_n &= \dfrac{n}{2}(u_p+u_n) \\
&= \dfrac{n}{2}\left[u_p+u_n+(n-p)r\right] \\
&= \dfrac{n}{2}[2up+(n-p)r]
\end{align*}
}
$$
### Monotonie d'une suite arithmétique
Soit $(u_n)_{n \in \mathbb{N}}$ une suite arithmétique de raison $r \in \mathbb{R}$, alors :
- Si $r=0$ alors la suite est constance (= stationnaire).
- Si $r>0$ alors la suite est croissante.
- Si $r<0$ alors la suite est décroissante.

## 2 Les suites géométriques
### Définition générale
> ==Définition== *suite géométrique*
> Soit $(u_n)_{n \in \mathbb{N}}$ une suite.
> On parle de **suite géométrique** lorsque chaque terme suivant peut se déduire à partir du précédant un multipliant par un réel. Ce réel est souvent appelé **la raison** et est noté $q \in \mathbb{R}$.

Ainsi, en respectant la définition ci-dessus, nous sommes capable de déterminer le terme suivant ($u_{n+1}$) d'une suite géométrique.
$$
\Large{u_{n+1} = u_n \times q}
$$
### Terme général $u_n$
Pour déterminer le terme général d'une suite géométrique $(u_n)_{n \in \mathbb{N}}$, rien de trop compliqué :
- On détermine la 'distance' entre le premier terme de la suite, et le terme $n$ à calculer. On notera ce dernier $N$.
- On multiplie alors $N-fois$ la raison $q$ au premier terme de la suite pour obtenir $u_n$.
**(1) On suppose que $u_0$ est le premier terme de la suite.**
	Alors on calcul la distance entre $u_0$ et $u_n$ qui est donnée par $N=n-0=n$ .
	Ainsi, on en déduit que :
	$$
	\Large{
	\begin{align*}
	u_n &= u_0 \times \underbrace{q \times q \times \ldots \times q}_{N-fois}
	\\ &= u_0 \times q^N
	\\ &= u_0 \times q^n
	\end{align*}}
	$$
**(2) Généralisons cette aspect, en supposant que $u_p$ avec $p \in \mathbb{N}$ est le premier terme de la suite $u_n$.**
	Alors on calcul la distance entre $u_p$ et $u_n$ qui est donnée par $N = n-p$ .
	Ainsi, on en déduit que :
	$$
	\Large{
	\begin{align*}
	u_n &= u_p \times \underbrace{q \times q \times \ldots \times q}_{N-fois}
	\\ &= u_p \times q^N
	\\ &= u_p \times q^{n-p}
	\end{align*}}
	$$
**On retiendra alors la seconde formule** pour le terme général d'une suite arithmétique, 
c'est à dire :
$$
\Large{u_n = u_p \times q^{n-p}}
$$

### Somme d'une suite géométrique
La somme des $n$-premiers termes d'une suite géométrique avec ($q \in \mathbb{R}$ comme raison) notée $S_n$ ou encore $S_{u_n}$ est définie comme suit :
### CAS 1 - $q=1$
$$
\Large{
\begin{align*}
S_n &= \underset{k=0}{\overset{n}{\sum}}u_k \\
&= n \times u_p
\end{align*}
}
$$
### CAS 2 - $q \neq 1$
$$
\Large{
\begin{align*}
S_n &= \underset{k=0}{\overset{n}{\sum}}u_k \\
&= u_p \dfrac{1-q^n}{1-q}
\end{align*}
}
$$
### Monotonie d'une suite géométrique
Soit $(u_n)_{n \in \mathbb{N}}$ une suite géométrique de raison $q \in \mathbb{R}$, alors :
- Si $q=1$ alors la suite est stationnaire.
- Si $q=-1$ alors la suite oscille entre deux valeurs.
- Si $|q|>1$ alors la suite diverge (vers $\pm \infty$).
- Si $|q|<1$ alors la suite converge vers $1$.