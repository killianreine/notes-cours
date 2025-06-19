# Examen - Rattrapage 2025

>[!info] Information concernant la notation
>- Exercice 1 (4 points)
>- Exercice 2 (4 points)
>	- Question 1 : 1.5 points
>	- Question 2 : 1 point
>	- Question 3 : 1.5 points
>- Exercice 3 (8 points)
>	- Question 1 : 1 point
>	- Question 2 : 1.5 points
>	- Question 3 : 1.5 points
>	- Question 4 : 1 point
>	- Question 5 : 1 point
>	- Question 6 : 2 points
>- Exercice 4 (4 points)
>	- Question 1 : 3 points
>	- Question 2 : 1 point
## Exercice 1
On cherche à résoudre l'équation de degré 2 suivante :

$$
z^2-(2+3i)z-5+i=0
$$

On pose :
- $a=1$
- $b=-(2+3i)=-2-3i$
- $c=-5+i$

Commençons par calculer le discriminant $\Delta$ donné par :

$$
\Delta = b^2-4ac
$$

Alors on a : 

$$
\begin{align*}
\Delta &= b^2-4ac \\
&= (-2-3i)^2-4 \times 1\times(-5+i) \\
&= (4+6i+6i+9i^2)-4(-5+i) \\
&= 4+12i-9-(-20+4i) \\
&= -5+12i+20-4i \\
&= 15+8i
\end{align*}
$$

Puisque $\Delta \in \mathbb{C}$ alors on cherche les solutions de l'équation $\delta^2=\Delta$ de la forme $x+iy$ où $x,y\in \mathbb{R}$ et sont solutions du système suivant :

$$
\begin{cases}
x^2+y^2 &= |\Delta| \\
x^2-u^2 &= \mathcal{R}e(\Delta) \\
2xy &= \mathcal{I}m(\Delta)
\end{cases}
$$

Calculons le module de $\Delta$ tel que :

$$
\begin{align*}
|\Delta| &= \sqrt{(\mathcal{R}e(\Delta))^2+(\mathcal{I}m(\Delta))^2} \\
&= \sqrt{15^2+8^2} \\
&= \sqrt{225+64} \\
&= \sqrt{289} \\
&= 17
\end{align*}
$$

Ainsi on obtient le système suivant à résoudre : 

$$
\begin{cases}
x^2+y^2 &= 17 & L_1\\
x^2-u^2 &= 15 & L_2\\
2xy &= 8 & L_3
\end{cases}
$$

- $L_1 - L_2$ 
  <br/> $2y^2=2 \Longleftrightarrow y^2=1 \Longleftrightarrow y=\pm 1$
- $L_1+L_2$
  <br/> $2x^2=32 \Longleftrightarrow x^2=16 \Longleftrightarrow x=\pm 4$
- D'après $L_3$
  <br/>Puisque $2xy=8 > 0$ alors $x$ et $y$ seront de même signes dans les solutions.

Les solutions de l'équation $\delta^2=\Delta$ sont données par :

$$
\delta_1=4+i \hspace{1cm} \delta_2=-4-i
$$

On peut alors déterminer les solutions finales de l'équation initiale :
<br/> On ne considère que la première solution $\delta_1$.

$$
z_1=\frac{-b+\delta}{2a}=\frac{2+3i+4+i}{2}=\frac{6+4i}{2}=3+2i
$$

$$
z_2=\frac{-b-\delta}{2a}=\frac{2+3i-4-i}{2}=\frac{-2+2i}{2}=-1+i
$$

Ainsi l'équation admet comme solutions :

$$
\fbox{S = \{3+2i \quad ; \quad 1-i\}}
$$

## Exercice 2
On considère une matrice $A$ tel que :

$$
A = \begin{pmatrix} 3 & 0 & 1 \\ -1 & 3 & -2 \\ -1 & 1 & 0\end{pmatrix}
$$

**Question 1**
<br/>Calculons $A-2I_3$.
<br/> $I_3$ représente la matrice identité de taille $3 \times 3$ tel que : 

$$
I_3 = \begin{pmatrix} 1&0&0 \\ 0&1&0 \\ 0&0&1\end{pmatrix}
$$

Ainsi : 

$$
2I_3 = 2\times\begin{pmatrix} 1&0&0 \\ 0&1&0 \\ 0&0&1\end{pmatrix}=\begin{pmatrix} 2&0&0 \\ 0&2&0 \\ 0&0&2\end{pmatrix}
$$

Et on peut alors calculer $A-2I_3$,

$$
\begin{align*}
A-2I_3 = \begin{pmatrix} 3 & 0 & 1 \\ -1 & 3 & -2 \\ -1 & 1 & 0\end{pmatrix} - \begin{pmatrix} 2&0&0 \\ 0&2&0 \\ 0&0&2\end{pmatrix} = \boxed{\begin{pmatrix} 1 & 0 & 1 \\ -1 & 1 & -2 \\ -1 & 1 & -2\end{pmatrix}}
\end{align*}
$$

Calculons $(A-2I_3)^2$.

$$
\begin{align*}
(A-2I_3)^2&=\begin{pmatrix} 1 & 0 & 1 \\ -1 & 1 & -2 \\ -1 & 1 & -2\end{pmatrix} \times \begin{pmatrix} 1 & 0 & 1 \\ -1 & 1 & -2 \\ -1 & 1 & -2\end{pmatrix}
\\& =\begin{pmatrix} 1 \times 1+0 \times 1+1 \times -1 & 1 \times 0 +0 \times1+1\times1 & 1 \times 1+0 \times-2+1\times-2 \\ -1 \times 1+1\times -1+-2\times-1 & -1 \times0+1\times1+-2\times1 & -1 \times 1+1\times-2+-2\times-2 \\ -1 \times 1+1\times -1+-2\times-1 & -1 \times0+1\times1+-2\times1 & -1 \times 1+1\times-2+-2\times-2
\end{pmatrix} \\
&= \boxed{\begin{pmatrix}0 & 1 &-1 \\ 0 & -1 &1 \\ 0 &-1 &1\end{pmatrix}}
\end{align*}
$$

Calculons $(A-2I_3)^3$.

$$
\begin{align*}
(A-2I_3)^3&=(A-2I_3)^2\times(A-2I_3) \\
&= \begin{pmatrix}0 & 1 &-1 \\ 0 & -1 &1 \\ 0 &-1 &1\end{pmatrix} \times \begin{pmatrix} 1 & 0 & 1 \\ -1 & 1 & -2 \\ -1 & 1 & -2\end{pmatrix} \\
&= \begin{pmatrix} 0 \times 1 +1\times-1+-1\times -1 & 0 \times 0+1 \times 1+-1 \times 1 &0\times1+1\times-2+-1\times-2 \\ 0 \times 1 +-1\times-1+1\times-1 & 0\times 0+-1\times1+1\times1 & 0 \times1+-1\times-2+1\times-2 \\ 0 \times 1 +-1\times-1+1\times-1 & 0\times 0+-1\times1+1\times1 & 0 \times1+-1\times-2+1\times-2 \end{pmatrix} \\
&= \boxed{\begin{pmatrix} 0 & 0 & 0 \\ 0& 0 & 0 \\ 0 & 0 & 0\end{pmatrix}}
\end{align*}
$$

**Question 2**
<br/> Développons $P=(X-2)^3$
<br/>On va utiliser la formule du binôme de Newton donnée par :

$$
(a+b)^n = \underset{k=0}{\overset{n}{\sum}}\binom{n}{k}a^kb^{n-k}
$$

Dans l'exercice,
- $a=X$
- $b=-2$

Ainsi en utilisant cette dernière dans le contexte de l'exercice :

$$
\begin{align*}
(X-2)^3 &= \underset{k=0}{\overset{3}{\sum}}\binom{3}{k}X^k(-2)^{3-k} \\
&= \binom{3}{0}X^0(-2)^3+\binom{3}{1}X^1(-2)^2+\binom{3}{2}X^2(-2)^1+\binom{3}{3}X^3(-2)^0 \\
&= 1\times1 \times-8+3 \times X \times 4+3\times X^2 \times-2+1 \times X^3 \times 1 \\
&= -8+12X-6X^2+X^3 \\
&= \boxed{X^3-6X^2+12X-8}
\end{align*}
$$

Les valeurs des coefficients binomiales $\binom{n}{k}$ se déterminent de deux manières, ici on décide d'utiliser le triangle de Pascal :

$$
\begin{array}{c|ccccc}
n \backslash k & 0 & 1 & 2 & 3 & 4 \\
\hline
0 & 1 &   &   &   &   \\
1 & 1 & 1 &   &   &   \\
2 & 1 & 2 & 1 &   &   \\
3 & 1 & 3 & 3 & 1 &   \\
4 & 1 & 4 & 6 & 4 & 1 \\
\end{array}
$$

> On utilise alors la lignes où $n=3$ qui donne bien $1, 3, 3, 1$. 

**Question 3**
<br/> On veut montrer que $A$ est inversible et donner $A^{-1}$ en fonction de $A$ de $A^2$ et de $A^3$.

Pour commencer, calculons le déterminant de $A$ pour déterminer si la matrice est inversible.
<br/>On a décider de développer le déterminant de $A$ par rapport à la première ligne.

$$
\begin{align*}
det(A)&=\begin{vmatrix} 3 & 0 & 1 \\ -1 & 3 & -2 \\ -1 & 1 & 0 \end{vmatrix} \\
&= (-1)^{1+1}\times3\times(3 \times 0 -(-2)\times1)+(-1)^{1+3}\times1\times(-1\times1-3\times-1)\\
&= 1 \times 3 \times -2 + 1\times1\times4 \\
&= -6+4 \\
&= \boxed{-2}
\end{align*}
$$

Puisque $det(A) \neq 0$ alors $A$ est inversible.

Déterminons une expression de $A^{-1}$.
<br/> À la question précédente, on a calculé $P(X)=(X-2)^3$. L'évaluation de $P$ par $A$ c'est à dire $P(A)$ est donnée par : 

$$
P(A) = (A-2I_3)^3=A^3-6A^2+12A-8I_3
$$

En fait en terme matriciel :
- $X$ devient la matrice $A$
- une constante devient $I_3$ par exemple $-2 \rightarrow -2I_3$. 

Et à la question 1, on a vu que : 

$$
(A-2I_3)^3=0
$$
Ainsi :

$$
\begin{align*}
P(A) &= (A-2I_3)^3 &=0
\\ &= A^3-6A^2+12A-8I_ 3 &=0
\end{align*}
$$

On obtient l'équation suivante : 

$$
A^3-6A^2+12A-8I_ 3 =0
$$
On peut isoler $I_3$ puisque par définition c'est une matrice inversible, alors on obtient :

$$
\begin{align*}
A^3-6A^2+12A-8I_ 3 &=0 \\
A^3-6A^2+12A &= 8I_3
\end{align*}
$$

On peut factoriser le terme de gauche par $A$. 

$$
\begin{align*}
A^3-6A^2+12A &= 8I_3 \\
A(A^2-6A+12I_3) &= 8I_ 3
\end{align*}
$$

On peut isoler isoler $A$ à droite puisque c'est une matrice inversible, on obtient alors :

$$
\begin{align*}
A(A^2-6A+12I_3) &= 8I_ 3 \\
(A^2-6A+12I_3) &= 8I_ 3 \times A^{-1} \\
A^2-6A+12I_3=8A^{-1}
\end{align*}
$$

Ainsi on obtient alors : 

$$
\boxed{
A^{-1} = \frac{1}{8} \left( A^2 - 6A + 12 I_3 \right)
}
$$

## Exercice 3
