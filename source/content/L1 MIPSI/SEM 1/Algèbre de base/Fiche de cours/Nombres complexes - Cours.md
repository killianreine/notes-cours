
On admet l'existence d'un élément $i$ tel que : 

$$
i^2 = -1
$$

>[!cite] Nombre complexe
>Élément $z$ de la forme :
>
>$$
>z=a+ib
>$$
>
>Où $a, b \in \mathbb{R}$  sont respectivement la **partie réelle** et la **partie imaginaire** de $z$ notées $\mathcal{R}e(z)$ et $\mathcal{I}m(z)$.  
>On dit alors que *$z$ est un nombre complexe*, il appartient donc à l'ensemble $\mathbb{C}$.  
>C'est la **==forme algébrique==** de $z$.

En considérant $z_1=a_1+ib_1$ et $z_2=a_2+ib_2$, on dit qu'ils sont **égaux** lorsque partie réelle et leur partie imaginaire sont égales deux à deux : 

$$
(z_1=z_2) \Longleftrightarrow (a_1=a_2 \quad et \quad b_1=b_2)
$$

<br/>

$\boxed{\text{Addition de deux nombres complexes}}$  
Soient $z_1=a_1+ib_1$ et $z_2=a_2+ib_2$, alors $z_1+z_2$ la somme de deux complexes est donnée par : 

$$
z_1+z_2=a_1+a_2+i(b_1+b_2)
$$

<details class="custom-details">
<summary><span class="custom-summary">La démonstration</span></summary>

*Ce résultat se retrouve assez facilement*

$$
\begin{align*}
z_1+z_2 &= (a_1+ib_1)+(a_2+ib_2) \\
&= a_1+a_2+ib_1+ib_2 \\
&= a_1+a_2+\underbrace{i(b_1+b_2)}_{\text{factoriser par }i}
\end{align*}
$$

</details>

<br/>

$\boxed{\text{Produit de deux nombres complexes}}$  
Soient $z_1=a_1+ib_1$ et $z_2=a_2+ib_2$, alors $z_1+z_2$ le produit de deux complexes est donnée par : 

$$
z_1z_2=a_1a_2-b_1b_2+i(a_1b_2+a_2b_1)
$$


<details class="custom-details">
<summary><span class="custom-summary">La démonstration</span></summary>

*Ce résultat se retrouve assez facilement* :

$$
\begin{align*}
z_1z_2 &= (a_1 + ib_1)(a_2 + ib_2) \\
&= a_1a_2 + a_1ib_2 + ib_1a_2 + i^2b_1b_2 & \text{(développer)} \\
&= a_1a_2 + ia_1b_2 + ia_2b_{1} + (-1)(b_1b_2 )& \text{(car } i^2 = -1) \\
&= a_1a_2-b_1b_2 + ia_1b_2 + ia_2b_1 & \text{(regrouper les termes)} \\
&= a_1a_2 - b_1b_2 + i(a_1b_2 + a_2b_{1)}& (\text{factoriser par }i)
\end{align*}
$$

</details>

>[!tip]+ Point méthode
>*Calculer le produit de 2 nombres complexes.*  
>Soit $z_1=a_1+ib_1$ et $z_2=a_2+ib_2$ alors, pour calculer le produit $z_1z_2$ suivons les étapes suivantes : 
>- Développer le produit $(a_1+ib_1)(a_2+ib_2)$
>- Remplacer $i^2=-1$
>- Simplifier l'expression en regroupant les parties réelles et imaginaires.

>[!cite] Conjugué d'un complexe
>Soit $z$ un nombre complexe *sous forme algébrique* alors on appelle **==conjugué==** le nombre complexe noté $\overline{z}$ et donné par : 
>
>$$
>\overline{z}=a-ib
>$$

Pour simplifier, le conjugué c'est simplement inverser le signe de la partie imaginaire de $z$.  

<u>Exemple :</u>  
Si $z=2+2i$ alors son conjugué sera donné par $\overline{z}=2-2i$.

>[!cite] Module d'un complexe
>Soit $z=a+ib$ un nombre complexe *sous forme algébrique* alors on appelle **==module==** le nombre complexe noté $|z|$ et donné par : 
>
>$$
>|z|=\sqrt{a^2+b^2}
>$$
>

<br/>

$\boxed{\text{Quelques propriétés à savoir}}$  
- $\overline{\overline{z}}=z$  
  Le conjugué appliqué $2$ fois, redonne le complexe d'origine
- Si $z \in \mathbb{R}$ alors $z=\overline{z}$  
  Se note aussi :
  
  $$
  (z \in \mathbb{R}) \Longleftrightarrow (z=\overline{z})
  $$

<details class="custom-details">
<summary><span class="custom-summary">La démonstration</span></summary>

Soit $z \in \mathbb{R}$  
Alors cela veut dire que $z$ n'a pas de partie imaginaire ainsi $z=a+0i=a$.  
En calculant le conjugué on obtient :  

$$
\overline{z}=a-0i=a=z
$$

Ainsi ($z \in \mathbb{R}) \Longrightarrow (z=\overline{z})$  

Montrons le sens contraire.  
Soit $z \in \mathbb{C}$  
Alors $z=a+ib$
D'où $\overline{z}=a-ib$.  
On suppose que $z = \overline{z}$  
Alors on a :

$$
\begin{align*}
z &= \overline{z}\\
a+ib &= a-ib\\
ib &= -ib\\
2ib &= 0\\
b&=0
\end{align*}
$$

Puisque $b=0$ alors $z=a+0i=a$ donc $z \in \mathbb{R}$  
On se retrouve avec $z \in \mathbb{R}$  

L'équivalence est donc démontrée.
</details>

Considérons un nombre complexe de la forme suivante : 

$$
z = \frac{N}{D}
$$

Où :
- $D$ est un complexe  
  Le dénominateur
- $N$ un réel ou un complexe  
  Le numérateur

Alors on peut **simplifier cette fraction** *(mettre sous forme algébrique)* en multipliant en le numérateur et le dénominateur par le conjugué de $D$ :

$$
\frac{N}{D} = \frac{N\overline{D}}{D\overline{D}}=\frac{N\overline{D}}{|D|^2}
$$

>[!tip]+ Point méthode
>*Simplifier une fraction complexe*
>Soit $z=\overline{N}{D}$.  
>Alors pour simplifier $z$ il suffit de suivre les étapes suivantes :
>
>1. Déterminer $N$ et $D$.
>2. Calculer $|D|^2$ et $\overline{D}$.
>3. Simplifier grâce à une des deux formules.
>4. Conclure avec le résultat de la forme $a+ib$ où $a,b \in \mathbb{R}$

