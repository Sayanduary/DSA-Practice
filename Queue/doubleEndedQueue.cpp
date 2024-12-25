#include <iostream>
using namespace std;
#define MAX 100
typedef struct
{
  int arr[MAX];
  int front;
  int rear;
} Queue;
void initializeQueue(Queue *q)
{
  q->front = q->rear = -1;
}
int isEmpty(Queue *q)
{
  return (q->front == -1);
}
int isFull(Queue *q)
{
  return ((q->front == 0 && q->rear == MAX - 1) || q->front == q->rear + 1);
}
void insertQueueAtFront(Queue *q, int val)
{
  if (isFull(q))
  {
    cout << "Can not insert vallue in the Queue";
    return;
  }
  if (isEmpty(q))
  {
    q->front = q->rear = 0;
  }
  else if (q->front == 0)
  {
    q->front = MAX - 1;
  }
  else
  {
    q->front--;
  }
  q->arr[q->front] = val;
}
void insertQueueInRear(Queue *q, int val)
{
  if (isFull(q))
  {
    cout << "Can not inset value in queue";
    return;
  }
  if (isEmpty(q))
  {
    q->front = q->rear = 0;
  }
  else if (q->rear = MAX - 1)
  {
    q->rear = 0;
  }
  else
  {
    q->rear++;
  }
  q->arr[q->rear] = val;
}
void deleteFront(Queue *q)
{
  if (isEmpty(q))
  {
    cout << "Queue is Empty";
    return;
  }
}
int main()
{
  return 0;
}