#include <iostream>

using namespace std;

struct ListNode
{
int       m_nKey;
ListNode* m_pNext;
};

ListNode* List_add(ListNode* p,int const& n)
{
    if(p->m_pNext==nullptr)
    {
        p->m_pNext=new ListNode;
        p=p->m_pNext;
        p->m_nKey=n;
        p->m_pNext=nullptr;
        return p;
    }
    p=p->m_pNext;
    p->m_nKey=n;
    return p;
}

int main()
{
    int a;
    size_t i,n,k;
    ListNode* head=new ListNode;
    ListNode* p;
    head->m_pNext=nullptr;
    while(cin>>n)
    {
        cin>>a;
        head->m_nKey=a;
        p=head;
        for(i=1;i<n;++i)
        {
            cin>>a;
            p=List_add(p,a);
        }
        cin>>k;
        if(k==0||k>n)
            cout<<0<<endl;
        else if(k<=n)
        {
            p=head;
            for(i=0;i<n-k;++i)
                p=p->m_pNext;
            cout<<p->m_nKey<<endl;
        }
    }
    return 0;
}