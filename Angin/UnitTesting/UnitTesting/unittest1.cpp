#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\..\StandardLib\source\String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesting
{		
	TEST_CLASS(Strings)
	{
	public:
		
		// TEST: Default constructor
		TEST_METHOD(ConstructorDefault)
		{
			String myString;
			
			char * expected = nullptr;
			char * actual = myString.GetString();
			
			Assert::AreEqual(expected, actual, L"Default Constructor failed");
		}
		
		// TEST: Constructor that takes a char*
		TEST_METHOD(ConstructorCharPtr)
		{
			// Create the expected char[]
			char * expected = "Hello World";
			
			// Create a string and pass in the expected
			String myString(expected);
			
			// Get the actual
			char * actual = myString.GetString();

			// Compare
			for (unsigned int i = 0; i < myString.GetLength(); i++)
			{
				Assert::AreEqual(expected[i], actual[i], L"Constructor that takes a char* failed");
			}
		}

		// TEST: GetString and SetString
		TEST_METHOD(GettersAndSetters)
		{
			// Create the expected char[]
			char * expected = "Hello World";
			
			// Create a string that is null
			String myString;
						
			// Set the expected
			myString.SetString(expected);
						
			// Get the actual
			char * actual = myString.GetString();
			
			// Compare
			for (unsigned int i = 0; i < myString.GetLength(); i++)
			{
				Assert::AreEqual(expected[i], actual[i], L"Set/Get String failed");
			}
		}

		// TEST: GetLength
		TEST_METHOD(GetLength)
		{
			String myString("Hello World");

			unsigned int expected = 11;
			unsigned int actual = myString.GetLength();

			Assert::AreEqual(expected, actual, L"GetLength test failed");
		}

		// TEST: Copy Constructor
		TEST_METHOD(CopyConstructor)
		{
			String myString1("Hello");
			String myString2(myString1);
			Assert::IsTrue(myString1 == myString2, L"Copy Constructor test failed");
		}
		// TEST: Copy Assignment
		TEST_METHOD(CopyAssignment)
		{
			String myString1("Hello");
			String myString2 = myString1;
			Assert::IsTrue(myString1 == myString2, L"Copy assignment test failed");
		}
		
		// TEST: + operator and Move Constructor
		TEST_METHOD(ConcatinateConstructor)
		{
			String myString1("Hello");
			String myString2;
			myString2.SetString(" World");
			String myString3(myString1 + myString2);
			Assert::AreEqual("Hello World", myString3.GetString(), L"Concatinate using a constructor test failed");
		}

		// TEST: Move Assignment
		TEST_METHOD(ConcatinateAssignment)
		{
			String myString1("Hello");
			String myString2;
			myString2.SetString(" World");
			myString1 = myString1 + myString2;
			Assert::AreEqual("Hello World", myString1.GetString(), L"Concatinate using assignment test failed");
		}

		// TEST: += operator
		TEST_METHOD(AdditionAssignment)
		{
			String myString1("Hello ");
			String myString2("World");
			myString1 += myString2;
			Assert::AreEqual("Hello World", myString1.GetString(), L"Addition Assignment test failed");
		}

		// TEST: == operator
		TEST_METHOD(IsEqual)
		{
			String myString1("Hello World");
			String myString2;
			myString2.SetString("Hello World");
			Assert::IsTrue(myString1 == myString2, L"Is equal test failed");
		}

		// TEST: != operator
		TEST_METHOD(IsNotEqual)
		{
			String myString1("HelloWorld");
			String myString2;
			myString2.SetString("Hello World");
			Assert::IsTrue(myString1 != myString2, L"Is not equal test failed");
		}
	};
}