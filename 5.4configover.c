#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    long port = 8080;
    char *host = "localhost";
    int debug = 0;

    int i = 1;
    while (i < argc) {
        if (strcmp(argv[i], "--port") == 0 || strcmp(argv[i], "-p") == 0) {
            if (i + 1 >= argc) {
                printf("Error: %s requires a number value\n", argv[i]);
                return 1;
            }
            char *endptr;
            long new_port = strtol(argv[i + 1], &endptr, 10);
            if (*endptr != '\0') {
                printf("Error: Invalid number '%s' for %s\n", argv[i + 1], argv[i]);
                return 1;
            }
            if (new_port < 0 || new_port > 65535) {
                printf("Error: Port '%ld' out of valid range (0-65535)\n", new_port);
                return 1;
            }
            port = new_port;
            i += 2; 
        } else if (strcmp(argv[i], "--host") == 0 || strcmp(argv[i], "-h") == 0) {
            if (i + 1 >= argc) {
                printf("Error: %s requires a host address\n", argv[i]);
                return 1;
            }
            host = argv[i + 1];
            i += 2;
        } else if (strcmp(argv[i], "--debug") == 0 || strcmp(argv[i], "-d") == 0) {
            debug = 1;
            i++;
        } else {
            printf("Error: Unknown flag or unexpected argument '%s'\n", argv[i]);
            return 1;
        }
    }

    printf("Configuration:\n");
    printf("  Port: %ld\n", port);
    printf("  Host: %s\n", host);
    printf("  Debug: %s\n", debug ? "true" : "false");

    return 0;
}