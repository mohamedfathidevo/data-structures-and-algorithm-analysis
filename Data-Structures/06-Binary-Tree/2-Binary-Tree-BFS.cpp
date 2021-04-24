#include <bits/stdc++.h>

using namespace std;

template <class T>
struct node
{
    T data;
    node *left;
    node *right;
};

template <class T>
class binary_tree
{
public:
    node<T> *root;

    binary_tree();

    node<T> *creat_node(T);

    void insert_node(T);

    void in_order_recursive(node<T> *);

    void pre_order_recursive(node<T> *);

    void post_order_recursive(node<T> *);

    bool search_recursive(node<T> *, T);

    void breadth_first_traversal();
};

template <class T>
binary_tree<T>::binary_tree()
{
    root = NULL;
}

template <class T>
node<T> *binary_tree<T>::creat_node(T data)
{
    auto *new_node = new node<T>();
    if (!new_node)
        exit(EXIT_FAILURE);
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

template <class T>
void binary_tree<T>::insert_node(T data)
{
    if (root == NULL)
    {
        root = creat_node(data);
        return;
    }
    queue<node<T> *> queue;
    queue.push(root);
    while (!queue.empty())
    {
        node<T> *temp = queue.front();
        queue.pop();

        if (temp->left != NULL)
            queue.push(temp->left);
        else
        {
            temp->left = creat_node(data);
            return;
        }

        if (temp->right != NULL)
            queue.push(temp->right);
        else
        {
            temp->right = creat_node(data);
            return;
        }
    }
}

template <class T>
void binary_tree<T>::in_order_recursive(node<T> *current)
{
    if (current == NULL)
        return;
    in_order_recursive(current->left);
    cout << current->data << ' ';
    in_order_recursive(current->right);
}

template <class T>
void binary_tree<T>::pre_order_recursive(node<T> *curr)
{
    if (curr == NULL)
        return;
    cout << curr->data << ' ';
    pre_order_recursive(curr->left);
    pre_order_recursive(curr->right);
}

template <class T>
void binary_tree<T>::post_order_recursive(node<T> *curr)
{
    if (curr == NULL)
        return;
    post_order_recursive(curr->left);
    post_order_recursive(curr->right);
    cout << curr->data << ' ';
}

template <class T>
bool binary_tree<T>::search_recursive(node<T> *curr, T data)
{
    if (curr == NULL)
        return false;
    if (curr->data == data)
        return true;
    bool left_search = search_recursive(curr->left, data);
    bool right_search = search_recursive(curr->right, data);
    return left_search || right_search;
}

template <class T>
void binary_tree<T>::breadth_first_traversal()
{
    if (root == NULL)
        return;
    queue<node<T> *> q;
    q.push(root);
    while (!q.empty())
    {
        node<T> *curr = q.front();
        q.pop();
        cout << curr->data << ' ';
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}

//
