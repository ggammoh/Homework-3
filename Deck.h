#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <iostream>

class Deck{
    private:
        int numCards;
        Card *top;  //Pointer to the top of the deck
        Card *bottom; //Pointer to the bottom of the deck

    public:
        Deck();
        int Pull(); //Pull the card from the top of the deck
        void Add(int cardNum);//Add the won cards to the bottom of the deck

        int getNumCards(); //Returns the number of cards the player has left

        bool isEmpty(); //Return wether or not the player has any card left

        void printDeck();

        void printTop();
};

#endif