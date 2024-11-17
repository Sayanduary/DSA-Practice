#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
} *front = NULL, *rear = NULL;
void enQueue(int x)
{
    Node *t;
    t = (struct Node *)malloc(sizeof(Node));
    if (t == NULL)
    {
        cout << "Queue is Full ";
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}
int deQueue()
{
    int x = -1;

    if (front == NULL)
    {
        cout << "Queue is Empty ";
        return x;
    }
    Node *temp = front;
    front = front->next;
    x = temp->data;
    delete temp;
    return x;
}
void displayQueue()
{
    Node *temp = front;
    while (temp)
    {
        cout << temp->data << ' ';
        if (temp->next != NULL)
        {
            cout << " -> ";
        }
        temp = temp->next;
    }
}
int main()
{
    enQueue(10);
    enQueue(20);
    deQueue();
    displayQueue();
    return 0;
}