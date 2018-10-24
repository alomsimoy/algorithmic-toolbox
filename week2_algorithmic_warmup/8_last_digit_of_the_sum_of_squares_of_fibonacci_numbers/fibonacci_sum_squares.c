#include <stdio.h>

long long get_pisano_period(long long m)
{
    long long a = 0,
         b = 1,
         c = a + b;

    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) {
            return i + 1;
        }
    }

    return 0;
}

long long get_fibonacci_huge_fast(long long n, long long m)
{
    long long remainder = n % get_pisano_period(m),
         first = 0,
         second = 1,
         result = remainder;

    for (long long i = 1; i < remainder; i++) {
        result = (first + second) % m;
        first = second;
        second = result;
    }

    return result % m;
}

int fibonacci_sum_squares_fast(long long n)
{
    int x = get_fibonacci_huge_fast(n - 1, 10) % 10;
    int y = get_fibonacci_huge_fast(n, 10) % 10;
    return (x * y) % 10;
}

int fibonacci_sum_squares_naive(long long n)
{
    if (n <= 1) {
        return n;
    }

    long long previous = 0,
         current = 1,
         sum = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int get_fibonacci_last_digit_fast(int n)
{
    if (n <= 1) {
        return n;
    }

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }

    return (current * previous) % 10;
}

int main()
{
    long long n = 0;
    scanf("%lld", &n);

    // printf("%lld\n", get_fibonacci_last_digit_fast(n + 1));
    printf("%lld\n", fibonacci_sum_squares_fast(n + 1));
    return 0;
}
