#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string str;
    stack<int> s;
    while (cin >> str)
    {
        if (str == "+")
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            int res = a + b;
            s.push(res);
        }
        else if (str == "-")
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            int res = a - b;
            s.push(res);
        }
        else if (str == "*")
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            int res = a * b;
            s.push(res);
        }
        else if (str == "/")
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            int res = a / b;
            s.push(res);
        }
        else
        {
            int num = stoi(str);
            s.push(num);
        }
    }

    cout << s.top() << '\n';
}