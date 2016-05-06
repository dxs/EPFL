#include <stdlib.h>
#include <stdio.h>

// symboles et type pour codes d'erreurs
enum Erreur_lecture {LECTURE_ARG, LECTURE_OUVERTURE, 
					 LECTURE_NB0, LECTURE_LIVREUR,
					 LECTURE_NB1, LECTURE_VEHICULE,
					 LECTURE_NB2, LECTURE_LIVRAISON,
					 LECTURE_FIN, LECTURE_ETAT};
					 
typedef enum Erreur_lecture ERREUR_LECTURE;
								
// prototypes
void lecture(char * nom_fichier);
void decodage_ligne(char * tab);
void erreur(ERREUR_LECTURE code);

// lit le fichier dont le nom est transmis sur la ligne de commande
int main(int argc, char * argv[])
{
  if(argc != 2) erreur(LECTURE_ARG);
	
  lecture(argv[1]);

  return EXIT_SUCCESS;
}

// traite le fichier ligne par ligne.  
void lecture( char * nom_fichier)
{
  char tab[80];
  FILE * fichier = NULL; 

  if((fichier = fopen (nom_fichier, "r")) != NULL) 
  {
    while(fgets(tab,80,fichier)) 
    {
      if((tab[0]=='#')||(tab[0]=='\n')||(tab[0]=='\r'))
        continue;  // lignes à ignorer, on passe à la suivante
       
	  decodage_ligne(tab);	  
    }
    printf("fin de la lecture\n");
  }
  else erreur(LECTURE_OUVERTURE);
}

// décodage selon l'etat courant d'une ligne lue dans le fichier 
// met à jour l'etat
void decodage_ligne(char * tab)
{
  // états de l'automate de lecture					 
  enum Etat_lecture {NB0,LIVREUR,NB1,VEHICULE,NB2,LIVRAISON,FIN};
  
  static int etat = NB0; // état initial
  static int i, total;
  int disp, num;
  char nom[40];

  switch(etat) 
  {
  case NB0: 
	if(sscanf(tab,"%d", &total) !=1) erreur(LECTURE_NB0); 
	else i=0 ;
	
	if(total==0) etat=NB1; else etat=LIVREUR ; 
	printf("Nb de livreurs: %d\n",total); break;

  case LIVREUR: 
	if(sscanf(tab,"%39s %d", nom, &disp) != 2) erreur(LECTURE_LIVREUR);
	else ++i;
	
	if(i == total) etat=NB1 ;
	printf("Livreur %d: %s \t %d\n",i, nom, disp); break;

  case NB1: 
	if(sscanf(tab,"%d", &total) !=1) erreur(LECTURE_NB1); 
	else i=0 ;
	
	if(total==0) etat=NB2; else etat=VEHICULE ; 
	printf("Nb de véhicules: %d\n",total); break;

  case VEHICULE: 
	if(sscanf(tab,"%d %d", &num, &disp) != 2) erreur(LECTURE_VEHICULE);
	else ++i;
	
	if(i == total) etat=NB2 ;
	printf("Vehicule %d: %d \t %d\n",i, num, disp); break;

  case NB2: 
	if(sscanf(tab,"%d", &total) !=1) erreur(LECTURE_NB2); 
	else i=0;
	
	if(total==0) etat=FIN; else etat=LIVRAISON ; 
	printf("Nb de livraisons: %d\n",total); break;

  case LIVRAISON: 
	if(sscanf(tab,"%39s %d", nom, &num) != 2) erreur(LECTURE_LIVRAISON);
	else ++i;
	
	if(i == total) etat=NB2 ;
	printf("Livraison %d: %s \t %d\n",i, nom, num); break;

  case FIN: erreur(LECTURE_FIN) ; break;

  default: erreur(LECTURE_ETAT);
  }	
}

// affiche un message d'erreur puis quitte le programme
void erreur(ERREUR_LECTURE code)
{
  switch(code)
  {
	case LECTURE_ARG : printf(" nom de fichier manquant\n");  break;
	case LECTURE_OUVERTURE: printf(" ouverture impossible\n");break;
	case LECTURE_NB0 : 
	case LECTURE_NB1 : 
	case LECTURE_NB2 : 
	case LECTURE_LIVREUR : 
	case LECTURE_VEHICULE : 
	case LECTURE_LIVRAISON : printf(" lecture impossible \n");
	case LECTURE_FIN : printf(" format non respecté \n");     break;
	case LECTURE_ETAT : printf(" etat inexistant\n");         break;
	default: printf(" erreur inconnue\n");
  }
  exit(EXIT_FAILURE);
}
