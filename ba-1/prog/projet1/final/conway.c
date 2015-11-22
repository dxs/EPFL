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

#define ZOOM_MAX  100
#define ZOOM_MIN 1
#define TAILLE_FORMAT  2
#define CHARMAX 35

struct basicVal
{
	int ligne;
	int colonne; 
	int zoom;
	int nbJ;
	int nbS;
};

//-------------------------------------------------------------------------------
//                 NE PAS MODIFIER CES PROTOTYPES DE FONCTIONS

static void erreur_nbJ(int nbJ);
static void erreur_nbS(int nbS);
static void erreur_nbJ_nbS(int nbJ, int nbS);
static void erreur_zoom(int zoom);
//-------------------------------------------------------------------------------

static void lecture();
static void analyse(int* pT1, int* pT2, struct basicVal* pVal);
static void start(int* pT1, int* pT2, struct basicVal* pVal);
static void output(int* tableau, struct basicVal* pVal, int compteur);
static void header(struct basicVal*);
static void reprint(int question);


static int verbose = 0;

int main(int argc, const char* argv[])
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
	scanf("%d", &val.nbS);
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
	int *pTabInit = (int*)tabInit;
	int *pTabSuiv = (int*)tabSuiv;
	for (i = 0; i < val.colonne; i++)
		for (j = 0; j < val.ligne; j++)
			scanf("%d", &tabInit[i][j]);
	header(pVal);
	output(pTabInit, pVal, 0);
}

static void analyse(int* pT1, int* pT2, struct basicVal* pVal)
{
	int i, posX, posY;
	int ligne = pVal->ligne;
	int colonne = pVal->colonne;
	for (i = 0; i < ligne * colonne; i++)
	{
		posX = i % ligne;
		posY = i / ligne;
		if ((posX > 0) && (y > 0) && (posX < i) && (posY < j))//cas 0
			*(pT2 + i) = caseVivante(pT1, i, pVal, 0);
		else
		{
			if (posY == 0 || posY == ligne)
				if (posY == 0)//cas 8
					*(pT2 + i) = caseVivante(pT1, i, pVal, 8);
				else//cas 1
					*(pT2 + i) = caseVivante(pT1, i, pVal, 1);
			else
				if (posX == 0 || posX == colonne)
					if (posX == 0)//cas 2
						*(pT2 + i) = caseVivante(pT1, i, pVal, 2);
					else//cas 4
						*(pT2 + i) = caseVivante(pT1, i, pVal, 4);
			if (posX == 0)
				if(posY == 0)//cas 10
					*(pT2 + i) = caseVivante(pT1, i, pVal, 10);
				else//cas 3
					*(pT2 + i) = caseVivante(pT1, i, pVal, 3);
			else
				if(posX == colonne && posY == 0)//cas 12
					*(pT2 + i) = caseVivante(pT1, i, pVal, 12);
				else//cas 5
					*(pT2 + i) = caseVivante(pT1, i, pVal, 5);
		}

	}//for end
}

static int caseVivante(int* tableau, int position, struct basicVal* pVal, cas)
{

}

static void start(int* pT1, int* pT2, struct basicVal* pVal)
{
	int i;
	for (i = 0; i < pVal->nbJ; i++)
		if (i % 2 == 0)
			analyse(pT1, pT2, pVal);
		else
			analyse(pT2, pT1, pVal);
	if (i % pVal->nbS == 0)
		if (i % 2 == 0)
			output(pT2, pVal, i);
		else
			output(pT1, pVal, i);
}

static void output(int* tableau, struct basicVal* pVal, int compteur)
{
	int i, j, k, l, charcompteur = 0;
	if (compteur != 0) //imprime une ligne noire
		for (i = 0; i < pVal->colonne * pVal->zoom; i++, charcompteur++)
			if (charcompteur == CHARMAX)
			{
				printf("\n");
				charcompteur = 0;
			}
			else
				printf("1 ");
	
	printf("\n");
	charcompteur = 0;

	//impression du tableau
	for (i = 0; i < pVal->ligne; i++)
		for (k = 0; k < pVal->zoom; k++)
		{
			for (j = 0; j < pVal->colonne; j++)
				for (l = 0; l < pVal->zoom; l++, charcompteur++)
				{
					if (charcompteur == CHARMAX)
					{
						printf("\n");
						charcompteur = 0;
					}
					printf("%d ", *(tableau + (i*pVal->ligne) + j));
				}
			printf("\n");
			charcompteur = 0;
		}
}

static void header(struct basicVal * pVal)
{
	int col = pVal->colonne * pVal->zoom;
	int lig = pVal->ligne * pVal->zoom;
	lig += (pVal->nbJ / pVal->nbS) * (pVal->ligne * pVal->zoom);
	lig += pVal->nbJ / pVal->nbS;
	printf("P1\n%d %d\n", col, lig);
}

static void reprint(int question)
{
	if (verbose)
	{
		switch (question)
		{
		case 0: printf("Entrez le nombre de mises à jours\n");
			break;
		case 1: printf("Entrez la période d'affichage\n");
			break;
		case 2: printf("Entrez le facteur de zoom\n");
			break;
		case 3: printf("Entrez le code du format de l'image\n");
			break;
		case 4: printf("Entrez les dimensions de l'image\n");
			break;
		case 5: printf("Entrez les valeurs du monde\n");
			break;
		default: break;
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
