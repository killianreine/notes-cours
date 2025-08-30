# Introduction
## Qu'est-ce qu'un fichier en informatique
Un **==fichier==** est une unité de stockage d'informations sur un support *(clé USB, disque dur, SSD, ...)*. Un fichier peut contenir plusieurs types de données : 
- **fichier texte**, lisible par un humain (comme les fichiers `.txt`)
- **fichiers binaires**, données codées, lisible par un programme (comme i, fichier `.exe` ou une image `.jpg`)

En langage C, on distingue donc deux formes de fichiers :
1. Les fichiers textes  
   Ils sont constitués de caractères, terminés par un caractère de fin de ligne `\n` en linux, `\r\n` sur Windows.
2. Les fichiers binaires  
   Les données sont enregistrées sous leur forme brute *(= non transformée en caractères)*

## Pourquoi utiliser des fichiers
Jusqu'à maintenant et comme expliqué dans le cours [[09 - Allocation dynamique]] lorsque vous écrivez un programme en C, les données comme les tableaux, les variables, les structures sont stockées dans la **mémoire vive** *(RAM)* et elle disparaissent dès que le programme se termine.  
Les fichiers permettraient alors de 
- **sauvegarder des données** avant la fin du programme pour pouvoir les réutiliser plus tard sans qu'elles ne soient détruite à la fin du programme.
- **échanger des informations** entre différents programmes
- **stocker de grande quantités de données** qui ne peuvent pas toujours être gardées en mémoire.

<u>Exemple :</u>  
- Un éditeur de texte sauvegarde votre saisie dans un fichier `.txt`. 
- Une application de gestion sauvegarde vos données dans un fichier `.dat` ou `.csv`.

## Types d'accès aux fichiers
Avant de commencer à manipuler des fichiers, faut-il déjà savoir comprendre comment on peut y accéder...
- **Accès séquentiel**  
  On lit/écrit les données les unes après les autres dans l'ordre. On peut voir ceci comme lire un roman page par page. Ce genre d'accès est très utile pour les fichiers texte.
- **Accès direct (ou aléatoire)**  
  On peut accéder à une position donnée dans le fichier. Bien plus utile pour les fichiers binaires. Par exemple ouvrir une vidéo et avancer à une certaine durée.

## Les fichiers et le système d'exploitation
Le système d'exploitation gère les fichiers grâce aux informations suivantes :
- Le **nom** du fichier
- Le **chemin** d'accès du fichier
- Le **type** de fichier *(texte, binaire, exécutable, ...)*
- Les **droits d'accès** *(lecture, écriture, exécution)*

>[!info] Remarque
>En langage C, pour travailler avec un fichier, on ne passe pas directement par son nom. On utilise ce qu'on appelle un **==pointeur de fichier==** qui permet de faire le lien entre le programme C et le fichier fourni par le système d'exploitation.

## Cycle de vie d'un fichier en C
Lorsqu’on veut utiliser un fichier, il y a plusieurs étapes **logiques** à suivre :
1. **Ouverture du fichier** : le programme demande au système d’exploitation de préparer le fichier pour lecture/écriture.
2. **Traitement du fichier** : lecture ou écriture des données.
3. **Fermeture du fichier** : libération des ressources et sauvegarde correcte.

<div class="card">
  <svg viewBox="0 0 1000 940" role="img" aria-labelledby="title desc">
  <title id="title">Diagramme : cycle de vie d'un fichier</title>
  <desc id="desc">Du début du programme à la fermeture du fichier, avec décisions d'erreur et boucle de traitement.</desc>
  <defs>
    <marker id="arrow" markerWidth="10" markerHeight="10" refX="8" refY="5" orient="auto" markerUnits="strokeWidth">
      <path d="M0,0 L10,5 L0,10 z" fill="currentColor"/>
    </marker>
  </defs>
  <!-- Start -->
  <g class="nodeCycle" transform="translate(460,40)">
    <rect class="terminatorCycle" width="280" height="70" rx="35"/>
    <text class="textCycle" x="140" y="42" text-anchor="middle">Début du programme</text>
  </g>
  <!-- Ask open -->
  <g class="nodeCycle" transform="translate(440,140)">
    <rect class="boxCycle" width="320" height="90"/>
    <text class="titleCycle" x="160" y="32" text-anchor="middle">Demander l'ouverture du fichier</text>
    <text class="textCycle" x="160" y="58" text-anchor="middle">Choisir chemin, mode, droits</text>
  </g>
  <!-- Decision open -->
  <g class="nodeCycle" transform="translate(480,270)">
    <polygon class="decisionCycle" points="160,0 320,70 160,140 0,70"/>
    <text class="titleCycle" x="160" y="60" text-anchor="middle">Ouverture réussie ?</text>
    <text class="textCycle" x="160" y="84" text-anchor="middle">(fichier, permissions, etc.)</text>
  </g>
  <!-- Error handling -->
  <g class="nodeCycle" transform="translate(120,420)">
    <rect class="dangerCycle" width="300" height="110"/>
    <text class="titleCycle" x="150" y="30" text-anchor="middle">Gérer l'échec d'ouverture</text>
    <text class="textCycle" x="150" y="54" text-anchor="middle">Vérifier chemin/droits,</text>
    <text class="textCycle" x="150" y="74" text-anchor="middle">créer le fichier si besoin,</text>
    <text class="textCycle" x="150" y="94" text-anchor="middle">afficher un message</text>
  </g>
  <!-- Processing -->
  <g class="nodeCycle" transform="translate(780,420)">
    <rect class="boxCycle" width="300" height="110"/>
    <text class="titleCycle" x="150" y="30" text-anchor="middle">Traiter le fichier</text>
    <text class="textCycle" x="150" y="54" text-anchor="middle">Lire / Écrire / Mettre à jour</text>
    <text class="textCycle" x="150" y="74" text-anchor="middle">Accès séquentiel ou direct</text>
    <text class="textCycle" x="150" y="94" text-anchor="middle">Gestion des erreurs I/O</text>
  </g>
  <!-- Continue decision -->
  <g class="nodeCycle" transform="translate(780,570)">
    <polygon class="decisionCycle" points="150,0 300,70 150,140 0,70"/>
    <text class="titleCycle" x="150" y="60" text-anchor="middle">Fin du traitement ?</text>
    <text class="textCycle" x="150" y="84" text-anchor="middle">(données épuisées / action finie)</text>
  </g>
  <!-- Close -->
  <g class="nodeCycle" transform="translate(460,720)">
    <rect class="boxCycle" width="280" height="80"/>
    <text class="titleCycle" x="140" y="34" text-anchor="middle">Fermer le fichier</text>
    <text class="textCycle" x="140" y="58" text-anchor="middle">Libérer les ressources</text>
  </g>
  <!-- End -->
  <g class="nodeCycle" transform="translate(460,820)">
    <rect class="terminatorCycle" width="280" height="70" rx="35"/>
    <text class="textCycle" x="140" y="42" text-anchor="middle">Fin du programme</text>
  </g>
  <!-- Legend -->
  <g class="legendCycle" transform="translate(20,20)">
    <rect class="legendBoxCycle" x="0" y="0" width="360" height="120" rx="12"/>
    <text class="titleCycle" x="16" y="24">Légende</text>
    <g transform="translate(16,40)">
      <rect class="boxCycle" width="24" height="16" rx="4"/>
      <text class="textCycle" x="34" y="13">Étape de traitement</text>
    </g>
    <g transform="translate(16,64)">
      <rect class="terminatorCycle" width="24" height="16" rx="8"/>
      <text class="textCycle" x="34" y="13">Début/Fin</text>
    </g>
    <g transform="translate(16,88)">
      <polygon class="decisionCycle" points="0,8 12,16 24,8 12,0"/>
      <text class="textCycle" x="34" y="13">Point de décision</text>
    </g>
    <g transform="translate(200,40)">
      <rect class="dangerCycle" width="24" height="16" rx="4"/>
      <text class="textCycle" x="34" y="13">Gestion d'erreur</text>
    </g>
  </g>
  <!-- Main flow arrows -->
  <path class="arrowCycle" d="M600,110 L600,140" marker-end="url(#arrow)"/>
  <path class="arrowCycle" d="M600,230 L600,270" marker-end="url(#arrow)"/>
  <!-- Error path -->
  <path class="arrowCycle errorCycle" d="M480,340 L270,340 L270,420" marker-end="url(#arrow)"/>
  <text class="textCycle" x="370" y="332" font-size="14" text-anchor="middle">Non</text>
  <!-- Success path -->
  <path class="arrowCycle okCycle" d="M800,340 L930,340 L930,420" marker-end="url(#arrow)"/>
  <text class="textCycle" x="865" y="332" font-size="14" text-anchor="middle">Oui</text>
  <!-- Retry loop -->
  <path class="arrowCycle warnCycle" d="M270,420 L270,380 L80,380 L80,185 L440,185" marker-end="url(#arrow)"/>
  <text class="textCycle" x="175" y="372" font-size="12">Corriger et réessayer</text>
  <!-- Processing to decision -->
  <path class="arrowCycle" d="M930,530 L930,570" marker-end="url(#arrow)"/>
  <!-- End processing -->
  <path class="arrowCycle" d="M780,640 L600,640 L600,720" marker-end="url(#arrow)"/>
  <text class="textCycle" x="690" y="632" font-size="14" text-anchor="middle">Oui, terminé</text>
  <!-- Continue processing loop -->
  <path class="arrowCycle" d="M1080,640 L1150,640 L1150,475 L1080,475" marker-end="url(#arrow)"/>
  <text class="textCycle" x="1120" y="632" font-size="14" text-anchor="middle">Non, continuer</text>
  <!-- Final arrow -->
  <path class="arrowCycle" d="M600,800 L600,820" marker-end="url(#arrow)"/>
</svg>
</div>

