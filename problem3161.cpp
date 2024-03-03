#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> deq[150000];
    int t;
    cin >> t;

    while (t--)
    {
        string opr;
        cin >> opr;

        if (opr == "pushfront")
        {
            int A, B;
            cin >> A >> B;
            deq[A - 1].push_front(B);
        }
        else if (opr == "pushback")
        {
            int A, B;
            cin >> A >> B;
            deq[A - 1].push_back(B);
        }
        else if (opr == "popfront")
        {
            int A;
            cin >> A;
            cout << deq[A - 1].front() << "\n";
            deq[A - 1].pop_front();
        }
        else if (opr == "popback")
        {
            int A;
            cin >> A;
            cout << deq[A - 1].back() << "\n";
            deq[A - 1].pop_back();
        }
    }
}