/* Serie 20 */

#include <stdio.h>
#include "liste.h"

int main ( void )
{
  ELEMENT *tete = NULL,
          *elem;

  elem = liste_ajouter ( &tete );

  elem->produit_nb = 34;
  elem->prix       = 10.95;

  liste_afficher ( tete );  

  elem = liste_ajouter ( &tete );

  elem->produit_nb = 12;
  elem->prix       = 9.95;

  liste_afficher ( tete );

  /* Retire un a un les elements de la liste
     et les detruit: */
  vider_liste ( &tete );

  liste_afficher ( tete );

  return 0;
}
