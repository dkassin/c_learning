#include "stdio.h"

void increment_ptr(int* counter) {
    *counter = *counter + 1;
}

void use_counter() {
    int counter_val = 0;
    int* counter = &counter_val;
    increment_ptr(counter);
    increment_ptr(counter);
    printf("counter value: %d\n", counter_val);
    printf("pointer value: %p\n", counter);    
}

int main() {
    use_counter();
    return 0;
}