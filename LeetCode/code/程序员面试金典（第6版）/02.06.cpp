/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
	bool isPalindrome(ListNode* head)
	{
		if (head == nullptr || head->next == nullptr)
			return true;
		size_t len = 2;
		ListNode* tail = head->next;
		ListNode* p = head->next->next;
		while (p)
		{
			tail = p;
			++len;
			p = tail->next;
		}
		ListNode *q, *t;
		size_t i;
		size_t const mid = len / 2;
		p = head;
		for (i = 0; i < mid; ++i)
			p = p->next;
		q = p->next;
		while (q)
		{
			t = q->next;
			q->next = p;
			p = q;
			q = t;
		}
		for (i = 0; i < mid; ++i)
		{
			if (head->val != tail->val)
				return false;
			head = head->next;
			tail = tail->next;
		}
		return true;
	}
};