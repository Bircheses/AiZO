#ifndef AIZO_SHELLSORT_H
#define AIZO_SHELLSORT_H

#include "Sort.h"
/**
 * Child class for Sort class that realizes shell's sort
 * @tparam T - template for different types of variables
 */
template<typename T>
class ShellSort : public Sort<T> {
private:
    const int arr[10] = {1,8,23,77,281,1073,4193,16657,65921,262913}; //array that hold values of Sedgewick's gap sequence
    int k=9; //variable that initialize first gap for Sedgewick's sequence
public:
    ShellSort(T *tab, int tabSize); //Constructor for ShellSort class
    ~ShellSort(); //Destructor for ShellSort class
    void shellalgsort(); //Function that sort array given in a constructor ascendingly using Shell's gap sequence
    void sedgewickalgsort(); //Function that sort array given in a constructor ascendingly using Sedgewick's gap sequence
};

#endif