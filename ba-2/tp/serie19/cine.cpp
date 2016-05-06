/* Demo OpenGL/GLUI : cinematique inverse (series 18) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glui.h>

extern "C" {
  #include "graphic.h"
  #include "chaine.h"
}

#define SEGMENT1_ID   1
#define SEGMENT2_ID   2 

// constantes qui définissent le domaine minimum selon X et Y
#define X_MIN 	-20
#define X_MAX 	 20
#define Y_MIN 	-20
#define Y_MAX	 20

namespace 
{
  // fenetre de dessin
  // identificateur entier
  int main_window; 
  // largeur et hauteur de la fenêtre 
  int width, height;
  // variables qui définissent le domaine visualisé courant avec Ortho
  GLfloat x_min, x_max, y_min, y_max;

  // interface GLUI
  GLUI *glui;
  GLUI_Spinner    *spinner1;
  GLUI_Spinner    *spinner2;
  // le widget Statictext fait clignoter la fenetre GLUI
  GLUI_EditText   *edittext ;
  GLUI_Checkbox   *checkbox ;
  int attract_var;
  
  // variable chaine articulee
  CHAINE ch2seg;
}

/*------------------------------------------------------------------*/
/*
 * widget reshape callback.  This is called when the widget
 * has been resized.  Typically, we call glViewport.
 */
void reshape_cb(int x, int y)
{
  //le viewport prend toute la fenêtre
  glViewport(0, 0, x, y); 
    
  // mémorisation pour la conversion des coordonnées souris vers OPENGL
  width = x;
  height= y;
  
  // ajustement du domaine visualisé selon la forme de la fenêtre
  // pour garantir d'avoir toujours au moins [-20,20] selon X et Y
  float aspect_ratio = (float) width / height ; 

  // à compléter série 18 : calculer ici x_min, x_max, y_min, y_max
  
  
} 

/*-----------------------------------------------------------------*/
/* mise à jour de l'affichage GLUT                                 */
/* on suppose que la structure de donnée de la ch2seg est à jour   */
 
void display_cb ()
{    	
  // à compléter série 18 
  // Mise à jour GLUI, seulement l'atteignabilité "oui" ou "non"
  // selon le booleen att de la structure CHAINE
  

  
  // mise à jour de l'affichage GLUT de dessin avec OPEN_GL
  glClearColor ( 0., 0., 0., 0. );       // specifie la couleur 
  glClear(GL_COLOR_BUFFER_BIT);

  // ré-initialisation de la matrice de transformation 
  glLoadIdentity();
    
  // projection orthographique
  // les derniers paramètres (profondeur) restent constants pour du 2D
  glOrtho(x_min, x_max, y_min, y_max, -1.0, 1.0);

  // à compléter série 18 : appeler la fonction qui dessine la chaine
  
  
  
  /* Affiche l'image a l'ecran. */
  glutSwapBuffers();
}

/*------------------------------------------------------------------*/
/* pour l'exercice 1: changement des longueurs de segments          */

void set_length_cb (int control)
{
  /* A completer (serie 18) */
  

  glutPostRedisplay();
}

/*------------------------------------------------------------------*/
void set_point_cb (int button, int button_state, int x, int y )
{
  /* A completer (serie 18) */
 

  glutPostRedisplay();
}

/*------------------------------------------------------------------*/
void set_point_motion_cb (int x, int y )
{
  /* A completer (serie 18) */
 
  
  glutPostRedisplay();
}

/*------------------------------------------------------------------*/
/* pour l'exercice 9: mise à jour du but qui est attiré vers (0,0)  */

void idle_cb()
{
  if ( glutGetWindow() != main_window)
    glutSetWindow( main_window);

  // completer ici la mise à jour conditionnelle
  /*
  if()
  {
    
    glutPostRedisplay();
  }
  * */
}
/*-------------------------------------------------------------------------*/
int main(int argc, char **argv) 
{
  // init structure de donnee de la chaine articulee ch2seg
  ch2seg.length_segment1 = 5.;
  ch2seg.length_segment2 = 2.;
  ch2seg.but_x = 3.;
  ch2seg.but_y = 6.;
  chaine_update(&ch2seg);

	
  // init GLUT
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  printf ("DEMO serie18 Microtechnique\n\n");
  
  glutInitWindowSize( 400, 400 );

  main_window = glutCreateWindow( "Serie 18" );
  glutDisplayFunc( display_cb );
  glutReshapeFunc( reshape_cb );
  
  // autres fonctions callback pour la souris 
  glutMouseFunc( set_point_cb );
  glutMotionFunc( set_point_motion_cb );

  // init interface graphique utilisateur GLUI

  glui = GLUI_Master.create_glui((char*) "GLUI", 0, 400, 50 ); 

  // interface GLUI à completer (serie 18) 






   // button Quit
   glui->add_button((char*) "Quit", 0,(GLUI_Update_CB)exit );

  
  // fonction callback pour idle mode
  
  GLUI_Master.set_glutIdleFunc(idle_cb);

  // la fen. GLUT de dessin est associée à la fen. GLUI d'interface
  // un evenement de redisplay du dessin sera envoyé automatiquement
  // apres chaque traitement d'evenement de la fenetre GLUI
  glui->set_main_gfx_window( main_window );
 

  //--------------- fin des initialisations ---------------------
  
  // boucle infinie de traitement des evenements
  glutMainLoop();

  return EXIT_SUCCESS;
}
