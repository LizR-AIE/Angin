#pragma once

class String
{
public:	
	// Constructor
	String();
	// Constructor that takes in a char array
	String(char * string);
	// Copy constructor
	String(const String & other);
	// Move constructor
	String(String && other);
	// Destructor
	~String();
	// Copy assignment: leaves a copy there
	String & operator = (const String & other);
	// Move assignment: moves the data from other
	String & operator = (String && other);
	// + operator: returns a string that contains the two strings
	String operator + (const String & other) const;
	// += operator: adds the other string to this string
	String & operator += (const String & other);
	// == operator: returns true if the two strings are the same
	bool operator == (const String & other);
	// != operator: returns true if the two strings are different
	bool operator != (const String & other);
	// Returns the current length of the String
	const unsigned int GetLength() const;
	// Returns the begining of the string as a char reference
	char & GetString() const;
	// Recalculate the length of the string
	void UpdateLength();
		
private:
	char * m_charArray;

	unsigned int m_length;
};