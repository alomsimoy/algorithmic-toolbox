#include <stdio.h>

int gcd_fast(int a, int b)
{
    if (b == 0)
        return a;

    return gcd_fast(b, a % b);
}

long long lcm_fast(int a, int b)
{
    return (long long) a * b / gcd_fast(a, b);
}

long long lcm_naive(int a, int b)
{
    for (long l = 1; l <= (long long) a * b; ++l)
        if (l % a == 0 && l % b == 0)
            return l;

    return (long long) a * b;
}

int main()
{
  int a, b;
  scanf("%d %d", &a, &b);
  // printf("%lld\n", lcm_naive(a, b));
  printf("%lld\n", lcm_fast(a, b));
  return 0;
}
