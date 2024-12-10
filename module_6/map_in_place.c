typedef int(*i2i)(int);

int double_it(int x) {
    return x * 2;
}

int square(int y) {
    return y * y;
}

int negate(int z) {
    return -z;
}

void map_in_place(int len, int* data, i2i f) {
    for (int i = 0; i < len; i++)
        data[i] = f(data[i]);
}

int main() {
    int a[7] = {1, 2, 3, 4, 5, 6, 7};
    i2i b[3] = {double_it, square, negate};
    for (int i = 0; i < 3; i++)
        map_in_place(7, a, b[i]);
}