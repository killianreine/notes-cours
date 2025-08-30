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
  <svg viewBox="0 0 1200 940" role="img" aria-labelledby="title desc">
    <title id="title">Diagramme : cycle de vie d’un fichier</title>
    <desc id="desc">Du début du programme à la fermeture du fichier, avec décisions d’erreur et boucle de traitement.</desc>
    <defs>
      <marker id="arrow" markerWidth="10" markerHeight="10" refX="8" refY="5" orient="auto" markerUnits="strokeWidth">
        <path d="M0,0 L10,5 L0,10 z" fill="currentColor"></path>
      </marker>
    </defs>
    <!-- Start -->
    <g class="nodeCycle" transform="translate(460,40)">
      <rect class="terminatorCycle" width="280" height="70" rx="35"></rect>
      <text class="textCycle" x="140" y="42" text-anchor="middle">Début du programme</text>
    </g>
    <!-- Ask open -->
    <g class="nodeCycle" transform="translate(440,140)">
      <rect class="boxCycle" width="320" height="90"></rect>
      <text class="titleCycle" x="160" y="28" text-anchor="middle">Demander l’ouverture du fichier</text>
      <text class="textCycle" x="160" y="54" text-anchor="middle">Choisir chemin, mode, droits</text>
    </g>
    <!-- Decision open -->
    <g class="nodeCycle" transform="translate(480,270)">
      <polygon class="decisionCycle" points="160,0 320,70 160,140 0,70"></polygon>
      <text class="titleCycle" x="160" y="56" text-anchor="middle">Ouverture réussie ?</text>
      <text class="textCycle" x="160" y="82" text-anchor="middle">(fichier, permissions, etc.)</text>
    </g>
    <!-- Error -->
    <g class="nodeCycle" transform="translate(120,420)">
      <rect class="dangerCycle" width="300" height="110"></rect>
      <text class="titleCycle" x="150" y="28" text-anchor="middle">Gérer l’échec d’ouverture</text>
      <text class="textCycle" x="150" y="54" text-anchor="middle">Vérifier chemin/droits,</text>
      <text class="textCycle" x="150" y="74" text-anchor="middle">créer le fichier si besoin,</text>
      <text class="textCycle" x="150" y="94" text-anchor="middle">afficher un message</text>
    </g>
    <!-- Processing -->
    <g class="nodeCycle" transform="translate(780,420)">
      <rect class="boxCycle" width="300" height="110"></rect>
      <text class="titleCycle" x="150" y="28" text-anchor="middle">Traiter le fichier</text>
      <text class="textCycle" x="150" y="54" text-anchor="middle">Lire / Écrire / Mettre à jour</text>
      <text class="textCycle" x="150" y="74" text-anchor="middle">Accès séquentiel ou direct</text>
    </g>
    <!-- Continue decision -->
    <g class="nodeCycle" transform="translate(780,570)">
      <polygon class="decisionCycle" points="150,0 300,70 150,140 0,70"></polygon>
      <text class="titleCycle" x="150" y="56" text-anchor="middle">Fin du traitement ?</text>
      <text class="textCycle" x="150" y="82" text-anchor="middle">(données épuisées / action finie)</text>
    </g>
    <!-- Close -->
    <g class="nodeCycle" transform="translate(460,720)">
      <rect class="boxCycle" width="280" height="80"></rect>
      <text class="titleCycle" x="140" y="32" text-anchor="middle">Fermer le fichier</text>
      <text class="textCycle" x="140" y="56" text-anchor="middle">Libérer les ressources</text>
    </g>
    <!-- End -->
    <g class="nodeCycle" transform="translate(460,820)">
      <rect class="terminatorCycle" width="280" height="70" rx="35"></rect>
      <text class="textCycle" x="140" y="42" text-anchor="middle">Fin du programme</text>
    </g>
    <!-- Legend -->
    <g class="legendCycle" transform="translate(20,20)">
      <rect class="legendBoxCycle" x="0" y="0" width="320" height="96" rx="12"></rect>
      <text class="titleCycle" x="16" y="22">Légende</text>
      <g transform="translate(16,36)">
        <rect class="boxCycle" width="22" height="14" rx="4"></rect>
        <text class="textCycle" x="32" y="12">Étape</text>
      </g>
      <g transform="translate(100,36)">
        <rect class="terminatorCycle" width="22" height="14" rx="7"></rect>
        <text class="textCycle" x="32" y="12">Début/Fin</text>
      </g>
      <g transform="translate(206,36)">
        <polygon class="decisionCycle" points="0,7 11,14 22,7 11,0"></polygon>
        <text class="textCycle" x="32" y="12">Décision</text>
      </g>
    </g>
    <!-- Connectors -->
    <path class="arrowCycle" d="M600,110 V140" />
    <path class="arrowCycle" d="M600,230 V270" />
    <path class="arrowCycle errorCycle" d="M480,340 H270 V420" />
    <text class="textCycle" x="360" y="332" font-size="12" text-anchor="middle">Non</text>
    <path class="arrowCycle okCycle" d="M800,340 V420" />
    <text class="textCycle" x="740" y="332" font-size="12">Oui</text>
    <path class="arrowCycle warnCycle" d="M270,530 V600 H600 V230" />
    <text class="textCycle" x="292" y="548" font-size="12">Corriger et réessayer</text>
    <path class="arrowCycle" d="M930,530 V570" />
    <path class="arrowCycle" d="M780,640 H600 V720" />
    <text class="textCycle" x="764" y="632" font-size="12">Oui, terminé</text>
    <path class="arrowCycle" d="M1080,640 H1140 V420 H930" />
    <text class="textCycle" x="1090" y="632" font-size="12">Non, continuer</text>
    <path class="arrowCycle" d="M600,800 V820" />
  </svg>
</div>

