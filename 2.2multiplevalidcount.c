#include <stdio.h>
int main(int argc, char *argv[])
{
    if (argc == 2) 
    {
        printf("Hello %s!\n", argv[1]);
    }
    else if (argc == 3)
    {
        printf("Hello %s, you are %s!\n", argv[1], argv[2]);
    }
    else if (argc == 4)
    {
        printf("Hello %s, you are %s from %s!\n", argv[1], argv[2], argv[3]);
    }
    else
    {
        printf("Usage: ./program <name> [<age> [<city>]]\n");
        return 1;
    }
    
    return 0;
}