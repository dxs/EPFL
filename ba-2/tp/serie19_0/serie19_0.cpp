#include <stdlib.h>
#include <GL/glut.h>


#define RED 1
#define GREEN 2
#define BLUE 3
#define WHITE 4


namespace {
  float red=1.0, blue=1.0, green=1.0;
  float width,height;
}


void changeSize(int w, int h) {


	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0)
		h = 1;

	// we're storing these values for latter use in the 
	// mouse motion functions
	width = w;
	height = h;
	float ratio = 1.0* w / h;

	// Reset the coordinate system before modifying
	glLoadIdentity();
	
	// Set the viewport to be the entire window
        glViewport(0, 0, w, h);

        if (w <= h)
          gluOrtho2D(-1.0, 1.0, -1.0 * (GLfloat) h / (GLfloat) w, 1.0 * (GLfloat) h / (GLfloat) w);
        else 
          gluOrtho2D(-1.0 * (GLfloat) w / (GLfloat) h, 1.0 * (GLfloat) w / (GLfloat) h, -1.0, 1.0);
}

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(red,green,blue);

	glBegin(GL_TRIANGLES);
		glVertex3f(-0.5,-0.5,0.0);
		glVertex3f(0.5,0.0,0.0);
		glVertex3f(0.0,0.5,0.0);
	glEnd();

	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y) 
{        
    switch(key)
    {
    case 27: //quitte le programme en frappant la touche "Esc"
      exit(0);
    case 'r':
          red = 1.0; 
          green = 0.0; 
          blue = 0.0; 
          break;
    case 'g' : 
          red = 0.0; 
          green = 1.0; 
          blue = 0.0; 
          break;
    case 'b' : 
          red = 0.0; 
          green = 0.0; 
          blue = 1.0; 
          break;
    }
}

void processSpecialKeys(int key, int x, int y) 
{
    switch(key)
   {
      case GLUT_KEY_F1 : 
                red = 1.0; 
                green = 0.0; 
                blue = 0.0; 
                break;
      case GLUT_KEY_F2 : 
                red = 0.0; 
                green = 1.0; 
                blue = 0.0; 
                break;
      case GLUT_KEY_F3 : 
                red = 0.0; 
                green = 0.0; 
                blue = 1.0; 
		break;
    }
}

void processMouse(int button, int state, int x, int y) 
{
  if (state == GLUT_DOWN)
  {
    if (button == GLUT_LEFT_BUTTON)
    {
      red = 1.0; green = 0.0; blue = 0.0;
    } else if (button == GLUT_MIDDLE_BUTTON)
    {
      red = 0.0; green = 1.0; blue = 0.0;
    } else 
    {
      red = 0.0; green = 0.0; blue = 1.0;
    }
  }
} 
void processMouseActiveMotion(int x, int y) 
{  
  if (x < 0)
    red = 0.0;
  else if (x > width)
    red = 1.0;
  else
    red = ((float) x)/width;
}


int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(320,320);
    glutCreateWindow("Example 19_0");
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutKeyboardFunc(processNormalKeys);

    //Callbacks
   glutKeyboardFunc(processNormalKeys);
   glutSpecialFunc(processSpecialKeys);
   glutMouseFunc(processMouse);
   glutMotionFunc(processMouseActiveMotion);  

    glutMainLoop();

   return EXIT_SUCCESS;
}
