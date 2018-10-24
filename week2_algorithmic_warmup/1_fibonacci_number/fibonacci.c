#include <stdio.h>
#include <assert.h>
#include <inttypes.h>

int64_t fibonacci_naive(int n)
{
    if (n <= 1) {
        return n;
    }

    return (int64_t) fibonacci_naive(n - 1) + (int64_t) fibonacci_naive(n - 2);
}

int64_t fibonacci_fast(int n)
{
    if (n <= 1) {
        return n;
    }

    int64_t result[2] = {1, 1};
    for (int i = 2; i < n; i++) {
        int64_t cache = result[0];
        result[0] = result[1];
        result[1] = result[1] + cache;
    }

    return result[1];
}

void test_solution()
{
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 45; ++n) {
        printf("Test %d: %" PRId64 "\n", n, fibonacci_fast(n));
        // assert(fibonacci_fast(n) == fibonacci_naive(n));
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);

    // printf("%d\n", fibonacci_naive(n));
    // test_solution();
    printf("%" PRId64 "\n", fibonacci_fast(n));
    // print("%d\n", fibonacci_fast(n));
    return 0;
}

