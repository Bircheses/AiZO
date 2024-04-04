#ifndef AIZO_INSERTIONSORT_H
#define AIZO_INSERTIONSORT_H

#include "Sort.h"

template<typename T>
class InsertionSort : public Sort<T>{
public:
    InsertionSort(T *tab, int tabSize);
    ~InsertionSort();
    void sort();
};

#endif