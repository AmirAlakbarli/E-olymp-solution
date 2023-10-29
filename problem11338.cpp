#include <stdio.h>

int main()
{
    short max = 0, num = 0;
    char c;
    while ((c = getchar()) != '\n')
    {
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
        {
            if (num > max)
                max = num;
            num = 0;
        }
        else
        {
            num++;
        }
    }

    if (num > max)
        max = num;

    printf("%hd", max + 1);
}