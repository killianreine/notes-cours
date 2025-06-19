## 1. Compréhension (5 points)

### Question 1 : Dans un script bash, que signifie $# ?

**Réponse correcte :** ☑️ Nombre d'arguments

**Explication :** La variable `$#` contient le nombre d'arguments passés au script (sans compter le nom du script lui-même qui est dans `$0`).

### Question 2 : Qu'est-ce qu'un processus Zombie ?

**Réponse correcte :** ☑️ Un fils terminé avec un père en exécution

**Explication :** Un processus zombie est un processus fils qui a terminé son exécution mais dont l'entrée dans la table des processus n'a pas encore été libérée par le processus père. Le père doit appeler `wait()` ou `waitpid()` pour "récupérer" le code de retour du fils et libérer ses ressources.

### Question 3 : Que signifie « mutex » ?

**Réponse correcte :** ☑️ exclusion mutuelle

**Explication :** Mutex est l'abréviation de "Mutual Exclusion". C'est un mécanisme de synchronisation qui garantit qu'un seul thread peut accéder à une ressource partagée à la fois.

### Question 4 : Une procédure python « calcul » s'exécute en 3s. Combien de temps faut-il pour exécuter « calcul » deux fois via « Thread(target=calcul) » ?

**Réponse correcte :** ☑️ 3 s

**Explication :** Si on lance deux threads en parallèle avec la même fonction qui prend 3 secondes, et que le système peut réellement les exécuter en parallèle, le temps total sera de 3 secondes (les deux s'exécutent simultanément). Note : en Python, le GIL peut limiter le parallélisme réel pour les tâches CPU-intensives.

### Question 5 : Combien ce programme génère-t-il de processus ?

```c
int main(int argc, char *argv[])
{fork(); fork(); fork(); fork(); exit(0);}
```

**Réponse correcte :** ☑️ 16

**Explication :**

- Chaque `fork()` double le nombre de processus
- 4 appels à `fork()` → 2^4 = 16 processus au total
- Le processus initial se multiplie : 1 → 2 → 4 → 8 → 16

## 2. Script shell (4 points)

**Énoncé :** Écrire un script bash qui supprime les fichiers .doc si le .odt de même nom existe dans un répertoire donné en argument du script.

**Solution :**

```bash
#!/bin/bash

# Vérification qu'un argument est fourni
if [ $# -ne 1 ]; then
    echo "Usage: $0 <repertoire>"
    exit 1
fi

repertoire="$1"

# Vérification que le répertoire existe
if [ ! -d "$repertoire" ]; then
    echo "Erreur: Le répertoire '$repertoire' n'existe pas"
    exit 1
fi

count=0

# Parcourir tous les fichiers .doc du répertoire
for doc_file in "$repertoire"/*.doc; do
    # Vérifier que le fichier existe (au cas où il n'y a pas de .doc)
    if [ -f "$doc_file" ]; then
        # Extraire le nom de base sans l'extension
        basename=$(basename "$doc_file" .doc)
        
        # Vérifier si le fichier .odt correspondant existe
        if [ -f "$repertoire/$basename.odt" ]; then
            echo "Suppression de $doc_file (correspondant ODT trouvé)"
            rm "$doc_file"
            ((count++))
        else
            echo "Conservation de $doc_file (pas de ODT correspondant)"
        fi
    fi
done

echo "Nombre de fichiers DOC supprimés: $count"
```

## 3. Python (4 points)

**Énoncé :** Soit L une liste de 100 entiers générés aléatoirement (randint(0,100)). Écrire une fonction permettant de trouver le nombre de valeurs uniques de la liste L avec une complexité linéaire.

**Solution :**

```python
from random import randint

# Génération de la liste L
L = [randint(0, 100) for _ in range(100)]

def nbValeursUniques(liste):
    """
    Fonction pour compter le nombre de valeurs uniques dans une liste.
    Complexité: O(n) où n est la longueur de la liste.
    """
    valeurs_vues = set()
    
    for valeur in liste:
        valeurs_vues.add(valeur)
    
    return len(valeurs_vues)

# Alternative plus concise (même complexité)
def nbValeursUniques_v2(liste):
    """Version plus concise utilisant directement set()"""
    return len(set(liste))

# Test de la fonction
print(f"Liste L: {L}")
print(f"Nombre de valeurs uniques: {nbValeursUniques(L)}")

# Vérification avec la version concise
print(f"Vérification: {nbValeursUniques_v2(L)}")

# Affichage des valeurs uniques pour debug
valeurs_uniques = sorted(set(L))
print(f"Valeurs uniques: {valeurs_uniques}")
```

**Explication :**

- **Complexité temporelle :** O(n) - on parcourt la liste une seule fois
- **Complexité spatiale :** O(k) où k est le nombre de valeurs uniques
- **Principe :** Utilisation d'un `set` qui ne conserve que les valeurs uniques et permet l'insertion en temps constant moyen

## 4. Processus en langage C (4 points)

**Énoncé :** Écrire un programme effectuant la recherche d'un élément dans un tableau en utilisant des processus parallèles. Si le tableau est long (plus qu'une constante TAILLE_MIN), on le coupe en deux et on confie la recherche à deux processus différents.

**Solution :**

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define TAILLE_MIN 10
#define TAILLE_TABLEAU 20

// Fonction de recherche séquentielle
int recherche_sequentielle(int tableau[], int debut, int fin, int element) {
    int count = 0;
    printf("Processus %d recherche dans l'intervalle [%d, %d]\n", 
           getpid(), debut, fin-1);
    
    for (int i = debut; i < fin; i++) {
        if (tableau[i] == element) {
            printf("Processus %d: Occurrence trouvée à l'index %d\n", 
                   getpid(), i);
            count++;
        }
    }
    
    printf("Processus %d: %d occurrence(s) trouvée(s)\n", getpid(), count);
    return count;
}

// Fonction de recherche avec processus parallèles
int recherche_parallele(int tableau[], int debut, int fin, int element) {
    int taille = fin - debut;
    
    // Si la taille est petite, recherche séquentielle
    if (taille <= TAILLE_MIN) {
        return recherche_sequentielle(tableau, debut, fin, element);
    }
    
    // Sinon, diviser en deux parties
    int milieu = debut + taille / 2;
    pid_t pid1, pid2;
    int status1, status2;
    int count_total = 0;
    
    // Création du premier processus fils
    pid1 = fork();
    if (pid1 == 0) {
        // Processus fils 1 - première moitié
        int count = recherche_parallele(tableau, debut, milieu, element);
        exit(count);
    } else if (pid1 < 0) {
        perror("Erreur fork 1");
        return -1;
    }
    
    // Création du deuxième processus fils
    pid2 = fork();
    if (pid2 == 0) {
        // Processus fils 2 - deuxième moitié
        int count = recherche_parallele(tableau, milieu, fin, element);
        exit(count);
    } else if (pid2 < 0) {
        perror("Erreur fork 2");
        return -1;
    }
    
    // Processus père - attendre les fils
    waitpid(pid1, &status1, 0);
    waitpid(pid2, &status2, 0);
    
    // Récupérer les résultats
    if (WIFEXITED(status1)) {
        count_total += WEXITSTATUS(status1);
    }
    if (WIFEXITED(status2)) {
        count_total += WEXITSTATUS(status2);
    }
    
    return count_total;
}

int main() {
    // Initialisation du tableau d'exemple
    int tableau[TAILLE_TABLEAU] = {
        1, 3, 7, 3, 9, 3, 2, 8, 3, 5,
        3, 6, 4, 3, 1, 7, 3, 9, 2, 3
    };
    
    int element_recherche = 3;
    
    printf("=== Recherche de l'élément %d dans le tableau ===\n", 
           element_recherche);
    printf("Taille du tableau: %d\n", TAILLE_TABLEAU);
    printf("Taille minimum pour parallélisation: %d\n", TAILLE_MIN);
    printf("\nContenu du tableau: ");
    for (int i = 0; i < TAILLE_TABLEAU; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n\n");
    
    // Lancement de la recherche
    int total_occurrences = recherche_parallele(tableau, 0, TAILLE_TABLEAU, 
                                               element_recherche);
    
    printf("\n=== RÉSULTAT FINAL ===\n");
    printf("Nombre total d'occurrences de %d: %d\n", 
           element_recherche, total_occurrences);
    
    return 0;
}
```

**Points clés de la solution :**

1. **Stratégie diviser pour régner :** Le tableau est divisé récursivement en deux parties
2. **Condition d'arrêt :** Si la taille est ≤ TAILLE_MIN, recherche séquentielle
3. **Processus parallèles :** Utilisation de `fork()` pour créer des processus fils
4. **Communication :** Le nombre d'occurrences est retourné via `exit()` et récupéré avec `WEXITSTATUS()`
5. **Synchronisation :** Le processus père attend ses fils avec `waitpid()`
6. **Messages informatifs :** Affichage des découvertes et du processus qui les fait

**Exemple d'exécution :**

```
=== Recherche de l'élément 3 dans le tableau ===
Processus 1234: Occurrence trouvée à l'index 1
Processus 1234: Occurrence trouvée à l'index 3
Processus 1235: Occurrence trouvée à l'index 5
...
Nombre total d'occurrences de 3: 8
```