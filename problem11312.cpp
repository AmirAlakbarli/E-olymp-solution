#include <bits/stdc++.h>

using namespace std;

// Helper function to trim leading zeros from a string
string trimLeadingZeros(const string &str)
{
    int i = 0;
    while (i < str.size() && str[i] == '0')
    {
        i++;
    }
    return (i == str.size()) ? "0" : str.substr(i);
}

string minusLargeNumber(const string &num1, const string &num2)
{
    string result;
    int borrow = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0 || j >= 0)
    {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        int diff = digit1 - digit2 - borrow;
        borrow = 0;

        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }

        result = to_string(diff) + result;

        if (i >= 0)
            i--;
        if (j >= 0)
            j--;
    }

    // Remove leading zeros from the result
    result = trimLeadingZeros(result);

    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;

    string num;
    cin >> num;

    int len = num.size();

    if (len == 1)
    {
        cout << num;
    }
    else if (len == 2)
    {
        if (num[1] == '0')
            cout << '0';
        else
            cout << num[0] - num[1];
    }
    else if (len == 3)
    {
        if (num[1] == '0')
            cout << "-" << num[2];
        else
            cout << num[0] - '0' - stoi(num.substr(1, 2));
    }
    else
    {

        int i = 1;
        while (num[i] == '0')
            i++;

        i--;

        string lastPart = num.substr(i + 1, len - i - 1);

        if (i)
        {
            if (i == len - 1)
            {
                cout << '0';
            }
            else
            {
                cout << "-" << lastPart;
            }
        }
        else
        {
            cout << "-" << minusLargeNumber(lastPart, num.substr(0, 1));
        }
    }
    return 0;
}