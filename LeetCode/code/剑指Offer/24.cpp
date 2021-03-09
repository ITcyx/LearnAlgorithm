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
	ListNode* reverseList(ListNode* head)
	{
		ListNode *p = nullptr, *q;
		while (head)
		{
			q = head->next;
			head->next = p;
			p = head;
			head = q;
		}
		return p;
	}
};