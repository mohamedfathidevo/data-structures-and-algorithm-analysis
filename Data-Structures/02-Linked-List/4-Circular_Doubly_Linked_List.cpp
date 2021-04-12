#include <bits/stdc++.h>

using namespace std;

template <class T>
struct node
{
    T data;
    node *next;
    node *prev;
};

template <class T>
class circular_doubly_linked_list
{
public:
    node<T> *head;

    circular_doubly_linked_list();

    ~circular_doubly_linked_list();

    void insert_begin(T);

    void insert_end(T);

    void delete_begin();

    void delete_end();

    bool search_node(T);

    void print_linked_list();
};

template <class T>
circular_doubly_linked_list<T>::circular_doubly_linked_list()
{
    head = NULL;
}

template <class T>
circular_doubly_linked_list<T>::~circular_doubly_linked_list()
{
    head = NULL;
}

template <class T>
void circular_doubly_linked_list<T>::insert_begin(T new_data)
{
    auto *new_node = new node<T>();
    new_node->data = new_data;
    if (head == NULL)
    {
        head = new_node;
        new_node->next = head;
        new_node->prev = head;
    }
    else
    {
        node<T> *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
        head->prev = new_node;
        new_node->next = head;
        head = new_node;
    }
}

template <class T>
void circular_doubly_linked_list<T>::insert_end(T new_data)
{
    auto *new_node = new node<T>();
    new_node->data = new_data;
    if (head == NULL)
    {
        head = new_node;
        new_node->next = head;
        new_node->prev = head;
    }
    else
    {
        node<T> *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
        head->prev = new_node;
        new_node->next = head;
    }
}

template <class T>
void circular_doubly_linked_list<T>::delete_begin()
{
    if (head == NULL)
        return;
    else if (head->next == head)
    {
        head = NULL;
        delete (head);
    }
    else
    {
        node<T> *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = head->next;
        head->next->prev = temp;
        delete (head);
        head = temp->next;
    }
}

template <class T>
void circular_doubly_linked_list<T>::delete_end()
{
    if (head == NULL)
        return;
    else if (head->next == head)
    {
        head = NULL;
        delete (head);
    }
    else
    {
        node<T> *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->prev->next = head;
        head->prev = temp->prev;
        delete (temp);
    }
}

template <class T>
bool circular_doubly_linked_list<T>::search_node(T element)
{
    if (head == NULL)
        return false;
    else
    {
        bool is_found = false;
        node<T> *temp = head;
        while (temp->next != head)
        {
            if (temp->data == element)
                is_found = true;
            temp = temp->next;
        }
        if (temp->data == element)
            is_found = true;
        return is_found;
    }
}

template <class T>
void circular_doubly_linked_list<T>::print_linked_list()
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
