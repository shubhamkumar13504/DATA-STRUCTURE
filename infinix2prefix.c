#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}

int getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

char stack[MAX];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    if (top == -1)
        return '\0';
    return stack[top--];
}

char peek()
{
    if (top == -1)
        return '\0';
    return stack[top];
}

void reverse(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void swapBrackets(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '(')
            str[i] = ')';
        else if (str[i] == ')')
            str[i] = '(';
    }
}

void infixToPostfix(char *infix, char *output)
{
    int len = strlen(infix);
    top = -1; // clear stack
    char temp[MAX];
    snprintf(temp, MAX, "(%s)", infix);

    int k = 0;
    for (int i = 0; temp[i]; i++)
    {
        char c = temp[i];

        if (isalpha(c) || isdigit(c))
        {
            output[k++] = c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (peek() != '(')
            {
                output[k++] = pop();
            }
            pop(); // remove '('
        }
        else
        {
            if (isOperator(peek()))
            {
                if (c == '^')
                {
                    while (getPriority(c) <= getPriority(peek()))
                    {
                        output[k++] = pop();
                    }
                }
                else
                {
                    while (getPriority(c) < getPriority(peek()))
                    {
                        output[k++] = pop();
                    }
                }
            }
            push(c);
        }
    }

    while (top != -1)
    {
        output[k++] = pop();
    }

    output[k] = '\0';
}

void infixToPrefix(char *infix, char *prefix)
{
    char revInfix[MAX], postfix[MAX];

    strcpy(revInfix, infix);
    reverse(revInfix);
    swapBrackets(revInfix);
    infixToPostfix(revInfix, postfix);
    reverse(postfix);
    strcpy(prefix, postfix);
}

int main()
{
    char infix[MAX] = "K+L-M*N+^OP*W/U/V*T+Q";
    char prefix[MAX];

    printf("Infix expression: %s\n", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
