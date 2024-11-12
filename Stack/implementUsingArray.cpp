#include <iostream>
using namespace std;
struct Stack
{
  int size;
  int top;
  int *arr;
};

void createStack(struct Stack *st)
{
  cout << "Enter Size " << endl;
  cin >> st->size;
  st->top = -1;
  st->arr = (int *)malloc(st->size * sizeof(int));
}
void displayStack(struct Stack st)
{
  int i;
  for (i = st.top; i >= 0; i--)
  {
    cout << st.arr[i] << " ";
  }
  cout << endl;
}

void push(struct Stack *st, int data)
{
  if (st->top == st->size - 1)
  {
    cout << "Stack Overflow ";
  }
  st->top++;
  st->arr[st->top] = data;
}
int pop(struct Stack *st)
{
  int x = -1;
  if (st->top == -1)
  {
    cout << "Stack Underflow ";
  }
  x = st->arr[st->top];
  st->top--;
  return x;
}

int peek(struct Stack st, int pos)
{
  int x = -1;
  if (st.top - pos + 1 < 0)
  {
    cout << "invalid Position";
  }
  x = st.arr[st.top - pos + 1];
  return x;
}

int main()
{
  struct Stack st;
  createStack(&st);
  push(&st, 10);
  push(&st, 20);
  push(&st, 40);
  push(&st, 100);
  
  // pop(&st);
  displayStack(st);
  cout << "Element--> " << peek(st, 1) << endl;

  return 0;
}