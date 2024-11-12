#include <iostream>
using namespace std;
class Node
{
public:
  int data;
  Node *next;
};
class Stack
{
private:
  Node *top;

public:
  Stack() { top == NULL; }

  void push(int x);
  int pop();
  void display();
};
void Stack::push(int x)
{
  Node *t = new Node;
  if (t == NULL)
  {
    cout << "Stack is Full";
  }
  else
  {
    t->data = x;
    t->next = top;
    top = t;
  }
}

int Stack::pop()
{
  int x;
  if (top == NULL)
  {
    cout << "Stack is Underflow";
  }

  x = top->data;
  Node *temp = top;
  temp = top;
  top = top->next;
  delete temp;
  return x;
}

void Stack::display()
{
  Node *temp = top;
  if (temp)
  {
    cout << temp->data;
    if (temp->next != NULL)
    {
      cout << " -> ";
    }
    temp = temp->next;
  }
}

int main()
{
  Stack stk;
  stk.push(10);
  stk.push(20);
  stk.push(30);
  stk.pop();
  stk.display();

  return 0;
}