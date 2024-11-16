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
    front = rear = -1;
    this->size = 10;
    arr = new int[this->size];
  }
  Queue(int size)
  {
    front = rear = -1;
    this->size = size;
    arr = new int[this->size];
  }
  void enQueue(int x);
  int deQueue();
  void display();
};
void Queue::enQueue(int x)
{
  if (rear == size - 1)
  {
    cout << "queue is full";
  }
  rear++;
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
  front++;
  x = arr[front];
  arr[front] = 0;
  return x;
}

void Queue::display()
{
  int i;
  for (i = front + 1; i <= rear; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
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