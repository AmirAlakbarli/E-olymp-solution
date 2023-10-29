#include <stdio.h>

int main()
{
    int n, idx;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
        if (nums[i] == 1)
        {
            idx = i;
        }
    }

    for (int i = idx; i < n; i++)
    {
        printf("%d ", nums[i]);
    }

    for (int i = 0; i < idx; i++)
    {
        printf("%d ", nums[i]);
    }
}