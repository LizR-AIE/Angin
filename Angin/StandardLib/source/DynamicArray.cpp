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
void DynamicArray<T>::PushBack(T a_toPushBack)
{
	if (m_usedMemorySize == m_allocatedMemorySize)
		Resize();
	
	m_array[m_usedMemorySize] = a_toPushBack;
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