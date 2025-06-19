# Fiche de cours - PHP

>**PHP** = PHP Hypertext Preprocessor

>[!warning] Attention
>- **PHP** est interprété côté serveur
>- **JS** est exécuté du coté client

En PHP, le code est délimité par `<?php ... ?>`, chaque instruction est terminée par un `;` et , les blocs délimités par des accolades. 
Plusieurs méthodes pour insérer des commentaires :
```php
// Sur une ligne
/*
	Sur
	plusieurs lignes
*/
```

Pour définir une variable en PHP on utilise `$`. **Le nom des variables est sensible à la casse**, il doit commencer par un Under score `_` ou par une lettre pouvant être minuscule ou majuscule.
```php
$ma_variable = valeur
```

```php
$a = 1;
function test() {
   global $a;  // Référence à la variable globale
   echo $a;
}
test(); // Affiche 1
```

Il existe de nombreuses **variables prédéfinies** que nous verrons tout le long du semestre.
>[!tip] Astuce
>Pour afficher la liste complète des variables prédéfinies il suffit de taper `phpinfo`.

Il es possible de définit une **constante** en utilisant la fonction `define`, ainsi cette dernière ne pourra jamais être modifiée ou détruite durant le script.
```php
<?php
	define('MA_CONSTANTE', valeur)
?>
```

>[!warning] Attention
>- Généralement, une constante est écrite en majuscules
>- Les constantes n'acceptent que les types scalaires (booéen, entier, double, chaine de caractères)

##### ***Les types en PHP***
>[!info] Information
>PHP est un langage **faiblement typé**.

| `bool`  | `int`  | `float`  | `string` | `array` |          `object`          |
| :-----: | :----: | :------: | :------: | :-----: | :------------------------: |
| booléen | entier | flottant |  chaîne  | Tableau | Obj de classe indéterminée |
*Un booléen peut avoir la valeur `TRUE` ou `FALSE`.*

##### ***Interpolation des variables***

```php
$var = 45;
$interpol = "ma variable vaut $var.";
$sansInterpol = 'ma variable vaut $var.';
echo $interpol;
echo $sansInterpol;

// Console :
// ma variable vaut 45.
// ma variable vaut $var.
```
Les chaînes entre double guillemets permettent l'**interpolation de variables**. 
***Caractère d'échappement :***

| `\n` | `\t` | `\\` | `\'` | ... |
| :--: | :--: | :--: | :--: | :-: |

>[!warning] Attention
>- Dans les chaînes dites simple `' ... '` (i.e. entre simple guillemets), seul les caractères d'échappements `\'` e `\\` sont utilisables.
>- L'interpolation ne fonctionne pas avec les tableau et les appels de fonctions.

```php
<?php
function addition($a, $b){
	return $a + $b;
}

echo "Le résultat est {addition(4, 5)}"; // ERREUR
echo "Le résultat est {$addition(4, 5)}"; // ERREUR
echo "Le résultat est ".addition(4, 5); // CORRECT
?>
```
On peut **concaténer** des chaînes de caractères en utilisant l'opérateur `.` qui permet la concaténation.

Il existe deux manières de créer des tableaux :
##### ***Tableau classique***
  ```php
$tab = array(1, 2, 3, 4);
echo $tab[0]; // Affiche 1
```
##### ***Tableau associatif***
```php
$tabAsso = array(
	'rouge' => 'R',
	'vert' => 'G',
	'bleu' => 'B'
);

echo $tabAsso[1]; // ERREUR
echo $tabAsso['vert']; // Affiche G
```

##### ***Opérations arithmétiques, logiques, comparaisons***

|   `+`    |     `-`      |      `*`       |   `/`    |  `%`  |   `**`    |
| :------: | :----------: | :------------: | :------: | :---: | :-------: |
| Addition | Soustraction | Multiplication | Quotient | Reste | Puissance |

| `==`  | égal                               |
| ----- | ---------------------------------- |
| `!=`  | **différent**                      |
| `<>`  | **différent**                      |
| `<`   | **inférieur**                      |
| `<=`  | **inférieur ou égal**              |
| `>`   | **supérieur**                      |
| `>=`  | **supérieur ou égal**              |
| `===` | **égalité (de type et de valeur)** |
| `!==` | **différent**                      |
| `<=>` | **combiné (spaceship)**            |
```php
echo 3 == '3'; // TRUE
echo 3 === '3' // FALSE

echo 3 != '3' // FALSE
echo 3 !== '3' // TRUE
```

>[!tip] Tips
>Les opérateurs `===` et `!==` permettent d'éviter les conversions de types.

| `&&` | `and` | `or` | \|\| | `xor` | `!` |
| :--: | :---: | :--: | :--: | :---: | :-: |
|  ET  |  ET   |  OU  |  OU  |  XOR  | NOT |
Les opérateurs logiques suivent les priorités suivantes : 
```
! > && > || > and > xor > or
```

##### ***Post et pré incrémentation***
```php
$a++; // Post-incrémentation
++$a; // Pré-incrémentation
$a--; // Post-décrémentation
--$a; // Pré-décrémetation
```
Ainsi, on a :
```php
$a = 4;
$b = 2;
echo $a++; // Affiche 4
echo ++$b; // Affiche 3
```

##### ***Opérateur de coalescence***
L'opérateur de **coalescence nulle** (`??`) en PHP est utilisé pour vérifier si une variable est définie et différente de `null`. C'est une façon concise de gérer les valeurs par défaut.
```php
$var = $var1 ?? $var2
```
- Si `var1` est définie et différente de `null` alors `var` prendra cette valeur.
- Sinon `var2`

On peut aussi utiliser l'opérateur ternaire.
```php
<?php
	$nom = isset($_GET['nom']) ? $_GET['nom'] : 'Invité'; // Ternaire
	$nom = $_GET['nom'] ?? 'Invité'; // Coalescence (plus propre)
?>
```

##### ***Opérateur de contrôle d'erreur***
L'**opérateur de contrôle d'erreur** en PHP est représenté par le symbole `@`. Il est utilisé pour **supprimer les messages d'erreur** générés par certaines expressions.
Lorsqu'il est placé devant une expression, l'opérateur `@` masque toutes les erreurs éventuelles qui pourraient être générées par cette expression.
```php
// Syntaxe de base
@$result = expression;
```

<u>Quelques exemples :</u>
```php
<?php
$contenu = @file_get_contents('fichier_inexistant.txt');

if ($contenu === false) {
    echo "Erreur : Impossible de lire le fichier.";
}
?>
```

```php
<?php
	echo @$variable_non_definie; // Pas d'erreur affichée, juste une sortie vide.
?>
```

>[!warning] Attention
>Il est généralement préférable d'utiliser des `try...catch` au lieu de l'opérateur de gestion des erreurs.

##### ***Structure de contrôle***
```php
if (condition){
	// Instructions
}
elseif (_otherCondition){
	// Autres instructions
}
else{
	// Instructions
}
```

```php
// On considère une variable $var 
switch ($var){
	case cas1:
		// Truc à faire
	case cas2:
		// ...
	case ..:
		// ...
	default:
		// Instructions par défaut
}
```

```php
/*
Les trois formes suivantes sont égales
On considère deux variables $start et $end définies au préalable
*/

for(int $i=$start; $i<=$end; $i++){
	// Truc à faire
}

for(int $i=$start;;$i++){
	if($i > $end) { break; }
	// Instructions
}

$i = $start;
for(;;){
	if($i > $end) {break;}
	//Instructions
	$i++;
}

for($i = $start; $i<=$end; INSTRUCTIONS, $i++);
```

###### ***`foreach` avec un tableau classique***
```php
$tableau = array(1, 2, 3, 4, 5);
foreach($tableau as $valeur){
	echo $valeur;
}
// Affichera successivement 1, 2, 3, 4, 5
```

###### ***`foreach` avec un tableau associatif***
```php
$tabAsso = array(
	'rouge' => 'R',
	'vert' => 'G',
	'bleu' => 'B'
);
foreach($tabAsso as $cle => $valeur){
	echo "$cle : $valeur \n";
}
//Affichage :
/*
	rouge : R
	vert : G
	bleu : B
*/
```

```php
while(condition){
	// Instructions
}
```

```php
do{
	// Instructions
}while(condition)
```

##### ***Produire du code HTML***
```php
$code = '<html>...';
$code .= '</html>'; // Concaténation

echo $code;
```

##### ***Exécution du programme PHP***
```
php -f nomFichier.php
```

On peut générer un fichier `html` pendant l'exécution, il suffit de *détourner* la sortie standard.
```
php -f nomFichier.php > nomFichier.php
```

##### ***Les fonctions***
```php
function nom_fonction ($param_1, ..., $param_n]) [: type] {
	//instruction_1;
	// ...
	//instruction_m;
	return $resultat;
}
```

```php
rand(borneINF, borneSUP); // Génération d'un nb aléatoire [borneINF; borneSUP]
```

***Valeur par défaut***
```php
function maFonction($var = valDefaut, ...){ ... }
```

###### ***Fonctions prédéfinies***
- `strlen($chaine)` longueur d'une chaine
- `explode($delim, $chaine, [$limite])` Retourne un tableau de sous chaîne de la chaine principale découpé selon le délimiteur.
- `substr($chaine, $start, [$length])` Retourne une partie de chaine à partir de l'indice `$start`, d'un longueur `$length` *optionnel*.
- `sizeof($array)` nb élément du tableau.
- `sort($array)` trier dans l'ordre croissant
- `array_pop(&$array)` dépile et retourne le dernier élément du tableau.
- `array_push(&$array, $var)` ajoute une/plusieurs variables à la fin du tableau.

```php
<?php
  function ajouteDuBlahblah(&$string) {
     $string .= ', et du blahblah.';
  }

  $str = 'Ceci est une chaîne';
  ajouteDuBlahblah($str); // le symbole & n'est pas nécessaire, la passage par référence est défini une fois pour toute lors de la déclaration de la fonction
  echo $str; /* affiche Ceci est une chaîne, et du blahblah. */
?>
```

```php
<?php
  function fctBlah2($bar) {
    $bar .= ', et blah blah.';
  }
  $str = 'Ceci est une chaîne';
  fctBlah2 ($str);
  echo $str;// affiche 'Ceci est une chaîne'
  fctBlah2 (&$str);
  echo $str; /* affiche 'Ceci est une chaîne, et blah blah. */
?>
```
##### ***Les fichiers***
Et oui ! PHP possède des fonctions pour charger des fichiers, ce qui permet de charger un script contenant des fonctions usuelles.
- `require(nomFichier)` se remplace par le contenu du fichier
- `require_once(nomFichier)` évite de charger plusieurs fois le même fichier
Il existe les même fonctions pour inclure le contenu d'un fichier, très utile lorsqu'on souhaite insérer un en-tête ou un pied de page.
- `include(nomFichier)` ou `include_once(nomFichier)`
>[!warning] Attention
>À la différence de `require` si `include` évalue mal le fichier, cela déclenchera un warning.

```php
// Ouverture d'un fichier
$fichier = fopen("nomFichier", "mode");

// Fermuture d'un fichier
fclose($fichier);
```

Les modes possibles sont `'r'`, `'w'`, `'a'`, `'w+'`, `'a+'`, où :
- `a+`
  Représente les droits d'ajouts et de lecture. **On ajoute à la fin d'un fichier**.
	  - Ouvre le fichier en lecture/écriture
	  - Le curseur  se trouve en fin de fichier
	  - Les données sont écrites à la fin pour pas écraser le contenu existant
	  - Création du fichier si il n'existe pas
- `w+`
  Représente le mode lecture et écriture.
	- Ouverture en lecture/écriture
	- Efface le fichier si il existe
	- Création du fichier si il n'existe pas
	- Le curseur est placé **au début** du fichier

```php
<?php
$file = fopen("exemple.txt", "w+");

if ($file) {
    // Écrire dans le fichier (écrase le contenu existant)
    fwrite($file, "Contenu entièrement remplacé.\n");

    // Ramener le curseur au début pour lire ce qui a été écrit
    rewind($file);
    echo fread($file, 100); // Lire les 100 premiers caractères

    fclose($file);
} else {
    echo "Erreur : Impossible d'ouvrir le fichier.";
}
?>
```

>[!tip] Astuce
>- Si le fichier ouvert n'est pas valide alors `$file=NULL`.
>- On ajoute toujours à la fin d'un fichier
>- Le pointeur de fichier doit être valide

***LECTURE DANS UN FICHIER***
- `fgets($file, [length])` retourne une chaine de caractère contenue dans le fichier.
	- Si on spécifie `length` alors la lecture s'arrête à `length-1 octets` ou à la fin de la ligne en cours
	- Sinon la ligne complète est récupérée
- `feof($file)` retour `TRUE` si on est au bout du fichier après le dernier appel à `fgets()` sinon `FALSE`;
- `file_get_contents(nomFichier)` retourne l'entièreté du fichier dans une chaine de caractère.
- `file(nomFichier)` retourne un tableau qui contient chaque ligne du fichier.

***ÉCRITURE DANS UN FICHIER***
- `fwrite($file, $chaine, $length)` écrit `$chaine` dans le fichier.
- `fputs(...)` pareil que au dessus.

<u>Lecture d'un fichier ligne par ligne</u>
```php
$fp=fopen('fichier.txt','r');
$codeHTML ='';
if(!$fp) { // vérifie que le pointeur de fichier est valide
	exit('Impossible d\'ouvrir fichier.txt');
}
else {
  while (!feof($fp)) { // répète jusqu'à la fin de fichier
    $ligne = fgets($fp); // lit une ligne
    $ligne = rtrim($ligne); // enlève le retour chariot de fin de ligne
    $codeHTML .= "$ligne<br />";
  }
  fclose($fp);
}
echo $codeHTML;
```

<u>Lecture avec `file`</u>
```php
$tabLignes=file('fichier.txt');
$extraitHTML = '<pre>';
if(is_array($tabLignes)) {
	foreach ($tabLignes as $ligne) { 
		$ligne = rtrim($ligne); // enlève le retour chariot de fin de ligne
		$extraitHTML .= "$ligne\n";
	}
}
$extraitHTML .= '</pre>';
print $extraitHTML;
```

On utilise `implode([delim], array)` pour la concaténation.
```php
implode(' ; ',array(" Albus", ' Percival', "Wulfric"));
implode(array(" Albus", ' Percival', "Wulfric"));

/*
Albus ; Percival ; Wulfric
Albus PercivalWulfric
*/
```

À l'inverse `explode(delim, chaine)` pour découper une chaine.
```php
$tab = explode(";", implode(' ; ',array(" Albus", ' Percival', "Wulfric")));
foreach ($tab as $mot){
	echo "$mot\n";
}

/*
Albus 
Percival
Wulfric
*/
```
##### ***Les tableaux***
```php
// Tableau indexé automatiquement
$tab = array(1, 2, 3, ...);
$tab = [1, 2, 3, 4, ...];

// Tableau associatif
$tab = array(
	cle => val,
	cle2 => val2
);
```

On peut **modifier / accéder** aux éléments d'un tableau.
```php
// Tableau indéxé
$tab[indice]=...;

// Tableau associatif
$tab['cle']=...;
```

**Ajout/suppression**
```php
// Ajout à la fin
$tab[count($tab)]=nvElem;
$tab[] = nvElem;

// Ajout au début
array_unshift($tab, nvElem);

// Suppression
$dernier = array_pop($tab); // DERNIER
$premier = array_unshift($tab); // PREMIER
```

**TRI**
```php
sort($tab); // CROISSANT
rsort($tab); // DECROISSANT
```

**DÉCOMPOSITION TABLEAU ASSOCIATIF**
```php
$keyTab = array_keys($tabAsso);
$valueTab = array_values($tabAsso);
```

**OPÉRATIONS SUR LES TABLEAUX**
- `+` l'union de deux tableaux
- `==` égalité
- `===` identité, `!==` non identité *à revoir*
- `!=, <>` inégalité
- **Union**
    - L'opérateur d'union ajoute le contenu du deuxième tableau à la fin du premier.
    - **En cas de clés identiques** les éléments du deuxième tableau sont ignorés.
- **Égalité, Identité**
    - Deux tableaux sont égaux lorsqu'ils possèdent les mêmes clés/valeurs.
    - Deux tableaux sont identiques lorsqu'ils possèdent les mêmes clés/valeurs dans le même ordre et avec les mêmes types.

>[!warning] Attention
>- Fichier PHP avec l'extension `.php`
>- Fichier s'exécute côté serveur
>- Pour exécuter un fichier PHP il faut y accéder via un serveur web et protocole HTTP/HTTPS

##### ***Les formulaires***
Les formulaires permettent d'interagir avec les utilisateurs sur un site web. 
- `phpinfo();` pour obtenir les variables d'environnement
	- `$GLOBALS`, `$_SERVER`, `$_GET`, `$_POST`, `$_FILES`, ... 
	- On récupère les informations transmises depuis une URL via `$_SERVER['QUERY_STRING']`
	- `$_SERVEUR['REQUEST_METHOD']` pour savoir quelle méthode on a utilisé (`GET` ou `POST`)
	- Les super variables `$_POST` et `$_GET` représentent des tableaux associatifs qui contiennent en fait les données transmises. 
	- `$_REQUEST` est un tableau associatif composé du contenu de `$_GET`, `$_POST` et `$_COOKIE`

**Envoyer des informations**
- La méthode GET
  Les données envoyées sont ajoutées à l'URL
- La méthode POST
  Elle utilise une méthode d'envoie à part entière qui n'utilise pas les URL en plus, elle permet d'envoyer un plus grand nombre de données

**Structure d'un formulaire**
```html
<form action="prog.php" method="get | post" enctype="type" target="nom">
	<!-- Contenu du formulaire -->
</form>
```

- `action="prog.php"`
  c'est l'URL vers lequel on vas traiter les données envoyées
- `method="get"` ou `method='post'`
  Quelle méthode a été utilisée pour envoyée les données au programme
- `enctype="type"` la méthode d'encodage utilisée (MIME valide avec POST)
- `target="nom"` *(optionnel)*
  Dans quel fenêtre on affiche le résultat du traitement du formulaire

**Éléments d'un formulaire**

*Les `input`*
C'est un élément vide qui permet d'interagir de plusieurs façon avec l'utilisateur.
```html
<input type="type" id="identif" size="..." />
```

Voici les différents types :

```html
<label>Type texte</tabel>
<input type="text" />
```
<label>Type texte</tabel>
<input type="text" placeholder="du texte" />

```html
<label>Type password</tabel>
<input type="text" />
```
<label>Type password</tabel>
<input type="password" />
*Dans ce cas, le texte tapé sera remplacé par `*` ou  $\cdot$ *

```html
<label>Type radio</tabel>
<input type="radio" value="cheypas" /> <label>choix</label>
<input type="radio" value="cheypas" checked /> <label>choix coché</label>
```
<label>Type radio</tabel>
<input type="radio" name="cheypas" /><label>choix</label>
<input type="radio" value="cheypas" checked /> <label>choix coché</label>

```html
<label>Type radio</tabel>
<input type="checkbox" value="cheypas" /> <label>choix</label>
<input type="checkbox" value="cheypas" checked /> <label>choix coché</label>
```
<label>Type checkbox</tabel>
<input type="checkbox" value="cheypas" /> <label>choix</label>
<input type="checkbox" value="cheypas" checked /> <label>choix coché</label>

```html
<label>Type submit</tabel>
<input type="submit" value="clique olala" />
```
<label>Type submit</tabel>
<input type="submit" value="clique olala" />

```html
<label>Type hidden</tabel>
<input type="hidden" value="cheypas" /><label>Je suis caché...</label>
```
<label>Type hidden</tabel>
<input type="hidden" value="cheypas" /><label>Je suis caché...</label>

*Label pour un champ de saisie*
```html
<label for="it"> Écrit un truc là :
	<input type="text" id="it" size="12" />
</label>
```

<label for="it"> Écrit un truc là :
	<input type="text" id="it" size="12" />
</label>

>[!info] Remarque
>On peut regrouper un ensemble de champs de saisie avec `filedset` 

```html
<fieldset>
    <legend>Papiers SVP !</legend>
    <label for="nom">Ton nom : 
	    <input id="nom" type="text" size="12" />
	</label>
	<label for="prenom">Ton prénom : 
	    <input id="prenom" type="text" size="12" /></label>
    <label for="cb">Ton code CB : 
	    <input id="cb" type="text" size="12" />
	</label>
</fieldset>
```

<fieldset>
    <legend>Papiers SVP !</legend>
    <label for="nom">Ton nom : <input id="nom" type="text" size="12" /></label>
    <label for="prenom">Ton prénom : <input id="prenom" type="text" size="12" /></label>
    <label for="cb">Ton code CB : <input id="cb" type="text" size="12" /></label>
</fieldset>

**Les listes de choix**
```html
<select name="nomChoix" size="3" multiple="multiple">
  <option value="1">un</option>
  <option value="2">deux</option>
  <option value="3">trois</option>
  <option value="4">quatre</option>
</select>
```
<select name="nomChoix" size="3" multiple="multiple">
  <option value="1">un</option>
  <option value="2" selected="selected">deux</option>
  <option value="3">trois</option>
  <option value="4">quatre</option>
</select>

**Textarea**
```html
<textarea rows="3" cols="50">Zone de texte pour la saisie !</textarea>
```

<textarea rows="3" cols="50">Zone de texte pour la saisie !</textarea>

###### Gestion des champs textuels
```html
<form action="test.php" method="get">
  <p><b>Nom : </b>
  <input type="text" name="nom" size="10" /></p>
  <p><input type="submit" name="envoi"   
         value="Envoyer mon nom.." /></p>
</form>
```
<form action="test.php" method="get">
  <p><b>Nom : </b>
  <input type="text" name="nom" size="10" value="nem" /></p>
  <p><input type="submit" name="envoi"   
         value="Envoyer mon nom.." /></p>
</form>

Lorsqu'on clique sur le bouton,
- Redirection vers la page `test.php`
On peut récupérer le nom envoyé puis l'afficher

```php
// test.php -> pour traiter les informations envoyées par le formulaire
<?php
$nom = $_GET['nom']
echo "<p> $nom </p>"
?>
```
<p>Nom envoyé : nem</p>

###### Gestion des select
```html
<form action="test2.php" method="post">
<p>Ville : 
	<select size="3" name="ville">
        <option value="Amiens" > Amiens </option>
        <option value="Bordeaux" selected="selected" > Bordeaux</option>
        <option value="Caen"> Caen</option>
        <option value="Lille"> Lille</option>
    </select>
	<input type="submit" name="enregistrement" value="Envoyer" />  
	<input type="reset" name="annuler" value="Effacer" />
</p>
</form>
```

<form action="test2.php" method="post">
<p>Ville : 
	<select size="3" name="ville">
        <option value="Amiens" > Amiens </option>
        <option value="Bordeaux" selected="selected" > Bordeaux</option>
        <option value="Caen"> Caen</option>
        <option value="Lille"> Lille</option>
    </select>
	<input type="submit" name="enregistrement" value="Envoyer" />  
	<input type="reset" name="annuler" value="Effacer" />
</p>
</form>

```php
// test2.php -> Traiter les informations envoyées
<?php
echo('Ville : '.$_POST['ville']);
echo("<br />\n");
?>
```
<p>Ville : Bordeaux</p>
###### Gestion des checkbox
Lorsque l'o utilise une checkbox il peut arriver que l'on coche plusieurs cases ainsi, le résultat doit êtes stocké dans un tableau...
Ici le tableau c'est `cadeau[]`

```html
<form action="test3.php" method="get">
<p>Cadeaux : <br />
Livre  <input type="checkbox" name="cadeaux[]" 
                 value="livre" checked="checked" />   
Tee-shirt <input type="checkbox" name="cadeaux[]"    
                    value="tee-shirt" />
Sac <input type="checkbox" name="cadeaux[]" 
              value="sac" checked="checked" />
Sweat  <input type="checkbox" name="cadeaux[]" 
                 value="sweat" /></p>
<p><input type="submit" name="enregistrement" value="Envoyer" /></p>
</form>
```

<form action="test3.php" method="get">
<p>Cadeaux : <br />
Livre  <input type="checkbox" name="cadeaux[]" 
                 value="livre" checked="checked" />   
Tee-shirt <input type="checkbox" name="cadeaux[]"    
                    value="tee-shirt" />
Sac <input type="checkbox" name="cadeaux[]" 
              value="sac" checked="checked" />
Sweat  <input type="checkbox" name="cadeaux[]" 
                 value="sweat" /></p>
<p><input type="submit" name="enregistrement" value="Envoyer" /></p>
</form>

Dans ce cas il vas falloir **parcourir le tableau** pour afficher toutes les valeurs.

```php
// test3.php
<?php
// On récupère les cases cochées
$tab = $_GET['cadeaux'];
code = "<ul>";
foreach ($tab as $cadeau){
	code.= "<li> $cadeau </li>";
}
echo code.="</ul>";
?>
```
<ul>
	<li>Livre</li>
	<li>Sac</li>
</ul>

>[!warning]
>On peut aussi vouloir vérifier si le résultat du formulaire est bien un tableau !

```php
if(isset($tab) && is_array($tab)){
	// Le code du dessus là
}
```

>[!info]
>La récupération fonctionne <u>de la même manière</u> avec la sélection de choix multiple.

###### Gestion des zones textuelles
```html
<form action="test4.php" method="get">
	<label>  Écrit qqch là : </label><br/>
	<textarea rows="3" cols="50">Zone de texte pour la saisie !</textarea>
	<input type="submit" name="envoi"   value="Clic" />
</form>
```

<form action="test4.php" method="get">
	<label>  Écrit qqch là : </label><br/>
	<textarea rows="3" cols="50">Zone de texte pour la saisie !</textarea>
	<input type="submit" name="envoi"   value="Clic" />
</form>

On utilise `htmlentities(...)`
```php
// test4.php
<?php
echo('<p>');
echo(htmlentities($_GET['nom']));
echo("\n</p>");
?>
```
<p>Zone de texte pour la saisie !</p>

##### PHP et PostgreSQL
**Étapes générales à suivre**
1. Se connecter à la BDD
2. Récupérer un pointeur de connexion
3. Préparation et exécution de la requête
4. Vérification de l'exécution
5. Exploitation des résultats
6. Libération des ressources utilisées
7. Fermeture de la connexion

###### Connexion à la Base de données
On utilise `pg_connect(...)` pour se connecter à la base de donnée. On lui fournit en paramètre l'ensemble des informations de connexion.

```php
<?php
// Ficher connexion.php
// Toujours préférable de stocker ses identifiants mots passe dans un autre fichier extérieur php
$dbHost = "localhost";
$dbName = "maBase";
$dbUser = "toi";
$dbPassword = "****";
?>
```

```php
// Fichier qui test la connexion
<?php
$strconnex = "hot=$dbHost dbname=$dbName user=$dbUser password=$dbPassword";
$ptrdb = pg_connect($strconnex);

// Vérification de la co
if($ptrdb){
	echo "connexion réussie";
}
else{
	echo "raté, essai encore...";
}
?>
```

###### Exécuter une requête
On utilise `pg_query(...)`,  en suivant les étapes : 
1. Préparation de la requête
2. Exécution de la requête
```php
pg_query($pointeur, $requete);
```

###### Exploiter les résultats
- *Récupérer les lignes du résultat et positionne le curseur sur la ligne suivante*
  On accède aux données via `$tableau[$indice]`
```php
pg_fetch_row($pointeur, $numero_ligne);
```

```php
<?php
$pointeur = pg_connect($connex);
// Préparation de la requête
$requete = 'SELECT * FROM Table';

// Exécution de la requête
$ptrQuery = pg_query($pointeur, $requete);
$code = "";
if($ptrQuery){
	$numLigne = 0; // On commence à la première ligne
	// On lit tant qu'il reste qqch à lire
	while($ligne = pg_fetch_row($pointeur, $numLigne)){
		// Traitement à faire
		code .= "<p>";
		for($j=0; $j<count($ligne); $j++) code.="$ligne[j] ";
		$numLigne++;
		$code.="</p>\n";
	}
}
echo $code;
?>
```

- *Récupérer le résultat sous forme de tableau associatif*
  On accède aux données via `$tableau["nomColonne"]`
```php
pg_fetch_assoc($resultat) : array
```

```php
$ptrDB = pg_connect($strConnex);
if (!$ptrDB) { exit('pb de connection'); }
else {
  $requete = 'SELECT * FROM collectivite';
  $ptrQuery = pg_query($ptrDB,$requete);
  $blocHTML = "<div>\n";
  if ($ptrQuery) {
    while($ligne = pg_fetch_assoc($ptrQuery)) {
      $blocHTML .= '<p>';
      $blocHTML .= $ligne['col_code'].'; '
			      .$ligne['col_nom'].'; '
			      .$ligne['col_region'];
      $blocHTML .= "</p>\n";  // retour à la ligne lisibilité code html
    }
  }
  $blocHTML .= '</div>';
}
```

```html
<div>
<p>1; Ain; Rhône-Alpes</p>
<p>10; Aube; Champagne-Ardenne</p>
<p>11; Aude; Languedoc-Roussillon</p>
<p>12; Aveyron; Midi-Pyrénées</p>
<p>13; Bouches-du-Rhône; Provence-Alpes-Côte d'Azur</p>
<p>14; Calvados; Basse-Normandie</p>
<p>15; Cantal; Auvergne</p>
<p>16; Charente; Poitou-Charentes</p>
<p>17; Charente-Maritime; Poitou-Charentes</p>
...
</div>
```

<div>
<p>1; Ain; Rhône-Alpes</p>
<p>10; Aube; Champagne-Ardenne</p>
<p>11; Aude; Languedoc-Roussillon</p>
<p>12; Aveyron; Midi-Pyrénées</p>
<p>13; Bouches-du-Rhône; Provence-Alpes-Côte d'Azur</p>
<p>14; Calvados; Basse-Normandie</p>
<p>15; Cantal; Auvergne</p>
<p>16; Charente; Poitou-Charentes</p>
<p>17; Charente-Maritime; Poitou-Charentes</p>
...
</div>

- *Récupérer chaque ligne du résultat dans un tableau de différents objets*
  On accède aux valeurs via `$tableau[$ligne]` ou `$tableau["nomColonne"]`
```php
pg_fetch_array($pointeur);
```

```php
$ptrDB = pg_connect($strConnex);
if (!$ptrDB) { echo('pb de connection'); }
else {
  $requete = 'select * from collectivite';
  $ptrQuery = pg_query($ptrDB,$requete);
  if ($ptrQuery) {
    while($ligne = pg_fetch_array($ptrQuery)) {
      echo '<p>';
      echo $ligne['code'].' '.$ligne[1].' '.$ligne['region'];
      echo '</p>';
    }
  }
}
```

- *Récupérer tous les résultats dans un tableau*
```php
pg_fetch_all($resultat) : array
```

>[!info] Remarque
>On peut aussi récupérer le nombre de lignes et de colonnes :
>- `pg_num_rows($resultat)` nombre de lignes
>- `pg_num_fields($resultat)` nombre de colonnes

###### Traitement des erreurs
```php
pg_last_error($pointeur);
```

###### Libérer la mémoire
```php
pg_free_result($resultat) : bool
```

###### Fermer la connexion à la base de donnée
```php
pg_close($pointeur) : bool
```

###### Préparer et exécuter une requête
```php
pg_prepare($pointeur, "nomRequete", $requete) : resource
```

En fait la réalisation des requête où on a besoin de spécifier des paramètres (id par exemple) se fait en 2 temps
- On la prépare 
- On l'exécute en lui donnant les valeurs

**EXEMPLE**
*On souhaite récupérer les identifiants selon un nom et un prénom*
```php
$requete = 'SELECT * FROM Enseignant WHERE nom LIKE $1 OR prenom LIKE $2';

// Préparation de la requête
pg_prepare($ptrDB,'reqPrep1',$requete);

// Exécution
$ptrQuery = pg_execute($ptrDB, 'reqPrep1', array('Amanton', 'Laurent'));

// Exploitation des résultats...
```

```php
pg_execute($pointeur, "nomRequete", $tab);
```

>[!warning]
>Le nom de requête a utiliser est celui que vous avez donné à la requête lors de l'appel à `pg_prepare`.

##### Les sessions
>[!info] Remarque
>- La durée de vie d'une variable est **limitée à UNE SEULE URL**

- Démarrage d'une session `session_start()`
  **doit être appel avant tout affichage dans le navigateur**
```php
// Création d'une variable de session
$_SESSION['nomVariable'] = valeur;
```
- `isset(nomVar)` Vérifier si la variable existe
- `unset(nomVar)` détruire la variable
  ```php
  unset($_SESSION['nomVariable']);
	```
- fin de session `session_destroy()`
- effacer les variables de session `session_unset()`
- `session_id()` pour récupérer id de session

##### Cookies
>[!cite] Définition
>un ==**cookie**== est une information échangée entre le serveur HTTP et un navigateur.

*Exemple d'utilisation*
- Panier d'achat
- Session
- Pistage web
- ...

##### CRUD
>[!info] Remarque
>**CR**eate **U**pdate **D**elete

##### Complément heredoc / nowdoc
```php
$str = <<<TAG
Une chaîne de caractères
sur plusieurs lignes
avec une $variable interpolée.
TAG;
```
- On peut le faire avec `<<<HTML ... HTML;`

>[!warning]
>La syntaxe `<<<'TAG' ... TAG;` ne <mark class="orange">procède pas à l'interpolation</mark> de variable.

```php
$str = <<<'TAG'
Une chaîne de caractères
sur plusieurs lignes
sans $variable interpolée.
TAG;
```
*On le voit ici car `$variable` est restée en vert...*
