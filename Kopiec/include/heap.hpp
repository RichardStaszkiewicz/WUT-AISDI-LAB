#include <vector>
#define HEAP


class heappy
{
    private:
        std::vector <double> heap;
        int cpx = 2;
        void sinking(const int &idx);
        void floating(const int &idx);
    public:
        heappy() = default;
        heappy(const int &cp);
        void insert(const double &val);
        double pop();
        void print();
};