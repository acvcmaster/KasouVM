#include <fstream>
#include <string>
#include "loadFile.h"
#include "stdlib.h"

using namespace std;

fileInfo* readFile(char* name)
{
	fileInfo* result = new fileInfo;

	char* buffer = (char*)malloc(BUFFER_SIZE);
	ifstream tFile;
	tFile.open(name);
	if( !tFile.is_open())
	{
		result->allData = NULL_CHAR_PTR;
		result->length = 0;
		return result;
	}

	int count = 0;
	while(!tFile.eof())
	{
		tFile.read(buffer + count, 1);
		count++;
	}
	
	tFile.close();
	result->allData = buffer;
	result->length = count;
	return result;
}