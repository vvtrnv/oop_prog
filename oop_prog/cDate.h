#pragma once
#include "Complex.h"

class cDate : public Complex
{
public:
	cDate();
	cDate(double var1, double var2);
	~cDate();

	char* get_dateCreate();
	void fixTime();

private:
	char* dateCreate;
};

