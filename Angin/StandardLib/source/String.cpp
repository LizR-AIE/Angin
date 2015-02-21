#include "String.h"

String::String()
{
	charArray = nullptr;
}

String::~String()
{

}

const unsigned int String::Length()
{
	if (charArray == nullptr)
		return 0;

	unsigned int length = 0;
	
	char ** charArrayPointer = &charArray;
	
	while (charArrayPointer != 0)
	{
		length++;
	}

	return length;
}