#include "Keyboard.h"
#include <iostream>

//Initialize Static Members
bool Keyboard::keys_     [GLFW_KEY_LAST] = { 0 };
bool Keyboard::keys_down_[GLFW_KEY_LAST] = { 0 };
bool Keyboard::keys_up_  [GLFW_KEY_LAST] = { 0 };

//Provides Keyboard Input to the Engine
void Keyboard::KeyCallBack(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	//Invalid Key Press
	if (key < 0) return;
	//Key Press
	if (action != GLFW_RELEASE && keys_[key] == false)
	{
		keys_down_[key] = true;
		keys_up_  [key] = false;
	}
	//Key Release
	if (action == GLFW_RELEASE && keys_[key] == true )
	{
		keys_down_[key] = false;
		keys_up_  [key] = true;
	}

	//Toggle Key Array Status
	keys_[key] = action != GLFW_RELEASE;
}

//Gets Key Status
bool Keyboard::Key(int key)
{
	return keys_[key];
}

//Tests for KeyDown and sets false after
bool Keyboard::KeyDown(int key)
{
	bool state = keys_down_[key];
	keys_down_[key] = false;
	return state;
}

//Tests for KeyUp and sets false after
bool Keyboard::KeyUp(int key)
{
	bool state = keys_up_[key];
	keys_up_[key] = false;
	return state; 
}
