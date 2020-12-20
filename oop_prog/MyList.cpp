#include "MyList.h"

MyList::MyList()
{
	size = 0;
	head = nullptr;
}

void MyList::push_back(const double& valid, const double& image)
{
	if (head == nullptr) 
		head = new Node(valid, image);
	else
	{
		Node* current = this->head;

		while (current->pNext != nullptr) 
			current = current->pNext;

		current->pNext = new Node(valid, image);
	}

	size++;
}

void MyList::push_front(const double& valid, const double& image)
{
	head = new Node(valid, image, head);
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

void MyList::insert(const double& valid, const double& image, const int& index)
{
	if (index == 0)
		push_front(valid, image);
	else
	{
		Node* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node* newNode = new Node(valid, image, previous->pNext);
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

Complex& MyList::operator[](const int& index)
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