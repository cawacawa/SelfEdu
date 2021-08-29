#pragma once
#include <iostream>
#include <vector>


using namespace std;

template <typename T>
class BST 
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

	BST() 
		: root(nullptr)
	{}
	~BST() 
	{
		deleteTree(root);
	}

	bool find(T key) 
	{
		return find(root, key);
	}
	void insert(T key) 
	{
		insert(root, key);
	}
	void remove(T key) 
	{
		remove(root, key);
	}
	int size() 
	{
		return size(root);
	}
	template <typename T1> friend ostream& operator<< (ostream& os, BST<T1>& bst);
private:
	void deleteTree(Node<T>* root) 
	{
		if (root) 
		{
			deleteTree(root->left);
			deleteTree(root->right);
			delete root;
		}
		
	}
	bool find(Node<T>* stroot, T key) 
	{
		if (stroot == nullptr) 
		{
			return false;
		}
		if (stroot->inf == key) 
		{
			return true;
		}
		if (key < stroot->inf) 
		{
			return find(stroot->left, key);
		}
		return find(stroot->right, key);
	}
	Node<T>* insert(Node<T>* stroot, T key)
	{
		if (root == nullptr) 
		{
			root = new Node<T>(key);
			return root;
		}
		if (find(stroot, key))
		{
			return stroot;
		}
		if (stroot == nullptr)
		{			
			return new Node<T>(key);
		}
		if (key < stroot->inf)
		{
			stroot->left = insert(stroot->left, key);
		}
		if (key > stroot->inf)
		{
			stroot->right = insert(stroot->right, key);
		}
		
		return stroot;
	}
	Node<T>* remove(Node<T>* stroot, int key) {
		if (stroot == nullptr || stroot->inf == key) return deleteRoot(stroot);
		Node<T>* curr = stroot;
		while (1) {
			int x = curr->inf;
			if (key < x) {
				if (curr->left == nullptr || curr->left->inf == key) {
					curr->left = deleteRoot(curr->left);
					break;
				}
				curr = curr->left;
			}
			else {
				if (curr->right == nullptr || curr->right->inf == key) {
					curr->right = deleteRoot(curr->right);
					break;
				}
				curr = curr->right;
			}
		}
		return stroot;
	}
	Node<T>* deleteRoot(Node<T>* stroot) {
		if (!stroot || stroot->inf == 0)return nullptr;
		if (stroot->right == nullptr) return stroot->left;
		Node<T>* x = stroot->right;
		while (x->left)x = x->left;
		x->left = stroot->left;
		return stroot->right;
	}
	int size(Node<T>* stroot)
	{
		if (stroot == nullptr)
			return 0;
		else
			return(size(stroot->left) + 1 + size(stroot->right));
	}
	ostream& PreOrder(ostream& outstream, Node<T>* cur) 
	{
		if (cur != nullptr)
		{
			outstream << cur->inf << " ";
			PreOrder(outstream, cur->left);
			PreOrder(outstream, cur->right);
		}
		return outstream;
	}
};


