#include <stdio.h>
#include <stdlib.h>

unsigned int max_stack_size = 65536;
unsigned int stack[65536];
int stack_top = -1;

void push(unsigned int value) {
    if (stack_top < max_stack_size - 1) {
        stack[++stack_top] = value;
    } else {
        printf("Error: Stack overflow\n");
        exit(2);
    }
}

unsigned int pop() {
    if (stack_top >= 0) {
        return stack[stack_top--];
    } else {
        printf("Error: Stack underflow\n");
        exit(1);
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
                if (stack_top + 1 < n) {
                printf("Error: Stack underflow from >\n");
                exit(1);
                }
            int64_t temp[n];
            
            for (int i = 0; i < n; i++) {
                temp[i] = pop();
            }
            // stack = ABC now temp = CBA
            int64_t last = temp[0];
            push(last);
            for (int i = n -1; i >0; i--) {
                push(temp[i]);
                }
            break;
            }
        case '<':
            int64_t n = stack[stack_top];
            pop();
            if (n >= 2) {
                if (stack_top + 1 < n) {
                printf("Error: Stack underflow from >\n");
                exit(1);
            } 
            int64_t temp[n];
            
            for (int i = 0; i < n; i++) {
                temp[i] = pop();
            }
            // stack = ABC now temp = CBA
            int64_t first = temp[n-1];

            for (int i = n-2; i >= 0; i--) {
                push(temp[i]);
                }
        
            push(first);
            break;
            }

            // Struggling to figure out how to implement the while loop ()
            // Ran out of time
            // i think i need the pgoram variable to be able to loop back and forth in the program string
    }    
}

int main(int argc, char *argv[])
{   
    if (argc > 1) {
        char* program =argv[1];
        int i = 0;
        while (program[i] != '\0'){
            interpreter(program[i]);
            i++;
        }   
        return 0;
    }
    return 1;
}