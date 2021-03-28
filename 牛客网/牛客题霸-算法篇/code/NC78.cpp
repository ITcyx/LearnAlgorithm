/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution
{
public:
	ListNode* ReverseList(ListNode* pHead)
	{
		if (pHead == nullptr)
			return  nullptr;
		ListNode* head = pHead->next, *t;
		pHead->next = nullptr;
		while (head)
		{
			t = head->next;
			head->next = pHead;
			pHead = head;
			head = t;
		}
		return pHead;
	}
};