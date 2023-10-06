#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int lengthOfNumber(int number)
{
    int length = 0;
    while (number > 0)
    {
        number /= 10;
        length++;
    }
    return length;
}

int *simplicity(int num1, int num2)
{
    int resNum1 = 0, resNum2 = 0;
    int degree = 1;
    int *res = malloc(2 * sizeof(int));
    while (num1 > 0 && num2 > 0)
    {
        if (num1 == num2)
            break;
        resNum1 += num1 % 10 * degree;
        resNum2 += num2 % 10 * degree;
        num1 /= 10;
        num2 /= 10;
        degree *= 10;
    }
    res[0] = resNum1;
    res[1] = resNum2;
    return res;
}

int bigProcess(int num1, int num2)
{
    if (num1 == 0)
        return 1;
    return (int)(abs(floor(log10(num2)) - ceil(log10(num1))) + 1);
}

int sameSizeProcess(int num1)
{
    if (num1 == 0)
        return 1;
    else
    {
        int arrDegree = (int)(floor(log10(num1)));
        if (num1 % (int)(pow(10, arrDegree)) == 0)
            return 1;
        else
        {
            int res = 1;
            int arrCommit = num1 / (int)(pow(10, arrDegree)) * (int)(pow(10, arrDegree));
            int *smallNumbers = malloc(arrDegree * sizeof(int));
            for (int i = 0; i < arrDegree; i++)
            {
                smallNumbers[i] = arrCommit + pow(10, i);
            }

            for (int i = 0; i < arrDegree; i++)
            {
                if (num1 <= smallNumbers[i])
                    res++;
            }
            return res;
        }
    }
}

int main()
{
    int lower, upper;
    scanf("%d %d", &lower, &upper);
    if (lengthOfNumber(lower) != lengthOfNumber(upper))
        printf("%d", bigProcess(lower, upper));
    else
    {
        int *arr = simplicity(lower, upper);
        int summary1 = arr[0], summary2 = arr[1];
        if (lengthOfNumber(summary1) != lengthOfNumber(summary2))
            printf("%d", bigProcess(summary1, summary2));
        else
            printf("%d", sameSizeProcess(summary1));
    }
}