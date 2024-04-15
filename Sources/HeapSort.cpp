#include "HeapSort.h"

template<typename T>
HeapSort<T>::HeapSort(T *tab, int tabSize){
    Sort<T>::setTabSize(tabSize);
    Sort<T>::setTabCopy(tab);
}

template<typename T>
HeapSort<T>::~HeapSort() {
    Sort<T>::deleteTab();
}

template<typename T>
void HeapSort<T>::sort() {
    T *temp = Sort<T>::getTabCopy();
    HeapSort::createHeap(temp, Sort<T>::getTabSize());
    for(int i=1;i<Sort<T>::getTabSize();i++) {
        Sort<T>::swap(&temp[0], &temp[Sort<T>::getTabSize() - i]);
        fixHeapDown(temp, 0, Sort<T>::getTabSize() - i);
    }
    if(temp[0]>temp[1]) Sort<T>::swap(&temp[0], &temp[1]);
}

template<typename T>
void HeapSort<T>::createHeap(T *tabCopy, int tabSize) {
    for(int i=(tabSize-2)/2; i>=0; --i){
        fixHeapDown(tabCopy, i, tabSize);
    }
}

template<typename T>
void HeapSort<T>::fixHeapDown(T *tabCopy, int i, int tabSize) {
    if (tabCopy[2*i+1]>=tabCopy[2*i+2]) {
        if (tabCopy[2*i+1]>tabCopy[i]) {
            Sort<T>::swap(&tabCopy[i], &tabCopy[2*i+1]);
            if(2*i+1<=(tabSize-2)/2) fixHeapDown(tabCopy, 2*i+1, tabSize);
        }
    } else {
        if (tabCopy[2*i+2] > tabCopy[i] && 2*i+2 < tabSize) {
            Sort<T>::swap(&tabCopy[i], &tabCopy[2*i+2]);
            if(2*i+2<=(tabSize-2)/2) fixHeapDown(tabCopy, 2*i+2, tabSize);
        }
    }
}

template class HeapSort<int>;
template class HeapSort<float>;