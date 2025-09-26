#include <stdio.h>
#include <string.h>

int is_digit(char c) {
    return c >= '0' && c <= '9';
}
int string_to_int(const char *str, int *valid) {
    int result = 0;
    int i = 0;
    int is_negative = 0;

    if (str[0] == '-') {
        is_negative = 1;
        i = 1;
    }

    while (str[i] != '\0') {
        if (!is_digit(str[i])) {
            *valid = 0;
            return 0;
        }
        result = result * 10 + (str[i] - '0');
        i++;
    }

    if (i == 0 || (i == 1 && is_negative)) {
        *valid = 0;
        return 0;
    }

    return is_negative ? -result : result;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: ./calc <num1> <operator> <num2>\n");
        return 1;
    }
    int valid1 = 1, valid2 = 1;
    int num1 = string_to_int(argv[1], &valid1);
    int num2 = string_to_int(argv[3], &valid2);

    if (!valid1 || !valid2) {
        printf("Error: Invalid number format\n");
        return 1;
    }
    if (strlen(argv[2]) != 1 || (argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != '*' && argv[2][0] != '/')) {
        printf("Error: Invalid operator. Use +, -, *, or /\n");
        return 1;
    }
    int result;
    char op = argv[2][0];
    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero\n");
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            printf("Error: Invalid operator\n");
            return 1;

    printf("%s %c %s = %d\n", argv[1], op, argv[3], result);

    return 0;
}
}