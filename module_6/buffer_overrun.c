#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>

// Pretend this function is actually one-way.
uint32_t hash(int len, const char *str) {
    uint32_t acc = 0;
    for (int i = len -1; i >= 0; i--) {
        acc *= 179;
        acc += str[i];
    }
    return acc;
}

typedef struct session {
    char name[16];
    char ok;
    char password[9];
} session;

int main() {
    session s = {0};
    printf("What is your name? ");
    gets(s.name);
    printf("What is your password? ");
    gets(s.password);
    if (hash(8, s.password) == 0x16c720e3) {
        s.ok = 1;
    }
    if (s.ok) {
        printf("You get ALL the MacGuffins.\n", s.name);
    } else {
        printf("Sorry %s, but your MacGuffins are in another castle.\n", s.name);
    }
}

// this could be broken by puting a name of Badguy12345678901