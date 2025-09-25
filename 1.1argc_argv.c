#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("number of arguments %d\n, argc");
    printf("program name %s\n, argv[0]");

        if (argc > 1) {
            printf("First argument: %s\n", argv[1]);
        }

    return 0;

}