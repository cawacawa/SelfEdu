#include "bintree.h"


template <typename T1>
ostream& operator<< (ostream& os, BST<T1>& bst)
{
   return bst.PreOrder(os, bst.root);
}



int main() 
{
	BST<int> bst;
	vector<int> toInsert;
	while (cin.get() != '\n') 
	{
		int i = 0;
		cin >> i;
		toInsert.push_back(i);
	}
    for (int i : toInsert)
	{
		bst.insert(i);
	}

	

	vector<int> toDelete;
	while (cin.get() != '\n')
	{
		int j = 0;
		cin >> j;
		toDelete.push_back(j);
	}
	for (int j : toDelete)
	{
		bst.remove(j);
	}


	cout << bst;

	return 0;
}