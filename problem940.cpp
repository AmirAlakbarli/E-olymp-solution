#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int nums[n];
    for (int &i : nums)
        cin >> i;

    stack<int> s;

    for (int &i : nums)
    {
        if (s.empty() || i == s.top())
            s.push(i);
        else
            s.pop();
    }
    if (s.empty())
        cout << "-1\n";
    else
    {
        int lastEl = s.top();
        int cnt = 0;
        for (int &i : nums)
        {
            if (i == lastEl)
                cnt++;
        }
        if (2 * cnt > n)
            cout << lastEl << '\n';
        else
            cout << "-1\n";
    }
}