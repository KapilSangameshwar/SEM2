// Write C Program to Evaluate Infix to prefix conversion Using Stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 100

char stack[N];

int top = -1;

void push(char c)
{

    if (top >= N - 1)
    {

        printf("Stack overflow\n");

        exit(1);
    }

    stack[++top] = c;
}

char pop()
{

    if (top < 0)
    {

        printf("Stack underflow\n");

        exit(1);
    }

    return stack[top--];
}

int is_operator(char c)
{

    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c)
{

    if (c == '+' || c == '-')
    {

        return 1;
    }

    else if (c == '*' || c == '/')
    {

        return 2;
    }

    else if (c == '^')
    {

        return 3;
    }

    return 0;
}

void reverse_string(char *str)
{

    int len = strlen(str);

    int i, j;

    for (i = 0, j = len - 1; i < j; i++, j--)
    {

        char temp = str[i];

        str[i] = str[j];

        str[j] = temp;
    }
}

void infix_to_prefix(char *infix, char *prefix)
{

    int infix_len = strlen(infix);

    int i, j;

    for (i = infix_len - 1, j = 0; i >= 0; i--)
    {

        char c = infix[i];

        if (isdigit(c) || isalpha(c))
        {

            prefix[j++] = c;
        }

        else if (c == ')')
        {

            push(c);
        }

        else if (is_operator(c))
        {

            while (top != -1 &&

                   precedence(stack[top]) > precedence(c))
            {

                prefix[j++] = pop();
            }

            push(c);
        }

        else if (c == '(')
        {

            while (stack[top] != ')')
            {

                prefix[j++] = pop();
            }

            pop();
        }
    }

    while (top != -1)
    {

        prefix[j++] = pop();
    }

    prefix[j] = '\0';

    reverse_string(prefix);
}

int main()
{

    char infix[N], prefix[N];

    scanf("%s", infix);

    infix_to_prefix(infix, prefix);

    printf("%s\n", prefix);

    return 0;
}