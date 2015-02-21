#pragma once

class String
{
public:
	
	// Constructor
	String();
	// Destructor
	~String();
	// Copy assignment
	String& operator=(const String &other);
	// Move assignment
	String& operator=(String&& other);

	const unsigned int Length();

	char * charArray;
};

