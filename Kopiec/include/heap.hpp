#include <algorithm>
#include <iostream>
#include <vector>
#define HEAP


template <typename KEY=double, typename DATA=double, const int CPX=2>
class heappy
{
    private:
        struct Node {KEY key; DATA val;};
        std::vector <Node> heap;
        int cpx = CPX;
        void sinking(const int &idx)
        {
            int min_adress = -1;
            double min_key = heap[idx].key;
            for(int offset = 1; offset <= cpx; offset++)
            {
                if(heap.size() <= cpx * idx + offset) break;
                if(heap[cpx * idx + offset].key < min_key)
                {
                    min_key = heap[cpx * idx + offset].key;
                    min_adress = cpx * idx + offset;
                }
            }
            if(min_adress == -1) return;

            std::swap(heap[min_adress], heap[idx]);
            sinking(min_adress);
            return;
        }
        void floating(const int &idx)
        {
            if(idx == 0) return;
            if(heap[idx].key < heap[int((idx - 1) / cpx)].key)
            {
                std::swap(heap[idx], heap[int((idx - 1) / cpx)]);
                floating(int((idx - 1) / cpx));
            }
            return;
        }
    public:
        heappy() = default;
        void insert(const KEY &key, const DATA &val)
        {
            heap.push_back(Node{key, val});
            floating(heap.size() - 1);
            return;
        }
        std::pair <KEY, DATA> pop()
        {
            Node min = heap[0];
            std::swap(heap[0], heap[heap.size() - 1]);
            heap.pop_back();
            sinking(0);
            return std::make_pair(min.key, min.val);
        }
        void print()
        {
            for(int i = 0; i < heap.size(); i++)
                std::cout << "[" << heap[i].key << ", " << heap[i].val << "] ";
            return;
        }
};
