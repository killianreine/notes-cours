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
x\cancel{-y}\cancel{+y}-z &= x^{2}\cancel{-y^{2}\cancel{+y^{2}}-z^{2}}\\
x-z &= x^{2}-z^{2} \Longleftrightarrow x\mathcal{R}z
\end{align*}
$$

On obtient donc bien que la relation $\mathcal{R}$ est transitive.

D'après **(i)**, **(ii)** et **(iii)** la relation $\mathcal{R}$ est réflexive, symétrique et transitive ce qui fait de elle une relation d'équivalence sur $\mathbb{R}$.