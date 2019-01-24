#include "Error.h"

Error::Error()
{
	errorName_ = EngineErrors::kOK;
	errorDescription_ = "";
	errorStatus_ = false;
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

const bool Error::get_errorStatus()
{
	return errorStatus_;
}

void Error::set_errorName(const EngineErrors errorName)
{
	errorName_ = errorName;
}

void Error::set_errorDescription(const std::string errorDescription)
{
	//Setter will concatenate error descriptions in the case that more than one may be reached
	errorDescription_ += errorDescription;
}

void Error::set_errorStatus(const bool errorStatus)
{
	errorStatus_ = errorStatus;
}

bool Error::IsSet()
{
	return errorStatus_;
}

std::ostream & operator<<(std::ostream & outstream, const Error::EngineErrors value)
{	
	const char* errorString = 0;
#define CONVERT_ENUMTOSTRING(p) case(p): errorString = #p; break;
	switch (value) {
		CONVERT_ENUMTOSTRING(Error::EngineErrors::kOK);
		CONVERT_ENUMTOSTRING(Error::EngineErrors::kInitializationError);
		CONVERT_ENUMTOSTRING(Error::EngineErrors::kWindowConstructionError);
	}
#undef  CONVERT_ENUMTOSTRING

	return outstream << errorString;
	
}
