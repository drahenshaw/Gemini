#include "Engine/Engine.h"
#include "Error.h"
#include "Engine/IO/Keyboard.h"
#include "Engine/IO/Mouse.h"
#include "Engine/Math/Rectangle.h"

#include "Engine/Math/Math.h"


void testError(Error * error)
{
	error->set_errorName(Error::EngineErrors::kInitializationError);
	error->set_errorDescription("First time testing this error description.\n");
	error->set_errorDescription("Second time testing this error description.\n");
}

int main(void)
{
	Error myError;

	testError(&myError);

	std::cout << myError.get_errorDescription();
	std::cout << myError.get_errorName();

	Engine & gemini = gemini.get_instance();
	gemini.StartUp("TestEngine", &myError);

	while (true)
	{
		gemini.Update();
		
		if (Keyboard::KeyDown(GLFW_KEY_SPACE) == true)
		{
			std::cout << "SPACE" << std::endl;
			std::cout << Keyboard::Key(GLFW_KEY_SPACE);
		}

		if (Keyboard::KeyUp(GLFW_KEY_SPACE) == true)
		{
			std::cout << "UP" << std::endl; std::cout << Keyboard::Key(GLFW_KEY_SPACE);
		}

		
		
	}

}


