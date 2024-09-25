#include "stdio.h"
#include "stdlib.h"

int main(int argc, char** argv) {
    char default_val[] = 0;
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