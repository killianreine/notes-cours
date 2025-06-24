# Les méthodes du TD1

>**==Rappel==**
>Soit $X$ une variable avec $(x_1, \ldots, x_{\mathcal{n}})$ les $n$ données et $\mathcal{E}_{total}$ l'effectif total de cette série (le nombre de données).
>Alors la fréquence notée $f_i$ de $x_i$ est donnée par :
>$$\Large{f_i = \dfrac{\mathcal{E}_{x_i}}{\mathcal{E}_{total}}}$$
> Où $\mathcal{E}_{i}$ représente l'effectif de $x_i$ .

## Moyenne d'un échantillon
> ==**Rappel**==
> Soit $X$ une variable avec $(x_1, \ldots, x_{\mathcal{n}})$ les $n$ données et $\mathcal{E}_{total}$ l'effectif total de cette série (le nombre de données).
> On note $\overline{x_n}$ la moyenne de la série définie par :
> $$\Large{\overline{x_n}=\dfrac{\underset{i=1}{\overset{n}{\sum}}x_i}{n}}$$

---
**Point méthode** 
*Calculer la moyenne d'une série, un échantillon.*
- On calcul la somme de toutes les données.
- On divise par le nombre de données
---

>==**Rappels**==
> * Soit $X$ une variable aléatoire avec $(x_1, \ldots, x_n)$ les $n$ données de l'échantilles (de la série). Alors l'étendue de la série notée $e$ est définie par :
>	$$\Large{e=x_{max} - x_{min}}$$
> - Soit $X$ une variable aléatoire avec $(x_1, \ldots, x_n)$ les $n$ données de l'échantilles (de la série). Alors la médiane de la série est définie par :
>	$$\Large{med(X)=x_{\frac{n+1}{2}}} \quad \text{si } n \text{ est pair}$$
	>$$\Large{med(X)=\dfrac{x_{(\frac{n}{2})}+x_{(\frac{n}{2}+1)}}{2}} \quad \text{si } n \text{ est impair}$$
## Tracer la boîte à moustache
---
**Point méthode**
*Tracer une boîte à moustache*
- Déterminer les quartiles $q_1$, $q_2$ et $q_3$.
	En sachant que :
	$$q_1 = x_{25\%} \quad ; \quad q_2 = med(X) \quad ; \quad q_3=x_{75\%}$$
- Déterminer l'écart interquartile noté $Iq$ et défini par $Iq = q_3-q_1$
- Déterminer les bornes de votre boîte à moustache. *J'ai décider de noter ces bornes $A$ et $B$.*
	$$A = q_1-1.5Iq \quad et \quad B = q_3 + 1.5Iq$$
	- Tracer votre boîte à moustache en respectant les bornes.
	- Tracer la position de la médiane à l'intérieur de votre boîte à moustache.
	- Placer (s'il y en a) les **outliers** (données hors de la boîte).
---

>==**Rappel**==
>Soit $X$ une variable associées à $n$ données alors, la variance notée $s_x^2$ est donnée par :
>$$s^2_x=\dfrac{1}{n-1}\underset{i=1}{\overset{n}{\sum}}(x_i-\overline{x_n})^2$$
>où $\overline{x}$ représente la moyenne de l'échantillon.

>==**Rappel**==
>Soit $X$ une variable associées à $n$ données alors, l'écart type notée $s_x$ est donnée par :
>$$s_x=\sqrt{\dfrac{1}{n-1}\underset{i=1}{\overset{n}{\sum}}(x_i-\overline{x_n})^2}=\sqrt{s_x^2}$$
>où $\overline{x}$ représente la moyenne de l'échantillon et $s_x^2$ la variance.
>Ainsi, **l'écart type représente la racine carré de la variance**.
## Calcul de la covariance par étapes
>==**Rappel**==
>Soit $X$ une variable associées à $n$ données alors, la covariance notée $cov(X, Y)$ est donnée par :
>$$s_{xy}=cov(X, Y) = \dfrac{\underset{i=1}{\overset{n}{\sum}}(x_i-\overline{x_n})(y_i-\overline{y_n})}{n-1}$$
>où $\overline{x_n}$ et $\overline{y_n}$ représentent les moyennes respectives de chaque échantillons $X$ et $Y$.

---
**Point méthode**
*Calculer la covariance de deux échantillons*
- Tracer la table des avec les colonnes suivantes 
	- $X$
	- $Y$
	- $\mathcal{E}_1=(x_i-\overline{x_n})$
	- $\mathcal{E}_2=(y_i-\overline{y_n})$
	- $\mathcal{E}_1\times\mathcal{E}_2$
- Remplir les colonnes une à une
- Faire la somme des valeurs de la dernière colonne
- Diviser le tout par $n-1$
---

>==**Rappel**==
>Le barycentre représente le point noté $\mathcal{B}$ (perso) de coordonnées $(\overline{x_n}, \overline{y_n})$. 
## Méthode des moindres carré
---
**Point méthode**
*Utiliser et comprendre la méthode des moindres carrés*
- Déterminer l'équation recherchée $Y=\beta_0+\beta_1X$
- Déterminer les valeurs des coefficients $\hat{\beta_0}$ et $\hat{\beta_1}$ en sachant que :
	$$\hat{\beta_1} = \dfrac{s_{xy}}{s^2_x} \quad et \quad \hat{\beta_0}=\overline{y_n}-\hat{\beta_1}\overline{x_n}$$
	où :
	- $s_{xy}$ représente la covariance
	- $s^2_x$ la variance de $X$
	- $\overline{x_n}$ et $\overline{y_n}$ les moyennes des séries
- En déduire l'équation de la droite
>On ajoute les "^" car ==ce sont des valeurs estimées== !
---

> ==**Rappels**==
>Soit $X$ une variable associées à $n$ données alors, on définit les coefficients de corrélation et de détermination comme suit :
>- **Coef. de corrélation**
>	$$\Omega_{xy}=\dfrac{s_{xy}}{s_y}$$
>- **Coef. de détermination**
>	$$R^2 = (\Omega_{xy})^2=\left( \dfrac{s_{xy}}{s_y} \right)^2$$
> où $s_{xy}$ représente la covariance et $s_y$ l'écart type de $Y$.