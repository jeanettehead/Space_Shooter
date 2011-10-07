#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>
#include "environment.h"

using namespace std;

#define WINDOW_WIDTH (500)
#define WINDOW_HEIGHT (500)
#define VIEWPORT_WIDTH (100)
#define VIEWPORT_HEIGHT (100)

////////////////////////////////////////////////////////////////////////////////
//  MAIN FUNCTION
////////////////////////////////////////////////////////////////////////////////
static int window_id;
char title[] = "SPACE SHOOTER";
Environment env(VIEWPORT_WIDTH, VIEWPORT_HEIGHT, WINDOW_WIDTH, WINDOW_HEIGHT);

void draw(void){
	env.draw();	
}

void reshape(int w, int h){
	env.reshape(w,h);
}

void handleNormalKeys(unsigned char key, int x, int y){
	env.handleNormalKeys(key,x,y);
}

void handleSpecialKeys(int key, int x, int y){
	env.handleSpecialKeys(key,x,y);	
}


int main(int argc, char **argv){
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(100, 100);
	window_id = glutCreateWindow(title);
	

	
	glutKeyboardFunc(handleNormalKeys);
	glutSpecialFunc(handleSpecialKeys);

	glutDisplayFunc(draw);
	glutReshapeFunc(reshape);
	glutIdleFunc(draw);
	
	env.initialize();
	glutMainLoop();


	return 0;
}
