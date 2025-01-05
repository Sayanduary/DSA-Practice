#include <stdio.h>
#include <stdlib.h>
#define MAX 5
struct Stack
{
  int top;
  int arr[MAX];
};
void initStack(struct Stack *stack)
{
  stack->top = -1;
}
int isEmpty(struct Stack *stack)
{
  return stack->top == -1;
}
int isFull(struct Stack *stack)
{
  return stack->top == MAX - 1;
}
void push(struct Stack *stack, int val)
{
  if (isFull(stack))
  {
    printf("Stack OverFlow!");
  }
  else
  {
    stack->arr[++stack->top] = val;
  }
}
int pop(struct Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack is UnerFlow!");
  }
  return stack->arr[stack->top--];
}
int peek(struct Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Nothing to peek");
  }
  return stack->arr[stack->top];
}

void displayStack(struct Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack is Empty");
  }
  for (int i = stack->top; i >= 0; i--)
  {
    printf("%d", stack->arr[i]);
    printf("\n");
  }
}

int main()
{
  struct Stack stack;
  initStack(&stack);
  push(&stack, 10);
  push(&stack, 20);
  push(&stack, 400);
  push(&stack, 50);

  pop(&stack);
  displayStack(&stack);
  int ele = peek(&stack);
  printf("top od element: %d", ele);
  return 0;
}