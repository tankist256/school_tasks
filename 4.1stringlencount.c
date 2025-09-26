#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./program <string1> [string2 ...]\n");
        return 1;
    }

    int total_length = 0;

    for (int i = 1; i < argc; i++) {
        int len = strlen(argv[i]);
        printf("%s: %d\n", argv[i], len);
        total_length += len;
    }

    printf("Total: %d\n", total_length);

    return 0;
}