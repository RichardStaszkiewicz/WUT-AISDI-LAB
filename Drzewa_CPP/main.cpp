#include <iostream>
#include "AVL.hpp"
#include "BST.hpp"

int main()
{
    BST_node root{56};
    root.add_value(32);
    root.add_value(11);
    root.add_value(45);
    root.add_value(86);
    root.print_as_root(0);
    BST_node result = root.find_value(11);
    if(result.parent == nullptr) std::cout << "Not in key values\n";
    else std::cout << "Parent is node with value: " << result.parent->node_value <<'\n';
    result = root.find_value(-13);
    if(result.parent == nullptr) std::cout << "Not in key values\n";
    else std::cout << "Parent is node with value: " << result.parent->node_value <<'\n';


    return 0;
}