#include <bits/stdc++.h>
using namespace std;

#define SIZE 10

template <class X>
class stack_array
{
    X *arr;
    int top;
    int capacity;

public:
    stack_array(int size = SIZE);

    void push(X);
    void pop();
    X peek();
    int size();
    bool isEmpty();
    bool isFull();

    ~stack_array()
    {
        delete[] arr;
    }
};

template <typename X>
stack_array<X>::stack_array(int size)
{
    arr = new X[size];
    capacity = size;
    top = -1;
}

template <typename X>
void stack_array<X>::push(X x)
{
    if (isFull())
        return;
    arr[++top] = x;
}

template <typename X>
void stack_array<X>::pop()
{
    if (isEmpty())
        return;
    top--;
}

template <typename X>
X stack_array<X>::peek()
{
    if (!isEmpty())
        return arr[top];
    else
        exit(EXIT_FAILURE);
}

template <typename X>
int stack_array<X>::size()
{
    return top + 1;
}

template <typename X>
bool stack_array<X>::isEmpty()
{
    return top == -1;
}

template <typename X>
bool stack_array<X>::isFull()
{
    return top == capacity - 1;
}