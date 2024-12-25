#include <iostream>
using namespace std;
typedef struct Node
{
  int data;
  struct Node *next;
} Node;

typedef struct
{
  Node *front;
  Node *rear;

} Queue;

void initializeQueue(Queue *q)
{
  q->front = NULL;
  q->rear = NULL;
}

int isEmpty(Queue *q)
{
  return q->front == NULL;
}
void enQueue(Queue *q, int val)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode)
  {
    cout << "Memory Allocation Failed";
    return;
  }
  newNode->data = val;
  newNode->next = NULL;

  if (isEmpty(q))
  {
    q->front = q->rear = newNode;
  }
  q->rear->next = newNode;
  q->rear = newNode;
}

int deQueue(Queue *q)
{
  if (isEmpty(q))
  {
    cout << "Queue is empty.Cannot dequeue";
  }
  Node *temp = q->front;
  int value = temp->data;
  q->front = q->front->next;

  if (q->front == NULL)
  {
    q->rear = NULL;
  }
  free(temp);
  return value;
}

void display(Queue *q)
{
  if (isEmpty(q))
  {
    cout << "Queue is Empty ";
    return;
  }
  Node *temp = q->front;
  cout << "Queue Elememts";
  while (temp != NULL)
  {
    cout << " " << temp->data;
    if (temp->next != NULL)
    {
      cout << " -> ";
    }
    temp = temp->next;
  }
  cout << endl;
}


int main()
{
  Queue q;
  initializeQueue(&q);
  enQueue(&q, 10);
  enQueue(&q, 20);
  enQueue(&q, 30);
  deQueue(&q);
  display(&q);
  return 0;
}