#pragma once
#include <iostream>
using namespace std;

template<typename T>
class templateList
{
public:
	templateList();
	~templateList();

	//удаление первого элемента в списке
	T pop_front();
	

	//добавление элемента в конец списка
	void push_back(T data);

	// очистить список
	void clear();

	// получить количество елементов в списке
	int GetSize() { return size; }

	// перегруженный оператор [] 
	T& operator[](const int index);

	// перегруженный оператор <<
	friend ostream& operator<<(ostream& os, Complex& obj);

	//добавление элемента в начало списка
	void push_front(T data);

	//добавление элемента в список по указанному индексу
	void insert(T data, int index);

	//удаление элемента в списке по указанному индексу
	T removeAt(int index);

	//удаление последнего элемента в списке
	void pop_back();

private:


	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int size;
	Node<T>* head;
};


template<typename T>
templateList<T>::templateList()
{
	size = 0;
	head = nullptr;
}


template<typename T>
templateList<T>::~templateList()
{
	clear();
}


template<typename T>
T templateList<T>::pop_front()
{
	try
	{
		if (head == nullptr)
			throw exception("Error! List is empty!");

		Node<T>* temp = head;

		head = head->pNext;
		size--;
		T rtrn = temp->data;
		delete temp;
		return rtrn;
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
}

template<typename T>
void templateList<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}

	size++;
}

template<typename T>
void templateList<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}


template<typename T>
T& templateList<T>::operator[](const int index)
{
	try
	{
		if (index >= size)
			throw exception("Error! The element does not exist");

		int counter = 0;

		Node<T>* current = this->head;

		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->pNext;
			counter++;
		}
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
}

ostream& operator<<(ostream& os, Complex& obj)
{
	os << obj.expression;
}

template<typename T>
void templateList<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	size++;
}

template<typename T>
void templateList<T>::insert(T nData, int index)
{
	try
	{
		if (index == 0)
			push_front(nData);
		else if (index >= size)
			throw exception("Error! The size of the list does not allow");
		else
		{
			Node<T>* previous = this->head;

			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->pNext;
			}

			Node<T>* newNode = new Node<T>(nData, previous->pNext);
			previous->pNext = newNode;
			size++;
		}
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
}

template<typename T>
T templateList<T>::removeAt(int index)
{
	try
	{
		if (index >= size)
			throw exception("Error! The element does not exist");
		else if (index == 0)
			pop_front();
		else
		{
			Node<T>* previous = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->pNext;
			}

			Node<T>* toDelete = previous->pNext;
			T rtrn = toDelete->data;
			previous->pNext = toDelete->pNext;
			delete toDelete;
			size--;
		}
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
}

template<typename T>
void templateList<T>::pop_back()
{
	try
	{
		if (head == nullptr)
			throw exception("Error! List is empty!");
		else
			removeAt(size - 1);
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
	
}


