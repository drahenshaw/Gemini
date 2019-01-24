#ifndef GEMINI_ERROR
#define GEMINI_ERROR

#include <iostream>
#include <string>


class Error
{
public:

	 enum EngineErrors
	{
		kOK = 0,
		kInitializationError = 1,
		kWindowConstructionError = 2
	};

public:
	Error();
	~Error();

	const EngineErrors get_errorName();
	const std::string  get_errorDescription();

	void set_errorName(const EngineErrors errorName);
	void set_errorDescription(const std::string errorDescription);


private:
	EngineErrors errorName_;
	std::string errorDescription_;
};

std::ostream & operator<<(std::ostream & outstream, const Error::EngineErrors enumName);






#endif