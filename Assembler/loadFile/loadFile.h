#ifndef LD_FILE
#define LD_FILE

#include "errors.h"

#define NULL_CHAR_PTR (char*)0

struct fileInfo
{
	char* allData;
	int length;
	fileInfoErrorID errorID;
	public:
		static fileInfo* nullInfo();
		bool isNull();
};

fileInfo* readFile(char* name, int bufferSize);

#endif