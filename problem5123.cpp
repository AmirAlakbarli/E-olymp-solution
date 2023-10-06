#include <stdio.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int testNum, num;
        scanf("%d %d", &testNum, &num);
        int max = num;
        while (num > 1)
        {
            if (num % 2 == 0)
                num /= 2;
            else
                num = num * 3 + 1;

            if (num > max)
                max = num;
        }
        printf("%d %d\n", testNum, max);
    }
}