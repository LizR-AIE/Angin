template <typename T>
DynamicArray<T>::DynamicArray()
{
	m_array = nullptr;
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
	if (m_array != nullptr)
	{
		delete m_array;
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