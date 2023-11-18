#include <stdio.h>

const int fibNums[40] = {
    0, 1, 2, 3, 5,
    8, 13, 21, 34, 55, 89,
    144, 233, 377, 610,
    987, 1597, 2584, 4181,
    6765, 10946, 17711, 28657,
    46368, 75025, 121393, 196418,
    317811, 514229, 832040,
    1346269, 2178309, 3524578,
    5702887, 9227465, 14930352,
    24157817, 39088169, 63245986,
    102334155};

char findChar(int num, int index)
{
    if (num == 1)
    {
        return 'a';
    }
    if (num == 2)
    {
        if (index == 1)
            return 'b';
        else if (index == 2)
            return 'c';
    }
    if (index <= fibNums[num - 2])
    {
        return findChar(num - 2, index);
    }
    else
    {
        return findChar(num - 1, index - fibNums[num - 2]);
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    if (n <= 35 && k > fibNums[n])
    {
        printf("No solution");
        return 0;
    }

    if (n == 2)
    {
        if (k == 1)
            printf("b");
        else if (k == 2)
            printf("c");
        return 0;
    }

    int i;

    for (i = 3; i <= n; i++)
    {
        if (fibNums[i] >= k)
            break;
    }

    char res = findChar(i, k);
    printf("%c", res);

    return 0;
}