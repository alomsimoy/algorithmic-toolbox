#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int count_digits(int n) {
    int count = 0;
    while(n != 0)
    {
        n /= 10;
        ++count;
    }
    return count;
}

int largest(const void *a, const void *b) {
    int ia = *(int *)a; // casting pointer types
    int ib = *(int *)b;
    int cache = ia;
    ia = ia * pow(10, count_digits(ib)) + ib;
    ib = ib * pow(10, count_digits(cache)) + cache;
    int digits_a = count_digits(ia);
    int digits_b = count_digits(ib);
    if (digits_a == digits_b) {
        return ib - ia;
    }
    if (digits_a < digits_b) {
        // printf("ia: %d, ib: %d, da: %d, db: %d, pow: %d",
                // ia, ib, digits_a, digits_b, pow(10, (digits_b-digits_a)));
        ib /= pow(10, (digits_b - digits_a));
        // printf(", ib': %d\n", ib);
        if (ib == ia)
            return -1;
    } else {
        // printf("ia: %d, ib: %d, da: %d, db: %d, pow: %d",
                // ia, ib, digits_a, digits_b, pow(10, (digits_a-digits_b)));
        ia /= pow(10, (digits_a - digits_b));
        // printf(", ia': %d\n", ia);
        if (ia == ib)
            return 1;
    }
    return ib - ia;
}

void largest_number(int length, int* array) {
    char result[100000];

    qsort(array, length, sizeof(int), largest);

    for (int i = 0; i < length; i++) {

        char buffer[1000];
        sprintf(buffer, "%d", array[i]);

        strcat(result, buffer);
        // printf("sum: %ld\n", result);
    }

    printf("%s\n", result);
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%ld", &a[i]);
    }
    largest_number(n, a);
}
