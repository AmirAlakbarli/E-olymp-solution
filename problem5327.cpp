#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string str;
    cin >> str;
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (s.empty())
            s.push(ch);
        else if (ch == ')' && s.top() == '(')
            s.pop();
        else
            s.push(ch);
    }
    if (s.empty())
        cout << "YES\n";
    else
        cout << "NO\n";
}