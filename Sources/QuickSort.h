#ifndef AIZO_QUICKSORT_H
#define AIZO_QUICKSORT_H

#include "Sort.h"
/**
 * Child class for Sort class that realizes quick sort
 * @tparam T - template for different types of variables
 */
template<typename T>
class QuickSort : public Sort<T>{
private:
    int pivot; //pivot: 1-left, 2-middle, 3-right, 4-random
    void quicksort(T *tab, int left, int right); //Recursive function that
    int partition(T *tab, int left, int right); //Partition function that divides given array into two smaller arrays,where elements are less than pivot and greater or equal than pivot, returns divide position
    [[nodiscard]] int getPivotIndex(int left, int right) const; //function that returns index of pivot, that depends on pivot param
public:
    QuickSort(T *tab, int tabSize, int pivot); //Constructor for HeapSort class
    ~QuickSort(); //Destructor for HeapSort class
    void sort(); //Function that sort array given in a constructor ascendingly
};


#endif