#include <iostream>
using namespace std;

int getMin(int * list, int size, int firstIndex){
    //returns the index of the minimal number in an array.
    int min = list[firstIndex];
    for (int i = firstIndex; i <= size; i++){
        //cout << "List[i]: " << list[i] << " Min: " << min << endl;
        if (list[i] < min){
            min = list[i];
        }
    }
    for (int i = firstIndex; i < size; i++){
        if (list[i] == min)
            return i;
    }
}

int * updateList(int * listToUpdate, int MinNumberIndex, int firstIndex){
    int minNumber = listToUpdate[minNumber];
    int numberFirstIndex = listToUpdate[firstIndex];
    listToUpdate[firstIndex] = minNumber;
    listToUpdate[MinNumberIndex] = numberFirstIndex;
    return listToUpdate;
}

void sortBySelectionSort(int * pvaloresAOrdenar, int size){
    int firstIndex = 0;
    while(firstIndex < size - 1){
        int minNumberIndex = getMin(pvaloresAOrdenar, size, firstIndex);
        //cout << pvaloresAOrdenar[minNumberIndex] << endl;
        pvaloresAOrdenar = updateList(pvaloresAOrdenar,minNumberIndex,firstIndex);
        firstIndex ++;
    }
    //cout << pvaloresAOrdenar[0];
    for (int i = 0; i < size; i++){
        cout << pvaloresAOrdenar[i] << "->";
    }
}

int main(){
    /*int pValores[] = {1,2,3,4,5};
    int *ptr = pValores;*/
    //cout << ptr[0];
    int lista[] = {3,1,4,7,2};
    int * ptr = lista;
    //sortBySelectionSort(ptr,5);
    /*int minIndex = getMin(ptr,5,0);
    ptr = updateList(ptr,minIndex,0);
    cout << ptr[0]<< ptr[1];*/
    cout << getMin(lista, 5, 0) << endl;
    cout << getMin(lista, 5, 1) << endl;
    cout << getMin(lista, 5, 2) << endl;
    cout << getMin(lista, 5, 3) << endl;
    cout << getMin(lista, 5, 4) << endl;

    return 0;
}