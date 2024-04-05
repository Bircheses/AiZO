#include <cstdlib>
#include <ctime>
#include <iostream>
#include "QuickSort.h"

template<typename T>
QuickSort<T>::QuickSort(T *tab, int tabSize, int pivot){
    Sort<T>::setTabSize(tabSize);
    Sort<T>::setTabCopy(tab);
    this->pivot = pivot;
}

template<typename T>
QuickSort<T>::~QuickSort() {
    Sort<T>::deleteTab();
}

template<typename T>
void QuickSort<T>::sort() {
    quicksort(Sort<T>::getTabCopy(), 0, Sort<T>::getTabSize()-1);
}

template<typename T>
int QuickSort<T>::getPivotIndex(int left, int right) const {
    if(pivot==1) return left;
    else if(pivot==2) return (right-left)/2+left;
    else if(pivot==3) return right;
    else if(pivot==4){
        srand(time(NULL));
        return rand()%(right-left)+left;
    }
}

template<typename T>
void QuickSort<T>::quicksort(T *tab, int left, int right) {
    if (left < right) {
        int m = partition(tab, left, right);
        quicksort(tab, left, m - 1);
        quicksort(tab, m + 1, right);
    }
}

template<typename T>
int QuickSort<T>::partition(T *tab, int left, int right) {
    int pivotIndex = getPivotIndex(left, right);
    T p = tab[pivotIndex], temp = tab[right];
    tab[right] = tab[pivotIndex];
    tab[pivotIndex] = temp;
    int i = left - 1, j = left;
    while(j<right){
        if(tab[j]<p) {
            i++;
            Sort<T>::swap(&tab[i], &tab[j]);
        }
        j++;
    }
    i++;
    Sort<T>::swap(&tab[i],&tab[right]);
    return i;
}

template class QuickSort<int>;
template class QuickSort<float>;