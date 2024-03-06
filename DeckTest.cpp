#include "Deck.h"
int main(){
    Deck myDeck;

    myDeck.Add(1);
    myDeck.Add(10);
    myDeck.Add(13);
    myDeck.Add(2);
    myDeck.Add(12);
    myDeck.Add(11);
    myDeck.Add(5);
    myDeck.printDeck();
    std::cout << myDeck.Pull();
    myDeck.printDeck();
    std::cout << myDeck.Pull();
    myDeck.printDeck();
    std::cout << myDeck.Pull();
    myDeck.printDeck();
    
}