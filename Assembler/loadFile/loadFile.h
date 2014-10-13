#ifndef LD_FILE
#define LD_FILE

#define NULL_CHAR_PTR (char*)0
#define BUFFER_OVERFLOW_ERROR "The specificed buffer size is too small to contain the file. Try with a larger size (default is 2048 bytes, -b <size> to change).\n"

struct fileInfo
{
	char* allData;
	int length;
	public:
		static fileInfo* nullInfo();
		bool isNull();
};

fileInfo* readFile(char* name, int bufferSize);

#endif