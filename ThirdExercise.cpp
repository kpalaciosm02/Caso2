#include "playerList.hpp"
#include <string>
#include <iostream>
using namespace std;

void sortByInsertionSort(playerList * playerList){
    playerNode * firstNode = playerList->firstNode;
    cout << "Primer nodo: " << firstNode->_player->name << " Segundo Nodo: " << firstNode->next->_player->name << endl;
    cout << firstNode->_player->name.compare(firstNode->next->_player->name) << endl;
}

int main(){
    string str1 = "Hannah";
    string str2 = "Pedro";
    string str3 = "Helena";
    cout << str2.compare(str1) << endl;
    playerList * list = new playerList();
    list->addPlayer(3,"Juan");
    list->addPlayer(4,"María");
    list->addPlayer(6,"Hannah");
    list->addPlayer(8,"Pedro");
    sortByInsertionSort(list);
}