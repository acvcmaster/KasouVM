#include "allIncludes.h"
#include <iostream>

#define NO_MORE_ARGS i == argc - 1
#define THIS_ARG *(argv + i)
#define VALID_OPT_LEN 2

using namespace std;

char* validOptions[VALID_OPT_LEN] = {"h", "o"};
char* assemblyName = "a.out";

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
			char* optArg;
			if( *(THIS_ARG + 1) != '-')
			{
				// Option with argument
				if( NO_MORE_ARGS)
				{
					cout << ARGUMENT_EXPECTED 
						<< "'" << THIS_ARG << "'." << endl;
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
				cout << INVALID_ARGUMENT << "'"
					<< optName << "'." << INVALID_ARGUMENT_CONT << endl;
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
		}
		else
		{
			fileNames[fileCount] = THIS_ARG;
			fileCount++;
		}
	}
	if( fileCount == 0)
	{
		cout << INSUFFICIENT_ARGS;
		return -1;
	}

	// Open files and assemble
	cout << "Assembling file '" << assemblyName << "'..\n";
	return 0;
}

bool isValidOption(char* option)
{
	for(int i = 0; i < VALID_OPT_LEN; i++)
		if(compareStr(validOptions[i], option))
			return true;
	return false;
}