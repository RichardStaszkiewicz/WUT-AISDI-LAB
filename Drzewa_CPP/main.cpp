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
    return 0;
}