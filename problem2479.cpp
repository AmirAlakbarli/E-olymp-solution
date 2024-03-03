#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string str;
        getline(cin, str);
        stack<int> s;
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            if (s.empty())
                s.push(ch);
            else if (ch == ')' && s.top() == '(')
                s.pop();
            else if (ch == ']' && s.top() == '[')
                s.pop();
            else
                s.push(ch);
        }
        if (s.empty())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}