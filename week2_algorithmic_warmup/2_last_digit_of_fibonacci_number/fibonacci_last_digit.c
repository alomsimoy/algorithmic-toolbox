#include <stdio.h>
#include <assert.h>

int get_fibonacci_last_digit_naive(int n)
{
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n)
{
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }

    return current;
}

void test_solution()
{
    assert(get_fibonacci_last_digit_fast(3) == 2);
    assert(get_fibonacci_last_digit_fast(10) == 5);
    for (int n = 0; n < 45; ++n) {
        printf("Test %d: %d\n", n, get_fibonacci_last_digit_fast(n));
        // assert(fibonacci_fast(n) == fibonacci_naive(n));
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);

    // test_solution();
    printf("%d\n", get_fibonacci_last_digit_fast(n));
    //printf("%d\n", get_fibonacci_last_digit_fast(n));
    return 0;
}

