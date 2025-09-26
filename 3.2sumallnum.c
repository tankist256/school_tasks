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
    if (argc < 2) {
        printf("Usage: ./program <number1> [number2 ...]\n");
        return 1;
    }

    int sum = 0;
    int has_valid_numbers = 0;

    for (int i = 1; i < argc; i++) {
        int valid = 1;
        int num = string_to_int(argv[i], &valid);
        if (valid) {
            sum += num;
            has_valid_numbers = 1;
        } else {
            printf("Warning: Skipping invalid number '%s'\n", argv[i]);
        }
    }
    if (!has_valid_numbers) {
        printf("Error: No valid numbers provided\n");
        return 1;
    }
    printf("Sum: %d\n", sum);

    return 0;
}