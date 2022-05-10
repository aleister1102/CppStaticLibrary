#pragma once
#include "Standard.h"

class State
{
private:
	bool _successful = true;
	int _errorCode = 0;
	string _message = "";

public:
	bool Successful() { return _successful; }
	int ErrorCode() { return _errorCode; }
	string Message() { return _message; }
	void setSuccessful(bool value) { _successful = value; }
	void setErrorCode(int value) { _errorCode = value; }
	void setMessage(string message) { _message = message; }
};