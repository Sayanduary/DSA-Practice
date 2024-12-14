#include <iostream>
using namespace std;
struct Queue
{
  int *arr;
  int front;
  int rear;
  int size;
};
void create(Queue *q, int size)
{
  q->size = size;
  q->front = q->rear = 0;
  q->arr = (int *)malloc(q->size * sizeof(int));
}
void enQueue(struct Queue *q, int data)
{
  if ((q->rear + 1) % q->size == q->front)
  {
    cout << "Queue is Full";
    return;
  }
  q->rear = ((q->rear + 1) % q->size);
  q->arr[q->rear] = data;
}

int deQueue(Queue *q)
{

  if (q->front == q->rear)
  {
    cout << "Queue is Empty";
    return -1;
  }
  q->front = ((q->front + 1) % q->size);
  return q->arr[q->front];
}

void display(Queue *q)
{
  if (q->front == q->rear)
  {
    cout << "Queue is Empty";
    return;
  }
  int i = (q->front + 1) % q->size;
  while (i != (q->rear + 1) % q->size)
  {
    cout << i << q->arr[i] << " ";
    i = (i + 1) % q->size;
  }
}
int main()
{
  struct Queue *q;
  create(q, 5);
  enQueue(q, 10);
  enQueue(q, 13);
  enQueue(q, 13);
  deQueue(q);
  deQueue(q);
  display(q);

  return 0;
}