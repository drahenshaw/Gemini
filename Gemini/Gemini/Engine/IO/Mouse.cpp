#include "Mouse.h"

//Initialize Static Members
double Mouse::mouse_x_ = 0.0;
double Mouse::mouse_y_ = 0.0;
bool   Mouse::buttons_     [GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool   Mouse::buttons_down_[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool   Mouse::buttons_up_  [GLFW_MOUSE_BUTTON_LAST] = { 0 }; 

void Mouse::MousePositionCallBack(GLFWwindow * window, double x_pos, double y_pos)
{
	int width, height;
	//Retrieve Frame Buffer Size
	glfwGetFramebufferSize(window, &width, &height); 
	mouse_x_ = x_pos;
	mouse_y_ = y_pos;
}

void Mouse::MouseButtonCallBack(GLFWwindow * window, int button, int action, int mods)
{
}

double Mouse::get_mouse_x()
{
	return 0.0;
}

double Mouse::get_mouse_y()
{
	return 0.0;
}

bool Mouse::Button(int button)
{
	return false;
}

bool Mouse::ButtonDown(int button)
{
	return false;
}

bool Mouse::ButtonUp(int button)
{
	return false;
}
