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

    void in_order_iterative();

    void pre_order_recursive(node<T> *);

    void pre_order_iterative();

    void post_order_recursive(node<T> *);

    void post_order_iterative();

    bool search_recursive(node<T> *, T);

    bool search_iterative(T);

    void delete_tree_recursive(node<T> *);

    void delete_tree_iterative();

    int find_max_value_recursive(node<T> *);

    int find_max_value_iterative();

    int find_min_value_recursive(node<T> *);

    int find_min_value_iterative();

    int max_depth(node<T> *);

    int min_depth(node<T> *);

    void mirror(node<T> *);

    int sum(node<T> *);

    void find_full_nodes(node<T> *);

    int height(node<T> *);

    int size(node<T> *);

    bool is_complete_tree(node<T> *, int, int);

    bool is_full_tree(node<T> *);
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
void binary_tree<T>::in_order_iterative()
{
    if (root == NULL)
        return;
    stack<node<T> *> s;
    node<T> *curr = root;
    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << ' ';
        curr = curr->right;
    }
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
void binary_tree<T>::pre_order_iterative()
{
    if (root == NULL)
        return;
    stack<node<T> *> stk;
    stk.push(root);
    while (!stk.empty())
    {
        node<T> *curr = stk.top();
        stk.pop();
        cout << curr->data << ' ';
        if (curr->right)
            stk.push(curr->right);
        if (curr->left)
            stk.push(curr->left);
    }
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
void binary_tree<T>::post_order_iterative()
{
    if (root == NULL)
        return;
    stack<node<T> *> stk, res;
    stk.push(root);
    while (!stk.empty())
    {
        node<T> *curr = stk.top();
        stk.pop();
        res.push(curr);
        if (curr->left)
            stk.push(curr->left);
        if (curr->right)
            stk.push(curr->right);
    }
    while (!res.empty())
    {
        cout << res.top()->data << ' ';
        res.pop();
    }
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
bool binary_tree<T>::search_iterative(T data)
{
    if (root == NULL)
        return false;
    stack<node<T> *> s;
    s.push(root);
    while (!s.empty())
    {
        node<T> *curr = s.top();
        s.pop();
        if (curr->data == data)
            return true;
        if (curr->right)
            s.push(curr->right);
        if (curr->left)
            s.push(curr->left);
    }
    return false;
}

template <class T>
void binary_tree<T>::delete_tree_recursive(node<T> *curr)
{
    if (curr == NULL)
        return;
    delete_tree_recursive(curr->left);
    delete_tree_recursive(curr->right);
    delete (curr);
}

template <class T>
void binary_tree<T>::delete_tree_iterative()
{
    if (root == NULL)
        return;
    stack<node<T> *> stk;
    stk.push(root);
    while (!stk.empty())
    {
        node<T> *curr = stk.top();
        stk.pop();
        if (curr->left)
            stk.push(curr->left);
        if (curr->right)
            stk.push(curr->right);
        delete (curr);
    }
}

template <class T>
int binary_tree<T>::find_max_value_recursive(node<T> *curr)
{
    if (curr == NULL)
        return INT_MIN;
    int res = curr->data;
    int left_res = find_max_value_recursive(curr->left);
    int right_res = find_max_value_recursive(curr->right);
    return max(res, max(left_res, right_res));
}

template <class T>
int binary_tree<T>::find_max_value_iterative()
{
    int res = INT_MIN;
    if (root == NULL)
        return res;
    stack<node<T> *> stk;
    node<T> *curr = root;
    stk.push(root);
    while (!stk.empty())
    {
        node<T> *curr = stk.top();
        res = max(res, curr->data);
        stk.pop();
        if (curr->left)
            stk.push(curr->left);
        if (curr->right)
            stk.push(curr->right);
    }
    return res;
}

template <class T>
int binary_tree<T>::find_min_value_recursive(node<T> *curr)
{
    if (curr == NULL)
        return INT_MAX;
    int res = curr->data;
    int left_res = find_min_value_recursive(curr->left);
    int right_res = find_min_value_recursive(curr->right);
    return min(res, min(left_res, right_res));
}

template <class T>
int binary_tree<T>::find_min_value_iterative()
{
    int res = INT_MAX;
    if (root == NULL)
        return res;
    stack<node<T> *> stk;
    node<T> *curr = root;
    stk.push(root);
    while (!stk.empty())
    {
        node<T> *curr = stk.top();
        res = min(res, curr->data);
        stk.pop();
        if (curr->left)
            stk.push(curr->left);
        if (curr->right)
            stk.push(curr->right);
    }
    return res;
}

template <class T>
int binary_tree<T>::max_depth(node<T> *curr)
{
    if (curr == NULL)
        return 0;
    int left_depth = max_depth(curr->left);
    int right_depth = max_depth(curr->right);
    return 1 + max(left_depth, right_depth);
}

template <class T>
int binary_tree<T>::min_depth(node<T> *curr)
{
    if (curr == NULL)
        return 0;
    int left_depth = min_depth(curr->left);
    int right_depth = min_depth(curr->right);
    return 1 + min(left_depth, right_depth);
}

template <class T>
void binary_tree<T>::mirror(node<T> *curr)
{
    if (curr == NULL)
        return;
    mirror(curr->left);
    mirror(curr->right);
    node<T> *temp = curr->left;
    curr->left = curr->right;
    curr->right = temp;
}

template <class T>
int binary_tree<T>::sum(node<T> *curr)
{
    if (curr == NULL)
        return 0;
    int left_sum = sum(curr->left);
    int right_sum = sum(curr->right);
    return left_sum + curr->data + right_sum;
}

template <class T>
void binary_tree<T>::find_full_nodes(node<T> *curr)
{
    if (curr == NULL)
        return;
    find_full_nodes(curr->left);
    if (curr->left != NULL && curr->right != NULL)
        cout << curr->data << " ";
    find_full_nodes(curr->right);
}

template <class T>
int binary_tree<T>::height(node<T> *curr)
{
    if (curr == NULL)
        return 0;
    int left_height = height(curr->left);
    int right_height = height(curr->right);
    return 1 + max(left_height, right_height);
}

template <class T>
int binary_tree<T>::size(node<T> *curr)
{
    if (curr == NULL)
        return 0;
    int left_size = size(curr->left);
    int right_size = size(curr->right);
    return left_size + 1 + right_size;
}

template <class T>
bool binary_tree<T>::is_complete_tree(node<T> *curr, int index, int tree_size)
{
    if (curr == NULL)
        return true;
    if (index >= tree_size)
        return false;
    bool left_subtree = is_complete_tree(curr->left, 2 * index + 1, tree_size);
    bool right_subtree = is_complete_tree(curr->right, 2 * index + 2, tree_size);
    return left_subtree && right_subtree;
}

template <class T>
bool binary_tree<T>::is_full_tree(node<T> *curr)
{
    if (curr == NULL)
        return true;
    if (curr->left == NULL && curr->right == NULL)
        return true;
    if (curr->left != NULL && curr->right != NULL)
        return is_full_tree(curr->left) && is_full_tree(curr->right);
    return false;
}

//