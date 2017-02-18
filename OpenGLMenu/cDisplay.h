#ifndef DISPLAY_H
#define DISPLAY_H
#include<iostream>
#include <string>
#include<GL\glew.h>
#include<GLFW\glfw3.h>
#include "cMouse.h";


using namespace std;

class Display
{
private:
	const GLint WIDTH = 800, HEIGHT = 600;
	MouseHM mouse;
	Display(const Display& other) {}
	Display & operator=(const Display& other) {}

	GLFWwindow* window;

	bool LMD; 

public:

	Display(unsigned int winWidth, unsigned int winHeight, int vpWinPosx, int vpWinPosy, int vpWidth, int vpHeight, const char * title, MouseHM &dmouse );
	virtual ~Display();

	void SwapBuffers();
	void Update();
	void UpdateMouse(double &x, double &y, int & b);

	//bool IsClosed();


	bool IsClosed()
	{
		return glfwWindowShouldClose(window);
	}


};

#endif //DISPLAY_H