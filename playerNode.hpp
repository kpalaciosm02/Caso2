#include <string>
#include <iostream>
using namespace std;
#include "player.hpp"

struct playerNode{
    //Node from a linked list of strings
    player * _player;
    playerNode * next;

    playerNode(){
        //Constructor method
        _player = new player();
        next = NULL;
    }

    playerNode(int _id, string _name){
        //Constructor method
        _player = new player(_id, _name);
        next = NULL;
    }
    void printDataN(){
        //Prints the player's data
        cout << "ID: " << _player->id << " Name: " << _player->name << endl;
    }
};