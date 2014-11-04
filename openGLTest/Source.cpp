#include <GL/glew.h>
#include <GL/freeglut.h>

using namespace std;

void display(void) {
	glClearColor(1.f, 0.f, 0.f, 1.f); // Clear the background of our window to red 
	glClear(GL_COLOR_BUFFER_BIT); //Clear the colour buffer (more buffers later on)  
	glLoadIdentity();  // Load the Identity Matrix to reset our drawing locations  
	glFlush(); // Flush the OpenGL buffers to the window  
}

void reshape(int width, int height) {
	glViewport(0, 0, (GLsizei)width, (GLsizei)height); // Set our viewport to the size of our window 
	glMatrixMode(GL_PROJECTION); // Switch to the projection matrix so that we can manipulate how our scene is viewed 
	glLoadIdentity(); // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)  
	gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0); // Set the Field of view angle (in degrees), the aspect ratio of our window, and the new and far planes 
	glMatrixMode(GL_MODELVIEW); // Switch back to the model view matrix, so that we can start drawing shapes correctly  
}

int main(int argc, char **argv) {
	glutInit(&argc, argv); // Initialize GLUT
	glutInitDisplayMode(GLUT_SINGLE); // Set up a basic display buffer (only single buffered for now)
	glutInitWindowSize(500, 500); // Set the width and height of the window  
	glutInitWindowPosition(100, 100); // Set the position of the window
	glutCreateWindow("Your first OpenGL Window"); // Set the title for the window
	
	glutDisplayFunc(display); // Tell GLUT to use the method "display" for rendering  

	glutReshapeFunc(reshape); // Tell GLUT to use the method "reshape" for rendering  
	
	glutMainLoop();
}