#ifndef GEMINI_ENGINE
#define GEMINI_ENGINE

#include <iostream>
#include "GLFW/glfw3.h"
#include "../Error.h"

#pragma comment (lib, "opengl32.lib")

class Engine
{
public:	
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;
	static double get_dT();
		
	~Engine();

	bool StartUp(const char * windowTitle, Error * error);
	void Update();
	void BeginRender();
	void EndRender();

private:
	static GLFWwindow * window_;
	static float dT_;
	float prev_dT_;

private:
	Engine();


};




#endif 
