 #include   <stdio.h>
 #include   <stdlib.h>
 #include   <string.h>
 #include   <GL/glu.h>
 #include   <GL/glut.h>

 extern   "C"  {
    #include   "graphic.h"
    #include   "chaine.h"
}

namespace {
  int main_window;

  int width, height;			/* Taille de la fenetre (en pixels) */
  float length_segment1 = 5.,		/* Longueur des segments de la chaine */
        length_segment2 = 3.,
        but_x = 3.,			/* Coordonnees du but a atteindre. */
        but_y = 6.;
}

/*-----------------------------------------------------------------*/
/* Redessine entierement le contenu du widget GLUT. */
 void  redraw_all ()
{ /* A completer (serie 17) */
    float  black [] = { 0., 0., 0. },
        white [] = { 1., 1., 1. },
        green [] = { 0., 1., 0. },
        red   [] = { 1., 0., 0. },
        yellow[] = { 1., 1., 0. },
        blue  [] = { 0., 0., 1. };

   float  alpha, beta;
   int    att;
   
   /*Efface le contenu de la fenetre*/

   /*Defini le domaine*/
 
   /*Calcul des angles*/
  
   /* Dessine les limites */
 
   /* Dessine la chaine */

   /* Dessine le but */
  
   /* Affiche l'image a l'ecran. */
   glutSwapBuffers();
}

 /*------------------------------------------------------------------*/
/*
 * widget reshape callback.  This is called by GLUT when the widget
 * has been resized.  Typically, we call glViewport.
 */
 void  reshape_cb ( int  x,  int  y)
{

  width = x;
  height = y;

  glViewport( 0, 0, width, height);
}

 /*------------------------------------------------------------------*/
/*
 * widget display callback.  This is called by GLUT when the widget's
 * contents have to be redrawn.
 */
 void  display_cb ()
{
   redraw_all();
}

 /*------------------------------------------------------------------*/



int  main( int  argc,  char * argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
  glutInitWindowPosition( 50, 50 );
  glutInitWindowSize( 400, 400 );

  main_window = glutCreateWindow(  "Serie 17-19"  );
  glutDisplayFunc( display_cb );
  glutReshapeFunc( reshape_cb );

   /* Boucle de gestion des evenements. */
   glutMainLoop();
   
   return 0;
}
