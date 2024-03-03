#include <iostream>
#include <stack>

using namespace std;

class MyStack
{
public:
    stack<int> s;
    string push(int n)
    {
        s.push(n);
        return "ok\n";
    }

    int pop()
    {
        int res = s.top();
        s.pop();
        return res;
    }

    int back()
    {
        return s.top();
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
    stack<int> empty;
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
            string res = customStack.push(num);
            cout << res;
        }
        else if (oper == "back")
        {
            int lastEl = customStack.back();
            cout << lastEl << '\n';
        }
        else if (oper == "size")
        {
            int sz = customStack.size();
            cout << sz << '\n';
        }
        else if (oper == "pop")
        {
            int lastEl = customStack.pop();
            cout << lastEl << '\n';
        }
        else if (oper == "clear")
        {
            customStack.clear();
        }
    }
}