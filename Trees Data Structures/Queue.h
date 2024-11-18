#include <stdio.h>
#include <stdlib.h>
struct Node
{
  Node *lchild;
  int data;
  Node *rchild;
};
typedef struct Queue
{
  int front;
  int rear;
  int size;
  Node **Q;
} Queue;

// Function to create a Queue
Queue *createQueue(int size)
{
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->front = q->rear = 0;
  q->size = size;
  q->Q = (Node **)malloc(sizeof(Node));
  return q;
}

// Function to enqueue an element
void enQueue(Queue *q, Node *x)
{
  if ((q->rear + 1) % q->size == q->front)
  {
    printf("Queue is full\n");
    return;
  }
  q->rear = (q->rear + 1) % q->size;
  q->Q[q->rear] = x;
}

// Function to dequeue an element
struct Node *deQueue(Queue *q)
{
  Node *x = NULL;
  if (q->rear == q->front)
  {
    printf("Queue is Empty\n");
    return NULL;
  }
  q->front = (q->front + 1) % q->size;
  x = q->Q[q->front];
  return x;
}

int isEmpty(struct Queue q)
{
  return q.front == q.rear;
}

int main()
{
  Queue *q = createQueue(10);
  enQueue(q, 20);
  enQueue(q, 40);
  enQueue(q, 80);
  deQueue(q);

  // Free allocated memory
  free(q->arr);
  free(q);

  return 0;
}
