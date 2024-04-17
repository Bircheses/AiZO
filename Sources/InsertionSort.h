#ifndef AIZO_INSERTIONSORT_H
#define AIZO_INSERTIONSORT_H

#include "Sort.h"
/**
 * Child class for Sort class that realizes insertion sort
 * @tparam T - template for different types of variables
 */
template<typename T>
class InsertionSort : public Sort<T>{
public:
    InsertionSort(T *tab, int tabSize); //Constructor for HeapSort class
    ~InsertionSort(); //Destructor for HeapSort class
    void sort(); //Function that sort array given in a constructor ascendingly
};

#endif