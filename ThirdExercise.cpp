#include "playerList.hpp"
#include <string>
#include <iostream>
using namespace std;

void sortByInsertionSort(playerList * playerList){
    playerNode * firstNode = playerList->firstNode;
    cout << "Primer nodo: " << firstNode->_player->name << " Segundo Nodo: " << firstNode->next->_player->name << endl;
    cout << firstNode->_player->name.compare(firstNode->next->_player->name) << endl;
}

bool checkSorted(playerList * playerList){
    playerNode * tmp = playerList->firstNode;
    while (tmp->next != NULL){
        cout << tmp->_player->name.compare(tmp->next->_player->name) << endl;
        if (tmp->_player->name.compare(tmp->next->_player->name) < 0)
            return false;
        tmp = tmp->next;
    }
    return true;
}

void swapNodes(playerList * playerList, int firstNodeToSwap){
    playerNode * tmp = playerList->firstNode;
    int actual = 0;
    while (actual != firstNodeToSwap){
        tmp = tmp->next;
        actual++;
    }
    if (tmp ->next != NULL){
        int idNext = tmp->next->_player->id;
        string nameNext = tmp->next->_player->name;

        tmp->next->_player->id = tmp->_player->id;
        tmp->next->_player->name = tmp->_player->name;
        
        tmp->_player->id = idNext;
        tmp->_player->name = nameNext;
    } 
}


void sortByInsertionSort2(playerList * playerList){
    int large = playerList->getQuantity();
    while(checkSorted(playerList) != true){
        for (int i = 0; i <large; i++){
            swapNodes(playerList,i);
        }
    }
    playerList->listPlayers();
}

int main(){
    playerList * list = new playerList();
    list->addPlayer(3,"Juan");
    list->addPlayer(4,"María");
    list->addPlayer(6,"Pedro");
    list->addPlayer(8,"Hannah");
    //sortByInsertionSort(list);
    //cout << "Sorted list: " << checkSorted(list) << endl;
    /*list->listPlayers();
    swapNodes(list,3);
    list->listPlayers();*/
    //sortByInsertionSort2(list);
}