# Examen - Rattrapage 2025
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
A-2I_3 = \begin{pmatrix} 3 & 0 & 1 \\ -1 & 3 & -2 \\ -1 & 1 & 0\end{pmatrix} - \begin{pmatrix} 2&0&0 \\ 0&2&0 \\ 0&0&2\end{pmatrix} = \begin{pmatrix} 1 & 0 & 1 \\ -1 & 1 & -2 \\ -1 & 1 & -2\end{pmatrix}
\end{align*}
$$

Calculons $(A-2I_3)^2$.

$$
\begin{align*}
(A-2I_3)^2&=\begin{pmatrix} 1 & 0 & 1 \\ -1 & 1 & -2 \\ -1 & 1 & -2\end{pmatrix} \times \begin{pmatrix} 1 & 0 & 1 \\ -1 & 1 & -2 \\ -1 & 1 & -2\end{pmatrix}
\\& =\begin{pmatrix} 1 \times 1+0 \times 1+1 \times -1 & 1 \times 0 +0 \times1+1\times1 & 1 \times 1+0 \times-2+1\times-2 \\ -1 \times 1+1\times -1+-2\times-1 & -1 \times0+1\times1+-2\times1 & -1 \times 1+1\times-2+-2\times-2 \\ -1 \times 1+1\times -1+-2\times-1 & -1 \times0+1\times1+-2\times1 & -1 \times 1+1\times-2+-2\times-2
\end{pmatrix} \\
&= \begin{pmatrix}0 & 1 &-1 \\ 0 & -1 &1 \\ 0 &-1 &1\end{pmatrix}
\end{align*}
$$

Calculons $(A-2I_3)^3$.

$$
\begin{align*}
(A-2I_3)^3&=(A-2I_3)^2\times(A-2I_3) \\
&= \begin{pmatrix}0 & 1 &-1 \\ 0 & -1 &1 \\ 0 &-1 &1\end{pmatrix} \times \begin{pmatrix} 1 & 0 & 1 \\ -1 & 1 & -2 \\ -1 & 1 & -2\end{pmatrix} \\
&= \begin{pmatrix} 0 \times 1 +1\times-1+-1\times -1 & 0 \times 0+1 \times 1+-1 \times 1 &0\times1+1\times-2+-1\times-2 \\ 0 \times 1 +-1\times-1+1\times-1 & 0\times 0+-1\times1+1\times1 & 0 \times1+-1\times-2+1\times-2 \\ 0 \times 1 +-1\times-1+1\times-1 & 0\times 0+-1\times1+1\times1 & 0 \times1+-1\times-2+1\times-2 \end{pmatrix} \\
&= \begin{pmatrix} 0 & 0 & 0 \\ 0& 0 & 0 \\ 0 & 0 & 0\end{pmatrix}
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

Ainsi :

$$
\begin{align*}
(X-2)^3 &= \underset{k=0}{\overset{3}{\sum}}\binom{3}{k}X^k(-2)^{3-k} \\
&= \binom{3}{0}X^0(-2)^3+\binom{3}{1}X^1(-2)^2+\binom{3}{2}X^2(-2)^1+\binom{3}{3}X^3(-2)^0 \\
&= 1\times1 \times-8+3 \times X \times 4+3\times X^2 \times-2+1 \times X^3 \times 1 \\
&= -8+12X-6X^2+X^3 \\
&= X^3-6X^2+12X-8
\end{align*}
$$
