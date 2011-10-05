#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>
#include "environment.h"

using namespace std;

#define WINDOW_WIDTH (500)
#define WINDOW_HEIGHT (500)

////////////////////////////////////////////////////////////////////////////////
//  MAIN FUNCTION
////////////////////////////////////////////////////////////////////////////////
static int window_id;
Environment env;
char title[] = "SPACE SHOOTER";

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
	
	env.initialize(WINDOW_WIDTH,WINDOW_HEIGHT);
	glutMainLoop();


	return 0;
}
