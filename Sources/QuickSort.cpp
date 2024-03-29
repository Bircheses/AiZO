#include <cstdlib>
#include <ctime>
#include "QuickSort.h"

QuickSort::QuickSort(int *tab, int tabSize, int pivot) {
    Sort::setTabSize(tabSize);
    Sort::setTabCopy(tab);
    this->pivot = pivot;
}

QuickSort::~QuickSort() {
    Sort::deleteTab();
}

void QuickSort::sort() {
    qsort(Sort::getTabCopy(), 0, Sort::getTabSize()-1);
}

void QuickSort::qsort(int *tab, int l, int r) {
    if (l >= r) return;
    int m = partition(tab, l, r);
    qsort(tab, l, m);
    qsort(tab, m + 1, r);
}

int QuickSort::partition(int *tab, int left, int right) const{
    int p = getPivot(tab, left, right);
    int l = left, r = right;
    while (true) {
        while (tab[l] < p) ++l;
        while (tab[r] > p) --r;
        if (l < r) {
            int pom = tab[l];
            tab[l] = tab[r];
            tab[r] = pom;
            ++l;
            --r;
        } else {
            if (r == right) r--;
            return r;
        }
    }
}

int QuickSort::getPivot(int *tab, int left, int right) const {
    switch (pivot) {
        case 1: { //lewy
            return tab[left];
            break;
        }
        case 2: { //środkowy
            return tab[(right-left)/2+left];
            break;
        }
        case 3: { //prawy
            return tab[right];
            break;
        }
        case 4: { //losowy
            srand(time(NULL));
            return rand()%right+left;
            break;
        }
        default: {
            return tab[left];
            break;
        }
    }
}
