#include <stdio.h>

using namespace std;

typedef unsigned long long llu;

int main()  
{
    llu t;
    scanf("%llu", &t);

    for (int i = 0; i < t; i++)
    {
        llu n;
        scanf("%llu", &n);
        int endNum = n % 2 ? 2 : 1;
        llu diff =  (n - 1 + endNum) / 2 *(n + 1 - endNum);
        printf("%llu\n", diff);
    }
}