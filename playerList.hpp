#include <string>
#include <iostream>
using namespace std;

struct player{
    int id;
    string name;
    player(){
        id = 0;
        name = "";
    }
    player(int _id, string _name){
        id = _id;
        name = _name;
    }
    void printDataP(){
        cout << "ID: " << id << " Name: " << name << endl;
    }
};

struct playerNode{
    player * _player;
    playerNode * next;

    playerNode(){
        _player = new player();
        next = NULL;
    }

    playerNode(int _id, string _name){
        _player = new player(_id, _name);
        next = NULL;
    }
    void printDataN(){
        cout << "ID: " << _player->id << " Name: " << _player->name << endl;
    }
};