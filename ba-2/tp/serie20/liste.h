/**
*** Fichier en-tete "liste.h"
**/

#ifndef LISTE_ELEMENT_H
#define LISTE_ELEMENT_H

typedef struct element ELEMENT;

struct element {

  int    produit_nb;

  float  prix;

  ELEMENT * suivant;

};

/*-----------------------------------------------*/

ELEMENT * liste_ajouter (ELEMENT **tete);

void      liste_retirer (ELEMENT **tete,
                         ELEMENT *el);

void      liste_afficher (ELEMENT *tete);

void vider_liste ( ELEMENT ** p_liste );

#endif
