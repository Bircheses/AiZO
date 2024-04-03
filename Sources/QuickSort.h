#ifndef AIZO_QUICKSORT_H
#define AIZO_QUICKSORT_H

#include "Sort.h"

/**
 * pivot: 1-left, 2-middle, 3-right, 4-random
 */
class QuickSort : public Sort{
private:
    int pivot{};
    void qsort(int *tab, int l, int r);
    int partition(int *tab, int left, int right);
    int getPivot(int *tab, int left, int right) const;
public:
    QuickSort();
    ~QuickSort();
    void sort(int *tab, int tabSize, int pivot);
};


#endif