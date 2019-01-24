#ifndef GEMINI_KEYBOARD
#define GEMINI_KEYBOARD

#include "GLFW/glfw3.h"

class Keyboard
{
public:
	static void KeyCallBack(GLFWwindow * window, int key, int scancode, int action, int mods);
	static bool Key    (int key);
	static bool KeyDown(int key);
	static bool KeyUp  (int key);

private:
	static bool keys_[];
	static bool keys_down_[];
	static bool keys_up_[];
};

#endif 
