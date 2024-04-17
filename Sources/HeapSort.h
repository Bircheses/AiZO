#ifndef AIZO_HEAPSORT_H
#define AIZO_HEAPSORT_H

#include "Sort.h"
/**
 * Child class for Sort class that realizes heap sort
 * @tparam T - template for different types of variables
 */
template<typename T>
class HeapSort : public Sort<T>{
public:
    HeapSort(T *tab, int tabSize); //Constructor for HeapSort class
    ~HeapSort(); //Destructor for HeapSort class
    void sort(); //Function that sort array given in a constructor ascendingly
private:
    void createHeap(T *tabCopy, int tabSize); //Function that creates heap from given array
    void fixHeapDown(T *tabCopy, int i, int tabSize); //Function that restores heap going down
};

#endif