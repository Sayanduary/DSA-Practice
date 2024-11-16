#include <iostream>
using namespace std;
struct Node
{
  char data;
  Node *next;
} *top = NULL;
void push(int data)
{
  Node *temp;
  temp = (Node *)malloc(sizeof(Node));
  if (temp == NULL)
  {
    cout << "Stack is Full";
  }
  temp->data = data;
  temp->next = top;
  top = temp;
}
int pop()
{
  int x;
  if (top == NULL)
  {
    cout << "stack is empty";
    return '\0';
  }
  x = top->data;
  Node *temp = top;
  top = top->next;
  return x;
  delete temp;
}
int peek()
{
  if (top == NULL)
  {
    cout << "Stack is Empty ";
  }
  return top->data;
}
void display()
{
  Node *temp = top;
  while (temp)
  {
    cout << temp->data;
    temp = temp->next;
  }
  cout << endl;
}
int main()
{
  pop();
  push('a');
  pop();
  push('b');
  pop();
  push('c');
  pop();
  display();
  return 0;
}