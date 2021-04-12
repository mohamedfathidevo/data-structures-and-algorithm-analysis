#include <bits/stdc++.h>
using namespace std;
#define SIZE 10

template <typename T>
class queue_array
{
private:
    T *arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    queue_array(int size = SIZE);

    void dequeue();
    void enqueue(T);
    T peek();
    int size();
    bool isEmpty();
    bool isFull();
};

template <typename T>
queue_array<T>::queue_array(int size)
{
    arr = new T[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

template <typename T>
void queue_array<T>::dequeue()
{
    if (isEmpty())
        return;
    front = (front + 1) % capacity;
    count--;
}

template <typename T>
void queue_array<T>::enqueue(T item)
{
    if (isFull())
        return;
    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

template <typename T>
T queue_array<T>::peek()
{
    if (isEmpty())
        exit(EXIT_FAILURE);
    return arr[front];
}

template <typename T>
int queue_array<T>::size()
{
    return count;
}

template <typename T>
bool queue_array<T>::isEmpty()
{
    return (size() == 0);
}

template <typename T>
bool queue_array<T>::isFull()
{
    return (size() == capacity);
}