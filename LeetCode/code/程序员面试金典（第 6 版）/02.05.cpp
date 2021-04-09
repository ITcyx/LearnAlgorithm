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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* s=new ListNode;
        ListNode* h=s;
        ListNode* p1=l1;
        ListNode* p2=l2;
        int c=0,t;
        while(p1&&p2)
        {
            t=p1->val+p2->val+c;
            s->next=new ListNode(t%10);
            c=t/10;
            s=s->next;
            p1=p1->next;
            p2=p2->next;
        }
        while(p1)
        {
            if(c)
            {
                t=p1->val+c;
                s->next=new ListNode(t%10);
                c=t/10;
            }
            else
                s->next =new ListNode(p1->val);
            s=s->next;
            p1=p1->next;
        }
        while(p2)
        {
            if(c)
            {
                t=p2->val+c;
                s->next=new ListNode(t%10);
                c=t/10;
            }
            else
                s->next =new ListNode(p2->val);
            s=s->next;
            p2=p2->next;
        }
        if(c)
            s->next=new ListNode(c);
        return h->next;
    }
};