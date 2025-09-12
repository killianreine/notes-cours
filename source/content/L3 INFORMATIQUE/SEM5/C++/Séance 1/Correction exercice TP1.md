# Exercice 1
On considère un fichier `notes.txt` de la forme suivante :
```
12
14.75
15
16
14
10.5
10
12
2.55
14
15
0.33
2
```
Tel que :
- L'entier de la première ligne représente le nombre de notes
- Les autres lignes sont les notes

Codez un programme permettant de stocker les notes dans **un vecteur** puis de calculer la moyenne des notes.
```c++
#include <iostream>     // Pour les E/S
#include <string>       // Pour les string
#include <vector>       // Pour les vecteurs
#include <fstream>      // Pour les fichiers

void calculer_moyenne(std::string fichier){
    // Ouvrir le fichier
    std::ifstream fich(fichier);

    // Vérifier si le fichier est ouvert
    if(!fich.is_open()){
        std::cout << "Le fichier 'na pas été ouvert\n";
        exit(1);
    }

    // On stocke le nombre de notes
    int nb_notes;
    fich >> nb_notes;

    // Création du vecteur et de la variable note
    std::vector<float> tab_note;
    float note;

    // Tant qu'il y a une note, on l'ajoute à la fin du vecteur
    while(fich >> note)
        tab_note.push_back(note);
    
    // Parcours du vecteur et ajout à la somme
    float somme = 0;
    for(auto i : tab_note) somme+=i;

    // Affichage de la moyenne
    std::cout << "Moyenne des notes : " << somme/nb_notes << "\n";

    // Fermer le fichier
    fich.close();
}

int main(){
    // Appel de la fonction
    calculer_moyenne("notes.txt");
}
``` 