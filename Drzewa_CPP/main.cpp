#include <iostream>
#include "AVL.hpp"
// #include "BST.hpp"

int main()
{
    // BST_node root{56};
    // root.add_value(32);
    // root.add_value(11);
    // root.add_value(45);
    // root.add_value(86);
    // root.add_value(56);
    // root.add_value(56);
    // root.print_as_root(0);
    // BST_node root2{12};
    // root2.add_value(19);
    // root2.add_value(-11);
    // root2.add_value(19);
    // root2.print_as_root(0);
    // if(!root.find_value(11)) std::cout << "Not in key values\n";
    // else std::cout << "Key in a tree";
    // if(!root.find_value(-13)) std::cout << "Not in key values\n";
    // else std::cout << "Key in a tree";
    TreeNode *root3 = NULL;
    root3 = add_value(root3, 10);
    root3 = add_value(root3, 271);
    root3 = add_value(root3, 2);
    root3 = add_value(root3, 21);
    root3 = add_value(root3, 18);
    print_AVL(root3, 0);


    return 0;
}