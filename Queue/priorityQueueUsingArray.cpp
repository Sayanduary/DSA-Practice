#include <iostream>
using namespace std;
#define MAX 50
struct Queue
{
  int arr[MAX];
  int front;
  int rear;
} *q;
void initialize(Queue *q)
{
  q->front = q->rear = -1;
};
bool isFull(Queue *q)
{
  return q->rear == MAX - 1;
}
bool isEmpty(Queue *q)
{
  return q->rear == -1 || q->front == -1;
}

void priorityQueue(Queue *q, int val)
{
  if (isFull(q))
  {
    cout << "Queue is Overflowed ";
    return;
  }
  int i;
  if (isEmpty(q))
  {
    q->front = q->rear = 0;
    q->arr[q->rear] = val;
    return;
  }
  for (i = q->rear; i >= q->front && q->arr[i] > val; i--)
  {
    q->arr[i + 1] = q->arr[i];
  }
  q->arr[i + 1] = val;
  q->rear++;
}
int deQueue(Queue *q)
{
  if (isEmpty(q))
  {
    cout << "Underflow";
    return -1;
  }
  int val = q->arr[q->front];
  q->front++;
  if (q->front > q->rear)
  {
    q->rear = q->front = -1;
  }
  return val;
};
void display(Queue *q)
{
  if (isEmpty(q))
  {
    cout << "Underflow";
    return;
  }
  for (int i = q->front; i <= q->rear; i++)
  {
    cout << q->arr[i] << " ";
  }
};

int main()
{
  Queue q;
  initialize(&q);

  // Test priorityQueue queue
  priorityQueue(&q, 30);
  priorityQueue(&q, 10);
  priorityQueue(&q, 20);
  priorityQueue(&q, 40);

  cout << "After priorityQueue insertions:\n";
  display(&q);

  cout << "Dequeue element: " << deQueue(&q) << " AND " << deQueue(&q) << "\n";
  display(&q);
  return 0;
}