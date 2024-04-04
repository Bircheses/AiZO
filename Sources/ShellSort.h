#ifndef AIZO_SHELLSORT_H
#define AIZO_SHELLSORT_H

#include "Sort.h"

class ShellSort : public Sort {
private:
    const int arr[10] = {1,8,23,77,281,1073,4193,16657,65921,262913};
    int k=9;
public:
    ShellSort(int *tab, int tabSize);
    ~ShellSort();
    void shellalgsort();
    void sedgewickalgsort();
};

#endif