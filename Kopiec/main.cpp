#include <bits/stdc++.h>
#include "heap.hpp"

int main()
{
    heappy test(4);
    test.insert(1);
    test.insert(2);
    test.insert(3);
    test.insert(-1);
    test.insert(-2);
    test.insert(2);
    test.print();
    std::cout << std::endl <<test.pop() << std::endl;
    test.print();
    std::cout << std::endl <<test.pop() << std::endl;
    test.print();
    std::cout << std::endl <<test.pop() << std::endl;
    test.print();
    // std::cout << test.pop() << std::endl;
}