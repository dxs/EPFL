#include <stdio.h>
#include "calendrier.h"
#include "difference.h"

////////////////////////////////////////////////////////////////////////////////
int main (void)
{ 
  int jour_1, mois_1, annee_1,
    jour_2, mois_2, annee_2;
  
  printf("Ce programme calcule le nombre de jours separant deux dates.\n");
  printf("Attention: les dates doivent etre posterieures au 1er jan. 1600.\n");
  
  // Saisie de la 1ere date, tant que celle-ci n'est pas valable.
  //  
  do 
    {
      printf("Entrez la premiere date : ");
      
      scanf("%d %d %d", &jour_1, &mois_1, &annee_1);
      
      if (!date_valable(jour_1, mois_1, annee_1) || (annee_1 < 1600))
	{
	  printf("Cette date n'est pas valable!\n");
	  
	  // Vide le reste du buffer
	  //
	  while ( (getchar()) !='\n');
	}
      else
	break;     /* quitte la boucle infinie */
    } while (1);   /* boucle "infinie" */
  
  // Saisie de la 2eme date, tant que celle-ci n'est pas valable.
  //  
  do 
    {
      printf("Entrez la deuxieme date : ");
      
      scanf("%d %d %d", &jour_2, &mois_2, &annee_2);
      
      if (!date_valable(jour_2, mois_2, annee_2) || (annee_2 < 1600))
	{
	  printf("Cette date n'est pas valable!\n");
	  
	  // Vide le reste du buffer
	  //
	  while ( (getchar()) !='\n');
	}
      else
	break;
    } while (1);
  
  // Calcul et affichage du resultat.
  //  
  printf("Le nombre de jours separant ces deux dates est : ");
  
  printf("%d\n", jours_entre_deux_dates(jour_1, mois_1, annee_1,
					jour_2, mois_2, annee_2));
  
  return 0;
}
