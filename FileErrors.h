#pragma once
#include <string>
using namespace std;
const int OPEN_ERROR = 1;
const int BAD_READ_FILE = 2;
const int END_FILE = 3;

class FileErrors
{
private:
	string _errorMessage;
	int _errorInt;
public:
	FileErrors();

	FileErrors(int _error);
	string GetErrorMessage(int _error);
};

