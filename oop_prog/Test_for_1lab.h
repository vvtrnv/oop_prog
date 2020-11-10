#include "Complex.h"
#pragma once

void Lab1_test1(bool result)
{
	cout << "===================Test #1===================\n";

	// ������ ������� ������������ �����.
	Complex ex1_test1(5, 4, "(5 + 4i)"); // �������� ����������� � �����������.
	Complex ex2_test1(11, 7, "(11 + 7i)"); // �������� ����������� � �����������.
	Complex res_test1; // �������� ������������ �����������.

	// ��������.
	cout << "---Summation---\n";
	res_test1.summarize(ex1_test1, ex2_test1);
	cout << ex1_test1.toStringExpression(); cout << " + "; cout << ex2_test1.toStringExpression(); cout << " = ";
	res_test1.showResult();
	res_test1.compare_with(16, 11);

	// ���������.
	cout << "---Subtraction---\n";
	res_test1.subtract(ex1_test1, ex2_test1);
	cout << ex1_test1.toStringExpression(); cout << " - "; cout << ex2_test1.toStringExpression(); cout << " = ";
	res_test1.showResult();
	res_test1.compare_with(-6, -3);

	// �������.
	cout << "---Division---\n";
	res_test1.divide(ex1_test1, ex2_test1);
	cout << ex1_test1.toStringExpression(); cout << " / "; cout << ex2_test1.toStringExpression(); cout << " = ";
	res_test1.showResult();
	res_test1.compare_with(0.48823, 0.0529);

	// ���������.
	cout << "---Multiplication---\n";
	res_test1.multiply(ex1_test1, ex2_test1);
	cout << ex1_test1.toStringExpression(); cout << " * "; cout << ex2_test1.toStringExpression(); cout << " = ";
	res_test1.showResult();
	res_test1.compare_with(27, 79);

	// �����������.
	cout << "---Comparison---\n";
	result = compare(ex1_test1, ex2_test1);
	if (result)
	{
		cout << ex1_test1.toStringExpression(); cout << " = "; cout << ex2_test1.toStringExpression(); cout << endl;
	}
	else
	{
		cout << ex1_test1.toStringExpression(); cout << " != "; cout << ex2_test1.toStringExpression(); cout << endl;
	}

	res_test1.showNumber();

} // ��������� 3 ����������� ��� ��������: ex1_test1 ; ex2_test1 ; res_test1 . ������ �����������.

void Lab1_test2(bool result)
{
	cout << "\n===================Test #2===================\n";

	// ������ ������� ������������ �����.
	Complex ex1_test2(2, 15, "(2 + 15i)"); // �������� ����������� � �����������.
	Complex ex2_test2(17, 7, "(17 + 7i)"); // �������� ����������� � �����������.
	Complex res_test2; // �������� ����������� �����������.

	// ��������.
	cout << "---Summation---\n";
	res_test2.summarize(ex1_test2, ex2_test2);
	cout << ex1_test2.toStringExpression(); cout << " + "; cout << ex2_test2.toStringExpression(); cout << " = ";
	res_test2.showResult();
	res_test2.compare_with(19, 22);

	// ���������.
	cout << "---Subtraction---\n";
	res_test2.subtract(ex1_test2, ex2_test2);
	cout << ex1_test2.toStringExpression(); cout << " - "; cout << ex2_test2.toStringExpression(); cout << " = ";
	res_test2.showResult();
	res_test2.compare_with(-15, 8);

	// �������.
	cout << "---Division---\n";
	res_test2.divide(ex1_test2, ex2_test2);
	cout << ex1_test2.toStringExpression(); cout << " / "; cout << ex2_test2.toStringExpression(); cout << " = ";
	res_test2.showResult();
	res_test2.compare_with(0.411, 0.713);

	// ���������.
	cout << "---Multiplication---\n";
	res_test2.multiply(ex1_test2, ex2_test2);
	cout << ex1_test2.toStringExpression(); cout << " * "; cout << ex2_test2.toStringExpression(); cout << " = ";
	res_test2.showResult();
	res_test2.compare_with(-71, 269);

	// �����������.
	cout << "---Comparison---\n";
	result = compare(ex1_test2, ex2_test2);
	if (result)
	{
		cout << ex1_test2.toStringExpression(); cout << " = "; cout << ex2_test2.toStringExpression(); cout << endl;
	}
	else
	{
		cout << ex1_test2.toStringExpression(); cout << " != "; cout << ex2_test2.toStringExpression(); cout << endl;
	}

	res_test2.showNumber();
} // ��������� 3 ����������� ��� ��������: ex1_test2 ; ex2_test2 ; res_test2 . ������ �����������.

void Lab1_test3(bool result)
{
	cout << "\n===================Test #3===================\n";

	// ������ ������� ������������ �����.
	Complex ex1_test3(18, 16, "(18 + 16i)"); // �������� ����������� � �����������.
	Complex ex2_test3(22, 11, "(22 + 11i)"); // �������� ����������� � �����������.
	Complex res_test3; // �������� ����������� �����������.

	// ��������.
	cout << "---Summation---\n";
	res_test3.summarize(ex1_test3, ex2_test3);
	cout << ex1_test3.toStringExpression(); cout << " + "; cout << ex2_test3.toStringExpression(); cout << " = ";
	res_test3.showResult();
	res_test3.compare_with(40, 27);

	// ���������.
	cout << "---Subtraction---\n";
	res_test3.subtract(ex1_test3, ex2_test3);
	cout << ex1_test3.toStringExpression(); cout << " - "; cout << ex2_test3.toStringExpression(); cout << " = ";
	res_test3.showResult();
	res_test3.compare_with(-4, 5);

	// �������.
	cout << "---Division---\n";
	res_test3.divide(ex1_test3, ex2_test3);
	cout << ex1_test3.toStringExpression(); cout << " / "; cout << ex2_test3.toStringExpression(); cout << " = ";
	res_test3.showResult();
	res_test3.compare_with(0.945, 0.255);

	// ���������.
	cout << "---Multiplication---\n";
	res_test3.multiply(ex1_test3, ex2_test3);
	cout << ex1_test3.toStringExpression(); cout << " * "; cout << ex2_test3.toStringExpression(); cout << " = ";
	res_test3.showResult();
	res_test3.compare_with(220, 550);

	// �����������.
	cout << "---Comparison---\n";
	result = compare(ex1_test3, ex2_test3);
	if (result)
	{
		cout << ex1_test3.toStringExpression(); cout << " = "; cout << ex2_test3.toStringExpression(); cout << endl;
	}
	else
	{
		cout << ex1_test3.toStringExpression(); cout << " != "; cout << ex2_test3.toStringExpression(); cout << endl;
	}

	res_test3.showNumber();
} // ��������� 3 ����������� ��� ��������: ex1_test3 ; ex2_test3 ; res_test3 . ������ �����������.

void Lab1_test4(bool result)
{
	cout << "\n===================Test #4===================\n";

	// ������ ������� ������������ �����.
	Complex ex1_test4(0, 0, "(0 + 0i)"); // �������� ����������� � �����������.
	Complex ex2_test4(0, 0, "(0 + 0i)"); // �������� ����������� � �����������.
	Complex res_test4; // �������� ����������� �����������.

	// ��������.
	cout << "---Summation---\n";
	res_test4.summarize(ex1_test4, ex2_test4);
	cout << ex1_test4.toStringExpression(); cout << " + "; cout << ex2_test4.toStringExpression(); cout << " = ";
	res_test4.showResult();
	res_test4.compare_with(0, 0);

	// ���������.
	cout << "---Subtraction---\n";
	res_test4.subtract(ex1_test4, ex2_test4);
	cout << ex1_test4.toStringExpression(); cout << " - "; cout << ex2_test4.toStringExpression(); cout << " = ";
	res_test4.showResult();
	res_test4.compare_with(0, 0);

	// �������.
	cout << "---Division---\n";
	res_test4.divide(ex1_test4, ex2_test4);
	cout << ex1_test4.toStringExpression(); cout << " / "; cout << ex2_test4.toStringExpression(); cout << " = ";
	res_test4.showResult();
	res_test4.compare_with(0, 0);

	// ���������.
	cout << "---Multiplication---\n";
	res_test4.multiply(ex1_test4, ex2_test4);
	cout << ex1_test4.toStringExpression(); cout << " * "; cout << ex2_test4.toStringExpression(); cout << " = ";
	res_test4.showResult();
	res_test4.compare_with(0, 0);

	// �����������.
	cout << "---Comparison---\n";
	result = compare(ex1_test4, ex2_test4);
	if (result)
	{
		cout << ex1_test4.toStringExpression(); cout << " = "; cout << ex2_test4.toStringExpression(); cout << endl;
	}
	else
	{
		cout << ex1_test4.toStringExpression(); cout << " != "; cout << ex2_test4.toStringExpression(); cout << endl;
	}

	res_test4.showNumber();
} // ��������� 3 ����������� ��� ��������: ex1_test4 ; ex2_test4 ; res_test4 . ������ �����������.

void Lab1_test5(bool result)
{
	cout << "\n===================Test #5===================\n";

	// ������ ������� ������������ �����.
	Complex ex1_test5(-100, 505, "(-100 + 505i)"); // �������� ����������� � �����������.
	Complex ex2_test5(190, 707, "(190 + 707i)"); // �������� ����������� � �����������.
	Complex res_test5; // �������� ����������� �����������.

	// ��������.
	cout << "---Summation---\n";
	res_test5.summarize(ex1_test5, ex2_test5);
	cout << ex1_test5.toStringExpression(); cout << " + "; cout << ex2_test5.toStringExpression(); cout << " = ";
	res_test5.showResult();
	res_test5.compare_with(90, 1212);

	// ���������.
	cout << "---Subtraction---\n";
	res_test5.subtract(ex1_test5, ex2_test5);
	cout << ex1_test5.toStringExpression(); cout << " - "; cout << ex2_test5.toStringExpression(); cout << " = ";
	res_test5.showResult();
	res_test5.compare_with(-290, -202);

	// �������.
	cout << "---Division---\n";
	res_test5.divide(ex1_test5, ex2_test5);
	cout << ex1_test5.toStringExpression(); cout << " / "; cout << ex2_test5.toStringExpression(); cout << " = ";
	res_test5.showResult();
	res_test5.compare_with(0.631, 0.311);

	// ���������.
	cout << "---Multiplication---\n";
	res_test5.multiply(ex1_test5, ex2_test5);
	cout << ex1_test5.toStringExpression(); cout << " * "; cout << ex2_test5.toStringExpression(); cout << " = ";
	res_test5.showResult();
	res_test5.compare_with(-376035, 25250);

	// �����������.
	cout << "---Comparison---\n";
	result = compare(ex1_test5, ex2_test5);
	if (result)
	{
		cout << ex1_test5.toStringExpression(); cout << " = "; cout << ex2_test5.toStringExpression(); cout << endl;
	}
	else
	{
		cout << ex1_test5.toStringExpression(); cout << " != "; cout << ex2_test5.toStringExpression(); cout << endl;
	}

	res_test5.showNumber();
} // ��������� 3 ����������� ��� ��������: ex1_test5 ; ex2_test5 ; res_test5 . ������ �����������.