#ifndef GEMINI_MOUSE
#define GEMINI_MOUSE

#include "GLFW/glfw3.h"

class Mouse
{
public:
	static void MousePositionCallBack(GLFWwindow * window, double x_pos, double y_pos);
	static void MouseButtonCallBack  (GLFWwindow * window, int button, int action, int mods);

	static double get_mouse_x();
	static double get_mouse_y();
	
	static bool Button    (int button);
	static bool ButtonDown(int button);
	static bool ButtonUp  (int button);

private:
	static double mouse_x_;
	static double mouse_y_;

	static bool buttons_[];
	static bool buttons_down_[];
	static bool buttons_up_[];

};



#endif