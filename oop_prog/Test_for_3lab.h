#pragma once
#include <iostream>
#include <fstream>
#include "Complex.h"

using namespace std;

void test2()
{
	const size_t ARRSIZE = 5;
	Complex arr[ARRSIZE]
	{
		Complex(1 ,5,"1+5i"),
		Complex(2, 3,"2+3i"),
		Complex(15, 10,"15+10i"),
		Complex(28, 30,"28+30i"),
		Complex(1.5, 2.3,"1+5i")
	};
	Complex arr2[ARRSIZE];

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
		for (int i = 0; i < ARRSIZE; i++)
		{
			fout << arr[i];
		}
	}
	fout.close();

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
		for (int i = 0; !fout.eof() && i < ARRSIZE; i++)
		{
			fin >> arr2[i];
		}
	}
	fin.close();

	//Сравниваем то, что записали и то, что считали
	cout << "Recorded data" << endl;
	for (int i = 0; i < ARRSIZE; i++)
	{
		cout << arr[i];
	}

	cout << "Read data" << endl;
	for (int i = 0; i < ARRSIZE; i++)
	{
		cout << arr2[i];
	}
	
	cout << "Did the data match?\t";
	for (int i = 0; i < ARRSIZE; i++)
	{
		if (compare(arr[i], arr2[i])) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}