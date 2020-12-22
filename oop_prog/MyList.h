#pragma once
#include "Complex.h"
#include "AnotherRep.h"
#include "cDate.h"
class MyList
{
public:
	MyList(); // Конструктор.
	~MyList(); // Деструктор.
	void push_back(Complex* nData); // Добавить в конец.
	void push_front(Complex* nData); // Добавить в начало.
	void pop_front(); // Удалить первый узел.
	void clear(); // Очистить список.
	void insert(Complex* nData, const int& index); // Добавление по индексу.
	void removeAt(const int& index); // Удалить узел по индексу.
	void pop_back(); // Удалить последний узел.
	
	void print_all(ostream& os); // Вывести на экран все объекты.
	int get_Size() { return size; } 

	Complex* operator[](const int& index); // Поиск по индексу.


private:

	class Node
	{
	public:
		Node* pNext; // Указатель на следующий узел списка.
		Complex* data; // Указатель на объект.
		
		Node(Complex* nData, Node* next = nullptr)
		{
			this->data = nData;
			this->pNext = next;
		}
	};

	int size; // Размер.
	Node* head; // Начальный узел.
};