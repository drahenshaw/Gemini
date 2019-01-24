#include "Engine/Engine.h"
#include "Error.h"


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

	Engine *gemini = new Engine();
	gemini->StartUp("TestEngine", &myError);


}


