# Généralités sur les variables

>[!cite] Définition
>- Une **==variable==** permet de stocker une donnée. Elle possède un **nom** qui permet de l'identifier et un **type** qui permet de savoir ce que l'on a stocker : nombre, caractère, ...
>- Une **==donnée==** est une information que l'on range dans une variable. 

<section class="panel">
    <div class="panel__title">Déclarer une variable</div>
    <div class="panel__body">
      <p>En JavaScript, il est possible de déclarer des variables de plusieurs manières différentes.</p>

      <ul>
        <li><span class="subhead">Variable statique</span></li>
      </ul>

      <pre class="code"><code><span class="kw">const</span> nomVariable = valeur ;</code></pre>

      <p>Une variable déclarée avec le mot clé <code class="kw">const</code> est non-mutable,
      c’est-à-dire qu’elle ne peut pas changer de valeur.</p>

      <ul>
        <li><span class="subhead">Variable dynamique</span></li>
      </ul>

      <pre class="code"><code><span class="kw">let</span> nomVariable = valeur ;</code></pre>

      <p>Une variable déclarée avec le mot clé <code class="kw">let</code> est mutable,
      on peut donc la changer.</p>

      <p>Si vous souhaitez afficher des résultats dans la console, il suffit d’utiliser :</p>

      <pre class="code"><code><span class="fn">console</span>.log(nomVariable) ;</code></pre>
    </div>
  </section>
  