#include <stdio.h>
#include <math.h>

int main()
{
    double x1, y1, r1, x2, y2, r2;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
    int result = 0;

    double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    if (d == 0)
    {
        if (r1 == r2)
            result = -1;
        else
            result = 0;
    }
    else if (d == r1 + r2 || d == abs(r1 - r2))
        result = 1;
    else if (d > r1 + r2 || d < abs(r1 - r2))
        result = 0;
    else
        result = 2;

    printf("%d", result);
}