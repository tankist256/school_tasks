#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_valid_number(const char *str) {
    int i = 0;
    if (str[0] == '-') i = 1;
    if (str[i] == '\0') return 0; 
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') return 0;
        i++;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./program <number1> [number2 ...]\n");
        return 1;
    }

    long sum = 0;
    int count = 0;
    long min = 0;
    long max = 0;
    int has_valid_numbers = 0;

    for (int i = 1; i < argc; i++) {
        if (!is_valid_number(argv[i])) {
            printf("Warning: Skipping invalid number '%s'\n", argv[i]);
            ;
        }
        char *endptr;
        long num = strtol(argv[i], &endptr, 10);

        if (*endptr != '\0') {
            printf("Warning: Skipping invalid number '%s'\n", argv[i]);
            break;
        }

        sum += num;
        count++;
        if (count == 1) {
            min = num;
            max = num;
        } else {
            if (num < min) min = num;
            if (num > max) max = num;
        }
        has_valid_numbers = 1;
    }

    if (!has_valid_numbers) {
        printf("Error: No valid numbers provided\n");
        return 1;
    }

    double average = (double)sum / count;

    printf("Count: %d\n", count);
    printf("Sum: %ld\n", sum);
    printf("Average: %.2f\n", average);
    printf("Minimum: %ld\n", min);
    printf("Maximum: %ld\n", max);

    return 0;
}