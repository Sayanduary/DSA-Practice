#include <iostream>
#include <string.h>
using namespace std;
struct Stack
{
  int size;
  int top;
  char *arr;
};
void createStack(struct Stack *st, int size)
{
  st->size = size;
  st->top = -1;
  st->arr = (char *)malloc(size * sizeof(char));
}
int isEmpty(struct Stack *st)
{
  return st->top == -1;
}
int isFull(Stack *st)
{
  return (st->top == st->size - 1);
}
void push(Stack *st, char val)
{
  if (!isFull(st))
  {
    st->top++;
    st->arr[st->top] = val;
  }
}
char pop(struct Stack *st)
{
  char x = '\0';
  if (isEmpty(st))
  {
    cout << "Stack Underflow ";
  }
  x = st->arr[st->top];
  st->top--;
  return x;
}
int isMatchingPair(char opening, char closing)
{
  return (opening == '(' && closing == ')') ||
         (opening == '{' && closing == '}') ||
         (opening == '[' && closing == ']');
}
int isBalance(char *exp)
{
  struct Stack st;
  createStack(&st, strlen(exp));
  for (int i = 0; exp[i] != '\0'; i++)
  {
    if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
    {
      push(&st, exp[i]);
    }
    else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
    {
      if (isEmpty(&st) || !isMatchingPair(pop(&st), exp[i]))
      {
        free(st.arr);
        return 0;
      }
    }
  }
  int balanced = isEmpty(&st);
  free(st.arr);
  return balanced;
}
int main()
{
  char exp[] = "";
  if (isBalance(exp))
  {
    cout << "Balanced ";
  }
  else
  {
    cout << "Not Balanced ";
  }
  return 0;
}