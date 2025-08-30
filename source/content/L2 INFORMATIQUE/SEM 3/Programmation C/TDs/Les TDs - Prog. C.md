# Présentation
## Le concept des TDs
Le tutorat de _Programmation C_ amène aussi son lot de nouveautés : **les séances de Travaux Dirigés (TD)**.  
Contrairement aux cours magistraux (CM) et aux travaux pratiques (TP) habituels, ces TD offrent une approche différente, plus souple et orientée vers la mise en pratique concrète des connaissances.

Plutôt que de suivre une série d’exercices indépendants, vous allez devoir choisir **un projet de grande ampleur** qui vous accompagnera tout au long du semestre. Ce projet constituera le fil rouge de vos séances, et il devra permettre de mobiliser et de consolider l’ensemble des notions abordées en cours magistral : structures de données, gestion mémoire, pointeurs, modularité, ainsi que les bonnes pratiques de programmation et de conception.

L’objectif est double :
- **Approfondir vos compétences techniques**, en confrontant la théorie à une application réaliste et complète.
- **Développer une autonomie et un esprit d’initiative**, en vous plaçant dans une démarche similaire à celle que vous rencontrerez dans un cadre professionnel ou de recherche.

Vous serez accompagnés tout au long du processus, mais le choix du projet est décisif : il doit être à la fois ambitieux et réalisable dans le temps imparti. Nous vous guiderons pour calibrer votre idée, définir des objectifs intermédiaires et mettre en place un plan de travail progressif.

En fin de semestre, **une présentation**, **une soutenance** ainsi qu'**une démo** viendront clôturer cette aventure, vous offrant l’occasion de valoriser vos acquis, de démontrer vos compétences et de partager vos réalisations avec vos camarades.

## Les séances de TDs
### 🎯 Le rôle des TDs dans le projet

Les **cours magistraux (CM)** donnent la théorie : notions du langage C, structures de contrôle, pointeurs, fichiers, etc.  
Les **TDs** (Travaux Dirigés) servent d’**espace de réflexion et de conception** avant de passer à la pratique en TP.

Concrètement, les TDs permettront aux étudiants de :
1. **Analyser le problème à résoudre**
    - Lire un énoncé de projet (jeu, gestionnaire, simulateur).
    - Identifier les fonctionnalités attendues (entrées/sorties, calculs, organisation).
2. **Découper le projet en modules / fonctionnalités**
    - Quels sous-problèmes composent la solution ?
    - Exemple : dans un jeu → saisie du joueur, vérification de victoire, sauvegarde des scores.
3. **Définir les fonctions nécessaires**
    - Quelles seront leurs **signatures** (arguments, type de retour) ?
    - Comment organiser le code pour éviter la duplication ?
4. **Choisir les structures de données adaptées**
    - Variables simples, tableaux, chaînes, structures, pointeurs.
    - Exemple : représenter un étudiant avec une `struct Etudiant`.
5. **Élaborer des algorithmes**
    - Décrire en pseudo-code ou schéma l’enchaînement logique des opérations.
    - Penser aux cas particuliers (entrées invalides, dépassement de tableau…).
6. **Anticiper les évolutions et extensions**
    - Comment rendre le projet évolutif ?
    - Exemple : un tableau statique pourra-t-il être remplacé plus tard par une liste dynamique ?
7. **Préparer les tests**
    - Définir des cas de test avant même de coder.
    - Exemple : que se passe-t-il si on saisit un score négatif ?

### 🚀 Pourquoi les TDs sont fondamentaux ?
- **Éviter le “codage à l’aveugle”** :  
    Les étudiants qui se lancent directement en TP sans avoir réfléchi aux structures et fonctions écrivent souvent un code confus, difficile à maintenir.
- **Structurer la pensée algorithmique** :  
    Les TDs les entraînent à raisonner comme des informaticiens : analyser, découper, modéliser.
- **Faciliter le passage en TP** :  
    Arriver en TP avec un plan clair (fonctions, structures, algorithmes) permet de se concentrer sur la syntaxe du C et la mise en œuvre technique.
- **Former aux bonnes pratiques de développement** :
    - Réflexion avant implémentation.
    - Conception modulaire.
    - Préparation des tests.
- **Encourager le travail collaboratif** :  
    Les TDs sont un moment où les étudiants discutent entre eux et avec l’enseignant de différentes solutions possibles → ce qui les prépare au travail en équipe.

# Le plan des séances de TDs

<div>
<table class="cours-planC">
  <thead>
    <tr>
      <th>#</th>
      <th>Cours</th>
      <th>Date</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>01</td>
      <td><a href="TD1">Séance TD1</a></td>
      <td>Jeudi 18 septembre 2025</td>
    </tr>
  </tbody>
</table>
</div>

## Liste des projets
*Vous pouvez évidemment choisir votre propre sujet...*

<div class="projects-containerTDC">
  <!-- Projet 1 -->
  <div class="project-cardTDC">
    <h2>🏫 Système de gestion d’université (mini-ENT)</h2>
    <p><strong>Objectif :</strong> Créer une application en C permettant de gérer étudiants, enseignants, cours, notes.</p>
    <ul>
      <li>Inscription d’un étudiant (nom, ID, filière).</li>
      <li>Ajout de cours avec enseignants.</li>
      <li>Gestion des notes (moyennes par étudiant, par cours).</li>
      <li>Sauvegarde/chargement dans des fichiers.</li>
      <li>Recherche (par nom, par cours).</li>
    </ul>
    <p><em>Extensions :</em> tri des étudiants, statistiques globales.</p>
  </div>
  <!-- Projet 2 -->
  <div class="project-cardTDC">
    <h2>🎮 Jeu de rôle textuel (RPG console)</h2>
    <p><strong>Objectif :</strong> Développer un petit RPG entièrement textuel.</p>
    <ul>
      <li>Création de personnage (nom, PV, force, inventaire).</li>
      <li>Exploration de zones textuelles.</li>
      <li>Combats avec système de tours.</li>
      <li>Sauvegarde/chargement de la partie.</li>
    </ul>
    <p><em>Extensions :</em> IA rudimentaire, niveaux de difficulté.</p>
  </div>
  <!-- Projet 3 -->
  <div class="project-cardTDC">
    <h2>📊 Analyseur de données scientifiques</h2>
    <p><strong>Objectif :</strong> Lire des ensembles de données numériques depuis des fichiers et proposer des analyses.</p>
    <ul>
      <li>Lecture de fichiers CSV.</li>
      <li>Calcul de statistiques (moyenne, variance, médiane).</li>
      <li>Tri et recherche dans les données.</li>
      <li>Génération de rapports.</li>
    </ul>
    <p><em>Extensions :</em> régressions simples, structures avancées.</p>
  </div>
  <!-- Projet 4 -->
  <div class="project-cardTDC">
    <h2>📚 Moteur de gestion de bibliothèque numérique</h2>
    <p><strong>Objectif :</strong> Créer un gestionnaire pour stocker et rechercher des livres.</p>
    <ul>
      <li>Stockage (titre, auteur, année, genre).</li>
      <li>Recherche et tri (alphabétique, année).</li>
      <li>Gestion dynamique mémoire.</li>
      <li>Sauvegarde/chargement.</li>
    </ul>
    <p><em>Extensions :</em> statistiques, gestion des emprunts.</p>
  </div>
  <!-- Projet 5 -->
  <div class="project-cardTDC">
    <h2>🌐 Mini-simulateur de réseau social</h2>
    <p><strong>Objectif :</strong> Simuler un petit réseau social en console.</p>
    <ul>
      <li>Création d’utilisateurs (nom, bio, ID).</li>
      <li>Gestion des relations (amis, abonnés).</li>
      <li>Publication de messages.</li>
      <li>Recherche utilisateurs ou messages.</li>
      <li>Sauvegarde des données.</li>
    </ul>
    <p><em>Extensions :</em> fil d’actualité, détection de communautés.</p>
  </div>
</div>
