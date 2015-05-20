#include "String.h"

String::String()
{
	m_charArray = nullptr;
	m_length = 0;
}

String::String(char * a_string)
{
	// Make a pointer to the string arguement
	const char * ptr = a_string;

	// Reset the length
	m_length = 0;

	// Incriment the pointer and the length until we get to the null turminator
	while (*ptr != 0)
	{
		m_length++;
		ptr++;
	}

	// Create memory for our new char[]
	m_charArray = new char[m_length + 1];

	// copy over the data from the arguement to this
	for (unsigned int i = 0; i < m_length; i++)
	{
		m_charArray[i] = a_string[i];
	}

	// add the null turminator
	m_charArray[m_length] = 0;
}

String::String(const String & a_other)
{
	m_length = a_other.m_length;
	m_charArray = new char[m_length + 1];

	for (unsigned int i = 0; i < m_length; i++)
	{
		// Copy over the data from the other string into this string
		m_charArray[i] = a_other.m_charArray[i];
	}
	// add a null turminator to the end of the char array
	m_charArray[m_length] = 0;
}

String::String(String && a_other)
{
	// move across the length of the string
	m_length = a_other.m_length;
	// create memory that is long enough for the string plus a null terminator				
	m_charArray = new char[m_length + 1]{0};
	// copy over the data from the other string
	for (unsigned int i = 0; i < m_length; i++)
	{
		m_charArray[i] = a_other.m_charArray[i];
	}
	// add the null terminator
	m_charArray[m_length] = 0;
	// free the memory used for the other string
	delete[] a_other.m_charArray;
	// make the memory null
	a_other.m_charArray = nullptr;
}

String::~String()
{
	if (m_charArray != nullptr)
	{
		delete[] m_charArray;
		m_charArray = nullptr;
	}
	m_length = 0;
}

String & String::operator=(const String & a_other)
{
	m_length = a_other.m_length;
	m_charArray = new char[m_length + 1];
	
	for (unsigned int i = 0; i < m_length; i++)
	{
		// Copy over the data from the other string into this string
		m_charArray[i] = a_other.m_charArray[i];
	}
	// add a null turminator to the end of the char array
	m_charArray[m_length] = 0;

	return *this;
}

String & String::operator=(String && a_other)
{
	if (*this != a_other)
	{
		// free out current string
		delete[] m_charArray;
		// move across the length of the string
		m_length = a_other.m_length;
		// create memory that is long enough for the string plus a null terminator				
		m_charArray = new char[m_length + 1]{0};
		// copy over the data from the other string
		for (unsigned int i = 0; i < m_length; i++)
		{
			m_charArray[i] = a_other.m_charArray[i];
		}
		// add the null terminator
		m_charArray[m_length] = 0;
		// free the memory used for the other string
		delete[] a_other.m_charArray;
		// make the memory null
		a_other.m_charArray = nullptr;
	}
	return *this;
}

String String::operator+(const String & a_other) const
{
	// Create the string to return
	String temp;
	// Calculate the length of the new string
	temp.m_length = m_length + a_other.m_length;
	// Allocate memory for the string to be stored in
	temp.m_charArray = new char[temp.m_length + 1];
	// copy the string from this to the new string
	for (unsigned int i = 0; i < m_length; i++)
	{
		temp.m_charArray[i] = m_charArray[i];
	}
	// copy the string from the other string into the new string
	unsigned int j = 0;
	for (unsigned int i = m_length; i < temp.m_length; i++)
	{
		temp.m_charArray[i] = a_other.m_charArray[j];
		j++;
	}
	// add a null terminator to the end
	temp.m_charArray[temp.m_length] = 0;

	return temp;
}

String & String::operator+=(const String & a_other)
{
	return *this = *this + a_other;
}

bool String::operator==(const String & a_other)
{
	if (m_length != a_other.GetLength())
		return false;

	for (unsigned int i = 0; i < m_length; i++)
	{
		if (m_charArray[i] != a_other.m_charArray[i])
			return false;
	}

	return true;
}

bool String::operator!=(const String & a_other)
{
	return !(*this == a_other);
}

const unsigned int String::GetLength() const
{
	return m_length;
}

char * String::GetString() const
{
	return m_charArray;
}

void String::SetString(const char * a_string)
{
	// Check if there is data already there
	if (m_charArray != nullptr)
	{
		// if so, delete it
		delete[] m_charArray;
		m_charArray = nullptr;
	}

	// Make a pointer to the string arguement
	const char * ptr = a_string;

	// Reset the length
	m_length = 0;

	// Incriment the pointer and the length until we get to the null turminator
	while (*ptr != 0)
	{
		m_length++;
		ptr++;
	}

	// Create memory for our new char[]
	m_charArray = new char[m_length + 1];

	// copy over the data from the arguement to this
	for (unsigned int i = 0; i < m_length; i++)
	{
		m_charArray[i] = a_string[i];
	}

	// add the null turminator
	m_charArray[m_length] = 0;
}

void String::UpdateLength()
{
	m_length = 0;
	char ** charPointer = &m_charArray;
	while (charPointer != 0)
	{
		m_length++;
	}
}