<div class="consigne_exo">
  <div class="exo-header">
    <span class="exo-num">1</span>
    <span>On donne la relation définie sur \( \mathbb{R} \) suivante : </span>
  </div>
  $$
  a \mathcal{R}b \Longleftrightarrow a^2-b^2=a-b
$$
  <ol class="exo-questions">
    <li>Montrer que la relation \( \mathcal{R} \) est une relation d'équivalence.</li>
    <li>Précisez la classe de représentant \( 2 \), de représentant \( m \) en général.</li>
  </ol>
</div>

 >[!cite] Définition
 > 
 > On considère $\mathcal{R}$ une relation définie sur un ensemble $A$. Alors on dit que $\mathcal{R}$ est une **==relation d'équivalence==** lorsqu'elle respecte les trois propriétés suivantes :
 >- Elle est **réflexive** : 
 >  $$
 > \forall x \in A \quad \text{ on a } \quad x\mathcal{R}x
 > $$
 >- Elle est **symétrique** : 
 >  $$
 >  \forall x,y \in A \quad x \mathcal{R}y \Longleftrightarrow y\mathcal{R}y
 >$$
 >- Elle est **transitive** : 
 >  $$
 >  \forall x,y,z \in A \quad (x \mathcal{R}y \text{ et } y\mathcal{R}z) \Longrightarrow x\mathcal{R}z
 >$$

$\boxed{\text{Question 1}}$  
 **(i)** Montrons que la relation $\mathcal{R}$ est réflexive  
 Soit $a \in \mathbb{R}$.  
 Alors on a :
 - $a^2-a^2=0$
 - $a-a=0$
On se retrouve donc bien avec $a\mathcal{R}a$, ainsi la relation $\mathcal{R}$ est réflexive. Car tout élément de $\mathbb{R}$ est en relation avec lui-même comme on vient de le montrer.

**(ii)** Montrons que la relation $\mathcal{R}$ est symétrique.  
En gros on doit montrer qu'à partir de $x \mathcal{R}y$ on arrive à retrouver $y \mathcal{R} x$.  
Par définition de la symétrie :

$$
	\begin{align*} x\mathcal{R}y \Longleftrightarrow a-b&=a^{2}-b^{2} \\
    -(a-b) &= -(a^{2}-b^{2})\\
-a+b &= -a^{2}+b^{2}\\
b-a &= b^{2}+a^{2} &\Longleftrightarrow y\mathcal{R}x
\end{align*}
$$

On a en fait inverser l'entièreté de l'équation de base et utiliser la commutativité de $(\mathbb{R}, -)$ pour réarranger les différents termes et arriver à l'expression voulue $b-a=b^{2}-a^{2}$.  
On retrouve bien la relation miroir à partir de $x \mathcal{R}y$ ainsi $\mathcal{R}$ est symétrique.  

**(iii)** Montrons que la relation $\mathcal{R}$ est transitive.  
Soit $x, y, z\in \mathbb{R}$,  
Alors par définition on a $x \mathcal{R}y$ et $y\mathcal{R}z$ ainsi : 

$$
x\mathcal{R}y \Longleftrightarrow x-y=x^{2}-y^{2} \quad \text{ et } \quad y\mathcal{R}z \Longleftrightarrow y-z=y^{2}-z^{2}
$$

On cherche à obtenir $a-z=a^{2}-z^{2}$ à partir des données que l'on a.  
On peut additionner les deux expressions conjecturées par définition.  

$$
\begin{align*} x\mathcal{R}y+y\mathcal{R}z \Longleftrightarrow (x-y)+(y-z) &= (x^{2}-y^2)+(y^{2}-z^{2}) \\
x\cancel{-y}\cancel{+y}-z &= x^{2}\cancel{-y^{2}}\cancel{+y^{2}}-z^{2}\\
x-z &= x^{2}-z^{2} \Longleftrightarrow x\mathcal{R}z
\end{align*}
$$

On obtient donc bien que la relation $\mathcal{R}$ est transitive.

D'après **(i)**, **(ii)** et **(iii)** la relation $\mathcal{R}$ est réflexive, symétrique et transitive ce qui fait de elle une relation d'équivalence sur $\mathbb{R}$.

$\boxed{\text{Question 2}}$  
On cherche a déterminer la classe de représentant $2$ puis de représentant général $m \in \mathbb{R}$.  

>[!cite] Définition
>Soit $\mathcal{R}$ une relation définie sur un ensemble quelconque $E$.  
>On appelle **==classe de représentant==** $m \in E$ *(ou classe d'équivalence)* l'ensemble de tous les éléments $x \in E$ tel que l'on a $x\mathcal{R}m$.  
>On note : 
>$$
>\overset{\cdot}{m} = \{ x \in E \mid x\mathcal{R}m \}
>$$
>*Autrement dit, une classe de représentant $m$ représente l'ensemble de tous les éléments qui sont en relation avec $m$*. 

>[!info] Remarque
>Une classe de représentant $m$ peut se noter $\overset{\cdot}m$ ou $\overline{m}$ ou encore $C(m)$.

Ainsi, la classe de représentant $2$ représente l'ensemble des $x \in \mathbb{R}$ en relation avec $2$.  
On note : 

$$
\begin{align*}
\overset{\cdot}2 &= \{x \in \mathbb{R} \mid x\mathcal{R}2\}\\
&= \{x \in \mathbb{R} \mid x-2=x^{2}-2^2\}
\end{align*}
$$

En prenant l'équation obtenue on a : 

$$
\begin{align*}
x-2 &= x^{2}-2^{2}\\
&= (x-2)(x+2)
\end{align*}
$$

>[!warning] 
>Il ne faut pas que $x=2$ car sinon notre équation ne pourrait plus se résoudre car si on déplace $x+2$ à gauche de l'équation, on doit le diviser. Cela est valide $\forall x \neq 2$.

$$
\begin{align*}
x-2 &= x^{2}-2^{2}\\
&= (x-2)(x+2) \\
1\cancel{(x-2)} &= \cancel{(x-2)}(x+2) \\
1 &= x+2
\end{align*}
$$

D'où $x=1-2=-1$.  
Cela signifie que $-1$ appartient à l'ensemble.  
Et puisque la relation est **réflexive** comme montrée à la question $1$, alors $2$ est en relation <u>avec lui même</u> d'où $2$ fera lui aussi partie de l'ensemble.  
On obtient la classe de représentant $2$ suivante :  

$$
\overset{\cdot}2=\{-1, 2\}
$$

Maintenant, il faut faire pareil mais plus avec un réel donné mais avec un représentant général qui peut désigner n'importe lequel des réels. Dans la consigne il a été nommé $m$.  
On cherche : 

$$
\begin{align*}
\overset{\cdot}m &= \{x \in \mathbb{R} \mid x\mathcal{R}m\}\\
&= \{x \in \mathbb{R} \mid x-m=x^{2}-m^2\}
\end{align*}
$$

Même procédé que pour trouvé la classe précédente : 

$$
\begin{align*}
x-m &= x^{2}-m^{2}\\
x-m &= (x-m)(x+m) \\
1\cancel{x-m} &= \cancel{(x-m)}(x+m)\\
1 &= x+m & \forall x&\neq m\\
x &= 1-m
\end{align*}
$$

On obtient alors que $x=1-m$, et on oublie pas que $\mathcal{R}$ est réflexive donc $m$ appartiendra à l'ensemble.  
D'où :

$$
\overset{\cdot}m = \{m, 1-m\}
$$

<div class="consigne_exo">
  <div class="exo-header">
    <span class="exo-num">2</span>
    <span>Soit \(A\) une partie donnée d'un ensemble \(E\). </span>
  </div>
  On considère la relation \(\mathcal{R}\) dans \(\mathcal{P}(E)\) définie par :
  $$
  X \mathcal{R}Y \Longleftrightarrow A \cap X = A \cap Y
$$
  <ol class="exo-questions">
    <li>Montrer que la relation \( \mathcal{R} \) est une relation d'équivalence.</li>
    <li>Donner <span class="mot-cle">l'ensemble quotient</span> lorsque \(A=\emptyset\) et \(A=E\).</li>
  </ol>
</div>

>[!info] Remarque
>Pour rappel, l'ensemble $\mathcal{P}(E)$ représente l'**==ensemble de toutes les parties==** de $E$. En gros l'ensemble contient tous les sous-ensembles possible de créer étant partie de $E$.

$\boxed{\text{Question 1}}$  
Montrons que $\mathcal{R}$ est une relation d'équivalence.

**(i)** Réflexivité  
Soit $X \in \mathcal{P}(E)$.  
Alors il est évident que $A \cap X=A\cap X$ on se retrouve bien avec $X\mathcal{R}X$. La relation $\mathcal{R}$ est donc évidemment réflexive.

>[!warning]
>Pour rappel les ensembles sont notés grâce à une **lettre majuscule** <u>par convention</u>...

**(ii)** Symétrie  
Soit $X,Y \in \mathcal{P}(E)$.  
Alors on a : $X\mathcal{R}Y \Longleftrightarrow A \cap X=A\cap Y$.  
On sait que l'opération $=$ est commutative sur tout ensemble $E$ alors $(\mathcal{P}(E), =)$ est commutative d'où :

$$
A \cap X = A\cap Y \Longleftrightarrow A\cap Y = A\cap X
$$

Ainsi, $\mathcal{R}$ est symétrique.

**(iii)** Transitivité  
Soit $X,Y,Z \in \mathcal{P}(E)$.  
Alors on a :
- $X\mathcal{R}Y \Longleftrightarrow A \cap X=A\cap Y$
- $Y\mathcal{R}Z \Longleftrightarrow A \cap Y=A\cap Z$ 

Puisque $A \cap Y=A\cap Z$ alors on obtient : 

$$
\begin{align*}
A \cap X &= A \cap Y \\
&= A \cap Z \Longleftrightarrow X\mathcal{R}Z
\end{align*}
$$

La relation $\mathcal{R}$ est donc bien transitive.  
D'après **(i)**, **(ii)** et **(iii)** la relation $\mathcal{R}$ est une relation d'équivalence.

$\boxed{\text{Question 2}}$  
L'ensemble quotient représente l'ensemble de toutes les classes de représentant $M \in \mathcal{P}(E)$.  
Si $A = \emptyset$, l'ensemble vide alors : 

$$
\forall X,Y \in \mathcal{P}(E), \quad X\mathcal{R}Y = \emptyset\cap X=\emptyset \cap Y
$$

On sait que pour l'intersection, $\emptyset$ est l'élément absorbant, en gros que $\forall E$, $E\cap\emptyset=\emptyset$ alors l'égalité suivante est vérifiée **pour toutes les parties de $E$**.  
Ainsi on note l'ensemble quotient : 

$$
{E} / \mathcal{R}=\mathcal{P}(E)
$$

Maintenant, si $A=E$.  
On cherche à savoir pour quels $X,Y$ parties de $E$ la relation est respectée : 

$$
\forall X,Y \in \mathcal{P}(E), \quad X\mathcal{R}Y = E\cap X=E \cap Y
$$

On sait que pour l'intersection $E$ l'ensemble englobant tous les autres est élément neutre, c'est à dire qu'il ne change pas l'issu du résultat. Ainsi pour toutes parties $A$ de $E$ on a $A\cap E=A$.  
Ainsi  

$$
E\cap X = E \cap Y \Longleftrightarrow X=Y
$$

Autrement dit, la relation est respectée si et seulement si $X$ et $Y$ désignent **le même ensemble**.  
D'où :

$$
E / \mathcal{R} = \{X,Y \in \mathcal{P}(E) \mid X=Y\}
$$

<div class="consigne_exo">
  <div class="exo-header">
    <span class="exo-num">3</span>
    <span>On considère sur \(\mathbb{R}\) la loi \(\star\) définie par :</span>
  </div>
  $$
  x \star y = axy+b(x+y)+c
$$
Trouver une relation liant \(a, b\) et \(c\) de sorte que cette loi soit associative.
</div>

>[!info] Remarque
>On dit qu'un loi $T$ définie sur $E$ est associative si et seulement si : 
>$$
>\forall x,y,z \in E \quad (xTy)Tz = xT(yTz)
>$$
>Si ceci est respecté, on dit que le magma $(E, T)$ est associatif.

Pour commencer, il serait bien de regarder dans quel(s) cas  $\star$ est une loi associative. Pour ce faire, nous allons calculer individuellement : 
- $(x\star y) \star z$
- $x\star(y\star z)$

Les étapes de calculs sont données ci contre :  
**Calcul de la première expression**  

$$
\begin{align*}
(x\star y) \star z &= [axy+b(x+y)+c] \star z
\end{align*}
$$

Si on pose que $X=x \star y$ alors $X = axy+b(x+y)+c$ d'où :

$$
\begin{align*}
(x\star y) \star z &= X \star z\\
&= aXz+b(X+z)+c\\
&= a(\underbrace{[axy+b(x+y)+c]}_{=X} \times z)+b(\underbrace{[axy+b(x+y)+c]}_{=X}+z)+c
\end{align*}
$$

Maintenant il reste plus qu'à rester **extrêmement rigoureux** et à développer jusqu'à la fin.  

$$
\begin{align*}
(x\star y) \star z &= a(\underbrace{[axy+b(x+y)+c]}_{=X} \times z)+b(\underbrace{[axy+b(x+y)+c]}_{=X}+z)+c\\
&= a(axyz+bz(x+y)+cz)+abxy+b^{2}(x+y)+bc+bz+c\\
&= a^{2}xyz+abz(x+y)+acz+abxy+b^{2}x+b^{2}y+bc+bz+c\\
&= a^{2}xyz+abxz+abyz+acz+abxy+b^{2}x+b^{2}y+bc+bz+c
\end{align*}
$$

**Calcul de la seconde expression**

$$
\begin{align*}
x \star (y \star z) &= x\star [ayz+b(y+z)+x]\\
&= a(x[ayz+b(y+z)+c])+b(x+[ayz+b(y+z)+c])+c \\
&= a(axyz+bx(y+z)+cx)+bx+abyz+b^{2}(y+z)+bc+c\\
&= a^{2}xyz+abx(y+z)+acx+bx+abyz+b^{2}y+b^{2}z+bc+c\\
&= a^{2}xyz+abxy+abxz+acx+bx+abyz+b^{2}y+b^{2}z+bc+c
\end{align*}
$$

on a alors obtenu les deux expressions suivantes : 

$$
\begin{cases}   
a^{2}xyz+abxz+abyz+acz+abxy+b^{2}x+b^{2}y+bc+bz+c \\
a^{2}xyz+abxy+abxz+acx+bx+abyz+b^{2}y+b^{2}z+bc+c
\end{cases}
$$

Maintenant, on peut soustraire les deux expressions, en théorie, cela devrai être différent de $0$ car on nous demande de trouver un lien reliant $a,b$ et $c$ pour que la loi soit associative.

$$
\begin{cases}   
\cancel{a^{2}xyz}+\cancel{abxz}+\cancel{abyz}+acz+\cancel{abxy}+b^{2}x+\cancel{b^{2}y}\cancel{+bc}+bz\cancel{+c} \\
\cancel{a^{2}xyz}+\cancel{abxy}+\cancel{abxz}+acx+bx+\cancel{abyz}+\cancel{b^{2}y}+b^{2}z+\cancel{bc}\cancel{+c}
\end{cases}
$$

La soustraction des deux lignes nous donne : 

$$
acz+b^{2}x+bz-(acx+bx+b^2z)
$$

Essayons de simplifier cette expression.  

$$
\begin{align*}
acz+b^{2}x+bz-(acx+bx+b^{2}z)&= acz+b^{2}x+bz-acx-bx-b^{2}z \\
&= ac(z-x)+b^{2}(x-z)+b(z-x)
\end{align*}
$$

On remarque que tous les facteurs sauf $1$ sont de la forme $e(x-z)$, essayons de faire en sorte que cela soit pareil, pour ce faire on a juste à inverser le signe de $b^2(x-z)$ : 

$$
-(b^{2}(x-z)) = -b^{2}(-x+z)=-b^{2}(z-x)
$$

D'où :

$$
ac(z-x)+b^{2}(x-z)+b(z-x) = ac(z-x)-b^{2}(z-x)+b(z-x) = (ac-b^{2}+b)(z-x)
$$

On cherche maintenant le lien entre $a,b$ et $c$ pour que $\star$ soit associative. Pour que ce soit respecté, il faudrait que la différences des deux expressions calculées précédemment fasse $0$.  
Autrement dit : 

$$
(ac-b^{2}+b)(z-x) = 0
$$

Et pour respecter cette égalité, comme c'est un produit, si l'un est nul, le tout est nul donc pour que $\star$ soit associative il faut que : 
- $ac-b^{2}+b=0$
- ou $z-x=0$

On cherche un lien entre $a,b$ et $c$ dont $(x-z)=0$ on peut l'oublier c'est pas ce qu'on veut.  
Mais en prenant la première condition on obtient le lien suivant : 

$$
ac-b^{2}+b=0 \Longleftrightarrow a=\dfrac{b^{2}-b}{c} \quad \text{avec } c\neq 0
$$

Et voilà, on a trouvé le lien entre $a,b$ et $c$ pour que la loi soit associative. Vous pouvez vérifier avec le triplet $(a,b,c)$ tel que $a=1$, $b=1$ et $c=2$.

