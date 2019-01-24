#include "Error.h"

Error::Error()
{
	errorName_ = EngineErrors::kOK;
	errorDescription_ = "";
}

Error::~Error()
{

}

const Error::EngineErrors Error::get_errorName()
{
	return errorName_;
}

const std::string Error::get_errorDescription()
{
	return errorDescription_;
}

void Error::set_errorName(const EngineErrors errorName)
{
	errorName_ = errorName;
}

void Error::set_errorDescription(const std::string errorDescription)
{
	errorDescription_ = errorDescription;
}

std::ostream & operator<<(std::ostream & outstream, const Error::EngineErrors value)
{	
	const char* errorString = 0;
#define CONVERT_VALUE(p) case(p): errorString = #p; break;
	switch (value) {
		CONVERT_VALUE(Error::EngineErrors::kOK);
		CONVERT_VALUE(Error::EngineErrors::kInitializationError);
		CONVERT_VALUE(Error::EngineErrors::kWindowConstructionError);
	}
#undef  CONVERT_VALUE

	return outstream << errorString;
	
}
