#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(char c)
{
    // if (top == -1)
    if (top == MAX - 1)
    {
        printf("overflow");
    }
    stack[++top] = c;
}
char pop()
{
    if (top == -1)
    {

        printf("underflow");
        return 0;
    }
    return stack[top--];
}
int balance(const char *expr)
{
    char last;
    for (int i = 0; i < strlen(expr); i++)
    {
        char c = expr[i];
        if (c == '(' || c == '[' || c == '{')
        {
            // push(c);
            if (top == MAX - 1)
            {
                printf("overflow");
            }
            stack[++top] = c;
        }
        if (c == ')' || c == ']' || c == '}')
        {
            if (top == -1)
                return 0;
            // last = pop();
            if (top == -1)
            {

                printf("underflow");
                return 0;
            }
            last = stack[top--];
            if (((last == '(' && c != ')') ||
                 (last == '[' && c != ']') ||
                 (last == '{' && c != '}')))
            {
                return 0;
            }
        }
    }
    bool result = (top == -1);
    return result;
}

// Main function
int main()
{
    char expr[MAX];

    printf("Enter an expression: ");
    scanf("%s", expr);
    printf("%d\n", balance(expr));

    return 0;
}
