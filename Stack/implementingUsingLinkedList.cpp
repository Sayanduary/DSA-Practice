#include <iostream>
using namespace std;
struct Node
{
  int data;
  struct Node *next;
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
  Node *temp;
  if (top == NULL)
  {
    cout << "Stack is Empty";
  }
  else
  {
    temp = top;
    top = top->next;
    x = temp->data;
    delete temp;
  }
  return x;
}

void display()
{
  struct Node *temp = top;
  while (temp)
  {
    cout << temp->data << " ";
    if (temp->next != NULL)
    {
      cout << " -> ";
    }
    temp = temp->next;
  }
}

int main()
{
  push(10);
  push(20);
  push(30);
  push(40);
  cout << "Popped Data-> " << pop() << endl;
  display();
  return 0;
}