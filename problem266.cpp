#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;

    int len_a = a.length();
    int len_b = b.length();

    if (len_a > len_b)
        cout << ">";
    else if (len_a < len_b)
        cout << "<";
    else
    {
        int compare = a.compare(b);
        if (compare > 0)
            cout << ">";
        else if (compare < 0)
            cout << "<";
        else
            cout << "=";
    }
}