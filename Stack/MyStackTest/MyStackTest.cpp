#include "pch.h"
#include "CppUnitTest.h"
#include "../stack/stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MyStackTest
{
	TEST_CLASS(MyStackTest)
	{
	public:
		TEST_METHOD(newStackSizeEqualsZero)
		{
			MyStack<int> tst;
			Assert::IsTrue(tst.getSize() == 0);
		}
		TEST_METHOD(after3Pushes_sizeEquals3)
		{
			MyStack<int> tst;			
			tst.push(5);
			tst.push(3);
			tst.push(2);
			Assert::IsTrue(tst.getSize() == 3);			
		}
		TEST_METHOD(popFromEmpty_sizeEqualsZero)
		{
			MyStack<int> tst;
			tst.pop();
			Assert::IsTrue(tst.getSize() == 0);
		}
		TEST_METHOD(getTopInEmptyStack_returnMinusAdin) 
		{
			MyStack<int> tst;
			Assert::IsTrue(tst.getTop() == -1);
		}
		TEST_METHOD(getTopTest)
		{
			MyStack<int> tst;
			tst.push(5);
			tst.push(3);
			tst.push(2);
			Assert::IsTrue(tst.getTop() == 2);
		}
	};
}