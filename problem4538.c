#include <stdio.h>
#include <math.h>

int main()
{
    signed long balloon;
    scanf("%lu", &balloon);
    printf("%lu", (signed long)floor((floor(sqrt(8 * balloon + 1)) - 1) / 2));
}