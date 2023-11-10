#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long step = 1000000000, sumOfSteps = 0;
    long long lowerBound = 0, upperBound = 1000000000;
    do
    {
        cout << "run " << step << '\n';
        sumOfSteps += step;
        long long lap;
        cin >> lap;
        lowerBound = max(lowerBound, sumOfSteps / (lap + 1) + 1);
        upperBound = min(upperBound, sumOfSteps / lap);
        step = (lowerBound + upperBound) * (lap + 1) / 2 - sumOfSteps;
    } while (lowerBound < upperBound);

    cout << "ensure " << lowerBound;
}
