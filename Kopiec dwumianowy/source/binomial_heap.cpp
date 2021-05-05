#include <bits/stdc++.h>
#include "binomial_heap.hpp"

using namespace std;

// btree_Node::~btree_Node()
// {
//     if(son != nullptr) delete this->son;
//     if(sibling != nullptr) delete this->sibling;
//     delete sibling;
//     delete son;
//     delete parent;
// }

int btree_Node::get_degree() // zwraca stopien
{
    return degree;
}
double btree_Node::get_value() // zwraca wartosc
{
    return value;
}
btree_Node::btree_Node(double value_in, btree_Node *p) // konstruktor ustawia ojca, synow i braci oraz wartosc
{
    parent = p;
    son = nullptr;
    sibling = nullptr;
    value = value_in;
    degree = 0;
}
void btree_Node::add_son(btree_Node *node) // dodaj syna to wierchołka
{
    if(node)
    {
        node->sibling = nullptr;
        if(son)
        {
            btree_Node *actual = son;
            while(actual->sibling)
            {
                actual = actual->sibling;
            }
            actual->sibling = node;
        }
        else
        {
            son = node;
        }
        degree++;
        node->parent = this;
    }

}
bheap::bheap() // konstruktor kopca
{
    head = 0;
}
int bheap::degree(btree_Node *node) // zwraca stopien
{
    if(!node)
    {
        return -1;
    }
    int index = 0;
    btree_Node *son = node->son;
    while(son)
    {
        son = son->sibling;
        index++;
    }
    return index;
}
btree_Node* bheap::merge(btree_Node *node1, btree_Node *node2) // laczy 2 wierzcholki
{
    btree_Node *heap = nullptr;
    if(node1 || node2) // jezeli istnieje ktorys z wierzcholkow
    {
        if(node1 && !node2) // sprawdzanie czy ktorys z nich nie jest pusty
        {
            heap = node1;
        }
        else if(!node1 && node2)
        {
            heap = node2;
        }
        else
        {
            btree_Node *actual = nullptr;
            btree_Node *next = nullptr;
            btree_Node *previous = nullptr;
            btree_Node *current = nullptr;
            if(node1->get_degree() >= node2->get_degree()) // sprawdzenie stopni wierzcholkow
            {
                heap = node2;
                next = node1;
            }
            else
            {
                heap = node1;
                next = node2;
            }
            current = heap;
            while(current && next && current != next) // laczenie 2 kopcow w 1 przez przypisanie wskaznikow rodzenstwa
            {
                if(current->get_degree() <= next->get_degree())
                {
                    if(current->sibling)
                    {
                        actual = current->sibling;
                        current->sibling = next;
                        previous = current;
                        current = next;
                        next = actual;
                    }
                    else
                    {
                        current->sibling = next;
                        current = next;
                    }
                }
                else
                {
                    if(previous)
                    {
                        previous->sibling = next;
                    }
                    else
                    {
                        heap = next;
                    }
                    actual = next->sibling;
                    next->sibling = current;
                    previous = next;
                    next = actual;
                }
            }
        }
    }
    return heap;
}
btree_Node* bheap::unionheap(btree_Node *node1, btree_Node *node2) // laczy kopce tego samego rzedu, aby byl conajwyzej jeden
{
    btree_Node *heap = merge(node1, node2);
    if(heap)
    {
        btree_Node *actual = heap;
        btree_Node *previous = nullptr;
        btree_Node *next = nullptr;
        int degree1, degree2;
        while(actual && actual->sibling)
        {
            next = actual->sibling;
            degree1 = actual->get_degree();
            degree2 = next->get_degree();
            if(degree1 == degree2 && degree1 != degree(next->sibling))
            {
                if(actual->get_value() < next->get_value())
                {
                    actual->sibling = next->sibling;
                    actual->add_son(next);
                    previous = actual;
                    actual = actual->sibling;
                }
                else
                {
                    if(previous)
                    {
                        previous->sibling = next;
                    }
                    else
                    {
                        heap = next;
                    }
                    next->add_son(actual);
                    previous = next;
                    actual = next->sibling;
                }
            }
            else
            {
                if(!previous)
                {
                    heap = actual;
                }
                previous = actual;
                actual = next;
            }
        }
    }
    return heap;
}
void bheap::insert(double value) // dodawanie wartosci
{
    btree_Node *p = head? head->parent: nullptr;
    btree_Node *add = new btree_Node(value, p); // tworzenie nowego wierzcholka
    head = unionheap(add, head); // laczenie z glownym kopcem
}
double bheap::pop() // usuwa i zwraca najmniejszy element w kopcu, laczy pozostale kopce
{
    btree_Node *previous = nullptr;
    btree_Node *min = nullptr;
    btree_Node *actual = nullptr;
    btree_Node *next = nullptr;
    double minimum;
    if(head)
    {
        btree_Node *min2 = nullptr;
        min = head;
        actual = head->sibling;
        previous = head;
        while(actual)
        {
            if(actual->get_value() < min->get_value())
            {
                min = actual;
                min2 = previous;
            }
            previous = previous->sibling;
            actual = actual->sibling;
        }
        if(min2)
        {
            min2->sibling=min->sibling;
        }
        else
        {
            head = min->sibling;
        }
        next = min->son;
        actual = next;
        while(actual)
        {
            actual->parent = min->parent;
            actual = actual->sibling;
        }
        min->sibling = nullptr;
        min->son = nullptr;
        min->parent = nullptr;
        minimum = min->get_value();
        delete min;
        head = unionheap(head, next);
        actual = min = min2 = next = nullptr;
    }
    else
    {
        return 0;
    }
    return minimum;
}

// int main()
// {
//     bheap heap;
//     heap.insert(10);
//     heap.insert(30);
//     heap.insert(80);
//     heap.insert(5);
//     heap.insert(1);
//     cout<<heap.pop()<<endl;
//     cout<<heap.pop()<<endl;
//     cout<<heap.pop()<<endl;
// }