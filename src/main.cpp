#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>
#include "environment.h"
#include "point.h"

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

void test();

int main(int argc, char **argv){
	if(argc > 1){
		test();
		return 0;
	}

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

void test(){
	cout << "testing Point..." << endl;
	
	Point p(1.2,1.3,1.4);
	cout << p.x << "," << p.y << "," << p.z << endl;

	Point q;
	cout << q.x << "," << q.y << "," << q.z << endl;

	float d = Point::dot(q,p);
	cout << "dot prod=" << d << endl;

	cout << "another =" << Point::dot(p,p) << endl;

	cout << "distance =" << Point::distance(q,p) << endl;
	
	Point x = 2.0 * p;
	Point x2 = p*2.0;
	Point x3 = Point::scale(2.0,p);
	cout << "scale = (";
	cout << x.x << "," << x.y << "," << x.z;
	cout << ") = (" << x2.x << "," << x2.y << "," << x2.z;
	cout << ") = (" << x3.x << "," << x3.y << "," << x3.z << ")" << endl;
	
	Point y = p + p;
	Point y2 = Point::add(p,p);
	cout << "add = (";	
	cout << y.x << "," << y.y << "," << y.z;
	cout << ") = (" << y2.x << "," << y2.y << "," << y2.z << ")" << endl;

	Point crs(1, 0, 0);
	Point crs2(0, 1, 0);
	Point crs3 = Point::cross(crs,crs2);
	cout << "cross = (" << crs3.x << "," << crs3.y << "," << crs3.z << ")" << endl;
	

	Point norm(2,0,0);
	cout << "norm = (" << norm.x << "," << norm.y << "," << norm.z << ")";
	norm.normalize();
	cout << " -> (" << norm.x << "," << norm.y << "," << norm.z << ")" << endl;

	cout << "magnitude=" << Point::magnitude(norm) << endl;

	cout << "angle=" << Point::angle(crs,crs2) << endl;

	Point copy(12,13,14);
	Point copy2 = copy;
	cout << copy2.x << "," << copy2.y << "," << copy2.z << endl;

	 
}
