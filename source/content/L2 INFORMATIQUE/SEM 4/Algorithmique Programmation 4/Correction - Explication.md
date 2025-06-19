## Algorithme $\mathcal{A}$

2) L'objectif de l'algorithme $\mathcal{A}$ c'est de retourner un vecteur contenant les chiffres de l'entrée $k$ écrite en binaire. Par définition si `w` est ce vecteur, on doit avoir : $$k=\underset{i=0}{\overset{l(w)-1}{\sum}}w[i] \times2^i$$
   On vas montrer que le vecteur `v` résultat de l'algorithme vérifie bien cette égalité. Pour cela, on va montrer par récurrence sur $i$ l'existence d'un invariant.
   Notons $n_i$ la valeur de $n$ au début de la $i-ème$ itération. 
   Soit alors $$I(i)=2^i \times n_i + \underset{j=0}{\overset{i-1}{\sum}}v[j]\times2^j$$Montrer que la fonction $I$ est un invariant, c'est à dire qu'elle est constante pour tout $i$ lors de l'algorithme. Votre preuve sera par récurrence sur $i$.

INITIALISATION
Pour $i=0$ :
$$I(0)=2^0 \times n_0 + \underset{j=0}{\overset{0-1}{\sum}}v[j]\times2^j=2^0 \times k + 0=1 \times k = k$$
initialisation vraie.

HEREDITE
On suppose que $I(i)$ est vraie et on cherche à montrer que $I(i+1)$ l'est aussi. 
$$I(i)=I(i+1)$$
Pour une itération que l'on note $i$ qui est un entier on a :
- $v[i]=n_i MOD 2$ le reste de la division euclidienne de $n_i$ et $2$ 
- $n_{i+1} = n_i DIV 2$ le quotient de la ...
$$I(i+1)=2^{i+1} \times n_{i+1} + \underset{j=0}{\overset{i-1+1}{\sum}}v[j]\times2^j$$
$$I(i+1)=2^{i+1} \times n_{i+1} + \underset{j=0}{\overset{i}{\sum}}v[j]\times2^j$$
