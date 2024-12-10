#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// int valid_expression_check(const char *expression) {

// }
typedef struct ExpressionGroup {
    char atoms[64][256];
    int atom_count;
} ExpressionGroup;

void parse_expression(const char *expression, ExpressionGroup expressiongroups[128], int *expression_count) {
    int current_expression_group = -1;
    char atom[256];
    int atom_pos = 0;

    for (int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];

        if (isspace(c)) {
            continue;
        }

        if (c == '(') {
            current_expression_group++;
            expressiongroups[current_expression_group].atom_count = 0;
        } else if (c == ')') {
            if (atom_pos > 0) {
                atom[atom_pos] = '\0';
                strcpy(expressiongroups[current_expression_group].atoms[expressiongroups[current_expression_group].atom_count++], atom);
                atom_pos = 0;
            }
        } else {
            atom[atom_pos++] = c;
            if ( expression[i + 1] == '(' || expression[i + 1] == ')' || expression[i + 1] == '\0') {
                atom[atom_pos] = '\0';
                strcpy(expressiongroups[current_expression_group].atoms[expressiongroups[current_expression_group].atom_count++], atom);
                atom_pos = 0; 
            }
        }
    } 
    *expression_count = current_expression_group + 1;
}

void print_parsed_expression(ExpressionGroup expressiongroups[128], int expression_count) {
    printf("[");
    for (int i = 0; i < expression_count; i++) {
        printf("[");
        for (int j = 0; j < expressiongroups[i].atom_count; j++) {
            printf("%s", expressiongroups[i].atoms[j]);
            if (j < expressiongroups[i].atom_count - 1) {
                printf(", ");
            }
        }
        printf("]");
        if (i < expression_count - 1) {
            printf(",");
        }
    }
    printf("]\n");
}

int is_number(const char *str) {

    if (*str == '\0') return 0;
    while (*str) {
        if (!isdigit((unsigned char) *str)) {
            return 0;
        }
        str++;
    }
    return 1;
}


int main(){
    printf("psi> ");
    char input[4096];
    ExpressionGroup expressiongroups[128];
    int expression_count = 0;

    if (fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0';
        if (is_number(input)) {
            printf("%s\n", input);
            return 0;
        } else {
            parse_expression(input, expressiongroups, &expression_count);
            print_parsed_expression(expressiongroups, expression_count);
        }
        // valid_expression_check
        // return value
        // printf("%s\n", input);
    } else {
        printf("ERROR (error value)\n");
    }
    return 0;
}