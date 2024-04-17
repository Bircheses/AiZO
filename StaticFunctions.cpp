#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <fstream>
#include <algorithm>

using namespace std;

template<typename T>
static void sortAscendigly(T* tab, int tabSize){
    sort(tab, tab+tabSize);
}

template<typename T>
static void sortDescendigly(T* tab, int tabSize){
    sort(tab, tab+tabSize, greater<T>());
};

template<typename T>
static void sort33(T* tab, int tabSize){
    srand(time(NULL));
    if(std::numeric_limits<T>::is_integer) {
        for (int i = 0; i < tabSize/3; i++) {
            tab[i] = rand() % 3333 + 1;
        }
        for (int i = tabSize/3; i < tabSize; i++){
            tab[i] = rand() % 6666 + 3334;
        }
    }else{
        for (int i = 0; i < tabSize/3; i++) {
            tab[i] = (rand() % 3333 + 1)+((float)(rand())/(float)(RAND_MAX));
        }
        for (int i = tabSize/3; i < tabSize; i++){
            tab[i] = (rand() % 6666 + 3334)+((float)(rand())/(float)(RAND_MAX));
        }
    }
    sort(tab, tab+(tabSize/3));
    /*int i=tabSize-1;
    while(tab[i]>3333) i--;
    cout << i << endl;*/
};

template<typename T>
static void sort66(T* tab, int tabSize){
    srand(time(NULL));
    if(std::numeric_limits<T>::is_integer) {
        for (int i = 0; i < tabSize*2/3; i++) {
            tab[i] = rand() % 6666 + 1;
        }
        for (int i = tabSize*2/3; i < tabSize; i++){
            tab[i] = rand() % 3333 + 6667;
        }
    }else{
        for (int i = 0; i < tabSize*2/3; i++) {
            tab[i] = (rand() % 6666 + 1)+((float)(rand())/(float)(RAND_MAX));
        }
        for (int i = tabSize*2/3; i < tabSize; i++){
            tab[i] = (rand() % 3333 + 6667)+((float)(rand())/(float)(RAND_MAX));
        }
    }
    sort(tab, tab+(tabSize*2/3));
    /*int i=tabSize-1;
    while(tab[i]>6666) i--;
    cout << i << endl;*/
};

template<typename T>
void show_array(T* tab, int tabSize) {
    for (int i = 0; i < tabSize; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;
}

template<typename T>
T* generate_table(T* ptr, int tabSize) {
    delete [] ptr;
    srand(time(NULL));
    T *tab = new T[tabSize];
    if(std::numeric_limits<T>::is_integer) {
        for (int i = 0; i < tabSize; i++) {
            tab[i] = rand() % 9999 + 1;
        }
    }else{
        for (int i = 0; i < tabSize; i++) {
            tab[i] = (rand() % 9999 + 1)+((float)(rand())/(float)(RAND_MAX));
        }
    }
    return tab;
}

template<typename T>
T* read_from_file(T* ptr, int tabSize) {
    string url;
    int pom, i;
    T *tab;
    system("CLS");
    cout << "Podaj nazwe pliku tekstowego (bez rozszerzenia)" << endl;
    cin >> url;
    system("CLS");
    ifstream file(url + ".txt");
    delete [] ptr;
    if (file.is_open()) {
        i = 0;
        while (file >> pom) {
            if (i == 0) {
                tabSize = pom;
                tab = new T[tabSize];
            } else tab[i - 1] = pom;
            i++;
        }
        return tab;
    } else cout << "Niepoprawna nazwa pliku!" << endl;
}