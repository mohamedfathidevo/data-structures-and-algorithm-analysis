#include <bits/stdc++.h>

using namespace std;

template <class T>
struct node
{
    T data;
    node *next;
};

template <class T>
class circular_linked_list
{
public:
    node<T> *head;

    circular_linked_list();

    ~circular_linked_list();

    void insert_begin(T);

    void insert_end(T);

    void delete_begin();

    void delete_end();

    bool search_node(T);

    void print_linked_list();
};

template <class T>
void circular_linked_list<T>::insert_begin(T new_data)
{
    auto *new_node = new node<T>();
    new_node->data = new_data;
    if (head == NULL)
    {
        head = new_node;
        new_node->next = head;
    }
    else
    {
        node<T> *temp = head;
        while (temp->next != head)
            temp = temp->next;
        new_node->next = head;
        temp->next = new_node;
        head = new_node;
    }
}

template <class T>
void circular_linked_list<T>::insert_end(T new_data)
{
    auto *new_node = new node<T>();
    new_node->data = new_data;
    if (head == nullptr)
    {
        head = new_node;
        new_node->next = head;
    }
    else
    {
        node<T> *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = new_node;
        new_node->next = head;
    }
}

template <class T>
void circular_linked_list<T>::delete_begin()
{
    if (head == NULL)
        return;
    if (head->next == head)
    {
        head = NULL;
    }
    else
    {
        node<T> *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = head->next;
        delete (head);
        head = temp->next;
    }
}

template <class T>
void circular_linked_list<T>::delete_end()
{
    if (head == NULL)
        return;
    if (head->next == head)
    {
        head = NULL;
    }
    else
    {
        node<T> *temp = head;
        node<T> *prev = NULL;
        while (temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete (temp);
    }
}

template <class T>
bool circular_linked_list<T>::search_node(T element)
{
    bool isFound = false;
    node<T> *temp = head;
    while (temp->next != head)
    {
        if (temp->data == element)
        {
            isFound = true;
            break;
        }
        temp = temp->next;
    }
    return isFound;
}

template <class T>
void circular_linked_list<T>::print_linked_list()
{
    node<T> *temp = head;
    cout << "[ ";
    while (temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ]\n";
}

template <class T>
circular_linked_list<T>::circular_linked_list()
{
    head = NULL;
}

template <class T>
circular_linked_list<T>::~circular_linked_list()
{
    head = NULL;
}