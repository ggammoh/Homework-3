#ifndef CARD_H
#define CARD_H

class Card{
    public:
        Card *next;
        int value;
        Card(int cardNum) {value = cardNum; next = nullptr;}
};

#endif 
