#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "Counter.h"
#include "Sources/InsertionSort.h"
#include "Sources/QuickSort.h"
#include "Sources/ShellSort.h"
#include "Sources/HeapSort.h"

using namespace std;

int *tab;
int tabSize;

void menu();
void read_from_file();
void generate_table();
void show_array();
void run_sort();
void insertion_sort();
void heap_sort();
void quick_sort(int pivot);
void shell_sort(int choice);

int main() {
    menu();
    delete[] tab;
    return 0;
}

void menu() {
    srand(time(NULL));
    bool out = false;
    while (!out) {
        int n;
        cout << "======================MENU======================" << endl;
        cout << "1-Wczytaj dane z pliku tekstowego" << endl;
        cout << "2-Wygeneruj tablice o zadanym rozmiarze" << endl;
        cout << "3-Wyswietl tablice na ekranie" << endl;
        cout << "4-Przeprowadz sortowanie" << endl;
        cout << "0-Zakoncz program" << endl;
        cin >> n;
        switch (n) {
            case 1: {
                read_from_file();
                break;
            }
            case 2: {
                system("CLS");
                cout << "Podaj wielkosc tablicy:" << endl;
                cin >> tabSize;
                system("CLS");
                generate_table();
                break;
            }
            case 3: {
                system("CLS");
                if (tab != NULL) {
                    show_array();
                } else cout << "Tablica jest pusta!" << endl;
                break;
            }
            case 4: {
                system("CLS");
                if (tab != NULL) {
                    run_sort();
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

void read_from_file() {
    string url;
    int pom, i;
    system("CLS");
    cout << "Podaj nazwe pliku tekstowego (bez rozszerzenia)" << endl;
    cin >> url;
    system("CLS");
    ifstream file(url + ".txt");
    if (tab != NULL) delete[] tab;
    if (file.is_open()) {
        i = 0;
        while (file >> pom) {
            if (i == 0) {
                tabSize = pom;
                tab = new int[tabSize];
            } else tab[i - 1] = pom;
            i++;
        }
    } else cout << "Niepoprawna nazwa pliku!" << endl;
}

void generate_table() {
    if (tab != nullptr) delete[] tab;
    tab = new int[tabSize];
    for (int i = 0; i < tabSize; i++) {
        tab[i] = rand() % 9999 + 1;
    }
}

void show_array() {
    for (int i = 0; i < tabSize; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;
}

void run_sort() {
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
                insertion_sort();
                break;
            }
            case 2: {
                heap_sort();
                break;
            }
            case 3: {
                int choice;
                system("CLS");
                cout << "====WYBIERZ ZLOZONOSC ALGORYTMU=====" << endl;
                cout << "1-O(n^2) Shell'a" << endl;
                cout << "2-O(n^4/3) Sedgewick'a" << endl;
                cin >> choice;
                shell_sort(choice);
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
                quick_sort(pivot);
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

void insertion_sort() {
    int n;
    bool out = false;
    InsertionSort insertionSort(tab, tabSize);
    Counter counter;
    counter.start();
    insertionSort.sort();
    counter.stop();
    system("CLS");
    cout << "Posortowano tablice w czasie " << counter.getElapsedTime() << " ms" << endl;
    while (!out) {
        cout << "1-Wyswietl posortowana tablice" << endl;
        cout << "0-Wroc do poprzedniego menu" << endl;
        cin >> n;
        switch (n) {
            case 1: {
                system("CLS");
                insertionSort.printTab();
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

void heap_sort(){
    int n;
    bool out = false;
    HeapSort heapSort(tab, tabSize);
    Counter counter;
    counter.start();
    heapSort.sort();
    counter.stop();
    system("CLS");
    cout << "Posortowano tablice w czasie " << counter.getElapsedTime() << " ms" << endl;
    while (!out) {
        cout << "1-Wyswietl posortowana tablice" << endl;
        cout << "0-Wroc do poprzedniego menu" << endl;
        cin >> n;
        switch (n) {
            case 1: {
                system("CLS");
                heapSort.printTab();
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

void quick_sort(int pivot) {
    int n;
    bool out = false;
    system("CLS");
    QuickSort quickSort(tab, tabSize, pivot);
    Counter counter;
    counter.start();
    quickSort.sort();
    counter.stop();
    cout << "Posortowano tablice w czasie " << counter.getElapsedTime() << " ms" << endl;
    while (!out) {
        cout << "1-Wyswietl posortowana tablice" << endl;
        cout << "0-Wroc do poprzedniego menu" << endl;
        cin >> n;
        switch (n) {
            case 1: {
                system("CLS");
                quickSort.printTab();
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

void shell_sort(int choice){
    int n;
    bool out = false;
    ShellSort shellSort(tab, tabSize);
    if(choice==1){
        Counter counter;
        counter.start();
        shellSort.shellalgsort();
        counter.stop();
        system("CLS");
        cout << "Posortowano tablice w czasie " << counter.getElapsedTime() << " ms" << endl;
    }else if(choice==2){
        Counter counter;
        counter.start();
        shellSort.sedgewickalgsort();
        counter.stop();
        system("CLS");
        cout << "Posortowano tablice w czasie " << counter.getElapsedTime() << " ms" << endl;
    }
    while (!out) {
        cout << "1-Wyswietl posortowana tablice" << endl;
        cout << "0-Wroc do poprzedniego menu" << endl;
        cin >> n;
        switch (n) {
            case 1: {
                system("CLS");
                shellSort.printTab();
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