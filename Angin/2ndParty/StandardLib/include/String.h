#pragma once

#ifdef STANDARD_EXPORTS
#	define STANDARD_API __declspec(dllexport)
#else
#	define STANDARD_API __declspec(dllimport)
#endif

#pragma pack(push)

class String
{
public:	
	// Constructor
	STANDARD_API String();
	// Constructor that takes in a char array
	STANDARD_API String(char * string);
	// Copy constructor
	STANDARD_API String(const String & other);
	// Move constructor
	STANDARD_API String(String && other);
	// Destructor
	STANDARD_API ~String();
	// Copy assignment: leaves a copy there
	STANDARD_API String & operator = (const String & other);
	// Move assignment: moves the data from other
	STANDARD_API String & operator = (String && other);
	// + operator: returns a string that contains the two strings
	STANDARD_API String operator + (const String & other) const;
	// += operator: adds the other string to this string
	STANDARD_API String & operator += (const String & other);
	// == operator: returns true if the two strings are the same
	STANDARD_API bool operator == (const String & other);
	// != operator: returns true if the two strings are different
	STANDARD_API bool operator != (const String & other);
	
	// Returns the current length of the String
	STANDARD_API const unsigned int GetLength() const;
	// Returns the beginning of the string as a char pointer
	STANDARD_API char * GetString() const;

	// Set the string
	STANDARD_API void SetString(const char * string);
		
private:
	// Recalculate the length of the string
	STANDARD_API void UpdateLength();

	char * m_charArray;

	unsigned int m_length;
};
#pragma pack(pop)