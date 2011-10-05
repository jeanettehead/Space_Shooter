#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include "environment.h"

using namespace std;

void Environment::handleNormalKeys(unsigned char key, int x, int y){
	cout << "handling normal key: " << key << " at (" << x << "," << y << ")" << endl; 
}

void Environment::handleSpecialKeys(int key, int x, int y){
	cout << "handling special key: " << key << " at (" << x << "," << y << ")" << endl; 
}

void Environment::draw(void){
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}

void Environment::reshape(int w, int h){

}

void Environment::initialize(int w, int h){
	glClearColor(0.f, 0.f, 0.f, 0.f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,w,h);	
	gluOrtho2D(0,w,0,h);	
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
}

