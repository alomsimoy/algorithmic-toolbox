#include <stdio.h>

int summands_length(int n) {
    int counter = 0;
    while(n > 0) {
        counter++;
        n -= counter;
    }
    return counter;
}

int optimal_summands(int remaining, int* summands) {
    int length = 0;
    int candy = 1;
    while(remaining) {
        // printf("remaining: %d, candy %d\n", remaining, candy);
        if (remaining < candy) {
            summands[length - 1] += remaining;
            remaining = 0;
        } else {
            summands[length] = candy;
            remaining -= candy;
            length++;
            candy++;
        }
    }
    return length;
}

int main()
{
    int n;
    scanf("%d", &n);

    int summands[summands_length(n)];
    int size = optimal_summands(n, summands);

    printf("%d\n", size);

    for (int i = 0; i < size; ++i) {
        printf("%d ", summands[i]);
    }

    printf("\n");
}
