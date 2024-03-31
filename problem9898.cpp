#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int sum(ListNode *head)
{
    ListNode *temp = head;
    int res = 0;
    while (temp != NULL)
    {
        res = res + temp->val;
        temp = temp->next;
    }
    return res;
}

int main()
{
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    node1->next = node2;
    ListNode *node3 = new ListNode(3);
    node2->next = node3;

    cout << sum(node1);
}