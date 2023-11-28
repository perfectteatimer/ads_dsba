#ifndef HEAP_H
#define HEAP_H

#include <vector>

template <typename T>
class Heap
{

private:
    /* vector to contain N heap's nodes */
    std::vector<T> v;

    /* heapifies the heap starting from node in position #i; O(N) */
    void heapify(int i);

public:
    /* constructor, calls heapify */
    Heap(const std::vector<T>& v);

    /* returns the number of elements in the heap */
    int size();

    /* checks whether the heap is empty */
    bool empty();

    /* pushes in the heap a T-element with value x; O(log N) */
    // [optional] void push(const T& x);

    /* pops out the root element of the heap; O(log N) */ 
    T pop();
};

/* sorts any vector v of T-elements by using a heap */
template <typename T>
void heapsort(std::vector<T>& v)
{
    // Your code here...
}

template <typename T>
int Heap<T>::size()
{
    return v.size();
}

// Write the implementation of the template class methods here...


#endif