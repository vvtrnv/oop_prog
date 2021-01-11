#pragma once
#include <iostream>
#include "Complex.h"
#include "templateList.h"


bool compare_complex(const char* expected[], templateList<Complex>& real); // Сравнение результатов для объектов класса Complex.
template<class T> bool compare_expected_real(T expected[], templateList<T>& real); // Сравнение результатов для стандартных типов int, float, double...

void lab7_test_1_1_INT()
{
	// Тест 1.1.
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~Тест 1 для типа данных INT~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~Тест 1.1. Добавление элементов и вывод на экран, а так же проверка обращения по индексу~~~" << endl;
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
	
	// Проверка результатов.
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
		cout << "~Тест 1.1. Пройден!~" << endl;
	else
		cout << "~Тест 1.1. Не пройден!!!!~" << endl;

	cout << endl << endl;
}

void lab7_test_1_2_INT()
{
	cout << "~~~Тест 1.2. Удаление первого и последнего элемента~~~" << endl;
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

	//Удаляем последний элемент и первый элемент.
	typeInt.pop_front();
	typeInt.pop_back();
	
	for (int i = 0; i < typeInt.GetSize(); i++)
	{
		cout << typeInt[i] << "\t";
	}
	cout << endl;

	// Проверка
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
		cout << "~Тест 1.2. Пройден!~" << endl;
	else
		cout << "~Тест 1.2. Не пройден!!!!~" << endl;

	cout << endl << endl;
}

void lab7_test_1_3_INT()
{
	cout << "~~~Тест 1.3. Проверка функции push_front() и insert()~~~" << endl;
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

	// Добавляем новый элемент по индексу 5.
	typeInt.insert(11111, 5);

	for (int i = 0; i < typeInt.GetSize(); i++)
	{
		cout << typeInt[i] << "\t";
	}
	cout << endl;

	// Проверка.
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
		cout << "~Тест 1.3. Пройден!~" << endl;
	else
		cout << "~Тест 1.3. Не пройден!!!!~" << endl;
}

void lab7_test_1_4_INT()
{
	cout << "~~~Тест 1.4. Проверка удаления по индексу 5~~~" << endl;
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

	// Удаляем элемент по индексу 5
	typeInt.removeAt(5);

	for (int i = 0; i < typeInt.GetSize(); i++)
	{
		cout << typeInt[i] << "\t";
	}
	cout << endl;

	// Проверка.
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
		cout << "~Тест 1.4. Пройден!~" << endl;
	else
		cout << "~Тест 1.4. Не пройден!!!!~" << endl;
}

void lab7_test_2_1_COMPLEX()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~Тест 2 для типа данных COMPLEX~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~Тест 2.1. Добавление элементов и вывод на экран, а так же проверка обращения по индексу~~~" << endl;
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

	// Проверка.
	cout << "Проверка:" << endl;
	const char* expected[SIZE]
	{
		"(1.000000 + 2.000000 i)",
		"(22.000000 + 66.000000 i)",
		"(1.166100 + 22.000000 i)",
		"(777.000000 + 223.000000 i)",
		"(1998.000000 + 2020.000000 i)"
	};
	if (compare_complex(expected, typeComplex))
		cout << "~Тест 2.1. Пройден!~" << endl;
	else
		cout << "~Тест 2.1. Не пройден!!!!~" << endl;

	cout << endl << endl;
}

void lab7_test_2_2_COMPLEX()
{
	cout << "~~~Тест 2.2. Удаление первого и последнего элемента~~~" << endl;
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

	//Удаляем последний элемент и первый элемент.
	cout << "\nУдаляем первый и последний элемент:" << endl;
	typeComplex.pop_front();
	typeComplex.pop_back();

	for (int i = 0; i < typeComplex.GetSize(); i++)
	{
		cout << typeComplex[i];
	}
	cout << endl;

	// Проверка
	cout << "Проверка:" << endl;
	const char* expected[SIZE-2]
	{
		"(22.000000 + 66.000000 i)",
		"(1.166100 + 22.000000 i)",
		"(777.000000 + 223.000000 i)",
	};
	if (compare_complex(expected, typeComplex))
		cout << "~Тест 2.2. Пройден!~" << endl;
	else
		cout << "~Тест 2.2. Не пройден!!!!~" << endl;

	cout << endl << endl;
}

void lab7_test_2_3_COMPLEX()
{
	cout << "~~~Тест 2.3. Проверка функции push_front() и insert()~~~" << endl;
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

	// Добавляем элемент по индексу 3.
	cout << "\nДобавляем элемент по индексу 3:" << endl;
	Complex toAdd(5555, 6666);
	typeComplex.insert(toAdd, 3);

	for (int i = 0; i < typeComplex.GetSize(); i++)
	{
		cout << typeComplex[i];
	}
	cout << endl;

	//Проверка.
	cout << "Проверка:" << endl;
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
		cout << "~Тест 2.3. Пройден!~" << endl;
	else
		cout << "~Тест 2.3. Не пройден!!!!~" << endl;

	cout << endl << endl; 
}

void lab7_test_2_4_COMPLEX()
{
	cout << "~~~Тест 2.4. Проверка удаления по индексу 5~~~" << endl;
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

	// Удаляем элемент.
	cout << "\nУдаляем элемент по индексу 2" << endl;
	typeComplex.removeAt(2);

	for (int i = 0; i < typeComplex.GetSize(); i++)
	{
		cout << typeComplex[i];
	}
	cout << endl;

	//Проверка.
	cout << "Проверка:" << endl;
	const char* expected[SIZE + 1]
	{
		"(1998.000000 + 2020.000000 i)",
		"(777.000000 + 223.000000 i)",
		"(22.000000 + 66.000000 i)",
		"(1.000000 + 2.000000 i)",
	};
	if (compare_complex(expected, typeComplex))
		cout << "~Тест 2.4. Пройден!~" << endl;
	else
		cout << "~Тест 2.4. Не пройден!!!!~" << endl;

	cout << endl << endl;
}


//-------------- Вспомогательные функции. --------------//

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
		cout << "Ожидаемое значение:\t" << expected[i] << endl;
		cout << "Реальное значение:\t" << real[i].to_String() << endl << endl;

		if (strcmp(expected[i], real[i].to_String()) != 0) return false;
	}

	return true;
}