//
//  main.c
//  projet prog I
//
//  Created by Demeure Eugénie on 15.10.15.
//  Copyright © 2015 Demeure Eugénie. All rights reserved.
//
//-------------------------------------------------------------------------------
// sciper: 261984
// nom: Demeure
// prenom: Eugénie
// fichier: conway.c
// date: 30.10.2015
// description du programme: projet PROG I Automne 2015-16 EPFL MT-EL
//-------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NBJ_MIN 0
#define NBS_MIN 0
#define ZOOM_MIN 0
#define ZOOM_MAX 100
#define NB_CHAR 100
#define MAX_CHAR 35
#define FAUX 0
#define VIVANT 1
#define MORT 0
#define VOISINS3 3
#define VOISINS2 2

//#define DEBUG1
//#define DEBUG2
//#define SVEN

/*struct baseValeur
 {
 int nbJ;
 int nbS;
 char a;
 //par ex. permet de "remplacer" un tableau
 };*/

int verbose = FAUX;

//-------------------------------------------------------------------------------
//                 NE PAS MODIFIER CES PROTOTYPES DE FONCTIONS

static void erreur_nbJ(int nbJ);
static void erreur_nbS(int nbS);
static void erreur_nbJ_nbS(int nbJ, int nbS);
static void erreur_zoom(int zoom);
//-------------------------------------------------------------------------------
static void initialisation(int *ptr_nbJ, int *ptr_nbS, int *ptr_zoom);

static void impression(int zoom, int nbL, int nbC, int etape,
                       int tab_maj[nbL + 2][nbC + 2]);

static void mise_a_jour(int nbJ, int nbS, int nbL, int nbC, int zoom,
                        int tab_initial[nbL + 2][nbC + 2]);

static int tab_a_jour(int i, int j, int nbL, int nbC,
                      int tab_initial[nbL + 2][nbC + 2]);

static void en_tete(int nbL, int nbC, int zoom, int nbJ, int nbS);

int main(int argc, const char * argv[])
{
    int nbL = 0, nbC = 0;
    int i = 0, j = 0;
    int nbJ = 0, nbS = 0, zoom = 0;
    int *ptr_nbJ = &nbJ, *ptr_nbS = &nbS, *ptr_zoom = &zoom;
    
    /*struct baseValeur val;
     val.nbJ;
     struct baseValeur *val_2;
     val_2->nbS;*/
    
    scanf("%d", &verbose);
    
    initialisation(ptr_nbJ, ptr_nbS, ptr_zoom);
    zoom = *ptr_zoom;
    
#ifdef DEBUG1
    printf("nbS = %d et nbJ = %d\n", nbS, nbJ);
#endif
    
    if (verbose)
    {
        printf("Entrez le nombre de colonnes et le nombre de lignes\n");
    }
    scanf("%d %d", &nbC, &nbL);
    
    int tab_initial[nbL + 2][nbC + 2];
    for(i = 0; i < nbL+2; i++)
        for(j = 0; j < nbC + 2; j++)
            tab_initial[i][j] = 0;
    
    if (verbose)
    {
        printf("Entrez la valeur de la case à la ligne "
               "et à la colonne du tableau\n");
    }
    for (i = 1; i < nbL + 1; i++)
    {
        for (j = 1; j < nbC + 1; j++)
        {
            scanf("%d", &tab_initial[i][j]);
        }
    }
    
    mise_a_jour(nbJ, nbS, nbL, nbC, zoom, tab_initial);
    
    return EXIT_SUCCESS;
}

static void mise_a_jour(int nbJ,int nbS, int nbL, int nbC, int zoom,
                        int tab_initial[nbL + 2][nbC + 2])
{
    int i = 0, j = 0;
    int etape = 0;
    int tab_maj[nbL + 2][nbC + 2];
    
    en_tete(nbL, nbC, zoom, nbJ, nbS);
    impression(zoom, nbL, nbC, etape, tab_initial);
    
    for (etape = 1; etape <= nbJ; etape++)
    {
        for (i = 1; i < nbL+1; i++)
        {
            for (j = 1; j < nbC+1; j++)
            {
                tab_maj[i][j] = tab_a_jour(i, j, nbL, nbC, tab_initial);
            }
        }
        
        //transfert de val tabInit->tabMaj
        for (i = 1; i < nbL + 1; i++)
        {
            for (j = 1; j < nbC + 1; j++)
            {
                tab_initial[i][j] = tab_maj[i][j];
            }
        }
        
        if (etape % nbS == 0)
        {
            impression(zoom, nbL, nbC, etape, tab_initial);
        }
    }
}

static int tab_a_jour (int i, int j, int nbL, int nbC,
                       int tab_initial[nbL + 2][nbC + 2])
{
    int total = 0;
    total += tab_initial[i - 1][j - 1];
    total += tab_initial[i - 1][j];
    total += tab_initial[i - 1][j + 1];
    total += tab_initial[i][j - 1];
    total += tab_initial[i][j + 1];
    total += tab_initial[i + 1][j - 1];
    total += tab_initial[i + 1][j];
    total += tab_initial[i + 1][j + 1];
    
    if (tab_initial[i][j] == 0)
        return (total == VOISINS3) ? VIVANT : MORT;
    else
        return (total == VOISINS2 || total == VOISINS3) ? VIVANT : MORT;
}

static void impression(int zoom, int nbL, int nbC, int etape,
                       int tab_maj[nbL + 2][nbC + 2])
{
    int i = 0, j = 0, k = 0, l = 0;
    int compteur = 0, un = 1;
    
    if (etape != 0)
    {
        for (i = 0; i < nbC*zoom; i++)
            printf("%d ", un);
        printf("\n");
    }
    
    for (i = 1; i < nbL+1; i++)
        for (k = 0; k < zoom; k++)
        {
            for (j = 1; j < nbC+1; j++)
                for (l = 0; l < zoom; l++, compteur++)
                {
                    if (compteur == MAX_CHAR)
                    {
                        printf("\n");
                        compteur = 0;
                    }
                    printf("%d ", tab_maj[i][j]);
                }
            printf("\n");
	    compteur = 0;
        }
}

static void en_tete(int nbL, int nbC, int zoom, int nbJ, int nbS)
{
    printf("P1\n%d %d\n", nbC*zoom, (nbL*zoom)*(nbJ/nbS+1)+(nbJ/nbS));
}

static void initialisation(int *ptr_nbJ, int *ptr_nbS, int *ptr_zoom)
{
    char format[NB_CHAR] = {0};
    int nbJ = 0, nbS = 0, zoom = 0;
    
    if (verbose)
    {
        printf("Entrez le nombre de mises à jour et l'intervalle de "
               "sauvegarde de l'état du jeu\n");
    }
    scanf("%d %d", ptr_nbJ, ptr_nbS);
    nbJ = *ptr_nbJ;
    nbS = *ptr_nbS;
    if (nbJ < NBJ_MIN)
    {
        erreur_nbJ(nbJ);
    }
    
    if (nbS < NBS_MIN)
    {
        erreur_nbS(nbS);
    }
    
    //détection des cas interdits de combinaison entre nbJ et nbS
    if ((nbJ == 0 && nbS != 0 && nbS != 1) ||
        (nbJ > NBJ_MIN && nbS > NBS_MIN && nbJ%nbS != 0))
    {
        erreur_nbJ_nbS(nbJ, nbS);
    }
    
    
    if (verbose)
    {
        printf("Entrez l'agrandissement de l'image voulu "
               "pour l'affichage en sortie\n");
    }
    scanf("%d", ptr_zoom);
    zoom = *ptr_zoom;
    
    if (zoom <= ZOOM_MIN || zoom > ZOOM_MAX)
    {
        erreur_zoom(zoom);
    }
    
    
    if (verbose)
    {
        printf("Entrez le format de l'image\n");
    }
    scanf("%s", format);
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
