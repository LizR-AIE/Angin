#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\StandardLib\source\DynamicArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DynamicArrayUT
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			DynamicArray<int> * da = new DynamicArray<int>();
			da->PushBack(23);
			da->PushBack(64);
			Assert::IsTrue(da->Size() == 1);
			int t = (*da)[1];
			Assert::IsTrue((*da)[0] == 23);

		}

	};
}