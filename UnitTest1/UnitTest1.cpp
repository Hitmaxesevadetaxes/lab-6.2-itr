#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\HP\source\repos\lab 6.2 itr\lab 6.2 itr\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int size = 5; 
			int arr[size];
			{ 2, 4, 8, 10, 12; };
			int minOddIndex = findMinOddIndex(arr, size);
				int actual = -1;



				Assert::AreEqual(actual, minOddIndex);
		}
	};
}
