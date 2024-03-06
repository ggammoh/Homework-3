/*
Create a side pile class that models a stack using an array. This side pile will have a
maximum of 5 possible cards in the stack. A player cannot peek at what is in their side
pile. A player can add a card to the top or remove a card from the top. This needs a way
to tell the player how many cards they have left but not the other player
*/
#include "Card.h"

class Pile{
    private:
        int top;
        Card *Stack[5];
    public:
        Pile();
        void push(Card *card);
        int pop();
};