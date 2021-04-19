#include <iostream>

using namespace std;

class TreeNode
{
    public:
        double value;
        TreeNode *left_son;
        TreeNode *right_son;
        int step;
};

int step(TreeNode *node)
{
    if(node == NULL)
    {
        return 0;
    }
    return node->step;
}

int balance(TreeNode *node)
{
    if(node == NULL)
    {
        return 0;
    }
    return step(node->left_son) - step(node->right_son);
}

TreeNode* next_node(double new_value)
{
    TreeNode* new_node = new TreeNode();
    new_node->value = new_value;
    new_node->left_son = nullptr;
    new_node->right_son = nullptr;
    new_node->step = 1;
    return new_node;
}

TreeNode *right_rotate(TreeNode *place)
{
    TreeNode *place2 = place->left_son;
    TreeNode *place3 = place2->right_son;

    place2->right_son = place;
    place->left_son = place3;

    int max_value = 1 + max(step(place->left_son), step(place->right_son));
    place->step = max_value;
    max_value = 1 + max(step(place2->left_son), step(place2->right_son));
    place2->step = max_value;

    return place2;
}

TreeNode *left_rotate(TreeNode *place)
{
    TreeNode *place2 = place->right_son;
    TreeNode *place3 = place2->left_son;

    place2->left_son = place;
    place->right_son = place3;

    int max_value = 1 + max(step(place->left_son), step(place->right_son));
    place->step = max_value;
    max_value = 1 + max(step(place2->left_son), step(place2->right_son));
    place2->step = max_value;

    return place2;
}

TreeNode *add_value(TreeNode *node, double value)
{
    if(node == NULL)
    {
        return next_node(value);
    }
    if(value > node->value)
    {
        node->right_son = add_value(node->right_son, value);
    }
    else if(value < node->value)
    {
        node->left_son = add_value(node->left_son, value);
    }
    else
    {
        return node;
    }
    node->step = 1 + max(step(node->right_son), step(node->left_son));

    int bal = balance(node);
    if(bal > 1 && value < node->left_son->value)
    {
        return right_rotate(node);
    }
    if(bal < -1 && value > node->right_son->value)
    {
        return left_rotate(node);
    }
    if(bal > 1 && value > node->left_son->value)
    {
        node->left_son = left_rotate(node->left_son);
        return right_rotate(node);
    }
    if(bal < -1 && value < node->right_son->value)
    {
        node->right_son = right_rotate(node->right_son);
        return left_rotate(node);
    }
    return node;
}

bool find(TreeNode *node, double value)
{
    if(node->value == value)
    {
        return true;
    }
    if(node->value > value)
    {
        if(node->left_son == nullptr) 
        {
            return false;
        }
        else 
        {
            return find(node->left_son, value);
        }
    }
    else
    {
        if(node->right_son == nullptr)
        {
            return false;
        }
        else
        {
            return find(node->right_son, value);
        }
    }
}
void preOrder(TreeNode *root)
{
    if(root != NULL)
    {
        cout << root->value << " ";
        preOrder(root->left_son);
        preOrder(root->right_son);
    }
}
void print_AVL(TreeNode *node, int depth)
{
    if(node->left_son != nullptr)
    {
        print_AVL(node->left_son, depth+1);
    }
    for(int i = 0; i < depth * 2; i++)
    {
        cout<<" ";
    }
    cout<<node->value<<endl;
    if(node->right_son != nullptr)
    {
        print_AVL(node->right_son, depth+1);
    }
    return;
}