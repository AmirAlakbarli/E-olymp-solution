#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    string s;

    while (t--)
    {
        cin >> n;
        cin >> s;
        stack<char> stk;

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (stk.empty())
            {
                stk.push(ch);
            }
            else if (ch == '<' && stk.top() == '>')
            {
                stk.pop();
            }
            else
            {
                stk.push(ch);
            }
        }
        if (stk.empty())
        {
            cout << "legal" << endl;
        }
        else
        {
            cout << "illegal" << endl;
        }
    }
}