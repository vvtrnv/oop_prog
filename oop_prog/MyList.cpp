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
	Node* temp = head;
	head = head->pNext;

	delete temp;
	size--;
}

void MyList::clear()
{
	while (size)
		pop_front();
}

void MyList::insert(Complex* nData, const int& index)
{
	if (index == 0)
		push_front(nData);
	else
	{
		Node* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node* newNode = new Node(nData, previous->pNext);
		previous->pNext = newNode;
		size++;
	}

}

void MyList::removeAt(const int& index)
{
	if (index == 0)
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

void MyList::pop_back()
{
	removeAt(size - 1);
}

Complex* MyList::operator[](const int& index)
{
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

void MyList::print_all(ostream& os)
{
	Node* current = this->head;
	int len = this->get_Size();
	for (int i = 0; i < len; i++)
	{
		os << i << ") " << current->data->to_String() << endl;
		current = current->pNext;
	}
}

MyList::~MyList()
{
	clear();
}