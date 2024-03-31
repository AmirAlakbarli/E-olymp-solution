#include <stdio.h>
#include <vector>

using namespace std;
typedef unsigned long long llu;

int abs(int a)
{
    return a < 0 ? -a : a;
}

int main()
{
    int n, num1, num2;
    llu sum1, sum2;
    scanf("%d", &n);

    int p[n + 1];
    p[1] = -1, p[2] = 1;

    scanf("%d", &num1);
    scanf("%d", &num2);
    sum1 = 0, sum2 = abs(num2 - num1);

    for (int i = 3; i <= n; i++)
    {
        int tempNum = num2;
        int tempSum = sum2;

        scanf("%d", &num2);
        if (sum2 + abs(num2 - tempNum) < sum1 + 3 * abs(num2 - num1))
        {
            sum2 += abs(num2 - tempNum);
            p[i] = i - 1;
        }
        else
        {
            sum2 = sum1 + 3 * abs(num2 - num1);
            p[i] = i - 2;
        }
        num1 = tempNum;
        sum1 = tempSum;
    }

    vector<int> path;
    int i = n;
    while (i > 0)
    {
        path.push_back(i);
        i = p[i];
    }

    printf("%llu\n", sum2);
    printf("%d\n", path.size());

    for (int i = path.size() - 1; i >= 0; i--)
        printf("%d ", path[i]);
}
