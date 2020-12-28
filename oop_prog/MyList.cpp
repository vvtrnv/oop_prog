#include "MyList.h"

MyList::MyList()
{
	size = 0;
	head = nullptr;
}

void MyList::push_back(Complex* nData)
{
	if (head == nullptr) 
		head = new Node(nData);
	else
	{
		Node* current = this->head;

		while (current->pNext != nullptr) 
			current = current->pNext;

		current->pNext = new Node(nData);
	}

	size++;
}

void MyList::push_front(Complex* nData)
{
	head = new Node(nData, head);
	size++;
}

void MyList::pop_front()
{
	try
	{
		if (head == nullptr)
			throw exception("Error! List is empty!");
		Node* temp = head;
		head = head->pNext;

		delete temp;
		size--;
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}

	
}

void MyList::clear()
{
	while (size)
		pop_front();
}

void MyList::insert(Complex* nData, const int& index)
{
	try
	{
		if (index == 0)
			push_front(nData);
		else if (index >= size)
			throw exception("Error! The size of the list does not allow");

		Node* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node* newNode = new Node(nData, previous->pNext);
		previous->pNext = newNode;
		size++;
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void MyList::removeAt(const int& index)
{

	try
	{
		if (index >= size)
			throw exception("Error! The element does not exist");
		else if (index == 0)
			pop_front();
		else
		{
			Node* previous = head;
			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->pNext;
			}
			Node* toDelete = previous->pNext;
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

void MyList::pop_back()
{
	try
	{
		if (head == nullptr)
			throw exception("List is empty!");

		removeAt(size - 1);
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
}

Complex* MyList::operator[](const int& index)
{
	try
	{
		if (index >= size)
			throw exception("Error! The element does not exist");

		int counter = 0;
		Node* current = this->head;

		while (current != nullptr)
		{
			if (counter == index)
				return current->data;

			current = current->pNext;
			counter++;
		}
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void MyList::print_all(ostream& os)
{

	try
	{
		if (this->head == nullptr)
			throw exception("Error! List is empty!");

		Node* current = this->head;
		int len = this->get_Size();
		for (int i = 0; i < len; i++)
		{
			os << i << ") " << current->data->to_String() << endl;
			current = current->pNext;
		}
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
}

MyList::~MyList()
{
	clear();
}