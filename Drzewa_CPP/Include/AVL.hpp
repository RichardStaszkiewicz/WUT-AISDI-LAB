#ifdef AVL

#define AVL
#include <BST.hpp>

class AVL_tree : public BST::BST_tree
{
    public:
        AVL_node *root;
};

class AVL_node : public BST::BST_node
{
    public:
        AVL_node *parent;
        AVL_node *son_left;
        AVL_node *son_right;
        double node_value;
        int delta; // gdzie się przechyla
};

#endif