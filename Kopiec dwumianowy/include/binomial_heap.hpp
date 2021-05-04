#define BINOMIAL

#include <vector>
#include <memory>

class btree_Node
{
    private:
    int degree;
    double value;
    public:
    btree_Node *parent;
    btree_Node *son;
    btree_Node *sibling;
    btree_Node(double value_in, btree_Node *p);
    void add_son(btree_Node *node);
    int get_degree();
    double get_value();
};

class bheap
{
    private:
        btree_Node *head;
        btree_Node* merge(btree_Node *node1, btree_Node *node2);
        btree_Node* unionheap(btree_Node *node1, btree_Node *node2);
    public:
        bheap();
        void insert(double val);
        int degree(btree_Node *node);
        double pop();
};