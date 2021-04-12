#include <bits/stdc++.h>

using namespace std;

#define MAX 100

class Deque
{
    int arr[MAX];
    int front;
    int rear;
    int size;

public:
    Deque(int size)
    {
        front = -1;
        rear = 0;
        this->size = size;
    }

    void insert_front(int key);

    void insert_rear(int key);

    void delete_front();

    void delete_rear();

    bool isFull();

    bool isEmpty();

    int getFront();

    int getRear();
};

bool Deque::isFull()
{
    return ((front == 0 && rear == size - 1) ||
            front == rear + 1);
}

bool Deque::isEmpty()
{
    return (front == -1);
}

void Deque::insert_front(int key)
{
    if (isFull())
    {
        return;
    }

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (front == 0)
        front = size - 1;

    else
        front = front - 1;
    arr[front] = key;
}

void Deque::insert_rear(int key)
{
    if (isFull())
    {
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == size - 1)
        rear = 0;
    else
        rear = rear + 1;
    arr[rear] = key;
}

void Deque::delete_front()
{
    if (isEmpty())
    {
        return;
    }
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size - 1)
        front = 0;
    else
        front = front + 1;
}

void Deque::delete_rear()
{
    if (isEmpty())
    {
        cout << " Underflow\n"
             << endl;
        return;
    }

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = size - 1;
    else
        rear = rear - 1;
}

int Deque::getFront()
{
    if (isEmpty())
    {
        cout << " Underflow\n"
             << endl;
        return -1;
    }
    return arr[front];
}

int Deque::getRear()
{
    if (isEmpty() || rear < 0)
    {
        cout << " Underflow\n"
             << endl;
        return -1;
    }
    return arr[rear];
}