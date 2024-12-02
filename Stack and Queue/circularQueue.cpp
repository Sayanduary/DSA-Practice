#include <iostream>
using namespace std;
struct Queue
{
  int size;
  int front;
  int rear;
  int *array;
} *Q;
Queue *create(int size)
{
  Queue *q = (Queue *)malloc(sizeof(Queue));
  if (q == NULL)
  {
    return NULL; // Handle memory allocation failure
  }

  q->size = size;
  q->front = q->rear = -1;
  q->array = (int *)malloc(q->size * sizeof(int));
  if (q->array == NULL)
  {
    free(q); // Free allocated memory if array allocation fails
    return NULL;
  }

  return q; // Return the created queue
}
int isEmpty(struct Queue *q)
{
  return q->front == q->rear;
}
int isFull(Queue *q)
{
  return (q->rear + 1) % q->size == q->front;
}
void enQueue(struct Queue *q, int val)
{
  if (isFull(q))
  {
    cout << "Queue is Overflowed ";
  }
  q->rear = (q->rear + 1) % q->size;
  q->array[q->rear] = val;
}
int deQueue(Queue *q)
{
  int val = -1;
  if (isEmpty(q))
  {
    cout << "Queue is Underflowed ";
    return val;
  }
  q->front = (q->front + 1) % q->size;
  val = q->front;
  return val;
}
void display(Queue *q)
{
  int i;
  for (i = (q->front + 1) % q->size; i <= q->rear; i++)
  {
    cout << q->array[i] << " ";
  }
}
int main()
{
  Queue *q = create(10);
  enQueue(q, 10);
  enQueue(q, 20);
  deQueue(q);
  display(q);
  return 0;
}