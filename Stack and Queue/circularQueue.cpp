#include <iostream>
using namespace std;
class Queue
{
private:
  int front;
  int rear;
  int size;
  int *arr;

public:
  Queue()
  {
    front = rear = 0;
    this->size = 10;
    arr = new int[this->size];
  }
  Queue(int size)
  {
    front = rear = 0;
    this->size = size;
    arr = new int[this->size];
  }
  void enQueue(int x);
  int deQueue();
  void display();
};
void Queue::enQueue(int x)
{
  if ((rear + 1) % this->size == front)
  {
    cout << "queue is full";
  }
  rear = (rear + 1) % size;
  arr[rear] = x;
}
int Queue::deQueue()
{
  int x = -1;
  if (rear == front)
  {
    cout << "Queue is Empty ";
    return -1;
  }
  front = (front + 1) % size;
  x = arr[front];

  return x;
}

void Queue::display()
{
  int i = front + 1;
  do
  {
    cout << arr[i] << " ";
    i = (i + 1) % size;
  } while (i != (rear + 1) % size);
}

int main()
{
  Queue q;
  q.enQueue(20);
  q.enQueue(40);
  q.enQueue(80);
  q.deQueue();
  q.display();
  return 0;
}