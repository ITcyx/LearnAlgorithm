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
	ListNode* partition(ListNode* head, int x)
	{
		if (head == nullptr)
			return head;
		ListNode* i = head;
		while (i)
		{
			if (i->val >= x)
				break;
			i = i->next;
		}
		if (i)
		{
			ListNode* j;
			int t;
			j = i->next;
			while (j)
			{
				if (j->val < x)
				{
					t = j->val;
					j->val = i->val;
					i->val = t;
					i = i->next;
				}
				j = j->next;
			}
		}
		return head;
	}
};