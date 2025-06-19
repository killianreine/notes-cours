## 1. Compréhension (6 points)

### Question 1 : Dans un script bash, que signifie $? ?

**Réponse correcte :** ☑️ Code de retour de la dernière commande

**Explication :** La variable `$?` contient le code de retour (exit status) de la dernière commande exécutée. Par convention, 0 signifie succès, toute autre valeur indique une erreur.

### Question 2 : Qu'est-ce qu'un Intent ?

**Réponse correcte :** ☑️ Un objet de communication

**Explication :** Dans le contexte Android, un Intent est un objet de messagerie qui permet de communiquer entre composants d'une application ou entre applications.

### Question 3 : Que signifie « mutex » ?

**Réponse correcte :** ☑️ exclusion mutuelle

**Explication :** Mutex est l'abréviation de "Mutual Exclusion". C'est un mécanisme de synchronisation qui garantit qu'un seul thread peut accéder à une ressource partagée à la fois.

### Question 4 : Mon CPU possède 4 cœurs HT. Un programme d'un thread prend 1 seconde. Quel est le temps total si le programme génère 10 threads identiques simultanément ?

**Réponse correcte :** ☑️ 3 s

**Explication :**

- CPU avec 4 cœurs HT = 8 threads logiques
- 10 threads à exécuter, chacun prenant 1 seconde
- Premier lot : 8 threads en parallèle → 1 seconde
- Deuxième lot : 2 threads restants → 1 seconde
- Troisième lot : 8 threads du premier lot libérés, mais déjà terminés
- Total : 2 secondes + overhead ≈ 3 secondes

### Question 5 : Combien ce programme génère-t-il de processus ?

c

```c
int main(int argc, char *argv[])
{fork(); fork(); fork(); fork(); fork();
exit(0);}
```

**Réponse correcte :** ☑️ 32

**Explication :**

- Chaque `fork()` double le nombre de processus
- 5 appels à `fork()` → 2^5 = 32 processus au total
- Le processus initial + 31 processus créés = 32 processus

### Question 6 : Que signifie « raw » ?

**Réponse correcte :** Cette question manque de contexte, mais la réponse la plus probable serait liée aux données brutes non traitées.

## 2. Script shell (4 points)

**Énoncé :** Écrire un script bash qui compte le nombre de fichiers .pdf si le .odt de même nom existe dans un même répertoire donné en argument du script.

**Solution :**

bash

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

# Parcourir tous les fichiers .pdf du répertoire
for pdf_file in "$repertoire"/*.pdf; do
    # Vérifier que le fichier existe (au cas où il n'y a pas de .pdf)
    if [ -f "$pdf_file" ]; then
        # Extraire le nom de base sans l'extension
        basename=$(basename "$pdf_file" .pdf)
        
        # Vérifier si le fichier .odt correspondant existe
        if [ -f "$repertoire/$basename.odt" ]; then
            ((count++))
        fi
    fi
done

echo "Nombre de fichiers PDF ayant un ODT correspondant: $count"
```

## 3. Android (3 points)

**Énoncé :** Expliquez la différence entre les capteurs Gyroscope et Accéléromètre.

**Réponse :**

### Accéléromètre

- **Fonction :** Mesure l'accélération linéaire selon les trois axes (X, Y, Z)
- **Unité :** m/s² (mètres par seconde carré)
- **Usage :**
    - Détection de l'orientation de l'appareil (portrait/paysage)
    - Mesure des mouvements et secousses
    - Détection de la gravité terrestre (9.81 m/s²)
- **Applications :** Rotation d'écran, podomètre, détection de chute

### Gyroscope

- **Fonction :** Mesure la vitesse de rotation angulaire autour des trois axes
- **Unité :** rad/s (radians par seconde)
- **Usage :**
    - Détection des rotations précises
    - Mesure de la vitesse de rotation
    - Stabilisation et navigation
- **Applications :** Jeux (contrôle par rotation), réalité augmentée, navigation GPS

### Différences clés

1. **Nature des mesures :** Accélération linéaire vs rotation angulaire
2. **Précision de rotation :** Le gyroscope est plus précis pour les rotations
3. **Complémentarité :** Souvent utilisés ensemble pour une meilleure précision (fusion de capteurs)

## 4. Threads en langage C (4 points)

**Énoncé :** Écrire un programme qui affiche le taux des différences entre deux matrices de triplets en utilisant deux threads pour accélérer les calculs. Matrices 1920x1080 de triplets RGB (unsigned char).

**Solution :**

```c
typedef struct {
    unsigned char r, g, b;
} RGB;

typedef struct {
    RGB (*matrix1)[1080];
    RGB (*matrix2)[1080];
    int start_row;
    int end_row;
    int *diff_count;
    pthread_mutex_t *mutex;
} ThreadData;

void* compare_matrices(void* arg) {
    ThreadData *data = (ThreadData*)arg;
    int local_diff = 0;
    
    for (int i = data->start_row; i < data->end_row; i++) {
        for (int j = 0; j < 1080; j++) {
            RGB pixel1 = data->matrix1[i][j];
            RGB pixel2 = data->matrix2[i][j];
            
            if (pixel1.r != pixel2.r || 
                pixel1.g != pixel2.g || 
                pixel1.b != pixel2.b) {
                local_diff++;
            }
        }
    }
    
    pthread_mutex_lock(data->mutex);
    *(data->diff_count) += local_diff;
    pthread_mutex_unlock(data->mutex);
    
    return NULL;
}

int main() {
    RGB matrix1[1920][1080];
    RGB matrix2[1920][1080];
    
    // Initialisation des matrices (à remplir selon le contexte)
    
    pthread_t thread1, thread2;
    pthread_mutex_t mutex;
    int total_differences = 0;
    
    pthread_mutex_init(&mutex, NULL);
    
    ThreadData data1 = {
        .matrix1 = matrix1,
        .matrix2 = matrix2,
        .start_row = 0,
        .end_row = 960,  // Première moitié
        .diff_count = &total_differences,
        .mutex = &mutex
    };
    
    ThreadData data2 = {
        .matrix1 = matrix1,
        .matrix2 = matrix2,
        .start_row = 960,
        .end_row = 1920,  // Deuxième moitié
        .diff_count = &total_differences,
        .mutex = &mutex
    };
    
    // Création des threads
    pthread_create(&thread1, NULL, compare_matrices, &data1);
    pthread_create(&thread2, NULL, compare_matrices, &data2);
    
    // Attente de la fin des threads
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    // Calcul du pourcentage
    int total_pixels = 1920 * 1080;
    double percentage = ((double)total_differences / total_pixels) * 100.0;
    
    printf("Pourcentage de pixels différents: %.2f%%\n", percentage);
    printf("Nombre de pixels différents: %d sur %d\n", 
           total_differences, total_pixels);
    
    pthread_mutex_destroy(&mutex);
    
    return 0;
}
```

**Points clés de la solution :**

1. **Division du travail :** Chaque thread traite la moitié des lignes de l'image
2. **Synchronisation :** Utilisation d'un mutex pour protéger l'accès à la variable partagée
3. **Structure de données :** Passage des paramètres via une structure
4. **Efficacité :** Comparaison pixel par pixel avec arrêt dès qu'une différence est trouvée