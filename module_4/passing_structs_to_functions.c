// , it’s far more common to pass a pointer to a struct to a function 
// though its by no means illegal to pass the struct itself.

//If you have a struct, use dot (.).
// If you have a pointer to a struct, use arrow (->).

#include <stdio.h>

struct car {
    char *name;
    float price;
    int speed;
};

void set_price(struct car *c, float new_price){
    (*c).price = new_price; // Works, but non-idiomatic :(

    // The line above is 100% equivalent to the one below:

    c->price = new_price;
}

int main(void)
{
    struct car saturn = {.speed=175, .name="Saturn SL/2"};

    // Pass a pointer to this struct car, along with a new,
    // more realistic pprice:

    set_price(&saturn, 799.99);

    printf("Price: %f\n", saturn.price);
}