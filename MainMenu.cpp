#include <iostream>
#include <algorithm>
#include <fstream>

#include "Sources/Counter.h"
#include "Sources/InsertionSort.h"
#include "Sources/QuickSort.h"
#include "Sources/ShellSort.h"
#include "Sources/HeapSort.h"
#include "StaticFunctions.cpp"

using namespace std;

template<typename T> T *tab;
int tabSize;

template<typename T> void menu();
template<typename T> void read_from_file();
template<typename T> void all_sort_menu();
template<typename T> void insertion_sort_menu();
template<typename T> void heap_sort_menu();
template<typename T> void quick_sort_menu(int pivot);
template<typename T> void shell_sort_menu(int choice);
template<typename T> void symulacja();
template<typename T> void symulacja_temp(int algorithm_choice);

template<typename T>
void symulacja(){
    for(tabSize=10000; tabSize<=640000; tabSize*=2) {
        for (int i = 0; i < 100; i++) {
            tab<T> = generate_table<T>(tab<T>, tabSize);
            //sortAscendigly(tab<T>, tabSize);
            //sortDescendigly(tab<T>, tabSize);
            //sort33<T>(tab<T>, tabSize);
            //sort66<T>(tab<T>, tabSize);
            symulacja_temp<T>(8);
        }
        cout << "space" << endl;
    }
    char a;
    cin >> a;
}

template<typename T>
void symulacja_temp(int algorithm_choice){
    Counter counter;
    switch (algorithm_choice) {
        case 1:{
            InsertionSort<T> insertionSort(tab<T>,tabSize);
            counter.start();
            insertionSort.sort();
            counter.stop();
            break;
        }
        case 2:{
            HeapSort<T> heapSort(tab<T>, tabSize);
            counter.start();
            heapSort.sort();
            counter.stop();
            break;
        }
        case 3:{
            ShellSort<T> shellSort(tab<T>, tabSize);
            counter.start();
            shellSort.shellalgsort();
            counter.stop();
            break;
        }
        case 4:{
            ShellSort<T> shellSort(tab<T>, tabSize);
            counter.start();
            shellSort.sedgewickalgsort();
            counter.stop();
            break;
        }
        case 5:{
            QuickSort<T> quickSort(tab<T>, tabSize, 1);
            counter.start();
            quickSort.sort();
            counter.stop();
            break;
        }
        case 6:{
            QuickSort<T> quickSort(tab<T>, tabSize, 2);
            counter.start();
            quickSort.sort();
            counter.stop();
            break;
        }
        case 7:{
            QuickSort<T> quickSort(tab<T>, tabSize, 3);
            counter.start();
            quickSort.sort();
            counter.stop();
            break;
        }
        case 8:{
            QuickSort<T> quickSort(tab<T>, tabSize, 4);
            counter.start();
            quickSort.sort();
            counter.stop();
            break;
        }
    }
    cout << counter.getElapsedTime() << " " << endl;
}

template<typename T>
void read_from_file() {
    string url;
    int pom, i;
    system("CLS");
    cout << "Podaj nazwe pliku tekstowego (bez rozszerzenia)" << endl;
    cin >> url;
    system("CLS");
    ifstream file(url + ".txt");
    delete [] tab<T>;
    if (file.is_open()) {
        i = 0;
        while (file >> pom) {
            if (i == 0) {
                tabSize = pom;
                tab<T> = new T[tabSize];
            } else tab<T>[i - 1] = pom;
            i++;
        }
    } else {
        cout << "Niepoprawna nazwa pliku!" << endl;
    }
}

int main() {
    char c;
    bool out = false;
    while (!out) {
        system("CLS");
        cout << "Wybierz na jakich typach chcesz pracowac" << endl;
        cout << "i-Int" << endl;
        cout << "f-Float" << endl;
        cout << "0-Wyjscie z programu" << endl;
        cin >> c;
        system("CLS");
        if (c == 'i') {
            menu<int>();
            //symulacja<int>();
            delete[] tab<int>;
        } else if (c == 'f') {
            menu<float>();
            //symulacja<float>();
            delete[] tab<float>;
        } else if (c == '0') {
            out = true;
        }
    }
    return 0;
}

template<typename T>
void menu() {
    bool out = false;
    while (!out) {
        int n;
        cout << "======================MENU======================" << endl;
        cout << "1-Wczytaj dane z pliku tekstowego" << endl;
        cout << "2-Wygeneruj tablice o zadanym rozmiarze" << endl;
        cout << "3-Wyswietl tablice na ekranie" << endl;
        cout << "4-Przeprowadz sortowanie" << endl;
        cout << "0-Wroc do poprzedniego menu" << endl;
        cin >> n;
        switch (n) {
            case 1: {
                read_from_file<T>();
                break;
            }
            case 2: {
                system("CLS");
                cout << "Podaj wielkosc tablicy:" << endl;
                cin >> tabSize;
                system("CLS");
                tab<T> = generate_table<T>(tab<T>, tabSize);
                break;
            }
            case 3: {
                system("CLS");
                if (tab<T> != NULL) {
                    show_array<T>(tab<T>, tabSize);
                } else cout << "Tablica jest pusta!" << endl;
                break;
            }
            case 4: {
                system("CLS");
                if (tab<T> != NULL) {
                    all_sort_menu<T>();
                } else cout << "Tablica jest pusta!" << endl;
                break;
            }
            case 0: {
                out = true;
                system("CLS");
                break;
            }
            default:
                cout << "Niepoprawna liczba" << endl;
                system("CLS");
                break;
        }
    }
}

template<typename T>
void all_sort_menu() {
    int n;
    bool out = false;
    while (!out) {
        cout << "============WYBIERZ METODE SORTOWANIA===========" << endl;
        cout << "1-Sortowanie przez wstawianie (Insertion Sort)" << endl;
        cout << "2-Sortowanie przez kopcowanie (Heap Sort)" << endl;
        cout << "3-Sortowanie Shella (Shell's Sort)" << endl;
        cout << "4-Sortowanie szybkie (Quick Sort)" << endl;
        cout << "0-Wroc do menu glownego" << endl;
        cin >> n;
        switch (n) {
            case 1: {
                insertion_sort_menu<T>();
                break;
            }
            case 2: {
                heap_sort_menu<T>();
                break;
            }
            case 3: {
                int choice;
                system("CLS");
                cout << "====WYBIERZ ZLOZONOSC ALGORYTMU=====" << endl;
                cout << "1-O(n^2) Shell'a" << endl;
                cout << "2-O(n^4/3) Sedgewick'a" << endl;
                cin >> choice;
                shell_sort_menu<T>(choice);
                break;
            }
            case 4: {
                int pivot;
                system("CLS");
                cout << "============WYBIERZ PIVOT===========" << endl;
                cout << "1-lewy" << endl;
                cout << "2-srodkowy" << endl;
                cout << "3-prawy" << endl;
                cout << "4-losowy" << endl;
                cin >> pivot;
                quick_sort_menu<T>(pivot);
                break;
            }
            case 0: {
                system("CLS");
                out = true;
                break;
            }
            default: {
                out = true;
                break;
            }
        }
    }
}

template<typename T>
void insertion_sort_menu() {
    int n;
    bool out = false;
    system("CLS");
    InsertionSort<T> insertionSort(tab<T>, tabSize);
    Counter counter;
    counter.start();
    insertionSort.sort();
    counter.stop();
    cout << "Posortowano tablice w czasie " << counter.getElapsedTime() << " ms" << endl;
    while (!out) {
        cout << "1-Wyswietl posortowana tablice" << endl;
        cout << "2-Sprawdz poprawnosc posortowania" << endl;
        cout << "0-Wroc do poprzedniego menu" << endl;
        cin >> n;
        switch (n) {
            case 1: {
                system("CLS");
                insertionSort.printTab();
                break;
            }
            case 2: {
                system("CLS");
                if(insertionSort.isSortCorrect()) cout << "True" << endl;
                else cout << "False" << endl;
                break;
            }
            case 0: {
                system("CLS");
                out = true;
                break;
            }
            default: {
                out = true;
                break;
            }
        }
    }
}

template<typename T>
void heap_sort_menu(){
    int n;
    bool out = false;
    system("CLS");
    HeapSort<T> heapSort(tab<T>, tabSize);
    Counter counter;
    counter.start();
    heapSort.sort();
    counter.stop();
    cout << "Posortowano tablice w czasie " << counter.getElapsedTime() << " ms" << endl;
    while (!out) {
        cout << "1-Wyswietl posortowana tablice" << endl;
        cout << "2-Sprawdz poprawnosc posortowania" << endl;
        cout << "0-Wroc do poprzedniego menu" << endl;
        cin >> n;
        switch (n) {
            case 1: {
                system("CLS");
                heapSort.printTab();
                break;
            }
            case 2: {
                system("CLS");
                if(heapSort.isSortCorrect()) cout << "True" << endl;
                else cout << "False" << endl;
                break;
            }
            case 0: {
                system("CLS");
                out = true;
                break;
            }
            default: {
                out = true;
                break;
            }
        }
    }
}

template<typename T>
void quick_sort_menu(int pivot) {
    int n;
    bool out = false;
    system("CLS");
    QuickSort<T> quickSort(tab<T>, tabSize, pivot);
    Counter counter;
    counter.start();
    quickSort.sort();
    counter.stop();
    cout << "Posortowano tablice w czasie " << counter.getElapsedTime() << " ms " << endl;
    while (!out) {
        cout << "1-Wyswietl posortowana tablice" << endl;
        cout << "2-Sprawdz poprawnosc posortowania" << endl;
        cout << "0-Wroc do poprzedniego menu" << endl;
        cin >> n;
        switch (n) {
            case 1: {
                system("CLS");
                quickSort.printTab();
                break;
            }
            case 2: {
                system("CLS");
                if(quickSort.isSortCorrect()) cout << "True" << endl;
                else cout << "False" << endl;
                break;
            }
            case 0: {
                system("CLS");
                out = true;
                break;
            }
            default: {
                out = true;
                break;
            }
        }
    }
}

template<typename T>
void shell_sort_menu(int choice){
    int n;
    bool out = false;
    system("CLS");
    ShellSort<T> shellSort(tab<T>, tabSize);
    if(choice==1){
        Counter counter;
        counter.start();
        shellSort.shellalgsort();
        counter.stop();
        cout << "Posortowano tablice w czasie " << counter.getElapsedTime() << " ms" << endl;
    }else if(choice==2){
        Counter counter;
        counter.start();
        shellSort.sedgewickalgsort();
        counter.stop();
        cout << "Posortowano tablice w czasie " << counter.getElapsedTime() << " ms" << endl;
    }
    while (!out) {
        cout << "1-Wyswietl posortowana tablice" << endl;
        cout << "2-Sprawdz poprawnosc posortowania" << endl;
        cout << "0-Wroc do poprzedniego menu" << endl;
        cin >> n;
        switch (n) {
            case 1: {
                system("CLS");
                shellSort.printTab();
                break;
            }
            case 2: {
                system("CLS");
                if(shellSort.isSortCorrect()) cout << "True" << endl;
                else cout << "False" << endl;
                break;
            }
            case 0: {
                system("CLS");
                out = true;
                break;
            }
            default: {
                out = true;
                break;
            }
        }
    }
}
