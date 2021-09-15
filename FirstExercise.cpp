#include <iostream>
using namespace std;

int getMin(float * list, int size, int firstIndex){
    //returns the index of the minimum number of a list
    float min = list[firstIndex];
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

float * updateList(float * list, int firstIndex, int minNumberIndex){
    //changes the data between the first index and the index with the minimal number
    float minNumber = list[minNumberIndex];
    float firstIndexNumber = list[firstIndex];
    list[firstIndex] = minNumber;
    list[minNumberIndex] = firstIndexNumber;
    return list;
}

void sortBySelectionSort(float * pvaloresAOrdenar, int size){
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
    float lista[] = {24.2,42.1,58.7,2.1,104.5,17.6,99.5,13.6,8.8,145.9,59.0};
    float lista2[6] = {9.9,8.8,7.7,6.6,5.5,4.4};
    float * ptr = lista;
    float * ptr2 = lista2;
    sortBySelectionSort(ptr,11);
    sortBySelectionSort(ptr2,6);
    return 0;
}