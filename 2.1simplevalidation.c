#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./program <name> <age>\n");
        return 1;
    }
    
    printf("Hello %s, you are %s years old!\n", argv[1], argv[2]);
    
    return 0;
}