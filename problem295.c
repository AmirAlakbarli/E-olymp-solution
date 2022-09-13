#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int r;
    scanf("%d", &r);
    int sum = 0;
    for (int i = 0; i <= r; i++)
    {
        sum += floor(sqrt(r * r - i * i));
    }

    printf("%d", 4 * sum + 1);
}