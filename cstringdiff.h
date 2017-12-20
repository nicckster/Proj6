
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int  LexDiff              (const char* s1, const char* s2);
int  DictionaryDiff       (const char* s1, const char* s2);
bool LexComp              (const char* s1, const char* s2);
bool DictionaryComp       (const char* s1, const char* s2);
void PrintStrings(char* array[], size_t count);
