#include "cstringdiff.h"
#include <iostream>
#include <cstring>

// copies a string in buffer and returns a pointer to the copy in memory
char* CopyString (const char* buffer)
{
	size_t size = strlen(buffer);
	char* cptr = new char [1 + size];
	strcpy(cptr,buffer);
	cptr [size] = '\0';
	return cptr;
}

int  LexDiff(const char* s1, const char* s2)
{
	return strcmp(s1, s2); // return de diff value of the ascii table
};

bool LexComp(const char* s1, const char* s2)
{
	//    std::cout << "lexComp\n";
	
	if ( LexDiff(s1, s2) < 0 ) // if lexdiff returns a -ve value then true
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

int  DictionaryDiff       (const char* s1, const char* s2)
{
	string a1 = CopyString(s1); // aux string to get the lenght of s1
	string a2 = CopyString(s2); // aux string to get the lenght of s2
	char *b1 =CopyString(s1); // copy of s1 to be able to edit the content
	char *b2 =CopyString(s2); // copy of s2 to be able to edit the content
	
	for ( int i = 0; i <= a1.length(); i++) // transforms all uppercase to
		// lowercase on b1
	{
		if (a1[i]>=65 && a1[i] <=90 )
			b1[i] = b1[i] +32;
	}
	for ( int i = 0; i <= a1.length(); i++)// transforms all uppercase to
		// lowercase on b2
	{
		if (a2[i]>=65 && a2[i] <=90 )
			b2[i] = b2[i] +32;
	}
	return strcmp(b1, b2);// returns any diff value between s1 and s2
}

bool DictionaryComp(const char* s1, const char* s2)
{
	
	if ( DictionaryDiff(s1, s2) < 0 ) // if lexdiff returns a -ve value then
		// true
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

void PrintStrings(char* array[], size_t count)
{
	for (size_t i = 0; i < count; ++i)
		std::cout << "  " << array[i] << '\n';
}
