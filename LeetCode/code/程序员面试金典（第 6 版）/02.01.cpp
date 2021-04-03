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
	bool hash_table[20001];

public:
	ListNode* removeDuplicateNodes(ListNode* head)
	{
		if (head == nullptr)
			return head;
		bool* hash_j = hash_table + 20001;
		for (bool* hash_i = hash_table; hash_i != hash_j; ++hash_i)
			*hash_i = true;
		ListNode* h = head;
		hash_table[h->val] = false;
		for (ListNode* p = head->next; p; p = p->next)
			if (hash_table[p->val])
			{
				hash_table[p->val] = false;
				h->next = p;
				h = p;
			}
		h->next = nullptr;
		return head;
	}
};