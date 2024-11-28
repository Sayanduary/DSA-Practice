#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node
{
    char data;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *top;
} Stack;

void initStack(Stack *s)
{
    s->top = NULL;
}

int isEmpty(Stack *s)
{
    return s->top == NULL;
}

void push(Stack *s, char value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

char pop(Stack *s)
{
    if (isEmpty(s))
    {
        return '\0'; // Return null character if stack is empty
    }
    Node *temp = s->top;
    char value = temp->data;
    s->top = s->top->next;
    free(temp);
    return value;
}

char peek(Stack *s)
{
    if (isEmpty(s))
    {
        return '\0'; // Return null character if stack is empty
    }
    return s->top->data;
}

int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void infixToPostfix(char *infix, char *postfix)
{
    Stack s;
    initStack(&s);
    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i]; // Add operand to output
        }
        else if (infix[i] == '(')
        {
            push(&s, infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(&s) && peek(&s) != '(')
            {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Pop the '('
        }
        else if (isOperator(infix[i]))
        {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(infix[i]))
            {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
        i++;
    }

    while (!isEmpty(&s))
    {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0'; // Null-terminate the postfix string
}

int main()
{
    char infix[100], postfix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
