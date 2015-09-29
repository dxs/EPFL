//------------------------------------------------------------------------------
// sciper: 253133
// nom: Borden
// prenom: Sven
// fichier: conway.c
// date: 30.09.2015
// description du programme: projet PROG I Automne 2015-16 EPFL MT-EL
//-------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

//#define DEBUG_LVL_1

typedef int bool;
enum { false, true };

static void lecture();
static void start(int * pT1, int * pT2, int nbLig, int nbCol, int nbJ, int nbS, int zoom);
static int  caseVivante(int * tableau, int position, int nbLig, int nbCol, int cas);
static void output(int * tableau, int nbL, int nbC, int compteur, int zoom);
static void reprint(int nbPrint);
static void erreur_nbJ(int nbJ);
static void erreur_nbS(int nbS);
static void erreur_nbJ_nbS(int nbJ, int nbS);
static void erreur_zoom(int zoom);

static bool verbose;

int main(int argc, const char * argv[]) 
{
	lecture();

    return EXIT_SUCCESS ;
}

//A appeler pour commencer le programme, lecture et accueil
static void lecture()
{
	//variables
	int nbJ, nbS, nbL, nbC, zoom;
	int i, j;
	char format[2];

	//lecture des input
	scanf("%d", &verbose);
	
	reprint(0);
	scanf("%d", &nbJ);
	if(nbJ < 0)
		erreur_nbJ(nbJ);
	
	reprint(1);
	scanf("%d", &nbS);
	if(nbS < 0)
		erreur_nbS(nbS);
	if(nbJ % nbS != 0)
		erreur_nbJ_nbS(nbJ, nbS);

	reprint(2);
	scanf("%d", &zoom);
	if(zoom <= 0 || zoom > 100)
		erreur_zoom(zoom);

	reprint(3);
	scanf("%s", format);
	
	reprint(4);
	scanf("%d", &nbL);
	scanf("%d", &nbC);

	reprint(5);
	
	//output de l'entete
	int tabInit[nbL][nbC];
	int tabSuiv[nbL][nbC];
	int *pTabInit = (int*)tabInit;
	int *pTabSuiv = (int*)tabSuiv;
	for(i = 0; i < nbL; i++)
	{
		for(j = 0; j < nbC; j++)
		{
			scanf("%d", &tabInit[i][j]);
		}
	}
	
	printf("P1\n%d %d\n", nbL * zoom, zoom * (nbC * (nbJ/nbS)) + (nbJ/nbS) - 1);
	output(pTabInit, nbL, nbC, 0, zoom);
	//on commence à analyser
	//utilisation de un pointeur ou de pointeur de pointeur
	start(pTabInit, pTabSuiv, nbL, nbC, nbJ, nbS, zoom);

}


static void start(int * pT1, int * pT2, int nbLig, int nbCol, int nbJ, int nbS, int zoom)
{
	int i, k, posX, posY;

	for(k = 0; k < nbJ; k++)
	{
		posX = posY = 0;
		if(k % 2 == 0)//T1 est la base, T2 est la MaJ
		{
#ifdef DEBUG_LVL_1
			printf("\nT1\n");
#endif
			for(i = 0; i < nbLig * nbCol; i++)
			{
				posX = i % nbCol;
				posY = i / nbCol;
				if((posX > 0) && (posX < nbLig-1 ) && //cas 0
						(posY > 0) && (posY < nbCol-1))
					*(pT2 + i) = caseVivante(pT1, i, nbLig, nbCol, 0);//Maj de case i
				else
				{
					if((posX > 0) && (posX < nbLig-1) && //cas 1
							(posY == nbCol-1))
						*(pT2 + i) = caseVivante(pT1, i, nbLig, nbCol, 1);

					if((posX == 0) && //cas 2
							(posY > 0) && (posY < nbCol-1))
						*(pT2 + i) = caseVivante(pT1, i, nbLig, nbCol, 2);

					if((posX == 0) && //cas 3
							(posY == nbCol-1))
						*(pT2 + i) = caseVivante(pT1, i, nbLig, nbCol, 3);
					
					if((posX == nbLig-1) && // cas 4
							(posY > 0) && (posY < nbCol-1))
						*(pT2 + i) = caseVivante(pT1, i, nbLig, nbCol, 4);

					if((posX == nbLig-1) && //cas 5
							(posY == nbCol-1))
						*(pT2 + i) = caseVivante(pT1, i, nbLig, nbCol, 5);

					if((posX > 0) && (posX < nbLig-1) && // cas 8
							(posY == 0))
						*(pT2 + i) = caseVivante(pT1, i, nbLig, nbCol, 8);

					if((posX == 0) && // cas 10
							(posY == 0))
						*(pT2 + i) = caseVivante(pT1, i, nbLig, nbCol, 10);

					if((posX == nbLig-1) && // cas 12
							(posY == 0))
						*(pT2 + i) = caseVivante(pT1, i, nbLig, nbCol, 12);
				}//else end
			}//for end
			
			if(k%nbS == 0)
				output(pT2, nbLig, nbCol, k, zoom);
		}//if end
		else//if compteur%2 != 0, alors T1 est la MaJ et T2 est la base
		{
#ifdef DEBUG_LVL_1
			printf("\nT2\n");
#endif
			for(i = 0; i < nbLig * nbCol; i++)
			{
				posX = i % nbCol;
				posY = i / nbCol;
				if((posX > 0) && (posX < nbLig-1 ) && //cas 0
						(posY > 0) && (posY < nbCol-1))
					*(pT1 + i) = caseVivante(pT2, i, nbLig, nbCol, 0);//Maj de case i
				else
				{
					if((posX > 0) && (posX < nbLig-1) && //cas 1
							(posY == nbCol-1))
						*(pT1 + i) = caseVivante(pT2, i, nbLig, nbCol, 1);

					if((posX == 0) && //cas 2
							(posY > 0) && (posY < nbCol-1))
						*(pT1 + i) = caseVivante(pT2, i, nbLig, nbCol, 2);

					if((posX == 0) && //cas 3
							(posY == nbCol-1))
						*(pT1 + i) = caseVivante(pT2, i, nbLig, nbCol, 3);
					
					if((posX == nbLig-1) && // cas 4
							(posY > 0) && (posY < nbCol-1))
						*(pT1 + i) = caseVivante(pT2, i, nbLig, nbCol, 4);

					if((posX == nbLig-1) && //cas 5
							(posY == nbCol-1))
						*(pT1 + i) = caseVivante(pT2, i, nbLig, nbCol, 5);

					if((posX > 0) && (posX < nbLig-1) && // cas 8
							(posY == 0))
						*(pT1 + i) = caseVivante(pT2, i, nbLig, nbCol, 8);

					if((posX == 0) && // cas 10
							(posY == 0))
						*(pT1 + i) = caseVivante(pT2, i, nbLig, nbCol, 10);

					if((posX == nbLig-1) && // cas 12
							(posY == 0))
						*(pT1 + i) = caseVivante(pT2, i, nbLig, nbCol, 12);
				}//else end
			}//end for
			
			if(k%nbS == 0)
				output(pT1, nbLig, nbCol, k, zoom);
		}//end else
	}//end for (k)	
}

/*Fonction qui retourne si la case donnée est vivante.
 *int cas, représente le cas de la case à déterminer, voir doc
*/
static int caseVivante(int * tableau, int position, int nbLig, int nbCol, int cas)
{
	//%TODO
#ifdef DEBUG_LVL_2
	switch(cas)
	{
		case 0 : printf("Centre\n");
					break;
		case 1 : printf("Bas\n");
					break;
		case 2 : printf("Gauche\n");
					break;
		case 3 : printf("Bas-gauche\n");
					break;
		case 4 : printf("Droite\n");
					break;
		case 5 : printf("Bas-droite\n");
					break;
		case 8 : printf("Haut\n");
					break;
		case 10 : printf("Haut-gauche\n");
					break;
		case 12 : printf("Haut_droite\n");
	}
#endif
	int vivant = 0, countVoisin = 0;
	tableau += position;
	switch(cas)
	{
		case 0 :	countVoisin += *(tableau-1-nbCol);
					countVoisin += *(tableau-nbCol);
					countVoisin += *(tableau+1-nbCol);
					countVoisin += *(tableau-1);
					countVoisin += *(tableau+1);
					countVoisin += *(tableau-1+nbCol);
					countVoisin += *(tableau+nbCol);
					countVoisin += *(tableau+1+nbCol);
					//printf("%d", countVoisin);
					break;
		case 1 :	countVoisin += *(tableau-1-nbCol);
					countVoisin += *(tableau-nbCol);
					countVoisin += *(tableau+1-nbCol);
					countVoisin += *(tableau-1);
					countVoisin += *(tableau+1);
					//printf("%d", countVoisin);
					break; 
		case 2 : 	countVoisin += *(tableau-nbCol);
					countVoisin += *(tableau+1-nbCol);
					countVoisin += *(tableau+1);	
					countVoisin += *(tableau+nbCol);
					countVoisin += *(tableau+1+nbCol);
					//printf("%d", countVoisin);
					break;
		case 3 :	countVoisin += *(tableau-nbCol);
					countVoisin += *(tableau+1-nbCol);
					countVoisin += *(tableau+1);	
					//printf("%d", countVoisin);
					break;
		case 4 :	countVoisin += *(tableau-1-nbCol);
					countVoisin += *(tableau-nbCol);
					countVoisin += *(tableau-1);
					countVoisin += *(tableau-1+nbCol);
					countVoisin += *(tableau+nbCol);
					//printf("%d", countVoisin);
					break;
		case 5 : 	countVoisin += *(tableau-1-nbCol);
					countVoisin += *(tableau-nbCol);
					countVoisin += *(tableau-1);
					//printf("%d", countVoisin);
					break;
		case 8 :	countVoisin += *(tableau-1);
					countVoisin += *(tableau+1);
					countVoisin += *(tableau-1+nbCol);
					countVoisin += *(tableau+nbCol);
					countVoisin += *(tableau+1+nbCol);
					//printf("%d", countVoisin);
					break;
		case 10:	countVoisin += *(tableau+1);
					countVoisin += *(tableau+nbCol);
					countVoisin += *(tableau+1+nbCol);
					//printf("%d", countVoisin);
					break;
		case 12:	countVoisin += *(tableau-1);
					countVoisin += *(tableau-1+nbCol);
					countVoisin += *(tableau+nbCol);
					//printf("%d", countVoisin);
	}
	if(*tableau == 0)
	{
		if(countVoisin == 3)
		{
			vivant = 1;
		}
	}
	else
	{
		if(countVoisin == 3 || countVoisin == 2)
		{
			vivant = 1; 
		}
	}
	tableau -= position;
	return vivant;
}

static void output(int * tableau, int nbL, int nbC, int compteur, int zoom)
{
	int i, j, k, l, depassement = 0;
	
	//if(compteur != 0)//ligne noire
	//{
		for(i=0; i < nbC * zoom; i++)
		{
			if(depassement==70)
			{		
				printf("\n");
				depassement=0;
			}
			printf("1");
			depassement++;
		}
		printf("\n");
	//}
	
	depassement = 0;
	for(i = 0; i < nbL; i++)
		for(k = 0; k < zoom; k++)
		{
			for(j = 0; j < nbC; j++)
				for(l = 0; l < zoom; l++)
				{
					if(depassement==70)
					{
						printf("\n");
						depassement = 0;
					}
					depassement++;
					printf("%d", *(tableau + (i*nbL) + j));
				}
			printf("\n");
			depassement=0;
		}
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
