#define DEBUG 0

#include <stdlib.h>
#include <stdio.h>

int a2i(char* number);
int len(char* text);
int power(int base, int pwr);
void strcopy(char* target, char* source);
int strcompare(char* textA, char* textB);

int main(int argc, char** argv)
{
    int i;
    int keywords = 0;
    int integers = 0;
    int strings = 0;
    int flags = 0;
    char* argp = malloc(sizeof(char)*argc);
    for(i = 1; i < argc; i++)
    {
        int j;
        int chars_pres = 0;
        if(argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] != 0)
        {
            keywords++;
            argp[i] = 'k';
        }
        else if(argv[i][0] != '-' || argv[i][2] != 0)
        {  
            for(j = 0; argv[i][j] != '\0'; j++) 
        {
                if(argv[i][j] - '0' >= 9 || argv[i][j] - '0' < 0 )
             {
                strings++;
                chars_pres = 1;
                argp[i] = 's';
                break;
             }
        }
        if(chars_pres == 0)
        {
            integers++;
            argp[i] = 'i';
        }

        {
        else
        {
            flags++;
            argp[i] = 'f';
        }
        }
    }

    }