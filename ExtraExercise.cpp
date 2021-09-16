#include "doubleCircularPlayerList.hpp"
int main(){
    doublePlayerList * list = new doublePlayerList();
    list->addPlayer(1,"Juan");
    list->addPlayer(2,"Hannah");
    list->addPlayer(3,"Fabián");
    list->addPlayer(4,"Pedro");
    list->addPlayer(5,"Sabrina");
    //cout << "Lenght: " << list->getQuantity() << endl;
    //cout << list->firstNode->previous->next->_player->name << endl;
    list->listPlayers();
    list->removePlayer(5);
    //list->removePlayer(1);
    list->removePlayer(3);
    cout << endl << endl;
    list->listPlayers();
    //list->addPlayer(6,"Diego");
    list->listPlayers();
}