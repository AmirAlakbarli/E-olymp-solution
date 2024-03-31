#include <iostream>

using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

ListNode *detectCycle(ListNode *head)
{
    ListNode *p = head, *q = head;
    while (q != nullptr)
    {
        p = p->next;
        if (q->next == nullptr)
            return NULL;
        q = q->next->next;

        if (p == q)
        {
            break;
        }
    }

    if (q == nullptr)
        return NULL;

    q = head;
    int cnt = 0;
    while (q != p)
    {
        p = p->next;
        q = q->next;
        cnt++;
    }
    return p;
}

int main()
{
    ListNode *n1 = new ListNode(1), *n2 = new ListNode(2), *n3 = new ListNode(3), *n4 = new ListNode(4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;
    cout << detectCycle(n1)->data;
}