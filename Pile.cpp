#include "Pile.h"

Pile::Pile(){
    top = 0;
    for (int i = 0; i < 5; i++){
        Stack[i] = nullptr;
    }
}

void Pile::push(Card* card){
    if(top != 5){
        Stack[top] = card;
        top++;
    }
    else{//Throw stack full exception
    }
}

int Pile::pop(){
    if(top = 0){
        top--;
        delete Stack[top];
    }
    else{//Throw stack empty exception
    }
}