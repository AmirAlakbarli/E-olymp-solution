#include <iostream>

using namespace std;

class ListNode
{
public:
    ListNode *next;
    int data;

    ListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

int hasCycle(ListNode *head)
{
    ListNode *p = head, *q = head;
    while (q != nullptr)
    {
        p = p->next;
        if (q->next == nullptr)
            break;
        q = q->next->next;

        if (p == q)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    ListNode *n1 = new ListNode(1), *n2 = new ListNode(2), *n3 = new ListNode(3), *n4 = new ListNode(4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;
    cout << hasCycle(n1);
}