#pragma once

template <typename T>
class MyStack
{
	template <typename T>
	struct Node
	{
		Node* next;
		T data;
		Node()
			: data{}
			, next{}
		{};
		Node(const T& data, Node* next)
			: data(data)
			, next(next)
		{}
	};
	Node<T>* Top;
	int size;
public:
	MyStack()
		: Top(nullptr)
		, size(0)
	{}
	~MyStack()
	{
		deleteStack();
	}
	void push(const T& data)
	{
		Node<T>* nNode = new Node<T>(data, nullptr);
		nNode->next = Top;
		Top = nNode;
		size++;
	}
	void pop()
	{
		if (size == 0)
		{
			return;
		}
		Node<T>* tmp = Top;
		Top = Top->next;
		delete tmp;
		size--;
	}
	int getSize()
	{
		return size;
	}
	T getTop()
	{
		if (Top == nullptr)
		{
			return -1;
		}
		return Top->data;
	}
private:
	void deleteStack()
	{
		while (Top != nullptr)
		{
			Node<T>* tmp = Top;
			Top = Top->next;
			delete tmp;
			size = 0;
		}
	}
};