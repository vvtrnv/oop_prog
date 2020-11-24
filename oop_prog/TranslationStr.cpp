#include <cstdio>
#include <sstream>
#include "TranslationStr.h"

char* TranslationStr::get_StrRepresent()
{
	return this->strRepresent;
}

void TranslationStr::double_toStr()
{
	char expr[255];
	sprintf_s(expr, 100, "(%f+%f i)", getValid(), getImage());

	if (strRepresent)
	{

		delete[] strRepresent;
		strRepresent = nullptr;
	}
	int len = strlen(expr) + 1;
	strRepresent = new char[len];
	strcpy_s(strRepresent, len, expr);
}

void TranslationStr::str_toDouble()
{
	char* tempValid[255];
	char* tempImage[255];
	int pause;
	for (int i = 0; strRepresent[i]; i++)
	{
		
	}


	stringstream strStream; // Преобразуем из формата строки в int.
	strStream << strValid;  //
	strStream >> p.valid;  //
}