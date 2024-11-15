#include <iostream>
using namespace std;
struct Queue
{
  int size;
  int front;
  int rear;
  int *arr; // Pointer to An Arary ,Memory allocation Dynamically
};
void createQueue(Queue *q, int size)
{
  q->size = size;
  q->front = q->rear = -1;
  q->arr = (int *)malloc(q->size * sizeof(int));
}
void enQueue(Queue *q, int x)
{
  if (q->rear == q->size - 1)
  {
    cout << "Queue is Full ";
  }
  q->rear++;
  q->arr[q->rear] = x;
}
int deQueue(Queue *q)
{
  int x = -1;
  if (q->front == q->rear)
  {
    cout << "Queue is Empty";
    return -1;
  }
  q->front++;
  x = q->arr[q->front];
  q->arr[q->front] = 0;
  return x;
}
void displayQueue(struct Queue q)
{
  if (q.front == q.rear)
  {
    cout << "Queue is Empty" << endl;
    return;
  }
  for (int i = q.front + 1; i <= q.rear; i++)
  {
    cout << q.arr[i] << " ";
  }
  cout << endl;
}
int main()
{
  struct Queue q;
  createQueue(&q, 3);
  enQueue(&q, 10);
  enQueue(&q, 30);
  enQueue(&q, 40);
  deQueue(&q);
  displayQueue(q);
  return 0;
}