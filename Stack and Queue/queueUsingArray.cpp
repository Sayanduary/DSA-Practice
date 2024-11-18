#include <iostream>
#include <stdlib.h>
using namespace std;
struct Queue
{
  int size;
  int front;
  int rear;
  int *array;
};
int isFull(Queue *q)
{
  return (q->rear == q->size - 1);
}
int isEmpty(Queue *q)
{
  return (q->front == q->rear);
}
void enQueue(struct Queue *q, int val)
{
  if (isFull(q))
  {
    cout << "This Queue is Full";
  }
  else
  {
    q->rear++;
    q->array[q->rear] = val;
  }
}
int deQueue(Queue *q)
{
  int val = -1;
  if (isEmpty(q))
  {
    cout << "The Queue is Empty ";
    return val;
  }
  q->front++;
  val = q->array[q->front];
  return val;
}
void QueueDisplay(Queue q)
{
  for (int i = q.front + 1; i <= q.rear; i++)
  {
    cout << q.array[i] << " ";
  }
}
int main()
{
  struct Queue q;
  q.size = 100;
  q.front = q.rear = -1;
  q.array = (int *)malloc(q.size * (sizeof(int)));
  enQueue(&q, 10);
  enQueue(&q, 20);
  deQueue(&q);
  QueueDisplay(q);
  return 0;
}