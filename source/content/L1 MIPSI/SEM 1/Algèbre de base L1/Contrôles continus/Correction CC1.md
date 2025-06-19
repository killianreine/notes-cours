### Exercice 1
Résoudre l'équation de degré $2$ complexe suivante :
$$
z²-(3+i)z+8-i=0
$$
*indication : $676=26^2$*
Commençons par calculer le discriminant noté $\Delta$ et défini par :
$$\Delta = b^2-4ac$$
où :
- $a=1$
- $b=-(3+i)$
- $c=8-i$
Ainsi on a :
$$
\begin{align*}
\Delta &= b^2-4ac \\
&= (-3-i)^2-4 \times1\times(8-i) \\
&= 9+3i+3i+i^2-4(8-i) \\
&= 9+6i-1-(32-4i) \\
&= 8+6i-32+4i \\
&= -24+10i \in \mathbb{C}
\end{align*}
$$
Puisque le discriminant est un complexe, nous allons utiliser la **méthode algébrique**.
Posons $\mathcal{E} : \delta^2=\Delta$ 
Cherchons les solutions de $\mathcal{E}$ de la forme $x+iy$ avec $x,y \in \mathbb{R}$ solutions du système suivant :
$$
\begin{cases}
 x^2+y^2 &= |\Delta| \\
 x^2-y^2&=\mathcal{R}e(\Delta) \\
 2xy &= \mathcal{I}m(\Delta)
\end{cases}
$$
Par définition du module, on a :
- $|\Delta|=\sqrt{a^2+b^2}=\sqrt{24^2+10^2}=\sqrt{676}=26$
- $\mathcal{R}e(\Delta)=-24$
- $\mathcal{I}m(\Delta)=10$
Ainsi on obtient le système suivant :$$
\begin{cases}
 x^2+y^2 &= 26,  L_1\\
 x^2-y^2&=-24,  L_2\\
 2xy &= 10, L_3
\end{cases}
$$

Pour déterminer les solutions du système nous allons effectuer les opérations suivantes :
- $L_1+L_2$
  $2x^2=2 \Longleftrightarrow x^2=1$ d'où $x=\pm1$
- $L_1-L_2$
  $2y^2=50 \Longleftrightarrow y^2=25$ d'où $y=\pm5$
- D'après $L_3$
  On a $2xy=10 > 0$ ainsi les inconnues $x$ et $y$ sont de mêmes signes. 
Les solutions du système sont donc les suivantes :
$$\delta_1 = 1+5i \quad \delta_2=-1-5i$$
On pose $\delta=\delta_1$, les solutions de l'équation initiale sont données par :
$$z_{1,2} = \frac{-b \pm \delta}{2a}$$
Ce qui donne :
$$
z_1 = \frac{3+i+1+5i}{2}=\dfrac{4+6i}{2}=2+3i \quad z_2=\frac{3+i-1-5i}{2}=\frac{2-4i}{2}=1-2i
$$
On obtient l'ensemble de solutions $S= \{2+3i, 1-2i\}$.

### Exercice 2
On considère $$\mathcal{F} = \{ x \in \mathbb{R}^4 \mid 3x_1+2x_2-x_3+2x_4=0 \}$$
1. Montrer que $\mathcal{F}$ est un sous-espace vectoriel de $\mathbb{R}^4$.
2. Déterminer la notation $Vect(u_1, \ldots, u_k)$ avec $k \in \mathbb{N}^*$.
3. Montrer que la famille engendrée par la notation $Vect$ est une **base**. Pour rapppel, on appelle **base** une famille libre de vecteur noté $\mathcal{B}=(u_1, \ldots, u_k)$, on dit d'une famille qu'elle est libre lorsque : $$\lambda_1u_1+\lambda_2u_2+\ldots+\lambda_ku_k=0_{\mathbb{K}^n}$$
   avec $\lambda_1, \lambda_2, \ldots, \lambda_k \in \mathbb{R}$.

##### ***Sous-espace vectoriel*** 
On dit que $\mathcal{F}$ est un sous-espace vectoriel de $\mathbb{R}^4$ si et seulement si :
- $0_{\mathbb{R}^4} \in \mathcal{F}$
- $\lambda x+y \in \mathcal{F}$ avec $x,y \in \mathcal{F}$ et $\lambda \in \mathbb{R}$.
Soit :
$$0_{\mathbb{R}^4}=\begin{pmatrix} 0 \\ 0 \\0\\0\end{pmatrix}=\begin{pmatrix} x_1 \\ x_2 \\ x_3 \\ x_4\end{pmatrix}$$
Alors on a :
- $3x_1 + 2x_2-x_3+2x_4 = 3\times0+2 \times0-0+2\times0=0$
Ainsi, on peut confirmer que $0_{\mathbb{R}^4} \in \mathcal{F}$.
Soit $x,y \in \mathcal{F}$ et $\lambda \in \mathbb{R}$, montrons que $\lambda x+y \in \mathcal{F}$.
Posons $z=\lambda x+y$ 
Alors on obtient :
$$z=\begin{pmatrix} z_1 \\ z_2 \\ z_3 \\ z_4\end{pmatrix}=\begin{pmatrix} \lambda x_1+y_1 \\ \lambda x_2+y_2 \\ \lambda x_3+y_3 \\ \lambda x_4+y_4\end{pmatrix}$$
$$
\begin{align*}
3z_1+2z_2-z_3+2z_4 &= 3(\lambda x_1+y_1)+2(\lambda x_2+y_2)-(\lambda x_3+y_3)+2(\lambda x_4+y_4)  \\
&= 3\lambda x_1+3y_1 + 2\lambda x_2+2y_2-\lambda x_3-y_3+2\lambda x_4+2y_4 \\
&= \lambda(\underbrace{3x_1+2x_2-x_3+2x_4}_{=0})+\underbrace{3y_1+2y_2-y_3+2y_4}_{=0} \\
&= \lambda 0+0 \\ &=0
\end{align*}$$
Car $x,y \in \mathcal{F}$
Ainsi on a $\lambda x+y \in \mathcal{F}$.
On en conclu alors que $\mathcal{F}$ est un sous-espace vectoriel de $\mathbb{R}^4$.

##### ***Notation $Vect$***
Soit $x \in \mathcal{F}$ alors on a :
$$3x_1+2x_2-x_3+2x_4=0 \Longleftrightarrow x_3 =3x_1+2x_2+2x_4$$
Ainsi on obtient la combinaison linéaire suivante :
$$x=\begin{pmatrix} x_1 \\ x_2 \\ x_3 \\ x_4\end{pmatrix}=\begin{pmatrix} x_1 \\ x_2 \\ 3x_1+2x_2+2x_4 \\ x_4\end{pmatrix}=x_1\begin{pmatrix} 1 \\ 0 \\ 3 \\ 0\end{pmatrix}+x_2\begin{pmatrix} 0 \\ 1 \\ 2 \\ 0\end{pmatrix}+x_4\begin{pmatrix} 0 \\ 0 \\ 2 \\ 1\end{pmatrix}=x_1u_1+x_2u_2+x_4u_3$$
D'où $\mathcal{F} \subset Vect(u_1, u_2, u_3)$.
Vérifions que les trois vecteurs déterminés appartiennent à $\mathcal{F}$
- Avec $u_1$.
  $3x_1 + 2x_2-x_3+2x_4=3 +0-3+0=0$
- Avec $u_2$
  $3x_1 + 2x_2-x_3+2x_4=0+2-2+0=0$
- Avec $u_3$ 
  $3x_1 + 2x_2-x_3+2x_4=0+0-2+2=0$
Ainsi $u_1, u_2, u_3 \in \mathcal{F}$.
Et puisque $\mathcal{F}$ est un sous-espace vectoriel alors $Vest(u_1, u_2, u_3) \subset \mathcal{F}$.
Ainsi les deux inclusions permettent de conclure :
$$\mathcal{F} = Vect\left(\begin{pmatrix} 1 \\ 0 \\ 3 \\ 0\end{pmatrix},\begin{pmatrix} 0 \\ 1 \\ 2 \\ 0\end{pmatrix},\begin{pmatrix} 0 \\ 0 \\ 2 \\ 1\end{pmatrix}\right)$$

D'après la question 2. la famille engendrée par la notation $Vect$ est $F=(u_1, u_2, u_3)$, ainsi vérifions que cette dernière est libre.
Soit $\lambda_1, \lambda_2, \lambda_3 \in \mathbb{R}$ alors on a :
$$
\begin{cases}
\lambda_1 = 0 \\
\lambda_2=0 \\
3\lambda_1+2\lambda_2+2\lambda_3=0 \\
\lambda_3=0
\end{cases}
$$
D'après le système on a $\lambda_1=\lambda_2=\lambda_3=0$ alors la famille $F$ est une famille libre et constitue une base de $\mathbb{R}^4$.

### Exercice 3
1. Montrer par récurrence que l'on a :
$$\forall n \in \mathbb{N^*} \quad \underset{k=1}{\overset{n}{\sum}}k^3=\frac{n^2(n+1)^2}{4}$$
**DÉFINITION**
Soit $P$ la propriété qui $\forall n \in \mathbb{N^*}$ est définie par :
$$\forall n \in \mathbb{N^*} \quad \underset{k=1}{\overset{n}{\sum}}k^3=\frac{n^2(n+1)^2}{4}$$
**INITIALISATION**
Puisque $n \in \mathbb{N}^*$ alors on a $n \geq 1$ on prend donc $n_0=1$ pour l'initialisation. Montrons que $P(n_0)$ est vérifiée :
$$\underset{k=1}{\overset{1}{\sum}}k^3=0^3+1^3=1 \quad et \quad \frac{1^2(1+1)^2}{4}=\frac{4}{4}=1$$
Ainsi la propriété $P$ est vérifiée au rang $n_0=1$.
**HÉRÉDITÉ**
Supposons que la propriété $P(n)$ est vraie pour un rang $n \in \mathbb{N}^*$ fixé. Montrons que celle ci est vraie au rang $n+1$.
$$
\begin{align*}
\underset{k=1}{\overset{n+1}{\sum}}k^3 &= \underset{k=1}{\overset{n}{\sum}}k^3+(n+1)^3 \\
&= \underbrace{\frac{n^2(n+1)^2}{4}}_{hypothese}+(n+1)^3 \\
&= \frac{n^2(n+1)^2}{4}+(n^2+2n+1)(n+1) \\
&= \frac{n^2(n+1)^2}{4} + n^3+n^2+2n^2+2n+n+1 \\
&= \frac{n^2(n+1)^2}{4} + n^3+3n^2+3n+1 \\
&= \frac{n^2(n+1)^2+4(n^3+3n^2+3n+1)}{4} \\
&= \frac{n^2(n^2+2n+1)+4n^3+12n^2+12n+4}{4} \\
&= \frac{n^4+2n^3+n^2+4n^3+12n^2+12n+4}{4} \\
&= \frac{n^4+6n^3+13n^2+12n+4}{4}
\end{align*}
$$
Et si on remplace $n$ par $n+1$ dans la terme de droite de notre propriété on a :
$$
\begin{align*}
\frac{(n+1)^2(n+2)^2}{4} &= \frac{(n^2+2n+1)(n^2+2n+2n+4)}{4} \\
&= \frac{(n^2+2n+1)(n^2+4n+4)}{4} \\
&= \frac{n^4+4n^3+4n^2+2n^3+8n^2+8n+n^2+4n+4}{4} \\
&= \frac{n^4+6n^3+13n^2+12n+4}{4}
\end{align*}
$$
Ainsi la propriété $P(n+1)$ est vérifiée, on peut donc en conclure que :
$$\forall n \in \mathbb{N^*} \quad \underset{k=1}{\overset{n}{\sum}}k^3=\frac{n^2(n+1)^2}{4}$$

2. En déduire pour tout $n \in \mathbb{N}^*$ : 
$$\underset{k=1}{\overset{n}{\sum}}k(2k^2-1)$$ Simplifions cette somme avec les propriétés que nous connaissons :
$$
\begin{align*}
\underset{k=1}{\overset{n}{\sum}}k(2k^2-1) &=\underset{k=1}{\overset{n}{\sum}}(2k^3-k) \\
&= \underset{k=1}{\overset{n}{\sum}}2k^3 - \underset{k=1}{\overset{n}{\sum}}k \\
&= 2\underset{k=1}{\overset{n}{\sum}}k^3-\underset{k=1}{\overset{n}{\sum}}k \\
&= 2\times\frac{n^2(n+1)^2}{4}-\frac{n(n+1)}{2} \\
&= 2 \times \frac{n^2(n^2+2n+1)-2(n(n+1))}{4} \\
&= \frac{2(n^2(n^2+2n+1))-2(n(n+1))}{4} \\
&= \frac{2(n^4+2n^3+n^2)-(n^2+n)}{4} \\
&= \frac{2n^4+4n^3+2n^2-n^2-n}{4} \\
&= \frac{2n^4+4n^3+n^2-n}{4}
\end{align*}
$$
3. a) À l'aide de la formule du binôme de Newton, calculer le polynôme suivant :
$$P(X) = (X-3)^4+(X-5)^2$$
Le binôme de Newton est définit par :
$$(a+b)^2 = \underset{k=0}{\overset{n}{\sum}}\begin{pmatrix} n \\ k\end{pmatrix}a^kb^{n-k}$$
En appliquant cette formule on a :
$$
\begin{align*}
P(X) &= (X-3)^4+(X-5)^2 \\
&= X^4-12X^3+55X^2-118X+106
\end{align*}
$$

4. b) Déterminer l'expression de la somme suivante :
$$S_n = \underset{k=2}{\overset{n}{\sum}}\left( \frac{1}{\sqrt{k-1}}-\frac{2}{\sqrt{k}}+\frac{1}{\sqrt{k+1}}\right)$$
On vas utiliser le changement d'indices.
$$
\begin{align*}
S_n&=\underset{k=2}{\overset{n}{\sum}}\left( \frac{1}{\sqrt{k-1}}-\frac{2}{\sqrt{k}}+\frac{1}{\sqrt{k+1}}\right) \\
&= \underset{k=2}{\overset{n}{\sum}}\frac{1}{\sqrt{k-1}}- \underset{k=2}{\overset{n}{\sum}}\frac{2}{\sqrt{k}}+ \underset{k=2}{\overset{n}{\sum}}\frac{1}{\sqrt{k+1}} \\
&= \underset{j=1}{\overset{n-1}{\sum}}\frac{1}{\sqrt{j}}- \underset{k=2}{\overset{n}{\sum}}\frac{2}{\sqrt{k}}+ \underset{l=3}{\overset{n+1}{\sum}}\frac{1}{\sqrt{l}} \\
&= \underset{j=1}{\overset{n-1}{\sum}}\frac{1}{\sqrt{j}}- 2\underset{k=2}{\overset{n}{\sum}}\frac{1}{\sqrt{k}}+ \underset{l=3}{\overset{n+1}{\sum}}\frac{1}{\sqrt{l}} \\
&= \underset{j=1}{\overset{n-1}{\sum}}\frac{1}{\sqrt{j}}- \left(\underset{k=2}{\overset{n}{\sum}}\frac{1}{\sqrt{k}}+\underset{k=2}{\overset{n}{\sum}}\frac{1}{\sqrt{k}}\right)+ \underset{l=3}{\overset{n+1}{\sum}}\frac{1}{\sqrt{l}} \\
&= \underbrace{\underset{j=1}{\overset{n-1}{\sum}}\frac{1}{\sqrt{j}}- \underset{k=2}{\overset{n}{\sum}}\frac{1}{\sqrt{k}}}_{E_1}-\underbrace{\underset{k=2}{\overset{n}{\sum}}\frac{1}{\sqrt{k}}+ \underset{l=3}{\overset{n+1}{\sum}}\frac{1}{\sqrt{l}}}_{E_2}
\end{align*}
$$
Traitons $E_1$ et $E_2$ de manière individuelle.
Commençons par $E_1$ :
$$
\begin{align*}
E_1 &= \underset{k=1}{\overset{n-1}{\sum}}\frac{1}{\sqrt{k}}- \underset{k=2}{\overset{n}{\sum}}\frac{1}{\sqrt{k}} \\
&= 1+{\frac{1}{\sqrt{2}}}+{\frac{1}{\sqrt{3}}}+...+{\frac{1}{\sqrt{n-1}}}-\left( {\frac{1}{\sqrt{2}}}+{\frac{1}{\sqrt{3}}}+...+{\frac{1}{\sqrt{n-1}}}+\frac{1}{\sqrt{n}} \right)  \\
&= 1+\cancel{\frac{1}{\sqrt{2}}}+\cancel{\frac{1}{\sqrt{3}}}+...+\cancel{\frac{1}{\sqrt{n-1}}}-\left( \cancel{\frac{1}{\sqrt{2}}}+\cancel{\frac{1}{\sqrt{3}}}+...+\cancel{\frac{1}{\sqrt{n-1}}}+\frac{1}{\sqrt{n}} \right) \\
&= 1-\frac{1}{\sqrt{n}}
\end{align*}
$$
Puis ensuite $E_2$
$$
\begin{align*}
E_2 &= -\underset{k=2}{\overset{n}{\sum}}\frac{1}{\sqrt{k}}+ \underset{k=3}{\overset{n+1}{\sum}}\frac{1}{\sqrt{k}} \\
&= -\frac{1}{\sqrt{2}}-\frac{1}{\sqrt{3}}-...-\frac{1}{\sqrt{n}}+\frac{1}{\sqrt{3}}+\ldots+\frac{1}{\sqrt{n}}+\frac{1}{\sqrt{n+1}} \\
&= -\frac{1}{\sqrt{2}}\cancel{-\frac{1}{\sqrt{3}}}-...\cancel{-\frac{1}{\sqrt{n}}}+\cancel{\frac{1}{\sqrt{3}}}+\ldots+\cancel{\frac{1}{\sqrt{n}}}+\frac{1}{\sqrt{n+1}} \\
&= \frac{1}{\sqrt{n+1}}-\frac{1}{\sqrt{2}} 
\end{align*}
$$
Ainsi on obtient :
$$\begin{align*}
E_1+E_2 &= 1-\frac{1}{\sqrt{n}} + \frac{1}{\sqrt{n+1}}-\frac{1}{\sqrt{2}} \\
\end{align*}$$