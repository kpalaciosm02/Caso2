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

struct playerList{
    //Linked list made of players
    playerNode * firstNode;

    playerList(){
        //Constructor method
        firstNode = NULL;
    }
    bool isEmpty(){
        //Checks if the list is empty
        if (firstNode == NULL){
            return true;
        }
        else{
            return false;
        }
    }
    int getQuantity(){
        //Returns the length of the list
        if (firstNode == NULL){
            return 0;
        }
        else{
            int length = 0;
            playerNode * tmp = firstNode;
            while(tmp != NULL){
                length += 1;
                tmp = tmp->next;
            }
            return length;
        }
    }
    bool addPlayer(int pNumber, string pName){
        playerNode * newNode = new playerNode(pNumber, pName);
        if (firstNode == NULL){
            firstNode = newNode;
            return true;
        }
        else{
            playerNode * tmp = firstNode;
            while (tmp != NULL){
                if (tmp->next !=NULL){
                    tmp = tmp->next;
                }
                else{
                    tmp->next = newNode;
                    return true;
                }
            }
            return false;
        }
    }
    bool removePlayer(int pNumber){
        if (firstNode == NULL){
            return false;
        }
        else{
            playerNode * tmp = firstNode;
            if (firstNode->_player->id == pNumber){
                firstNode = firstNode->next;
                return true;
            }
            else{
                playerNode * anterior = firstNode;
                tmp = tmp->next;
                while(tmp != NULL){
                    if (tmp->_player->id == pNumber){
                        anterior->next = tmp->next;
                        return true;
                    }
                    else{
                        anterior = anterior->next;
                        tmp = tmp->next;
                    }
                }
                return false;
            }
            
        }
    }
    bool insertPlayer(int pNumber, string pName, int pPosition){
        int length = 0;
        playerNode * tmp = firstNode;
        while(tmp != NULL){
            length += 1;
            tmp = tmp->next;
        }
        //cout << "Largo: " << length << endl;
        playerNode * newNode = new playerNode(pNumber, pName);
        if (firstNode == NULL){
            firstNode = newNode;
            return true;
        }
        else{
            int actual = 0;
            if (pPosition > length){
                pPosition = length;
                playerNode * tmp = firstNode;
                while (actual < pPosition - 1){
                    //tmp->printDataN();
                    tmp = tmp->next;
                    actual = actual + 1;
                }
                tmp->next = newNode;
            }
            else{
                playerNode * tmp = firstNode;
                while(actual != pPosition - 1){
                    tmp = tmp->next;
                    actual = actual + 1;
                }
                playerNode * nextNode = tmp->next;
                newNode->next = nextNode;
                tmp->next = newNode;
            }
        }
    }

    void listPlayers(){
        if (firstNode == NULL){
            cout << "FAIL: Tried to print empty list." << endl;
        }
        else{
            playerNode * tmp = firstNode;
            while(tmp != NULL){
                tmp->printDataN();
                tmp = tmp->next;
            }
        }
    }
};