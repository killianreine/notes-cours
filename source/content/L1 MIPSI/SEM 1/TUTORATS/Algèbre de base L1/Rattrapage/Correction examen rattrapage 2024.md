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
**Question 1**
On veut montrer que l'application $f$ est linéaire.

$$
f(x) = (-x_1-x_2+x_3, -4x_1-x_2+2x_3, -6x_1-3x_2+4x_3) \quad \forall x \in \mathbb{R}^3
$$

Pour montrer que $f$ est une application linéaire il faut montrer que pour $x, y \in \mathbb{R}^3$ et $\lambda \in \mathbb{R}$ on a :

$$
f(\lambda x+y)=\lambda f(x)+f(y)
$$

Soit  $x, y \in \mathbb{R}^3$ et $\lambda \in \mathbb{R}$ alors on a : 

$$
\lambda x+y = \begin{pmatrix} \lambda x_1+y_1 \\ \lambda x_2+y_2 \\ \lambda x_3+y_3\end{pmatrix}
$$

Alors on peut étudier $f(\lambda x + y)$ tel que : 

$$
\begin{align*}
f(\lambda x + y ) &= \begin{pmatrix} -(\lambda x_1+y_1)-(\lambda x_2+y_2)+\lambda x_3+y_3 \\ -4(\lambda x_1+y_1)-(\lambda x_2+y_2)+2(\lambda x_3+y_3) \\ -6(\lambda x_1+y_1)-3(\lambda x_2+y_2)+4(\lambda x_3+y_3) \end{pmatrix} \\ \\
&= \begin{pmatrix} -\lambda x_1-y_1-\lambda x_2-y_2+\lambda x_3+y_3 \\ -4\lambda x_1-4y_1-\lambda x_2-y_2+2\lambda x_3+2y_3 \\ -6 \lambda x_1-6y_1-3\lambda x_2-3y_2+4\lambda x_3+4y_3 \end{pmatrix} \\ \\ &= \begin{pmatrix} -\lambda x_1-\lambda x_2+\lambda x_3-y_1-y_2+y_3 \\ -4\lambda x_1-\lambda x_2+2\lambda x_3-4y_1-y_2+2y_3 \\ -6 \lambda x_1-3\lambda x_2+4\lambda x_3-6y_1-3y_2+4y_3 \end{pmatrix} \\ \\ &= \begin{pmatrix} \lambda(-x_1-x_2+x_3)-y_1-y_2+y_3 \\ \lambda(-4x_1-x_2+2x_3)-4y_1-y_2+2y_3 \\ \lambda(-6x_1-3x_2+4x_3)-6y_1-3y_2+4y_3 \end{pmatrix} \\\\ &= \lambda\begin{pmatrix}-x_1-x_2+x_3 \\ -4x_1-x_2+2x_3 \\ -6x_1-3x_2+4x_3 \end{pmatrix} + \begin{pmatrix} -y_1-y_2+y_3 \\ -4y_1-y_2+2y_3 \\ -6y_1-3y_2+4y_3 \end{pmatrix} \\\\ &= \lambda f(x)+f(y)
\end{align*}
$$

Ainsi $f$ est bien une application linéaire. Donc $f \in \mathcal{L}(\mathbb{R}^3)$ .

**Question 2**
Le noyau de $f$ est donné par : 

$$
Ker(f) = \{ x \in \mathbb{R}^3 \mid -x_1-x_2+x_3=0, -4x_1-x_2+2x_3=0, -6x_1-3x_2+4x_3=0 \}
$$

Redémontrons que $Ker(f)$ est un sous-espace vectoriel de $\mathbb{R} ^3$.
<br/> On dit que $Ker(f)$ est un sous-espace vectoriel de $\mathbb{R}^3$ si et seulement si :
- $0_{\mathbb{R}^3} \in Ker(f)$
- $\lambda x + y \in Ker(f)$ avec $\lambda \in \mathbb{R}$ et $x, y \in Ker(f)$.

Montrons que $0_{\mathbb{R}^3} \in Ker(f)$. 
<br/> Le vecteur nul de l'espace $\mathbb{R}^3$ est donné par : 

$$
0_{\mathbb{R}^3} = \begin{pmatrix} 0 \\ 0 \\ 0\end{pmatrix} = \begin{pmatrix} x_1 \\ x_2 \\ x_3\end{pmatrix}
$$

Alors on a :
- $-x_1-x_2+x_3=-0-0+0=0$
- $-4x_1-x_2+2x_3 = -4 \times 0 - 0 + 2 \times 0 = 0$
- $-6 \times 0-3 \times 0 + 4 \times 0 = 0$

Ainsi on a bien $0_{\mathbb{R}^3} \in Ker(f)$. (a)

Soit $x, y \in Ker(f)$ et $\lambda \in \mathbb{R}$ alors :
<br/> On pose $z = \lambda x + y$.
<br/> D'où :

$$
z =\begin{pmatrix} z_1 \\  z_2 \\  z_3\end{pmatrix}= \begin{pmatrix} \lambda x_1+y_1 \\ \lambda x_2+y_2 \\ \lambda x_3+y_3\end{pmatrix}
$$

Vérifions que pour chaque condition $\lambda x + y = 0$ pour respecter $Ker(f)$.
<br/>On a : 

$$
\begin{align*}
-z_1-z_2+z_3 &= -(\lambda x_1+y_1)-(\lambda x_2+y_2)+\lambda x_3+y_3 \\
&= -\lambda x_1-y_1-\lambda x_2-y_2+\lambda x_3+y_3 \\
&= \lambda(-x_1-x_2+x_3)-y_1-y_2+y_3 \\
&= \lambda 0+0 \\
&=0
\end{align*}
$$

Car $x, y \in Ker(f)$.

$$
\begin{align*}
-4z_1-z_2+2z_3 &= -4(\lambda x_1+y_1)-(\lambda x_2+y_2)+2(\lambda x_3+y_3) \\
&= -4\lambda x_1-4y_1-\lambda x_2-y_2+2\lambda x_3+2y_3 \\
&= \lambda(-4x_1-x_2+2x_3)-4y_1-y_2+2y_3 \\
&= \lambda 0+0 \\
&=0
\end{align*}
$$

Car $x, y \in Ker(f)$.

$$
\begin{align*}
-6z_1-3z_2+4z_3 &= -6(\lambda x_1+y_1)-3(\lambda x_2+y_2)+4(\lambda x_3+y_3) \\
&= -\lambda 6x_1-6y_1-3\lambda x_2-3y_2+4\lambda x_3+4y_3 \\
&= \lambda(-6x_1-3x_2+4x_3)-6y_1-3y_2+4y_3 \\
&= \lambda 0+0 \\
&=0
\end{align*}
$$

Car $x,y \in Ker(f)$.

En somme, $\lambda x + y \in Ker(f)$ (b).
<br/>D'après (a) et (b), $Ker(f)$ est un sous-espace vectoriel de $\mathbb{R}^3$.

**Question 3**
On chercher à déterminer une base de $Ker(f)$.
<br/> Pour se faire, il faut déterminer la notation tel que $Ker(f)=Vect(u_1, \ldots, u_k)$ avec $k \in \mathbb{N}^*$.

Pour déterminer la notation $Ker(f)=Vect(u_1, \ldots, u_k)$ il va falloir :
- Montrer que $Ker(f)\subset Vect(u_1, \ldots, u_k)$
- Montrer que $Vect(u_1, \ldots, u_k) \subset Ker(f)$
<br/>La double inclusion implique nécessairement l'égalité !

Soit $x \in Ker(f)$.
<br/>Alors $x \in \mathbb{R}^3$ et 

$$
\begin{cases} -x_1-x_2+x_3&=0 & L_1\\ -4x_1-x_2+2x_3&=0 &L_2 \\ -6x_1-3x_2+4x_3&=0 &L_3 \end{cases}
$$

Notre objectif est de déterminer une combinaison linéaire de $x$ en essayant de trouver la valeur d'une ou plusieurs composante du vecteur.
<br/> Pour cela on utilise le système précédant.

D'après $L_1$
<br/> $-x_1-x_2+x_3=0$ Alors $x_1=-x_2+x_3$.
<br/> On peut remplacer $x_1$ dans les autres lignes du système.

$$
\begin{cases}  -4(-x_2+x_3)-x_2+2x_3&=0 &L_2 \\ -6(-x_2+x_3)-3x_2+4x_3&=0 &L_3 \end{cases} \quad \quad \Longleftrightarrow \begin{cases}  3x_2-2x_3&=0 &L_2 \\3x_2-2x_3&=0 &L_3 \end{cases}
$$

D'après $L_2$ 
<br/>$3x_2-2x_3=0$ alors $2x_3=3x_2$ ce qui implique que $x_3=\frac{3}{2}x_2$.
<br/> On peut maintenant remplacer la valeur de $x_3$ dans celle de $x_1$ trouvée en premier et on obtient : 

$$
x_1 = -x_2+\frac{3}{2}x_2=-\frac{2}{2}x_2+\frac{3}{2}x_2 = \frac{1}{2}x_2
$$

Maintenant on peut réécrire $x$ sachant que :

$$
x = \begin{pmatrix} x_1 \\  x_2 \\  x_3\end{pmatrix}=\begin{pmatrix} \frac{1}{2}x_2 \\  x_2 \\  \frac{3}{2}x_2\end{pmatrix}=x_2\begin{pmatrix} \frac{1}{2} \\  1 \\  \frac{3}{2}\end{pmatrix}
$$

Ainsi $x=x_2 u$ une combinaison linéaire de $x_2$ avec $u=(\frac{1}{2}, 1, \frac{3}{2})$ ainsi $u \in Vect(u_1, \ldots, u_k)$.
<br/> Donc $Ker(f) \subset Vect(u)$. (c)

Maintenant, il faut montrer l'inclusion dans le second sens, et pour faire ça, il faut prendre chaque vecteur de $Vect(\ldots)$ et montrer qu'ils appartiennent à $Ker(f)$.

Soit $u=(\frac{1}{2}, 1, \frac{3}{2})$. 
<br/> Alors :
- $-u_1-u_2+u_3=-\frac{1}{2}-1+\frac{3}{2}=-\frac{1}{2}-\frac{2}{2}+\frac{3}{2}=-\frac{3}{2}+\frac{3}{2}=0$
- $-4u_1-u_2+2u_3=-4\times \frac{1}{2}-1+2 \times \frac{3}{2}=-\frac{6}{2}+\frac{6}{2}=0$
- $-6u_1-3u_2+4u_3=-6 \times \frac{1}{2}-3\times 1+4 \times \frac{3}{2} = -\frac{12}{2}+\frac{12}{2}=0$
<br/>Ainsi le vecteur $u \in Ker(f)$ et puisque $Ker(f)$ est un sous-espace vectoriel de $\mathbb{R}^3$ alors on a : $Vect(u) \subset kerf(f)$ (d).

D'après (c) et (d) : $Ker(f) = Vect\left( \begin{pmatrix} \frac{1}{2} \\  1 \\  \frac{3}{2}\end{pmatrix} \right)$.
<br/>Puisque la famille engendrée par le $Vect$ ne contient qu'un vecteur, alors c'est une famille libre par définition donc une base de $Ker(f)$.
<br/>On note la base :

$$
\boxed{\mathcal{B_0}=\left( \begin{pmatrix} \frac{1}{2} \\  1 \\  \frac{3}{2}\end{pmatrix} \right)}
$$

**Question 4**
<br/>On cherche a déterminer la matrice de $f$ dans la base canonique de $\mathbb{R}^3$.
<br/>Notons $\mathcal{E}$ cette dernière telle que : 

$$
\mathcal{E} = \left( \begin{pmatrix} 1 \\  0 \\  0\end{pmatrix}, \begin{pmatrix} 0 \\  1 \\  0\end{pmatrix}, \begin{pmatrix} 0 \\  0 \\  1\end{pmatrix} \right) = (e_1, e_2, e_3)
$$

Calculons l'application de $f$ avec chaque vecteur : 
- $f(e_1)=(-1, -4, -6)$ 
- $f(e_2)=(-1, -1, -3)$
- $f(e_3)=(1, 2, 4)$
Ainsi on obtient la matrice suivante : 

$$
\boxed{M_{\mathcal{E}}(f) = \begin{pmatrix} -1 & -1 & 1 \\ -4 & -1 & 2 \\ -6 & -3 & 4\end{pmatrix}}
$$

**Question 5**
On cherche à monter que $\mathcal{B}$ est une base de $\mathbb{R}^3$.
<br/> Il faut montrer que la famille engendrée par la base est libre.

Montrons que tous les lambdas sont nuls avec la somme des $\lambda_iu_i$. 

$$
\lambda_1u_1+\lambda_2u_2+\lambda_3u_3 = 0_{\mathbb{R}^3}
$$

Avec $\lambda_1, \lambda_2, \lambda_3 \in \mathbb{R}$. 
<br/>On obtient alors le système suivant : 

$$
\begin{cases}
\lambda_1 + \lambda_3 &= 0 &L_1 \\
2\lambda_1 + \lambda_2 &= 0 & L_2 \\
3 \lambda_1+\lambda_2+2\lambda_3 &= 0 & L_3
\end{cases}
$$

Il faut résoudre ce système en montrant que tous les lambdas sont nuls.

- D'après $L_1$ on a $\lambda_1+\lambda_3=0$ alors $\lambda_1=-\lambda_3$.
<br/>On remplace $\lambda_1$ dans les autres lignes.
<br/>On obtient alors : 

$$
\begin{cases}
-2\lambda_3 + \lambda_2 &= 0 & L_2 \\
\lambda_2-\lambda_3 &= 0 & L_3
\end{cases}
$$

- D'après $L_3$ on a $\lambda_2-\lambda_3=0$ alors $\lambda_3=\lambda_2$
<br/>On remplace dans le seconde ligne :

$$
-2 \lambda_2+\lambda_2=0 \Longleftrightarrow -\lambda_2=0 \Longleftrightarrow \lambda_2=0
$$

Puisque $\lambda_2=0$ alors $\lambda_3=\lambda_2=0$ et $\lambda_1=-\lambda_3=-0=0$.
<br/>On a donc bien $\lambda_1=\lambda_2=\lambda_3=0$, ainsi $\mathcal{B}$ est bien une base de $\mathbb{R}^3$.

**Question 6**
