#ifndef AIZO_SHELLSORT_H
#define AIZO_SHELLSORT_H

#include "Sort.h"

class ShellSort : public Sort {
private:
    int pow(int a, int b);
public:
    ShellSort();
    ~ShellSort();
    void sort(int *tab, int tabSize, int space);
};

#endif