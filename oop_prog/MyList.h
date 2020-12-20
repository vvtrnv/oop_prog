#pragma once
#include "Complex.h"
#include "AnotherRep.h"
#include "cDate.h"
class MyList
{
public:
	MyList(); // Конструктор.
	//~MyList(); // Деструктор.
	void push_back(const double& valid, const double& image); // Добавить в конец.
	void push_front(const double& valid, const double& image); // Добавить в начало.
	void pop_front(); // Удалить первый узел.
	void clear(); // Очистить список.
	void insert(const double& valid, const double& image, const int& index); // Добавление по индексу.
	void removeAt(const int& index); // Удалить узел по индексу.
	void pop_back(); // Удалить последний узел.
	int get_Size() { return size; }

	Complex& operator[](const int& index);


private:

	class Node
	{
	public:
		Node* pNext; // Указатель на следующий узел списка.
		Complex data; // Указатель на объект.

		Node(const double& valid, const double& image, Node* next = nullptr)
		{
			this->data = Complex(valid, image);
			this->pNext = next;
		}
	};

	int size; // Размер.
	Node* head; // Начальный узел.
};


