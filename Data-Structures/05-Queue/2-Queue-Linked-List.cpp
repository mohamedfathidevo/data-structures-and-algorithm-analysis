#include <bits/stdc++.h>

using namespace std;

template <class T>
struct node
{
    T data;
    node *next;
};

template <class T>
class queue_linked_list
{
private:
    node<T> *front;
    node<T> *rear;
    int count;

public:
    queue_linked_list();

    void dequeue();

    void enqueue(T);

    T peek();

    int size();

    bool isEmpty();

    void print_queue();

    ~queue_linked_list()
    {
        node<T> temp = front;
        while (temp != NULL)
        {
            front = front->next;
            delete (temp);
            temp = front;
        }
    }
};

template <class T>
queue_linked_list<T>::queue_linked_list()
{
    front = rear = NULL;
    count = 0;
}

template <class T>
void queue_linked_list<T>::dequeue()
{
    if (isEmpty())
        return;
    node<T> *temp = front;
    if (front->next == NULL)
    {
        front = rear = NULL;
        delete (temp);
    }
    else
    {
        front = front->next;
        delete (temp);
    }
    count--;
}

template <class T>
void queue_linked_list<T>::enqueue(T new_data)
{
    auto *new_node = new node<T>();
    new_node->data = new_data;
    if (front == NULL && rear == NULL)
        front = rear = new_node;
    else
    {
        rear->next = new_node;
        rear = new_node;
    }
    count++;
}

template <class T>
T queue_linked_list<T>::peek()
{
    if (isEmpty())
        exit(EXIT_FAILURE);
    return front->data;
}

template <class T>
int queue_linked_list<T>::size()
{
    return count;
}

template <class T>
bool queue_linked_list<T>::isEmpty()
{
    return (front == NULL);
}

template <typename T>
void queue_linked_list<T>::print_queue()
{
    node<T> *curr = front;
    while (curr != NULL)
    {
        cout << curr->data << ' ';
        curr = curr->next;
    }
}
