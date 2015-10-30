//-------------------------------------------------------------------------------
// sciper: 253133
// nom: Borden
// prenom: Sven
// fichier: conway.c
// date: 20.10.2015
// version: 0.9
// description du programme: projet PROG I Automne 2015-16 EPFL MT-EL
//-------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#define ZOOM_MAX = 100
#define ZOOM_MIN = 1
#define TAILLE_FORMAT = 2

static void lecture();
static void reprint(int nbPrint);
//-------------------------------------------------------------------------------
//                 NE PAS MODIFIER CES PROTOTYPES DE FONCTIONS

static void erreur_nbJ(int nbJ);
static void erreur_nbS(int nbS);
static void erreur_nbJ_nbS(int nbJ, int nbS);
static void erreur_zoom(int zoom);
//-------------------------------------------------------------------------------

static int verbose = 0;

int main(int argc, const char * argv[]) 
{
	lecture();
    return EXIT_SUCCESS ;
}

static void lecture()
{
	//Fields
	int nbJ, nbS, nbL, nbC, zoom;
	int i, j;
	int question = 0;
	char format[TAILLE_FORMAT];

	//Lecture des inputs
	scanf("%d", &verbose);

	reprint(question++);
	scanf("%d", &nbJ);
	if(nbJ < 0)
		erreur_nbJ(nbJ);
	
	reprint(question++);
	scanf("%d", &nbS);
	if(nbS < 0)
		erreur_nbS(nbS);
	if((nbS > 0 && nbJ % nbS != 0) || (nbJ == 0 && nbS > 1))
		erreur_nbJ_nbS(nbJ, nbS);

	reprint(question++);
	scanf("%d", &zoom);
	if(zoom < ZOOM_MIN || zoom > ZOOM_MAX)
		erreur_zoom(zoom);

	reprint(question++);
	scanf("%s", format);

	reprint(question++);
	scanf("%d", &nbC);
	scanf("%d", &nbL);

	reprint(question++);

	int tabInit[nbC][nbL];
	int tabSuiv[nbC][nbL];
	
	for(i = 0; i < nbC; i++)
		for(j = 0; j < nbL; j++)
			scanf("%d", &tabInit[i][j]);
}

static void reprint(int nbPrint)
{
	if(verbose)
	{
		switch(nbPrint)
		{
			case 0 : printf("Entrez le nombre de mises à jours\n");
						break;
			case 1 : printf("Entrez la période d'affichage\n");
						break;
			case 2 : printf("Entrez le facteur de zoom\n");
						break;
			case 3 : printf("Entrez le code du format de l'image\n");
						break;
			case 4 : printf("Entrez les dimensions de l'image\n");
						break;
			case 5 : printf("Entrez les valeurs du monde\n");
						break;
			default : break;
		}
	}
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
