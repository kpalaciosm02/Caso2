#include <string>
#include <iostream>
using namespace std;

struct player{
    //Structure representing a player
    int id;
    string name;
    player(){
        //Constructor method
        id = 0;
        name = "";
    }
    player(int _id, string _name){
        //Constructor method
        id = _id;
        name = _name;
    }
    void printDataP(){
        //Prints the player's data
        cout << "ID: " << id << " Name: " << name << endl;
    }
};