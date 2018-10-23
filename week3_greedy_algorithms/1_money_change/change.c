#include <stdio.h>

int get_change(int m)
{
    int coins[3] = {10, 5, 1};
    int n = 0, i = 0;

    while(m > 0) {
        if (m >= coins[i]) {
            m -= coins[i];
            n++;
        } else {
            i++;
        }
    }

    return n;
}

int main()
{
    int m;
    scanf("%d", &m);
    printf("%d\n", get_change(m));
}
