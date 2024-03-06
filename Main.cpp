#include "Deck.cpp"
#include "Pile.cpp"

void shuffleDeck(Deck p1, Deck p2);

int main(){
    Deck player;
    Deck computer;

    shuffleDeck(player, computer);
    player.printDeck();
    computer.printDeck();
}

void shuffleDeck(Deck p1, Deck p2){
    int cards[] = {4,4,4,4,4,4,4,4,4,4,4,4,4};
    int index = 0;
    for (int i = 0; i < 31;){
        index = rand() % 13 + 1;
        if (cards[index] != 0){
            p1.Add(cards[index]);
            i++;
        }
    }
    for (int i = 0; i < 31;){
        index = rand() % 13 + 1;
        if (cards[index] != 0){
            p2.Add(cards[index]);
            i++;
        }
    }
}