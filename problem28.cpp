#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef unsigned long long llu;

vector<llu> divisors(llu n)
{
    vector<llu> divs;
    for (llu i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            divs.push_back(i);
        }
    }

    return divs;
}

int main()
{
    llu n;
    scanf("%llu", &n);

    vector<llu> divs = divisors(n);

    // print divisors
    // for (llu i = 0; i < divs.size(); i++)
    // {
    //     cout << divs[i] << " ";
    // }

    // putchar('\n');

    vector<llu> logs;
    for (llu i = 0; i < divs.size(); i++)
    {
        llu logOfNum = log(n) / log(divs[i]);
        logs.push_back(logOfNum);
    }

    // print logs
    // for (llu i = 0; i < logs.size(); i++)
    // {
    //     cout << logs[i] << " ";
    // }

    // putchar('\n');

    llu i, j;
    bool flag = false;

    for (i = 0; i < divs.size(); i++)
    {
        llu mult = 1;
        llu temp = divs[i];

        for (j = 0; j < logs[i]; j++)
        {
            mult *= temp;
            temp++;

            if (mult == n)
            {
                flag = true;
                break;
            }

            else if (mult > n)
            {
                break;
            }
        }

        if (mult == n)
        {
            flag = true;
            break;
        }
    }

    if (i == divs.size())
    {
        i--;
    }

    // printf("i:%d\n", i);

    if (flag)
    {
        llu start = divs[i], end = divs[i] + j;
        printf("%llu %llu", start, end);
    }
    else
    {
        printf("%llu", n);
    }

    return 0;
}
