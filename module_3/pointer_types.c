#include <stdio.h>

int main(void)
{
    int i;
    int *p; // p's type is a "pointer to an int", or "int-pointer"

    p = &i; // p is assigned to the address of i--p now "points to" i
}