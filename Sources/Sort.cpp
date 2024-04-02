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

int *Sort::getTabCopy() {
    return tabCopy;
}

void Sort::setTabCopy(const int *tab) {
    delete [] tabCopy;
    tabCopy = new int[tabSize];
    for(int i=0; i < tabSize; i++){
        tabCopy[i] = tab[i];
    }
}

int Sort::getTabSize() const {
    return tabSize;
}

void Sort::setTabSize(int tabSize) {
    Sort::tabSize = tabSize;
}

void Sort::swap(int *a, int *b) {
    int pom = *b;
    *b = *a;
    *a = pom;
}
