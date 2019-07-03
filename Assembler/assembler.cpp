#include "assembler.h"
#include <iostream>

using namespace std;

assembler::assembler(fileInfo** _allFiles, int _fileCount)
{
	allFiles = _allFiles;
	fileCount = _fileCount;
}

void assembler::issueError(bool* e, char* errorMessage)
{
	*e = true;
	cout << errorMessage << endl;
}

bool assembler::assemble()
{
	bool errorHasOccured = false;
	cout << "assembling.." << endl;	
	return errorHasOccured;
}