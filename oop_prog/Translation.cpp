#include "Translation.h"

#define strdup _strdup

Translation::Translation() : Complex() { double_toStr(); }

Translation::Translation(double var1, double var2) : Complex(var1, var2) { double_toStr(); }

char* Translation::get_strRepresent()
{
	return this->strRepresent;
}

Translation::~Translation()
{
	delete[] strRepresent;
}

void Translation::double_toStr()
{
	char expr[255];
	sprintf_s(expr, 100, "(%f + %f i)", get_Valid(), get_Image());

	if (strRepresent)
	{

		delete[] strRepresent;
		strRepresent = nullptr;
	}
	strRepresent = strdup(expr);
}

void Translation::str_toDouble()
{
	setlocale(LC_NUMERIC, "C"); // для stringstream, чтобы вместе запятой в дробном числе показывал точку.


}