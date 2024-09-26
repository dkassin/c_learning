#include "stdlib.h"

typedef struct bytestring {
    unsigned char* data;
    size_t length;
} bytestring;

bytestring* bytestring_new(size_t len, const unsigned char* src) {
    bytestring* out = malloc(sizeof(bytestring));
    out->length = len;
    out->data = malloc(len);
    memcpy(out->data, src, len);
    return out;
}

void bytestring_delete(bytestring* b) {
    free(b->data);
    free(b);
}