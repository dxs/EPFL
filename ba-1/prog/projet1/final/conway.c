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

#define ZOOM_MAX	100
#define ZOOM_MIN	1
#define SIZE_FORMAT 2
#define NB_SAVE		3
#define MIN_NB_SAVE 2
#define ALIVE		1
#define DEAD		0
#define CHARMAX		35

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
static int caseVivante(int* tab, int position, struct basicVal* pVal, int cas);
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
	char format[SIZE_FORMAT];
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
	start(pTabInit, pTabSuiv, pVal);
}

static void analyse(int* pT1, int* pT2, struct basicVal* pVal)
{
	int i, posX, posY;
	int ligne = pVal->ligne;
	int colonne = pVal->colonne;
	for (i = 0; i < ligne * colonne; i++)
	{
		printf("i = %d\t pT1 = %d\n", i, *pT1);
		posX = i % ligne;
		posY = i / ligne;
		if (posX > 0 && (posY > 0) && (posX < colonne) && (posY < ligne))//cas 0
			*(pT2 + i) = caseVivante(pT1, i, pVal, 0);
		else
		{
			if ((posX > 0) && (posX < colonne - 1) && //cas 1
				(posY == ligne - 1))
				*(pT2 + i) = caseVivante(pT1, i, pVal, 1);

			if ((posX == 0) && //cas 2
				(posY > 0) && (posY < ligne - 1))
				*(pT2 + i) = caseVivante(pT1, i, pVal, 2);

			if ((posX == 0) && //cas 3
				(posY == ligne - 1))
				*(pT2 + i) = caseVivante(pT1, i, pVal, 3);

			if ((posX == colonne - 1) && // cas 4
				(posY > 0) && (posY < ligne - 1))
				*(pT2 + i) = caseVivante(pT1, i, pVal, 4);

			if ((posX == colonne - 1) && //cas 5
				(posY == ligne - 1))
				*(pT2 + i) = caseVivante(pT1, i, pVal, 5);

			if ((posX > 0) && (posX < colonne - 1) && // cas 8
				(posY == 0))
				*(pT2 + i) = caseVivante(pT1, i, pVal, 8);

			if ((posX == 0) && // cas 10
				(posY == 0))
				*(pT2 + i) = caseVivante(pT1, i, pVal, 10);

			if ((posX == colonne - 1) && // cas 12
				(posY == 0))
				*(pT2 + i) = caseVivante(pT1, i, pVal, 12);
		}//else end

	}//for end
}

static int caseVivante(int* tab, int position, struct basicVal* pVal, int cas)
{
	printf("VALEUR BASE = %d\n", *tab);
	int count = 0;
	int ligne = pVal->ligne;
	tab += position;
	printf("position = %d\n", *tab);

	switch (cas)
	{
	case 0: printf("Centre\n");
		break;
	case 1: printf("Bas\n");
		break;
	case 2: printf("Gauche\n");
		break;
	case 3: printf("Bas-gauche\n");
		break;
	case 4: printf("Droite\n");
		break;
	case 5: printf("Bas-droite\n");
		break;
	case 8: printf("Haut\n");
		break;
	case 10: printf("Haut-gauche\n");
		break;
	case 12: printf("Haut_droite\n");
	}

	switch (cas)
	{
	case 0 :
		count += *(tab - 1 - ligne);
		count += *(tab - ligne);
		count += *(tab + 1 - ligne);
		count += *(tab - 1);
		count += *(tab + 1);
		count += *(tab - 1 + ligne);
		count += *(tab + ligne);
		count += *(tab + 1 + ligne);
		break;
	case 1 :
		count += *(tab - 1 - ligne);
		count += *(tab - ligne);
		count += *(tab + 1 + ligne);
		count += *(tab - 1);
		count += *(tab + 1);
		break;
	case 2 :
		count += *(tab - ligne);
		count += *(tab + 1 - ligne);
		count += *(tab + 1);
		count += *(tab + ligne);
		count += *(tab + 1 + ligne);
		break;
	case 3 :
		count += *(tab - ligne);
		count += *(tab + 1 - ligne);
		count += *(tab + 1);
		break;
	case 4 :
		count += *(tab - 1 - ligne);
		count += *(tab - ligne);
		count += *(tab - 1);
		count += *(tab - 1 + ligne);
		count += *(tab + ligne);
		break;
	case 5 :
		count += *(tab - 1 - ligne);
		count += *(tab - ligne);
		count += *(tab - 1);
		break;
	case 8 :
		count += *(tab - 1);
		count += *(tab + 1);
		count += *(tab - 1 + ligne);
		count += *(tab + ligne);
		count += *(tab + 1 + ligne);
		break;
	case 10:
		count += *(tab + 1);
		count += *(tab + ligne);
		count += *(tab + 1 + ligne);
		break;
	case 12:
		count += *(tab - 1);
		count += *(tab - 1 + ligne);
		count += *(tab + ligne);
		break;
	default:
		break;
	}
	printf("COUNT = %d\n", count);
	if (*tab == 0)
		if (count == NB_SAVE)
			return ALIVE;
		else
			return DEAD;
	else
		if (count == MIN_NB_SAVE || count == NB_SAVE)
			return ALIVE;
		else
			return DEAD;
}

static void start(int* pT1, int* pT2, struct basicVal* pVal)
{
	int i;
	for (i = 1; i <= pVal->nbJ; i++)
	{
		//printf("i = %d\n", i);
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
}

static void output(int* tableau, struct basicVal* pVal, int compteur)
{
	int i, j, k, l, charcompteur = 0;
	if (compteur != 0) //imprime une ligne noire
		for (i = 0; i < pVal->colonne * pVal->zoom; i++, charcompteur++)
		{
			if (charcompteur == CHARMAX)
			{
				printf("\n");
				charcompteur = 0;
			}
			else
				printf("1 ");
		}
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
		case 0: printf("Entrez le nombre de mises � jours\n");
			break;
		case 1: printf("Entrez la p�riode d'affichage\n");
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
// Fonctions pr�d�finies pour indiquer si les donn�es sont correctes
// Les fonctions signalant une erreur provoquent la fin du programme
// en appelant exit(). Leur message d'erreur est toujours affich�.
//
//                 NE PAS MODIFIER CES FONCTIONS
//-------------------------------------------------------------------------------

// A appeler si le nombre de mises � jours n'est pas positif
static void erreur_nbJ(int nbJ)
{
	printf("Le nombre de mises � jours nbJ n'est pas positif: %d\n", nbJ);
	exit(EXIT_FAILURE);
}

// A appeler si la periode de sauvegarde n'est pas positive
static void erreur_nbS(int nbS)
{
	printf("La p�riode de sauvegarde nbS n'est pas positive: %d\n", nbS);
	exit(EXIT_FAILURE);
}

// A appeler si la periode de sauvegarde n'est pas positive
static void erreur_nbJ_nbS(int nbJ, int nbS)
{
	printf("La combinaison du nombre de mises � jour %d et de la p�riode de "
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
