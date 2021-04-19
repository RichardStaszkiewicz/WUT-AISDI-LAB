#include <bits/stdc++.h>
#include <chrono>
#include "AVL.hpp"
#include "BST.hpp"


// record start = std::chrono::high_resolution_clock::now();
// auto finish = std::chrono::high_resolution_clock::now();
// std::chrono::duration<double> elapsed = finish - start;
// std::cout << "Elapsed time: " << elapsed.count() << " s\n";
std::vector <double> count_random(int amount, int sample)
{
    std::vector <double> answer;
    double cumulative_insert = 0;
    double cumulative_find = 0;
    for(int x = 0; x < sample; x++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        BST_node root{rand()};
        for(int i = 1; i < amount; i++) root.add_value(rand());
        std::chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start;
        cumulative_insert += elapsed.count();
        for(int i = 0; i < 3; i++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            bool temp = root.find_value(rand());
            std::chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start;
            cumulative_find += elapsed.count();
        }
    }
    answer.push_back(cumulative_insert/sample);
    answer.push_back(cumulative_find/(3 * sample));
    cumulative_insert = 0;
    cumulative_find = 0;
    for(int x = 0; x < sample; x++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        TreeNode *root = NULL;
        for(int i = 0; i < amount; i++) root = add_value(root, rand());
        std::chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start;
        cumulative_insert += elapsed.count();
        for(int i = 0; i < 3; i++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            bool temp = find(root, rand());
            std::chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start;
            cumulative_find += elapsed.count();
        }
    }
    answer.push_back(cumulative_insert/sample);
    answer.push_back(cumulative_find/(3 * sample));
    return answer;
}


std::vector <double> count_sorted(int amount, int sample)
{
    std::vector <double> answer;
    double cumulative_insert = 0;
    double cumulative_find = 0;
    for(int x = 0; x < sample; x++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        BST_node root{0};
        for(int i = 1; i < amount; i++) root.add_value(i);
        std::chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start;
        cumulative_insert += elapsed.count();
        for(int i = 0; i < 3; i++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            bool temp = root.find_value(rand());
            std::chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start;
            cumulative_find += elapsed.count();
        }
    }
    answer.push_back(cumulative_insert/sample);
    answer.push_back(cumulative_find/(3 * sample));
    cumulative_insert = 0;
    cumulative_find = 0;
    for(int x = 0; x < sample; x++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        TreeNode *root = NULL;
        for(int i = 0; i < amount; i++) root = add_value(root, i);
        std::chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start;
        cumulative_insert += elapsed.count();
        for(int i = 0; i < 3; i++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            bool temp = find(root, rand());
            std::chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start;
            cumulative_find += elapsed.count();
        }
    }
    answer.push_back(cumulative_insert/sample);
    answer.push_back(cumulative_find/(3 * sample));
    return answer;
}


int main()
{
    std::ofstream random;
    random.open("random.csv");
    random << "Amount; BST_insert; BST_find; AVL_insert; AVL_find\n";
    int amounts[] = {10, 25, 100, 500, 1000, 2500, 5000, 10000, 25000, 50000, 75000, 100000};
    for(int i = 0; i < 12; i++)
    {
        std::vector <double> random_data = count_random(amounts[i], 3);
        random << amounts[i];
        for(int i = 0; i < random_data.size(); i++) random << "; " << random_data[i];
        random << '\n';
    }
    random.close();
    std::ofstream sorted;
    sorted.open("sorted.csv");
    sorted << "Amount; BST_insert; BST_find; AVL_insert; AVL_find\n";
    for(int i = 0; i < 12; i++)
    {
        std::vector <double> sorted_data = count_sorted(amounts[i], 3);
        sorted << amounts[i];
        for(int i = 0; i < sorted_data.size(); i++) sorted << "; " << sorted_data[i];
        sorted << '\n';
    }
    sorted.close();
    return 0;
}