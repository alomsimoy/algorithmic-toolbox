#include <stdio.h>
#include <inttypes.h>

int main ()
{
    int total;
    scanf("%d", &total);
    int numbers[2] = {0, 0};
    for(int i = 0; i < total; i++) {
        int num;
        scanf("%d", &num);
        if (num >= numbers[0]) {
            numbers[1] = numbers[0];
            numbers[0] = num;
        } else if (num > numbers[1]) {
            numbers[1] = num;
        }
    }

    printf("%" PRId64 "\n", (int64_t) numbers[0] * (int64_t) numbers[1]);

    return 0;
}
