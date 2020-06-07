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
