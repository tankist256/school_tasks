#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **flags;
    int flag_count;
    char **keywords;
    int keyword_count;
    char **numbers;
    int number_count;
    char **strings;
    int string_count;
} ArgArrays;

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

int is_number(const char *str) {
    int has_dot = 0;
    int i = 0;
    
    // Handle negative numbers
    if (str[0] == '-') {
        i = 1;
        if (str[1] == '\0') return 0;
    }
    
    for (; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            if (has_dot) return 0;
            has_dot = 1;
        } else if (!is_digit(str[i])) {
            return 0;
        }
    }
    return 1;
}

ArgArrays parse_arguments(int argc, char *argv[]) {
    ArgArrays result = {NULL, 0, NULL, 0, NULL, 0, NULL, 0};
    
    result.flags = malloc(sizeof(char*) * (argc-1));
    result.keywords = malloc(sizeof(char*) * (argc-1));
    result.numbers = malloc(sizeof(char*) * (argc-1));
    result.strings = malloc(sizeof(char*) * (argc-1));
    
    result.flag_count = 0;
    result.keyword_count = 0;
    result.number_count = 0;
    result.string_count = 0;
    
    for (int i = 1; i < argc; i++) {
        if (strncmp(argv[i], "--", 2) == 0) {
            result.keywords[result.keyword_count++] = argv[i];
        } else if (argv[i][0] == '-') {
            result.flags[result.flag_count++] = argv[i];
        } else if (is_number(argv[i])) {
            result.numbers[result.number_count++] = argv[i];
        } else {
            result.strings[result.string_count++] = argv[i];
        }
    }
    
    return result;
}
void print_results(ArgArrays arrays) {
    printf("Flags: [");
    for (int i = 0; i < arrays.flag_count; i++)
    {
        printf("%s", arrays.flags[i]);
        if (i < arrays.flag_count - 1) printf(", ");
    }
    printf("]\n");
    
    printf("Keywords: [");
    for (int i = 0; i < arrays.keyword_count; i++)
    {
        printf("%s", arrays.keywords[i]);
        if (i < arrays.keyword_count - 1) printf(", ");
    }
    printf("]\n");
    
    printf("Numbers: [");
    for (int i = 0; i < arrays.number_count; i++)
    {
        printf("%s", arrays.numbers[i]);
        if (i < arrays.number_count - 1) printf(", ");
    }
    printf("]\n");
    
    printf("Strings: [");
    for (int i = 0; i < arrays.string_count; i++)
    {
        printf("%s", arrays.strings[i]);
        if (i < arrays.string_count - 1) printf(", ");
    }
    printf("]\n");
}
void free_arrays(ArgArrays arrays) 
{
    free(arrays.flags);
    free(arrays.keywords);
    free(arrays.numbers);
    free(arrays.strings);
}
int main(int argc, char *argv[])
{
    ArgArrays arrays = parse_arguments(argc, argv);
    print_results(arrays);
    free_arrays(arrays);
    return 0;
}