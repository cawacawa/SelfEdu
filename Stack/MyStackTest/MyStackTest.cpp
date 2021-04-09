#include "pch.h"
#include "CppUnitTest.h"
#include "../stack/stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MyStackTest
{
	TEST_CLASS(MyStackTest)
	{
	public:
		TEST_METHOD(constructor)
		{
			MyStack<int> tst;
			Assert::IsTrue(tst.getSize() == 0);
		}
		TEST_METHOD(pushsizeTest)
		{
			MyStack<int> tst;
			Assert::IsTrue(tst.getSize() == 0);
			tst.push(5);
			Assert::IsTrue(tst.getSize() == 1);
			tst.push(6);
			Assert::IsTrue(tst.getSize() == 2);
		}
		TEST_METHOD(popFromEmpty)
		{
			MyStack<int> tst;
			tst.pop();
			Assert::IsTrue(tst.getSize() == 0);
		}
		TEST_METHOD(popsizeTest)
		{
			MyStack<int> tst;
			tst.push(1);
			tst.push(2);
			tst.push(3);
			Assert::IsTrue(tst.getSize() == 3);
			tst.pop();
			Assert::IsTrue(tst.getSize() == 2);
			tst.pop();
			Assert::IsTrue(tst.getSize() == 1);
		}
		TEST_METHOD(destr)
		{
			MyStack<int> tst;
			tst.push(1);
			tst.push(2);
			tst.push(3);
			tst.~MyStack();
		}
		TEST_METHOD(deleteEmpty)
		{
			MyStack<int> tst;
			tst.~MyStack();
		}
		TEST_METHOD(getTopTest)
		{
			MyStack<int> tst;
			Assert::IsTrue(tst.getTop() == -1, L"1st assert");
			tst.push(3);
			Assert::IsTrue(tst.getTop() == 3, L"2nd assert");
			tst.push(4);
			Assert::IsTrue(tst.getTop() == 4, L"3d assert");
			tst.push(5);
			Assert::IsTrue(tst.getTop() == 5, L"4th assert");
		}
	};
}