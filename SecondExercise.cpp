#include "playerList.hpp"

int main(){
    cout << "----Second Exercise Tests----" << endl;
    playerList * list = new playerList();
    cout << "Quantity of players: " << list->getQuantity() << endl;
    cout << "Empty list: " << list->isEmpty() << endl;
    list->listPlayers();
    cout << endl << "Inserting players: " << endl;
    list->addPlayer(3,"Juan");
    list->addPlayer(4,"María");
    list->addPlayer(6,"Hannah");
    list->addPlayer(8,"Pedro");
    list->listPlayers();
    cout << "Remove a player: " << endl;
    list->removePlayer(8);
    list->listPlayers();
    cout << endl << "Insert a player in a given position: " << endl;
    list->insertPlayer(1,"a",10);
    list->listPlayers();
    cout << endl << "Insert a player in a given position: " << endl ;
    list->insertPlayer(7,"b",2);
    list->listPlayers();

    return 0;
}