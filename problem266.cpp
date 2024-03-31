#include <stdio.h>

int main()
{
    char a[100002];
    char digit;
    short len_a = 0, len_b = 0;
    char res = '=';
    bool flag = false;

    do
    {
        digit = getchar();
        a[len_a++] = digit;
    } while (digit != '\n');

    len_a--;

    do
    {
        digit = getchar();
        if (len_b > len_a)
        {
            res = '<';
            break;
        }
        if (a[len_b] > digit && !flag)
        {
            res = '>';
            flag = true;
        }
        else if (a[len_b] < digit && !flag)
        {
            res = '<';
            flag = true;
        }

        len_b++;
    } while (digit != '\n');

    len_b--;

    if (len_a > len_b)
        res = '>';
    else if (len_a < len_b)
        res = '<';

    printf("%c", res);
}