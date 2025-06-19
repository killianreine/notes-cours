# Fiche de route - 01/04/2025
### ***Partie 1 - Le langage xHTML1.0***

> **HTML** = **H**yper**t**ext **M**arkup **L**anguage

##### ***Les URL***
Les navigateurs comme Firefox, accèdent au documents web via ce qu'on appelle des URL.
>[!cite] Définition
>Un URL est une chaîne de caractères qui indique :
>- Le protocole d'accès au document (HTTP, HTTPS)
>- Le nom / l'IP de l'hébergeur 
>- Le chemin d'accès
>- Le nom de la ressource

<u>Exemple :</u>
```uri
https://litis.univ-lehavre.fr/~fournier/HTML_CSS/coursHTML.php  
```
Dans l'URL ci dessus :
- `https` le protocole
	- `http` HyperText Transfert Protocol 
	- `s` secure
- `litis.univ-lehavre.fr`le nom du domaine
	- `litis` le sous-domaine, il permet d'organiser les différents services sur un même site web
	- `univ-lehavre` le nom du domaine qui ici est l'université du Havre
	- `.fr` domaine se situant en France
- `/~fournier/HTML_CSS/coursHTML.php` le chemin pour accéder à la ressource

>[!tip] Astuces / Recommandations
>- Faites en sorte que vos noms de fichiers et de dossiers ne contiennent pas d'espaces, utilisez les underscores `_`.
>- Aucun caractères accentués dans les noms.

>[!info] Remarque
>- Si nous aurions eu l'URL suivante : 
>
>`https://litis.univ-lehavre.fr/~fournier/HTML_CSS/`
>C'est à dire lorsque l'on ne spécifie pas de nom de fichiers dans l'URL alors, on accèdera au fichier `index.html` par défaut **si il existe**.

##### ***Définitions de base***
>[!cite] Définitions
>- On appelle **==élément==** le nom des balises.
>- On appelle **==balise==** un marqueur textuel dans un document indiquant le début et la fin d'une certaine structure *(ex. titre)*
>- On appelle **==attribut==** les options possibles des balises ouvrantes permettant d'associer **au moins** une valeur.
>- On appelle **==contenu==** le texte encadré entre les balises ouvrantes/fermantes **utilisant le même élément**.

Il existe trois types de balises :
- **ouvrante** `<element ...>`
- **fermante** `</element>`
- **vide** `<element ... />` *(=sans contenu)*

>[!tip] Astuce
>Pour insérer des commentaires en HTML on utilise `<!-- -->`.

##### ***Blocs et éléments intégrés***

- **Les éléments de bloc**
Ils permettent de définir les divisions d'un document, il interrompent le flux d'affichage du document. On utilise `div`.
*Interrompre le flux d'affichage : Le contenu d'un bloc s'affiche précédé et suivit d'un retour à la ligne*
- **Les éléments intégrés**
Eux n'interrompent pas le flux d'affichage, on utilise `span`.

##### ***Éléments vides et entité HTML***
>[!cite] Définition
>On appelle **==élément vide==**, un élément qui n'est pas associé à un contenu textuel, en gros il se referme juste après avoir été ouvert.
>- `br`, `img`, `hr`, ...

>[!cite] Définition
>Les **==entités HTML==** de la forme `&entite` permettent d'afficher mes caractères spéciaux.
>- `&lt` <, `&gt` >, `&copy`, ...

##### ***Structure d'un document HTML***
```html
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
      "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
  <head>
    <!-- encodage utf-8 -->
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />

    <title>Titre onglet</title>

  </head>

  <body>
    <!-- contenu (uniquement des blocs) -->
  </body>

</html>
```
- Le `DOCTYPE` représente en fait la norme utilisée, ici on utilise xHTML1.0.
- `<html>...</html>` les balises encadrant le contenu du document
- `<head>...</head>` l'entête *(=encodage, titre onglet, ...)* 
- `<body>...</body>` le corps de la page web (contenu affiché à l'écran)
  Structuré uniquement à l'aide des éléments de blocs, on ne laisse pas se balader du texte comme ça de manière libre.

>[!warning] Attention
>Veuillez respecter l'ordre de fermeture des balises :
>- **VALIDE** : `<span><h1><b>...</b></h1></span>`
>- **INVALIDE** : `<span><h1><b>...</h1></span></b>`

>[!info] Normes principales xHTML1.0
>- nom éléments et attributs en minuscules 
>- attributs associé à **au moins** une valeur
>- valeur des attributs entre guillemets

##### ***Blocs élémentaires***
Les blocs élémentaires permettent de définir les structures de base d'un document.
- paragraphes `p`
- titre `h1`, ..., `h6`
- texte préformaté `pre`
- ...
>[!warning] Attention
>Le contenu des blocs élémentaires est limité aux :
>- Texte simple
>- Élément intégré
>- Élément vide

##### ***Éléments intégrés***
Les éléments intégrés permettent de mettre en évidence des mots, de créer des liens entre les documents, insérer des images, des sautes de lignes, ... .
**Un élément intégré doit <u>obligatoirement</u> se trouver dans un élément bloc**.

- **Mise en évidence** visuelle
  `b`, `strong`, `i`, `em`, `sub`, `sup`, `big`, `small`, ...
  *à notre que certain d'entre eux comme `big` et `small` sont devenus obsolètes en HTML5, conséquence de l'utilisation des feuilles de styles CSS.*
- Les **liens hypertextes** :
```html
<p>
	<a href="lien vers fichier">texte du lien</a>
</p>
```
- Pour les forcer le retour à la ligne on utilise `<br/>` *à éviter d'utiliser*
- Les **images**
```html
<p>
	<img src="lien de l'image" alt="contexte" title="legende de l'image" />
</p>
```
>[!tip] Astuce
>- l'attribut `alt` permet d'afficher un petit texte lorsque l'image n'a pas réussi à être chargée.
>- l'attribut `title` permet lorsque l'utilisateur survole l'image d'afficher une petit légende.

##### ***Blocs structurés***
Ce sont des blocs qui nécessite l'utilisation d'autres blocs pour leur contenu.
- Citation longue
  Pas de mise en forme particulière, à part une marge à gauche
- Liste
	- Liste ordonnée `ol` associée à `li`
	- Liste non ordonnée `ul` associée à `li`
	- Liste de définition `dl` associée à `dt` et `dd`
>[!info] Remarque
>`li` et `dd` accepte tous les contenus comme `div`.
<u>Exemple de liste de définition :</u>
```html
<dl>
  <dt>defA :</dt>
  <dd>definition term</dd>
  <dt>defB : </dt>
  <dd>definition data</dd>
</dl>
```

***Structure correcte pour les listes imbriquées***
```html
<ul>
	<li> Premier item 
		<ol> <!-- sous liste -->
			<li> Sous item </li>
			<li> Sous item </li>
		</ol>
	</li>
	<li> Second item 
		<ol> <!-- sous liste -->
			<li> Sous item </li>
			<li> Sous item </li>
		</ol>
	</li>
</ul>
```
En gros ce qu'il faut retenir c'est que si vous faites des sous listes, la déclaration de la sous liste doit se faire à l'intérieure de l'item `li` associé.

##### ***Les tableaux***
- `<table>...</table>` les balises qui délimitent le tableau
- `<tr>...</tr>` ligne composée de cellules
- `<td>...</td>` *(= simple)* ou `<th>...</th>` *(= titres)*
- `<caption>...</caption>` légende/titre du tableau
- `<thead>, <tbody>, <tfoot>` sont les marqueurs sémantiques, utiles pour l'impression de tableaux sur plusieurs pages.
- `<colgroup>` regrouper ,un ensemble de colonnes
- `col` propriétés d'alignement d'une/plusieurs colonnes
```html
<table border="1">
	<tr>
		<th>Titre col1</th>
		<th>Titre col2</th>
	</tr>
	<tr>
		<td align="center" rowspan="2">contenu 1.2</td>
		<td>contenu 2.2</td>
	</tr>
	<tr>
		<td valign="bottom">contenu 2.3</td>
	</tr>
</table>
```
- L'attribut `border="1"` permet d'ajouter des bordures autour du tableau et entre les cellules, sinon, ce dernier ne possède aucune bordure.
- `colspan="n"` pour fusionner `n` colonnes
- `rowspan="n"` pour fusionner `n` lignes
- `valign` ou `align` pour l'alignement vertical horizontal

##### ***Entête et métadonnées***
Dans l'entête d'un fichier HTML `<head> ... </head>` on trouve des informations concernant le document :
- Le titre de l'onglet **obligatoire** avec `title`
- Les métadonnées avec `meta` :
	- date de MAJ, date de création, mots clés, auteur, ...
- L'élément `link` permet de lier une feuille de style CSS par exemple
- L'élément `script` lui permet de lier un fichier JS
[plus d'info sur l'élément `meta`](https://litis.univ-lehavre.fr/~fournier/InfoDoc/coursHTML.php?page=31)
```html
<meta name="Author" content="Killian Reine" />
```
par exemple...

**Retour sur l'élément `link`**
Il permet de relier d'autres documents à un même document HTML :
- feuille de style
- Une icone
```html
<link rel="stylesheet" href="chemin fichier css" type="text/css" />
<link rel="shortcut icon" href="chemin icone" type="image/bmp" />
```

##### ***Les formulaires***
Les formulaires permettent de créer en HTML des documents interactifs autorisant la saisie d'informations par un utilisateur.
Les balises `<form>...</form>` permettent d'encadrer les différents éléments d'un formulaire.
```html
<form action="programme" method="post | get" enctype="type" target="nom">
<!-- Des informations à saisir par ex. -->
</form>
```
- `action` indique l'URL du programme qui vas traiter les données envoyées par le formulaire.
- `method` qui peut être `post` ou `get` indique la méthode utilisée pour envoyer les données.
- `enctype` méthode d'encodage
- `target` désigne ou le résultat du formulaire sera affiché *(optionnel)*
***Les éléments associés aux formulaires***
- l'élément `input`
`input` est un élément vide `<input .... />`, il permet d'interagir avec l'utilisateur de plusieurs manières. Cette dernière dépend de la valeur de l'attribut `type`.

|    Type    | Pour quoi faire                                                                |
| :--------: | :----------------------------------------------------------------------------- |
|   `text`   | zone de saisie                                                                 |
| `password` | zone de texte non lisible (pour les mdp)                                       |
|  `radio`   | bouton radio                                                                   |
| `checkbox` | case à cocher                                                                  |
|  `submit`  | Bouton d'envoi du formulaire<br>Au clic, il exécute le programme dans `action` |
|  `image`   | Bouton représenté par une image                                                |
|  `reset`   | Bouton pour annuler les saisies, réinitialiser                                 |
|   `file`   | upload un fichier                                                              |
|  `hidden`  | champs caché                                                                   |
```html
<form action="" method="" >
	<input type="text"  size="15" />
	<input type="checkbox" />
	<input type="radio" name="nomBouton" /> 
	<input type="submit" value="Envoyer" />
	<input type="image" src="chemin image" />
	<input type="reset" value="Annuler" />
	<input type="hidden" value="espace" />
	<input type="password" value="test" size="15" />
	<input type="file" />
</form>
```

- L'élément `select`
Il permet de créer une liste de sélection (déroulante) et de choisir une ou plusieurs options.
```html
<select name="nomChoix" size="3">
  <option value="v1">un</option>
  <option value="v2">deux</option>
  <option value="v3">trois</option>
  <option value="v4">quatre</option>
</select>
```
Ici je ne peux sélectionner qu'une option sur les quatre.
Par contre, si j'ajoute `multiple="multiple"` je pourrai sélectionner plusieurs options avec `ctrl+clic`.
```html
<select name="choixMultiple" size="3" multiple="multiple">
```

- L'élément `textarea`
Permet la saisie de texte long. Lors de sa déclaration, on peut lui donnée un nom pour identifier la zone de saisie `name`, le nombre de colonnes `cols` et de lignes `rows` affichées, ...
```html
<textarea rows="12" cols="50">Du texte bien long...</textarea>
```

- L'éléments `label`
Il permet d'écrire un seul champs de saisie.
```html
<label for="id">Nom champs de saisie
      <input id="id" type="text" size="12" />
</label>
```

- L'éléments `fieldset`
Il permet de regrouper des champs de saisie et de leur associer une `legend` légende.
```html
<fieldset>
    <legend>Légende</legend>
    <label for="lab1">Label 1 :<input id="lab1" type="text" size="12" /></label>
    <label for="lab2">Label 2 :<input id="lab2" type="text" size="12" /></label>
</fieldset>
```

##### ***Passage à HTML 5***
- **Simplification du squelette** du document
```html
<!DOCTYPE html>
<html lang="fr">
<head>
	<meta charset="utf-8" />
	<link rel="stylesheet" href="style.css" />
	<script src="script.js"></script>
</head>
<body>
	<!-- Contenu de la page -->
</body>
```
- **Ajout de blocs**
  `header`, `footer`, `nav`, `aside`, `section`, `article`
- **Intégration multimédia**
  `video`, `audio`, `canvas`
- **Amélioration formulaires**
	- nouveaux input : `date`, `color`, `datetime`, `datetime-local`, `time`, `week`, `month`, `number`, `ranger`, `search`, `tel`, `email`, `url`
	- nouveaux éléments : `datalist`, `keygen`, `output`
- **Enrichissement API JS**
	- Géolocalisation
	- Drag and drop
	- Web sockets
	- Web storage
	- Canvas
- Suppression de `acronym` pour `abbr`
- Suppression au profit de CSS : `big`, `small`, `center`, `font`, ...
- Suppression de `frame`, `frameset`, ...

### ***Partie 2 - Le langage CSS***

>**CSS** = **C**ascading **S**tyle **S**heets

##### ***Intérêt des feuilles de styles***
- HTML
	- Structurer les éléments d'une page
	- Visualisation réalisée par le navigateur par interprétation du code HTML
- CSS
	- Définition d'une ou de plusieurs apparences à différents éléments
	- Meilleure maîtrise de la présentation de la page
	- Facilite l'unification des styles de toutes les pages du site sans modifier le contenu HTML
	- Indépendant du code HTML, simplifiant la lecture

##### ***Ajouter du style !***
- Balise `<style>...</style>` dans l'entête HTML
```html
<header>
	<title>Titre de la page</title>
	<meta ... />
	<style>
		/* Les styles CSS */
		h1{
			color: red;
		}
	</style>
</header>
```
- Attribut `style` directement dans les éléments HTML
```html
<h1 style="color: red;">Titre niveau 1</h1>
```
- Utilisation de `link` pour lier un fichier CSS 
```html
<header>
	<title>Titre de la page</title>
	<meta ... />
	<link rel="stylesheet" href="style.css" type="text/css" />
</header>
```
*C'est la méthode la plus recommandée pour insérer du CSS.*

##### ***Structure du code CSS***
Voici la structure générale d'un code **css**.
```
element {
	propriete: valeur;
	propriete: valeur;
}
```

>[!cite] Définition
>- Un ==**propriété**== est un élément de style paramétrable
>  `color`, `background-color`, `font-size`, ...
>- Une **==valeur==** est un ensemble de possibilité prédéfini pour une propriété.

- Pour les longueurs, il existe plusieurs unités de mesure : `pt`, `px`, `ex`, `em`, `cm`, `in`, `pc`, `mm`
	- Longueur absolues : `1in = 2.54cm`, `1pt=1/72in`, `1pc=12pt`
	- Longueur relatives : 
		- `em` et `ex` dépendent de la taille de la police de référence.
		- Les pixels `px` dépendant de la taille du média (tablette, téléphone, pc)
- Pour les URL : `url("nomURL")`
- Les pourcentages : `...%`

##### ***Les sélecteurs***
- `*` universel, les propriétés s'appliquent à tous les éléments du document
- les identifiants `#id`
- les classes `.class`
- Pseudo éléments, pseudo classes
- sélecteurs contextuels

##### ***Les couleurs***
- `color` premier plan, les caractères
- `background-color` l'arrière plan
- `border-color` les couleurs des bordures
Les valeurs de couleurs disponibles sont : le nom de la couleur, le code RGB ou le code hexadécimal.

| `maroon` |  `red`  |  `blue`   |     `orange`     | `yellow` | `olive` |
| :------: | :-----: | :-------: | :--------------: | :------: | :-----: |
| `black`  | `white` | `#00ff00` | `rgb(255, 0, 0)` |  `teal`  | `gray`  |
##### ***Propriétés associées aux textes***
- `text-align`
- `vertical-align`
- `text-decoration` (souligné, surligner, barré, ...)
  `underline`, `overline`, `line-through`
- `text-transform` 
  `none`, `capitalize`, `uppercase`, `lowercase`
>[!tip] Astuce
>- `capitalize` chaque mot commence par une majuscule
>- `uppercase` tout en majuscule

- `text-indent`
  On spécifie la taille ou le pourcentage
- `line-height`
  Un nombre, taille, pourcentage
- `word-spacing`
  par défaut `normal` ou sinon on spécifie la taille de l'espace
- `letter-spacing`
- `white-space`

##### ***Propriétés associées aux polices***
- `font-family` pour changer la police (famille)
  `serif`, `arial`, `sans-serif`, `monospace`, `cursive`
- `font-style`
  `normal`, `italic`, `oblique`
- `font-variant`
  Soit on fait rien soit on associe `small-caps`, en gros la première lettre est une grosse majuscule, les autres des plus petites.
- `font-weight` pour mettre en gras
  valeur entre `[100; 900]`, sinon `lighter`, `bold`, `bolder`
- `font-size` la taille de la police
  `xx-small`, `x-small`, `small`, `medium`, `large`, `x-large`, `xx-large`
  On peut aussi spécifier la longueur, le pourcentage
>[!info] Remarque
>La propriété `font` regroupe plusieurs propriétés globales :
>- `font-style`
>- `font-variant`
>- `font-weight`
>- `font-size`
>Et d'autres, on peut alors combiner le tout en une seule ligne.

<u>Exemple</u>
```css
p{
	font: italic bold 14pt/3 times, serif; }
}
```

##### ***Les boîtes***
Tous les éléments HTML sont affichés dans une boîte.
Chaque boîte est construite selon 4 niveaux :
- La marge extérieure : `margin`
- Les bords : `border`
- La marge intérieure : `padding`
- le contenu
![[css-box-model.png|500]]
###### ***Les marges extérieures***
- `margin-left`
- `margin-right`
- `margin-top`
- `margin-bottom`
- `margin`
  Peut être définit de plusieurs façon
```css
#premier{
	margin : 10px;
	/*Chaque marge extérieur de 10px*/
}

#second{
	margin : 10px 20px;
	/*
	équivaut à :
	margin-top et margin-bottom à 10px
	margin-left et margin-right à 20px
	*/
}

#troisieme{
	margin : 10px 20px 30px;
	/*margin-top | margin-left margin-right | margin-bottom*/
}

#quatrieme{
	margin: 10px 15px 12px 13px;
	/*margin-top | margin-right | margin-bottom | margin-left*/
}
```

###### ***Les bordures***
- `border-color`
- `border-width`
  `thin`, `thick` ou alors la longueur
- `border-style`
  `solid`, `dotted`, `dashed`, `double`, `groove`, `inset`, `outset`, ...
Les déclinaisons des propriétés précédentes sont valables pour chaque bordure une à une :
- `border-left-*`
-  `border-right-*`
-  `border-top-*`
-  `border-bottom-*`
Les règles d'attributions fonctionnent de la même manière que pour `margin`.
![[Pasted image 20250329160620.png]]
###### ***Les marges intérieures***
- L'élément `padding` fonctionnent globalement de la même manière que `margin`.

##### ***Propriétés d'arrière plan***
>[!info] Remarque
>Les propriétés d'arrière plan s'appliquent à l'intérieur des bordures :
>- `padding`
>- contenu du bloc
- `background-color`
- `background-image: url(...);`
- `background-repeat`
- `background-position`
- `background-attachment`
  `fixed` ou `scroll`

##### ***Propriétés de liste***
- `list-style-type`
  `disc`, `circle`, `square`, `decimal`, `lower-roman`, `upper-roman`, `lower-greek`, `georgian`, `katakana`, `lower-alpha`, `alpha`
- `list-style-position`
  `inside`, `outside`
- `list-style-image: url(...);`
  par défaut `none`
La propriété `list-style` regroupe ces dernières.

##### ***Propriétés de tableaux***
- `border-collapase`
  Les bords des cellules séparés `separate` ou non `collapse`
- `border-spacing` espacement entre les bords des cellules
- `caption-side`
  Position de la légende `top` ou `bottom`
- `empty-cells`
  Afficher les cellules vides `show` ou `hide`
- `table-layout` chevauchement des cellules

##### ***Propriétés positionnement des boîtes***
- `width`, `height`, `max-height`, `max-width`
  pareil avec `min-*`
- `position`
	- `static` et `relative` : Respecte le flux normal des éléments
	- `absolute`, `fixed` : Affichent une boîte en dehors du flux
- `top`, `right`, `bottom`, `left` position lorsque **non statique**
- `float` place occupée par un élément flottant
  `left`, `right`, `none`
- `overflow` gestion de l'affichage du contenu d'un bloc lorsqu'il dépasse les limites
  `visible`, `hidden`, `scroll`, `auto`
- `z-index : entier`, le niveau d'empilement d'affichage d'une boîte
  Qui est au premier plan, au second, ... groissièrement

##### ***Retour sur les sélecteurs***
- `*` universel, les propriétés s'appliquent à tous les éléments du document
- les sélecteurs d'identifiants `#id`
  Un unique usage dans le document.
- les classes `.class`
  Usage groupé sur des éléments distincts 
- Pseudo éléments
- Pseudo classes
- sélecteurs contextuels

- `elem fils`
  Cible tout les `fils` dans `elem`
  *par exemple `table p`*
- `pere > element`
  Cible les élément directement inclus dans père
```html
<th>
	<p> Un texte random...</p>
</th>
```
Pour styliser le paragraphe on utilisera le sélecteur `th > p`
- `element:first-child`
  Premier fils d'un élément
  `tr:first-child`, on cible cellules de la première ligne
- `element + second`
  Cible `second` si il est directement précédé de `element`
  `h1+p` cible les paragraphes qui suivent un titre `h1`
```html
<h1>TITRE</h1>
<p>Du paragraphe comme ça pour rigoler</p>
```
- `element[attribut]`
  Cible tous les éléments associé à l'attribut `attribut`
- `element[attribut="valeur"]`
   Cible tous les éléments associé à l'attribut `attribut` et avec la valeur `valeur`

>[!cite] Définition
>un élément _`f`_ ==**descend**== d'un élément _`ancêtre`_ s'il est employé dans le contenu de _`ancêtre`_ (à n'importe quel endroit).

##### ***Arborescence HTML***
```html
<!DOCTYPE ...>
<html xmlns="http://www.w3.org/1999/xhtml">
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title>titre onglet</title>
    ...
  </head>
  <body>
    <h1> Titre</h1>
    <p>Du texte</p>
    <ol></ol>
    ...
  </body>
</html>
```

Est représenté par l'arbre suivant :
```
html
 ┣━━━ head
 ┃     ┣━━━ meta
 ┃     ┣━━━ title
 ┃     ┗━━━ ...
 ┗━━━ body
       ┣━━━ h1
       ┣━━━ p
       ┣━━━ ol
       ┗━━━ ...
```
- `html` est de profondeur 0
- `body` de profondeur 1
- `h1` de profondeur 2

##### ***Pseudo éléments et pseudo classes***
- Avec les liens
	- `a:link` lien vierge
	- `a:visited` lien visité
- Avec la souris
	- `:hover` on survol
	- `:focus` élément de formulaire acceptant els saisies clavier
	- `:active` là où on clique
- `:first-line` première ligne d'un bloc
- `:first-letter`
- `::before` et `::after` avant/après contenu d'un élément