#include <iostream>
using namespace std;
struct Queue
{
  int data;
  Queue *next;
};
struct Queue *front;
struct Queue *rear;
void insert(Queue *)
{
  struct Queue *ptr;
  int data;
  ptr = (Queue *)malloc(sizeof(Queue));
  if (ptr == NULL)
  {
    cout << "Overflow";
    return;
  }
  else
  {
    cout << "Enter the Data";
    cin >> data;
    ptr->data = data;
    if (front == NULL)
    {
      front = ptr;
      rear = ptr;
      front->next = NULL;
      rear->next = NULL;
    }
    else
    {
      rear->next = ptr;
      rear = ptr;
      rear->next = NULL;
    }
  }
}
void deleteQueue(Queue *q)
{
  Queue *ptr;
  if (front == NULL)
  {
    cout << "Underflow";
    return;
  }
  else
  {
    ptr = front;
    front = front->next;
    free(ptr);
  }
}
void display(Queue *q)
{
  Queue *ptr = front;
  if (front == NULL)
  {
    cout << "Empty Queue";
    return;
  }
  while (ptr)
  {
    cout << ptr->data;
    if (ptr->next != NULL)
    {
      cout << "->";
    }
    ptr = ptr->next;
  }
}
int main()
{
  Queue *node;
  insert(node);
  insert(node);
  deleteQueue(node);
  display(node);

  return 0;
}