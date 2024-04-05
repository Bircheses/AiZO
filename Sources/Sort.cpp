#include "Sort.h"
#include <iostream>

template<typename T>
bool Sort<T>::isSortCorrect() {
    for(int i=0; i<tabSize-1; i++){
        if(tabCopy[i]>tabCopy[i+1]){
            return false;
        }
    }
    return true;
}

template<typename T>
void Sort<T>::printTab() {
    for(int i=0; i<tabSize; i++){
        std::cout << tabCopy[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void Sort<T>::deleteTab() {
    delete [] tabCopy;
}

template<typename T>
T* Sort<T>::getTabCopy() {
    return tabCopy;
}

template<typename T>
void Sort<T>::setTabCopy(const T *tab) {
    delete [] tabCopy;
    tabCopy = new T[tabSize];
    for(int i=0; i < tabSize; i++){
        tabCopy[i] = tab[i];
    }
}

template<typename T>
int Sort<T>::getTabSize() const {
    return tabSize;
}

template<typename T>
void Sort<T>::setTabSize(int size) {
    Sort::tabSize = size;
}

template<typename T>
void Sort<T>::swap(T *a, T *b) {
    T pom = *b;
    *b = *a;
    *a = pom;
}

template class Sort<int>;
template class Sort<float>;