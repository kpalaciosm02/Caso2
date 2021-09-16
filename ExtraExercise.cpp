#include "prueba.hpp"
int main(){
    doublePlayerList * list = new doublePlayerList();
    list->addPlayer(1,"Juan");
    list->addPlayer(2,"Hannah");
    list->addPlayer(3,"Fabián");
    cout << "Lenght: " << list->getQuantity() << endl;
    cout << list->firstNode->next->_player->name << endl;
    list->listPlayers();
}