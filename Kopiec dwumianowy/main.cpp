#include <bits/stdc++.h>
#include <chrono>
#include "binomial_heap.hpp"

int main()
{
    std::ofstream out;
    out.open("binomial_h.csv");
    out << "Amount, BHeap Insert, BHeap Pop, PQueue Insert, PQueue Pop\n";
    std::vector < std::vector <double> > ans;
    bheap BH;
    auto start = std::chrono::high_resolution_clock::now();
    double cumulative_pop = 0;

    for(int i = 1; i <= 1000000; i++)
    {
        if(i % 1000 == 0)
        {
            std::chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start;
            std::vector <double> a;
            a.push_back(i);
            a.push_back(elapsed.count() - cumulative_pop);
            auto startx = std::chrono::high_resolution_clock::now();
            for(int x = 0; x < 10; x++) auto z = BH.pop();
            std::chrono::duration<double> elapsedx = std::chrono::high_resolution_clock::now() - startx;
            cumulative_pop += elapsedx.count();
            a.push_back(elapsedx.count()/10);
            ans.push_back(a);
        }
        BH.insert(rand());
    }

    std::priority_queue <double> PQ;
    start = std::chrono::high_resolution_clock::now();
    cumulative_pop = 0;
    for(int i = 1; i <= 1000000; i++)
    {
        if(i % 1000 == 0)
        {
            std::chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start;
            ans[int((i - 1)/1000)].push_back(elapsed.count() - cumulative_pop);
            auto startx = std::chrono::high_resolution_clock::now();
            for(int x = 0; x < 10; x++) PQ.pop();
            std::chrono::duration<double> elapsedx = std::chrono::high_resolution_clock::now() - startx;
            cumulative_pop += elapsedx.count();
            ans[int((i - 1)/1000)].push_back(elapsedx.count()/10);
        }
        PQ.push(rand());
    }

    for(int i = 0; i < ans.size(); i++)
    {
        out << ans[i][0];
        for(int x = 1; x < ans[i].size(); x++) out << ", " << ans[i][x];
        out << '\n';
    }

    return 0;
}