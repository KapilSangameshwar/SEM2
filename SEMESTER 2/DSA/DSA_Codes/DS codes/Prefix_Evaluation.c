//Prefix Evaluation

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

// Function to evaluate prefix expression
int evaluatePrefix(char *expression) {
    struct Stack stack;
    stack.top = -1;

    // Read the expression from right to left
    for (int i = strlen(expression) - 1; i >= 0; i--) {
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');
        } else {
            int operand1 = pop(&stack);
            int operand2 = pop(&stack);
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

// Test the prefix evaluation function
int main() {
    char prefixExpression[MAX_SIZE];
    printf("Enter a prefix expression: ");
    fgets(prefixExpression, MAX_SIZE, stdin);

    int result = evaluatePrefix(prefixExpression);
    printf("Result: %d\n", result);

    return 0;
}
