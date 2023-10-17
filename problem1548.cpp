#include <stdio.h>
#include <math.h>

int main()
{
    unsigned long long num, nums[1000];
    int count = 0;
    while (1)
    {
        scanf("%llu", &num);
        if (num == 0)
            break;
        nums[count] = (unsigned long long)ceil((ceil(sqrt(8 * num + 9)) + 3) / 2);
        count++;
    }

    for (int i = 0; i < count; i++)
    {
        printf("Case %d: %llu\n", i + 1, nums[i]);
    }
}