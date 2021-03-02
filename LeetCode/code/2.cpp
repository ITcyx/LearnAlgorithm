/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode a;
		ListNode* p = &a;
		int c = 0, t;
		while (l1 != nullptr&&l2 != nullptr)
		{
			t = l1->val + l2->val + c;
			p->next = new ListNode(t % 10);
			p = p->next;
			c = t / 10;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1 != nullptr)
		{
			t = l1->val + c;
			p->next = new ListNode(t % 10);
			p = p->next;
			c = t / 10;
			l1 = l1->next;
		}
		while (l2 != nullptr)
		{
			t = l2->val + c;
			p->next = new ListNode(t % 10);
			p = p->next;
			c = t / 10;
			l2 = l2->next;
		}
		if (c)
			p->next = new ListNode(c);
		return a.next;
	}
};