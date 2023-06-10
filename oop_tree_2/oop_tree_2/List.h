#pragma once
#include <iostream>
#include <exception>
using namespace std;

template <typename T>
class LinkedList
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node* prev;

		Node(T data, Node* next = nullptr, Node* prev = nullptr)
			: data(data), next(next), prev(prev) { }
	};

	Node* head;

	Node* tail;

	int size;

public:
	LinkedList() : head(nullptr), tail(nullptr), size(0) { }
	~LinkedList()
	{
		Clear();
	}

	bool IsEmpty() const { return size == 0; }


	void AddHead(T data)
	{

		Node* item = new Node(data, head);

		if (IsEmpty()) tail = item;
		else head->prev = item;

		head = item;

		++size;
	}

	void DeleteHead()
	{
		if (IsEmpty()) return;

		Node* temp = head;

		head = head->next;

		delete temp;

		--size;

		if (IsEmpty()) tail = nullptr;
		else head->prev = nullptr;
	}


	void AddTail(T data)
	{

		Node* item = new Node(data, nullptr, tail);


		if (IsEmpty())
			head = item;
		else
			tail->next = item;

		tail = item;

		++size;
	}


	void DeleteTail()
	{
		if (IsEmpty()) return;

		Node* temp = tail;

		tail = tail->prev;

		delete temp;

		--size;


		if (IsEmpty()) head = nullptr;

		else tail->next = nullptr;
	}

	void InsertItem(T data, int index)
	{
		if (index < 0 || index > size) throw out_of_range("Index is out of the range!");
		if (index == size) { AddTail(data); return; }
		if (index == 0) { AddHead(data); return; }

		Node* current = head;
		for (int i = 0; i < index; ++i)
		{
			current = current->next;
		}

		Node* item = new Node(data, current, current->prev);

		current->prev->next = item;

		current->prev = item;

		++size;
	}

	void Reverse()
	{
		LinkedList<T>* newList = new LinkedList<T>;
		int size = GetCount();
		for (size_t i = 0; i < size; i++)
		{
			newList->AddHead(this->GetFirst());
			this->DeleteHead();
		}
		this->head = newList->head;
		this->tail = newList->tail;
		this->size = size;
	}

	void DeleteByIndex(int index)
	{
		if (index < 0 || index >= size) throw out_of_range("Index is out of the range!");
		if (index == size - 1) { DeleteTail(); return; }
		if (index == 0) { DeleteHead(); return; }
		Node* current = head;
		for (int i = 0; i < index; ++i)
		{
			current = current->next;
		}
		current->prev->next = current->next;
		current->next->prev = current->prev;
		delete current;
		--size;
	}

	T GetFirst() const
	{
		if (IsEmpty()) throw exception("List is empty.");

		return head->data;
	}
	T GetLast() const
	{
		if (IsEmpty()) throw exception("List is empty.");

		return tail->data;
	}
	int GetCount() const
	{
		return size;
	}

	void Show() const
	{

		for (Node* i = head; i != nullptr; i = i->next)
		{
			cout << i->data << " ";
		}
		cout << endl;
	}

	void Clear()
	{
		Node* item = head;
		while (item != nullptr)
		{
			Node* next = item->next;
			delete item;
			item = next;
		}
		head = tail = nullptr;
		size = 0;
	}
};