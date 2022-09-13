#include <stdio.h>
#include <math.h>
int main()
{
  int A, B, C, D, K, i, x;
  unsigned long long int N;
  scanf("%d %d %d %d %llu %d", &A, &B, &C, &D, &N, &K);
  int max = 0;
  for (i = 1; i <= K; i++)
  {
    for (x = 0; x <= N / A; x++)
    {
      int y = (N - A * x) / B;
      if (C * x + D * y >= max)
        max = C * x + D * y;
    }
    N += max;
  }
  printf("%llu", N);
}