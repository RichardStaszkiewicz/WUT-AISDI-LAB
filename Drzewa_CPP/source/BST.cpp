#include <iostream>
#include "BST.hpp"

BST_node::BST_node(const double &value)
{
    node_value = value;
    son_left = nullptr;
    son_right = nullptr;
    parent = nullptr;
}

void BST_node::add_value(const double& value)
{
    if(node_value >= value)
    {
        if(son_left == nullptr)
        {
            BST_node *new_node = new BST_node{value};
            new_node->parent = this;
            son_left = new_node;
            return;
        }
        else son_left->add_value(value);
    }
    else
    {
        if(son_right == nullptr)
        {
            BST_node *new_node = new BST_node{value};
            new_node->parent = this;
            son_right = new_node;
            return;
        }
        else son_right->add_value(value);
    }
    return;
}

BST_node BST_node::find_value(const double& value)
{
    if(node_value == value)
        return *this;
    if(node_value > value)
    {
        if(son_left == nullptr) return BST_node(value);
        else return son_left->find_value(value);
    }
    else
    {
        if(son_right == nullptr) return BST_node(value);
        else return son_right->find_value(value);
    }
}

// graficzne, można drzewkiem jak w tree, ale później
void BST_node::print_as_root(const int &depth)
{
    if(son_left != nullptr)
        son_left->print_as_root(depth + 1);
    for(int i = 0; i < depth * 2; i++) std::cout << " ";
    std::cout << node_value << "\n";
    if(son_right != nullptr)
        son_right->print_as_root(depth + 1);
    return;
}
