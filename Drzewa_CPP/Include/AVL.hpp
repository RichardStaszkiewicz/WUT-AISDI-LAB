// #ifdef

#define AVL

class TreeNode
{
    public:
        double value;
        TreeNode *left_son;
        TreeNode *right_son;
        int step;
};

int step(const TreeNode *node);
int balance(const TreeNode *node);
TreeNode* next_node(const double new_value);
TreeNode *right_rotate(TreeNode *place);
TreeNode *left_rotate(TreeNode *place);
TreeNode *add_value(TreeNode *node, const double &value);
bool find(const TreeNode *node, const double &value);
void preOrder(const TreeNode *root);
void print_AVL(const TreeNode *node, const int &depth);

// #endif