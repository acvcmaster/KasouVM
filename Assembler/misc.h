#ifndef MISC
#define MISC

#define CURRENT_A_CHAR *(a + i)
#define CURRENT_B_CHAR *(b + i)

bool compareStr(char* a, char* b)
{
	int lenA = 0;
	int lenB = 0;
	for(int i = 0; CURRENT_A_CHAR != '\0'; i++)
		lenA++;
	for(int i = 0; CURRENT_B_CHAR != '\0'; i++)
		lenB++;
	if( lenA == lenB)
	{
		for(int i = 0; i < lenA; i++)
			if (CURRENT_A_CHAR != CURRENT_B_CHAR)
				return false;
		return true;
	}
	return false;
}

#endif