#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){};
};

ListNode *DeleteFirstElement(ListNode *head, int element)
{
    ListNode *temp = head;
    if (head->val == element)
    {
        head = head->next;
        delete temp;
        return head;
    }
    while (temp->next != NULL)
    {
        if (temp->next->val == element)
        {
            ListNode *temp2 = temp->next;
            temp->next = temp->next->next;
            delete temp2;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    ListNode *n1 = new ListNode(1), *n2 = new ListNode(2), *n3 = new ListNode(3), *n4 = new ListNode(4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n1 = DeleteFirstElement(n1, 2);
    while (n1 != NULL)
    {
        cout << n1->val << " ";
        n1 = n1->next;
    }
}