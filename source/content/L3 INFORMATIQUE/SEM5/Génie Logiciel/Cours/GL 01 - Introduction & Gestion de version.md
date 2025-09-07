# Introduction au module GL
Le **génie logiciel** (_software engineering_ en anglais) est une discipline de l’informatique qui s’intéresse à la **conception, au développement, à la maintenance et à la gestion des logiciels** de manière systématique, structurée et efficace.  
Le développement de logiciels demande du temps, est difficile et couteux. Le génie logiciel peut être vu comme un ensemble de méthodes/outils permettant de rendre le développement plus efficace et plus rapide.

On peut citer quelques composantes liées au génie logiciel GL :
- **Méthodes de structuration de code :** code Smells, design pattern, ...
- **Outils de développement :** IDE, Construction de code, Gestion de version, ...
- **Aide à la mise en œuvre de qualité :** Outils de tests, contrôles sur le code
- **Gestion de projet :** Gantt, Cocomo, ...

# Gestion de version
## Introduction
### C'est quoi la gestion de version ?
La **==gestion de version==** est une manière d'organiser et de suivre l'évolution d'un travail au fil du temps. Elle permet de garder un historique de toutes les modifications apportées à un projet *(fichiers, documents, code, ...)*. C'est un peu comme une mémoire de son développement. 

### Pourquoi ce serait utile ?
La gestion de version est utile pour de nombreuses raisons, elle permet de garder un historique de tout ce qu'on a fait dans notre projet comme modifications, de permettre de savoir quand elles ont été faites et pourquoi. Il peut aussi arriver qu'il y ai une erreur sur une des version, l'outil de gestion de projet permet alors de **retourner en arrière** et reprenant une version précédente. L'outil de gestion de version permet aussi de travailler à plusieurs sur les mêmes fichiers en parallèle.

La gestion de version, c’est :
- **mémoriser** chaque étape d’un projet,
- **comparer** les différentes versions,
- **revenir** en arrière si besoin,
- **collaborer** plus facilement.
C’est une discipline qui devient essentielle dès qu’on travaille sur des projets un peu complexes, surtout en équipe.

## Gestion de version mono-document

>[!cite] Définition
>On appelle **==gestion de version mono-document==** le fait de garder l'historique des modifications appliquées à **un seul document**.

Ce dernier permet une explication de chaque version, un retour en arrière et un identificateur de version. 

$\boxed{\text{Conflit de versions parallèles}}$  
On considère deux développeurs $Dev_a$ et $Dev_b$ qui travaillent sur un fichier qui est dans une certaine version. Dans notre exemple nous considérerons que le fichier est en version `v2.0`.
- Le développeur $Dev_a$ récupère le fichier dans le dépôt.
- Le développeur $Dev_b$ récupère le fichier dans le dépôt.
Ainsi, les deux développeurs travaillent **en parallèle** sur la même version d'un même fichier.
- Le développeur $Dev_a$ finit de modifier le fichier, ce dernier le dépose dans le dépôt. La nouvelles version du fichier est donc notée $v3.a$.
- Le développeur $Dev_b$ a lui aussi terminé, il dépose son fichier et ce dernier passe donc en version $v3.b$.
Le problème c'est que en déposant sa nouvelle version, le développeur $Dev_b$ a écrasé les modifications du développeur $Dev_a$. Ceci créé donc un conflit de version.

<div>
<div class="bodyMOno">
  <div class="containerMOno" role="figure" aria-label="Schéma montrant un conflit de version mono‑document entre deux développeurs">
    <div class="headerMOno">
      <p class="descriptionMOno">Illustration d'un scénario classique : deux développeurs (<strong>Dev_a</strong> et <strong>Dev_b</strong>) partent de la même version <code>v2.0</code> et travaillent en parallèle.</p>
    </div>
    <div class="legendMOno">
      <div class="legend-itemMOno">
        <div class="legend-dotMOno repo"></div>
        <span>Dépôt central</span>
      </div>
      <div class="legend-itemMOno">
        <div class="legend-dotMOno devA"></div>
        <span>Développeur A</span>
      </div>
      <div class="legend-itemMOno">
        <div class="legend-dotMOno devB"></div>
        <span>Développeur B</span>
      </div>
      <div class="legend-itemMOno">
        <div class="legend-dotMOno danger"></div>
        <span>Conflit / Écrasement</span>
      </div>
    </div>
    <div class="diagram-containerMOno">
      <svg class="svgMOno" viewBox="0 0 1150 580" role="img" aria-labelledby="diagram-title diagram-desc">
        <title id="diagram-titleMOno">Diagramme de conflit de versioning mono-document</title>
        <desc id="diagram-descMOno">Timeline montrant comment deux développeurs travaillant en parallèle sur v2.0 créent un conflit quand Dev_b écrase les modifications de Dev_a</desc>
        <defs>
          <!-- Gradient backgrounds -->
          <linearGradient id="repoGradMOno" x1="0%" y1="0%" x2="100%" y2="100%">
            <stop offset="0%" style="stop-color:#6366f1;stop-opacity:1" />
            <stop offset="100%" style="stop-color:#8b5cf6;stop-opacity:1" />
          </linearGradient>
          <linearGradient id="devAGradMOno" x1="0%" y1="0%" x2="100%" y2="100%">
            <stop offset="0%" style="stop-color:#10b981;stop-opacity:0.9" />
            <stop offset="100%" style="stop-color:#059669;stop-opacity:0.9" />
          </linearGradient>
          <linearGradient id="devBGradMOno" x1="0%" y1="0%" x2="100%" y2="100%">
            <stop offset="0%" style="stop-color:#f59e0b;stop-opacity:0.9" />
            <stop offset="100%" style="stop-color:#d97706;stop-opacity:0.9" />
          </linearGradient>
          <!-- Arrow markers -->
          <marker id="arrowRepoMOno" viewBox="0 0 12 12" refX="11" refY="6" markerWidth="10" markerHeight="10" orient="auto">
            <path d="M 0 0 L 12 6 L 0 12 Z" fill="url(#repoGradMOno)"/>
          </marker>
          <marker id="arrowAMOno" viewBox="0 0 12 12" refX="11" refY="6" markerWidth="10" markerHeight="10" orient="auto">
            <path d="M 0 0 L 12 6 L 0 12 Z" fill="url(#devAGradMOno)"/>
          </marker>
          <marker id="arrowBMOno" viewBox="0 0 12 12" refX="11" refY="6" markerWidth="10" markerHeight="10" orient="auto">
            <path d="M 0 0 L 12 6 L 0 12 Z" fill="url(#devBGradMOno)"/>
          </marker>
          <!-- Glow effects -->
          <filter id="glowMOno" x="-50%" y="-50%" width="200%" height="200%">
            <feGaussianBlur stdDeviation="4" result="coloredBlur"/>
            <feMerge>
              <feMergeNode in="coloredBlur"/>
              <feMergeNode in="SourceGraphic"/>
            </feMerge>
          </filter>
          <filter id="dangerGlowMOno" x="-50%" y="-50%" width="200%" height="200%">
            <feGaussianBlur stdDeviation="6" result="coloredBlur"/>
            <feMerge>
              <feMergeNode in="coloredBlur"/>
              <feMergeNode in="SourceGraphic"/>
            </feMerge>
          </filter>
          <!-- Warning icon -->
          <symbol id="warningMOno" viewBox="0 0 24 24">
            <path d="M12 2L2 22h20L12 2zm0 6l6 10H6l6-10zm0 2l-3 6h6l-3-6z" fill="#ef4444"/>
          </symbol>
          <!-- Grid background -->
          <pattern id="gridMOno" width="40" height="40" patternUnits="userSpaceOnUse">
            <path d="M 40 0 L 0 0 0 40" fill="none" stroke="rgba(255,255,255,0.03)" stroke-width="1"/>
          </pattern>
        </defs>
        <rect width="100%" height="100%" fill="url(#gridMOno)" />
        <!-- Timeline axis -->
        <g>
          <line x1="100" y1="100" x2="1050" y2="100" stroke="url(#repoGradMOno)" stroke-width="4" marker-end="url(#arrowRepoMOno)" filter="url(#glowMOno)"/>
        </g>
        <!-- Lane labels -->
        <g class="lane-labelsMOno" font-size="16" font-weight="600" fill="var(--text)">
          <text x="50" y="95">Dépôt</text>
          <text x="50" y="255">Dev A</text>
          <text x="50" y="415">Dev B</text>
        </g>
        <!-- Initial state: v2.0 in repo -->
        <g class="repo-initialMOno" transform="translate(150,60)">
          <rect x="0" y="0" rx="15" ry="15" width="160" height="60" fill="url(#repoGradMOno)" filter="url(#glowMOno)"/>
          <text x="80" y="25" text-anchor="middle" font-size="16" font-weight="600" fill="white">Dépôt Central</text>
          <text x="80" y="45" text-anchor="middle" font-size="14" fill="#e2e8f0">Version 2.0</text>
        </g>
        <!-- Dev A local work -->
        <g class="dev-a-localMOno" transform="translate(180,215)">
          <rect x="0" y="0" rx="12" ry="12" width="140" height="65" fill="rgba(16,185,129,0.15)" stroke="var(--devA)" stroke-width="2"/>
          <text x="70" y="25" text-anchor="middle" font-size="14" font-weight="600" fill="var(--devA)">Dev A (local)</text>
          <text x="70" y="45" text-anchor="middle" font-size="13" fill="var(--muted)">v2.0 → modifications</text>
        </g>
        <!-- Dev B local work -->
        <g class="dev-b-localMOno" transform="translate(180,375)">
          <rect x="0" y="0" rx="12" ry="12" width="140" height="65" fill="rgba(245,158,11,0.15)" stroke="var(--devB)" stroke-width="2"/>
          <text x="70" y="25" text-anchor="middle" font-size="14" font-weight="600" fill="var(--devB)">Dev B (local)</text>
          <text x="70" y="45" text-anchor="middle" font-size="13" fill="var(--muted)">v2.0 → modifications</text>
        </g>
        <!-- Dev A publishes first -->
        <path class="path-aMOno" d="M 320 245 Q 400 200 480 120" fill="none" stroke="url(#devAGradMOno)" stroke-width="5" marker-end="url(#arrowAMOno)" filter="url(#glowMOno)"/>
        <g class="repo-v3aMOno" transform="translate(460,60)">
          <rect x="0" y="0" rx="15" ry="15" width="160" height="60" fill="url(#devAGradMOno)" filter="url(#glowMOno)"/>
          <text x="80" y="25" text-anchor="middle" font-size="16" font-weight="600" fill="white">Dépôt Central</text>
          <text x="80" y="45" text-anchor="middle" font-size="14" fill="#e2e8f0">Version 3.a</text>
        </g>
        <!-- Dev B publishes later (overwrites) -->
        <path class="path-bMOno" d="M 320 405 Q 480 350 700 120" fill="none" stroke="url(#devBGradMOno)" stroke-width="5" marker-end="url(#arrowBMOno)" filter="url(#glowMOno)"/>
        <g class="repo-v3bMOno" transform="translate(900,50)">
          <rect x="0" y="0" rx="15" ry="15" width="160" height="80" fill="var(--danger)" filter="url(#dangerGlowMOno)"/>
          <text x="80" y="28" text-anchor="middle" font-size="16" font-weight="600" fill="white">Dépôt Central</text>
          <text x="80" y="50" text-anchor="middle" font-size="14" fill="#fecaca">Version 3.b</text>
          <text x="80" y="68" text-anchor="middle" font-size="12" fill="#fca5a5">(v3.a écrasée!)</text>
        </g>
        <!-- Conflict warning -->
        <g class="conflict-warningMOno" transform="translate(650,65)">
          <rect x="0" y="0" rx="10" ry="10" width="220" height="50" fill="rgba(239,68,68,0.2)" stroke="var(--danger)" stroke-width="2"/>
          <use href="#warningMOno" x="10" y="15" width="20" height="20"/>
          <text x="35" y="20" font-size="14" font-weight="700" fill="var(--danger)">CONFLIT DÉTECTÉ</text>
          <text x="35" y="35" font-size="12" fill="var(--muted)">Écrasement des modifications</text>
        </g>
        <!-- Timeline annotations -->
        <g class="timeline-annotationsMOno" font-size="14" fill="var(--muted)">
          <!-- Time markers -->
          <line x1="230" y1="140" x2="230" y2="145" stroke="var(--muted)" stroke-width="2"/>
          <text x="230" y="160" text-anchor="middle" font-weight="500">T1</text>
          <text x="230" y="175" text-anchor="middle" font-size="12">Récupération</text>
          <line x1="540" y1="140" x2="540" y2="145" stroke="var(--muted)" stroke-width="2"/>
          <text x="540" y="160" text-anchor="middle" font-weight="500">T2</text>
          <text x="540" y="175" text-anchor="middle" font-size="12">Push Dev A</text>
          <line x1="780" y1="140" x2="780" y2="145" stroke="var(--muted)" stroke-width="2"/>
          <text x="780" y="160" text-anchor="middle" font-weight="500">T3</text>
          <text x="780" y="175" text-anchor="middle" font-size="12">Push Dev B</text>
        </g>
        <!-- Parallel work indication -->
        <g class="parallel-workMOno" stroke-dasharray="8 4" stroke="rgba(255,255,255,0.3)" stroke-width="2">
          <line x1="180" y1="195" x2="450" y2="195"/>
          <line x1="180" y1="355" x2="650" y2="355"/>
        </g>
        <text class="parallel-textMOno" x="415" y="320" text-anchor="middle" font-size="16" font-weight="600" fill="var(--accent)">Travail en parallèle</text>
        <!-- Problem explanation -->
        <g class="problem-explanationMOno" transform="translate(100,480)">
          <rect x="0" y="0" rx="12" ry="12" width="950" height="80" fill="rgba(239,68,68,0.1)" stroke="var(--danger)" stroke-width="1"/>
          <text x="20" y="25" font-size="16" font-weight="700" fill="var(--danger)">Problème :</text>
          <text x="20" y="45" font-size="14" fill="var(--text)">• Dev B n'était pas au courant des modifications de Dev A (v3.a)</text>
          <text x="20" y="62" font-size="14" fill="var(--text)">• Sa publication (v3.b) écrase complètement le travail de Dev A</text>
        </g>
      </svg>
    </div>
  </div>
</div>
</div>
