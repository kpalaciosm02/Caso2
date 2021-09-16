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
        return firstNode == NULL;
    }
    int getQuantity(){
        if (isEmpty()){
            return 0;
        }
        else{
            int lenght = 0;
            doublePlayerNode * tmp = firstNode;
            while(tmp != lastNode){
                lenght += 1;
                tmp = tmp->next;
            }
            lenght = lenght + 1;
            return lenght;
        }
    }
    bool addPlayer(int pNumber, string pName){
        doublePlayerNode * newNode = new doublePlayerNode(pNumber, pName);
        if (firstNode == NULL){
            firstNode = newNode;
            return true;
        }
        else{
            newNode->previous = lastNode;
            newNode->next = firstNode;
            lastNode->next = newNode;
            firstNode->previous = newNode;
            return true;
        }
    }
    void listPlayers(){
        if (firstNode == NULL){
            cout << "FAIL: Tried to print empty list." << endl;
        }
        else{
            doublePlayerNode * tmp = firstNode;
            while (tmp->next != firstNode){
                tmp->printData();
                tmp = tmp->next;
            }
        }
    }
};