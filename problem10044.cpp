#include <iostream>

using namespace std;

class ListNode
{
public:
    ListNode *next;
    int val;

    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

ListNode *merge(ListNode *l1, ListNode *l2)
{
    ListNode *res = new ListNode(0);
    ListNode *temp = res;
    while (true)
    {
        if (l1 == nullptr)
        {
            temp->next = l2;
            break;
        }
        if (l2 == nullptr)
        {
            temp->next = l1;
            break;
        }

        if (l1->val < l2->val)
        {
            temp->next = l1;
            l1 = l1->next;
        }
        else
        {
            temp->next = l2;
            l2 = l2->next;
        }

        temp = temp->next;
    }

    return res->next;
}

int main()
{
    ListNode *l1_n1 = new ListNode(1);
    ListNode *l1_n2 = new ListNode(4);
    l1_n1->next = l1_n2;
    ListNode *l1_n3 = new ListNode(7);
    l1_n2->next = l1_n3;
    ListNode *l1_n4 = new ListNode(8);
    l1_n3->next = l1_n4;
    ListNode *l1_n5 = new ListNode(9);
    l1_n4->next = l1_n5;

    ListNode *l2_n1 = new ListNode(2);
    ListNode *l2_n2 = new ListNode(6);
    l2_n1->next = l2_n2;
    ListNode *l2_n3 = new ListNode(8);
    l2_n2->next = l2_n3;

    ListNode *res = merge(l1_n1, l2_n1);

    while (res != nullptr)
    {
        cout << res->val << " ";
        res = res->next;
    }
}