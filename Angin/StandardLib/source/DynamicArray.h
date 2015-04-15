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
	//bool operator==(const T &rhs);
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
	T& operator[](unsigned int &index);

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
	void PushBack(T toPushBack);
	void PopBack();
	void Clear();
	unsigned int Size();

private:
	// Internal functions
	void Resize();

	// Variables
	T** m_array;
	unsigned int m_allocatedMemorySize;
	unsigned int m_usedMemorySize;
};

//#include "DynamicArray.cpp"

template <typename T>
DynamicArray<T>::DynamicArray()
{
	m_array = nullptr;
	m_allocatedMemorySize = 0;
	m_usedMemorySize = 0;
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
	if (m_array != nullptr)
	{
		for (unsigned int i = 0; i < m_usedMemorySize; i++)
		{
			delete m_array[i];
			m_array[i] = nullptr;
		}
		delete[] m_array;
		m_array = nullptr;
	}
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray &other)
{

}

template<typename T>
DynamicArray<T>::DynamicArray(DynamicArray && other)
{

}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other)
{

}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray && other)
{

}

template<typename T>
T& DynamicArray<T>::operator[](unsigned int &a_index)
{
	return *m_array[a_index];
}

template<typename T>
void DynamicArray<T>::PushBack(T a_toPushBack)
{
	if (m_usedMemorySize == m_allocatedMemorySize)
		Resize();

	m_array[m_usedMemorySize] = &a_toPushBack;
	m_usedMemorySize++;
}

template<typename T>
void DynamicArray<T>::PopBack()
{
	delete m_array[m_usedMemorySize];
	m_array = nullptr;
	m_usedMemorySize--;
}

template<typename T>
void DynamicArray<T>::Clear()
{
	for (unsigned int i = 0; i < m_usedMemorySize; i++)
	{
		delete m_array[i];
	}
	m_usedMemorySize = 0;
	m_allocatedMemorySize = 0;
}

template<typename T>
unsigned int DynamicArray<T>::Size()
{
	return m_usedMemorySize;
}

template<typename T>
void DynamicArray<T>::Resize()
{
	if (m_allocatedMemorySize == 0)
	{
		m_allocatedMemorySize = 8;
		m_array = new T*[m_allocatedMemorySize];
	}
	else
	{
		T** temp = new T*[m_allocatedMemorySize * 2];
		for (unsigned int i = 0; i < m_allocatedMemorySize; i++)
		{
			temp[i] = m_array[i];
		}
		m_array = temp;
		m_allocatedMemorySize *= 2;
	}
}