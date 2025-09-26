#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./display <file1> [file2 ...]\n");
        return 1;
    }

    int all_files_failed = 1;

    for (int i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        if (file == NULL) {
            printf("Error: Cannot open file '%s'\n", argv[i]);
            continue;
        }

        all_files_failed = 0;

        printf("File: %s\n", argv[i]);
        printf("----\n");

        int c;
        while ((c = fgetc(file)) != EOF) {
            putchar(c);
        }

        printf("\n----\n");

        fclose(file);
    }

    if (all_files_failed) {
        printf("Error: No files could be opened\n");
        return 1;
    }

    return 0;
}