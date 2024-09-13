#include "stdio.h"
#include "string.h"

int main(int argc, char** argv) {
    char default_val[256] = {0};
    char *input = default_val;
    int row, col;
    int x[1][26] = { {0} };

    if (argc > 1) {
        for (int i = 1; (i < argc); i++) {
            input = argv[i];

            for (int j = 0; j < strlen(input); j++) {
                char c = input[j];

                if (c >= 'a' && c <= 'z') {
                    x[0][c - 'a']++;
                }
            }
        }
    }

    for (row = 0; row < 1; row++) {
        for (col = 0; col < 26; col++) {
            if (x[0][col] != 0)
                printf("%c %d\n", 'A' + col, x[row][col]);
        }
    }
    return 0;
}