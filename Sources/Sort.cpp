#include "Sort.h"
#include <iostream>

void Sort::printTab() {
    for(int i=0; i<tabSize; i++){
        std::cout << tabCopy[i] << " ";
    }
    std::cout << std::endl;
}

void Sort::deleteTab() {
    delete [] tabCopy;
}

template <typename T>
T *Sort::getTabCopy() {
    return tabCopy;
}

template <typename T>
void Sort::setTabCopy(const T *tab) {
    delete [] tabCopy;
    tabCopy = new T[tabSize];
    for(int i=0; i < tabSize; i++){
        tabCopy[i] = tab[i];
    }
}

int Sort::getTabSize() const {
    return tabSize;
}

void Sort::setTabSize(int size) {
    Sort::tabSize = size;
}

template <typename T>
void Sort::swap(T *a, T *b) {
    T pom = *b;
    *b = *a;
    *a = pom;
}
