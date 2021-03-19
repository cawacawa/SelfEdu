#pragma once
#include <string>

template<typename T>
class MyList
{
	template<typename T> 
	struct Node
	{
		T inf;
		Node* prev;
		Node* next;	
		Node() 
			: inf{} 
			, prev{} 
			, next{}
		{};
		Node(const T& inf, Node* prev, Node* next) 
			: inf(inf)
			, prev(prev)
			, next(next)
		{}
	};
	typedef Node<T> ListNode;
	ListNode* Head;
	ListNode* Tail;
	int size;
public:
	MyList() 
	{
		Head = Tail = nullptr;
		size = 0;
	}
	~MyList() 
	{
		deleteList();
	}
	void addToBegin(const T& inf)
	{
		Node<T>* nNode = new Node<T>(inf, nullptr, Head);
		if (Tail == nullptr)
		{
			Tail = nNode;
		}
		else
		{
			Head->prev = nNode;
		}
		Head = nNode;
		size++;
	}
	void addToEnd(const T& inf)
	{
		Node<T>* nNode = new Node<T>((T&)inf, Tail, nullptr, size);
		if (Head == nullptr)
		{
			Head = nNode;
		}
		else 
		{
			Tail->next = nNode;
		}
		Tail = nNode;
		size++;
	}
	void printAll() 
	{
		ListNode* Node = Head;
		while (Node != nullptr)
		{
			printf("%-u ", Node->inf);
			Node = Node->next;
		}
		printf("\n");
	}
	void deleteFromBegin() 
	{		
		if (size == 0) 
		{
			return;
		}
		else if (size > 1) 
		{
			ListNode* tmp = Head;
			Head = Head->next;
			delete tmp;
			Head->prev = nullptr;
			size--;
			return;
		}
		else if(size == 1)
		{
			ListNode* tmp = Head;
			Head = nullptr;
			Tail = nullptr;
			delete tmp;
			size--;
		}
	}
	int getSize() 
	{
		return size;
	}
	T getElemByIndex(int index) 
	{
		ListNode* tmp = Head;
		int i = 1;
		while (tmp != nullptr) 
		{
			if (i == index)
			{
				return tmp->inf;
			}
			tmp = tmp->next;
			i++;
		}
		return -1;//????
	}	
private:
	void deleteList() 
	{
		ListNode* Buff;
		while (Head != nullptr)
		{
			Buff = Head->next;
			delete (Head);
			Head = Buff;
		}
		Tail = nullptr;
		size = 0;
	}
};

