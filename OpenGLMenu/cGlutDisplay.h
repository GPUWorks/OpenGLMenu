#ifndef GLUT_DISPLAY_H
#define GLUT_DISPLAY_H

#include<iostream>
#include <string>
#include<GL\glew.h>
#include <FG\glut.h>
#include<GLFW\glfw3.h>
//#include "cMouse.h";



#define RED 1
#define GREEN 2
#define BLUE 3
#define ORANGE 4

#define FILL 1
#define LINE 2

#define SHRINK 1
#define NORMAL 2

static int fillMenu, shrinkMenu, mainMenu, colorMenu;
static int menuFlag = 0;
static float red = 1.0f, blue = 0.5f, green = 0.5f;
static float scale = 1.0f;
static float lx = 0.0f, lz = -1.0f;

static float angle = 0.0f;
static float deltaAngle = 0.0f;
static float deltaMove = 0;
static int xOrigin = -1;
static float x = 0.0f, z = 5.0f;









using namespace std;

class GLUTDisplay
{
private:
	const GLint WIDTH = 800, HEIGHT = 600;
	//Mouse mouse;
	GLUTDisplay(const GLUTDisplay& other) {}
	GLUTDisplay & operator=(const GLUTDisplay& other) {}




public:

	
	
	static void drawSnowMan();
	GLUTDisplay(int argc, char **argv, unsigned int winWidth, unsigned int winHeight, int vpWinPosx, int vpWinPosy, int vpWidth, int vpHeight, const char * title);
	//virtual ~GLUTDisplay();
	//void SwapBuffers();
	//void Update();
	//void UpdateMouse(double &x, double &y, int & b);

	static void renderScene(void);
	static void changeSize(int w, int h);
	static void processNormalKeys(unsigned char key, int xx, int yy);
	static void pressKey(int key, int xx, int yy);
	static void releaseKey(int key, int x, int y);
	static void mouseButton(int button, int state, int x, int y);
	static void mouseMove(int x, int y);
	static void computePos(float deltaMove);



	static void processMenuStatus(int status, int x, int y) {

		if (status == GLUT_MENU_IN_USE)
			menuFlag = 1;
		else
			menuFlag = 0;
	}
	static void createPopupMenus() {


		shrinkMenu = glutCreateMenu(processShrinkMenu);

		glutAddMenuEntry("Shrink", SHRINK);
		glutAddMenuEntry("NORMAL", NORMAL);

		fillMenu = glutCreateMenu(processFillMenu);

		glutAddMenuEntry("Fill", FILL);
		glutAddMenuEntry("Line", LINE);

		colorMenu = glutCreateMenu(processColorMenu);
		glutAddMenuEntry("Red", RED);
		glutAddMenuEntry("Blue", BLUE);
		glutAddMenuEntry("Green", GREEN);
		glutAddMenuEntry("Orange", ORANGE);

		mainMenu = glutCreateMenu(processMainMenu);

		glutAddSubMenu("Polygon Mode", fillMenu);
		glutAddSubMenu("Color", colorMenu);
		// attach the menu to the right button
		glutAttachMenu(GLUT_RIGHT_BUTTON);

		// this will allow us to know if the menu is active
		glutMenuStatusFunc(processMenuStatus);
	}
	static void processMainMenu(int option) {

		// nothing to do in here
		// all actions are for submenus
	}
	static void createGLUTMenus()
	{

		int menu;

		// create the menu and
		// tell glut that "processMenuEvents" will
		// handle the events
		menu = glutCreateMenu(processMenuEvents);

		//add entries to our menu
		glutAddMenuEntry("Red", RED);
		glutAddMenuEntry("Blue", BLUE);
		glutAddMenuEntry("Green", GREEN);
		glutAddMenuEntry("Orange", ORANGE);

		// attach the menu to the right button
		glutAttachMenu(GLUT_RIGHT_BUTTON);
	}
	static void processShrinkMenu(int option) {

		switch (option) {

		case SHRINK: scale = 0.5f; break;
		case NORMAL: scale = 1.0f; break;
		}
	}
	static void processFillMenu(int option) {

		switch (option) {

		case FILL: glPolygonMode(GL_FRONT, GL_FILL); break;
		case LINE: glPolygonMode(GL_FRONT, GL_LINE); break;
		}
	}

	static void processColorMenu(int option) {

		switch (option) {
		case RED:
			red = 1.0f;
			green = 0.0f;
			blue = 0.0f; break;
		case GREEN:
			red = 0.0f;
			green = 1.0f;
			blue = 0.0f; break;
		case BLUE:
			red = 0.0f;
			green = 0.0f;
			blue = 1.0f; break;
		case ORANGE:
			red = 1.0f;
			green = 0.5f;
			blue = 0.5f; break;
		}
	}
	static void processMenuEvents(int option) {

		switch (option) {
		case RED:
			red = 1.0f;
			green = 0.0f;
			blue = 0.0f; break;
		case GREEN:
			red = 0.0f;
			green = 1.0f;
			blue = 0.0f; break;
		case BLUE:
			red = 0.0f;
			green = 0.0f;
			blue = 1.0f; break;
		case ORANGE:
			red = 1.0f;
			green = 0.5f;
			blue = 0.5f; break;
		}
	}



};

#endif //DISPLAY_H
