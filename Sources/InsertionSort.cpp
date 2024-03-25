#include "InsertionSort.h"

InsertionSort::InsertionSort(int *tab, int tabSize) {
    Sort::setTabSize(tabSize);
    Sort::setTabCopy(tab);
}

InsertionSort::~InsertionSort() {
    Sort::deleteTab();
}

void InsertionSort::sort() {
    int *temp = Sort::getTabCopy();
    for(int i=1; i<Sort::getTabSize(); i++){
        for(int j=i; j>0; j--){
            if(temp[j] < temp[j-1]){
                int num = temp[j];
                temp[j] = temp[j-1];
                temp[j-1] = num;
            }
        }
    }
}
