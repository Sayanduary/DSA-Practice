#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *front = NULL, *rear = NULL;
void enQueue(int val)
{
    struct Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        cout << "Queue is Full";
        return;
    }
    newNode->data = val;
    newNode->next = NULL;
    if (front == NULL)
    {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}
void display(struct Node *head_ref)
{
    while (head_ref)
    {

        cout << head_ref->data << " ";
        head_ref = head_ref->next;
    }
}
int deQueue()
{
    int val = -1;
    Node *ptr = front;
    if (front == NULL)
    {
        cout << "Queue is Empty";
        return val;
    }
    front = front->next;
    val = ptr->data;
    free(ptr);
    return val;
}
int main()
{
    enQueue(100);
    enQueue(40);
    enQueue(90);
    enQueue(20);
    deQueue();
    display(front);
    return 0;
}