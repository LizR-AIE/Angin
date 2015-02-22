#pragma once

class String
{
public:	
	// Constructor
	String();
	// Constructor that takes in a char array
	String(char * string);
	// Destructor
	~String();
	// Copy assignment: leaves a copy there
	String & operator = (const String & other);
	// Move assignment: moves the data from other
	String & operator = (String && other);

	//Returns the current length of the String
	const unsigned int GetLength() const;
	
	// Returns the begining of the string as a char reference
	char & GetString() const;
	
	void UpdateLength();
		
private:
	char * m_charArray;

	unsigned int m_length;
};