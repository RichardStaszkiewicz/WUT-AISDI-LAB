// #ifdef BST

#define BST

class BST_node
{
    public:
        BST_node *parent;
        BST_node *son_right;
        BST_node *son_left;
        double node_value;
        BST_node(const double &value);
        void print_as_root(const int &depth);
        void add_value(const double& value);
        bool find_value(const double& value);
};


class BST_tree
{
    public:
        BST_node *root;
        int size;
        BST_tree();
};


// #endif