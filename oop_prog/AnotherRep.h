#pragma once
#include "Complex.h"
class AnotherRep : public Complex
{
public:
	AnotherRep();
	AnotherRep(double var1, double var2);

	~AnotherRep();

	void convertTrig();
	void convertExp();

	char* get_strTrig();
	char* get_strExp();
	double get_R();
	double get_Angle();

private:
	char* strTrig; // ������������������ �����.
	char* strExp; // ������������� �����.
	double r; // ��������.
	double angle; // ����.
};

