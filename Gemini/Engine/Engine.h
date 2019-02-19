#ifndef GEMINI_ENGINE
#define GEMINI_ENGINE

#include <iostream>
#include "GLFW/glfw3.h"
#include "Error.h"

#pragma comment (lib, "opengl32.lib")

class Engine
{
public:	
	// Window Width & Height
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;
	// Returns change in time each frame
	static double get_dT();			
	// Return Singleton Instance Engine
	static Engine & get_instance();	
	// Initialize method for Engine - StartUp OpenGL/GLFW
	bool StartUp(const char * windowTitle, Error * error);
	// Poll Events and Calculate dT each frame
	void Update();
	// Clear Back Buffer and Begin Rendering
	void BeginRender();
	// Swap Front & Back Buffer
	void EndRender();
	// Did an exit event occur?
	bool should_window_close(); 

private:
	static GLFWwindow * window_;
	static float dT_;
	float prev_dT_;

private:
	// Hide Constructors to Enforce Singleton Pattern
	Engine() {};
	~Engine();
	Engine(Engine const&) = delete;
	void operator=(Engine const&) = delete;
};

#endif 
