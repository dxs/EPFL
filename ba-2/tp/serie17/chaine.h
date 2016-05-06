/**
*** Fichier en-tete "chaine.h"
**/

#ifndef CHAINE_H
#define CHAINE_H

/* ------------------------------------------------------
   Cette fonction calcule les angles alpha et beta
   pour atteindre (ou essayer d'atteindre) un but (x,y).
   Elle retourne 1 si le but est atteignable, ou 0 sinon.
   Dans tous les cas, les angles alpha et beta sont calcules.
   ------------------------------------------------------
*/

int chaine_calcule_angles (float l1,
                           float l2,
                           float x,
                           float y,
                           float *alpha,
                           float *beta);

/* -----------------------------------------------------
   Cette fonction calcule le rayon minimal en dessous
   duquel un but ne pourra pas etre atteint (limite
   inferieure de l'espace atteignable par l'effecteur).
   -----------------------------------------------------
*/

float chaine_rayon_min (float l1,
                        float l2);

/* -----------------------------------------------------
   Cette fonction calcule le rayon maximal en dessus
   duquel un but ne pourra pas etre atteint (limite
   superieure de l'espace atteignable par l'effecteur).
   -----------------------------------------------------
*/

float chaine_rayon_max (float l1,
                        float l2);

/* -----------------------------------------------------
   Affiche la chaine articulee, a partir de ses
   parametres.
   -----------------------------------------------------
*/

void  chaine_dessine (float l1,
                      float l2,
                      float alpha,
                      float beta);

/* -----------------------------------------------------
   Affiche les limites de l'espace atteignable par
   l'effecteur de la chaine articulee.
   -----------------------------------------------------
*/

void chaine_dessine_limites (float l1,
                             float l2);

#endif
