#ifndef ASSEMBLER
#define ASSEMBLER

#include "loadFile/loadFile.h"

class assembler
{
	fileInfo** allFiles;
	int fileCount;
	public:
		assembler(fileInfo**, int);
		bool assemble();
		static void issueError(bool*, char*);
};

#endif