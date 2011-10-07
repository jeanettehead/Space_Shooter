#ifndef ENVIRONMENT_H
#define ENVIRONMENT
class Environment {
	private:
	int *dim;

	void drawShips();
	void drawGameScreen(void);
	
	public:
	Environment(int vw, int vh,int w, int h);

	//initialize opengl stuff
	void initialize();
	

	//drawing and reshaping
	void draw(void);

	void reshape(int w, int h);	

	//handle keyboard
	void handleNormalKeys(unsigned char key, int x, int y);
	void handleSpecialKeys(int key, int x, int y);
};
#endif

