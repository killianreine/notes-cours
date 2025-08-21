#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Erreur argument : %s <nombre> <taille>\n", argv[0]);
        return 1;
    }
	
	// Récupération des derniers arguments
	// On utilise atoi() pour convertir les arguments en entier !
	int k = atoi(argv[1]);  // Le nombre dont on veut les multiples
    int n = atoi(argv[2]);  // Le nombre de multiples
    int tab[n];             // Création du tableau
    
    // Remplissage
    for(int i=0; i<n; i++) 
		  tab[i]=k*(i+1);
		
	// Affichage
	printf("[ ");
	for(int i=0; i<n-1; i++) 
		printf("%d, ", tab[i]);
	printf("%d ]\n", tab[n-1]);
	return 0;
}
