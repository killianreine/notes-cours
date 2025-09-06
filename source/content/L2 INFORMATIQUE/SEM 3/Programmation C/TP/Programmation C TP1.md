# TP1 - Premiers pas en C : La Machine à Café Virtuelle ☕

**Durée :** 1h30  
**Objectif :** Découvrir les bases du langage C en créant une simulation de machine à café interactive

---

## 🎯 Objectifs pédagogiques

À l'issue de ce TP, vous saurez :

- Structurer un programme C avec `#include` et `main()`
- Utiliser les types de données de base (`int`, `float`, `char`)
- Gérer les entrées/sorties avec `printf()` et `scanf()`
- Implémenter des structures conditionnelles (`if/else`)
- Créer des boucles simples (`while`, `for`)
- Manipuler des variables et effectuer des calculs

---

## 📋 Contexte du projet

Vous allez programmer une **machine à café virtuelle** qui permet à l'utilisateur de :
- Choisir parmi différents types de boissons
- Gérer un porte-monnaie virtuel
- Calculer la monnaie à rendre
- Suivre le stock des ingrédients

---

## 🛠️ Exercice 1 : Structure de base (15 min)

### Consigne
Créez le fichier `machine_cafe.c` avec la structure de base suivante :

```c
#include <stdio.h>

int main() {
    printf("=== MACHINE À CAFÉ VIRTUELLE ===\n");
    printf("Bienvenue dans notre café automatique !\n");
    
    return 0;
}
```

### Questions
1. Que fait l'instruction `#include <stdio.h>` ?
2. Pourquoi utilise-t-on `\n` dans les chaînes de caractères ?
3. Que signifie `return 0;`, que se passe t-il si on ne le met pas ? Pourquoi ?

## ☕ Exercice 2 : Menu des boissons (20 min)

### Consigne
Étendez votre programme pour afficher un menu de boissons avec leurs prix :  
Vous allez devoir afficher les options de votre machine à café, c'est à dire quelle sorte de boisson elle vend. Nous nous contenterons de prendre les boissons suivantes : *expresso, double, chocolat, cappuccino*. Vous devez simplement afficher les options de la machine de cette forme : 
```
1. Expresso 1.50
2. Double 2.80
...
```

1. Déclarez une variable pour stocker le prix de la boisson choisie
2. Sans utiliser de `if`, trouve un moyen *après sélection de la boisson* de lui associer le bon prix.
3. Affichez le nom de la boisson et son prix

### Questions
- Quelle est la différence entre `%d` et `%f` dans `printf` ?
- Pourquoi utilise-t-on `&choix` dans `scanf` ?

## 💰 Exercice 3 : Gestion du paiement (25 min)

### Consigne
Ajoutez la gestion du paiement à votre programme :

### À implémenter
1. Demandez à l'utilisateur d'insérer de l'argent
2. Faite en sorte que l'utilisateur puisse payer.

### Tests à effectuer
- Argent insuffisant (ex: 1.00€ pour un cappuccino à 2.50€)
- Argent exact (ex: 2.50€ pour un cappuccino)
- Argent en excès (ex: 5.00€ pour un expresso à 1.50€)

## 📦 Exercice 4 : Gestion des stocks (30 min)

### Consigne
Ajoutez un système de gestion des stocks d'ingrédients :

### Variables de stock à déclarer
```c
int stock_cafe = 10;      // doses de café
int stock_lait = 8;       // doses de lait
int stock_chocolat = 5;   // doses de chocolat
int stock_the = 6;        // sachets de thé
```

### Consommation par boisson
- **Expresso** : 1 dose de café
- **Café long** : 1 dose de café
- **Double** : $2$ doses de café
- **Cappuccino** : 1 dose de café + 1 dose de lait
- **Chocolat chaud** : 1 dose de chocolat + 1 dose de lait
- **Thé** : 1 sachet de thé

### À implémenter
1. Vérifiez si les ingrédients sont disponibles avant de servir
2. Si disponibles : décrémenter les stocks et servir la boisson
3. Si indisponibles : afficher un message d'erreur
4. Affichez l'état des stocks après chaque commande

### Exemple de sortie
```
Préparation de votre cappuccino...
# Cappuccino servi !

=== ÉTAT DES STOCKS ===
Café : 9 doses
Lait : 7 doses
Chocolat : 5 doses
Thé : 6 sachets
```

---

## 🔄 Exercice 5 : Boucle principale (20 min)

### Consigne

Transformez votre programme pour qu'il fonctionne en continu jusqu'à ce que l'utilisateur décide d'arrêter :

### Structure à implémenter

```c
int continuer = 1;  // 1 = continuer, 0 = arrêter

while(continuer) {
    // Votre code de machine à café
    
    printf("\nVoulez-vous commander autre chose ? (1=Oui, 0=Non) : ");
    scanf("%d", &continuer);
}

printf("Merci de votre visite ! À bientôt !\n");
```

### Améliorations optionnelles

1. Ajoutez une option "0" dans le menu pour quitter
2. Comptez le nombre total de boissons servies
3. Calculez le chiffre d'affaires total

---

## 🎖️ Exercice Bonus : Fonctionnalités avancées (temps restant)

### Pour aller plus loin, ajoutez :
1. **Mode maintenance** : Option pour recharger les stocks
2. **Statistiques** : Boisson la plus vendue, recette totale
3. **Validation des entrées** : Vérifier que l'utilisateur entre des valeurs valides
4. **Messages personnalisés** : Différents messages selon l'heure simulée
## 💡 Conseils pratiques
### Compilation et exécution
```bash
gcc -o machine_cafe machine_cafe.c
./machine_cafe
```

### Debugging
- Utilisez `printf()` pour afficher les valeurs des variables
- Vérifiez que les types de données correspondent
- Testez tous les cas possibles

### Bonnes pratiques
- Commentez votre code pour expliquer la logique
- Utilisez des noms de variables explicites
- Indentez votre code pour améliorer la lisibilité

**Bonne programmation ! ☕🖥️**