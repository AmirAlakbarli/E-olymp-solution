#include <stdio.h>

int main()
{
    unsigned long int a, b, c;
    scanf("%lu%lu%lu", &a, &b, &c);
    printf("%lu", a * b + b * c + c * a);
}