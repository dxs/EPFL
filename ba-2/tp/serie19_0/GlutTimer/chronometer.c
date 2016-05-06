#include <GL/glut.h>    
#include <GL/gl.h>	
#include <GL/glu.h>

#include <stdio.h>


// id of the GLUT window
int window; 

// Variables to count the elapsed time
int minutes = 0;
int seconds = 0;
int milliseconds = 0;

// A function to initialize OpenGL
void initGL(int window_width, int window_height)
{
	// Set the background color to black
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	

	// Set the color to draw to green.
	glColor3f(0.0, 1.0, 0.0);	

	// Set projetion matrix to identity
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 

	// Set ortographic projection values
	glOrtho(-1.,1., -1.,1., 1.,-1.);

	// Pass to the drawing mode
	glMatrixMode(GL_MODELVIEW);
}

// Resize callback. Called whenever the window is resized.
void resizeCB(int window_width, int window_height)
{
	// Set the viewport
	glViewport(0, 0, window_width, window_height);		

	// Set the projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.,1., -1.,1., 1.,-1.);

	// Pass to the drawing mode
	glMatrixMode(GL_MODELVIEW);
}


void displayCB()
{
	// Array which we use to print the time values
	static char text_buffer[256];

	// Clear the color buffer
	glClear(GL_COLOR_BUFFER_BIT);		
	glLoadIdentity();				

	// Set the position of the text on the screen
	glRasterPos2i(-0.1, -0.05);

	// Convert the time value into a character array
	sprintf(text_buffer, "%02d:%02d:%01d", minutes, seconds, milliseconds);

	// Draw text_buffer onto the screen
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, text_buffer); 

	// Swap the buffers
	glutSwapBuffers();
}

// Keyboard callback function
void keyboardCB(unsigned char key, int x, int y) 
{
	// If q is pressed, exit from the application
	if (key == 'q' || key == 'Q') 
	{ 
		// Destroy the window
		glutDestroyWindow(window); 

		exit(0);                   
	}
}

// Timer callback
void timerCB(int value)
{
	// Set the timer to 100 milliseconds.
	// It means that it will be called 10 times
	// a second.
	glutTimerFunc(100, &timerCB, 0);

	// Update the milliseconds count
	++milliseconds;

	// If elapsed milliseconds reach to 10 x 100 = 1000
	// reset it and increment seconds.
	if(milliseconds == 10)
	{
		milliseconds = 0;
		++seconds;

		// If elapsed seconds reach to 60
		// reset it and increment minutes
		if(seconds == 60)
		{
			seconds = 0;
			++minutes;
		}
	}

	// Update the display
	glutPostRedisplay();
}

int main(int argc, char **argv) 
{   
	// Initialize GLUT
	glutInit(&argc, argv);  

	// RGBA display with double buffer
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);  

	// Initialize the window size
	glutInitWindowSize(640, 480);  

	// Set the initial window position
	glutInitWindowPosition(0, 0);  

	// Create the window to draw inside
	window = glutCreateWindow("Chronometer");  

	// Use fullscreen
	glutFullScreen();

	// Register the display callback
	glutDisplayFunc(&displayCB);

	// Register the reshape callback
	glutReshapeFunc(&resizeCB);

	// Register the keyboard callback
	glutKeyboardFunc(&keyboardCB);

	// Register the timer callback
	glutTimerFunc(100, &timerCB, 0);

	// Initialize the OpenGL 
	initGL(640, 480);

	// Enter the glut main loop
	glutMainLoop();  

	return 0;
}

