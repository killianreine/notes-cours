Révision pour le CC2 (séance 2)
- Raisonnement par récurrence
- Étudier la monotonie d'une suite
- Utiliser les propriétés des puissances, des sommes et des produits

## Exercice 1
Soit $(u_n)_{n \in \mathbb{N}}$ la suite définie par :$$u_n = 4n + 2^n\times(-2)$$
>==**Rappel**==
>Soit $x \in \mathbb{R}$ alors $x^a \times x^b=x^{a+b}$.

En sachant cette propriété, je peux déterminer que :
$$2^n \times (-2) = 2^n \times 2 \times (-1) =2^{n+1} \times -1 = -2^{n+1}$$
D'où l'expression finale de ma suite est donnée par :
$$u_n = 4n - 2^{n+1}$$
Pour étudier la monotonie d'une suite il y a plusieurs méthodes possibles. Dans notre cas, nous décidons de déterminer le signe de $u_{n+1}-u_n$.
1) **Déterminons les expressions respectives de $u_n$ et de $u_{n+1}$ de manière individuelle.**
*D'après la consigne :*
- $u_n=4n - 2^{n+1}$
- Ainsi, $u_{n+1} = 4(n+1) - 2^{n+2}=4n+4-2^{n+2}$

2) **Calculons $u_{n+1}-u_n$.**
$$
\begin{align*}
u_{n+1}-u_n &= 4n+4-2^{n+2}-(4n-2^{n+1}) \\
&= \cancel{4n}+4-2^{n+2}\cancel{-4n}+2^{n+1} \\
&= 4-2^{n+2}+2^{n+1} \\
&= 4-2^{2+1} \times 2+2^{n+1} \\
&= 4+2^{n+1}(-2+1) \\
&= 4-2^{n+1}
\end{align*}
$$

3) **Calculons le signe de l'expression trouvée.**
On a donc déterminé que $u_{n+1}-u_n=4-2^{n+1}$.
Par définition, on sais que $4>0$.
Il faut donc étudier le signe de $4-2^{n+1}$ tout entier.
Une méthode consiste à construire un tableau avec les valeurs de $u_{n+1}-u_n$ pour quelques rangs puis d'observer ce qu'il se passe.
Si on construit le tableau pour $n \in [0;4]$ alors on a :

|      $n$      |  0   |  1   |  2   |  3   |  4   |
| :-----------: | :--: | :--: | :--: | :--: | :--: |
| $u_{n+1}-u_n$ |  2   |  0   |  -4  | -12  | -28  |
|    $signe$    | $<0$ | $=0$ | $>0$ | $>0$ | $>0$ |
*Pour compléter le tableau il suffit de déterminer la valeur de $u_{n+1}-u_n$ au rangs données.*
Ainsi grâce au tableau on peut voir que :
- Pour $n \in [0; 1]$ on a $u_{n+1}-u_n \geq 0$
- Pour $n \in [1;4]$ on a $u_{n+1}-u_n \leq 0$
On suppose alors que $u_{n+1}-u_n \leq 0$ pour tout $n \in \mathbb{N}$ avec $n \geq 1$.
**Attention, c'est une supposition, elle ne vaut rien dans le raisonnement si elle n'est pas prouvée**.
Ce qui sous-entends qu'il va falloir prouver cette supposition. On va alors utiliser un raisonnement par récurrence.

>==**Rappel**==
>*Les étapes du raisonnement par récurrence*
>1. **DÉFINITION** de la propriété $\mathcal{P}(n)$ et de $n$.
>2. **INITIALISATION**, montrer $\mathcal{P}(n_0)$
>3. **HÉRÉDITÉ**, supposer vraie $\mathcal{P}(n)$ pour un $n$ fixé, montrer que $\mathcal{P}(n+1)$ est vraie elle aussi.
>4. **CONCLUSION**

**DÉFINITION**
Soit $\mathcal{P}(n)$ la propriété "$u_{n+1}-u_n \leq 0 \quad \forall n \in \mathbb{N} \mid n \geq 1$"

**INITIALISATION**
Puisque $n \geq 1$, alors pour l'initialisation, on va prendre $n_0=1$.
Alors on a :
$$
\begin{align*}
u_{n_0+1}-u_n &= 4-2^{1+1} \\ &= 4-4
\\ &= 0
\end{align*}
$$
Et $0 \leq 0$ ainsi la propriété $\mathcal{P}(n_0)$ est vérifiée.

**HÉRÉDITÉ**
Supposons que la propriété $\mathcal{P}$ est vraie pour un $n \geq 1$ fixé alors, montrons que la propriété $\mathcal{P}(n+1)$ est aussi valide.
On a :
$$
\begin{align*}
u_{n+2}-u_{n+1} &= 4-2^{n+2}-(4-2^{n+1}) \\ 
&= 4-2^{n+2}-4+2^{n+1} \\
&= \cancel{4}-2^{n+2}\cancel{-4}+2^{n+1} \\
&= -2^{n+1} \times 2+2^{n+1} \\
&= 2^{n+1}(-2+1) \\
&= -2^{n+1}
\end{align*}
$$
Puisque $n \geq 1$ alors : $2^{n+1} \geq 0$ d'où $-2^{n+1} \leq 0$.
On se retrouve alors avec $u_{n+2}-u_{n+1} \leq 0$.
La propriété $\mathcal{P}(n+1)$ est donc vérifiée.

**CONCLUSION**
Puisque $u_{n+1}-u_n \leq 0, \forall n \geq 1$, alors on dit que la suit $u_n$ est décroissante à partir du rang $n=1$.

## Exercice 2
*Exercice n°4 de la fiche TD4 partie 1, disponible sur le cours Eureka du tutorat.*
Pour chacune de suites suivantes, déterminer à partir de quel rang elles sont définies puis déterminer leur monotonie.

1) $u_n = \dfrac{n}{2^n}$
Pour commencer déterminons l'ensemble de définition de la suite.
La suite $u_n$ est définie tant que $2^n \neq 0$.
Et, par définition $n \in \mathbb{N}$ d'où $2^n \geq 1 > 0$. Ainsi la suite est bien définie pour tout entier $n$.

Afin de calculer la monotonie de cette suite, nous allons étudier le rapport à $1$ de $\frac{u_{n+1}}{u_n}$.
- Déterminons $u_n$ et $u_{n+1}$.
	- $u_n = \frac{n}{2^n}$ (*Donnée dans l'énoncée*)
	- $u_{n+1}=\frac{n+1}{2^{n+1}}$
- Calculons la quotient
$$
\begin{align*}
\frac{u_{n+1}}{u_n} &= \frac{\dfrac{n+1}{2^{n+1}}}{\dfrac{n}{2^n}}
\end{align*}
$$
>==**Rappel**==
>Soit $A, B, C, D  \in \mathbb{R}$ alors :
>$$\frac{\frac{A}{B}}{\frac{C}{D}}=\frac{A}{B} \times \frac{D}{C}$$
>*Diviser deux fractions revient à multiplier la première par l'inverse de la seconde.*

D'où
$$
\begin{align*}
\frac{u_{n+1}}{u_n} &= \frac{\dfrac{n+1}{2^{n+1}}}{\dfrac{n}{2^n}} \\
&= \frac{n+1}{2^{n+1}} \times \frac{2^n}{n} \\
&= \frac{n+1}{2^n \times 2} \times \frac{2^n}{n} \\ 
&= \frac{n+1}{\cancel{2^n} \times 2} \times \frac{\cancel{2^n}}{n} \\
&= \frac{n+1}{2} \times \frac{1}{n} \\
&= \frac{n+1}{2n} \\
\end{align*}
$$
Nous avons obtenue la forme finale, maintenant il faut étudier son rapport à $1$.
En décomposant ma fraction j'ai :
$$
\begin{align*}
\frac{n+1}{2n} &= \frac{n}{2n}+\frac{1}{2n} \\
&= \frac{1 \times n}{2 \times n}+\frac{1}{2} \times \frac{1}{n} \\
&= \frac{1 \times \cancel{n}}{2 \times \cancel{n}}+\frac{1}{2} \times \frac{1}{n} \\
&= \frac{1}{2}+\frac{1}{2} \times \frac{1}{n} \\
&= \frac{1}{2}\left( 1+ \frac{1}{n}\right)
\end{align*}
$$
Ainsi on a :
$\forall n \in \mathbb{N}$ on a forcément $\frac{1}{n} \leq 1$.
Et, en ajoutant / multipliant les termes restants on vas obtenir :
$$
\begin{align*}
\frac{1}{n} & \leq 1 \\
1 + \frac{1}{n} & \leq 2 & (\text{on ajoute }1 \mid \text{ valide pour } n \geq 1) \\
\frac{1}{2}\left( 1+ \frac{1}{n}\right) & \leq 1 & (\text{on mutliplie par } \frac{1}{2})
\end{align*}
$$
**Nb : Quand je dis on ajoute/multiplie pas un nombre $x$, cela sous entends que je fais l'opération à gauche de l'inéquation mais aussi à droite.**

Ainsi on a :
$$
u_{n+1}-u_n=\frac{1}{2}\left( 1+ \frac{1}{n}\right) \leq 1 \quad \forall n \geq 1
$$
Donc on en déduit que $u_{n+1} \leq u_nn$ et que la suit est décroissante à partir du rang $n=1$.

2) $u_n = \dfrac{n!}{2^n}$ 
Par définition, $u_n$ est bien définie lorsque $2^n \neq 0$ or, on sait que $\forall n \in \mathbb{N}$ on a $2^n \geq 1 > 0$ d'où, $u_n$ est bien définie pour tout entier $n$.
Pour déterminer la monotonie de cette suite, nous allons étudier le rapport à $1$ de $\frac{u_{n+1}}{u_n}$.

>==**Rappel**==
>On note *factorielle* de $n$ le réel $n!$ tel que : $$n! = 1 \times 2 \times \ldots \times n = \underset{k=1}{\overset{n}{\prod}}k$$
>où $\prod$ représente le symbole produit.

Déterminons $u_{n+1}$ et $u_n$ de manière individuelles.
- $u_n = \dfrac{n!}{2^n}$
- $u_{n+1} = \dfrac{(n+1)!}{2^{n+1}}$
Maintenant on peut calculer le rapport à $1$ de $\frac{u_{n+1}}{u_n}$.
On a :
$$
\begin{align*}
\frac{u_{n+1}}{u_n} &= \frac{\dfrac{(n+1)!}{2^{n+1}}}{\dfrac{n!}{2^{n}}} \\
&= \dfrac{(n+1)!}{2^{n+1}} \times \dfrac{2^n}{n!} \\
&= \dfrac{(n+1)!}{2^{n}\times2} \times \dfrac{2^n}{n!} \\
&= \dfrac{(n+1)!}{\cancel{2^{n}}\times2} \times \dfrac{\cancel{2^n}}{n!} \\
&= \dfrac{(n+1)!}{2} \times \dfrac{1}{n!} 
\end{align*}
$$
Par définition de la factorielle on a :
- $n! = \underset{k=1}{\overset{n}{\prod}}k$
- $(n+1)!=\underset{k=1}{\overset{n+1}{\prod}}k=\underset{k=1}{\overset{n}{\prod}}k \times(n+1)=n! \times (n+1)$
Ainsi :
$$
\begin{align*}
\frac{u_{n+1}}{u_n} &=  \dfrac{(n+1)!}{2} \times \dfrac{1}{n!} \\
&= \frac{n! \times(n+1)}{2} \times \dfrac{1}{n!} \\
&= \frac{\cancel{n!} \times(n+1)}{2} \times \dfrac{1}{\cancel{n!}} \\
&= \frac{(n+1)}{2} \times \dfrac{1}{1} \\
&= \frac{(n+1)}{2}
\end{align*}
$$
On peut alors étudier le signe de l'expression trouvée
Par définition :
$$
\begin{align*}
n & \geq 0 \\
n+1 & \geq 1 \\
\frac{n+1}{2} &\geq \frac{1}{2}
\end{align*}
$$
Malheureusement, on voit que $\frac{u_{n+1}}{u_n} \geq \frac{1}{2}$ mais nous on cherche le **rapport à $1$**, ainsi On veut savoir à partir de quand l'expression trouvée sera supérieure à $1$.
Ainsi, on a :
$$
\begin{align*}
\frac{n+1}{2} &\geq 1 \\
n+1 & \geq 2  \\
n &\geq 1
\end{align*}
$$
Ainsi on vient de montrer que :
$$\dfrac{u_{n+1}}{u_n} \geq 1 \quad \forall n \geq 1$$
La suite $u_n$ est alors croissante à partir du rang $n=1$.

3) $u_n = \underset{k=1}{\overset{n}{\sum}}\dfrac{1}{\sqrt{k}}-n$
Ici, on a une somme qui vas de $1$ à $n$ ainsi, la fraction $\frac{1}{k}$ est toujours définie.
D'où $u_n$ est bien définie $\forall n \geq 0$.
Dans note cas, nous avons une somme dans le terme général de la suite, et en réfléchissant un peu quand on étudie la monotonie, on chercher principalement à *enlever / simplifier* des termes, et, le seul moyen pour enlever des termes avec une somme c'est en les soustrayant alors, cette fois, nous calculerons le signe de $u_{n+1}-u_n$.
Déterminons $u_{n}$ et $u_{n+1}$.
- $u_n = \underset{k=1}{\overset{n}{\sum}}\dfrac{1}{\sqrt{k}}-n$
- $u_{n+1} = \underset{k=1}{\overset{n+1}{\sum}}\dfrac{1}{k}-(n+1) = \underset{k=1}{\overset{n+1}{\sum}}\dfrac{1}{\sqrt{k}}-n-1$
Commençons a calculer la soustraction :
$$
\begin{align*}
u_{n+1}-u_n &= \underset{k=1}{\overset{n+1}{\sum}}\dfrac{1}{\sqrt{k}}-n-1 - \left( \underset{k=1}{\overset{n}{\sum}}\dfrac{1}{\sqrt{k}}-n \right) \\
&= \underset{k=1}{\overset{n+1}{\sum}}\dfrac{1}{\sqrt{k}}-n-1 - \underset{k=1}{\overset{n}{\sum}}\dfrac{1}{\sqrt{k}}+n \\
&= \underset{k=1}{\overset{n+1}{\sum}}\dfrac{1}{\sqrt{k}}\cancel{-n}-1 - \underset{k=1}{\overset{n}{\sum}}\dfrac{1}{\sqrt{k}}+\cancel{n} \\
&= \underset{k=1}{\overset{n+1}{\sum}}\dfrac{1}{\sqrt{k}}-1 - \underset{k=1}{\overset{n}{\sum}}\dfrac{1}{\sqrt{k}}
\end{align*}
$$

>==**Rappel**==
>Par définition d'une somme :
>La somme de $1$ à $n+1$ est égale à la somme des $1$ à $n$ ajouté au dernier terme.
>En mathématiques :
>$$S_{n+1} = S_n + \alpha$$
>où $\alpha$ représente le dernier terme de la somme $S_{n+1}$.

Ainsi, en suivant ce raisonnement on a :
$$
\underset{k=1}{\overset{n+1}{\sum}}\dfrac{1}{\sqrt{k}} = \underset{k=1}{\overset{n}{\sum}}\dfrac{1}{\sqrt{k}}+\frac{1}{\sqrt{n+1}}
$$
où $\dfrac{1}{n+1}$ est le dernier terme de la somme.
Ainsi on se retrouve avec :
$$
\begin{align*}
u_{n+1}-u_n &= \underset{k=1}{\overset{n+1}{\sum}}\dfrac{1}{\sqrt{k}}-1 - \underset{k=1}{\overset{n}{\sum}}\dfrac{1}{\sqrt{k}} \\
&= \underset{k=1}{\overset{n}{\sum}}\dfrac{1}{\sqrt{k}}+\frac{1}{\sqrt{n+1}} -1-\underset{k=1}{\overset{n}{\sum}}\dfrac{1}{\sqrt{k}} \\
&= \cancel{\underset{k=1}{\overset{n}{\sum}}\dfrac{1}{\sqrt{k}}}+\frac{1}{\sqrt{n+1}} -1\cancel{-\underset{k=1}{\overset{n}{\sum}}\dfrac{1}{\sqrt{k}} } \\
&= \frac{1}{\sqrt{n+1}} -1 \\
\end{align*}
$$
On peut alors déterminer le signe de l'expression trouvée.
$$
\begin{align*}
n & \geq 0 \\
n+1 & \geq 1 \\
\sqrt{n+1} &\geq \sqrt{1}=1 \\ 
\frac{1}{\sqrt{n+1}} & \leq 1 \\
\frac{1}{\sqrt{n+1}}-1 & \leq 0
\end{align*}
$$
Puisque $u_{n+1}-u_n \leq 0$ alors $u_{n+1} \leq u_n$ ainsi la suite $u_n$ est décroissante pour tout entier $n$.

4) $u_n = \underset{k=1}{\overset{n}{\prod}}\dfrac{2k-1}{2k}$
On a un produit qui vas de $1$ à $n$ alors $2k \geq 2$ pour tout $n$ donc la suite $u_n$ est bien définie pour tout entier.
Déterminons $u_n$ et $u_{n+1}$ :
- $u_n = \underset{k=1}{\overset{n}{\prod}}\dfrac{2k-1}{2k}$
- $u_{n+1} = \underset{k=1}{\overset{n+1}{\prod}}\dfrac{2k-1}{2k}$
Dans notre cas, nous avons un produit dans le terme général de $u_n$ du coup je réfléchis à comment *simplifier* des termes, et pour des produits, on peut simplifie un nombre $x$ si il est à la fois au dénominateur et au numérateur.
D'où on vas calculer le rapport à $1$ de $\frac{u_{n+1}}{u_n}$.
Ainsi on a :
$$
\begin{align*}
\frac{u_{n+1}}{u_n} &= \frac{\underset{k=1}{\overset{n+1}{\prod}}\dfrac{2k-1}{2k}}{\underset{k=1}{\overset{n}{\prod}}\dfrac{2k-1}{2k}} \\
&= \frac{\frac{\underset{k=1}{\overset{n+1}{\prod}}2k-1}{\underset{k=1}{\overset{n+1}{\prod}}2k}}{{\frac{\underset{k=1}{\overset{n}{\prod}}2k-1}{\underset{k=1}{\overset{n}{\prod}}2k}}} \\
&= \frac{\underset{k=1}{\overset{n+1}{\prod}}2k-1}{\underset{k=1}{\overset{n+1}{\prod}}2k} \times \frac{\underset{k=1}{\overset{n}{\prod}}2k}{\underset{k=1}{\overset{n}{\prod}}2k-1} \\
&= \frac{\underset{k=1}{\overset{n}{\prod}}2k-1 \times2(n+1)-1}{\underset{k=1}{\overset{n}{\prod}}2k \times 2(n+1)} \times \frac{\underset{k=1}{\overset{n}{\prod}}2k}{\underset{k=1}{\overset{n}{\prod}}2k-1} 
\end{align*}
$$
$$
\begin{align*}
\dfrac{u_{n+1}}{u_n}&=  \frac{\cancel{\underset{k=1}{\overset{n}{\prod}}2k-1} \times2(n+1)-1}{\cancel{\underset{k=1}{\overset{n}{\prod}}2k} \times 2(n+1)} \times \frac{\cancel{\underset{k=1}{\overset{n}{\prod}}2k}}{\cancel{\underset{k=1}{\overset{n}{\prod}}2k-1}} \\
&= \dfrac{2(n+1)-1}{2(n+1)} \\
&= \dfrac{2(n+1)}{2(n+1)}-\dfrac{1}{2(n+1)} \\
&= 1-\dfrac{1}{2(n+1)} \\
 &= 1-\dfrac{1}{2n+2}
\end{align*}
$$
On peut alors étudier le signe de l'expression finale.
$$
\begin{align*}
n & \geq 0 \\
2n & \geq 0 \\
2n +2 & \geq 2 \\
\frac{1}{2n+2} & \leq \frac{1}{2} \\
1-\frac{1}{2n+2} & \leq 1-\frac{1}{2}=\frac{1}{2}<1
\end{align*}
$$
Ainsi puisque $\dfrac{u_{n+1}}{u_n} < 1$ alors la suite $u_n$ est strictement décroissante.