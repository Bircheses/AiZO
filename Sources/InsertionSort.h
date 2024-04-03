#ifndef AIZO_INSERTIONSORT_H
#define AIZO_INSERTIONSORT_H

#include "Sort.h"

class InsertionSort : public Sort{
public:
    InsertionSort();
    ~InsertionSort();
    void sort(int *tab, int tabSize);
};

#endif