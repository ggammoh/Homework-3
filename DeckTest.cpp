#include "Pile.h"
int main(){
    Pile myPile;
    Card card1 = Card(1);
    Card card2 = Card(2);
    Card card3 = Card(3);
    Card card4 = Card(4);
    Card card5 = Card(5);
    Card card6 = Card(6);
    myPile.push(&card1);
    myPile.push(&card2);
    myPile.push(&card3);
    myPile.push(&card4);
    myPile.push(&card5);
    myPile.push(&card6);
    myPile.printPile();
    std::cout << myPile.pop() << std::endl;
    myPile.printPile();
    std::cout << myPile.pop()<< std::endl;
    myPile.printPile();
    std::cout << myPile.pop()<< std::endl;
    myPile.pop();
    
 }