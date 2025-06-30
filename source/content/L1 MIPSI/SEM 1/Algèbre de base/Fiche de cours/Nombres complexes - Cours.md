
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

>[!tip] Point méthode
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
$$

Pour simplifier, le conjugué c'est simplement inverser le signe de la partie imaginaire de $z$.  

<u>Exemple :</u>  
Si $z=2+2i$ alors son conjugué sera donné par $\overline{z}=2-2i$.

