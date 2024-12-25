#include <iostream>
using namespace std;
#define MAX 5
typedef struct
{
  int front, rear;
  int arr[MAX];
} Queue;

void initializeQueue(Queue *q)
{
  q->front = q->rear = -1;
}

int isFull(Queue *q)
{
  return (q->rear + 1) % MAX == q->front;
}
int isEmpty(Queue *q)
{
  return q->front == -1;
}

void enQueue(Queue *q, int val)
{
  if (isFull(q))
  {
    cout << "Queue is Full Cannot insert";
    return;
  }
  if (q->front == -1)
  {
    q->front = 0;
  }
  q->rear = (q->rear + 1) % MAX;
  q->arr[q->rear] = val;
}

int deQueue(Queue *q)
{
  if (isEmpty(q))
  {
    return -1;
  }
  int value = q->arr[q->front];
  if (q->rear == q->front)
  {
    q->front = q->rear = -1;
  }
  q->front = (q->front + 1) % MAX;
  return value;
}

void display(Queue *q)
{
  if (isEmpty(q))
  {
    cout << "Queue is empty!" << endl;
  }
  else
  {
    int i = q->front;
    cout << "Queue elements: ";
    while (i != q->rear)
    {
      cout << q->arr[i] << " ";
      i = (i + 1) % MAX;
    }
    cout << q->arr[q->rear] << endl; // Print the last element
  }
}
int main()
{
  Queue q;
  initializeQueue(&q);

  enQueue(&q, 10);
  enQueue(&q, 20);
  enQueue(&q, 30);
  enQueue(&q, 40);
  enQueue(&q, 50);

  display(&q);

  return 0;
}