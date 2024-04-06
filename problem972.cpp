#include <bits/stdc++.h>
using namespace std;

class Time
{
public:
    int hours, min, sec;
    Time(int h, int m, int s) : hours(h), min(m), sec(s) {}
};

bool compare(Time *a, Time *b)
{
    if (a->hours != b->hours)
        return a->hours < b->hours;
    if (a->min != b->min)
        return a->min < b->min;
    return a->sec < b->sec;
}

int main()
{
    Time *t1 = new Time(12, 10, 34);
    Time *t2 = new Time(12, 9, 45);

    int n, h, m, s;
    cin >> n;
    vector<Time *> times;
    for (int i = 0; i < n; i++)
    {
        cin >> h >> m >> s;
        times.push_back(new Time(h, m, s));
    }

    sort(times.begin(), times.end(), compare);

    for (int i = 0; i < n; i++)
    {
        cout << times[i]->hours << " " << times[i]->min << " " << times[i]->sec << endl;
    }
}