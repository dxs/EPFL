 #include <GL/glut.h>

 // rapport largeur/hauteur de la fenêtre
 static GLfloat aspect_ratio = 1.f ; 

  void affichage(void)

   {
    // variables qui définissent le domaine visualisé avec Ortho
    GLfloat gauche= -1, droite = 1, bas= -1, haut= 1;
    
    glClear(GL_COLOR_BUFFER_BIT);

    // ré-initialisation de la matrice de transformation 
    glLoadIdentity();
    
    // ajustement du domaine visualisé selon la forme de la fenêtre
    // pour garantir d'avoir toujours au moins [-1, 1] selon X et Y
    // les derniers paramètres (profondeur) restent constants pour du 2D
    if (aspect_ratio <= 1.)
      glOrtho(gauche, droite, bas/aspect_ratio, haut/aspect_ratio, -1.0, 1.0);
    else 
      glOrtho(gauche*aspect_ratio, droite*aspect_ratio, bas, haut, -1.0, 1.0);

    // commandes de dessin ; ici chaque sommet a une couleur différente
    // OPENGL va interpoler les couleurs pour remplir le polygone
    glBegin(GL_POLYGON);

        glColor3f(0.0,0.0,0.0);

        glVertex2f(-0.5,-0.5);

        glColor3f(1.0,0.0,0.0);

        glVertex2f(0.5,-0.5);

        glColor3f(0.0,0.0,1.0);

        glVertex2f(0.5,0.5);

    glEnd();

    glutSwapBuffers();            //exchange back and front buffers

  }  

  void reshape(int w, int h)
  {
    //le viewport prend toute la fenêtre
    glViewport(0, 0, w, h); 
    
    // mise à jour pour usage futur par affichage()
    aspect_ratio = (GLfloat)w / (GLfloat)h ; 
  } 



   int main(int argc, char **argv)

   {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowPosition(200, 200);

    glutInitWindowSize(250, 250);
    aspect_ratio = 250/250 ;

    glutCreateWindow("exemple 1");


    /*Initialisation Open GL */

     glClearColor(1.0, 1.0, 1.0, 0.0); //pour un fond blanc; 
    //fond noir avec glClearColor(0.0, 0.0, 0.0, 0.0);

    /* Enregistrement des fonctions de rappel */

    glutDisplayFunc(affichage);

    glutReshapeFunc(reshape); 


    /*entrée dans la boucle principale de glut */

    glutMainLoop();     
    
    
    return 0;

   }
