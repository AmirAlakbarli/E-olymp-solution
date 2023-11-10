#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;
int main()
{
    cout << "? " << -MAX << " " << -MAX << endl
         << flush;
    int d1;
    cin >> d1;
    cout << "? " << MAX << " " << -MAX << endl
         << flush;
    int d2;
    cin >> d2;
    int y = (d1 + d2) / 2 - 2 * MAX;
    int x = (d1 - d2) / 2;
    cout << "! " << x << " " << y << endl
         << flush;
}