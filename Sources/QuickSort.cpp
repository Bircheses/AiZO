#include <cstdlib>
#include <ctime>
#include <iostream>
#include "QuickSort.h"

QuickSort::QuickSort(int *tab, int tabSize, int pivot){
    Sort::setTabSize(tabSize);
    Sort::setTabCopy(tab);
    this->pivot = pivot;
}

QuickSort::~QuickSort() {
    Sort::deleteTab();
}

void QuickSort::sort() {
    quicksort(Sort::getTabCopy(), 0, Sort::getTabSize()-1);
}

void QuickSort::quicksort(int *tab, int l, int r) {
    if(l<r) {
        int m = partition(tab, l, r);
        quicksort(tab, l, m - 1);
        quicksort(tab, m + 1, r);
    }
}

int QuickSort::partition(int *tab, int left, int right) {
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

int QuickSort::getPivot(int *tab, int left, int right) const {
    if(pivot==1) return tab[left];
    else if(pivot==2) return tab[(right-left)/2+left];
    else if(pivot==3) return tab[right];
    else if(pivot==4){
        srand(time(NULL));
        return tab[rand()%(right-left)+left];
    }
}
