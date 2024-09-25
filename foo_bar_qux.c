#include "stdio.h"
#include "stdlib.h"

int qux(int x, int y) {
    int a = ~x;
    printf("qux.a at %p     M[%p] = %d\n", &a, &a, a);
    printf("qux.x at %p     M[%p] = %d\n", &x, &x, x);
    printf("qux.y at %p     M[%p] = %d\n", &y, &y, y);
    putchar('\n');
    if (x > 0)
        return qux(-x, y);
    else
        return 3 + a;
}

int bar(int x, int y) {
    int a = y ^ x;
    printf("bar.a at %p     M[%p] = %d\n", &a, &a, a);
    printf("bar.x at %p     M[%p] = %d\n", &x, &x, x);
    printf("bar.y at %p     M[%p] = %d\n", &y, &y, y);   
    putchar('\n');
    return qux(x + a, y -  a);
}

int foo(int x, int y){
    int a = x % 2;
    printf("foo.a at %p     M[%p] = %d\n", &a, &a, a);
    printf("foo.x at %p     M[%p] = %d\n", &x, &x, x);
    printf("foo.y at %p     M[%p] = %d\n", &y, &y, y);
    putchar('\n');
    return bar(x, y + a);
}

static int x = 3;

int main() {
    int* a = calloc(1, sizeof(int));
    int y = 5;
    printf("Before calls... \n");
    printf("main.a at %p     M[%p] = %d\n", a, a, *a);
    printf("main.x at %p     M[%p] = %d\n", &x, &x, x);
    printf("main.y at %p     M[%p] = %d\n", &y, &y, y);
    putchar('\n');
    *a = foo(x,y);
    printf("After calls... \n");
    printf("main.a at %p     M[%p] = %d\n", a, a, *a);
    printf("main.x at %p     M[%p] = %d\n", &x, &x, x);
    printf("main.y at %p     M[%p] = %d\n", &y, &y, y);
    putchar('\n');
    return 0;
}