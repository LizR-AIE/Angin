#pragma once
#include "ListNode.h"

class List
{
public:
	List();
	~List();

	void Add(int value);
	
	// insert before
	// insert after
	// remove
	// find
	// clear

	ListNode SentinelBeginNode;
	ListNode SentinelEndNode;

	ListNode* begin() { return SentinelBeginNode.next; }
	ListNode* end() { return SentinelEndNode.prev; }
};