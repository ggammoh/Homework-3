/*
Create a side pile class that models a stack using an array. This side pile will have a
maximum of 5 possible cards in the stack. A player cannot peek at what is in their side
pile. A player can add a card to the top or remove a card from the top. This needs a way
to tell the player how many cards they have left but not the other player
*/
#pragma once
#include "Card.h"
#include<iostream>
class Pile{
    private:
        int top;
        Card *Stack[5];
    public:

        Pile(){
            top = 0;
            for (int i = 0; i < 5; i++){
                Stack[i] = nullptr;
            }
        }

        void push(Card *card){
            std::cout << top;
            if(top < 5){
                Stack[top] = card;
                top++;
            }
            else{//Throw stack full exception
            }
        }

        int pop(){
            int val = -1;
            
            if(top > 0){
                top--;
                val = Stack[top]->value;
                Stack[top] = NULL;
                return val;
            }
            else{//Throw stack empty exception
            }
            return val;
        }

        int getNumCardsLeft(){
            return top;
        }

        void printPile() {
            std::cout << "Pile Contents: ";
            for (int i = 0; i < top; ++i) {
                std::cout << Stack[i]->value << " ";
            }
            std::cout << "\n";
        }
};