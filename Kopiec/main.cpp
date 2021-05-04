#include <bits/stdc++.h>
#include "heap.hpp"

int main()
{
    heappy <> test;
    test.insert(1, 1.1);
    test.insert(2, 2.3);
    test.insert(3, 98.11);
    test.insert(-1, 7);
    test.insert(-2, -2);
    test.insert(2, 11.1102);
    test.print();
    std::cout << std::endl <<test.pop().first << std::endl;
    test.print();
    std::cout << std::endl <<test.pop().first << std::endl;
    test.print();
    std::cout << std::endl <<test.pop().first << std::endl;
    test.print();
    // std::cout << test.pop() << std::endl;
}