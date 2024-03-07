#include "Deck.cpp"
#include "Pile.cpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void shuffleDeck(Deck p1, Deck p2);
void drawCards(Deck& playerDeck, Deck& computerDeck, int& playerCard, int& computerCard);
int compareCards(int playerCard, int computerCard);
int playRound(Deck& playerDeck, Deck& computerDeck);
void handleRound(Deck& playerDeck, Deck& computerDeck, int playerCard, int computerCard);
void determineWinner(Deck& playerDeck, Deck& computerDeck);

int main(){
    srand(time(0));
    Deck player;
    Deck computer;

    shuffleDeck(player, computer);
    player.printDeck();
    computer.printDeck();

    while (!player.isEmpty() && !computer.isEmpty()) {
        int playerDecision;
        std::cout << "Player's turn: Do you want to (1) Push or (2) Pull a card? ";
        std::cin >> playerDecision;

        if (playerDecision == 1) { // push a card
            int playerCard = player.Pull();
            int computerCard = computer.Pull();
            std::cout << "Player's card: " << playerCard << std::endl;
            std::cout << "Computer's card: " << computerCard << std::endl;
            // Determine the winner
            handleRound(player, computer, playerCard, computerCard);
        } else if (playerDecision == 2) { // pull a card
            int playerCard = player.Pull();
            std::cout << "Player's card: " << playerCard << std::endl;
            // Draw a card for the computer
            int computerCard = computer.Pull();
            std::cout << "Computer's card: " << computerCard << std::endl;
            // Determine the winner 
            handleRound(player, computer, playerCard, computerCard);
        } else {
            std::cout << "Invalid choice! Please choose 1 or 2." << std::endl;
            continue;
        }
    }

    determineWinner(player, computer);

    return 0;
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


void drawCards(Deck& p1, Deck& p2, int& p1Card, int& p2Card) {
    p1Card = p1.Pull();
    p2Card = p2.Pull();
}

int compareCards(int p1Card, int p2Card) {
    if (p1Card == p2Card) {
        return 0; // Tie
    } else {
        return p1Card > p2Card ? 1 : -1;
    }
}

int playRound(Deck& p1, Deck& p2) {
    int p1Card, p2Card;
    drawCards(p1, p2, p1Card, p2Card);
    return compareCards(p1Card, p2Card);
}

void handleRound(Deck& player, Deck& computer, int playerCard, int computerCard) {
    int playerTotal = playerCard;
    int computerTotal = computerCard;

    // Check if the player has more than one card in their deck
    if (!player.isEmpty()) {
        std::cout << "Do you want to pull another card? (1) Yes or (2) No: ";
        int pullDecision;
        std::cin >> pullDecision;

        if (pullDecision == 1) { // Player chooses to pull another card
            int additionalCard = player.Pull();
            std::cout << "Player's additional card: " << additionalCard << std::endl;
            playerTotal += additionalCard;
        }
    }

    // Determine the winner of the round
    if (playerTotal > computerTotal) {
        std::cout << "Player 1 wins the round!" << std::endl;
        // Add the cards to the bottom of the player's deck
        player.Add(playerCard);
        player.Add(computerCard);
    } else {
        std::cout << "Player 2 wins the round!" << std::endl;
        // Add the cards to the bottom of the computer's deck
        computer.Add(playerCard);
        computer.Add(computerCard);
    }
}

// Determine the winner of the game
void determineWinner(Deck& player, Deck& computer) {
    if (player.isEmpty() && computer.isEmpty()) {
        std::cout << "The game ends in a tie!" << std::endl;
    } else if (player.isEmpty()) {
        std::cout << "Player 2 wins the game!" << std::endl;
    } else {
        std::cout << "Player 1 wins the game!" << std::endl;
    }
}