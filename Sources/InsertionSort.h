#ifndef AIZO_INSERTIONSORT_H
#define AIZO_INSERTIONSORT_H

#include "Sort.h"

class InsertionSort : public Sort{
public:
    InsertionSort(int *tab, int tabSize);
    ~InsertionSort();
    void sort();
};

#endif