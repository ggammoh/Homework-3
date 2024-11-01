#include "Deck.h"

Deck::Deck(){
    numCards = 0;
}

void Deck::Add(int cardNum){
    if(isEmpty()){
        top = new Card(cardNum);
        bottom = top;
        numCards++;
        return;
    }
    Card* temp = new Card(cardNum);
    temp->next = bottom;
    bottom = temp;
    numCards++;
}

int Deck::Pull(){
    if(isEmpty()){
        return -1;
    }
    int val = top->value;
    Card *temp = bottom;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete top;
    top = temp;
    top->next=nullptr;
    numCards--;
    return val;
}

int Deck::getNumCards(){
    return numCards;
}

bool Deck::isEmpty(){
    return numCards<=0;
}

void Deck::printDeck(){
    Card *temp = bottom;
    std::cout << std::endl;
    std::cout << temp->value << " ";
    while(temp->next != nullptr){
        temp = temp->next;
        std::cout << temp->value << " ";
    }
    std::cout << std::endl;
}

void Deck::printTop(){
    int rtnval = top->value;
    std::cout << rtnval;
}
