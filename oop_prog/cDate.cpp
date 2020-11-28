#include <ctime>
#include "cDate.h"

// ������������.
cDate::cDate() : Complex()
{
	//this->dateCreate = new char[10];
	//dateCreate = nullptr;
	fixTime();
}

cDate::cDate(double var1, double var2) : Complex(var1, var2)
{
	//this->dateCreate = new char[10];
	//dateCreate = nullptr;
	fixTime();
}


// ����������, ��������� ����� ���������� ������.
cDate::~cDate()
{
	delete[] dateCreate;
}


// �������. ������� �� �����, ��������� �������� ������ ������.
char* cDate::get_dateCreate() { return this->dateCreate; }

// ������.
void cDate::fixTime()
{
	time_t now = time(NULL);
	this->dateCreate = new char[30];
	ctime_s(this->dateCreate, 30, &now);
}


