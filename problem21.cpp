#include <stdio.h>
#include <set>

using namespace std;

int main()
{
    long long a;
    int p;
    multiset<long long> c;
    scanf("%lld %d", &a, &p);
    p = 100 - p;
    int in;
    for (int i = 0; i < a; ++i)
    {
        scanf("%d", &in);
        c.insert((in * 100));
    }

    while (a-- > 1)
    {
        auto itOrig = c.begin(), it = itOrig;
        long long s = (long long)(p * ((*it++) + (*it++)) / 100);
        c.erase(itOrig, it);
        c.insert(s);
    }

    long long r = *c.begin();
    printf("%lld.%02lld", r / 100, r % 100);
    return 0;
}