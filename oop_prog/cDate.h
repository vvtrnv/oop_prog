#pragma once
#include "Complex.h"

class cDate : public Complex
{
public:
	cDate();
	cDate(double var1, double var2);
	~cDate();

	virtual char* to_String();
	void fixTime();

private:
	char* dateCreate;
};

