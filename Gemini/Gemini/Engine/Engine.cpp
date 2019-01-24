#include "Engine.h"

//Initialize Static Members
int Engine::SCREEN_WIDTH = 1024;
int Engine::SCREEN_HEIGHT = 768;
GLFWwindow * Engine::window_ = nullptr;
float Engine::dT_ = 0;

double Engine::get_dT()
{
	return dT_;
}

Engine::Engine()
{

}

Engine::~Engine()
{
	//Terminate the GLFW Library on ShutDown
	glfwTerminate();
}

bool Engine::StartUp(const char * windowTitle, Error * error)
{
	//Initialize GLFW Library on StartUp
	if (!glfwInit())
	{		
		error->set_errorName(Error::EngineErrors::kInitializationError);
		error->set_errorDescription("Error Initializing GLFW");		
		error->set_errorStatus(true);
		return false;
	}

	//Create Game Window with static width, height, and a title
	window_ = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, NULL, NULL);
	if (window_ == NULL)
	{
		error->set_errorName(Error::EngineErrors::kWindowConstructionError);
		error->set_errorDescription("Error Creating GLFW Window");
		error->set_errorStatus(true);
		return false;
	}

	//GLFW Setup
	glfwMakeContextCurrent(window_);
	int width, height;
	//Pass buffer width, height by ref to maintain changes
	glfwGetFramebufferSize(window_, &width, &height);
	//Reduce flickering - Vsync
	glfwSwapInterval(1);

	//Set Callbacks
	//
	//
	//

	
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	//Find halfway point on the screen and set window position
	int xPos = (mode->width - SCREEN_WIDTH) / 2; 
	int yPos = (mode->height - SCREEN_HEIGHT) / 2;
	glfwSetWindowPos(window_, xPos, yPos);
	
	//GL Setup
	//Attach Viewport to Window
	glViewport(0, 0, width, height);
	//Matrix Mode specifies which Matrix stack is the target for subsequent operations
	glMatrixMode(GL_PROJECTION);
	//Load Initial Matrix
	glLoadIdentity(); 
	//Camera Settings
	glOrtho(0, width, 0, height, -10, -10);
	glDepthRange(-10, 10);
	//Change GL State to MODELVIEW
	glMatrixMode(GL_MODELVIEW);

	//Alpha Blending - Blends Incoming Source RGBA with values already in frame buffer
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	prev_dT_ = (float)glfwGetTime();

	return true;
}

void Engine::Update()
{
	//Update dT and process all pending events
	float timeNow = (float)glfwGetTime();
	dT_ = timeNow - prev_dT_;
	prev_dT_ = timeNow;
	glfwPollEvents();
}

void Engine::BeginRender()
{
	//Clear back buffer with solid color
	glClearColor(0, 0, 0, 1); 
	//Bitwise OR mask to clear specified buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
}

void Engine::EndRender()
{
	//Swaps front and back buffers for the window for specified interval
	glfwSwapBuffers(window_); 
}
