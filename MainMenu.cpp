#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "Sources/InsertionSort.h"

using namespace std;

int* tab;
int tabSize;

void menu();
void read_from_file();
void generate_table();
void show_array();
void run_sort();
void inSort();

int main() {
    menu();
    delete [] tab;
    return 0;
}

void menu(){
    srand(time(NULL));
    bool out = false;
    while(!out){
        int n;
        cout << "======================MENU======================" << endl;
        cout << "1-Wczytaj dane z pliku tekstowego" << endl;
        cout << "2-Wygeneruj tablice o zadanym rozmiarze" << endl;
        cout << "3-Wyswietl tablice na ekranie" << endl;
        cout << "4-Przeprowadz sortowanie" << endl;
        cout << "0-Zakoncz program" << endl;
        cin >> n;
        switch(n){
        case 1:{
            read_from_file();
            break;
        }
        case 2:{
            system("CLS");
            cout << "Podaj wielkosc tablicy:" << endl;
            cin >> tabSize;
            system("CLS");
            generate_table();
            break;
        }
        case 3:{
            system("CLS");
            if(tab != NULL){
                show_array();
            }else cout << "Tablica jest pusta!" << endl;
            break;
        }
        case 4:{
            system("CLS");
            if(tab != NULL){
                run_sort();
            }else cout << "Tablica jest pusta!" << endl;
            break;
        }
        case 0:{
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

void read_from_file(){
    string url;
    int pom, i;
    system("CLS");
    cout << "Podaj nazwe pliku tekstowego (bez rozszerzenia)" << endl;
    cin >> url;
    system("CLS");
    ifstream file(url + ".txt");
    if(tab != NULL) delete [] tab;
    if(file.is_open()){
        i=0;
        while(file >> pom){
            if(i==0){
                tabSize = pom;
                tab = new int[tabSize];
            }
            else tab[i-1] = pom;
            i++;
        }
    }else cout << "Niepoprawna nazwa pliku!" << endl;
}

void generate_table(){
    if(tab != NULL) delete [] tab;
    tab = new int[tabSize];
    for(int i=0; i<tabSize; i++){
        tab[i]=rand()%99+1;
    }
}

void show_array(){
    for(int i=0;i<tabSize;i++){
        cout << tab[i] << " ";
    }
    cout << endl;
}

void run_sort(){
    int n;
    bool out = false;
    while(!out) {
        cout << "============WYBIERZ METODE SORTOWANIA===========" << endl;
        cout << "1-Sortowanie przez wstawianie (Insertion Sort)" << endl;
        cout << "2-Sortowanie przez kopcowanie (Heap Sort)" << endl;
        cout << "3-Sortowanie Shella (Shell's Sort)" << endl;
        cout << "4-Sortowanie szybkie (Quick Sort)" << endl;
        cout << "0-Wroc do menu glownego" << endl;
        cin >> n;
        switch (n) {
            case 1: {
                inSort();
                break;
            }
            case 2: {
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
            case 0:{
                system("CLS");
                out=true;
                break;
            }
            default:
                break;
        }
    }
}

void inSort(){
    int n;
    bool out = false;
    InsertionSort insertionSort(tab, tabSize);
    insertionSort.sort();
    system("CLS");
    cout << "Posortowano tablice!" << endl;
    while(!out) {
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
            default:
                break;
        }
    }
}