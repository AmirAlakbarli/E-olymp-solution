#include <bits/stdc++.h>
using namespace std;

string luckyNum(int n)
{
    char digits[4] = {'8', '1', '2', '4'};
    string res;

    while (n != 0)
    {
        if (n % 4 == 0)
        {
            res += '8';
            n /= 4;
            n--;
        }
        else
        {
            res += (digits[n % 4]);
            n /= 4;
        }
    }

    reverse(res.begin(), res.end());
    return res;
}

string add(string a, string b)
{
    string res;
    int carry = 0;
    char digits[] = {'0', '1', '2', '4', '8'};
    int i = a.length() - 1, j = b.length() - 1;

    while (i >= 0 || j >= 0)
    {
        int digit1 = (i >= 0) ? a[i] - '0' : 0;
        int digit2 = (j >= 0) ? b[j] - '0' : 0;
        int idx1 = digit1 ? (int)log2(digit1) + 1 : 0;
        int idx2 = digit2 ? (int)log2(digit2) + 1 : 0;
        int sumidx = idx1 + idx2 + carry;
        carry = 0;
        if (sumidx > 4)
        {
            carry = 1;
            sumidx %= 4;
        }
        res = digits[sumidx] + res;
        i--, j--;
    }
    if (carry)
        res = '1' + res;
    return res;
}

string smallestLucky(string n)
{
    map<char, char> digits = {{'1', '2'}, {'2', '4'}, {'4', '8'}, {'8', '1'}};
    map<char, char> substitution = {{'0', '1'}, {'3', '4'}, {'5', '8'}, {'6', '8'}, {'7', '8'}};
    int len = n.length();
    int idx = 0;
    string res;
    while (idx < len && digits.count(n[idx]))
    {
        res += n[idx];
        idx++;
    }
    if (idx == len)
    {
        return add(res, "1");
    }
    else
    {
        if (n[idx] == '9')
        {
            return add(res, "1") + string(len - idx, '1');
        }
        else
        {
            return res + substitution[n[idx]] + string(len - idx - 1, '1');
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q, t;
    cin >> q;
    while (q--)
    {
        cin >> t;
        if (t == 1)
        {
            int k;
            cin >> k;
            cout << luckyNum(k) << '\n';
        }
        else
        {
            string k;
            cin >> k;
            cout << smallestLucky(k) << '\n';
        }
    }
}