#include "playerList.hpp"

int main(){
    /*cout << "PLAYER CREATION TESTS." << endl;
    player * player1 = new player();
    player1->printDataP();
    player * player2 = new player(1, "Kenneth");
    player2->printDataP();

    cout << "NODE CREATION TESTS." << endl;
    playerNode * nodo1 = new playerNode();
    nodo1->printDataN();
    playerNode * nodo2 = new playerNode(2, "Fabian");
    nodo2->printDataN();*/

    playerList * list = new playerList();
    cout << "Quantity of players: " << list->getQuantity() << endl;
    cout << "Lista vacía: " << list->isEmpty() << endl;
    list->listPlayers();
    list->addPlayer(3,"Juan");
    list->addPlayer(4,"María");
    list->addPlayer(6,"Hannah");
    list->addPlayer(8,"Pedro");
    list->listPlayers();
    cout << "Quantity of players: " << list->getQuantity() << endl;
    cout << "Lista vacía: " << list->isEmpty() << endl;
    cout << "Quitando jugador 3: " << list->removePlayer(3) << endl;
    cout<< "Quitando jugador 5: " << list->removePlayer(5) << endl;
    cout<< "Quitando jugador 6: " << list->removePlayer(6) << endl;
    cout << "Quitando jugador 8: " << list->removePlayer(8) << endl;
    list->listPlayers();

    return 0;
}