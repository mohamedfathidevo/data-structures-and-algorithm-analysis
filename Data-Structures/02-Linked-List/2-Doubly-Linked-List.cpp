#include <bits/stdc++.h>

using namespace std;

template <class T>
struct node
{
    T data;
    node *prev;
    node *next;
};

template <class T>
class doubly_linked_list
{
public:
    node<T> *head;
    node<T> *tail;

    void insert_begin(T);

    void insert_end(T);

    void insert_node(node<T> *, T);

    void delete_begin();

    void delete_end();

    void delete_node(node<T> *);

    bool search_node_iterative(T);

    bool search_node_recursive(node<T> *, T);

    void print_linked_list_iterative();

    void print_linked_list_recursive(node<T> *);

    int get_length_iterative();

    int get_length_recursive(node<T> *);

    void insert_at(int, T);

    void delete_at(int);

    node<T> *at(int);

    node<T> *print_middle();

    void delete_list_iterative();

    void delete_list_recursive(node<T> *);

    void reverse();

    int count_key_iterative(T);

    int count_key_recursive(node<T> *, T);

    void remove_duplication();

    bool detect_loop();

    int count_nodes(node<T> *);

    int loop_length();

    void swap_nodes(int, int);

    void print_linked_list_reverse();
};

template <typename T>
void doubly_linked_list<T>::insert_begin(T new_data)
{
    auto *new_node = new node<T>();
    new_node->data = new_data;
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

template <typename T>
void doubly_linked_list<T>::insert_end(T new_data)
{
    auto *new_node = new node<T>();
    new_node->data = new_data;
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}

template <typename T>
void doubly_linked_list<T>::insert_node(node<T> *prev_node, T new_data)
{
    if (prev_node == NULL)
        return;
    auto *new_node = new node<T>();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    if (prev_node->next != NULL)
        prev_node->next->prev = new_node;
    prev_node->next = new_node;
    new_node->prev = prev_node;
}

template <typename T>
void doubly_linked_list<T>::delete_begin()
{
    if (head == NULL)
        return;
    node<T> *temp_node = head;
    if (head == tail)
    {
        delete (temp_node);
        head = NULL;
        tail = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
        delete (temp_node);
    }
}

template <typename T>
void doubly_linked_list<T>::delete_end()
{
    if (head == NULL)
        return;
    node<T> *temp_node = tail;
    if (head == tail)
    {
        delete (temp_node);
        head = NULL;
        tail = NULL;
    }
    else
    {
        tail = tail->prev;
        tail->next = NULL;
        delete (temp_node);
    }
}

template <typename T>
void doubly_linked_list<T>::delete_node(node<T> *prev_node)
{
    if (prev_node == NULL || prev_node->next == NULL)
        return;
    node<T> *temp_node = prev_node->next;
    prev_node->next = temp_node->next;
    if (temp_node->next != NULL)
        temp_node->next->prev = prev_node;
    delete (temp_node);
}

template <typename T>
bool doubly_linked_list<T>::search_node_iterative(T key)
{
    node<T> *curr = head;
    while (curr != NULL)
    {
        if (curr->data == key)
            return true;
        curr = curr->next;
    }
    return false;
}

template <typename T>
bool doubly_linked_list<T>::search_node_recursive(node<T> *curr, T key)
{
    if (curr == NULL)
        return false;
    return (curr->data == key) || search_node_recursive(curr->next, key);
}

template <typename T>
void doubly_linked_list<T>::print_linked_list_iterative()
{
    node<T> *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << ' ';
        curr = curr->next;
    }
}

template <typename T>
void doubly_linked_list<T>::print_linked_list_recursive(node<T> *curr)
{
    if (curr == NULL)
        return;
    cout << curr->data << ' ';
    print_linked_list_recursive(curr->next);
}

template <typename T>
int doubly_linked_list<T>::get_length_iterative()
{
    int length = 0;
    node<T> *curr = head;
    while (curr != NULL)
    {
        curr = curr->next;
        length++;
    }
    return length;
}

template <typename T>
int doubly_linked_list<T>::get_length_recursive(node<T> *curr)
{
    if (curr == NULL)
        return 0;
    return 1 + get_length_recursive(curr->next);
}

template <typename T>
void doubly_linked_list<T>::insert_at(int idx, T new_data)
{
    int n = get_length_iterative();
    if (idx < 0 || idx > n)
        return;
    if (idx == 0)
    {
        insert_begin(new_data);
        return;
    }
    if (idx == n - 1)
    {
        insert_end(new_data);
        return;
    }
    int i = 1;
    node<T> *prev = head;
    while (i < idx)
    {
        prev = prev->next;
        i++;
    }
    insert_node(prev, new_data);
}

template <typename T>
void doubly_linked_list<T>::delete_at(int idx)
{
    int n = get_length_iterative();
    if (idx < 0 || idx >= n)
        return;
    if (idx == 0)
    {
        delete_begin();
        return;
    }
    if (idx == n - 1)
    {
        delete_end();
        return;
    }
    int i = 1;
    node<T> *prev = head;
    while (i < idx)
    {
        prev = prev->next;
        i++;
    }
    delete_node(prev);
}

template <typename T>
node<T> *doubly_linked_list<T>::at(int idx)
{
    int n = get_length_iterative();
    if (idx < 0 || idx >= n)
        return NULL;
    int i = 0;
    node<T> *curr = head;
    while (i < idx)
    {
        curr = curr->next;
        i++;
    }
    return curr;
}

template <typename T>
node<T> *doubly_linked_list<T>::print_middle()
{
    if (head == NULL)
        return NULL;
    node<T> *slow_ptr = head;
    node<T> *fast_ptr = head->next;
    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
    return slow_ptr;
}

template <typename T>
void doubly_linked_list<T>::print_linked_list_reverse()
{
    node<T> *curr = tail;
    while (curr != NULL)
    {
        cout << curr->data << ' ';
        curr = curr->prev;
    }
}

template <typename T>
void doubly_linked_list<T>::delete_list_iterative()
{
    node<T> *curr = head;
    while (curr != NULL)
    {
        head = head->next;
        delete (curr);
        curr = head;
    }
}

template <typename T>
void doubly_linked_list<T>::delete_list_recursive(node<T> *curr)
{
    if (curr == NULL)
        return;
    delete_list_recursive(curr->next);
    delete (curr);
}

template <typename T>
void doubly_linked_list<T>::reverse()
{
    node<T> *curr1 = head;
    node<T> *curr2 = tail;
    node<T> *temp;
    while (curr1 != curr2 && curr1->next != curr2 && curr2->prev != curr1)
    {
        temp = curr1;
        curr1 = curr2;
        curr2 = temp;
        curr1 = curr1->next;
        curr2 = curr2->prev;
    }
}

template <typename T>
int doubly_linked_list<T>::count_key_iterative(T key)
{
    int cnt = 0;
    node<T> *curr = head;
    while (curr != NULL)
    {
        if (curr->data == key)
            cnt++;
        curr = curr->next;
    }
    return cnt;
}

template <typename T>
int doubly_linked_list<T>::count_key_recursive(node<T> *curr, T key)
{
    if (curr == NULL)
        return 0;
    return (curr->data == key) + count_key_recursive(curr->next, key);
}

template <typename T>
void doubly_linked_list<T>::remove_duplication()
{
    if (head == NULL)
        return;
    node<T> *curr1 = head;
    while (curr1->next != NULL)
    {
        node<T> *curr2 = curr1->next;
        node<T> *prev2 = curr1;
        while (curr2 != NULL)
        {
            if (curr2->data == curr1->data)
            {
                delete_node(prev2);
                curr2 = prev2;
            }
            prev2 = curr2;
            curr2 = curr2->next;
        }
        if (curr1->next != NULL)
            curr1 = curr1->next;
    }
}

template <typename T>
bool doubly_linked_list<T>::detect_loop()
{
    node<T> *slow_ptr = head;
    node<T> *fast_ptr = head;
    while (fast_ptr && fast_ptr->next)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if (slow_ptr == fast_ptr)
            return true;
    }
    return false;
}

template <typename T>
int doubly_linked_list<T>::count_nodes(node<T> *curr)
{
    int res = 1;
    node<T> *temp = curr;
    while (temp->next != curr)
    {
        res++;
        temp = temp->next;
    }
    return res;
}

template <typename T>
int doubly_linked_list<T>::loop_length()
{
    node<T> *slow_ptr = head;
    node<T> *fast_ptr = head;
    while (fast_ptr && fast_ptr->next)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if (slow_ptr == fast_ptr)
            return count_nodes(slow_ptr);
    }
    return 0;
}

template <typename T>
void doubly_linked_list<T>::swap_nodes(int i, int j)
{
    if (i == j)
        return;
    int n = get_length_iterative();
    if (i < 0 || i >= n)
        return;
    if (j < 0 || j >= n)
        return;
    node<T> *prev1 = at(i - 1);
    node<T> *curr1 = at(i);
    node<T> *prev2 = at(j - 1);
    node<T> *curr2 = at(j);
    if (curr1 == NULL || curr2 == NULL)
        return;
    if (prev1 != NULL)
    {
        prev1->next = curr2;
        curr2->prev = prev1;
    }
    else
        head = curr2;
    if (prev2 != NULL)
    {
        prev2->next = curr1;
        curr1->prev = prev2;
    }
    else
        head = curr1;
    node<T> *temp1 = curr2->next;
    curr2->next = curr1->next;
    curr1->next = temp1;
    node<T> *temp2 = curr2->prev;
    curr2->prev = curr1->prev;
    curr1->prev = temp2;
}