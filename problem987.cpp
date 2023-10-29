#include <stdio.h>
#include <stdlib.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int compare(const void *a, const void *b)
{
    int int_a = *((int *)a);
    int int_b = *((int *)b);

    if (int_a == int_b)
        return 0;
    else if (int_a < int_b)
        return -1;
    else
        return 1;
}

int main()
{
    int n, res1, res2;
    scanf("%d", &n);
    int nums[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    qsort(nums, n, sizeof(int), compare);

    res2 = 0;
    if (n >= 2)
    {
        res1 = res2;
        res2 = nums[1] - nums[0];
    }
    if (n >= 3)
    {
        res1 = res2;
        res2 = nums[2] - nums[0];
    }
    if (n >= 4)
    {
        for (int i = 3; i < n; i++)
        {
            int temp = res2;
            res2 = min(res1, res2) + nums[i] - nums[i - 1];
            res1 = temp;
        }
    }

    printf("%d", res2);
}