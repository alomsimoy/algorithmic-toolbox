#include <stdio.h>
#include <stdlib.h>

/*
long* sort(int n, long* array)
{
    long sorted[n];

    for (int i = 0; i < n; i++) {
        long biggest;
        int index;
        for (int j = 0; j < n; j++) {
            if (array[j] != NULL && array[j] > biggest) {
                biggest = array[j];
                index = j;
            }
        }
        sorted[i] = biggest;
        array[index] = NULL;
    }
    return sorted;
}
*/

int long_cmp(const void *a, const void *b)
{
    const long la = *(const long *)a; // casting pointer types
    const long lb = *(const long *)b;
    if (la > lb) return 1;
    if (la > lb) return -1;
    return 0;
}

long long max_dot_product(int n, long* a, long* b) {
    qsort(a, n, sizeof(long), long_cmp);
    qsort(b, n, sizeof(long), long_cmp);

    long long result = 0;
    for (int i = 0; i < n; i++) {
        result += ((long long) a[i]) * b[i];
    }

    return result;
}

int main()
{
    int n;

    scanf("%d", &n);

    long a[n], b[n];

    for (int i = 0; i < n; i++) {
        scanf("%ld", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%ld", &b[i]);
    }

    printf("%ld\n", max_dot_product(n, a, b));
}
