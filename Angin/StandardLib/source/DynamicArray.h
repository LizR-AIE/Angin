#pragma once

#ifdef STANDARD_EXPORTS
#	define STANDARD_API __declspec(dllexport)
#else
#	define STANDARD_API __declspec(dllimport)
#endif

#pragma pack(push)

template<typename T>
class DynamicArray
{
public:
	//--------------------------------
	// Constructors and Destructor
	//--------------------------------
	STANDARD_API DynamicArray();
	STANDARD_API DynamicArray(const DynamicArray &other);
	STANDARD_API DynamicArray(DynamicArray && other);
	STANDARD_API ~DynamicArray();

	//--------------------------------
	// Assignment operators: 
	// copy and move assignment 
	// += -= *= /= %= &= |= ^= <<= >>=
	//--------------------------------
	STANDARD_API DynamicArray& operator=(const DynamicArray& other);
	STANDARD_API DynamicArray& operator=(DynamicArray && other);
	// +=		operator overload
	// -=		operator overload
	// *=		operator overload
	// /=		operator overload
	// %=		operator overload
	// &=		operator overload
	// |=		operator overload
	// ^=		operator overload
	// <<=		operator overload
	// >>=		operator overload

	//--------------------------------
	// Increment and Descrement: 
	// ++ --
	//--------------------------------
	// ++		operator overload
	// --		operator overload

	//--------------------------------
	// Arithmetic operators: 
	// unary +, - math: + - * / %
	//--------------------------------
	// +		unary operator overload
	// -		unary operator overload
	// +		addition operator overload
	// -		subtraction operator overload
	// *		operator overload
	// /		operator overload
	// %		operator overload

	//--------------------------------
	// Bitwise operators:
	// ~ & | ^ << >>
	//--------------------------------
	// ~		operator overload
	// &		operator overload
	// |		operator overload
	// ^		operator overload
	// <<		operator overload
	// >>		operator overload

	//--------------------------------
	// Logical operators:
	// ! && ||
	//--------------------------------
	// !		operator overload
	// &&		operator overload
	// ||		operator overload

	//--------------------------------
	// Comparison operators: 
	// < > <= >= == !=
	//--------------------------------
	// ==		operator overload
	// !=		operator overload
	// <		operator overload
	// >		operator overload
	// <=		operator overload
	// >=		operator overload
				
	//--------------------------------
	// Member access operators:
	// [] * & -> ->*
	//--------------------------------
	// []		operator overload

	// ->		operator overload
	// ->*		operator overload

	//--------------------------------
	// Other operators:
	// () , 
	//--------------------------------
	// ()		operator overload
	// ,		operator overload
	
	//--------------------------------
	// Special operators:
	// new delete new[] delete[]
	//--------------------------------
	// new		operator overload
	// delete	operator overload
	// new[]	operator overload
	// delete[]	operator overload
	
	//--------------------------------
	// Functions
	//--------------------------------
	STANDARD_API void PushBack(T &toPushBack);
	STANDARD_API void PopBack();
	STANDARD_API void Clear();
	STANDARD_API unsigned int Size();

private:
	// Internal functions
	STANDARD_API void Resize();

	// Variables
	T** m_array;
	unsigned int m_allocatedMemorySize;
	unsigned int m_usedMemorySize;
};

#include "DynamicArray.cpp"