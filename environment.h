#ifndef ENVIRONMENT_H
#define ENVIRONMENT
class Environment {
	
	
	public:
	//initialize opengl stuff
	void initialize(int w, int h);
	

	//drawing and reshaping
	void draw(void);
	void reshape(int w, int h);	

	//handle keyboard
	void handleNormalKeys(unsigned char key, int x, int y);
	void handleSpecialKeys(int key, int x, int y);
};
#endif

