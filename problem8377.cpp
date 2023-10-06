#include <stdio.h>

using namespace std;

int productOfDigits(int n)
{
    int product = 1;
    while (n > 0)
    {
        product *= n % 10;
        n /= 10;
    }
    return product;
}

int main()
{
    int n;

    while (scanf("%d", &n) != EOF)
    {
        int steps = 0;
        while (n > 9)
        {
            n = productOfDigits(n);
            steps++;
        }
        printf("%d\n", steps);
    }
}