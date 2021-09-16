#include <string>
#include <iostream>
using namespace std;
#include "doublePlayerNode.hpp"

struct doublePlayerList{
    doublePlayerNode * firstNode;
    doublePlayerNode * lastNode;

    doublePlayerList(){
        firstNode = lastNode = NULL;
    }
    bool isEmpty(){
        if (firstNode == NULL){
            return true;
        }
        else{
            return false;
        }
    }
    int getQuantity(){
        if (isEmpty()){
            return 0;
        }
        else{
            int length = 0;
            doublePlayerNode * tmp = firstNode;
            while(tmp != lastNode){
                length = length + 1;
                tmp = tmp->next;
            }
            length = length + 1;
            return length;
        }
    }
    bool addPlayer(int pNumber, string pName){
        doublePlayerNode * newNode = new doublePlayerNode(pNumber, pName);
        if (firstNode == NULL){
            firstNode = lastNode = newNode;
            return true;
        }
        else{
            newNode->previous = lastNode;
            newNode->next = firstNode;
            lastNode->next = newNode;
            firstNode->previous = newNode;
            lastNode = newNode;
            return true;
        }
    }
    bool removePlayer(int pNumber){
        if (firstNode == NULL){
            return false;
        }
        else{
            doublePlayerNode * tmp = firstNode;
            if (lastNode->_player->id == pNumber){
                lastNode->previous->next = firstNode;
                firstNode->previous = lastNode->previous;
                lastNode = lastNode->previous;
                return true;
            }
            else if (firstNode->_player->id == pNumber){
                firstNode->previous->next = firstNode->next;
                firstNode->next->previous = firstNode->previous;
                firstNode = firstNode->next;
                return true;
            }
            else{
                while(tmp->next != firstNode){
                    if (tmp->_player->id == pNumber){
                        tmp->previous->next = tmp->next;
                        tmp->next->previous = tmp->previous;
                        tmp = NULL;
                        return true;
                    }
                    else{
                        tmp = tmp->next;
                    }
                }
                return false;
            }
            
        }
    }
    void insertPlayer(int pNumber, string pName, int pPosition){
        int length = getQuantity();
        if (pPosition >= getQuantity() - 1){
            addPlayer(pNumber, pName);
        }
        else{
            doublePlayerNode * newNode = new doublePlayerNode(pNumber, pName);
            if (pPosition == 0){
                newNode->previous = lastNode;
                lastNode->next = newNode;
                firstNode->previous = newNode;
                newNode->next = firstNode;
                firstNode = newNode;
            }
            else{
                int actual = 0;
                doublePlayerNode * tmp = firstNode;
                while(actual != pPosition){
                    tmp = tmp->next;
                    actual += 1;
                }
                tmp->previous->next = newNode;
                newNode->previous = tmp->previous;
                tmp->previous = newNode;
                newNode->next = tmp;
            }
        }
    }
    void listPlayers(){
        if (firstNode == NULL){
            cout << "FAIL: Tried to print empty list." << endl;
        }
        else{
            doublePlayerNode * tmp = firstNode;
            while(tmp->next != firstNode){
                tmp->printData();
                tmp = tmp->next;
            }
            tmp->printData();
        }
    }
};