#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[] = "Hello, world!";
    char t[100]; // Each char is one byte, so plenty of room

    // This makes a copy of the string!

    strcpy(t, s); // destination pointer is the first(the new variable), source second

    // We modify t
    t[0] = 'z';

    // And s remains unaffected becuse it's  different string
    printf("%s\n", s); // "Hello, world!"

    printf("%s\n", t); // "zello, world!"
}