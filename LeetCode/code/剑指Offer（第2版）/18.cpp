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
	ListNode* deleteNode(ListNode* head, int const& val)
	{
		if (head->val == val)
			return head->next;
		ListNode* next;
		ListNode* pre;
		pre = head;
		next = head->next;
		while (next)
		{
			if (next->val == val)
			{
				pre->next = next->next;
				return head;
			}
			pre = next;
			next = next->next;
		}
		return head;
	}
};