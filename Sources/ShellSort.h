#ifndef AIZO_SHELLSORT_H
#define AIZO_SHELLSORT_H

#include "Sort.h"

class ShellSort : public Sort {
public:
    ShellSort();
    ~ShellSort();
    void sort(int *tab, int tabSize, int algorithm_choice);
    void shell(int *tab, int tabSize);
    void sedgewick(int *tab, int tabSize);
};

#endif