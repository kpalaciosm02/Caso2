#include "playerList.hpp"

int main(){
    cout << "PLAYER CREATION TESTS." << endl;
    player * player1 = new player();
    player1->printDataP();
    player * player2 = new player(1, "Kenneth");
    player2->printDataP();

    cout << "NODE CREATION TESTS." << endl;
    playerNode * nodo1 = new playerNode();
    nodo1->printDataN();
    playerNode * nodo2 = new playerNode(2, "Fabian");
    nodo2->printDataN();
    return 0;
}