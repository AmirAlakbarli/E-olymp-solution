#include <stdio.h>
using namespace std;

int main()
{
    int res = 0;
    char digit;
    while ((digit = getchar()) != '\n')
        res++;
    printf("%d", res);
}