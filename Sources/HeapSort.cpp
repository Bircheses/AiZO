#include <iostream>
#include "HeapSort.h"

HeapSort::HeapSort(int *tab, int tabSize){
    Sort::setTabSize(tabSize);
    Sort::setTabCopy(tab);
    HeapSort::createHeap(Sort::getTabCopy(), Sort::getTabSize());
}

HeapSort::~HeapSort() {
    Sort::deleteTab();
}

void HeapSort::sort() {
    int *temp = Sort::getTabCopy();
    for(int i=1;i<=getTabSize();i++) {
        swap(&temp[0], &temp[getTabSize() - i]);
        fixHeapDown(temp, 0, getTabSize() - i);
    }
}

void HeapSort::createHeap(int *tabCopy, int tabSize) {
    for(int i=(tabSize-2)/2; i>=0; --i){
        HeapSort::fixHeapDown(tabCopy, i, tabSize);
    }
}

void HeapSort::fixHeapDown(int *tabCopy, int i, int tabSize) {
    if (tabCopy[2*i+1]>=tabCopy[2*i+2]) {
        if (tabCopy[2*i+1]>tabCopy[i]) {
            Sort::swap(&tabCopy[i], &tabCopy[2*i+1]);
            if(2*i+1<=(tabSize-2)/2) HeapSort::fixHeapDown(tabCopy, 2*i+1, tabSize);
        }
    } else {
        if (tabCopy[2*i+2] > tabCopy[i] && 2*i+2 < tabSize) {
            Sort::swap(&tabCopy[i], &tabCopy[2*i+2]);
            if(2*i+2<=(tabSize-2)/2) HeapSort::fixHeapDown(tabCopy, 2*i+2, tabSize);
        }
    }
}