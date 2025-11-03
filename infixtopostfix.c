#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char c) {
    if (s->top < MAX - 1) {
        s->data[++s->top] = c;
    } else {
        printf("Stack overflow!\n");
        exit(1);
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top--];
    } else {
        printf("Stack underflow!\n");
        exit(1);
    }
}

char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    } else {
        printf("Stack is empty!\n");
        exit(1);
    }
}

int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    } else {
        return 0;
    }
}

void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    initStack(&s);
    int i = 0, j = 0;

    while (infix[i]) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            push(&s, infix[i++]);
        } else if (infix[i] == ')') {
            while (peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); 
            i++;
        } else {
            while (!isEmpty(&s) && peek(&s) != '(' && precedence(infix[i]) <= precedence(peek(&s))) {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i++]);
        }
    }

    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0'; 
}

float evaluatePostfix(char *postfix) {
    Stack s;
    initStack(&s);

    for (int i = 0; postfix[i]; i++) {
        if (isdigit(postfix[i])) {
            push(&s, postfix[i] - '0'); 
        } else {
            float b = pop(&s);
            float a = pop(&s);
            switch (postfix[i]) {
                case '+':
                    push(&s, a + b);
                    break;
                case '-':
                    push(&s, a - b);
                    break;
                case '*':
                    push(&s, a * b);
                    break;
                case '/':
                    if (b != 0) {
                        push(&s, a / b);
                    } else {
                        printf("Error: Division by zero!\n");
                        exit(1);
                    }
                    break;
                default:
                    printf("Invalid operator!\n");
                    exit(1);
            }
        }
    }

    return pop(&s);
}

float evaluateInfix(char *infix) {
    char postfix[MAX];
    infixToPostfix(infix, postfix);
    return evaluatePostfix(postfix);
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = 0; 

    printf("Infix Expression: %s\n", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    printf("Infix Evaluation: %.2f\n", evaluateInfix(infix));
    printf("Postfix Evaluation: %.2f\n", evaluatePostfix(postfix));

    return 0;
}