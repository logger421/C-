#include <iostream>
#include <vector>

#pragma once

template <typename T>
class BinaryHeap
{
    // element 0 jest dowolny chcemy zaczynac od 1
    // dla przyjemniejszych operacji.
    std::vector<T> vec = {-1};
    int size;

    int P( int i );
    int R( int i );
    int L( int i );

    void shiftDown( int i );
    void shiftUp( int i );
public:
    BinaryHeap() : size(0) {}
    T getRoot();
    T RemoveRoot();
    bool isEmpty() const;
    void insert( T x );  
    void print();
};

