#include "ShellSort.h"

template<typename T>
ShellSort<T>::ShellSort(T *tab, int tabSize) {
    Sort<T>::setTabSize(tabSize);
    Sort<T>::setTabCopy(tab);
    while(arr[k]>=tabSize) k--;
}

template<typename T>
ShellSort<T>::~ShellSort() {
    Sort<T>::deleteTab();
}

template<typename T>
void ShellSort<T>::shellalgsort() {
    T *temp = Sort<T>::getTabCopy();
    int tabSize = Sort<T>::getTabSize();
    for (int gap=tabSize/2; gap>0; gap/=2) {
        for(int i=gap; i<tabSize; i++){
            int j=i;
            while(j>=gap && temp[j] < temp[j-gap]){
                Sort<T>::swap(&temp[j-gap], &temp[j]);
                j-=gap;
            }
        }
    }
}

template<typename T>
void ShellSort<T>::sedgewickalgsort() {
    T *temp = Sort<T>::getTabCopy();
    int tabSize = Sort<T>::getTabSize();
    for (int gap=arr[k]; gap>0; gap=arr[k--]) {
        for(int i=gap; i<tabSize; i++){
            int j=i;
            while(j>=gap && temp[j] < temp[j-gap]){
                Sort<T>::swap(&temp[j-gap], &temp[j]);
                j-=gap;
            }
        }
    }
}