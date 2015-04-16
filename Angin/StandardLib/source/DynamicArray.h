#pragma once

template<typename T>
class DynamicArray
{
public:
	T operator[](unsigned int a_index)	
	{
		return m_array[a_index];
	}
	
	//--------------------------------
	// Constructors and Destructor
	//--------------------------------
	DynamicArray()
	{
		m_array = nullptr;
		m_allocatedMemorySize = 0;
		m_usedMemorySize = 0;
	}
		
	~DynamicArray()
	{
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}
	void PushBack(T a_toPushBack)
	{
		if (m_usedMemorySize == m_allocatedMemorySize)
			Resize();

		m_array[m_usedMemorySize] = a_toPushBack;
		m_usedMemorySize++;
	}
	
	void PopBack()
	{
		delete m_array[m_usedMemorySize];
		m_array = nullptr;
		m_usedMemorySize--;
	}

	void Clear()
	{
		for (unsigned int i = 0; i < m_usedMemorySize; i++)
		{
			delete m_array[i];
		}
		m_usedMemorySize = 0;
		m_allocatedMemorySize = 0;
	}

	unsigned int Size()
	{
		return m_usedMemorySize;
	}

private:
	// Internal functions
	void Resize()
	{
		if (m_allocatedMemorySize == 0)
		{
			m_allocatedMemorySize = 8;
			m_array = new T[m_allocatedMemorySize];
		}
		else
		{
			T* temp = new T[m_allocatedMemorySize * 2];
			for (unsigned int i = 0; i < m_allocatedMemorySize; i++)
			{
				temp[i] = m_array[i];
			}
			m_array = temp;
			m_allocatedMemorySize *= 2;
		}
	}

	// Variables
	T* m_array;
	unsigned int m_allocatedMemorySize;
	unsigned int m_usedMemorySize;
};

