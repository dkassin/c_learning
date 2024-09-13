#include "stdio.h"

void print_size(int a[]) {
    printf("sizeof(a) = %lu\n", sizeof(a));
}

int main(int argc, char** argv) {
    int a[7];
    printf("sizeof(a) = %lu\n", sizeof(a));
    print_size(a);
    return 0;
}