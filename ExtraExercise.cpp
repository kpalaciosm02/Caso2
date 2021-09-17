#include "doubleCircularPlayerList.hpp"
int main(){
    cout << "----Extra Exercise Tests" << endl;
    doublePlayerList * list = new doublePlayerList();
    list->addPlayer(1,"Juan");
    list->addPlayer(2,"Hannah");
    list->addPlayer(3,"Fabián");
    list->addPlayer(4,"Pedro");
    list->addPlayer(5,"Sabrina");
    cout << "Lenght: " << list->getQuantity() << endl;
    cout << "Empty list: " << list->isEmpty() << endl;
    list->listPlayers();    
    cout << "Inserting players by index" << endl;
    list->insertPlayer(7,"Carlos",1);
    list->listPlayers();
    cout << "Removing players 1,3 and 5" << endl;
    list->removePlayer(5);
    list->removePlayer(1);
    list->removePlayer(3);
    list->listPlayers();
    cout << endl;
    list->addPlayer(6,"Diego");
    cout << endl;
    list->listPlayers();
}