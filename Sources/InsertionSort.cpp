#include "InsertionSort.h"

template<typename T>
InsertionSort<T>::InsertionSort(T *tab, int tabSize){
    Sort<T>::setTabSize(tabSize);
    Sort<T>::setTabCopy(tab);
}

template<typename T>
InsertionSort<T>::~InsertionSort() {
    Sort<T>::deleteTab();
}

template<typename T>
void InsertionSort<T>::sort(){
    int *temp = Sort<T>::getTabCopy();
    for(int i=1; i<Sort<T>::getTabSize(); i++){
        int j=i;
        while(j>0 && temp[j] < temp[j-1]){
            Sort<T>::swap(&temp[j-1], &temp[j]);
            j--;
        }
    }
}