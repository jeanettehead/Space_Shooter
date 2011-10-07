#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include "environment.h"

using namespace std;

/*
 * FUNCTION: Environment()
 * 	Constructs and initializes the ship lists that the Environment object
 * 	uses.
 * PARAMETERS:
 * 	int vw: the viewport width to use
 * 	int vh: the viewport height to use
 * 	int w: the screen width to use
 * 	int h: the screen height to use
 */
Environment::Environment(int vw, int vh, int w, int h){
	dim = (int*) malloc(sizeof(int) * 4);
	dim[0] = vw;
	dim[1] = vh;
	dim[2] = w;
	dim[3] = h;

}

/*
 * FUNCTION: handleNormalKeys()
 * 	handles all key events that are from ascii keys, and passes the event
 * 	along to the appropriate object that needs to know of the event.
 * PARAMETERS:
 * 	unsigned char key: key that was pressed
 * 	int x: screen x location of where the mouse position is
 * 	int y: screen y location of where the mouse position is
 */
void Environment::handleNormalKeys(unsigned char key, int x, int y){
	cout << "handling normal key: " << key << " at (" << x << "," << y << ")" << endl; 
}

/*
 * FUNCTION: handleSpecialKeys()
 * 	handles all key events that are from keys that can't be represented by
 * 	an ascii character, and passes the event along to the appropriate object
 * 	that needs to know of the event
 * PARAMETERS:
 * 	int key: non-ascii key that was pressed represented by glut enum
 * 	int x: mouse's x position on the screen
 * 	int y: mouse's y position on the screen
 */
void Environment::handleSpecialKeys(int key, int x, int y){
	cout << "handling special key: " << key << " at (" << x << "," << y << ")" << endl; 
}

/*
 * FUNCTION: draw()
 * 	calls the draw function of every ship that is in it's list. Also draws
 * 	the border of the game screen, the current score, multiplier, lives left.
 * PARAMETERS:
 * 	none
 */
void Environment::draw(void){
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	
	drawGameScreen();
	drawShips();

	
	glPopMatrix();
	glutSwapBuffers();
}

/*
 * FUNCTION: drawShips()
 *  draws all the ships that the environment knows about
 * PARAMETERS:
 * 	none
 */
void Environment::drawShips(){
	
}

/*
 * FUNCTION: drawGameScreen()
 *  draws the border of the game screen, the screen that all the ships can 
 *  be displayed in, as well as current score, multiplier, and lives left 
 * PARAMETERS:
 * 	none
 */
void Environment::drawGameScreen(){
	
}

/*
 * FUNCTION: reshape
 *  reshapes the window when the user changes the window size
 * PARAMETERS:
 * 	int w: the width of the new window
 * 	int h: the height of the new window
 */
void Environment::reshape(int w, int h){
	
}

/*
 * FUNCTION: initialize()
 *  initializes the opengl environment for the game
 * PARAMETERS:
 */
void Environment::initialize(){
	int w, h, vw, vh;
	vw = dim[0];
	vh = dim[1];
	w = dim[2];
	h = dim[3];

	glClearColor(0.f, 0.f, 0.f, 0.f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,w,h);	
	gluOrtho2D(0,vw,0,vh);	
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
}

