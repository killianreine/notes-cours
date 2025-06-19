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