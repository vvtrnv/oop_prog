#pragma once
#include "Complex.h"
class Translation : public Complex
{
public:
	Translation();
	Translation(double var1, double var2);
	void str_toDouble();
	void double_toStr();

private:
	char* strRepresent;
};

