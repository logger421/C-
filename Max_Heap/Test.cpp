#include <iostream>
#include "BinaryHeap.h"
#include "BinaryHeap_Impl.h"

int main() {

    using std::cout;
    using std::endl;

    BinaryHeap<int> i_priorQueue;

    cout << "Czy pusty?: " << i_priorQueue.isEmpty() << endl;

    i_priorQueue.insert(50);
    cout << "Czy pusty?: " << i_priorQueue.isEmpty() << endl;
    cout << "ROOT:\t" << i_priorQueue.getRoot() << endl;
    
    i_priorQueue.insert(76);
    i_priorQueue.insert(100);
    i_priorQueue.insert(25);
    i_priorQueue.insert(125);
    i_priorQueue.insert(300);

    cout << "ROOT:\t" << i_priorQueue.getRoot() << endl;
    i_priorQueue.print();
    
    i_priorQueue.RemoveRoot();
    cout << "Czy pusty?: " << i_priorQueue.isEmpty() << endl;
    cout << "ROOT:\t" << i_priorQueue.getRoot() << endl;
    i_priorQueue.print();

    i_priorQueue.RemoveRoot();
    i_priorQueue.RemoveRoot();
    i_priorQueue.RemoveRoot();
    cout << "Czy pusty?: " << i_priorQueue.isEmpty() << endl;
    cout << "ROOT:\t" << i_priorQueue.getRoot() << endl;
    i_priorQueue.print();



    BinaryHeap<double> d_priorQueue;

    d_priorQueue.insert(2.5);
    d_priorQueue.insert(1.5);
    d_priorQueue.insert(3.5);
    d_priorQueue.insert(1.25);
    d_priorQueue.insert(32.5);
    d_priorQueue.insert(16);
    cout << "Czy pusty?: " << d_priorQueue.isEmpty() << endl;
    cout << "ROOT:\t" << d_priorQueue.getRoot() << endl;
    d_priorQueue.print();
    d_priorQueue.RemoveRoot();
    cout << "ROOT:\t" << d_priorQueue.getRoot() << endl;
    d_priorQueue.print();
    return 0;
}
