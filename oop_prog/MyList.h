#pragma once
#include "Complex.h"
#include "AnotherRep.h"
#include "cDate.h"
class MyList
{
public:
	MyList(); // �����������.
	~MyList(); // ����������.
	void push_back(Complex* nData); // �������� � �����.
	void push_front(Complex* nData); // �������� � ������.
	void pop_front(); // ������� ������ ����.
	void clear(); // �������� ������.
	void insert(Complex* nData, const int& index); // ���������� �� �������.
	void removeAt(const int& index); // ������� ���� �� �������.
	void pop_back(); // ������� ��������� ����.
	
	void print_all(ostream& os); // ������� �� ����� ��� �������.
	int get_Size() { return size; } 

	Complex* operator[](const int& index); // ����� �� �������.


private:

	class Node
	{
	public:
		Node* pNext; // ��������� �� ��������� ���� ������.
		Complex* data; // ��������� �� ������.
		
		Node(Complex* nData, Node* next = nullptr)
		{
			this->data = nData;
			this->pNext = next;
		}
	};

	int size; // ������.
	Node* head; // ��������� ����.
};