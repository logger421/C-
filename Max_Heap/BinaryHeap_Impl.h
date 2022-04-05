#include "BinaryHeap.h"

template <typename T>
T BinaryHeap<T>::getRoot() {
    if (!isEmpty())
        return vec[1];
    else {
        std::cerr << "Heap is Empty you can't get root element!\n";
        std::abort();
    }
}

template < typename T >
bool BinaryHeap<T>::isEmpty() const{
    return (bool) (size == 0);
}

template < typename T >
void BinaryHeap<T>::print() {
    std::cout << "HEAP:\n";
     for(int i = 1; i <= size; i++) {
         std::cout << vec[i] << " ";
     }
     std::cout << std::endl;
}

template < typename T >
T BinaryHeap<T>::RemoveRoot() {
    T max = vec[1];
    std::swap(vec[1], vec[size]);
    size--;
    shiftDown(1);
    return max;
}

template < typename T >
void BinaryHeap<T>::insert( T x ){
    if(size + 1 >= (int)vec.size()) {
        vec.push_back(0);
    }
    ++size;
    vec.at(size) = x;
    shiftUp(size);
    return;
}


/* ideksy wezlow (przykladowe itd):
            1
        2       3
    4      5 6      7
   8 9
*/

// METODY PRYWATNE

// (int) 9/2 = 4. 7/2 = 3, ok
template < typename T >
int BinaryHeap<T>::P(int i) {
    return i>>1;
}

// 1*2 + 1 = 3, 2*2+1 = 5, ok
template < typename T >
int BinaryHeap<T>::R(int i) {
    return (i<<1) + 1;
}

// 1*2 = 2, 2*2 = 4, 3*2 = 6, ok
template < typename T >
int BinaryHeap<T>::L(int i) {
    return i<<1;
}

        // metody kopcowania

template < typename T >
void BinaryHeap<T>::shiftDown( int i ) {
    if( i > size ) 
        return;
    int temp = i;
    if( (L(i) <= size) && (vec[i] < vec[L(i)]) )
        temp = L(i);
    if( (R(i) <= size) && (vec[temp] < vec[R(i)]) )
        temp = R(i);
    if( temp != i ) {
        std::swap( vec[i], vec[temp] );
        shiftDown(temp);
    }
}

template < typename T >
void BinaryHeap<T>::shiftUp( int i ) {
    if( i == 1 )
        return;
    if( i > size )
        return;
    if( vec[P(i)] < vec[i] )
        std::swap(vec[P(i)], vec[i]);
    shiftUp(P(i));
}