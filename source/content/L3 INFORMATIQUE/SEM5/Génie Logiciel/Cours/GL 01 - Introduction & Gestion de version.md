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