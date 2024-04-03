#include "ShellSort.h"

ShellSort::ShellSort() = default;

ShellSort::~ShellSort() {
    Sort::deleteTab();
}

void ShellSort::sort(int *tab, int tabSize, int algorithm_choice) {
    Sort::setTabSize(tabSize);
    Sort::setTabCopy(tab);
    switch (algorithm_choice) {
        case 1:
            shell(Sort::getTabCopy(), Sort::getTabSize());
        case 2:
            sedgewick(Sort::getTabCopy(), Sort::getTabSize());
    }
}

void ShellSort::shell(int *tab, int tabSize) {
    for (int gap=tabSize/2; gap>0; gap/=2) {
        for(int i=gap; i<tabSize; i++){
            int j=i;
            while(j>=gap && tab[j] < tab[j-gap]){
                swap(&tab[j-gap], &tab[j]);
                j-=gap;
            }
        }
    }
}

void ShellSort::sedgewick(int *tab, int tabSize) {
    int arr[10] = {1,8,23,77,281,1073,4193,16657,65921,262913};
    int k=9;
    while(arr[k]>=tabSize) k--;
    for (int gap=arr[k]; gap>0; gap=arr[k--]) {
        for(int i=gap; i<tabSize; i++){
            int j=i;
            while(j>=gap && tab[j] < tab[j-gap]){
                swap(&tab[j-gap], &tab[j]);
                j-=gap;
            }
        }
    }
}