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
#define SIZE_FORMAT	2
#define NB_SAVE		3
#define MIN_NB_SAVE	2
#define ALIVE		1
#define DEAD		0
#define CHARMAX		34

#define CENTRE		0
#define BAS			1
#define GAUCHE		2
#define BAS_GAUCHE	3
#define DROITE		4
#define BAS_DROITE	5
#define HAUT		8
#define HAUT_GAUCHE	10
#define HAUT_DROITE	12

#define DEBUG

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

	int tabInit[val.ligne][val.colonne];
	int tabSuiv[val.ligne][val.colonne];
	int *pTabInit = (int*)tabInit;
	int *pTabSuiv = (int*)tabSuiv;
	for (i = 0; i < val.ligne; i++)
		for (j = 0; j < val.colonne; j++)
		{
			scanf("%d", &tabInit[i][j]);
#ifdef DEBUG
			printf("LECTURE :\t%d\n", tabInit[i][j]);
#endif
		}
	if (val.nbS != 0)
	{
		header(pVal);
		output(pTabInit, pVal, 0);
	}
	start(pTabInit, pTabSuiv, pVal);
}

static void analyse(int* pT1, int* pT2, struct basicVal* pVal)
{
	int i, posX, posY;
	int ligne = pVal->ligne;
	int colonne = pVal->colonne;
	for (i = 0; i < ligne * colonne; i++)
	{
		posX = i / colonne;
		posY = i % colonne;
#ifdef DEBUG
		printf("ANALYSE :\tcase = %d\t valeur = %d\tposX = %d\tposY = %d\n", i, *pT1, posX, posY);
#endif
		if ((posX > 0) && (posY > 0) && (posX < ligne-1) && (posY < colonne-1))//cas 0
			*(pT2 + i) = caseVivante(pT1, i, pVal, CENTRE);
		else
		{
			if ((posX == ligne - 1) && //cas 1
				(posY > 0) && (posY < colonne-1))
				*(pT2 + i) = caseVivante(pT1, i, pVal, BAS);

			if ((posX > 0) && (posX < ligne - 1) &&//cas 2
				(posY == 0))
				*(pT2 + i) = caseVivante(pT1, i, pVal, GAUCHE);

			if ((posX == ligne - 1) && //cas 3
				(posY == 0))
				*(pT2 + i) = caseVivante(pT1, i, pVal, BAS_GAUCHE);

			if ((posX > 0) && (posX < ligne - 1) &&// cas 4
				(posY == colonne - 1))
				*(pT2 + i) = caseVivante(pT1, i, pVal, DROITE);

			if ((posX == ligne - 1) && //cas 5
				(posY == colonne - 1))
				*(pT2 + i) = caseVivante(pT1, i, pVal, BAS_DROITE);

			if ((posX == 0) && // cas 8
				(posY > 0) && (posY < colonne - 1))
				*(pT2 + i) = caseVivante(pT1, i, pVal, HAUT);

			if ((posX == 0) && // cas 10
				(posY == 0))
				*(pT2 + i) = caseVivante(pT1, i, pVal, HAUT_GAUCHE);

			if ((posX == 0) && // cas 12
				(posY == colonne - 1))
				*(pT2 + i) = caseVivante(pT1, i, pVal, HAUT_DROITE);
		}//else end

	}//for end
}

static int caseVivante(int* tab, int position, struct basicVal* pVal, int cas)
{
	int count = 0;
	int colonne = pVal->colonne;
	tab += position;
#ifdef DEBUG
	printf("CALCUL :\tvaleur = %d\t cas = %d\n", *tab, cas);
#endif
	switch (cas)
	{
	case CENTRE :
		count += *(tab - 1 - colonne);
		count += *(tab - colonne);
		count += *(tab + 1 - colonne);
		count += *(tab - 1);
		count += *(tab + 1);
		count += *(tab - 1 + colonne);
		count += *(tab + colonne);
		count += *(tab + 1 + colonne);
#ifdef DEBUG
		printf("CALCUL :\tvaleurTab = %d\n", *(tab - 1 - colonne));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab - colonne));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab + 1 - colonne));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab - 1));		
		printf("CALCUL :\tvaleurTab = %d\n", *(tab + 1));		
		printf("CALCUL :\tvaleurTab = %d\n", *(tab - 1 + colonne));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab + colonne));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab + 1 + colonne));
#endif
		break;
	case BAS :
		count += *(tab - 1 - colonne);
		count += *(tab - colonne);
		count += *(tab + 1 - colonne);
		count += *(tab - 1);
		count += *(tab + 1);
#ifdef DEBUG
		printf("CALCUL :\tvaleurTab = %d\n", *(tab - 1 - colonne));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab - colonne));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab + 1 + colonne));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab - 1));		
		printf("CALCUL :\tvaleurTab = %d\n", *(tab + 1));
#endif
		break;
	case GAUCHE :
		count += *(tab - colonne);
		count += *(tab + 1 - colonne);
		count += *(tab + 1);
		count += *(tab + colonne);
		count += *(tab + 1 + colonne);
#ifdef DEBUG
		printf("CALCUL :\tvaleurTab = %d\n", *(tab - colonne));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab + 1 - colonne));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab + 1));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab + colonne));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab + 1 + colonne));
#endif
		break;
	case BAS_GAUCHE :
		count += *(tab - colonne);
		count += *(tab + 1 - colonne);
		count += *(tab + 1);
#ifdef DEBUG
		printf("CALCUL :\tvaleurTab = %d\n", *(tab - colonne));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab + 1 - colonne));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab + 1));
#endif
		break;
	case DROITE :
		count += *(tab - 1 - colonne);
		count += *(tab - colonne);
		count += *(tab - 1);
		count += *(tab - 1 + colonne);
		count += *(tab + colonne);
#ifdef DEBUG
		printf("CALCUL :\tvaleurTab = %d\n", *(tab - 1 - colonne));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab - colonne));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab - 1));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab - 1 + colonne));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab + colonne));
#endif
		break;
	case BAS_DROITE :
		count += *(tab - 1 - colonne);
		count += *(tab - colonne);
		count += *(tab - 1);
#ifdef DEBUG
		printf("CALCUL :\tvaleurTab = %d\n", *(tab - 1 - colonne));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab - colonne));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab - 1));
#endif
		break;
	case HAUT :
		count += *(tab - 1);
		count += *(tab + 1);
		count += *(tab - 1 + colonne);
		count += *(tab + colonne);
		count += *(tab + 1 + colonne);
#ifdef DEBUG
		printf("CALCUL :\tvaleurTab = %d\n", *(tab - 1));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab + 1));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab - 1 + colonne));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab + colonne));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab + 1 + colonne));
#endif
		break;
	case HAUT_GAUCHE :
		count += *(tab + 1);
		count += *(tab + colonne);
		count += *(tab + 1 + colonne);
#ifdef DEBUG
		printf("CALCUL :\tvaleurTab = %d\n", *(tab + 1));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab + colonne));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab + 1 + colonne));
#endif
		break;
	case HAUT_DROITE :
		count += *(tab - 1);
		count += *(tab - 1 + colonne);
		count += *(tab + colonne);
#ifdef DEBUG
		printf("CALCUL :\tvaleurTab = %d\n", *(tab - 1));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab - 1 + colonne));
		printf("CALCUL :\tvaleurTab = %d\n", *(tab + colonne));
#endif
		break;
	default:
		break;
	}
#ifdef DEBUG
	printf("CALCUL :\tCOUNT = %d\n", count);
#endif
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
#ifdef DEBUG
		printf("START :\ti = %d\n", i);
#endif
		if (i % 2 == 0)
			analyse(pT2, pT1, pVal);
		else
			analyse(pT1, pT2, pVal);

		if (pVal->nbS != 0 && i % pVal->nbS == 0)
			if (i % 2 == 0)
				output(pT1, pVal, i);
			else
				output(pT2, pVal, i);
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
#ifdef DEBUG
					printf("%d ", (i*pVal->colonne) + j);
#endif
					printf("%d ", *(tableau + (i*pVal->colonne) + j));
				}
			printf("\n");
			charcompteur = 0;
		}
}

static void header(struct basicVal * pVal)
{
#ifdef DEBUG
	printf("HEADER :\theader start\n");
#endif
	int col = pVal->colonne * pVal->zoom;
	int lig = pVal->ligne * pVal->zoom;
		lig += (pVal->nbJ / pVal->nbS) * (pVal->ligne * pVal->zoom);
		lig += pVal->nbJ / pVal->nbS;
#ifdef DEBUG
	printf("HEADER :\theader end\n");
#endif
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
