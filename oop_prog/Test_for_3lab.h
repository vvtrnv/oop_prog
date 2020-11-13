#pragma once

#include <fstream>
#include "Complex.h"

using namespace std;

void resizeArr(Complex*& oldArr, int& size)// Меняет размер динамического массива.
{
	Complex* newArr = new Complex[size + 1];
	for (int i = 0; i < size; i++)
	{
		newArr[i] = oldArr[i];
	}

	if(size == 0) delete[] oldArr;
	size++;
	oldArr = newArr;
}

void Output_obj(Complex*& Arr, const int& sz)
{
	cout << "Output objects\n";
	for (int i = 0; i < sz; i++) cout << "Object #" << i + 1 << "\t" << Arr[i];
}

void Lab3_test1()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~TEST #1 IN/OUT CONCOLE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	int size = 0;
	Complex* arr = new Complex[size];
	int value = 1; // Для выбора добавить/вывести/выход из программы.
	while (value)
	{
		cout << "1 - Add object\n";
		cout << "2 - output to the console\n";
		cout << "0 - Exit and output to the console\n";
		cin >> value;
		cin.get();// Чтобы считать последний символ перехода на следующую строку для корректной работы getline().
		switch (value)
		{
		case 1:
		{
			cout << "Input object\n";
			resizeArr(arr, size); // Перераспределяем память и увеличиваем size на 1.
			cin >> arr[size - 1]; // Ввести новый объект.
			break;
		}
		case 2:
		{
			Output_obj(arr,size);
			break;
		}
		case 0:
		{
			Output_obj(arr, size);
			cout << "Exit\n";
			break;
		}
		default:
		{
			cout << "Enter the correct value!(1 or 2 or 0)\n";
			break;
		}
		}
		
	}
}

bool Lab3_test2()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~TEST 2 IN/OUT .TXT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	int size = 5;

	// Считывание из файла.
	Complex* arr = new Complex[size];
	ifstream fin;
	fin.open("Lr3_Test2.txt");

	if (!fin.is_open())
	{
		cerr << "Error! Check for the file!";
	}
	else
	{
		cout << "File is open! Download objects..." << endl;
		for (int i = 0; !fin.eof(); i++)
		{
			if (i == size) resizeArr(arr, size);
			if (fin.eof()) break;
			fin >> arr[i];
		}
		size--;
	}
	fin.close();

	// Запись в файл.
	ofstream fout;
	fout.open("Lr3_Test2.txt");

	if (!fout.is_open())
	{
		cerr << "Error! Сheck for the file." << endl;
	}
	else
	{
		cout << "File is open! Writing to a file..." << endl;
		for (int i = 0; i < size; i++)
		{
			fout << arr[i];
		}

	}
	fout.close();


	// Считывание из файла.
	fin.open("Lr3_Test2.txt");
	Complex* arr2 = new Complex[size];

	if (!fin.is_open())
	{
		cerr << "Error! Check for the file!";
	}
	else
	{
		cout << "File is open! Download objects..." << endl;
		for (int i = 0; !fin.eof() && i < size; i++)
		{
			fin >> arr2[i];
		}
	}
	fin.close();

	//Сравниваем то, что записали и то, что считали
	for (int i = 0; i < size; i++)
	{
		cout << "Recorded data: \t\t" << arr[i];
		cout << "Read data: \t\t" << arr2[i];
	}

	
	cout << "Did the data match?\t";
	bool flag = true;
	for (int i = 0; i < size; i++)
	{
		if (!compare(arr[i], arr2[i])) flag = false;
	}
	if (flag)
	{
		cout << "YES" << endl;
		return true;
	}
	else
	{
		cout << "NO" << endl;
		return false;
	}
}

bool Lab3_test3()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~TEST 3 IN/OUT .BIN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	
	int size = 8;
	Complex* arr = new Complex[size];

	// Считывание из файла.
	ifstream fin;
	fin.open("Lr3_Test2.bin", ios::binary);

	if (!fin.is_open())
	{
		cerr << "Error! Check for the file!";
	}
	else
	{
		cout << "File is open! Download objects..." << endl;
		for (int i = 0; !fin.eof() && i < size; i++)
		{
			if (i == size) resizeArr(arr, size);
			fin > arr[i];
		}
	}
	fin.close();
	
	// Запись в файл.
	ofstream fout;
	fout.open("Lr3_Test2.bin", ios::binary);

	if (!fout.is_open())
	{
		cerr << "Error! Сheck for the file." << endl;
	}
	else
	{
		cout << "File is open! Writing to a file..." << endl;
		for (int i = 0; i < size; i++)
		{
			fout < arr[i];
		}
	}
	fout.close();

	// Считывание из файла.
	Complex* arr2 = new Complex[size];

	fin.open("Lr3_Test2.bin", ios::binary);

	if (!fin.is_open())
	{
		cerr << "Error! Check for the file!";
	}
	else
	{
		cout << "File is open! Download objects..." << endl;
		for (int i = 0; !fout.eof() && i < size; i++)
		{
			fin > arr2[i];
		}
	}
	fin.close();

	//Сравниваем то, что записали и то, что считали
	for (int i = 0; i < size; i++)
	{
		cout << "Recorded data: \t\t" << arr[i];
		cout << "Read data: \t\t" << arr2[i];
	}


	cout << "Did the data match?\t";
	bool flag = true;
	for (int i = 0; i < size; i++)
	{
		if (!compare(arr[i], arr2[i])) flag = false;
	}
	if (flag)
	{
		cout << "YES" << endl;
		return true;
	}
	else
	{
		cout << "NO" << endl;
		return false;
	}
}