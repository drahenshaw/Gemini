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
	//Invalid Mouse Button
	if (button < 0) return;
	//Button Press
	if (action != GLFW_RELEASE && buttons_[button] == false)
	{
		buttons_down_[button] = true;
		buttons_up_  [button] = false;
	}
	//Button Release
	if (action == GLFW_RELEASE && buttons_[button] == true)
	{
		buttons_down_[button] = false;
		buttons_up_  [button] = true;
	}

	//Toggle Button Array Status
	buttons_[button] = action != GLFW_RELEASE;
}

double Mouse::get_mouse_x()
{
	return mouse_x_;
}

double Mouse::get_mouse_y()
{
	return mouse_y_;
}

//Gets Button Status
bool Mouse::Button(int button)
{
	return buttons_[button];
}

//Tests for ButtonDown and sets false after
bool Mouse::ButtonDown(int button)
{
	bool state = buttons_down_[button];
	buttons_down_[button] = false;
	return state;
}

//Tests for ButtonUp and sets false after
bool Mouse::ButtonUp(int button)
{
	bool state = buttons_up_[button];
	buttons_up_[button] = false;	
	return state;
}
