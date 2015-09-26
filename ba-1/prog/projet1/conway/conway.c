//-------------------------------------------------------------------------------
// sciper: 253133
// nom: Borden
// prenom: Sven
// fichier: conway.c
// date: 26.09.2015
// description du programme: projet PROG I Automne 2015-16 EPFL MT-EL
//-------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

static void erreur_nbJ(int nbJ);
static void erreur_nbS(int nbS);
static void erreur_nbJ_nbS(int nbJ, int nbS);
static void erreur_zoom(int zoom);

static int verbose;


int main(int argc, const char * argv[]) 
{
	//variables
	int nbJ,
		nbS,
		nbL,
		nbC,
		zoom;
	
	//lecture des input
	scanf("%d", &verbose);
	
	scanf("%d", &nbJ);
	if(nbJ < 0)
		erreur_nbJ(nbJ);
	
	scanf("%d", &nbS);
	if(nbS < 0)
		erreur_nbS(nbS);
	if(nbJ % nbS != 0)
		erreur_nbJ_nbS(nbJ, nbS);

	scanf("%d", &zoom);
	if(zoom <= 0 || zoom > 100)
		erreur_zoom(zoom);	




    return EXIT_SUCCESS ;
}



//-------------------------------------------------------------------------------
// Fonctions prédéfinies pour indiquer si les données sont correctes
// Les fonctions signalant une erreur provoquent la fin du programme
// en appelant exit(). Leur message d'erreur est toujours affiché.
//
//                 NE PAS MODIFIER CES FONCTIONS
//-------------------------------------------------------------------------------

// A appeler si le nombre de mises à jours n'est pas positif
static void erreur_nbJ(int nbJ) 
{
    printf("Le nombre de mises à jours nbJ n'est pas positif: %d\n", nbJ);
    exit(EXIT_FAILURE);
}

// A appeler si la periode de sauvegarde n'est pas positive
static void erreur_nbS(int nbS) 
{
    printf("La période de sauvegarde nbS n'est pas positive: %d\n", nbS);
    exit(EXIT_FAILURE);
}

// A appeler si la periode de sauvegarde n'est pas positive
static void erreur_nbJ_nbS(int nbJ, int nbS) 
{
    printf("La combinaison du nombre de mises à jour %d et de la période de "
           "sauvegarde %d est interdite\n", nbJ, nbS);
    exit(EXIT_FAILURE);
}

// A appeler si le facteur de zoom n'est pas dans le bon intervalle
static void erreur_zoom(int zoom) 
{
    printf("Le facteur de zoom %d n'est pas compris dans l'intervalle ]0,100]\n",
           zoom);
    exit(EXIT_FAILURE);
}
