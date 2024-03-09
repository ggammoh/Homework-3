#include "Pile.h"

Pile::Pile(){
    front = 0;
    for (int i = 0; i < 5; i++){
        Stack[i] = nullptr;
    }
}

void Pile::push(Card* card){
    if(front != 5){
        Stack[front] = card;
        front++;
    }
    else{//Throw stack full exception
    }

}

int Pile::pop(){
    int val = -1;
    if(front != 0){
        Card* temp = Stack[front-1];
        val = temp->value;
        delete Stack[front];
        front--;
        return val;
    }
    else{return -1;} //If Stack is empty
    return val;
}

int Pile::getNumCardsLeft() {
    return front;
}