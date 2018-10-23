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

long long get_fibonacci_huge_naive(long long n, long long m)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int main()
{
    long long n, m;
    scanf("%lld %lld", &n, &m);

    printf("%d\n", get_fibonacci_huge_fast(n, m));
    return 0;
}
