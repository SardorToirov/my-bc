#include <string.h>
#include "lib.h"

int top = -1;
const int OPERATORS[5] = {37, 42, 43, 45,
                          47};     // ascci table* '%','*','+','-','/';
const int BRACKETS[2] = {40, 41};  // ascci table* '(',')';

bool is_operator(char c)
{
    for (int i = 0; i < 5; i++)
    {
        if (c == OPERATORS[i]) return true;
    }
    return false;
}
bool is_bracket(char c)
{
    if (c == 40 || c == 41)  // ASCII table code
        return true;
    return false;
}
bool is_digit(char c)
{
    return (c >= 48 && c <= 57);
}

// It will push the element to the stack
void push_element(int d)
{
    if (top == SIZE - 1)
    {
        exit(1);
    }
    top++;
    stack[top] = d;
}

void pushh(int a)
{
    if (top == SIZE - 1)
    {
        printf("parse error\n");
        exit(1);
    }
    stk[++top] = a;
}
// It will pop the charater from the stack
int pop()
{
    if (top == -1)
    {
        printf("parse error\n");
        exit(1);
    }
    else
    {
        int x;
        x = stack[top];
        top = top - 1;
        return (x);
    }
}

// This function will pop up the value from the stack that will be give the
// actual calculate value
int popp()
{
    return (stk[top--]);
}
int precedence(char x)
{
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/' || x == '%' || x == '!') return 2;
    return (3);
}

int empty()
{
    if (top == -1) return 1;
    return 0;
}

int top_element()
{
    return (stack[top]);
}

void infix_to_postfix(char* infix, char* postfix)
{
    char x, token;
    int i, j = 0;
    for (i = 0; infix[i]; i++)
    {
        token = infix[i];
        if (isalnum(token) || token == '.')
            postfix[j++] = token;
        else if (token == '(')
            push_element('(');
        else if (token == ')')
            while ((x = pop()) != '(')
            {
                postfix[j++] = ' ';
                postfix[j++] = x;
            }
        else
        {
            postfix[j++] = ' ';
            while (precedence(token) <= precedence(top_element()) && !empty())
            {
                x = pop();
                postfix[j++] = x;
                postfix[j++] = ' ';
            }
            push_element(token);
        }
    }
    while (!empty())
    {
        x = pop();
        postfix[j++] = ' ';
        postfix[j++] = x;
    }
    postfix[j] = '\0';
}
// This function will get the postfix value and calculate this and give the
// actual value in integer or float value
int type_get_flag(char flag)
{
    if (flag == '+' || flag == '-' || flag == '*' || flag == '/' || flag == '%')
        return 1;
    if (flag == '0' || flag == '1' || flag == '2' || flag == '3' ||
        flag == '4' || flag == '5' || flag == '6' || flag == '7' ||
        flag == '8' || flag == '9' || flag == ' ' || flag == '.')
        return 0;
    else
        return -1;
}
