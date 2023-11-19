#include <stdio.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int abs(int a)
{
    return a > 0 ? a : -a;
}

int main()
{
    int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;
    scanf("%d %d %d %d", &ax1, &ay1, &ax2, &ay2);
    scanf("%d %d %d %d", &bx1, &by1, &bx2, &by2);

    int X_intersect = max(0, min(ax2, bx2) - max(ax1, bx1));
    int Y_intersect = max(0, min(ay2, by2) - max(ay1, by1));
    int len_x_a = ax2 - ax1;
    int len_y_a = ay2 - ay1;
    int len_x_b = bx2 - bx1;
    int len_y_b = by2 - by1;
    int res;

    if (X_intersect == len_x_a && Y_intersect == len_y_a)
    {
        res = 0;
    }
    else if (Y_intersect == len_y_a && (ax1 == bx1 || ax2 == bx2))
    {
        res = len_y_a * (bx1 - ax1 + ax2 - bx2);
    }
    else if (Y_intersect == len_y_a && !(ax1 < bx1 && ax2 > bx2))
    {
        res = len_y_a * (abs(ax1 - bx1) + abs(ax2 - bx2) + X_intersect - len_x_b);
    }
    else if (X_intersect == len_x_a && (ay1 == by1 || ay2 == by2))
    {
        res = len_x_a * (by1 - ay1 + ay2 - by2);
    }
    else if (X_intersect == len_x_a && !(ay1 < by1 && ay2 > by2))
    {
        res = len_x_a * (abs(ay1 - by1) + abs(ay2 - by2) + Y_intersect - len_y_b);
    }
    else
    {
        res = len_x_a * len_y_a;
    }

    printf("%d", res);
}