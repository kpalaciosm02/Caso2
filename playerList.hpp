#include <string>
#include <iostream>
using namespace std;
#include "playerNode.hpp"

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
        //Adds a player at the end of the list
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
        //Remove a player based on its number
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
        //Adds a player to a given position
        int length = 0;
        playerNode * tmp = firstNode;
        while(tmp != NULL){
            length += 1;
            tmp = tmp->next;
        }
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
        //Prints the list in order
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