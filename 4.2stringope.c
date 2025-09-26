#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_lower(char c) {
    return c >= 'a' && c <= 'z';
}

int is_upper(char c) {
    return c >= 'A' && c <= 'Z';
}

char to_upper(char c) {
    if (is_lower(c)) {
        return c - ('a' - 'A');
    }
    return c;
}

char to_lower(char c) {
    if (is_upper(c)) {
        return c + ('a' - 'A');
    }
    return c;
}

void string_to_upper(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = to_upper(str[i]);
    }
}

void string_to_lower(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = to_lower(str[i]);
    }
}

char *string_reverse(const char *str) {
    int len = strlen(str);
    char *result = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        result[i] = str[len - 1 - i];
    }
    result[len] = '\0';
    return result;
}

char *string_concat(char *argv[], int start, int end) {
    int total_len = 0;
    for (int i = start; i < end; i++) {
        total_len += strlen(argv[i]);
    }
    
    char *result = malloc(total_len + 1);
    
    int pos = 0;
    for (int i = start; i < end; i++) {
        strcpy(result + pos, argv[i]);
        pos += strlen(argv[i]);
    }
    result[total_len] = '\0';
    return result;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./program <operation> <string1> [string2 ...]\n");
        printf("Operations: upper, lower, reverse, concat\n");
        return 1;
    }

    char *operation = argv[1];
    if (strcmp(operation, "upper") != 0 &&
        strcmp(operation, "lower") != 0 &&
        strcmp(operation, "reverse") != 0 &&
        strcmp(operation, "concat") != 0) {
        printf("Error: Invalid operation '%s'. Use upper, lower, reverse, or concat\n", operation);
        return 1;
    }

    if (strcmp(operation, "upper") == 0 || strcmp(operation, "lower") == 0) {
        char **copies = malloc((argc - 2) * sizeof(char *));
        
        for (int i = 2; i < argc; i++) {
            copies[i - 2] = malloc(strlen(argv[i]) + 1);
            strcpy(copies[i - 2], argv[i]);
            if (strcmp(operation, "upper") == 0) {
                string_to_upper(copies[i - 2]);
            } else {
                string_to_lower(copies[i - 2]);
            }
        }

        for (int i = 0; i < argc - 2; i++) {
            printf("%s", copies[i]);
            if (i < argc - 3) printf(" ");
            free(copies[i]);
        }
        printf("\n");
        free(copies);
    } else if (strcmp(operation, "reverse") == 0) {
        for (int i = 2; i < argc; i++) {
            char *reversed = string_reverse(argv[i]);
            printf("%s", reversed);
            if (i < argc - 1) printf(" ");
            free(reversed);
        }
        printf("\n");
    } else if (strcmp(operation, "concat") == 0) {
        char *result = string_concat(argv, 2, argc);
        printf("%s\n", result);
        free(result);
    }

    return 0;
}