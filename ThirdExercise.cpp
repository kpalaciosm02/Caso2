#include "playerList.hpp"
#include <string>
#include <iostream>
using namespace std;

bool checkSorted(playerList * playerList){
    //Checks if the full list is sorted
    playerNode * tmp = playerList->firstNode;
    while (tmp->next != NULL){
        if (tmp->_player->name.compare(tmp->next->_player->name) >= 0)
            return false;
        tmp = tmp->next;
    }
    return true;
}

void swapNodes(playerList * playerList, int firstNodeToSwap){
    //Changes 2 nodes between them. Needs an index to know which node to swap with the next
    playerNode * tmp = playerList->firstNode;
    int actual = 0;
    while (actual != firstNodeToSwap){
        tmp = tmp->next;
        actual++;
    }
    if (tmp->next != NULL){
        int idNext = tmp->next->_player->id;
        string nameNext = tmp->next->_player->name;

        tmp->next->_player->id = tmp->_player->id;
        tmp->next->_player->name = tmp->_player->name;
        
        tmp->_player->id = idNext;
        tmp->_player->name = nameNext;
    }
}

bool checkNodes(playerList * playerList1, int firstNodeToCheck){
    //Checks if 2 nodes are sorted between them, does not take into account the other nodes in the list
    playerNode * tmp = playerList1->firstNode;
    int actual = 0;
    while (actual != firstNodeToCheck){
        tmp = tmp->next;
        actual++;
    }
    if (tmp->next != NULL){
        if(tmp->_player->name.compare(tmp->next->_player->name) == 1){
            return false;
        }
        else{
            return true;
        }
    }
    else{
        return true;
    }
}


void sortByInsertionSort(playerList * playerList1){
    //Calls the sorting functions until the full list is sorted
    int large = playerList1->getQuantity();
    while(checkSorted(playerList1) != true){
            for (int i = 0; i < large; i++){
                if (checkNodes(playerList1,i) == false){
                    swapNodes(playerList1,i);
                    i = 0;
                }
            }
    }
    playerList1->listPlayers();
}

int main(){
    playerList * list = new playerList();
    list->addPlayer(3,"Hannah");
    list->addPlayer(4,"Pedro");
    list->addPlayer(6,"Juan");
    list->addPlayer(8,"Maria");
    list->listPlayers();
    cout << "----Sorting list-----" << endl;
    sortByInsertionSort(list);
}