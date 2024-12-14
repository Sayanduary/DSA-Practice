// Pre Requirements
// 1.Two Pointers(front and rear)
// 2.One Array

#include <iostream>
using namespace std;
struct Queue
{
  int size;
  int front;
  int rear;
  int *arr;
};
void enQueue(Queue *q, int val)
{
  if (q->rear == q->size - 1)
  {
    cout << "Overflow";
    return;
  }
  q->rear++;
  q->arr[q->rear] = val;
}
int deQueue(Queue *q)
{
  int x = -1;
  if (q->front == q->rear)
  {
    cout << "isEmpty";
  }
  q->front++;
  x = q->arr[q->front];
  return x;
}
void display(Queue *q)
{
  for (int i = q->front + 1; i <= q->rear; i++)
  {
    cout << q->arr[i] << " ";
  }
}
int main()
{
  struct Queue q;
  cout << "Enter the size: ";
  cin >> q.size;
  q.arr = (int *)malloc(q.size * sizeof(int));
  q.front = q.rear = -1;
  enQueue(&q, 10);
  enQueue(&q, 12);
  deQueue(&q);
  display(&q);
  return 0;
}