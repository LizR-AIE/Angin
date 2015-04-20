#pragma once
#include "ListNode.h"

#ifdef ANGIN_EXPORTS
#	define ANGIN_API __declspec(dllexport)
#else
#	define ANGIN_API __declspec(dllimport)
#endif

class List
{
public:
	ANGIN_API List();
	ANGIN_API ~List();

	ANGIN_API void Add(int value);
	ANGIN_API ListNode* Find(int value);
	ANGIN_API void InsertBefore(ListNode * node, int value);
	ANGIN_API void InsertAfter(ListNode * node, int value);
	ANGIN_API void Remove(ListNode * node);
	ANGIN_API void Clear();

	ListNode SentinelBeginNode;
	ListNode SentinelEndNode;

	ANGIN_API ListNode* begin() { return SentinelBeginNode.next; }
	ANGIN_API ListNode* end() { return SentinelEndNode.prev; }
};