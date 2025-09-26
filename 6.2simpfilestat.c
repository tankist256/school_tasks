#include <stdio.h>

int is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

int main(int argc, char *argv[]) {
    // Check for at least one file argument
    if (argc < 2) {
        printf("Usage: ./filestat <file1> [file2 ...]\n");
        return 1;
    }

    int all_files_failed = 1;

    // Process each file argument
    for (int i = 1; i < argc; i++) {
        // Open the file
        FILE *file = fopen(argv[i], "r");
        if (file == NULL) {
            printf("Error: Cannot open file '%s'\n", argv[i]);
            continue;
        }

        all_files_failed = 0;

        // Initialize counters
        long size = 0;       // Bytes
        long lines = 0;      // Lines (count newlines)
        long words = 0;      // Words
        int in_word = 0;     // Track if currently in a word

        // Read file character by character
        int c;
        while ((c = fgetc(file)) != EOF) {
            size++; // Increment byte count

            // Count lines (newlines)
            if (c == '\n') {
                lines++;
            }

            // Count words (transition from non-whitespace to whitespace)
            if (!is_whitespace(c)) {
                if (!in_word) {
                    in_word = 1; // Start of a new word
                    words++;
                }
            } else {
                in_word = 0; // End of a word
            }
        }

        // If file doesn't end with newline, count last line
        if (size > 0 && in_word) {
            lines++; // Account for last line if no trailing newline
        }

        // Print statistics
        printf("File: %s\n", argv[i]);
        printf("  Size: %ld bytes\n", size);
        printf("  Lines: %ld\n", lines);
        printf("  Words: %ld\n", words);
        printf("\n");

        // Close the file
        fclose(file);
    }

    // Check if all files failed to open
    if (all_files_failed) {
        printf("Error: No files could be opened\n");
        return 1;
    }

    return 0;
}