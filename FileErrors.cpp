#include "stdafx.h"
#include "FileErrors.h"
#include <string>

using namespace std;


FileErrors::FileErrors()
{
}

FileErrors::FileErrors(int _error)
{
	if (_error == END_FILE) {
		_errorMessage = "End of file exceptions thrown";
	}
	else if (_error == OPEN_ERROR) {
		_errorMessage = "The file could not open";
	}
	else if (_error == BAD_READ_FILE) {
		_errorMessage = "The file was bad";
	}
	_errorInt = _error;
}


string FileErrors::GetErrorMessage(int error) {
	_errorInt = error;
	return _errorMessage;
}
