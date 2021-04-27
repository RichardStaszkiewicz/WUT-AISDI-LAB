#include <algorithm>
#include <iostream>
#include <vector>
#include "heap.hpp"


heappy::heappy(const int &cp)
{
    heap = std::vector <double>{};
    cpx = cp;
    return;
}


void heappy::sinking(const int &idx)
{
    int min_adress = -1;
    double min_val = heap[idx];
    for(int offset = 1; offset <= cpx; offset++)
    {
        if(heap.size() <= cpx * idx + offset) break;
        if(heap[cpx * idx + offset] < min_val)
        {
            min_val = heap[cpx * idx + offset];
            min_adress = cpx * idx + offset;
        }
    }
    if(min_adress == -1) return;
    else
    {
            std::swap(heap[min_adress], heap[idx]);
            sinking(min_adress);
            return;
    }
}


void heappy::floating(const int &idx)
{
    if(idx == 0) return;
    if(heap[idx] < heap[int((idx - 1) / cpx)])
    {
        std::swap(heap[idx], heap[int((idx - 1) / cpx)]);
        floating(int((idx - 1) / cpx));
    }
    return;
}


void heappy::insert(const double &val)
{
    heap.push_back(val);
    floating(heap.size() - 1);
    return;
}


double heappy::pop()
{
    double min = heap[0];
    std::swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    sinking(0);
    return min;
}

void heappy::print()
{
    for(int i = 0; i < heap.size(); i++)
        std::cout << heap[i] << " ";
    return;
}
