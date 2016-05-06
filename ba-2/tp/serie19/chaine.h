/**
*** Fichier en-tete "chaine.h"
**/

#ifndef CHAINE_H
#define CHAINE_H

#define BUT_ATTEINT     1
#define BUT_PAS_ATTEINT 0
#define EPSIL_SEGMENT 1e-4     // longueur minimum d'un segment

/* ------------------------------------------------------
   création d'un type CHAIN
   ce type est "concret" car on montre le modèle de la
   structure struct chain dans l'interface du module.
   D'un coté cela permet à main.cpp d'accéder aux champs
   de la structure mais de l'autre on manque de garanties
   de robustesse sur l'usage de variables de type CHAIN.
   Le cours introduira la notion de type "opaque" pour 
   résoudre ce problème.
   ------------------------------------------------------
*/
 
typedef struct chaine CHAINE;
  
struct chaine
{
    float length_segment1;	/* Longueur des segments de la chaine */
    float length_segment2;
    float but_x;			/* Coordonnees du but a atteindre. */ 
    float but_y;
    float alpha;
    float beta;
    int att;
};

/* ------------------------------------------------------
   Cette fonction met à jour la structure CHAIN pointée par p.
   Cela comprend les angles alpha et beta pour atteindre 
   (ou essayer d'atteindre) le but (x,y) mémorisé dans la structure.
   le champ att est mis à 1 si le but est atteignable, ou 0 sinon.
   ------------------------------------------------------
*/
  
void chaine_update(CHAINE *p);

/* -----------------------------------------------------
   Affiche complet: chaine, limite et but
   -----------------------------------------------------
*/
void chaine_display(CHAINE chaine);


#endif
