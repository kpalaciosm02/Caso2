#include "playerList.hpp"

int main(){

    playerList * list = new playerList();
    cout << "Quantity of players: " << list->getQuantity() << endl;
    cout << "Lista vacía: " << list->isEmpty() << endl;
    list->listPlayers();
    list->addPlayer(3,"Juan");
    list->addPlayer(4,"María");
    list->addPlayer(6,"Hannah");
    list->addPlayer(8,"Pedro");
    list->listPlayers();
    list->insertPlayer(1,"a",10);
    list->listPlayers();
    list->insertPlayer(7,"b",2);
    list->listPlayers();

    return 0;
}