// Build a command-line tool that sums its arguments, 
// which will all be integers, and prints the result to the console. 
// All arguments will be between -1000 and 1000, inclusive; 
// There can be as many as 100 of them.

#include "stdio.h"
#include "stdlib.h"

int main(int argc, char** argv) {
    int default_val = 0;
    int input = default_val;
    
    if (argc > 101) {
        printf("Too many arguments! The max is 100\n");
        return 1;
    }

    if (argc > 1){
        int sum = 0;
        int invalid_input = 0;

        for (int i = 1; (i < argc) ; i++){
            input = atoi(argv[i]);
            int value_check = (input <= -1000 || input > 1000) ? 1:0;
            switch (value_check) {
                case 0:
                    sum += input;
                    break;
                case 1:
                    invalid_input = 1;
                    printf("The value %d, is to large or to small!\n", input);
                    break;
            }
            
        }
        switch (invalid_input) {
            case 0:
                printf("%d", sum);
                break;                
        }   
    }
    else if (argc == 1)
        printf("0\n");

    return 0;
}