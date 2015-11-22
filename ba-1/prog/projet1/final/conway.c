//------------------------------------------------------------------------------
// sciper: 253133
// nom: Borden
// prenom: Sven
// fichier: conway.c
// date: 12.10.2015
// description du programme: projet PROG I Automne 2015-16 EPFL MT-EL
//-------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#define ZOOM_MAX = 100
#define ZOOM_MIN = 1
#define TAILLE_FORMAT = 2

struct basicVal
{
	int ligne;
	int colonne; 
	int zoom;
	int nbJ;
	int nbS;
};

static void lecture(),

static int verbose = 0;

int main(int argc, vonst char* argv[])
{
	lecture();
	return EXIT_SUCCESS;
}

static void lecture()
{
	int i, j;
	int question = 0;
	char format[2];
	struct basicVal val;
	struct basicVal *pVal = &val;

	scanf("%d", &verbose);

	reprint(question++);
	scanf("%d", &val.nbJ);
	if (val.nbJ < 0)
		erreur_nbJ(val.nbJ);

	reprint(question++);
	scanf("%d", val.nbS);
	if (val.nbS < 0)
		erreur_nbS(val.nbS);
	if ((val.nbS > 0 && val.nbJ % val.nbS != 0) || (val.nbJ == 0 && val.nbS > 1))
		erreur_nbJ_nbS(val.nbJ, val.nbS);

	reprint(question++);
	scanf("%d", &val.zoom);
	if (val.zoom < ZOOM_MIN || val.zoom > ZOOM_MAX)
		erreur_zoom(val.zoom);

	reprint(question++);
	scanf("%s", format);

	reprint(question++);
	scanf("%d", &val.colonne);
	scanf("%d", &val.ligne);

	reprint(question++);

	int tabInit[val.colonne][val.ligne];
	int tabSuiv[val.colonne][val.ligne];

	for (i = 0; i < nbC; i++)
		for (j = 0; j < nbL; j++)
			scanf("%d", &tabInit[i][j]);
	entete(pVal);
}

void entete(struct basicVal * pVal)
{
	int col = pVal->colonne * pVal->zoom;
	int lig = pVal->ligne * pVal->zoom; //premier affichage
	lig += (pVal->nbJ / pVal->nbS) * (pVal->ligne * pVal->zoom); //t etapes
	lig += pVal->nbJ / pVal->nbS; //t lignes noires
	printf("P1\n%d %d\n", col, lig);
}