#include <stdio.h>
#include <stdlib.h>

unsigned int max_stack_size = 65536;
int64_t stack[max_stack_size];
int stack_top = -1;

void push(int64_t value) {
    if (stack_top < max_stack_size - 1) {
        stack[++stack_top] = value;
    } else {
        printf("Error: Stack overflow\n");
        exit(2);
    }
}

void interpreter(int c) {
    switch (c) {
        case '0':
            push(0);
            break;
        case '+':
            if (stack_top >= 0) {
                stack[stack_top]++;
            } else {
                printf("Error: Stack underflow from +\n");
                exit(1);
            }
            break;
        case '_':
            pop();
            break;
        case '~':
            if (stack_top >= 0) {
                 push(stack[stack_top]);
            } else {
                printf("Error: Stack underflow from +\n");
                exit(1);
            }
            break;
        case '?':
            if (stack_top >= 0) {
                if (stack[stack_top] > 0) {
                    stack[stack_top]--;
                    push(1);
                } else {
                    push(0);
                }
            } else {
                printf("Error: Stack underflow from +\n");
                exit(1);
            }
            break;
        case '>':
            int64_t n = stack[stack_top];
            pop();
            if (n >= 2) {
                //  code to figure this out 
            } else {
                printf("Error: Stack underflow from +\n");
                exit(1);
            }
            break;





    }            
}


int64_t pop() {
    if (stack_top >= 0) {
        return stack[stack_top--];
    } else {
        printf("Error: Stack underflow\n");
        exit(1);
    }
}



int file_parse(char *file_name)
{
    FILE *fp;       //Variable to represent open file

    fp = fopen(file_name, "r"); // Open file for reading
    
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        return 1;
    }

    int c;
    while ((c = fgetc(fp)) != EOF){
        if (c == '0' || c == '+' || c == '_' || c == '~' ||
            c == '?' || c == '_' || c == '(' || c == ')' ||
            c == '~') {
                // Search a struct what c is to a method
            } 
        }
        fclose(fp);     // Close the file when done
        return 0;
}   


int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

}