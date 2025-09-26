#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_lower(char c) {
    return c >= 'a' && c <= 'z';
}

int is_upper(char c) {
    return c >= 'A' && c <= 'Z';
}

char to_lower(char c) {
    if (is_upper(c)) {
        return c + ('a' - 'A');
    }
    return c;
}

char *string_to_lower(const char *str) {
    int len = strlen(str);
    char *result = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        result[i] = to_lower(str[i]);
    }
    result[len] = '\0';
    return result;
}

int contains_word(const char *text, const char *word) {
    // Convert both text and word to lowercase
    char *text_lower = string_to_lower(text);
    char *word_lower = string_to_lower(word);
    
    int found = strstr(text_lower, word_lower) != NULL;
    
    free(text_lower);
    free(word_lower);
    
    return found;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./search <word> <text1> [text2 ...]\n");
        return 1;
    }

    char *search_word = argv[1];
    int found_any = 0;

    for (int i = 2; i < argc; i++) {
        if (contains_word(argv[i], search_word)) {
            printf("Found '%s' in '%s'\n", search_word, argv[i]);
            found_any = 1;
        }
    }

    if (!found_any) {
        printf("No matches found for '%s'\n", search_word);
    }

    return 0;
}