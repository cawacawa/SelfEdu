#include "pch.h"
#include "CppUnitTest.h"
#include "..\list\list.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MyListTest
{
	TEST_CLASS(MyListTest)
	{
	public:	
		TEST_METHOD(ConstructorTest)
		{
			MyList<int> testlist;
		    Assert::IsTrue(testlist.getSize() == 0, L"Size != 0");
		}
		TEST_METHOD(getElemByIndexInEmptyList)
		{
			MyList<int> testlist;
			Assert::IsTrue(testlist.getElemByIndex(2) == -1);			
		}
		TEST_METHOD(deleteElemFromEmptyList) 
		{
			MyList<int> testlist;
			testlist.deleteFromBegin();
		}
		TEST_METHOD(getElemIndex0) 
		{
			MyList<int> testlist;
			Assert::IsTrue(testlist.getElemByIndex(0) == -1);
		}
		TEST_METHOD(getSizeTest) 
		{
			MyList<int> testlist;
			testlist.addToBegin(3);
			Assert::IsTrue(testlist.getSize() == 1);
			testlist.addToBegin(2);
			Assert::IsTrue(testlist.getSize() == 2);
			testlist.addToBegin(1);
			Assert::IsTrue(testlist.getSize() == 3);
		}
	};
}
