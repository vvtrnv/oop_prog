#pragma once
#include "Complex.h"
class Translation : public Complex
{
public:
	Translation();
	Translation(double var1, double var2);
	Translation(const char* str);
	~Translation();

	void str_toDouble(const char* str);
	void double_toStr();
	char* get_strRepresent();

private:
	char* strRepresent;
};

