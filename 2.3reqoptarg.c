#define MAX_NUM_LEN 50
#define MAX_RESULT_LEN 100

#include <stdio.h>
#include <string.h>

    typedef struct
    {
        char integer_part[MAX_NUM_LEN];
        char fractional_part[MAX_NUM_LEN];
        int fractional_digits;
        int is_negative;
    } ParsedNumber;

        int is_digit(char c) 
        {
            return c >= '0' && c <= '9';
        }
            ParsedNumber parse_number(const char *str)
            {
                ParsedNumber result = {{0}, {0}, 0, 0};
                int i = 0, int_idx = 0, frac_idx = 0;

                
                if (str[0] == '-')
                {
                    result.is_negative = 1;
                    i = 1;
                }

                
                while (str[i] != '\0' && str[i] != '.')
                {
                    if (!is_digit(str[i]))
                    {
                        // Invalid character, return empty with invalid state
                        result.integer_part[0] = '\0';
                        result.fractional_part[0] = '\0';
                        result.is_negative = 0;
                        return result;
                    }
                    if (int_idx < MAX_NUM_LEN - 1)
                    {
                        result.integer_part[int_idx++] = str[i];
                    }
                    i++;
                }
                    result.integer_part[int_idx] = '\0';

                    if (str[i] == '.')
                    {
                        i++;
                        while (str[i] != '\0')
                        {
                            if (!is_digit(str[i]))
                            {
                                result.integer_part[0] = '\0';
                                result.fractional_part[0] = '\0';
                                result.is_negative = 0;
                                return result;
                            }
                            if (frac_idx < MAX_NUM_LEN - 1)
                            {
                                result.fractional_part[frac_idx++] = str[i];
                                result.fractional_digits++;
                            }
                            i++;
                        }
                    }
                    result.fractional_part[frac_idx] = '\0';
                    if (int_idx == 0 && result.fractional_digits > 0)
                    {
                        result.integer_part[0] = '0';
                        result.integer_part[1] = '\0';
                    }
{
                    return result;
}
                
            }

                void reverse_string(char *str) {
                    int len = strlen(str);
                    for (int i = 0; i < len / 2; i++) {
                        char temp = str[i];
                        str[i] = str[len - 1 - i];
                        str[len - 1 - i] = temp;
                    }
                }
                    void add_numbers(ParsedNumber num1, ParsedNumber num2, char *result)
                    {
                        char int_result[MAX_RESULT_LEN] = {0};
                        char frac_result[MAX_RESULT_LEN] = {0};
                        int max_frac_digits = num1.fractional_digits > num2.fractional_digits ? num1.fractional_digits : num2.fractional_digits;
                        int carry = 0, i, j, k = 0;

                        char frac1[MAX_NUM_LEN] = {0}, frac2[MAX_NUM_LEN] = {0};
                        strcpy(frac1, num1.fractional_part);
                        strcpy(frac2, num2.fractional_part);
                        for (i = num1.fractional_digits; i < max_frac_digits; i++)
                        {// Add fractional parts (right to left)
                            frac1[i] = '0';
                        }
                        for (i = num2.fractional_digits; i < max_frac_digits; i++)
                        {
                            frac2[i] = '0';
                        }
                        for (i = max_frac_digits - 1; i >= 0; i--)
                        {
                            int digit1 = frac1[i] ? frac1[i] - '0' : 0;
                            int digit2 = frac2[i] ? frac2[i] - '0' : 0;
                            int sum = digit1 + digit2 + carry;
                            carry = sum / 10;
                            frac_result[k++] = (sum % 10) + '0';
                        }
                        frac_result[k] = '\0';
                        reverse_string(frac_result);

                        char int1[MAX_NUM_LEN] = {0}, int2[MAX_NUM_LEN] = {0};
                        strcpy(int1, num1.integer_part[0] ? num1.integer_part : "0");
                        strcpy(int2, num2.integer_part[0] ? num2.integer_part : "0");
                        reverse_string(int1);
                        reverse_string(int2);

                        i = 0, k = 0;
                        while (int1[i] || int2[i] || carry) 
                        {
                            int digit1 = int1[i] ? int1[i] - '0' : 0;
                            int digit2 = int2[i] ? int2[i] - '0' : 0;
                            int sum = digit1 + digit2 + carry;
                            carry = sum / 10;
                            int_result[k++] = (sum % 10) + '0';
                            i++;
                        }
                        int_result[k] = '\0';
                        reverse_string(int_result);

                        int is_negative = 0;
                        if (num1.is_negative && !num2.is_negative) 
                        {
                            is_negative = 1;
                        }
                        else if (!num1.is_negative && num2.is_negative)
                        {
                            is_negative = 0; // Placeholder
                        }
                        else if (num1.is_negative && num2.is_negative)
                        {
                            is_negative = 1;
                        }

                        result[0] = '\0';
                        if (is_negative)
                        {
                            strcat(result, "-");
                        }
                        strcat(result, int_result[0] ? int_result : "0");
                        if (frac_result[0]) {
                            strcat(result, ".");
                            for (i = 0; i < 2 && frac_result[i]; i++)
                            {
                                result[strlen(result)] = frac_result[i];
                            }
                            result[strlen(result)] = '\0';
                        }
                    }
                        int main(int argc, char *argv[]) 
                    {
                        if (argc < 2)
                        {
                            printf("Usage: ./program <operation> [<args>]\n");
                            printf("Operations:\n");
                            printf("  --greet <name>\n");
                            printf("  --add <number1> <number2>\n");
                            printf("  --list\n");
                            return 1;
                        }
                        if (strcmp(argv[1], "--greet") == 0)
                        {
                            if (argc != 3)
                            {
                                printf("Usage: ./program --greet <name>\n");
                                return 1;
                            }
                            printf("Hello, %s!\n", argv[2]);
                        }
                        else if (strcmp(argv[1], "--add") == 0) 
                        {
                            if (argc != 4)
                            {
                                printf("Usage: ./program --add <number1> <number2>\n");
                                return 1;
                            }
                            ParsedNumber num1 = parse_number(argv[2]);
                            ParsedNumber num2 = parse_number(argv[3]);
                            if ((num1.integer_part[0] == '\0' && num1.fractional_part[0] == '\0' && !num1.is_negative && strcmp(argv[2], "0") != 0 && strcmp(argv[2], "0.0") != 0) ||
                                (num2.integer_part[0] == '\0' && num2.fractional_part[0] == '\0' && !num2.is_negative && strcmp(argv[3], "0") != 0 && strcmp(argv[3], "0.0") != 0))
                            {
                                printf("Error: Invalid number format\n");
                                return 1;
                            }
                            char result[MAX_RESULT_LEN] = {0};
                            add_numbers(num1, num2, result);
                            printf("%s + %s = %s\n", argv[2], argv[3], result);
                        }
                            else if (strcmp(argv[1], "--list") == 0)
                            {
                                if (argc != 2)
                                {
                                    printf("Usage: ./program --list\n");
                                    return 1;
                                }
                                printf("List operation executed.\n");
                            } 
                        else 
                            {
                                printf("Unknown operation: %s\n", argv[1]);
                                printf("Usage: ./program <operation> [<args>]\n");
                                printf("Operations:\n");
                                printf("  --greet <name>\n");
                                printf("  --add <number1> <number2>\n");
                                printf("  --list\n");
                                return 1;
                            }

                        return 0;
                    }