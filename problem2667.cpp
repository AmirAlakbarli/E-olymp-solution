#include <stdio.h>
#include <math.h>

int main()
{
    int n, m, x, y;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    x -= 1;
    y -= 1;
    printf("%d ", (m * (2 * x + 1) - 1) * (x % 2) + (int)pow(-1, x % 2) * (m * x + y));
}