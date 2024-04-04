#include "InsertionSort.h"

InsertionSort::InsertionSort(int *tab, int tabSize){
    Sort::setTabSize(tabSize);
    Sort::setTabCopy(tab);
}

InsertionSort::~InsertionSort() {
    Sort::deleteTab();
}

void InsertionSort::sort(){
    int *temp = Sort::getTabCopy();
    for(int i=1; i<Sort::getTabSize(); i++){
        int j=i;
        while(j>0 && temp[j] < temp[j-1]){
            swap(&temp[j-1], &temp[j]);
            j--;
        }
        /*for(int j=i; j>0; j--){
            if(temp[j] < temp[j-1]){
                swap(&temp[j-1], &temp[j]);
            }
        }*/
    }
}