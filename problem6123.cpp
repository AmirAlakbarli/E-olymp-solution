#include <iostream>
#include <stack>

using namespace std;

class MyStack
{
public:
    stack<int> s;
    void push(int n)
    {
        s.push(n);
        cout << "ok\n";
    }

    void pop()
    {
        if (s.empty())
        {
            cout << "error\n";
        }
        else
        {
            cout << s.top() << '\n';
            s.pop();
        }
    }

    int *back()
    {
        return s.empty() ? nullptr : &s.top();
    }

    int size()
    {
        return (int)s.size();
    }

    void clear()
    {
        s = stack<int>();
        cout << "ok\n";
    }

    void exit()
    {
        cout << "bye\n";
    }
};

int main()
{
    MyStack customStack;

    while (true)
    {
        string oper;
        cin >> oper;
        if (oper == "exit")
        {
            customStack.exit();
            break;
        }
        else if (oper == "push")
        {
            int num;
            cin >> num;
            customStack.push(num);
        }
        else if (oper == "back")
        {
            int *lastEl = customStack.back();
            lastEl ? cout << *lastEl << '\n' : cout << "error\n";
        }
        else if (oper == "size")
        {
            int sz = customStack.size();
            cout << sz << '\n';
        }
        else if (oper == "pop")
        {
            customStack.pop();
        }
        else if (oper == "clear")
        {
            customStack.clear();
        }
    }
}