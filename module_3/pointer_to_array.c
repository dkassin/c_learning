#include <stdio.h>

int main(void)
{
    int a[5] = {11,22,33,44,55};
    int *p;

    p = &a[0]; // p points to the array
                // to the first element actually

    printf("%d\n", *p); // Print "11"

    p = a; // shorthand for p points to the array
}