#pragma once

#include <fstream>
#include "Complex.h"

using namespace std;

void resizeArr(Complex*& oldArr, size_t& size)// Меняет размер динамического массива.
{
	Complex* newArr = new Complex[size + 1];
	for (int i = 0; i < size; i++)
	{
		newArr[i] = oldArr[i];
	}
	delete[] oldArr;

	oldArr = newArr;
	size++;
}

void Lab3_test1()
{

}

void Lab3_test2()
{
	cout << "TEST 2 IN/OUT .TXT----------\n";
	size_t size = 5;

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
			if (i >= size) resizeArr(arr, size);
			fin >> arr[i];
		}
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
		cout << "File is open!" << endl;
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
	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;

	//Complex a[2]
	//{
	//	Complex(1,2,"1+2i"),
	//	Complex(3,4,"3+4iii")
	//};
	//Complex copy[2];
	//for (int i = 0; i < 2; i++)
	//{
	//	a[i] = copy[i];
	//}
}

void Lab3_test3()
{
	cout << "TEST 3 IN/OUT .BIN----------\n";
	
	size_t size = 5;
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
			if (i >= size) resizeArr(arr, size);
			fin >> arr[i];
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
		cout << "File is open!" << endl;
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
	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;
}