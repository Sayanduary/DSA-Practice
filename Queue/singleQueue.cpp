#include <iostream>
using namespace std;
#define MAX 100
typedef struct
{
  int arr[MAX];
  int front;
  int rear;
} Queue;
void intializeQueue(Queue *q)
{
  q->front = -1;
  q->rear = -1;
}
int isEmpty(Queue *q)
{
  return q->front == -1;
}
int isFull(Queue *q)
{
  return q->rear == MAX - 1;
}
void enQueue(Queue *q, int val)
{
  if (isFull(q))
  {
    return;
  }
  if (isEmpty(q))
  {
    q->front = 0;
  }

  q->rear++;

  q->arr[q->rear] = val;
}
int deQueue(Queue *q)
{
  if (isEmpty(q))
  {
    cout << "Queue is empty can not delete item";
  }

  int value = q->arr[q->front];
  if (q->front == q->rear)
  {
    q->front = q->rear = -1;
  }
  q->front++;
  return value;
}

void display(Queue *q)
{
  if (isEmpty(q))
  {
    cout << "Queue is empty nothing to display";
  }
  cout << "Queue Elements";
  for (int i = q->front; i <= q->rear; i++)
  {
    cout << " " << q->arr[i];
  }
  cout << endl;
}
int main()
{
  Queue q;

  intializeQueue(&q);

  enQueue(&q, 10);
  enQueue(&q, 20);
  enQueue(&q, 30);
  deQueue(&q);
  display(&q);

  return 0;
}
