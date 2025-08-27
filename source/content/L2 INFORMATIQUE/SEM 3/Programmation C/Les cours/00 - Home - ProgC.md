<style>
body {
    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
    line-height: 1.6;
    min-height: 100vh;
    color: #333;
}
.container {
    max-width: 1200px;
    margin: 0 auto;
    padding: 20px;
    background: rgba(255, 255, 255, 0.95);
    backdrop-filter: blur(10px);
    border-radius: 20px;
    box-shadow: 0 20px 40px rgba(0, 0, 0, 0.1);
    margin-top: 20px;
    margin-bottom: 20px;
}
h1 {
    background: linear-gradient(45deg, #667eea, #764ba2);
    -webkit-background-clip: text;
    -webkit-text-fill-color: transparent;
    background-clip: text;
    font-size: 2.5em;
    text-align: center;
    margin-bottom: 30px;
    padding: 20px 0;
    position: relative;
}
h1::after {
    content: '';
    display: block;
    width: 100px;
    height: 4px;
    background: linear-gradient(45deg, #667eea, #764ba2);
    margin: 20px auto;
    border-radius: 2px;
}
h2 {
    color: #2c3e50;
    font-size: 1.8em;
    margin: 30px 0 20px 0;
    padding: 15px 0;
    border-bottom: 3px solid #3498db;
    position: relative;
}
h2::before {
    content: '';
    position: absolute;
    left: 0;
    bottom: -3px;
    width: 60px;
    height: 3px;
    background: #e74c3c;
}
h3 {
    color: #34495e;
    font-size: 1.4em;
    margin: 25px 0 15px 0;
    padding: 10px 0;
    border-left: 4px solid #3498db;
    padding-left: 15px;
    background: linear-gradient(90deg, rgba(52, 152, 219, 0.1), transparent);
}
p {
    margin-bottom: 15px;
    text-align: justify;
    color: #2c3e50;
    font-size: 1.1em;
}
ul {
    margin: 15px 0 15px 20px;
}
li {
    margin-bottom: 8px;
    color: #34495e;
    position: relative;
    padding-left: 10px;
}
li::before {
    content: '▶';
    color: #3498db;
    position: absolute;
    left: -15px;
    top: 0;
}
a {
    color: #3498db;
    text-decoration: none;
    font-weight: 500;
    transition: all 0.3s ease;
    position: relative;
}
a::after {
    content: '';
    position: absolute;
    width: 0;
    height: 2px;
    bottom: -2px;
    left: 0;
    background: linear-gradient(45deg, #3498db, #e74c3c);
    transition: width 0.3s ease;
}
a:hover::after {
    width: 100%;
}
a:hover {
    color: #e74c3c;
    transform: translateY(-1px);
}
table.cours-plan {
    width: 100%;
    border-collapse: collapse;
    font-family: Arial, sans-serif;
    margin: 30px 0;
    border-radius: 15px;
    overflow: hidden;
    box-shadow: 0 10px 30px rgba(0, 0, 0, 0.1);
}
table.cours-plan th {
    background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
    color: white;
    padding: 15px;
    font-size: 1.1em;
    font-weight: 600;
    text-transform: uppercase;
    letter-spacing: 1px;
}
table.cours-plan td {
    padding: 15px;
    border-bottom: 1px solid rgba(0, 0, 0, 0.05);
    transition: all 0.3s ease;
    background: white;
}
table.cours-plan tr:nth-child(even) td {
    background: rgba(102, 126, 234, 0.02);
}
table.cours-plan tr:hover td {
    background: linear-gradient(90deg, rgba(102, 126, 234, 0.1), rgba(118, 75, 162, 0.1));
    transform: scale(1.01);
    cursor: pointer;
}
table.cours-plan td:first-child {
    font-weight: bold;
    color: #667eea;
    font-size: 1.2em;
    text-align: center;
}
table.cours-plan td:nth-child(2) {
    font-weight: 600;
    color: #2c3e50;
}
table.cours-plan td:last-child {
    color: #7f8c8d;
    font-style: italic;
}
.intro-section {
    background: linear-gradient(135deg, rgba(102, 126, 234, 0.1), rgba(118, 75, 162, 0.1));
    padding: 25px;
    border-radius: 15px;
    margin-bottom: 30px;
    border-left: 5px solid #667eea;
    position: relative;
    overflow: hidden;
}
.intro-section::before {
    content: '';
    position: absolute;
    top: 0;
    right: 0;
    width: 100px;
    height: 100px;
    background: radial-gradient(circle, rgba(102, 126, 234, 0.1), transparent);
    border-radius: 50%;
}
.objectives-grid {
    display: grid;
    grid-template-columns: repeat(auto-fit, minmax(500px, 1fr));
    gap: 20px;
    margin: 20px 0;
}
.objective-card {
    background: white;
    padding: 20px;
    border-radius: 12px;
    box-shadow: 0 5px 15px rgba(0, 0, 0, 0.08);
    border-left: 4px solid #3498db;
    transition: all 0.3s ease;
    position: relative;
    overflow: hidden;
}
.objective-card::before {
    content: '';
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 2px;
    background: linear-gradient(90deg, #3498db, #e74c3c);
}
.objective-card:hover {
    transform: translateY(-5px);
    box-shadow: 0 15px 35px rgba(0, 0, 0, 0.15);
}
.tutorat-info {
    background: linear-gradient(135deg, rgba(52, 152, 219, 0.1), rgba(231, 76, 60, 0.1));
    padding: 25px;
    border-radius: 15px;
    margin: 30px 0;
    border: 2px solid rgba(52, 152, 219, 0.2);
}
.resources-section {
    background: rgba(39, 174, 96, 0.05);
    padding: 25px;
    border-radius: 15px;
    border-left: 5px solid #27ae60;
    margin: 30px 0;
}
.projects-section {
    background: rgba(243, 156, 18, 0.05);
    padding: 25px;
    border-radius: 15px;
    border-left: 5px solid #f39c12;
    margin: 30px 0;
}
.emoji {
    font-size: 1.2em;
    margin-right: 10px;
}
hr {
    border: none;
    height: 3px;
    background: linear-gradient(90deg, #667eea, #764ba2);
    margin: 40px 0;
    border-radius: 2px;
}
.final-message {
    text-align: center;
    font-size: 1.3em;
    font-weight: 600;
    color: #2c3e50;
    padding: 30px;
    background: linear-gradient(135deg, rgba(102, 126, 234, 0.1), rgba(118, 75, 162, 0.1));
    border-radius: 15px;
    margin-top: 30px;
}
.prerequis-card {
    background: rgba(155, 89, 182, 0.1);
    padding: 20px;
    border-radius: 12px;
    border-left: 4px solid #9b59b6;
    margin: 20px 0;
}
@keyframes fadeInUp {
    from {
        opacity: 0;
        transform: translateY(30px);
    }
    to {
        opacity: 1;
        transform: translateY(0);
    }
}
.container {
    animation: fadeInUp 0.8s ease-out;
}
.objective-card {
    animation: fadeInUp 0.8s ease-out;
    animation-delay: 0.2s;
    opacity: 0;
    animation-fill-mode: forwards;
}
.objective-card:nth-child(2) { animation-delay: 0.4s; }
.objective-card:nth-child(3) { animation-delay: 0.6s; }
@media (max-width: 768px) {
    .container {
        padding: 15px;
        margin: 10px;
    }
    h1 {
        font-size: 2em;
    } 
    h2 {
        font-size: 1.5em;
    }
    table.cours-plan th,
    table.cours-plan td {
        padding: 10px 8px;
        font-size: 0.9em;
    }
}
</style>
<div class="container">
    <h1><span class="emoji">📘</span> Cours de Programmation en C</h1>
    <div class="intro-section">
        <p><strong>Bienvenue !</strong><br>
        Ce dépôt contient un tutorat dédié à l'apprentissage du langage C, destiné aux étudiants débutants en informatique ou à toute personne souhaitant acquérir des bases solides en programmation.</p>
    </div>
    <h2><span class="emoji">🎯</span> Objectifs</h2>
    <div class="objectives-grid">
        <div class="objective-card">
            <li>Comprendre la syntaxe et les concepts fondamentaux du langage C</li>
        </div>
        <div class="objective-card">
            <li>Savoir écrire, compiler et exécuter des programmes simples</li>
        </div>
        <div class="objective-card">
            <li>Maîtriser les structures de contrôle (conditions, boucles) et les fonctions</li>
        </div>
        <div class="objective-card">
            <li>Manipuler les pointeurs, tableaux et structures pour développer des programmes plus complexes</li>
        </div>
        <div class="objective-card">
            <li>Acquérir de bonnes pratiques de programmation et de débogage</li>
        </div>
    </div>
    <h2><span class="emoji">ℹ️</span> Tutorats</h2>
    <div class="tutorat-info">
        <p>Le tutorat de programmation en C est un complément pratique au cours magistral.<br>
        Ces séances visent à :</p>
        <ul>
            <li>Revoir et approfondir les notions vues en cours</li>
            <li>S'exercer à l'écriture et à la correction de programmes</li>
            <li>Développer une méthode rigoureuse de résolution de problèmes en informatique</li>
            <li>Répondre aux questions spécifiques des étudiants et partager des astuces de programmation</li>
        </ul>
        <p>Le tutorat se déroule tout au long du semestre et offre un cadre collaboratif et interactif, favorisant l'entraide et la consolidation des compétences en programmation.</p>
    </div>
    <h3>Prérequis</h3>
    <div class="prerequis-card">
        <ul>
            <li>Connaissances de base en informatique</li>
            <li>Aucune expérience préalable en programmation n'est requise</li>
        </ul>
    </div>
    <h3>Plan du Cours</h3>
    <p>Table des matières complète : <a href="Prog C - Table des matières">[[Prog C - Table des matières]]</a></p>
    <table class="cours-plan">
        <thead>
        <tr>
        <th>#</th>
        <th>Cours</th>
        <th>Description</th>
        </tr>
        </thead>
        <tbody>
        <tr><td>01</td><td><a href="01 - Introduction">Introduction</a></td><td>Présentation du C</td></tr>
        <tr><td>02</td><td><a href="02 - Premiers pas">Premiers pas</a></td><td>Variables et entrées/sorties</td></tr>
        <tr><td>03</td><td><a href="03 - Opérateurs & Arithmétique">Opérateurs & Arithmétique</a></td><td>Opérations de base</td></tr>
        <tr><td>04</td><td><a href="04 - Conditions et boucles">Conditions et boucles</a></td><td>Structures de contrôle</td></tr>
        <tr><td>05</td><td><a href="05 - Retour sur les fonctions">Retour sur les fonctions</a></td><td>Fonctions et paramètres</td></tr>
        <tr><td>06</td><td><a href="06 - Les tableaux statiques">Les tableaux statiques</a></td><td>Tableaux fixes et manipulation</td></tr>
        <tr><td>07</td><td><a href="07 - Chaînes de caractères">Chaînes de caractères</a></td><td>Strings et fonctions associées</td></tr>
        <tr><td>08</td><td><a href="08 - Les pointeurs">Les pointeurs</a></td><td>Introduction aux pointeurs</td></tr>
        <tr><td>09</td><td><a href="09 - Allocation dynamique">Allocation dynamique</a></td><td>malloc, free, et gestion mémoire</td></tr>
        <tr><td>10</td><td><a href="10 - Structures avancées">Structures avancées</a></td><td>Structures et typedef</td></tr>
        <tr><td>11</td><td><a href="11 - Les fichiers">Les fichiers</a></td><td>Lecture/écriture fichiers</td></tr>
        <tr><td>12</td><td><a href="12 - Tests unitaires">Tests unitaires</a></td><td>Introduction aux tests en C</td></tr>
        <tr><td>13</td><td><a href="13 - Compilation séparée et Makefile">Compilation séparée et Makefile</a></td><td>Organisation du code et Makefiles</td></tr>
        <tr><td>14</td><td><a href="14 - Structures particulières">Structures particulières</a></td><td>Structures complexes et usage avancé</td></tr>
        <tr><td>15</td><td><a href="15 - Fonctions avancées">Fonctions avancées</a></td><td>Fonctions récursives et pointeurs de fonctions</td></tr>
        </tbody>
    </table>
    <h3>Ressources</h3>
    <div class="resources-section">
        <ul>
            <li><a href="https://en.cppreference.com/w/c">Documentation officielle du langage C</a></li>
            <li>Langage C - Maîtriser la programmation procédurale (avec exercices pratiques) (2e édition), édition ENI</li>
            <li>Zeste de savoir, Langage C <a href="https://zestedesavoir.com/tutoriels/pdf/755/le-langage-c-1.pdf">PDF</a></li>
        </ul>
    </div>
    <h3>Projets et exercices</h3>
    <div class="projects-section">
        <p>Le cours proposera des exercices de niveaux différents, chacun sera accompagné de sa correction. Et, pour consolider les acquis des <em>projets</em> pourront être proposés. La plupart du temps chaque projet aura un sujet liant sciences et informatiques.</p>
        <ul>
            <li>Mathématiques x informatique</li>
            <li>Algèbre x informatique</li>
            <li>Physique x informatique</li>
            <li>IRL x informatique</li>
        </ul>
    </div>
    <hr>
    <div class="final-message">
        Bonne chance dans votre apprentissage du langage C !
    </div>
</div>

