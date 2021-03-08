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
	vector<int> reversePrint(ListNode* head)
	{
		vector<int>a;
		while (head)
		{
			a.push_back(head->val);
			head = head->next;
		}
		auto p1 = a.begin();
		auto p2 = a.rbegin();
		auto const pc = a.begin() + a.size() / 2;
		int c;
		while (p1 < pc)
		{
			c = *p1;
			*p1 = *p2;
			*p2 = c;
			++p1;
			++p2;
		}
		return a;
	}
};