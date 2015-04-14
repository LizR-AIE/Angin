#pragma once

template<typename T>
class DynamicArray
{
public:
	//--------------------------------
	// Constructors and Destructor
	//--------------------------------
	DynamicArray();
	DynamicArray(const DynamicArray &other);
	DynamicArray(DynamicArray && other);
	~DynamicArray();

	//--------------------------------
	// Assignment operators: 
	// copy and move assignment 
	// += -= *= /= %= &= |= ^= <<= >>=
	//--------------------------------
	DynamicArray& operator=(const DynamicArray& other);
	DynamicArray& operator=(DynamicArray && other);
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
	
private:
	T* m_array;

};

#include "DynamicArray.cpp"