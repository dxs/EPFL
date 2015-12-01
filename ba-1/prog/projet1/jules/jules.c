//-------------------------------------------------------------------------------
// sciper: 262249
// nom: Brasey
// prenom: Jules
// fichier: conway.c
// date: 01.11.2015
// description du programme: projet PROG I Automne 2015-16 EPFL MT-EL
//-------------------------------------------------------------------------------

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define ZOOM_MIN 0
#define ZOOM_MAX 100
#define FAUX 0
#define NOIR 1
#define BLANC 0
//-------------------------------------------------------------------------------
//                 NE PAS MODIFIER CES PROTOTYPES DE FONCTIONS

static void erreur_nbJ(int nbJ);
static void erreur_nbS(int nbS);
static void erreur_nbJ_nbS(int nbJ, int nbS);
static void erreur_zoom(int zoom);

//-------------------------------------------------------------------------------


int main(int argc, const char * argv[]) 
{
	
	int nbJ ;
	int nbS ;
	int zoom ;
	int verbose ;
	int nbL = 0 ;
	int nbC = 0 ;
	int i = 0 ;
	int j = 0 ;
	char code_image[2] ;
	int k = 0;
	int compteur=0;
	int ever = 0;
	int l=0 ;
	int m=0;
	int compteur2 = 0;
	int compteur3 = 0;
	
	scanf("%d" , &verbose) ;
	
	if((verbose > 0))
	{
		printf("entrez le nombre de mise a jour:\n");
	}
	scanf("%d" , &nbJ) ;
	
	if  (nbJ < 0)
	{
		( erreur_nbJ(nbJ) ) ;
	}
	
	if(verbose > 0)
	{
		printf("entrez le nombre la période de sauvegarde:\n");
	}
	scanf("%d", &nbS) ;
	
	if (nbS < 0)
	{
		( erreur_nbS(nbS) ) ;
	}
		
	if (nbJ == 0 && nbS > 1)
	{
		( erreur_nbJ_nbS(nbJ,nbS) ) ;
	}
	
	if (nbS != 0)
	{	
		if (nbJ % nbS != 0)
		{
			( erreur_nbJ_nbS(nbJ,nbS) ) ;
		}
	}
		
	if(verbose > 0)
	{
		printf("entrez un zoom compris entre 1 et 100:\n") ;
	}
	scanf("%d" , &zoom) ;
	
	if (zoom <= ZOOM_MIN)
	{
		( erreur_zoom(zoom) ) ;
	}
		
	if (zoom > ZOOM_MAX)
	{
		( erreur_zoom(zoom) ) ;
	}
	
	if(verbose > 0)
	{
		printf("Donnez le code de l'image:\n") ;
	}
	scanf( "%s" , code_image );
	
	if(verbose > 0)
	{
		printf("Entrez les dimensions de l'image:\n");
	}
	scanf("%d", &nbL) ;
	scanf("%d", &nbC) ;
	
	if (nbL && nbC < 0) 
	{ 
		printf("Dimensions non valables\n") ;
			
		return EXIT_FAILURE ;
	}
	
	int valeur_monde[nbL+2][nbC+2];
	int maj[nbL+2][nbC+2];
	if(verbose > 0)
	{
	printf("Entrez les valeurs du monde:\n") ;
	}
	
	for(i=1; i < nbL+1; i++)
	{
		for(j=1; j < nbC+1; j++)
		{
			scanf("%d", &valeur_monde[i][j]) ;
				
		}
		 
	}
	


	
	//pose anneau de zéros
	
	for(i=0; i <= nbL+1; i++) valeur_monde[i][0] = FAUX; 
	for(i=0; i <= nbL + 1; i++) valeur_monde [i][nbC+1] = FAUX;
	for(j=0; j <= nbC+1; j++) valeur_monde[0][j]=FAUX;
	for(j=0; j <= nbC+1; j++) valeur_monde[nbL+1][j]=FAUX;
	
	
	//print
	printf("P1\n");
	printf("%d %d\n", zoom*nbC, ((zoom*nbL +1)* (nbJ/nbS+1))-1);
	
	for(ever=0; ever < nbJ+1; ever++)
	{
		if(ever%nbS == 0)
		{
			for(i=1; i< nbL+1; i++) //print valeur
			{
				for(m=0; m<zoom;m++)
				{
					compteur2 = 0;
					for(j=1; j< nbC+1; j++)
					{
							
						for(l=0; l<zoom;l++, compteur2++)
						{
							if(compteur2 == 30)
							{
								printf("\n");
								compteur2=0;
							}
							printf("%d ", valeur_monde[i][j]);	
						}
					}
					
					printf("\n");
				}
			}
				
			compteur2 = 0;
			if(ever < nbJ) //print ligne séparation
			{
				for(k=0; k< nbC*zoom; k++, compteur2++)
				{
					if(compteur2 == 30)
					{
						printf("\n");
						compteur2 = 0;
					}
					printf("1 ");
				}
				printf("\n");
				compteur2 = 0;
			}
		}
		
		for(i=1; i < nbL+1; i++) //analyse valeurs adjacente
		{
			for(j=1; j < nbC+1; j++)
			{
				compteur = 0;
				compteur += valeur_monde[i-1][j-1]; //haut gauche
				compteur += valeur_monde[i-1][j];
				compteur += valeur_monde[i-1][j+1];
				compteur += valeur_monde[i][j-1]; //millieu gauche
				compteur += valeur_monde[i][j+1];
				compteur += valeur_monde[i+1][j-1]; //bas gauche
				compteur += valeur_monde[i+1][j];
				compteur += valeur_monde[i+1][j+1];
				
				if (valeur_monde [i][j] == NOIR) 
				{
					if(compteur == 2 || compteur == 3) maj[i][j] = NOIR ;
				
					else maj[i][j] = BLANC ;
				}
			
				else 
				{
					if(compteur == 3) maj[i][j] = NOIR ;
				
					else maj[i][j] = BLANC ;
				}
			}
		}
		for(i=1; i < nbL+1; i++) //transfert val._monde à maj
		{
			for(j=1; j<nbC+1; j++)
			{
				valeur_monde[i][j]=maj[i][j];
			}
		} 
	}
	
	
		
		
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
