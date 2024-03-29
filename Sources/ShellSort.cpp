#include "ShellSort.h"

ShellSort::ShellSort(int *tab, int tabSize, int space) {
    Sort::setTabSize(tabSize);
    Sort::setTabCopy(tab);
}

ShellSort::~ShellSort() {
    Sort::deleteTab();
}

void ShellSort::sort() {

}

int ShellSort::pow(int a, int b) {
    if(b==0) return 1;
    else if(b==1) return b;
    else return a*pow(a,--b);
}
