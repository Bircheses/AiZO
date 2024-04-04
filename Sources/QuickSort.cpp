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
void QuickSort<T>::quicksort(T *tab, int l, int r) {
    if(l<r) {
        int m = partition(tab, l, r);
        quicksort(tab, l, m - 1);
        quicksort(tab, m + 1, r);
    }
}

template<typename T>
int QuickSort<T>::partition(T *tab, int left, int right) {
    int p = getPivot(tab, left, right);
    int i = left-1;
    for(int j=left; j<=right; j++){
        if(tab[j]<p){
            i++;
            swap(&tab[i],&tab[j]);
        }
    }
    swap(&tab[i+1],&tab[right]);
    return i+1;
    /*int l = left, r = right;
    while (true) {
        while (tab[l] < p) ++l;
        while (tab[r] > p) --r;
        if (l < r) {
            Sort::swap(&tab[r], &tab[l]);
            ++l;
            --r;
        } else {
            if (r == right) r--;
            return r;
        }
    }*/
}

template<typename T>
int QuickSort<T>::getPivot(T *tab, int left, int right) const {
    if(pivot==1) return tab[left];
    else if(pivot==2) return tab[(right-left)/2+left];
    else if(pivot==3) return tab[right];
    else if(pivot==4){
        srand(time(NULL));
        return tab[rand()%(right-left)+left];
    }
}
