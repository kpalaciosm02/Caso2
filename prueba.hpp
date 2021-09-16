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