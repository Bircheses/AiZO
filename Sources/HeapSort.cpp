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
void HeapSort<T>::fixHeapDown(T *tabCopy, int i, int tabSize){
    if (2*i+2 >= tabSize && tabCopy[2*i+1] > tabCopy[i]){
        Sort<T>::swap(&tabCopy[i], &tabCopy[2 * i + 1]);
        if (2 * i + 1 <= (tabSize - 2) / 2) fixHeapDown(tabCopy, 2 * i + 1, tabSize); //Sprawdzenie czy prawy potomek jest rodzicem
    }else if (tabCopy[2 * i + 1] >= tabCopy[2 * i + 2]) {  //Porównanie dwóch potomków
            if (tabCopy[2 * i + 1] > tabCopy[i]) {  //Porównanie lewego potomka z rodzicem
                Sort<T>::swap(&tabCopy[i], &tabCopy[2 * i + 1]);
                if (2 * i + 1 <= (tabSize - 2) / 2) fixHeapDown(tabCopy, 2 * i + 1, tabSize); //Sprawdzenie czy prawy potomek jest rodzicem
            }
    } else {
            if (tabCopy[2 * i + 2] > tabCopy[i] && 2 * i + 2 < tabSize) { //Porównanie prawego potomka z rodzicem oraz sprawdzenie czy prawy potomek nie jest już posortowany
                Sort<T>::swap(&tabCopy[i], &tabCopy[2 * i + 2]);
                if (2 * i + 2 <= (tabSize - 2) / 2) fixHeapDown(tabCopy, 2 * i + 2, tabSize); //Sprawdzenie czy lewy potomek jest rodzicem
            }
    }
}

template class HeapSort<int>;
template class HeapSort<float>;