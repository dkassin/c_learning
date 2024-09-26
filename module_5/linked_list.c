// #include "stdlib.h"

typedef struct uchar_list {
    bool is_end;
    unsigned char data;
    struct uchar_list* next;
} uchar_list;

uchar_list* uchar_list_new () {
    uchar_list* out = malloc(sizeof(uchar_list));
    out -> data = 0;
    out -> next = NULL;
    out -> is_end = true;
    return out;
}

int uchar_list_head(uchar_list* ll) {
    if (ll->is_end) {
        return -1 // error condition -- head of empty list
    } else {
        return ll-> data;
    }
}

uchar_list* uchar_list_cons(unsigned char c, uchar_list* tl) {
    uchar_list* out = malloc(sizeof(uchar_list));
    out->data = c;
    out->next = tl;
    out->is_end = false;
    return out;
}

void uchar_list_print(uchar_list* ll) {
    if (!ll->is_end) {
        printf("%d ", ll->data);
        uchar_list_print(ll->next);
    } else {
        printf("\n");
    }
}

int main() {
    uchar_list* nil = uchar_list_new();
    uchar_list* uno = uchar_list_cons(137, nil);
    uchar_list* dos = uchar_list_cons(86, uno);
    uchar_list* big = uchar_list_cons(51, dos);
    uchar_list_print(big);

    return 0;
}