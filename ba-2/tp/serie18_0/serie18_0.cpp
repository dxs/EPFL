#include <GL/glut.h>
#include <GL/glui.h>


namespace
{ 
    GLfloat aspect_ratio ; 
    int main_window;
    int radio_live_var;
    GLUI_RadioGroup *radio;
}

/********** User IDs pour les fonctions callback ********/
#define RADIOBUTTON_ID      100



void control_cb(int control)
{
   printf( "callback: %d\n", control );
   
   switch (control)
   {
      case (RADIOBUTTON_ID):
        printf("radio group: %d\n", radio->get_int_val() );
        printf("radio group live variable: %d\n", radio_live_var );
        break;
      default:
        printf("Not known command");
       break;
  }
} 
void affichage(void)
{

   // variables qui définissent le domaine visualisé avec Ortho
    GLfloat gauche= -1, droite = 1, bas= -1, haut= 1;
    
    glClear(GL_COLOR_BUFFER_BIT);

    // ré-initialisation de la matrice de transformation 
    glLoadIdentity();
    
     if (aspect_ratio <= 1.)
       glOrtho(gauche, droite, bas/aspect_ratio, haut/aspect_ratio, -1.0, 1.0);
    else 
       glOrtho(gauche*aspect_ratio, droite*aspect_ratio, bas, haut, -1.0, 1.0);


    glBegin(GL_POLYGON);

        glColor3f(0.0,0.0,0.0);

        glVertex2f(-0.5,-0.5);

        glColor3f(1.0,0.0,0.0);

        glVertex2f(0.5,-0.5);

        glColor3f(0.0,0.0,1.0);

        glVertex2f(0.5,0.5);

    glEnd();
 
   glutSwapBuffers();            //exchange back and front buffers
   printf("affichage\n");
}  

void reshape(int w, int h)
{
    //le viewport prend toute la fenêtre    
    glViewport(0, 0, w, h);         
   // mise à jour pour usage futur par affichage()    
   aspect_ratio = (GLfloat) w / (GLfloat) h ; 
   printf("reshape\n"); 
} 


int main(int argc, char **argv)

 {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowPosition(200, 200);

    glutInitWindowSize(250, 250);

    main_window = glutCreateWindow("exemple 1");


    /*Initialisation Open GL */

     glClearColor(1.0, 1.0, 1.0, 0.0); //pour un fond blanc;


    /* Enregistrement des fonctions de callback*/

    glutDisplayFunc(affichage);

    glutReshapeFunc(reshape);

    GLUI *glui = GLUI_Master.create_glui( "GLUI", 0, 400, 50 ); 

    radio = glui->add_radiogroup(&radio_live_var,RADIOBUTTON_ID,control_cb);
    glui->add_radiobutton_to_group( radio, "Sphere" );
    glui->add_radiobutton_to_group( radio, "Torus" );
    glui->add_radiobutton_to_group( radio, "Teapot" );

    glui->add_button( "Quit",0,(GLUI_Update_CB)exit ); 

     /*quand un widget de GLUI change, un évènement de redisplay est envoyé à la main_gfx_window */
    glui->set_main_gfx_window( main_window );


    /**** Regular GLUT main loop ****/  
   glutMainLoop();

}
