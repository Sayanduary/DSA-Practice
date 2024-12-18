#include <iostream>
using namespace std;

struct Queue {
    int *arr;
    int front;
    int rear;
    int size;
};

void create(Queue &q, int size) {
    q.size = size;
    q.front = q.rear = 0;
    q.arr = new int[q.size];
}

void enQueue(Queue &q, int data) {
    if ((q.rear + 1) % q.size == q.front) {
        cout << "Queue is Full" << endl;
        return;
    }
    q.rear = (q.rear + 1) % q.size;
    q.arr[q.rear] = data;
}

int deQueue(Queue &q) {
    if (q.front == q.rear) {
        cout << "Queue is Empty" << endl;
        return -1;
    }
    q.front = (q.front + 1) % q.size;
    return q.arr[q.front];
}

void display(Queue &q) {
    if (q.front == q.rear) {
        cout << "Queue is Empty" << endl;
        return;
    }
    int i = (q.front + 1) % q.size;
    while (i != (q.rear + 1) % q.size) {
        cout << q.arr[i] << " ";
        i = (i + 1) % q.size;
    }
    cout << endl;
}

int main() {
    Queue q;
    create(q, 5);

    enQueue(q, 10);
    enQueue(q, 13);
    enQueue(q, 15);

    cout << "Dequeued: " << deQueue(q) << endl;
    cout << "Dequeued: " << deQueue(q) << endl;

    cout << "Queue Contents: ";
    display(q);

    delete[] q.arr; // Free allocated memory
    return 0;
}
