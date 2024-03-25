#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class QuickSort{
    public:
        int* tab_copy;
        int size;
        int pivot;

    //pivot: 1-skrajny lewy, 2-skrajny prawy, 3-środkowy, 4-losowy
    QuickSort(int* tab, int pivot, int size){
        srand(time(NULL));
        this->size=size;
        tab_copy = new int[size];
        for(int i=0; i<size; i++){
            tab_copy[i]=tab[i];
        }
        switch (pivot){
        case 1:
            this->pivot=0;
            break;
        case 2:
            this->pivot=tab_copy[size-1];
            break;
        case 3:
            this->pivot=tab_copy[size/2];
            break;
        case 4:
            this->pivot=tab_copy[rand()%size];
            break;
        default:
            break;
        }
        sort();
        display();
    }

    ~QuickSort(){
        delete [] tab_copy;
    }

    void sort(){
        for(int i=0; i<size; i++){
            for(int j=size-1; j>-1; j--){
                
            }
        }
    }

    void display(){
        for(int i=0; i<size; i++){
            cout << tab_copy[i] << " ";
        }
    }
};