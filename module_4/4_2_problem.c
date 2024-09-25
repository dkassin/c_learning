#include "inttypes.h"
#include "stdio.h"
#include "stdlib.h"

int64_t recur_sum(int64_t n) {
    if (n <= 0)
        return 0;
    else
        return n + recur_sum(n - 1);
}

int main(int argc, char** argv) {
    int64_t n = 100;
    if (argc > 1)
        n = atoll(argv[1]);
    
    printf("%lld\n", recur_sum(n));
}