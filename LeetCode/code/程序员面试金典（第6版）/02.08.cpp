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
	ListNode *detectCycle(ListNode *head)
	{
		if (head == nullptr)
			return nullptr;
		ListNode *fast = head, *slow = head;
		while (fast->next != nullptr&&fast->next->next != nullptr)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
			{
				fast = head;
				while (fast != slow)
				{
					fast = fast->next;
					slow = slow->next;
				}
				return fast;
			}
		}
		return nullptr;
	}
};