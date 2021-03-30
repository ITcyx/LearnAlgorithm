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
	bool hasCycle(ListNode* head)
	{
		if (head == nullptr)
			return false;
		ListNode* slow = head->next;
		ListNode* fast;
		if (slow != nullptr)
			fast = slow->next;
		else
			fast = nullptr;
		while (fast != nullptr&&slow != nullptr)
		{
			if (fast == slow)
				return true;
			slow = slow->next;
			if (fast->next != nullptr)
				fast = fast->next->next;
			else
				fast = nullptr;
		}
		return false;
	}
};