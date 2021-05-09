#pragma once


template <typename T>
class MyBinTree 
{
	template<typename T>
	struct Node
	{
		T inf;
		Node* right;
		Node* left;
		Node(const T& inf)
			: inf(inf)
			, right(nullptr)
			, left(nullptr)
		{}
	};
	Node<T>* root;
public:
	MyBinTree() 
	{
		root = nullptr;
	}
	~MyBinTree() 
	{
		deleteTree(&root);
	}
	void add(T data) {
		Node<T>** cur = &root;
		while (*cur) {
			Node<T>& node = **cur;
			if (data < node.inf) {
				cur = &node.left;
			}
			else if (data > node.inf) {
				cur = &node.right;
			}
			else {
				return;
			}
		}
		*cur = new Node<T>(data);
	}
private:
	void deleteTree(Node<T>** root) 
	{
		if (*root) 
		{
			deleteTree(&((*root)->left));
			deleteTree(&((*root)->right));
			delete *root;
		}
	}
};