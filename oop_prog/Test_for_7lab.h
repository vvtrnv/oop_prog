#pragma once
#include <iostream>
#include "Complex.h"
#include "templateList.h"


bool compare_complex(const char* expected[], templateList<Complex>& real); // ��������� ����������� ��� �������� ������ Complex.
template<class T> bool compare_expected_real(T expected[], templateList<T>& real); // ��������� ����������� ��� ����������� ����� int, float, double...

void lab7_test_1_1_INT()
{
	// ���� 1.1.
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~���� 1 ��� ���� ������ INT~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~���� 1.1. ���������� ��������� � ����� �� �����, � ��� �� �������� ��������� �� �������~~~" << endl;
	templateList<int> typeInt;
	const int SIZE = 10;
	for (int i = 0; i < SIZE; i++)
	{
		typeInt.push_back(i + 1);
	}

	for (int i = 0; i < typeInt.GetSize(); i++)
	{
		cout << typeInt[i] << "\t";
	}
	cout << endl;
	
	// �������� �����������.
	int expected[SIZE]
	{
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		10
	};
	if (compare_expected_real(expected, typeInt))
		cout << "~���� 1.1. �������!~" << endl;
	else
		cout << "~���� 1.1. �� �������!!!!~" << endl;

	cout << endl << endl;
}

void lab7_test_1_2_INT()
{
	cout << "~~~���� 1.2. �������� ������� � ���������� ��������~~~" << endl;
	templateList<int> typeInt;
	const int SIZE = 10;
	for (int i = 0; i < SIZE; i++)
	{
		typeInt.push_back(i + 1);
	}

	for (int i = 0; i < typeInt.GetSize(); i++)
	{
		cout << typeInt[i] << "\t";
	}
	cout << endl;

	//������� ��������� ������� � ������ �������.
	typeInt.pop_front();
	typeInt.pop_back();
	
	for (int i = 0; i < typeInt.GetSize(); i++)
	{
		cout << typeInt[i] << "\t";
	}
	cout << endl;

	// ��������
	int expected[SIZE - 2]
	{
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9
	};
	if (compare_expected_real(expected, typeInt))
		cout << "~���� 1.2. �������!~" << endl;
	else
		cout << "~���� 1.2. �� �������!!!!~" << endl;

	cout << endl << endl;
}

void lab7_test_1_3_INT()
{
	cout << "~~~���� 1.3. �������� ������� push_front() � insert()~~~" << endl;
	templateList<int> typeInt;
	const int SIZE = 10;
	for (int i = 0; i < SIZE; i++)
	{
		typeInt.push_front(i + 1);
	}

	for (int i = 0; i < typeInt.GetSize(); i++)
	{
		cout << typeInt[i] << "\t";
	}
	cout << endl;

	// ��������� ����� ������� �� ������� 5.
	typeInt.insert(11111, 5);

	for (int i = 0; i < typeInt.GetSize(); i++)
	{
		cout << typeInt[i] << "\t";
	}
	cout << endl;

	// ��������.
	int expected[SIZE + 1]
	{
		10,
		9,
		8,
		7,
		6,
		11111,
		5,
		4,
		3,
		2,
		1
	};
	if (compare_expected_real(expected, typeInt))
		cout << "~���� 1.3. �������!~" << endl;
	else
		cout << "~���� 1.3. �� �������!!!!~" << endl;
}

void lab7_test_1_4_INT()
{
	cout << "~~~���� 1.4. �������� �������� �� ������� 5~~~" << endl;
	templateList<int> typeInt;
	const int SIZE = 10;
	for (int i = 0; i < SIZE; i++)
	{
		typeInt.push_back(i + 1);
	}

	for (int i = 0; i < typeInt.GetSize(); i++)
	{
		cout << typeInt[i] << "\t";
	}
	cout << endl;

	// ������� ������� �� ������� 5
	typeInt.removeAt(5);

	for (int i = 0; i < typeInt.GetSize(); i++)
	{
		cout << typeInt[i] << "\t";
	}
	cout << endl;

	// ��������.
	int expected[SIZE - 1]
	{
		1,
		2,
		3,
		4,
		5,
		7,
		8,
		9,
		10
	};
	if (compare_expected_real(expected, typeInt))
		cout << "~���� 1.4. �������!~" << endl;
	else
		cout << "~���� 1.4. �� �������!!!!~" << endl;
}

void lab7_test_2_1_COMPLEX()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~���� 2 ��� ���� ������ COMPLEX~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~���� 2.1. ���������� ��������� � ����� �� �����, � ��� �� �������� ��������� �� �������~~~" << endl;
	templateList<Complex> typeComplex;
	const int SIZE = 5;

	Complex arr[SIZE]
	{
		Complex(1,2),
		Complex(22,66),
		Complex(1.1661, 22),
		Complex(777, 223),
		Complex(1998, 2020)
	};

	for (int i = 0; i < SIZE; i++)
	{
		typeComplex.push_back(arr[i]);
	}

	for (int i = 0; i < SIZE; i++)
	{
		cout << typeComplex[i];
	}

	// ��������.
	cout << "��������:" << endl;
	const char* expected[SIZE]
	{
		"(1.000000 + 2.000000 i)",
		"(22.000000 + 66.000000 i)",
		"(1.166100 + 22.000000 i)",
		"(777.000000 + 223.000000 i)",
		"(1998.000000 + 2020.000000 i)"
	};
	if (compare_complex(expected, typeComplex))
		cout << "~���� 2.1. �������!~" << endl;
	else
		cout << "~���� 2.1. �� �������!!!!~" << endl;

	cout << endl << endl;
}

void lab7_test_2_2_COMPLEX()
{
	cout << "~~~���� 2.2. �������� ������� � ���������� ��������~~~" << endl;
	templateList<Complex> typeComplex;
	const int SIZE = 5;
	Complex arr[SIZE]
	{
		Complex(1,2),
		Complex(22,66),
		Complex(1.1661, 22),
		Complex(777, 223),
		Complex(1998, 2020)
	};

	for (int i = 0; i < SIZE; i++)
	{
		typeComplex.push_back(arr[i]);
	}

	for (int i = 0; i < SIZE; i++)
	{
		cout << typeComplex[i];
	}

	//������� ��������� ������� � ������ �������.
	cout << "\n������� ������ � ��������� �������:" << endl;
	typeComplex.pop_front();
	typeComplex.pop_back();

	for (int i = 0; i < typeComplex.GetSize(); i++)
	{
		cout << typeComplex[i];
	}
	cout << endl;

	// ��������
	cout << "��������:" << endl;
	const char* expected[SIZE-2]
	{
		"(22.000000 + 66.000000 i)",
		"(1.166100 + 22.000000 i)",
		"(777.000000 + 223.000000 i)",
	};
	if (compare_complex(expected, typeComplex))
		cout << "~���� 2.2. �������!~" << endl;
	else
		cout << "~���� 2.2. �� �������!!!!~" << endl;

	cout << endl << endl;
}

void lab7_test_2_3_COMPLEX()
{
	cout << "~~~���� 2.3. �������� ������� push_front() � insert()~~~" << endl;
	templateList<Complex> typeComplex;
	const int SIZE = 5;
	Complex arr[SIZE]
	{
		Complex(1,2),
		Complex(22,66),
		Complex(1.1661, 22),
		Complex(777, 223),
		Complex(1998, 2020)
	};

	for (int i = 0; i < SIZE; i++)
	{
		typeComplex.push_front(arr[i]);
	}

	for (int i = 0; i < SIZE; i++)
	{
		cout << typeComplex[i];
	}

	// ��������� ������� �� ������� 3.
	cout << "\n��������� ������� �� ������� 3:" << endl;
	Complex toAdd(5555, 6666);
	typeComplex.insert(toAdd, 3);

	for (int i = 0; i < typeComplex.GetSize(); i++)
	{
		cout << typeComplex[i];
	}
	cout << endl;

	//��������.
	cout << "��������:" << endl;
	const char* expected[SIZE + 1]
	{
		"(1998.000000 + 2020.000000 i)",
		"(777.000000 + 223.000000 i)",
		"(1.166100 + 22.000000 i)",
		"(5555.000000 + 6666.000000 i)",
		"(22.000000 + 66.000000 i)",
		"(1.000000 + 2.000000 i)",
	};
	if (compare_complex(expected, typeComplex))
		cout << "~���� 2.3. �������!~" << endl;
	else
		cout << "~���� 2.3. �� �������!!!!~" << endl;

	cout << endl << endl; 
}

void lab7_test_2_4_COMPLEX()
{
	cout << "~~~���� 2.4. �������� �������� �� ������� 5~~~" << endl;
	templateList<Complex> typeComplex;
	const int SIZE = 5;
	Complex arr[SIZE]
	{
		Complex(1,2),
		Complex(22,66),
		Complex(1.1661, 22),
		Complex(777, 223),
		Complex(1998, 2020)
	};

	for (int i = 0; i < SIZE; i++)
	{
		typeComplex.push_front(arr[i]);
	}

	for (int i = 0; i < SIZE; i++)
	{
		cout << typeComplex[i];
	}

	// ������� �������.
	cout << "\n������� ������� �� ������� 2" << endl;
	typeComplex.removeAt(2);

	for (int i = 0; i < typeComplex.GetSize(); i++)
	{
		cout << typeComplex[i];
	}
	cout << endl;

	//��������.
	cout << "��������:" << endl;
	const char* expected[SIZE + 1]
	{
		"(1998.000000 + 2020.000000 i)",
		"(777.000000 + 223.000000 i)",
		"(22.000000 + 66.000000 i)",
		"(1.000000 + 2.000000 i)",
	};
	if (compare_complex(expected, typeComplex))
		cout << "~���� 2.4. �������!~" << endl;
	else
		cout << "~���� 2.4. �� �������!!!!~" << endl;

	cout << endl << endl;
}


//-------------- ��������������� �������. --------------//

template<class T>
bool compare_expected_real(T expected[], templateList<T>& real)
{
	for (int i = 0; i < real.GetSize(); i++)
	{
		if (expected[i] != real[i])
			return false;
	}

	return true;
}

bool compare_complex(const char* expected[], templateList<Complex>& real)
{
	const int len = real.GetSize();
	for (int i = 0; i < len; i++)
	{
		cout << "��������� ��������:\t" << expected[i] << endl;
		cout << "�������� ��������:\t" << real[i].to_String() << endl << endl;

		if (strcmp(expected[i], real[i].to_String()) != 0) return false;
	}

	return true;
}