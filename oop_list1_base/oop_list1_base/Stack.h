#pragma once
#include <iostream>

class Stack
{
	const int maxSize;
	class Node
	{
	public:
		long item;
		Node* next;
		Node(const long& i, Node* next = nullptr) :item(i), next(next) { }
	};
	int currentSize = 0;
	Node* top;
	Node* tail;
protected:
	void AddTail(const long& item);
public:
	explicit Stack(int size) : top(nullptr), tail(nullptr), maxSize(size) {}
	~Stack();
	Stack(const Stack& st);
	bool IsEmpty() { return currentSize == 0; }
	bool isfull() { return currentSize == maxSize; }
	int StckCount() const { return currentSize; }
	bool push(const long& item);
	bool pop(long& item);
	bool peak(long& item);
};

Stack::~Stack()
{
	Node* temp;
	while (top != nullptr)      
	{
		temp = top;
		top = top->next;
		delete temp;
	}
}

Stack::Stack(const Stack& st) : maxSize(st.maxSize), currentSize(0)
{
	for (Node* i = st.top; i; i = i->next)
		AddTail(i->item);
}

void Stack::AddTail(const long& item)
{
	Node* tmp = new Node{ item, nullptr };
	if (IsEmpty())
		top = tmp;
	else
		tail->next = tmp;
	tail = tmp;
	++currentSize;
}

bool Stack::push(const long& item)
{
	if (isfull())
		return false;
	Node* addItem = new Node(item, top);
	currentSize++;
	if (IsEmpty()) tail = addItem;
	top = addItem;
	return true;
}

bool Stack::pop(long& item)
{
	if (IsEmpty()) return false;
	item = top->item;
	Node* temp = top;
	top = top->next;
	delete temp;
	--currentSize;
	if (IsEmpty()) tail = nullptr;
	return true;
}

bool Stack::peak(long& item)
{
	if (IsEmpty())
		return false;
	item = top->item;
	return true;
}