#include <bits/stdc++.h>
#include <chrono>
#include "heap.hpp"

std::vector <double> check2(const int &amount)
{
    std::vector <double> ans;
    heappy <int, int, 2> h;

    // Tworzenie kopca przez wstawianie
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < amount; i++) h.insert(i, i);
    std::chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start;
    ans.push_back(elapsed.count());

    // Usuwanie z wierzchołka kopca (10 próbek)
    start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 10; i++) auto x = h.pop();
    elapsed = std::chrono::high_resolution_clock::now() - start;
    ans.push_back(elapsed.count()/10);

    return ans;
}

std::vector <double> check5(const int &amount)
{
    std::vector <double> ans;
    heappy <int, int, 5> h;

    // Tworzenie kopca przez wstawianie
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < amount; i++) h.insert(i, i);
    std::chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start;
    ans.push_back(elapsed.count());

    // Usuwanie z wierzchołka kopca (10 próbek)
    start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 10; i++) auto x = h.pop();
    elapsed = std::chrono::high_resolution_clock::now() - start;
    ans.push_back(elapsed.count()/10);

    return ans;
}

int main()
{
    std::ofstream out;
    out.open("standard_heap.csv");
    out << "Amount, 2-Heap Insert, 2-Heap Pop, 5-Heap Insert, 5-Heap Pop\n";
    int amounts[] = {10, 25, 100, 500, 1000, 2500, 5000, 10000, 25000, 50000, 75000, 100000, 125000, 150000, 200000, 250000};
    for(int i = 0; i < 16; i++)
    {
        std:: cout << "Terminating: " << amounts[i] <<std::endl;
        out << amounts[i];
        std::vector <double> ans = check2(amounts[i]);
        for(int x = 0; x < ans.size(); x++) out << ", " << ans[x];
        ans = check5(amounts[i]);
        for(int x = 0; x < ans.size(); x++) out << ", " << ans[x];
        out << '\n';
    }
    out.close();
}