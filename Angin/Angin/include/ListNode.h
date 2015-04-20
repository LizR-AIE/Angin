#pragma

#ifdef ANGIN_EXPORTS
#	define ANGIN_API __declspec(dllexport)
#else
#	define ANGIN_API __declspec(dllimport)
#endif

class ListNode
{
public:
	ANGIN_API ListNode();
	ANGIN_API ~ListNode();

	int value;

	ListNode * next;
	ListNode * prev;
};