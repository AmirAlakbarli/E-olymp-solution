#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){};
};

int DistanceToCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            fast = head;
            int cnt = 0;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
                cnt++;
            }
            return cnt;
        }
    }
    return -1;
}

int main()
{
    ListNode *n1 = new ListNode(1), *n2 = new ListNode(2), *n3 = new ListNode(3), *n4 = new ListNode(4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;
    cout << DistanceToCycle(n1);
}