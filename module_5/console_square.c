#include <inttypes.h>
#include <limits.h>
#include <stdio.h>

int main() {
    int64_t n;
    fprintf(stdout, "Enter an integer: ");
    fflush(stdout);
    fscanf(stdin, "%lld", &n);
    if (n < INT_MIN || n > INT_MAX) {
        fprintf(stderr, "WARNING: value tot large -- overflow likely\n");
    }
    fprintf(stdout, "%lld square is %lld\n", n ,n*n);
    return 0;
}
