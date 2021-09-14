#include <iostream>
using namespace std;

int getMin(int * list, int size, int firstIndex){
    //returns the index of the minimum number of a list
    int min = list[firstIndex];
    for (int i = firstIndex; i < size; i++){
        if (list[i] < min)
            min = list[i];
    }
    for (int j = 0; j < size; j++){
        if (list[j] == min){
            return j;
        }
    }
}

int * updateList(int * list, int firstIndex, int minNumberIndex){
    //changes the data between the first index and the index with the minimal number
    int minNumber = list[minNumberIndex];
    int firstIndexNumber = list[firstIndex];
    list[firstIndex] = minNumber;
    list[minNumberIndex] = firstIndexNumber;
    return list;
}

void sortBySelectionSort(int * pvaloresAOrdenar, int size){
    //calls the other functions to sort a list in a loop
    int index = 0;
    while (index < size - 1){
        int minNumberIndex = getMin(pvaloresAOrdenar, size, index);
        pvaloresAOrdenar = updateList(pvaloresAOrdenar,index,minNumberIndex);
        index ++;
    }
    for (int i = 0; i < size; i++){
        cout << pvaloresAOrdenar[i] << "->";
    }
    cout << endl;
}

int main(){
    int lista[] = {24,42,58,2,104,17,99,13,8,145,59};
    int * ptr = lista;
    sortBySelectionSort(ptr,11);
    return 0;
}