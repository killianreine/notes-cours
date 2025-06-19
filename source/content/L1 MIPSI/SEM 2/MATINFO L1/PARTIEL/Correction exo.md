Exercice 1/1 : 
Calculer les valeurs initiales de la suite, $u_0$ et $u_1$.
D'après la situation décrite, en 2020 l’influenceuse compte 1000 abonnés, donc :
• $u_0 = 1000$.
Chaque année, elle perd 10 % de ses abonnés et gagne 250 nouveaux abonnés. Ainsi, pour l’année 2021 :
• $u_1 = 0.9 \times u_0 + 250 = 0.9 \times 1000 + 250 = 900 + 250 = 1150$.

Exercice 1/2 : 
Justifier la relation récursive $\forall n \in \mathbb{N}$, $u_{n+1} = 0.9n + 250$.
Pour justifier cette relation, on part du fait que, chaque année, l'influenceuse subit deux opérations sur son nombre d’abonnés :
• Elle perd 10 % de ses abonnés. Autrement dit, il lui reste 90 % de ses abonnés, ce qui s’exprime par 0.9·$u_n$.
• Elle gagne simultanément 250 nouveaux abonnés.
En combinant ces deux opérations, le nombre d’abonnés l’année suivante est la somme de 0.9·$u_n$ (les abonnés restants après la perte de 10 %) et de 250 (les nouveaux abonnés), ce qui se traduit par la relation :
$$u_{n+1} = 0.9\,u_n + 250.$$
Cette relation récursive traduit parfaitement le modèle de l’évolution annuelle du nombre d’abonnés. Aucun algorithme ou calculatrice scientifique n'est nécessaire pour obtenir cette relation.

Exercice 1/3 : 
Interpréter l'instruction suite(10) du code Python sans effectuer de calcul.
L'instruction suite(10) renvoie le terme de rang 10 de la suite : le programme commence avec 1000 abonnés et applique 10 fois la relation récurrente $u = 0.9 \times u + 250$ pour obtenir $u_{10}$, c'est-à-dire le nombre d’abonnés en 2030 selon le modèle proposé.

Exercice 1/4a : 
Montrer par raisonnement par récurrence que pour tout entier n, $u_n \leq 2500$.
Démonstration par récurrence
• Initialisation :
Pour n = 0, 
on a $u_0 = 1000$. 
Comme $1000 \leq 2500$, l’inégalité est vraie pour n = 0.
• Hérédité :
Hypothèse de récurrence : on suppose que pour un entier n quelconque, $u_n \leq 2500$.
Il faut montrer que $u_{n+1} \leq 2500$.
D'après la relation de récurrence,
$$u_{n+1} = 0.9\,u_n + 250.$$
En utilisant l’hypothèse $u_n \leq 2500$, on a :
$$u_{n+1} \leq 0.9 \times 2500 + 250 = 2250 + 250 = 2500.$$
• Conclusion :
Par le principe de récurrence, l’inégalité $u_n \leq 2500$ est vraie pour tout entier $n$.

Exercice 1/4b : 
Démontrer que la suite $(u_n)$ est croissante.
Soit la relation de récurrence :
$$u_{n+1}=0,9\,u_n+250.$$
• On commence par calculer la différence :
$$u_{n+1} - u_n = 0,9\,u_n + 250 - u_n = 250 - 0,1\,u_n.$$
• D'après la question 4(a), il a été démontré que pour tout $n \in \mathbb{N}$, $u_n \leq 2500$. Ainsi,
$$0,1\,u_n \leq 0,1 \times 2500 = 250.$$
• Par conséquent,
$$250 - 0,1\,u_n \geq 250 - 250 = 0.$$
• On en déduit que pour tout $n \in \mathbb{N}$,
$$u_{n+1} - u_n \geq 0,  $$
ce qui signifie que la suite $(u_n)$ est croissante.

Exercice 1/4c :
Déduire la convergence de la suite $(u_n)$ des propriétés précédentes.
La suite est croissante (ce qui a été démontré par récurrence) et majorée par 2500 (d'après la preuve par récurrence de la question 4a). Or, toute suite croissante et majorée converge. De plus, en passant à la limite dans la relation $u_{n+1}=0.9\,u_n+250$, on trouve que la limite $L$ vérifie $L=0.9\,L+250$, ce qui donne $L=2500$. Ainsi, la suite $(u_n)$ converge vers 2500.

Exercice 1/5 : 
Écrire un programme Python pour déterminer l'année où le nombre d'abonnés dépassera 2200.
```python
def trouver_annee_depassement():
	# Initialisation de la valeur de départ en 2020
	u = 1000
	n = 0  # n représente le nombre d'années écoulées depuis 2020
	# Tant que le nombre d'abonnés est inférieur ou égal à 2200
	while u <= 2200:
		n += 1
		u = 0.9 * u + 250  # Mise à jour du nombre d'abonnés pour l'année suivante
	# Retourne l'année où le seuil de 2200 abonnés est dépassé
	return 2020 + n

# Affichage du résultat
annee = trouver_annee_depassement()
print("L'année où le nombre d'abonnés dépasse 2200 est", annee)
```
<u>Chaque étape du raisonnement est la suivante :</u>
• On part de 1000 abonnés en 2020.
• Pour chaque année, on perd 10 % des abonnés et on gagne 250 abonnés.
• On utilise une boucle "`while`" pour simuler l'évolution annuelle jusqu'à ce que le nombre dépasse 2200.
• On retourne l'année correspondante en ajoutant le nombre d'années écoulées à 2020.
Un algorithme ou une calculatrice scientifique est nécessaire pour obtenir la réponse numérique.
Commentaire sur l'infographie : Analyser et commenter l'infographie en citant et analysant l'ensemble des documents fournis.
L'infographie présente un exercice riche et pédagogique centré sur les suites mathématiques appliquées à un contexte réel. Le titre « Exercice 1 - Suites mathématiques » et le contexte d'une influenceuse sur les réseaux sociaux introduisent immédiatement l'exercice en liant mathématiques et situation concrète. Cela incite l’apprenant à comprendre comment un phénomène réel peut être modélisé mathématiquement, ici par la perte annuelle de 10 % des abonnés compensée par l'acquisition de 250 nouveaux abonnés.
Les différentes questions proposées structurent l’exercice de manière progressive :
• La première partie demande de déterminer les valeurs initiales $u_0$ et $u_1$, ce qui constitue l'entrée dans le problème et permet d’ancrer la suite dans sa réalité de départ.
• La seconde question approfondit en justifiant la relation de récurrence modélisant l'évolution de la suite. Ceci renforce la compréhension des mécanismes de récurrence et du lien entre théorie mathématique et application pratique.
• L’extrait de code Python proposé, qui illustre le calcul de la suite grâce à une boucle, connecte la théorie à une approche algorithmique. Cette intégration de la programmation démontre que l’usage d’un algorithme ou d’une calculatrice scientifique est nécessaire pour obtenir la réponse numérique lorsque le problème le requiert.
• La partie suivante, par la demande d’un raisonnement par récurrence pour montrer que $u_n \leq 2500$ et pour démontrer le caractère croissant de la suite, pousse l’étudiant à utiliser des techniques de preuve mathématique fondamentales, consolidant ainsi ses compétences analytiques.
• Enfin, la dernière question relie mathématiques et programmation en demandant la conception d’un programme Python capable de déterminer l’année à laquelle le nombre d’abonnés dépassera 2200, soulignant l’importance de l’interdisciplinarité entre mathématiques et informatique.
Le format et le style de l’infographie sont adaptés pour un public éducatif : le texte est rédigé en français, utilisant un vocabulaire mathématique précis et une mise en page claire. L’harmonisation entre théorie et pratique, via le recours à une modélisation réelle et l’utilisation d’outils informatiques, rend l'exercice à la fois engageant et pertinent pour les étudiants du secondaire.
En résumé, l’infographie réussit à combiner modélisation mathématique, raisonnement par récurrence et programmation, créant ainsi un exercice complet qui permet aux élèves de visualiser l'application concrète des suites numériques tout en développant à la fois leur rigueur mathématique et leurs compétences en algorithmique.