### Exercice 1
On considère les suites suivantes :
- $u_n=(2, -1, 0, 3, 0, 0, 0, \ldots)$
- $t_n=(0, 0 ,5, -2, 1, 0, 0, \ldots)$
- $v_n=(1, 1, 1, 1, 1, 0, 0, 0, \ldots)$
- $s_n=(0, 0, 0, 0, 0, 0, 0, 0, 0 ,7, 0, 0, \ldots)$

**Questions**
1. Rappeler ce que signifie le terme <mark class="purple">degré d'un polynôme</mark>.
2. Déterminer le degré de chaque polynômes.
3. Écrire chaque polynôme sous sa forme standard :
   $$P(X) = \underset{k=0}{\overset{n}{\sum}}a_kX^k$$
   où $a_k$ représente la $k-ième$ composante de la suite $a_n$ représentant le polynôme.
4. Lesquels de ses polynômes sont unitaires ?

### Exercice 2
On considère les polynômes suivants :
- $P(X)=2X^4-3X^2+X-5$
- $Q(X)=X^3+2X^2-4X+1$
- $R(X)=-X^2+3X+2$

**Questions**
1. Calculer $P(X)+2Q(X)$.
2. Calculer $P(X) \times Q(X)$ puis $Q(X) \times R(X)$.
   *Que peut-on remarquer ?*
3. Déterminer le degré de $P(X)-Q(X) \times R(X)$ sans calculer, en expliquant les propriétés utilisées.

### Exercice 3
On considère deux polynômes $P(X)$ et $Q(X)$ de degré $3$ ou plus.
- $P(X) = aX^3+bX^2+cX+d$
- $Q(X)=(2a-b)X^3+(a+c)X^2+(b-d)X+(c+2d)$

**Questions**
1. À quelle condition $P(X)=Q(X)$ ?
2. Résoudre le système d'équations obtenu.
3. Donner l'expression générale des polynômes $P(X)$ vérifiant l'égalité $P(X)=Q(X)$.

### Exercice 4
1. Développer $(2X-3)^5$ en utilisant la formule du binôme de Newton.
2. Calculer $(X^2+X)^4$.
3. Déterminer le terme de plus haut degré dans $(3X^2-2X+1)^6$.

### Exercice 5
On cherche à déterminer s'il existe un polynôme $P(X)$ de degré $2$ tel que pour tout $n \in \mathbb{N}$, on a : $$P(n)=\underset{k=0}{\overset{n}{\sum}}k=\dfrac{n(n+1)}{2}$$
**Questions**
1. Calculer $P(0)$, $P(1)$, $P(2)$.
2. Donner la forme générale d'un polynôme $P(X)$ de degré $2$. Puis, établir le système d'équation dont les inconnues sont les coefficients de $P$.
3. Résoudre ce système et donner l'expression de $P(X)$.
4. Vérifier rigoureusement que $$P(n)=\underset{k=0}{\overset{n}{\sum}}k \quad \forall n\in \mathbb{N}$$
### Exercice 6
Soient les polynômes à coefficients dans $\mathbb{C}$. On peut aussi noter soient $P, Q \in \mathbb{C}[X]$.
- $P(X)=(1+i)X^3+2iX^2+(2-i)$
- $Q(X)=iX^3+(1-i)X^2+(2+i)X-1$

**Questions**
1. Calculer $P(X)+\overline{Q(X)}$
2. Déterminer le polynôme $R(X)$ tel que : $$P(X)-R(X)=\overline{P(X)}$$
3. Existe-t-il un polynôme $S(X)$ à coefficients réels tel que $P(X)+S(X)$ soit à coefficients réels ? Si oui, le déterminer.

### Exercice 7
Soient $A(X), B(X), C(X)$ trois polynôme non nuls.
**Questions**
1. Montrer que si $deg(A) \neq deg(B)$, alors $deg(A+B)=max(deg(A), deg(B))$.
2. Donner un exemple où $deg(A)=deg(B)$ mais $deg(A+B) < deg(A)$.
3. Prouver que $deg(ABC)=deg(A)+deg(B)+deg(C)$.
4. Si $A(X) \times B(X)=A(X) \times C(X)$ avec $A(X) \neq 0$, peut-on conclure que $B(X)=C(X)$ ? Justifier.

### Exercice 8
Une suite $(u_n)_{n \geq 0}$ vérifie la relation de récurrence :
$$u_{n+2}=3u_{n+1}-2u_n \quad n\geq 0 \quad et \quad u_0 = 1 , u_1=2$$
**Questions**
1. Calculer les trois premiers termes de la suite.
2. On suppose qu'il existe u polynôme $P$ tel que $u_n=P(n)$. Quel serait le degré minimal de $P(X)$ ?
3. En utilisant les valeurs calculées, déterminer si un tel polynôme de degré $2$ peut exister.