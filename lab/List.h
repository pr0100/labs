#pragma once

class List
{
public:
	List();
	~List();
	void push_back(int data);
	void deleteDuplicates();
	int kthToLast(const int k);
	void print();

private:
	class Node
	{
	public:
		Node* tail;
		int data;

		Node(int data, Node* pNext = nullptr)
		{
			this->data = data;
			this->tail = pNext;
		}
	};
	Node *head;
};

List::List()
{
	head = nullptr;
}

List::~List()
{
	while (head != nullptr)
	{
		Node* temp = head->tail;
		delete head;
		head = temp;
	}
}

void List::deleteDuplicates()
{
	if (head == nullptr)
		return;
	Node* current = head;
	while (current != nullptr)
	{
		Node* point = current;
		while (point->tail != nullptr)
		{
			if (point->tail->data == current->data)
				point->tail = point->tail->tail;				
			else
				point = point->tail;
		}
		current = current->tail;
	}
}


int List::kthToLast(const int k)
{
	if (k <= 0)
		return -1;
	Node* point1 = head;
	Node* point2 = head;
	for (int i = 0; i < k - 1; i++)
	{
		if (point2 == nullptr)
			return NULL;
		point2 = point2->tail;
	}
	if (point2 == nullptr)
		return NULL;
	while (point2->tail != nullptr)
	{
		point1 = point1->tail;
		point2 = point2->tail;
	}
	return point1->data;
}


void List::push_back(int data)
{
	if (head == nullptr)
		head = new Node(data);
	else
	{
		Node* current = this->head;
		while (current->tail != nullptr)
		{
			current = current->tail;
		}
		current->tail = new Node(data);
	}
}

void List::print()
{
	Node* temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->tail;
	}
}