#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int verbose = 0;
    int show_help = 0;
    char *non_flags[argc];
    int non_flag_count = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) {
            verbose = 1;
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            show_help = 1;
        } else {
            non_flags[non_flag_count++] = argv[i];
        }
    }
    if (show_help) {
        printf("Usage: ./program [-v|--verbose] [-h|--help] [arguments ...]\n");
        printf("Options:\n");
        printf("  -v, --verbose  Enable verbose output\n");
        printf("  -h, --help     Show this help message\n");
        return 0;
    }

    if (non_flag_count == 0 && !verbose) {
        printf("No arguments provided. Use --help for usage information.\n");
        return 1;
    }

    if (verbose) {
        printf("Verbose mode enabled\n");
    }

    if (non_flag_count > 0) {
        if (verbose) {
            printf("Processing %d non-flag argument(s):\n", non_flag_count);
        }
        for (int i = 0; i < non_flag_count; i++) {
            if (verbose) {
                printf("Argument %d: %s\n", i + 1, non_flags[i]);
            } else {
                printf("%s\n", non_flags[i]);
            }
        }
    }

    return 0;
}