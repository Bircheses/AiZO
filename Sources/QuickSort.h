#ifndef AIZO_QUICKSORT_H
#define AIZO_QUICKSORT_H

#include "Sort.h"

/**
 * pivot: 1-left, 2-middle, 3-right, 4-random
 */
template<typename T>
class QuickSort : public Sort<T>{
private:
    int pivot;
    void quicksort(T *tab, int left, int right);
    int partition(T *tab, int left, int right);
    int getPivotIndex(T *tab, int left, int right) const;
public:
    QuickSort(T *tab, int tabSize, int pivot);
    ~QuickSort();
    void sort();
};


#endif