/**
 * \file		projet17.c / nom à modifier pour les rendus (section 4)
 * \version		0.1
 * \date		2017-10-14
 * \author		Borden 253133
 * \brief		Programme pour le projet du cours CS-111(c)
 *              le nom projet17.c est utile pour la mise au point.
 *              Pour les rendus, il faut modifier le nom du fichier comme
 *              expliqué en section 4 de la donnée (on utilise son SCIPER)
 */

// *******************************************************************
// 		inclusion de fichiers en-tête avec la directives include

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// *******************************************************************
//			   Symboles définis avec la directive define
			   

//             Symboles définies avec l'instruction enum


// *******************************************************************
//						Functions declaration

// ########   ne pas modifier ces déclarations de fonctions    #######

/**
 * \brief	Si nbSim n'est pas strictement positif
 * \param   nbSim		la valeur invalide de nbSim
 */
static void erreur_nbSim(int nbSim);

/**
 * \brief	Si la taille du monde n'est pas strictement supérieure à 1
 * \param 	n	   		la valeur invalide
 */
static void erreur_taille_monde(int n);

/**
 * \brief	Si le nombre de personnes n'est pas dans [2, n*n]
 * \param 	nbP		la valeur invalide
 * \param 	n		la taille du monde
 */

static void erreur_nbP(int nbP, int n);

/**
 * \brief	Si un indice de position ou de but n'est pas dans [0, n-1]
 * \param 	indice	             la première valeur d'indice invalide
 * \param 	indicePersonne		 l'indice de la personne dans [0, nbP-1]
 */

static void erreur_indice_ligne_colonne(int indice, int indicePersonne);

/**
 * \brief	Si deux personnes ont la même position
 * \param 	indiceP_A	l'indice de la premiere personne dans [0, nbP-1]
 * \param 	indiceP_B	l'indice de la seconde  personne dans [0, nbP-1]
 */
static void erreur_superposition(int indiceP_A, int indiceP_B);

// ############################ END ##################################

// *******************************************************************
//						Global variable

/** variable booléenne déterminant l'affichage des messages d'invitation */
static int verbose;

// *******************************************************************
//						MAIN

int main(void)
{
    scanf("%d", &verbose);
    if(verbose)
        printf("Message\n");
    int showGrid;
    scanf("%d", &showGrid);
    
    if(verbose)
        printf("Message\n");
    int nbSim;
    scanf("%d", &nbSim);
    if(nbSim <= 0)
        error_nbSim(nbSim);

    if(verbose)
        printf("Message\n");
    int tailleMonde;
    scanf("%d", &tailleMonde);
    if(tailleMonde < 2)
        error_taille_monde(tailleMonde);

    if(verbose)
        printf("Message\n");
    int nbP;
    scanf("%d", &nbP);
    if(nbP < tailleMonde*tailleMonde)
        error_nbP(nbP, tailleMonde);


	return EXIT_SUCCESS;
}


// *******************************************************************

// ################## Ne pas modifier ces fonctions ##################
//====================================================================//
//																	  //
//				***		 Fonctions d'erreurs   	***					  //
//																	  //
//					  /!\ NE PAS MODIFIER /!\						  //
//																	  //
//====================================================================//

static void erreur_nbSim(int nbSim)
{
	printf("nbSim (=%d) ne valide pas nbSim > 0 !\n", nbSim);
}

static void erreur_taille_monde(int n)
{
	printf("n (=%d) ne valide pas n > 1 !\n", n);
}

static void erreur_nbP(int nbP, int n)
{
	printf("nbP (=%d) ne valide pas nbP > 1 ET nbP <= %d !\n", nbP, n*n);
}

static void erreur_indice_ligne_colonne(int indice, int indicePersonne)
{
	printf("indice incorrect %d de ligne ou colonne de la personne d'indice %d !\n", 
	       indice, indicePersonne);
}

static void erreur_superposition(int indiceP_A, int indiceP_B)
{
	// s'assure d'avoir les indices A et B dans l'ordre croissant
	if(indiceP_B > indiceP_A) 
	{
		int temp = indiceP_A;
		indiceP_A = indiceP_B;
		indiceP_B = temp;
	}
	
	printf("les personnes d'indices %d et %d se superposent !\n", 
		   indiceP_A, indiceP_B);
}

// ############################ END ##################################
