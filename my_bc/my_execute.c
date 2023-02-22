#include <stdio.h>
#include "./lib.h"

bool is_operator_exist(char* str)
{
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++)
    {
        if (str[i] == '%' || str[i] == '*' || str[i] == '+' || str[i] == '-' ||
            str[i] == '/')
            return true;
    }
    return false;
}

void sort_flag(char* str)
{
    if (!is_operator_exist(str))
    {
        printf("%d\n", atoi(str));
        return;
    }
    char postfix[256];
    int i;
    int len, val, num1, num2, result, cal = 0, H1;
    int point = 0;
    int point_value;
    strcpy(postfix, str);
    len = strlen(postfix);
    int B[6];
    for (i = 0; i < len; i++)
    {
        switch (type_get_flag(postfix[i]))
        {
            case 0:
                if (postfix[i] == ' ' && cal != 0)
                {
                    pushh(val);
                    cal = 0;
                    break;
                }
                if (postfix[i] == ' ' && cal == 0) break;
                cal++;
                if (postfix[i] == '.')
                {
                    point = 1;
                    point_value = val;
                    cal = 0;
                    break;
                }
                val = postfix[i] - '0';
                B[5] = B[4];
                B[4] = B[3];
                B[3] = B[2];
                B[2] = B[1];
                B[1] = B[0];
                B[0] = val;
                if (cal == 1)
                {
                    val = B[0];
                    H1 = 10;
                }
                if (cal == 2)
                {
                    val = (B[1] * 10) + B[0];
                    H1 = 100;
                }
                if (cal == 3)
                {
                    val = (B[2] * 100) + (B[1] * 10) + B[0];
                    H1 = 1000;
                }
                if (cal == 4)
                {
                    val = (B[3] * 1000) + (B[2] * 100) + (B[1] * 10) + B[0];
                    H1 = 10000;
                }
                if (cal == 5)
                {
                    val = (B[3] * 10000) + (B[2] * 1000) + (B[1] * 100) +
                          (B[1] * 10) + B[0];
                    H1 = 100000;
                }
                if (point == 1 && postfix[i + 1] == ' ')
                {
                    val = point_value + (val / H1);
                    point = 0;
                    break;
                }
                break;

            case -1:
                perror("parse error");
                break;
            case 1:
                num1 = popp();
                num2 = popp();
                switch (postfix[i])
                {
                    case '+':
                        result = num2 + num1;
                        break;
                    case '-':
                        result = num2 - num1;
                        break;
                    case '*':
                        result = num2 * num1;
                        break;
                    case '/':
                        result = num2 / num1;
                        break;
                    case '%':
                        result = (int)num2 % (int)num1;
                        break;
                }
                pushh(result);
        }
    }
    printf("%d\n", result);
}