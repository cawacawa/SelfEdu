#include "pch.h"
#include "..\bintree\bintree.h"

TEST(BinTree, insertAndSize) {
	BST<int> testtree;

	const size_t count = 5;
	testtree.insert(5);
	testtree.insert(10);
	testtree.insert(15);
	testtree.insert(2);
	testtree.insert(4);

	ASSERT_EQ(testtree.size(), count);
}
TEST(BinTree, remove) {
	BST<int> testtree;

	const size_t countAfterRemove = 4;
	testtree.insert(5);
	testtree.insert(10);
	testtree.insert(15);
	testtree.insert(2);
	testtree.insert(4);

	testtree.remove(15);
    ASSERT_EQ(testtree.size(), countAfterRemove);
		
	testtree.remove(20);
	ASSERT_EQ(testtree.size(), countAfterRemove);
}
TEST(BinTree, find) 
{
	BST<int> testtree;
	testtree.insert(5);
	testtree.insert(10);
	testtree.insert(15);
	testtree.insert(2);
	testtree.insert(4);

	ASSERT_EQ(testtree.find(15), true);
	ASSERT_EQ(testtree.find(20), false);
}