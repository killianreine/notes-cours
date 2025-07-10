Lors du cours n°2, nous avions parlé des types des variables en C, je fais surtout référence au type `char` qui représente un caractère [[02 - Premiers pas#Le type caractère]].  

>[!note] Rappel
>Le type `char` permet de stocker des caractères, et puisqu'ils sont stockés dans l'ordinateur sous forme d'entier, on peut alors aussi utiliser `char` pour stocker un entier.

Un problème se pose alors...  
Une variable de type `char` ne peut stocker **qu'un seul et unique caractère**, comment peut-on faire pour stocker des mots entiers ? Voire des phrases entières ?  
On cherche un moyen de stocker plusieurs lettre dans un même objet. Justement, on sait déjà le faire, par le biais des **==tableaux==**.

Il y a toujours un problème, une chaîne de caractères est plus qu'un tableau, elle doit être manipulable directement, hors ceci n'est possible **que si on connait sa taille**.

# Déclaration
Ici, rien ne change vraiment de déclaration d'un tableau :

```c
char chaine[t]="...";
```
Où 
- `t` représente la taille de la chaîne de caractères.
- `"..."` la chaîne de caractère que l'on stocke

<u>Exemple :</u>  
On souhaite stocké le mot `informatique` dans une chaine de caractères nommée `domaine`, on va alors créer un tableau de caractères et stocker le mot.
```c
char domaine = "informatique";
```

Voici d'une manière simplifiée, comment le mot est stocké.
<svg width="900" height="100" xmlns="http://www.w3.org/2000/svg">
  <style>
    .char-box { fill: #f0f8ff; stroke: #4682b4; stroke-width: 1; }
    .char-text { font-family: monospace; font-size: 16px; fill: #000; }
    .addr-text { font-family: monospace; font-size: 12px; fill: #555; }
  </style>

  <!-- Boxes for each character -->
  <g>
    <!-- Characters and addresses -->
    <!-- Total: 13 characters + null terminator -->
    <!-- "informatique" has 12 letters, we add '\0' at the end -->
    <!-- Each box is 60px wide -->
    <!-- Loop simulation -->
    <!-- i n f o r m a t i q u e \0 -->
    <!-- Addresses: for example, 0x1000 + i*60 -->
    <!-- Draw boxes and text -->
    <!-- Use <g> for grouping -->
    <!-- Use fixed spacing -->

    <!-- Character Boxes -->
    <!-- We'll simulate address labels below boxes -->

    <!-- Box 0 -->
    <rect x="10" y="20" width="60" height="50" class="char-box"/>
    <text x="35" y="50" class="char-text" text-anchor="middle">i</text>
    <text x="35" y="85" class="addr-text" text-anchor="middle">0x1000</text>

    <!-- Box 1 -->
    <rect x="70" y="20" width="60" height="50" class="char-box"/>
    <text x="95" y="50" class="char-text" text-anchor="middle">n</text>
    <text x="95" y="85" class="addr-text" text-anchor="middle">0x1001</text>

    <!-- Box 2 -->
    <rect x="130" y="20" width="60" height="50" class="char-box"/>
    <text x="155" y="50" class="char-text" text-anchor="middle">f</text>
    <text x="155" y="85" class="addr-text" text-anchor="middle">0x1002</text>

    <!-- Box 3 -->
    <rect x="190" y="20" width="60" height="50" class="char-box"/>
    <text x="215" y="50" class="char-text" text-anchor="middle">o</text>
    <text x="215" y="85" class="addr-text" text-anchor="middle">0x1003</text>

    <!-- Box 4 -->
    <rect x="250" y="20" width="60" height="50" class="char-box"/>
    <text x="275" y="50" class="char-text" text-anchor="middle">r</text>
    <text x="275" y="85" class="addr-text" text-anchor="middle">0x1004</text>

    <!-- Box 5 -->
    <rect x="310" y="20" width="60" height="50" class="char-box"/>
    <text x="335" y="50" class="char-text" text-anchor="middle">m</text>
    <text x="335" y="85" class="addr-text" text-anchor="middle">0x1005</text>

    <!-- Box 6 -->
    <rect x="370" y="20" width="60" height="50" class="char-box"/>
    <text x="395" y="50" class="char-text" text-anchor="middle">a</text>
    <text x="395" y="85" class="addr-text" text-anchor="middle">0x1006</text>

    <!-- Box 7 -->
    <rect x="430" y="20" width="60" height="50" class="char-box"/>
    <text x="455" y="50" class="char-text" text-anchor="middle">t</text>
    <text x="455" y="85" class="addr-text" text-anchor="middle">0x1007</text>

    <!-- Box 8 -->
    <rect x="490" y="20" width="60" height="50" class="char-box"/>
    <text x="515" y="50" class="char-text" text-anchor="middle">i</text>
    <text x="515" y="85" class="addr-text" text-anchor="middle">0x1008</text>

    <!-- Box 9 -->
    <rect x="550" y="20" width="60" height="50" class="char-box"/>
    <text x="575" y="50" class="char-text" text-anchor="middle">q</text>
    <text x="575" y="85" class="addr-text" text-anchor="middle">0x1009</text>

    <!-- Box 10 -->
    <rect x="610" y="20" width="60" height="50" class="char-box"/>
    <text x="635" y="50" class="char-text" text-anchor="middle">u</text>
    <text x="635" y="85" class="addr-text" text-anchor="middle">0x100A</text>

    <!-- Box 11 -->
    <rect x="670" y="20" width="60" height="50" class="char-box"/>
    <text x="695" y="50" class="char-text" text-anchor="middle">e</text>
    <text x="695" y="85" class="addr-text" text-anchor="middle">0x100B</text>

    <!-- Box 12 -->
    <rect x="730" y="20" width="60" height="50" class="char-box" fill="#e0e0e0" stroke="#a0a0a0"/>
    <text x="755" y="50" class="char-text" text-anchor="middle">\0</text>
    <text x="755" y="85" class="addr-text" text-anchor="middle">0x100C</text>

  </g>
</svg>
