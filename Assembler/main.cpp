#include "allIncludes.h"
#include <iostream>

#define NO_MORE_ARGS i == argc - 1
#define THIS_ARG *(argv + i)
#define VALID_OPT_LEN 4
#define STD_BUFFER_SIZE 2048

using namespace std;

char* validOptions[VALID_OPT_LEN] = {"h", "o", "b", "no_warnings"};
char* assemblyName = "a.out";
int bufferSize = STD_BUFFER_SIZE;
bool noWarnings = false;

bool isValidOption(char* option);

int main(int argc, char** argv)
{
	// Check arguments
	if( argc <= 1)
	{
		cout << INSUFFICIENT_ARGS;
		return -1;
	}
	// process command-line options
	int fileCount = 0;
	char* fileNames[argc];
	for(int i = 1; i < argc; i++)
	{
		if( *THIS_ARG == '-') // Option
		{
			char* optName;
			char* optArg = NULL_CHAR_PTR;

			if( *(THIS_ARG + 1) != '-')
			{
				// Option with argument
				if( NO_MORE_ARGS)
				{
					printf(ARGUMENT_EXPECTED, THIS_ARG);
					return -1;
				}
				optName = (THIS_ARG + 1);
				i++;
				optArg = THIS_ARG;
			}
			else
				optName = (THIS_ARG + 2);

			// Check to see if option exists
			if( !isValidOption(optName))
			{
				printf(INVALID_ARGUMENT, optName, INVALID_ARGUMENT_CONT);
				return -1;
			}

			if( compareStr(optName, validOptions[0]))
			{
				// Display help message
				if( optArg != NULL_CHAR_PTR)
				{
					cout << UNEXPECTED_ARGUMENT << UNEXPECTED_ARGUMENT_CONT;
					return -1;
				}
				cout << HELP_MESSAGE;
				return 0;
			}
			else if( compareStr(optName, validOptions[1]))
			{
				// Force name
				if( optArg == NULL_CHAR_PTR)
				{
					cout << EXPECTED_ARGUMENT;
					return -1;
				}
				assemblyName = optArg;
			}
			else if( compareStr(optName, validOptions[2]))
			{
				// Change buffer size
				if( optArg == NULL_CHAR_PTR)
				{
					cout << EXPECTED_ARGUMENT;
					return -1;
				}
				int _bufferSize = atoi(optArg);
				if( _bufferSize > 0)
					bufferSize = _bufferSize;
				else
				{
					cout << INVALID_BUFFER_SIZE;
					return -1;
				}
			}
			else if( compareStr(optName, validOptions[3]))
			{
				// suppress warnings
				if( optArg != NULL_CHAR_PTR)
				{
					cout << UNEXPECTED_ARGUMENT << UNEXPECTED_ARGUMENT_CONT;
					return -1;
				}
				noWarnings = true;
			}
		}
		else
		{
			fileNames[fileCount] = THIS_ARG;
			fileCount++;
		}
	}

	if( !noWarnings)
	{
		// Display warnings
		if( bufferSize != STD_BUFFER_SIZE)
			printf(W_NON_STANDARD_BUFFER_SIZE, bufferSize);
	}
	
	if( fileCount == 0)
	{
		cout << INSUFFICIENT_ARGS;
		return -1;
	}

	// Open files and assemble
	cout << "Assembling file '" << assemblyName << "'..\n";
	fileInfo* allFiles[fileCount];
	for(int i = 0; i < fileCount; i++)
	{
		allFiles[i] = readFile(fileNames[i], bufferSize);
		printf(OPENING_FILE, fileNames[i]);
		if( allFiles[i]->isNull())
		{
			printf(COULD_NOT_OPEN_FILE, fileNames[i]);
			return -1;
		}
		cout << "OK.\n";
	}

	// All green. Start assembling.
	assembler objectAsm(allFiles, fileCount);
	objectAsm.assemble();
	return 0;
}

bool isValidOption(char* option)
{
	for(int i = 0; i < VALID_OPT_LEN; i++)
		if(compareStr(validOptions[i], option))
			return true;
	return false;
}