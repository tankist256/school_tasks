#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int copy_file(const char *src, const char *dst) {
    FILE *source = fopen(src, "rb");
    if (source == NULL) {
        printf("Error: Cannot open source file '%s'\n", src);
        return 0;
    }

    FILE *dest = fopen(dst, "wb");
    if (dest == NULL) {
        printf("Error: Cannot open destination file '%s'\n", dst);
        fclose(source);
        return 0;
    }

    int c;
    while ((c = fgetc(source)) != EOF) {
        fputc(c, dest);
    }

    fclose(source);
    fclose(dest);
    return 1;
}

int merge_files(const char *output, char *inputs[], int input_count) {
    FILE *out = fopen(output, "wb");
    if (out == NULL) {
        printf("Error: Cannot open output file '%s'\n", output);
        return 0;
    }

    int success = 1;
    for (int i = 0; i < input_count; i++) {
        FILE *in = fopen(inputs[i], "rb");
        if (in == NULL) {
            printf("Error: Cannot open input file '%s'\n", inputs[i]);
            success = 0;
            continue;
        }

        int c;
        while ((c = fgetc(in)) != EOF) {
            fputc(c, out);
        }
        fclose(in);
    }

    fclose(out);
    return success;
}

int split_file(const char *input, long size) {
    FILE *in = fopen(input, "rb");
    if (in == NULL) {
        printf("Error: Cannot open input file '%s'\n", input);
        return 0;
    }

    fseek(in, 0, SEEK_END);
    long file_size = ftell(in);
    rewind(in);

    if (file_size == 0) {
        printf("Error: Input file '%s' is empty\n", input);
        fclose(in);
        return 0;
    }

    if (size <= 0) {
        printf("Error: Chunk size must be positive\n");
        fclose(in);
        return 0;
    }

    int num_chunks = (file_size + size - 1) / size;
    int success = 1;

    for (int i = 0; i < num_chunks; i++) {
        char out_name[256];
        snprintf(out_name, sizeof(out_name), "%s.%03d", input, i + 1);

        FILE *out = fopen(out_name, "wb");
        if (out == NULL) {
            printf("Error: Cannot open output file '%s'\n", out_name);
            success = 0;
            continue;
        }

        long bytes_written = 0;
        int c;
        while (bytes_written < size && (c = fgetc(in)) != EOF) {
            fputc(c, out);
            bytes_written++;
        }

        fclose(out);
    }

    fclose(in);
    return success;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./fileops <operation> <files...>\n");
        printf("Operations: copy <src> <dst>, merge <output> <input1> [input2 ...], split <input> <size>\n");
        return 1;
    }

    char *operation = argv[1];

    if (strcmp(operation, "copy") == 0) {
        if (argc != 4) {
            printf("Error: copy requires exactly two arguments: <src> <dst>\n");
            return 1;
        }
        if (!copy_file(argv[2], argv[3])) {
            printf("Error: Copy operation failed\n");
            return 1;
        }
        printf("Successfully copied '%s' to '%s'\n", argv[2], argv[3]);

    } else if (strcmp(operation, "merge") == 0) {
        if (argc < 4) {
            printf("Error: merge requires at least two arguments: <output> <input1> [input2 ...]\n");
            return 1;
        }
        if (!merge_files(argv[2], &argv[3], argc - 3)) {
            printf("Error: Merge operation failed\n");
            return 1;
        }
        printf("Successfully merged %d file(s) into '%s'\n", argc - 3, argv[2]);

    } else if (strcmp(operation, "split") == 0) {
        if (argc != 4) {
            printf("Error: split requires exactly two arguments: <input> <size>\n");
            return 1;
        }
        char *endptr;
        long size = strtol(argv[3], &endptr, 10);
        if (*endptr != '\0') {
            printf("Error: Invalid size '%s' for split\n", argv[3]);
            return 1;
        }
        if (!split_file(argv[2], size)) {
            printf("Error: Split operation failed\n");
            return 1;
        }
        printf("Successfully split '%s' into chunks of %ld bytes\n", argv[2], size);

    } else {
        printf("Error: Unknown operation '%s'. Use copy, merge, or split\n", operation);
        return 1;
    }

    return 0;
}