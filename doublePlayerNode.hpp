#include <string>
#include <iostream>
using namespace std;
#include "player.hpp"

struct doublePlayerNode{
    //Node from a double linked list (2 pointers)
    player * _player;
    doublePlayerNode * next;
    doublePlayerNode * previous;

    doublePlayerNode(){
        //Constructor method
        _player = new player();
        next = NULL;
        previous = NULL;
    }

    doublePlayerNode(int _id, string _name){
        //Constructor method
        _player = new player(_id,_name);
        next = NULL;
        previous = NULL;
    }

    void printData(){
        //Prints the player's data
        cout << "ID: " << _player->id << " Name: " << _player->name << endl;
    }

};