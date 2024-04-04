#ifndef AIZO_HEAPSORT_H
#define AIZO_HEAPSORT_H

#include "Sort.h"

template<typename T>
class HeapSort : public Sort<T>{
public:
    HeapSort(T *tab, int tabSize);
    ~HeapSort();
    void sort();
private:
    void createHeap(T *tabCopy, int tabSize);
    void fixHeapDown(T *tabCopy, int i, int tabSize);
};

#endif