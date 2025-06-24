# Loi de composition interne

>[!info] Rappels de cours
>Soit $f : E \to F$ un objet mathématiques.
>- On dit que $f$ est une **fonction** lorsque chaque élément de l'ensemble de départ $E$ (= antécédant) associe <u>au plus</u> un élément de l'ensemble d'arrivée $F$ (= image).
>- On dit que $f$ est une **application** de $E$ vers $F$ lorsque chaque éléments de l'ensemble de départ $E$ associe <u>un seul et un unique</u> élément de l'ensemble d'arrivée $F$.

>[!cite] Définition
>Soit $E$ un ensemble **non vide**.
>On appelle ==**loi de composition interne**== sur l'ensemble $E$ toutes les applications de $E \times E$ dans $E$.
>*Dans la suite on utilisera l'acronyme `lci` pour noter Loi de Composition Interne.*

*Prenons un exemple*
<u>Exemple :</u>
On considère $M$ l'ensemble des mots et $+$ l'opération de **concaténation** de deux mots. Alors on note : 
$$
\begin{align*}
+ & : & M \times M & \to & M \\
& & (x, y) & \to & x+y
\end{align*}
$$
La loi de composition interne de l'application $f$ qui prend à valeurs dans $M \times M$ et renvoie des valeurs dans $M$.

>[!info] Rappel de cours
>*La notion de produit cartésien et de $n-uplet$*
>- Soient $n \in \mathbb{N}^*$ et $E_1, \ldots, E_n$, $n-$ensembles.
>On appelle **produit cartésien** le produit de $n$ ensembles définit par :
>$$
>E_1 \times E_2 \times \ldots \times E_n = \{ (x_1, x_2, \ldots, x_n) \mid x_1 \in E_1, x_2 \in E_2, \ldots, x_n \in E_n \} = \underset{i=1}{\overset{n}{\prod}}E_i
>$$
>En gros, le produit cartésien ça forme un ensemble de $n-uplets$ ou chaque élément $i$ de ce dernier appartient au $ième$ ensemble.
>- La structure mathématiques $(x_1, x_2, \ldots, x_n)$ est appelée **n-uplet**. Et est par définition ordonnée. *(l'ordre des éléments est important)*

*Prenons un exemple concret*
<u>Exemple :</u>
Soit $E = \{ a, b, c \}$ un ensemble de trois éléments.
1) Calculer $E \times E$
2) Calculer $E \times \{A, B \}$

- Si $T : E \times E  \to E$ est une `lci` sur $E$ alors pour tout $x, y$ dans $E \times E$, on appelle **image de $T$ par $(x, y)$** ou **composée des termes $x$ et $y$** et, on note : $$xTy$$
- Si $T = +$ alors la loi est notée **additivement** et son composé est appelée somme de $x$ et $y$.
- Si $T = \times$ alors la loi est notée **multiplicativement** et le composée est appelé **produit** de $x$ et de $y$.

>[!tip] Astuce
>Soit $E$ un ensemble, alors si $|E|=n$, c'est à dire si l'ensemble contient un nombre fini $n$ d'éléments et qu'il n'est pas très grand, on peut donner la totalité des composés à l'aide d'une **table de Cayley**.

<u>Exemple :</u>
Soit $M=\{bonjour, le, monde\}$ un ensemble de mot et $+$ la *loi de concaténation* définie par : $$\begin{align*}
+ & : & M \times M & \to & M \\
& & (x, y) & \to & x+y
\end{align*}$$
Alors on a $|M|=3$ on peut alors représenter l'ensemble des composés dans une **table de Cayley**.
Ainsi :

|    $+$    |    $bonjour$    |    $le$    |    $monde$    |
| :-------: | :-------------: | :--------: | :-----------: |
| $bonjour$ | bonjour bonjour | bonjour le | bonjour monde |
|   $le$    |   le bonjour    |   le le    |   le monde    |
|  $monde$  |  monde bonjour  |  monde le  |  monde monde  |
Si on prend une `lci` générale notée $T$ sur un ensemble $E \times E$ avec $E = \{a , b\}$, alors on obtient la table de Cayley : 

| $T$ |    $a$     |    $b$     |
| :-: | :--------: | :--------: |
| $a$ | $a$ ou $b$ | $a$ ou $b$ |
| $b$ | $a$ ou $b$ | $a$ ou $b$ |
>Ainsi, on peut en déduire qu'il a plusieurs `lci` possible.

Vous utilisez déjà des `lci` au quotidien :
- Addition sur $\mathbb{N}$
- Multiplication sur $\mathbb{R}$
- Union sur les parties d'un ensemble
- Composition de fonction sur l'ensemble des application de $F$, noté $A(F, F)$

>[!cite] Définition
>Tout couple noté $(E, T)$ composé d'un ensemble non vide $E$ et d'une `lci` $T$ est appelé ==**magma**==.

Si on reprend les exemples précédents, on admet les magmas :
- $(\mathbb{N}, +)$
- $(\mathbb{R}, \times)$
- $(\mathcal{P}(E), \cup)$
- $(A(F, F), \circ)$

>[!info] Remarque
>Il est possible de construire des `lci` nouvelles à partir de celles connues.

<u>Exemple :</u>
On défini la loi de composition interne $\Delta$ suivante :
$$
\begin{align*}
\Delta & : & \mathbb{R}_+^* \times \mathbb{R}_+^* & \to & \mathbb{R}_+^* \\
& & (x, y) & \to & x \Delta y = \frac{x+y}{xy}
\end{align*}
$$
Pourquoi on a choisit $\mathbb{R}_+^*$ ?
- Si on avait choisit $\mathbb{R}^*$
  Alors :
  $$(x=-y) \Longrightarrow \left(x+y=0 \land \frac{x+y}{xy}=0 \right)$$
  Or ce cas n'est pas possible car on avait choisit $\mathbb{R}^*$ et que ce dernier exclu la valeur $0$.
- Si on avait choisit $\mathbb{R}_+$
  $$(x=0) \Longrightarrow \left( \dfrac{x+y}{xy}=\frac{y}{0}=ND \right)$$
  Il n'y a pas de sortie, d'image alors, ce n'est pas une `lci`. Pour rappel pour que $\Delta$ soit considéré comme une `lci` sur un ensemble $E$, il faut qu'elle soit une application, donc qu'elle associe à chaque antécédant une seule image.
Ainsi, le compromis pour que $(x \Delta y \neq 0 \land (x \neq 0 \lor y \neq 0))$ était de prendre l'ensemble $\mathbb{R}_+^*$.

>[!cite] Définition
>Soit $(E, T)$ un magma et $A \subset E$ qui est non vide. Alors on dit que $A$ est ==**stable par la loi**== $T$ si : $$\forall (x, y) \in A \times A \quad xTy \in A$$
>Si $A$ est une partie stable pour $T$ alors l'application $T_A$ est définie par :
>$$
>\begin{align*}
T_A & : & A \times A & \to & A \\
& & (x, y) & \to & xTy
\end{align*}
>$$
>Or $T$ est une `lci` sur $E$, pas sur $A$. On dit alors que $T_A$ est une `lci` sur $A$.

>[!question] Exercice
>Soit $(E, T)$ un magma stable sur $E$ et $(F_i)_{i \in I}$ une famille de parties non vide de $E$.
>- Montrer que $\underset{i\in I}{\bigcap}F_i$ est stable pour $T$.

>[!success] Correction
>- Par hypothèse on a $T : E \times E \to E$ tel que $T(A, B) \subseteq A$ si $A$ et $B$ sont stables.
>- $(F_i)_{i \in I}$ est une famille de parties **non vide** de $E$ tel que chaque partie $F_i$ est stable pour la loi $T$.
>Soit $x, y \in \underset{i\in I}{\bigcap}F_i$.
>Alors par définition de l'intersection $x \in F_i$ et $y \in F_i$ pour tout $i \in I$.
>Ainsi, puisque chaque $F_i$ est stable pour $T$ on a :
>$$xTy \in F_i \quad \forall i \in I$$
>Ainsi puisque chaque composé appartient à $F_i$ cela implique que $xTy \in \underset{i\in I}{\bigcap}F_i$ 
>D'où l'ensemble $\underset{i\in I}{\bigcap}F_i$ est stable pour $T$.

>[!cite] Définition
>Soit $(E, T)$ un magma, on dit que $T$ est ==**associative**== si et seulement si :
>$$\forall x,y,z \in E \quad (xTy)Tz = xT(yTz)$$
><u>Dans le cas d'une loi associative</u> $(xTy)Tz=xT(yTz)=xTyTz$. On dit alors que le magma est associatif.

<u>Exemple :</u>
*Voici quelques exemples de magmas associatifs*
- $(\mathbb{N}, +)$
- $(\mathbb{R}, \times)$
- $(\mathcal{P}(E), \cup)$

>[!tip] Astuce
>Pour montrer qu'un magma $M=(E, T)$ n'est pas associatif il suffit de montrer qu'il existe une combinaison d'éléments tel que : $$(xTy)Tz \neq xT(yTz)$$

>[!cite] Définition
>Soit $(E, T)$ un magma, on dit que $T$ est ==**commutative**== si et seulement si :
>$$\forall x,y \in E \quad xTy = yTx$$

<u>Exemple :</u>
*Voici quelques exemples de magmas*
1) Magmas commutatifs
	- $(\mathbb{N}, +)$
	- $(\mathbb{R}, \times)$
	- $(\mathcal{P}(E), \cup)$
2) Magmas non commutatifs
	- $(A(E, E), \circ)$ n'est pas commutatif.
	  Prenons $f : x \to 2x$ et $fg : x \to x+1$ alors :
	  $$f \circ g(x) = 2(x+1)=2x+2 \quad g \circ f(x)=2x+1 \quad \Longrightarrow f\circ g \neq g \circ f$$

>[!tip] Astuce
>Pour montrer qu'un magma $M=(E, T)$ n'est pas commutatif il suffit de montrer qu'il existe une combinaison d'éléments tel que : $$xTy \neq yTx$$

>[!cite] Définition
>Soit $(E, T)$ un magma, on dit que $e \in E$ est ==**élément neutre**== pour la loi $T$ si et seulement si :
>$$\forall x \in E \quad xTe = eTx=x$$
>Un élément est dit neutre lorsque muni d'une opération, il n'affecte pas l'issue du résultat.

<u>Exemple :</u>
- $(\mathbb{N}, +)$ admet $e=0$ pour élément neutre
- $(\mathbb{R}, \times)$ admet $e=1$ pour élément neutre
- $(\mathcal{P}(E), \cup)$ admet $e = \emptyset$ pour élément neutre
- $(\mathcal{P}(E), \cap)$ admet $e=E$ comme élément neutre
- $(A(E, E), \circ)$ admet $e=Id_x$ comme élément neutre

>[!info] Rappel de cours
>On note $Id_x$ l'**application identité** définie par :
>$$
>\begin{align*}
>Id_x : E & \to E \\ x & \to x
>\end{align*}
>$$
>En gros c'est l'application qui associe à $x$ lui même.

>[!example] Proposition
>
>Soit $(E, T)$ un magma.
>Si il admet un élément neutre **alors il est unique**.
>---
>**Démonstration**
><br/>Prenons $e_1, e_2$ deux éléments neutre du magma $M= (E, T)$.
>Alors on a :
>- $xTe_1=e_1Tx=x$
>- $xTe_2=e_2Tx=x$
>En particulier :
>$$e_1Te_2 = \begin{cases} e_1 \text{ car } e_2 \text{ est un neutre} \\ e_2 \text{ car } e_1 \text{ est un neutre}\end{cases}$$
>Puisque $e_1Te_2=e_1$ ou $e_1Te_2=e_2$, alors par **unicité des éléments** on a $e_1=e_2$.

>[!question] Exercice
>Soit $(E, T)$ un magma donné par sa table de Cayley.
>1) Donner un moyen de vérifier que $(E, T)$ admet un élément neutre.
>2) Donner les magmas à deux éléments qui possèdent un élément neutre.

>[!success] Correction
>1) Pour vérifier à l'aide d'une table de Cayley si un magma admet un élément neutre, il suffit de regarder la colonne et la ligne du même élément si ce dernier renvoi l'élément avec lequel il est muni alors il est neutre.
>2) Soit $(E, T)$ un magma qui possède un élément neutre, alors il vérifie : $$eTa=a \quad aTe=a \quad \forall a \in E$$
>   On considère $E=\{e, a\}$ muni d'une loi $T : E\times E \to E$ une `lci`. 
>   Soit $e$ l'élément neutre, Alors la table de Cayley doit respecter les conditions suivantes : $$eTe=e \quad aTe=a \quad eTa=a$$
>   Alors tout se joue dans la valeurs de $aTa$, qui peut être $a$ ou $e$ puisque $E$ ne contient que deux éléments et qu'un élément neutre doit appartenir au même ensemble $e$.
>   Ainsi il existe deux magmas à deux éléments possédant un élément neutre.

>[!warning] Attention
>- **NOTATION ADDITIVE**
>  L'élément neutre est noté $0_E$ et est appelé *0 de $(E,+)$.*
>- **NOTATION MULTIPLICATIVE**
>  L'élément neutre est noté $1_E$ et est appelé ==élément unité== du magma $(E, \times)$.

>[!cite] Définition
>Soit $(E, T)$ un magma qui admet comme élément neutre $e \in E$.
>Soit $x, y \in E$ on dit que "$x$ est ==**élément symétrique**== de $y$ par la loi $T$" si et seulement si :
>$$xTy = yTx = e$$
>Un élément de $E$ qui admet <u>au moins</u> un symétrique est dit ==**symétrisable**==.

<u>Exemple :</u>
- $(\mathbb{R}, +)$ le symétrique de $x$ est $-x$. Et il est appelé **opposé**.
  Aucun élément du magma $(\mathbb{N}, +)$ n'admet de symétrique pour $x>0$ car l'ensemble des naturels n'inclus pas les entiers inférieurs à $0$.
- $(\mathbb{R}, \times)$ Le symétrique de $x \in \mathbb{R}^*$ est $\frac{1}{x}=x^{-1}$ appelé **inverse**.
- Dans $(A(E, E), \circ)$ seule les applications **bijective** sont symétrisables.
  Si $f \in A(E, E)$ est bijective alors $\exists f^{-1} \in A(E, E)$ tel que : $$f \circ f^{-1} = f^{-1}\circ f=Id_x$$
  $f^{-1}$ est appelée **réciproque** de $f$.

>[!warning] Attention
>Il est possible qu'un élément admette plusieurs symétriques.

>[!info] Rappel de cours
>Soit $f$ une applications, alors on dit qu'elle est **bijective** si elle est :
>- Injective : $$\forall x_1,x_2 \in E \quad f(x_1)=f(x_2) \Longrightarrow x_1=x_2$$
>  **au plus 1** antécédant par image.
>- Surjective : $$\forall y \in E, \exists x \in E \mid f(x)=y$$
>  **au moins 1** antécédant par image. *il en existe au moins $1$ par image.*

>[!question] Exemple
>Montrer que l'application suivante est bijective.
>$$f : \mathbb{R} \to \mathbb{R} \quad f(x)=x+1$$

>[!success] Correction
>*todo...*

>[!cite] Définition
>Soit $(E, T)$ un magma et $a \in E$.
>- L'élément $a$ est dit ==**régulier à gauche**== si : $$\forall x,y \in E, \quad aTx=aTy \Longrightarrow x=y$$
>- L'élément $a$ est dit ==**régulier à droite**== si : $$\forall x,y \in E, \quad xTa=yTa \Longrightarrow x=y$$
>En somme, on dit que $a$ est ==**régulier**== si il l'est à droite et à gauche.

>[!question] Exemple
>Donner la négation de "$a$ est régulier à gauche".

>[!success] Correction
>Par définition, soit $(E, T)$ un magma et $a \in E$, 
>$$(a \text{ régulier } ) \Longleftrightarrow (\forall x,y \in E, \quad aTx=aTy \Longrightarrow x=y)$$
>Alors on cherche à déterminer la contraposée de $\forall x,y \in E, \quad aTx=aTy \Longrightarrow x=y$.
>Grâce à *l' UE Maths pour l'info en L1* on sait que $\lnot \forall = \exists$. Par contre on a affaire à une implication de la forme $\mathcal{P} \Longrightarrow \mathcal{Q}$ avec :
>- $\mathcal{P}=aTx=aTy$
>- $\mathcal{Q}=x=y$
>- Et on sait que :
>$$
>\begin{align*}
>\mathcal{P} &\Longrightarrow \mathcal{Q} \\
>\lnot\mathcal{P} & \lor \mathcal{Q}
>\end{align*}$$
>Ainsi :
>$$
>\begin{align*}
>\lnot(\mathcal{P} &\Longrightarrow \mathcal{Q}) \\
>\lnot(\lnot\mathcal{P} & \lor \mathcal{Q}) \\
>\mathcal{P} & \land \lnot\mathcal{Q}
>\end{align*}$$
>Donc, si $a$ n'est pas régulier $\exists x,y\in E, \quad aTx=aTy \land x \neq y$.

>[!info] Rappel de cours
>*Loi de Morgan*
>$$\lnot(\mathcal{P} \lor \mathcal{Q})=\lnot\mathcal{P} \land \lnot\mathcal{Q} \quad \lnot(\mathcal{P} \land \mathcal{Q})=\lnot\mathcal{P} \lor \lnot\mathcal{Q}$$

>[!example] Proposition
>Soit $(E, T)$ un magma associatif, $e \in E$ un élément neutre.
>Si $x \in E$ est symétrisable alors $x$ admet un unique symétrique.
>---
>**Démonstration**
>Soit $x \in E$ symétrisable.
>On suppose que $x$ admet au moins deux symétrique (= plusieurs) que l'on note $x', x''$ par la loi $T$.
>Alors : $$xTx' = x'Tx = e = xTx''=x''Tx$$
>On cherche à montrer que $x'=x''$.
>En utilisant l'associativité 
>- sur $x'T(xTx'')$ on a : $$x'T(xTx'')=(x'Tx)Tx''=eTx''=x''$$
>- sur $(x'Tx)Tx''$ on a : $$(x'Tx)Tx''=x'T(xTx'')=x'Te=x'$$
>Ainsi la double égalité permet de dire que $x'=x''$.

>[!example] Proposition
>Soit $(E, T)$ un magma associatif et $e \in E$ un élément neutre.
>Si $x \in E$ est symétrisable, alors $x'$ est régulier.
>---
>**Démonstration**
>Supposons $x \in E$ symétrisable, alors il admet au moins un symétrique que l'on note $x'$.
>Soient $a,b \in E$
>On cherche à montrer que $x'$ est régulier et on sait par hypothèse que $x$ est symétrisable. 
>- On a, notre élément $A=aTx$ et $B=bTx$, nous on doit montrer que $ATx'=BTx'$.
> $$
> \begin{align*}
> (aTx)Tx' &= (bTx)Tx' \\
> aT(xTx') &= bT(xTx') \\
> aTe &= bTe \\
> a &=b
>  \end{align*}
>  $$
>  $x'$ est régulier à droite.
>- On a, notre élément $A=xTA$ et $B=xTB$, nous on doit montrer que $x'TA=x'TB$.
> $$
> \begin{align*}
> x'T(xTa) &= x'T(xTb) \\
> (x'Tx)Ta &= (x'Tx)Tb \\
> eTa & eTb \\
> a &= b
>  \end{align*}
>  $$
>  $x'$ est régulier à gauche.
>En somme si $x'$ est symétrisable, alors il est aussi régulier.

>[!example] Proposition
>Soit $(E, T)$ un magma associatif, $e \in E$ un élément neutre.
>Si $x, y \in E$ sont symétrisables alors $xTy$ est symétrisable et son symétrique est $x'Ty'$ où $x'$ et $y'$ sont les symétriques respectifs de $x$ et de $y$ pour la loi $T$.
>---
>**Démonstration**
>Soit $x, y \in E$ symétrisable, alors chacun admet un symétrique respectif $x'$ et $y'$.
>- Montrons que $xTy$ est symétrisable : 
> $$
> \begin{align*}
> (xTy)T(y'Tx') &= xT(yTy')Tx' \\
> &= xTeTx' \\ &= xTx' \\ &= e
>  \end{align*}
>  $$
>- Montrons que $yTx$ est symétrisable :
> $$
> \begin{align*}
> (y'Tx')T(xTy) &= y'T(x'Tx)Ty \\ &= y'TeTy \\ &= y'Ty \\ &=e
>  \end{align*}
>  $$
>Alors si $x, y \in E$ sont symétrisables ils admettent un unique symétrique ici noté $x'$ et $y'$.

>[!warning] Attention
>Soit $(E, T)$ un magma admettant un élément neutre $e \in E$, deux éléments $x, y \in E$ sont symétriques si : $$xTy=yTx=e$$
>- En **notation additive** on dit que $x$ et $y$ sont <u>opposés</u>.
>- En **notation multiplicative** on dit que $x$ et $y$ sont <u>inverses l'un de l'autre</u>.

>[!cite] Définition
>Soit $(E, \times)$ un magma **supposé associatif** noté multiplicativement qui admet $1_E$ comme élément neutre. Soit $x \in E$.
>On définit le puissances de $x$ de la manière suivantes :
>- $x^0 = 1_E$
>- $\forall x \in \mathbb{N}^* \mid x^n = x \times x^{n-1}$
>- Si $x$ admet un symétrique (un inverse), alors les ==**puissances négatives**== de $x$ sont définies par $$\forall n \in \mathbb{N}^* \quad x^{-n}=(x^n)^{-1}$$

>[!example] Proposition
>Soit $(E, \times)$ un magma associatif noté multiplicativement qui admet un élément neutre $1_E$ et, $x \in E$ un élément inversible (symétrisable)
>Alors :
>1) $\forall n \in \mathbb{N} \quad x^n = x \times x^{n-1}$
>2) $\forall n \in \mathbb{N}^* \quad x^{-n}=(x^{-1})^n$
>3) $\forall p,q \in \mathbb{Z} \quad x^p \times x^q=x^{p+q}$
>4) $\forall p,q \in \mathbb{Z} \quad (x^p)^q=x^{pq}$
>---
>**Démonstration**
>*todo dans un des TD...*

>[!question] Exercice
>1) Donner les définition ci-dessus dans le cadre d'un magma associatif noté additivement qui admet $0_E$ comme élément neutre.
>2) Donner les propriétés ci-dessus dans le même cadre.

>[!question] Exercice
>Soit $(E, \times)$ un magma noté multiplicativement admettant un élément neutre $1_E$. Soit $a, x \in E$ deux éléments inversibles.
>1) Montrer que $$\forall n \in \mathbb{Z} \quad (a^{-1}xa)=a^{-1}xa$$
>2) Montrer que si $y \in E$ qui commute avec $x$, alors : $$\forall n \in \mathbb{Z} \quad (xy)^n=x^ny^n$$

