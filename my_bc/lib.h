#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 256
int stk[SIZE]; 
int stack[SIZE];
void push_element(int);
int pop();
int precedence(char);
int empty();
int top_element();
void infix_to_postfix(char*, char*);
void pushh(int);
int popp();
int type_get_flag(char);
void sort_flag(char*);



/*     sardor codes system    */


bool is_operator(char);
bool is_bracket(char);
bool is_digit(char);
bool is_avaiable_input(char*);