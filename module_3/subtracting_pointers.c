#include <stdio.h>

int my_strlen(char *s)
{
    // Start scanning from the beginning of the string
    char *p = s;

    // Scan until we find the NUL char
    while (*p != '\0')
        p++;

    // Return the differece in pointers

    return p - s;

}

int main(void)
{
    printf("%d\n", my_strlen("hello, world!")); // Prints "13"
}

// Pointer subtraction can only be between two pointers that point to the same array