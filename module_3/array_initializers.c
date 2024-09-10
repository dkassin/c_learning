#include <stdio.h>

int main(void)
{
    int i;
    int a[5] = {22, 37, 3490, 18, 95}; // Initialize with these Values

    for (i = 0; i < 5; i++) {
        printf("%d\n", a[i]);
    }

    int b[5] = {22, 37, 3490}; // automatically sets remaining  elements to 0

    for (i = 0; i < 5; i++) {
        printf("%d\n", b[i]);
    }
}