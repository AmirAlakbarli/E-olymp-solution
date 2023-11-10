#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    cin.ignore();
    vector<string> test;
    map<string, pair<int, int>> myMap;
    string s;
    for (int i = 0; i < 3 * n; i++)
    {
        getline(cin, s);
        myMap[s].first++;
        myMap[s].second = i;
    }

    vector<pair<string, pair<int, int>>> v;
    for (auto it = myMap.begin(); it != myMap.end(); it++)
    {
        v.push_back(make_pair(it->first, it->second));
    }

    sort(v.begin(), v.end(), [&](pair<string, pair<int, int>> a, pair<string, pair<int, int>> b)
         {
             if (a.second.first == b.second.first)
                 return a.second.second >= b.second.second;
             return a.second.first > b.second.first; });

    k = min(k, (int)v.size());
    for (int i = 0; i < k; i++)
    {
        cout << v[i].first << endl;
    }

    return 0;
}