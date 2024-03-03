#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> s;
    int t, n;
    cin >> t;

    while (t--)
    {
        int opr;
        cin >> opr;
        if (opr == 1)
        {
            cin >> n;
            if (s.empty())
            {
                s.push(n);
            }
            else
            {
                int min_num = min(n, s.top());
                s.push(min_num);
            }
        }
        else if (opr == 2)
        {
            s.pop();
        }
        else if (opr == 3)
        {
            cout << s.top() << "\n";
        }
    }
}