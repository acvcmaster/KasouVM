#ifndef LD_FILE
#define LD_FILE

struct fileInfo
{
	char* allData;
	int length;
};

fileInfo* readFile(char* name);

#define BUFFER_SIZE 2048 // 2KiB
#define NULL_CHAR_PTR (char*)0

#endif