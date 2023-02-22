
#include "lib.h"

bool is_divide_zero(char* str)
{
    for (int i = 0; str[i + 1] != '\0'; i++)
    {
        if (str[i] == '/' && str[i + 1] == '0') return true;
    }
    return false;
}

bool is_parse_error(const char* str)
{
    for (int t = 0; str[t + 1] != '\0'; t++)
    {
        if (str[t] == '/' || str[t] == '*')
        {
            if (str[t + 1] == '+' || str[t + 1] == '-') return true;
        }
        else if (str[t] == '+' || str[t] == '-')
        {
            if (str[t + 1] == '*' || str[t + 1] == '/') return true;
        }
        else if (str[t] == '(' && str[t + 1] == ')')
        {
            return true;
        }
        else if (str[t] == ')' && str[t + 1] == '(')
        {
            return true;
        }
    }
    return false;
}


bool is_error_string(char* str)
{
    for (int i = 0; str[i + 1] != '\0'; i++)
    {
        if (!is_operator(str[i]) && !is_bracket(str[i]) && !is_digit(str[i]))
        {
            return true;
        }
    }
    return false;
}

void strip(char* str)
{
    for (int i=0; str[i]!='\0'; i++)
    {
        if(str[i] == ' ')
            memmove(&str[i], &str[i + 1], strlen(str) - i);
    }
}

int main(int ac, char** av)
{
    if (ac == 2)
    {
        char* infix = strdup(av[1]);
        char postfix[strlen(infix)];
        strip(infix);
        // printf("%s\n", infix);
        if (is_divide_zero(infix))
        {
            fprintf(stderr, "divide by zero\n");
            exit(1);
        }
        else if (is_parse_error(infix))
        {
            fprintf(stderr, "parse error\n");
            exit(EXIT_FAILURE);
        }
        else if (is_error_string(infix))
        {
            fprintf(stderr, "parse error\n");
            exit(1);
        }
        infix_to_postfix(infix, postfix);
        sort_flag(postfix);
    }
    return 0;
}