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
class binary_search_tree
{
private:
    node<T> *root;

    void insert_node(node<T> *&, node<T> *&);

    void in_order_recursive(node<T> *);

    void pre_order_recursive(node<T> *);

    void post_order_recursive(node<T> *);

    bool search_recursive(node<T> *, T);

    node<T> *min_node(node<T> *);

    node<T> *max_node(node<T> *);

    void delete_node(node<T> *&, T);

    void delete_tree(node<T> *);

public:
    binary_search_tree();

    ~binary_search_tree();

    void insert_node(T);

    void in_order_recursive();

    void pre_order_recursive();

    void post_order_recursive();

    bool search_recursive(T);

    node<T> *min_node();

    node<T> *max_node();

    void delete_node(T);

    void delete_tree();
};

template <class T>
binary_search_tree<T>::binary_search_tree()
{
    root = nullptr;
}

template <class T>
void binary_search_tree<T>::in_order_recursive(node<T> *current)
{
    if (current == nullptr)
        return;
    in_order_recursive(current->left);
    cout << current->data << ' ';
    in_order_recursive(current->right);
}

template <class T>
void binary_search_tree<T>::pre_order_recursive(node<T> *curr)
{
    if (curr == NULL)
        return;
    cout << curr->data << ' ';
    pre_order_recursive(curr->left);
    pre_order_recursive(curr->right);
}

template <class T>
void binary_search_tree<T>::post_order_recursive(node<T> *curr)
{
    if (curr == NULL)
        return;
    post_order_recursive(curr->left);
    post_order_recursive(curr->right);
    cout << curr->data << ' ';
}

template <class T>
bool binary_search_tree<T>::search_recursive(node<T> *curr, T data)
{
    if (curr == NULL)
        return false;
    if (curr->data == data)
        return true;
    if (data < curr->data)
        return search_recursive(curr->left, data);
    else
        return search_recursive(curr->right, data);
}

template <class T>
node<T> *binary_search_tree<T>::max_node(node<T> *curr)
{
    if (curr->right == nullptr)
        return curr;
    else
        return max_node(curr->right);
}

template <class T>
node<T> *binary_search_tree<T>::min_node(node<T> *curr)
{
    if (curr->left == nullptr)
        return curr;
    else
        return min_node(curr->left);
}

template <class T>
void binary_search_tree<T>::delete_node(node<T> *&curr, T data)
{
    if (curr == nullptr)
        return;
    if (data < curr->data)
        delete_node(curr->left, data);
    else if (data > curr->data)
        delete_node(curr->right, data);
    else
    {
        if (curr->right == nullptr)
            curr = curr->left;
        else if (curr->left == nullptr)
            curr = curr->right;
        else
        {
            // get the successor ( smallest in the right subtree )
            node<T> *temp = min_node(curr->right);
            temp->left = curr->left;
            temp = curr;
            curr = curr->right;
            delete temp;
        }
    }
}

template <class T>
void binary_search_tree<T>::delete_tree(node<T> *curr)
{
    if (curr == nullptr)
        return;
    delete_tree(curr->left);
    delete_tree(curr->right);
    delete (curr);
}

template <class T>
void binary_search_tree<T>::insert_node(node<T> *&curr, node<T> *&new_node)
{
    if (curr == nullptr)
        curr = new_node;
    else if (new_node->data < curr->data)
        insert_node(curr->left, new_node);
    else
        insert_node(curr->right, new_node);
}

template <class T>
void binary_search_tree<T>::insert_node(T data)
{
    auto *new_node = new node<T>();
    new_node->data = data;
    new_node->left = new_node->right = nullptr;
    insert_node(root, new_node);
}

template <class T>
void binary_search_tree<T>::in_order_recursive()
{
    in_order_recursive(root);
}

template <class T>
void binary_search_tree<T>::pre_order_recursive()
{
    pre_order_recursive(root);
}

template <class T>
void binary_search_tree<T>::post_order_recursive()
{
    post_order_recursive(root);
}

template <class T>
bool binary_search_tree<T>::search_recursive(T data)
{
    return search_recursive(root, data);
}

template <class T>
node<T> *binary_search_tree<T>::min_node()
{
    return min_node(root);
}

template <class T>
node<T> *binary_search_tree<T>::max_node()
{
    return max_node(root);
}

template <class T>
void binary_search_tree<T>::delete_node(T data)
{
    delete_node(root, data);
}

template <class T>
void binary_search_tree<T>::delete_tree()
{
    delete_tree(root);
}

template <class T>
binary_search_tree<T>::~binary_search_tree()
{
    delete_tree();
}
