#pragma once
#include <unordered_map>
#include <cassert>

using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();

	void push_back(T data);
	void pop_front();
	void deleteDuplicates();
	T kthToLast(const int k);
	int getSize() const { return size; }
	T& operator[](const int index);

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
	Node<T> *head;
};

template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	while (size)
		pop_front();
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;
	size--;
}

template<typename T>
void List<T>::deleteDuplicates()
{
	Node<T>* previous = nullptr;
	Node<T>* current = this->head;
	unordered_map<T, int> mp;
	while (current != nullptr)
	{
		if (mp.find(current->data) != mp.end())
		{
			mp[current->data]++;
			previous->pNext = current->pNext;
			current = current->pNext;
			size--;
		}
		else
		{
			mp[current->data] = 1;
			previous = current;
			current = current->pNext;
		}
	}
}

template<typename T>
T List<T>::kthToLast(const int k)
{
	assert(size - k >= 0 && size - k < size);
	return this->operator[](size - k);
}

template<typename T>
void List<T>::push_back(T data)
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
T& List<T>::operator[](const int index)
{
	assert(index >= 0 && index <= size);
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
			return current->data;
		current = current->pNext;
		counter++;
	}
}
