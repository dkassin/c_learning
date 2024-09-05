#include <stdio.h>

void put_int(int x) {
    printf("%d\n", x);
}

void say_hello(char* name, int age) {
    puts("hello");
    puts(name);
    puts("You were born in ");
    put_int(2024 - age);
}

int main(void) {
    say_hello("Bob", 30);
    return 0;
}

