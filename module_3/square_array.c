#include "stdio.h"

void print_array(size_t n, int* a) {
    for (int i = 0; i < n; i++) {
        printf("[%d] = %d\n", i, a[i]);
    }
}

void square_array(size_t n, int* a){
    for (int i = 0; i < n; i++) {
        a[i] = a[i] * a[i];
    }
}

int main() {
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    square_array(10, a);
    print_array(10, a);
    return 0;
}