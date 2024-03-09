#pragma once
#include "Card.h"
#include <iostream>

class Deck{
    private:
        int numCards;
        Card *top;  //Pointer to the top of the deck
        Card *bottom; //Pointer to the bottom of the deck

    public:
        Deck(){
            numCards = 0;
        }
        int Pull(){ //Pull the card from the top of the deck
            Card *temp = top;
            int val = temp->value;

            top=top->next;

            delete temp;
            numCards--;

            return val;
        }
        void Add(int cardNum){//Add the won cards to the bottom of the deck
            Card* temp = new Card(cardNum);
            if(isEmpty()){
                top = bottom = temp;
                numCards++;
                return;
            }
            bottom->next = temp;
            bottom = temp;
            numCards++;
        }  
        int getNumCards(){ //Returns the number of cards the player has left
            return numCards;
        }
        bool isEmpty(){ //Return wether or not the player has any card left
            return numCards<=0;
        }
        void printDeck(){
            Card *temp = top;
            while (temp != nullptr) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << "\n";
        }
        void printTop(){
            int rtnval = top->value;
            std::cout << rtnval;
        }
};
