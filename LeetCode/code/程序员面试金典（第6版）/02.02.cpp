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
	int kthToLast(ListNode* head, int const& k)
	{
		int i;
		ListNode *p, *q;
		q = head;
		for (i = 1; i < k; ++i)
			q = q->next;
		p = head;
		while (q->next)
		{
			q = q->next;
			p = p->next;
		}
		return p->val;
	}
};