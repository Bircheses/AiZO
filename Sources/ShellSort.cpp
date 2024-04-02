#include "ShellSort.h"

ShellSort::ShellSort() = default;

ShellSort::~ShellSort() {
    Sort::deleteTab();
}

void ShellSort::sort(int *tab, int tabSize, int space) {
    Sort::setTabSize(tabSize);
    Sort::setTabCopy(tab);
    for (int gap=tabSize/2; gap>0; gap/=2) {
        for (int i=gap; i<tabSize; i++) {
            for (int j=i-gap; j<tabSize/gap; j++){

            }
        }
    }
}

int ShellSort::pow(int a, int b) {
    if (b == 0) return 1;
    else if (b == 1) return b;
    else return a * pow(a, --b);
}
