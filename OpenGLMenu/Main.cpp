#include <iostream>
#define GLEW_STATIC
#include<stdio.h>
#include<stdlib.h>
#include <GL\glew.h>
#include "cDisplay.h"
#include"cShader.h"
#include"cMesh.h"
#include"cPopMenu.h"
#include <GLFW\glfw3.h>
#include"cGlutDisplay.h";
using namespace std;

int main()//(int argc, char **argv)
{

	


	MouseHM mouse;
	//GLUTDisplay GLUTD(argc, argv, 800, 800, 0, 400, 400, 400, "VACCUM");
	//GLUTD.createGLUTMenus();
	//glutMainLoop();


	//(unsigned int winWidth, unsigned int winHeight, int vpWinPosx, int vpWinPosy, int vpWidth, int vpHeight, const char * title, Mouse &dmouse);
	Display display(800,800 , 0, 400, 400, 400, "VACCUM", mouse);

	Vertex vertices1[] =
	{
		Vertex(-0.5f, 0.5f, 0.0f), // Top-left
		Vertex(0.5f, 0.5f, 0.0f),// 1.0f, 0.0f, // Top-right
		Vertex(0.5f, -0.5f, 0.0f)//, 1.0f, 1.0f  // Bottom-left
	};

	Vertex vertices2[] =
	{
		Vertex(-0.5f, 0.5f, 0.0f), // Top-left
		Vertex(-0.5f,- 0.5f, 0.0f),// 1.0f, 0.0f, // Top-right
		Vertex(0.5f, -0.5f, 0.0f)//,// 0.0f, 1.0f, // Bottom-right

	};


	Vertex vertices3[] =
	{
		Vertex(-0.5f, 0.5f, -0.1f), 
		Vertex(-0.5f,-0.5f, -0.1f),
		Vertex(0.5f, -0.5f, -0.1f),
		Vertex(0.5f,  0.5f, -0.1f)
							
	};
	Mesh mesh1(vertices1, (sizeof(vertices1) / sizeof(vertices1[0])) );
	Mesh mesh2(vertices2, (sizeof(vertices2) / sizeof(vertices2[0])));
	Mesh mesh3(vertices3, (sizeof(vertices3) / sizeof(vertices3[0])));

	//SHADERS
	string shaderFiles = "./res/basicShader";
	Shader shader(shaderFiles);


	double x = 0;
	double y = 0;
	int b;


	

	/////////////////////////////////////////////////////////////////////
	while (!display.IsClosed())
	{
		display.Update();		
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		{//WHERE ALL THINGS WILL BE
			display.UpdateMouse(x, y, b);
			
			shader.Bind();
			//mesh1.Draw();
			//mesh2.Draw();
			mesh3.Draw();
		}
			
		display.SwapBuffers();
	}

	return 0;
}



