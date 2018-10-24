#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int cache = *b;
    *b = *a;
    *a = cache;
}

int partition2(int *a, int l, int r)
{
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= x) {
            j++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[l], &a[j]);
    return j;
}

int* partition3(int *a, int left, int right)
{
    int pivot = a[left];
    int smalls = 0;
    int equals = 0;
    static int result[2];
    // printf("left: %d, right: %d\n", left, right);
    for (int i = left + 1; i <= right; i++) {
        // printf("  pivot: %d, a[i]: %d\n", pivot, a[i]);
        if (a[i] == pivot) {
            equals++;
            swap(&a[i], &a[left + smalls + equals]);
        } else if (a[i] < pivot) {
            smalls++;
            // printf("    a[0]: %d, a[1]: %d, a[2]: %d\n", a[0], a[1], a[2]);
            swap(&a[i], &a[left + smalls]);
            if(equals) {
                swap(&a[i], &a[left + smalls + equals]);
            }
            // printf("    a[0]: %d, a[1]: %d, a[2]: %d\n", a[0], a[1], a[2]);
        }
    }
    // printf("smalls: %d, equals: %d\n", smalls, equals);
    swap(&a[left], &a[left + smalls]);
    result[0] = left + smalls;
    result[1] = left + smalls + equals;
    return result;
}

void randomized_quick_sort(int *a, int l, int r)
{
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    // swap(&a[l], &a[k]);
    int *m = partition3(a, l, r);
    // printf("equals; %d, %d\n", *m, *(m +1));

    randomized_quick_sort(a, l, *m - 1);
    randomized_quick_sort(a, *(m + 1) + 1, r);
}

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    randomized_quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
