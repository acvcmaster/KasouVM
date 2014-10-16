#include <fstream>
#include <string>
#include <iostream>
#include "loadFile.h"
#include "errors.h"
#include "stdlib.h"

using namespace std;

fileInfo* fileInfo::nullInfo()
{
	fileInfo* result = new fileInfo;
	result->allData = NULL_CHAR_PTR;
	result->length = 0;
	return result;
}

bool fileInfo::isNull()
{
	return allData == NULL_CHAR_PTR;
}

fileInfo* readFile(char* name, int bufferSize)
{
	fileInfo* result = fileInfo::nullInfo();
	result->errorID = fileInfoErrorID::OTHER;
	char* buffer = (char*)malloc(bufferSize);
	ifstream tFile;
	tFile.open(name);
	if( !tFile.is_open())
		return result;

	int count = 0;
	while(!tFile.eof())
	{
		if( count == bufferSize)
		{
			result->errorID = fileInfoErrorID::BUFFER_SIZE_TOO_SMALL;
			return result;
		}
		tFile.read(buffer + count, 1);
		count++;
	}

	tFile.close();
	result->allData = buffer;
	result->length = count;
	return result;
}