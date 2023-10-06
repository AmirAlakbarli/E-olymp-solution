#include <stdio.h>

using namespace std;

int main()
{
    int x, n, m;
    scanf("%d%d%d", &x, &n, &m);
    long mod = 1;
    for (int i = 0; i < n; i++)
    {
        mod = (mod * x) % m;
    }

    printf("%ld", mod);
}