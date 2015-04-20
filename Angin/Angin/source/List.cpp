#include "List.h"

List::List()
{
	SentinelBeginNode.next = &SentinelEndNode;
	SentinelEndNode.prev = &SentinelBeginNode;
}

List::~List()
{
	
}

void List::Add(int a_value)
{
	ListNode * foo = new ListNode();
	foo->value = a_value;
	
	foo->prev = SentinelEndNode.prev;
	SentinelEndNode.prev->next = foo;
	foo->next = &SentinelEndNode;
	SentinelEndNode.prev = foo;
}