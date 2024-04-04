#ifndef AIZO_HEAPSORT_H
#define AIZO_HEAPSORT_H

#include "Sort.h"

class HeapSort : public Sort{
public:
    HeapSort(int *tab, int tabSize);
    ~HeapSort();
    void sort();
private:
    void createHeap(int *tabCopy, int tabSize);
    void fixHeapDown(int *tabCopy, int i, int tabSize);
};

#endif