#include <bits/stdc++.h>

using namespace std;

template <class T>
struct node
{
    T data;
    node *next;
};

template <typename T>
class stack_linked_list
{
private:
    node<T> *head;

public:
    stack_linked_list();

    void push(T);

    void pop();

    T top();

    ~stack_linked_list();
};

template <typename T>
stack_linked_list<T>::stack_linked_list()
{
}

template <typename T>
void stack_linked_list<T>::push(T new_data)
{
    auto new_node = new node<T>();
    new_node->data = new_data;
    if (head == NULL)
        head = new_node;
    else
    {
        new_node->next = head;
        head = new_node;
    }
}

template <typename T>
void stack_linked_list<T>::pop()
{
    if (head == NULL)
        return;
    node<T> *temp = head;
    if (head->next == NULL)
    {
        delete (temp);
        head = NULL;
    }
    else
    {
        head = head->next;
        delete (temp);
    }
}

template <typename T>
T stack_linked_list<T>::top()
{
    if (head == NULL)
        exit(EXIT_FAILURE);
    else
        return head->data;
}

template <typename T>
stack_linked_list<T>::~stack_linked_list()
{
    node<T> *curr = head;
    while (curr != NULL)
    {
        head = head->next;
        delete (curr);
        curr = head;
    }
}
