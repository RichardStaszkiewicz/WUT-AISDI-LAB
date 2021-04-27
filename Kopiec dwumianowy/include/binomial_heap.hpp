#define BINOMIAL

#include <vector>
#include <memory>

class bheap
{
    private:
        class btree_Node
        {
            private:
                std::vector <btree_Node *> sons;
            public:
                double value;
        };
        std::vector <btree_Node *> heap;
        void meld();
    public:
        void insert(const double &val);
        double pop();
};
