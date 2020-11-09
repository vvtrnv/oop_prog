#pragma once

#include <fstream>
#include "Complex.h"

using namespace std;

void Lab3_test2()
{
	cout << "TEST 2 IN/OUT .TXT----------\n";
	size_t size = 0;
	Complex* arr = new Complex[size];
	Complex* arr2 = new Complex[size];

	// Считывание из файла.
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
			arr = resizeArr(arr, size);
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
}

//void Lab3_test3()
//{
//	cout << "TEST 3 IN/OUT .BIN----------\n";
//	
//	const size_t ARRSIZE = 5;
//	Complex arr[ARRSIZE]
//	{
//		Complex(1 ,5,"1+5i"),
//		Complex(2, 3,"2+3i"),
//		Complex(15, 10,"15+10i"),
//		Complex(28, 30,"28+30i"),
//		Complex(1.5, 2.3,"1+5i")
//	};
//	Complex arr2[ARRSIZE];
//
//	// Запись в файл.
//	ofstream fout;
//	fout.open("Lr3_Test2.bin", ios::binary);
//
//	if (!fout.is_open())
//	{
//		cerr << "Error! Сheck for the file." << endl;
//	}
//	else
//	{
//		cout << "File is open!" << endl;
//		for (int i = 0; i < ARRSIZE; i++)
//		{
//			fout < arr[i];
//		}
//	}
//	fout.close();
//
//	// Считывание из файла.
//	ifstream fin;
//	fin.open("Lr3_Test2.bin", ios::binary);
//
//	if (!fin.is_open())
//	{
//		cerr << "Error! Check for the file!";
//	}
//	else
//	{
//		cout << "File is open! Download objects..." << endl;
//		for (int i = 0; !fout.eof() && i < ARRSIZE; i++)
//		{
//			fin > arr2[i];
//		}
//	}
//	fin.close();
//
//	//Сравниваем то, что записали и то, что считали
//	for (int i = 0; i < ARRSIZE; i++)
//	{
//		cout << "Recorded data: \t\t" << arr[i];
//		cout << "Read data: \t\t" << arr2[i];
//	}
//
//
//	cout << "Did the data match?\t";
//	bool flag = true;
//	for (int i = 0; i < ARRSIZE; i++)
//	{
//		if (!compare(arr[i], arr2[i])) flag = false;
//	}
//	if (flag) cout << "YES" << endl;
//	else cout << "NO" << endl;
//}