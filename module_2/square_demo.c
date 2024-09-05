#include "stdio.h"
#include "stdlib.h"

int square(int x) {
    return x * x;
}

int main(int argc, char** argv) {
    int default_value = 137;
    int input = default_value;

    if (argc > 1) {
        input = atoi(argv[1]);
    }

    int result = square(input);
    printf("%d square is %d\n", input, result);
    return 0;
}