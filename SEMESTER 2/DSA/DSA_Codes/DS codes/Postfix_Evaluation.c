//postfix evaluation

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure for stack
struct Stack {
    int top;
    int array[MAX_SIZE];
};

// Stack operations
void push(struct Stack *stack, int item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->array[stack->top--];
}

// Function to evaluate postfix expression
int evaluatePostfix(char *expression) {
    struct Stack stack;
    stack.top = -1;

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                case '%':
                    push(&stack, operand1 % operand2);
                    break;
            }
        }
    }

    return pop(&stack);
}

// Test the postfix evaluation function
int main() {
    char postfixExpression[MAX_SIZE];
    printf("Enter a postfix expression: ");
    fgets(postfixExpression, MAX_SIZE, stdin);

    int result = evaluatePostfix(postfixExpression);
    printf("Result: %d\n", result);

    return 0;
}

