#pragma once
#include "Standard.h"

class State
{
private:
	bool _successful = true;
	int _errorCode = 0;
	std::string _message = "";

public:
	bool Successful() { return _successful; }
	int ErrorCode() { return _errorCode; }
	std::string Message() { return _message; }
	void setSuccessful(bool value) { _successful = value; }
	void setErrorCode(int value) { _errorCode = value; }
	void setMessage(std::string message) { _message = message; }
};