# 🔐 TP : OPÉRATION CRYPTEX - Mission de Chiffrement

## 📋 Contexte de la mission

L'année est 1942. Vous êtes un cryptographe de la Résistance française chargé de développer un système de communication sécurisé pour transmettre des messages entre les différents réseaux. Votre objectif : créer un programme en C capable de chiffrer, déchiffrer et analyser des messages en utilisant le **chiffre de Vigenère**, une technique réputée incassable à l'époque !

**Temps estimé :** 4-6 heures  
**Niveau :** Intermédiaire  
**Compétences visées :** Manipulation de tableaux, chaînes de caractères, algorithmes, structures de contrôle

---

## 🎯 Objectifs pédagogiques

À la fin de ce TP, vous serez capable de :

- ✅ Manipuler des tableaux statiques mono et multidimensionnels
- ✅ Traiter des chaînes de caractères complexes
- ✅ Implémenter des algorithmes de chiffrement
- ✅ Créer des fonctions modulaires et réutilisables
- ✅ Gérer les entrées/sorties utilisateur
- ✅ Déboguer et tester méthodiquement votre code

---

## 📐 Contraintes techniques OBLIGATOIRES

### Règles strictes

- ❌ **INTERDICTION** d'utiliser `malloc`, `calloc`, ou tout pointeur dynamique
- ✅ **UNIQUEMENT** des tableaux statiques (déclarés avec une taille fixe)
- ✅ Taille maximale du message : **500 caractères**
- ✅ Taille maximale de la clé : **100 caractères**
- ✅ Utilisation des bibliothèques standard autorisées : `stdio.h`, `string.h`, `ctype.h`, `stdlib.h`

### Structure du projet

Votre code doit être organisé ainsi :

```
projet_cryptex/
├── cryptex.c          (fichier principal)
└── tests.txt          (exemples de tests)
```

---

## 🛠️ Fonctionnalités à implémenter

### Phase 1 : Fonctions de base (40% de la note)

#### 1.1 - Préparation du texte

```c
void nettoyer_texte(char texte[], char resultat[]);
```

**Rôle :** Prépare le texte pour le chiffrement

- Supprime les accents : é→e, à→a, ç→c, etc.
- Préserve les espaces et la ponctuation
- Convertit tout en MAJUSCULES pour simplifier
- **Exemple :** `"Rendez-vous à 18h!"` → `"RENDEZ-VOUS A 18H!"`

#### 1.2 - Validation de la clé

```c
int valider_cle(char cle[]);
```

**Rôle :** Vérifie que la clé est valide

- Retourne 1 si la clé ne contient que des lettres
- Retourne 0 sinon
- Affiche un message d'erreur explicite si invalide

#### 1.3 - Chiffrement de Vigenère

```c
void chiffrer_vigenere(char message[], char cle[], char resultat[]);
```

**Rôle :** Chiffre le message selon l'algorithme de Vigenère

- **Formule :** `C[i] = (M[i] + K[i mod len(K)]) mod 26`
- Les caractères non-alphabétiques restent inchangés
- Préserve les espaces et la ponctuation
- **Exemple détaillé :**
    
    ```
    Message : BONJOUR
    Clé :     SECRET (répétée : SECRETS)
    
    B + S = 1 + 18 = 19 → T
    O + E = 14 + 4 = 18 → S
    N + C = 13 + 2 = 15 → P
    J + R = 9 + 17 = 26 → A (mod 26)
    O + E = 14 + 4 = 18 → S
    U + T = 20 + 19 = 39 → N (39 mod 26 = 13)
    R + S = 17 + 18 = 35 → J (35 mod 26 = 9)
    
    Résultat : TSPASNI
    ```
    

#### 1.4 - Déchiffrement de Vigenère

```c
void dechiffrer_vigenere(char chiffre[], char cle[], char resultat[]);
```

**Rôle :** Inverse le chiffrement

- **Formule :** `M[i] = (C[i] - K[i mod len(K)] + 26) mod 26`
- Le +26 évite les valeurs négatives

---

### Phase 2 : Analyse cryptographique (30% de la note)

#### 2.1 - Analyse de fréquence

```c
void analyser_frequences(char texte[], int frequences[26], int *total_lettres);
```

**Rôle :** Compte l'occurrence de chaque lettre

- Remplit un tableau de 26 cases (A-Z)
- Ignore la casse, espaces et ponctuation
- Met à jour le nombre total de lettres via le pointeur
- **Exemple :**
    
    ```
    Texte : "HELLO WORLD"
    Fréquences : A=0, B=0, C=0, D=1, E=1, ..., L=3, O=2, ...
    Total : 10 lettres
    ```
    

#### 2.2 - Affichage graphique avancé

```c
void afficher_histogramme(int frequences[26], int total);
```

**Rôle :** Affiche un histogramme ASCII stylisé

- Affiche les barres proportionnelles
- Indique le pourcentage de chaque lettre
- N'affiche que les lettres présentes (fréquence > 0)
- **Format attendu :**
    
    ```
    === ANALYSE DES FRÉQUENCES ===
    Total : 245 lettres analysées
    A: ████████████ 12.2% (30)
    E: ████████████████████ 18.8% (46)
    L: ██████ 5.7% (14)
    O: ████████ 8.2% (20)...
    ```
    

#### 2.3 - Calcul de l'indice de coïncidence

```c
float calculer_indice_coincidence(char texte[]);
```

**Rôle :** Calcule l'IC pour deviner la longueur de la clé

- **Formule :** `IC = Σ(ni * (ni-1)) / (N * (N-1))`
- IC ≈ 0.067 pour un texte français
- IC ≈ 0.038 pour un texte chiffré avec Vigenère
- Aide à déterminer si le texte est chiffré ou non

---

### Phase 3 : Attaque cryptanalytique (20% de la note)

#### 3.1 - Détection de mots-clés

```c
int contient_mots_francais(char texte[]);
```

**Rôle :** Vérifie si le texte contient des mots français courants

- Cherche au moins 3 mots parmi : "LE", "DE", "UN", "ET", "DANS", "QUE", "EST", "POUR", "PAR", "SUR"
- Retourne le nombre de mots trouvés
- Utile pour valider un déchiffrement

#### 3.2 - Force brute intelligente

```c
void attaque_force_brute(char message_chiffre[], int longueur_cle_max);
```

**Rôle :** Tente de casser le chiffrement

- Teste toutes les clés de longueur 1 à `longueur_cle_max` (max 4)
- Affiche uniquement les résultats contenant des mots français
- Limite : 26^4 = 456 976 combinaisons max (pour longueur 4)
- **Affichage attendu :**
    
    ```
    🔍 RECHERCHE EN COURS... (longueur de clé : 3)
    
    ✓ Clé possible trouvée : "CLE"  
    → "LE MESSAGE EST CLAIR ET CONTIENT DES MOTS"  
    → Score : 5 mots français détectés
    
    ✓ Clé possible trouvée : "MOT"  
    → "JK FQCCYMQ QCN NRZMX QD LKJNMQJN BQC SUD"  
    → Score : 2 mots français détectés
    ```
    

---

### Phase 4 : Interface utilisateur (10% de la note)

#### 4.1 - Menu principal interactif

```c
void afficher_menu();
int lire_choix();
```

**Menu complet attendu :**

```
╔═══════════════════════════════════════════╗
║   🔐 OPÉRATION CRYPTEX - V2.0 🔐         ║
║   Système de chiffrement de la Résistance ║
╚═══════════════════════════════════════════╝

[1] 📝 Chiffrer un message
[2] 🔓 Déchiffrer un message
[3] 📊 Analyser les fréquences d'un texte
[4] 🔍 Attaque par force brute
[5] 📖 Afficher l'aide
[6] 🚪 Quitter le programme

Votre choix : 
```

#### 4.2 - Gestion des erreurs

- Vérifier que le message ne dépasse pas 500 caractères
- Vérifier que la clé ne dépasse pas 100 caractères
- Valider que la clé ne contient que des lettres
- Gérer les entrées invalides dans le menu
- Afficher des messages d'erreur clairs et explicites

---

## 🧪 Tests obligatoires à réaliser

### Test 1 : Chiffrement basique

```
Message : "ATTAQUE A L AUBE"
Clé : "SECRET"
Résultat attendu : "SXVEEIW S T SYFX"
```

### Test 2 : Message avec ponctuation

```
Message : "Rendez-vous demain, 18h30!"
Clé : "RESISTANCE"
Résultat attendu : "ISKASL-EMFG UVQRTN, 18U30!"
```

### Test 3 : Réversibilité

Chiffrer puis déchiffrer avec la même clé doit redonner le message original.

### Test 4 : Analyse de fréquence

Sur le texte : "ELLE EST ALLEE A LA PLAGE"

- E devrait être la lettre la plus fréquente
- L et A également bien représentées

### Test 5 : Attaque force brute

Sur un message chiffré avec une clé de 3 lettres, l'attaque doit retrouver la bonne clé.

---

## 📚 Aide et ressources

### L'algorithme de Vigenère expliqué

**Principe :** Chaque lettre de la clé décale les lettres du message d'un certain rang.

**Table de correspondance :**

```
A=0, B=1, C=2, D=3, E=4, F=5, G=6, H=7, I=8, J=9,
K=10, L=11, M=12, N=13, O=14, P=15, Q=16, R=17,
S=18, T=19, U=20, V=21, W=22, X=23, Y=24, Z=25
```

**Exemple pas à pas :**

```
Message : "SALUT"
Clé : "CLE" (répétée : "CLECL")

S (18) + C (2) = 20 → U
A (0)  + L (11) = 11 → L
L (11) + E (4) = 15 → P
U (20) + C (2) = 22 → W
T (19) + L (11) = 30 → 30 mod 26 = 4 → E

Résultat : "ULPWE"
```

### Fonctions utiles

```c
toupper(c)    // Convertit en majuscule
tolower(c)    // Convertit en minuscule
isalpha(c)    // Vérifie si c'est une lettre
strlen(s)     // Longueur d'une chaîne
strcpy(d, s)  // Copie une chaîne
strstr(s, sub)// Cherche une sous-chaîne
```

---

## 🎁 BONUS (facultatifs, +20% max)

### Bonus 1 : Historique des messages (5%)

```c
void sauvegarder_historique(char messages[][500], int *nb_messages, char nouveau[]);
void afficher_historique(char messages[][500], int nb_messages);
```

Stocker les 10 derniers messages traités dans un tableau 2D.

### Bonus 2 : Chiffre de César intégré (5%)

```c
void chiffrer_cesar(char message[], int decalage, char resultat[]);
```

Ajouter une option pour chiffrer avec César (cas particulier de Vigenère).

### Bonus 3 : Détection automatique de la longueur de clé (5%)

```c
int deviner_longueur_cle(char message_chiffre[]);
```

Utiliser la méthode de Kasiski ou l'IC pour estimer la longueur de la clé.

### Bonus 4 : Export des résultats (5%)

```c
void exporter_vers_fichier(char message[], char cle[], char resultat[]);
```

Sauvegarder les résultats dans un fichier `resultats.txt`.