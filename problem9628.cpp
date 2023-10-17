#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    int stn1, stn2, stn3;
    if (n == 2)
    {
        scanf("%d %d", &stn1, &stn2);
        printf("%d", abs(stn2 - stn1));
    }
    else
    {
        scanf("%d %d %d", &stn1, &stn2, &stn3);
        int minDis1 = abs(stn2 - stn1);
        int minDis2 = abs(stn3 - stn1) > abs(stn3 - stn2) + minDis1 ? abs(stn3 - stn2) + minDis1 : abs(stn3 - stn1);
        for (int i = 3; i < n; i++)
        {
            int stn;
            scanf("%d", &stn);
            int disStn1 = abs(stn - stn2);
            int disStn2 = abs(stn - stn3);
            stn2 = stn3;
            stn3 = stn;
            int temp = minDis2;
            minDis2 = disStn1 + minDis1 > disStn2 + minDis2 ? disStn2 + minDis2 : disStn1 + minDis1;
            minDis1 = temp;
        }
        printf("%d", minDis2);
    }
}