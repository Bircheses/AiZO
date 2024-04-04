#include "ShellSort.h"

ShellSort::ShellSort(int *tab, int tabSize) {
    Sort::setTabSize(tabSize);
    Sort::setTabCopy(tab);
    while(arr[k]>=tabSize) k--;
}

ShellSort::~ShellSort() {
    Sort::deleteTab();
}

void ShellSort::shellalgsort() {
    int *temp = Sort::getTabCopy();
    int tabSize = Sort::getTabSize();
    for (int gap=tabSize/2; gap>0; gap/=2) {
        for(int i=gap; i<tabSize; i++){
            int j=i;
            while(j>=gap && temp[j] < temp[j-gap]){
                swap(&temp[j-gap], &temp[j]);
                j-=gap;
            }
        }
    }
}

void ShellSort::sedgewickalgsort() {
    int *temp = Sort::getTabCopy();
    int tabSize = Sort::getTabSize();
    for (int gap=arr[k]; gap>0; gap=arr[k--]) {
        for(int i=gap; i<tabSize; i++){
            int j=i;
            while(j>=gap && temp[j] < temp[j-gap]){
                swap(&temp[j-gap], &temp[j]);
                j-=gap;
            }
        }
    }
}