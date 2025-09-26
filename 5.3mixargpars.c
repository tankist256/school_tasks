#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int verbose = 0;
    long number = 0;
    int has_number = 0;
    char *output_filename = NULL;
    char *non_flags[argc];
    int non_flag_count = 0;

    // Process arguments
    int i = 1;
    while (i < argc) {
        if (strcmp(argv[i], "-v") == 0) {
            verbose = 1;
            i++;
        } else if (strcmp(argv[i], "-n") == 0) {
            if (i + 1 >= argc) {
                printf("Error: -n requires a number value\n");
                return 1;
            }
            char *endptr;
            number = strtol(argv[i + 1], &endptr, 10);
            if (*endptr != '\0') {
                printf("Error: Invalid number '%s' for -n\n", argv[i + 1]);
                return 1;
            }
            has_number = 1;
            i += 2; 
        } else if (strcmp(argv[i], "-o") == 0) {
            
            if (i + 1 >= argc) {
                printf("Error: -o requires a filename\n");
                return 1;
            }
            output_filename = argv[i + 1];
            i += 2; 
        } else if (argv[i][0] == '-') {
            // Unknown flag
            printf("Error: Unknown flag '%s'\n", argv[i]);
            return 1;
        } else {
            non_flags[non_flag_count++] = argv[i];
            i++;
        }
    }

    if (!has_number && !output_filename && !verbose && non_flag_count == 0) {
        printf("Usage: ./program [-v] [-n <number>] [-o <filename>] [arguments ...]\n");
        printf("Options:\n");
        printf("  -v             Enable verbose output\n");
        printf("  -n <number>    Set number value\n");
        printf("  -o <filename>  Set output filename\n");
        return 1;
    }

    if (verbose) {
        printf("Verbose mode enabled\n");
    }

    if (has_number) {
        if (verbose) {
            printf("Number value: %ld\n", number);
        }
    }
    if (output_filename) {
        if (verbose) {
            printf("Output filename: %s\n", output_filename);
        }
    }

    if (non_flag_count > 0) {
        if (verbose) {
            printf("Processing %d non-flag argument(s):\n", non_flag_count);
        }
        for (int j = 0; j < non_flag_count; j++) {
            if (verbose) {
                printf("Argument %d: %s\n", j + 1, non_flags[j]);
            } else {
                printf("%s\n", non_flags[j]);
            }
        }
    }

    return 0;
}
