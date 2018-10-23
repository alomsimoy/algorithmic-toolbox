#include <stdio.h>

long long get_pisano_period(long long m)
{
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
    return 0;
}

long long get_fibonacci_huge_fast(long long n, long long m)
{
    long long remainder = n % get_pisano_period(m);
    long long first = 0;
    long long second = 1;
    long long result = remainder;

    for (long long i = 1; i < remainder; i++) {
        result = (first + second) % m;
        first = second;
        second = result;
    }

    return result % m;
}

long long fibonacci_sum_fast(long long n) {
    return (get_fibonacci_huge_fast(n + 2, 10) + 9) % 10;
}


int main()
{
    long long n = 0, m = 0;
    scanf("%lld %lld", &n, &m);

    long long result = (fibonacci_sum_fast(m) + (10 - fibonacci_sum_fast(n - 1))) % 10;
    printf("%lld\n", result);
    return 0;
}

