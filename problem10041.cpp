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

void PrintReverse(ListNode *head)
{
    if (head == NULL)
        return;
    PrintReverse(head->next);
    cout << head->data << " ";
}

int main()
{
    ListNode *n1 = new ListNode(12), *n2 = new ListNode(13);
    n1->next = n2;
    PrintReverse(n1);
}