#include <cstdlib>
#include <ctime>
#include "QuickSort.h"

QuickSort::QuickSort() = default;

QuickSort::~QuickSort() {
    Sort::deleteTab();
}

void QuickSort::sort(int *tab, int tabSize, int pivot) {
    Sort::setTabSize(tabSize);
    Sort::setTabCopy(tab);
    this->pivot = pivot;
    qsort(Sort::getTabCopy(), 0, Sort::getTabSize()-1);
}

void QuickSort::qsort(int *tab, int l, int r) {
    if (l >= r) return;
    int m = partition(tab, l, r);
    qsort(tab, l, m);
    qsort(tab, m + 1, r);
}

int QuickSort::partition(int *tab, int left, int right) {
    int p = getPivot(tab, left, right);
    int l = left, r = right;
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
    }
}

int QuickSort::getPivot(int *tab, int left, int right) const {
    switch (pivot) {
        case 1: { //lewy
            return tab[left];
        }
        case 2: { //środkowy
            return tab[(right-left)/2+left];
        }
        case 3: { //prawy
            return tab[right];
        }
        case 4: { //losowy
            srand(time(NULL));
            return tab[rand()%(right-left)+left];
        }
        default: {
            return tab[left];
        }
    }
}
