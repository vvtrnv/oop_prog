#pragma once
#include "Complex.h"
class TranslationStr : public Complex
{
public:
	TranslationStr() : Complex()
	{
		int len = strlen(to_String()) + 1;
		strRepresent = new char[len];
		strcpy_s(strRepresent, len, to_String());
	}

	TranslationStr(double var1, double var2) : Complex(var1, var2)
	{
		// Перевод числа в строку. Копировать в strRepresent.
		double_toStr();
	}

	~TranslationStr()
	{
		delete[] strRepresent;
	}

	void double_toStr();
	void str_toDouble();
	char* get_StrRepresent();

private:
	char* strRepresent;
};

