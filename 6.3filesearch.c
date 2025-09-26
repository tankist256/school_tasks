#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if a character is a lowercase letter
int is_lower(char c) {
    return c >= 'a' && c <= 'z';
}

// Function to check if a character is an uppercase letter
int is_upper(char c) {
    return c >= 'A' && c <= 'Z';
}

// Function to convert a character to lowercase
char to_lower(char c) {
    if (is_upper(c)) {
        return c + ('a' - 'A');
    }
    return c;
}

// Function to create a lowercase copy of a string
char *string_to_lower(const char *str) {
    int len = strlen(str);
    char *result = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        result[i] = to_lower(str[i]);
    }
    result[len] = '\0';
    return result;
}

// Function to check if a word is in a line (case-sensitive or insensitive)
int contains_word(const char *line, const char *word, int case_insensitive) {
    if (case_insensitive) {
        char *line_lower = string_to_lower(line);
        char *word_lower = string_to_lower(word);
        int found = strstr(line_lower, word_lower) != NULL;
        free(line_lower);
        free(word_lower);
        return found;
    }
    return strstr(line, word) != NULL;
}

int main(int argc, char *argv[]) {
    // Check for at least word + one file
    if (argc < 3) {
        printf("Usage: ./filesearch [-i] <word> <file1> [file2 ...]\n");
        return 1;
    }

    int case_insensitive = 0;
    char *search_word = NULL;
    char *files[argc];
    int file_count = 0;
    int word_set = 0;

    // Parse arguments
    int i = 1;
    while (i < argc) {
        if (strcmp(argv[i], "-i") == 0) {
            case_insensitive = 1;
            i++;
        } else if (argv[i][0] == '-') {
            printf("Error: Unknown flag '%s'\n", argv[i]);
            return 1;
        } else if (!word_set) {
            search_word = argv[i];
            word_set = 1;
            i++;
        } else {
            files[file_count++] = argv[i];
            i++;
        }
    }

    // Validate word and at least one file
    if (!word_set || file_count == 0) {
        printf("Usage: ./filesearch [-i] <word> <file1> [file2 ...]\n");
        return 1;
    }

    int all_files_failed = 1;
    int found_any = 0;

    // Process each file
    for (int j = 0; j < file_count; j++) {
        FILE *file = fopen(files[j], "r");
        if (file == NULL) {
            printf("Error: Cannot open file '%s'\n", files[j]);
            continue;
        }

        all_files_failed = 0;

        // Read file line by line
        char line[1024]; // Assume max line length of 1023 chars
        long line_number = 0;
        while (fgets(line, sizeof(line), file) != NULL) {
            line_number++;
            // Remove trailing newline for output
            int len = strlen(line);
            if (len > 0 && line[len - 1] == '\n') {
                line[len - 1] = '\0';
            }
            // Check if line contains the word
            if (contains_word(line, search_word, case_insensitive)) {
                printf("%s:%ld:%s\n", files[j], line_number, line);
                found_any = 1;
            }
        }

        fclose(file);
    }

    // Handle case where no files could be opened
    if (all_files_failed) {
        printf("Error: No files could be opened\n");
        return 1;
    }

    // Handle case where no matches were found
    if (!found_any) {
        printf("No matches found for '%s'\n", search_word);
    }

    return 0;
}