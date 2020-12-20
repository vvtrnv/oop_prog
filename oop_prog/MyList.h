#pragma once
#include "Complex.h"
#include "AnotherRep.h"
#include "cDate.h"
class MyList
{
public:
	MyList(); // �����������.
	//~MyList(); // ����������.
	void push_back(const double& valid, const double& image); // �������� � �����.
	void push_front(const double& valid, const double& image); // �������� � ������.
	void pop_front(); // ������� ������ ����.
	void clear(); // �������� ������.
	void insert(const double& valid, const double& image, const int& index); // ���������� �� �������.
	void removeAt(const int& index); // ������� ���� �� �������.
	void pop_back(); // ������� ��������� ����.
	int get_Size() { return size; }

	Complex& operator[](const int& index);


private:

	class Node
	{
	public:
		Node* pNext; // ��������� �� ��������� ���� ������.
		Complex data; // ��������� �� ������.

		Node(const double& valid, const double& image, Node* next = nullptr)
		{
			this->data = Complex(valid, image);
			this->pNext = next;
		}
	};

	int size; // ������.
	Node* head; // ��������� ����.
};


