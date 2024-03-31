#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

ListNode *MiddleElement(ListNode *head)
{
    ListNode *res = head;
    int count = 0;
    while (head != nullptr)
    {
        count++;
        head = head->next;
    }
    count = (count - 1) / 2;
    while (count--)
    {
        res = res->next;
    }
    return res;
}

int main()
{
    ListNode *n1 = new ListNode(1), *n2 = new ListNode(2), *n3 = new ListNode(3), *n4 = new ListNode(4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    ListNode *res = MiddleElement(n1);
    cout << res->val << '\n';
    return 0;
}