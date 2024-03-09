#include "Deck.h"
#include "Pile.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void shuffleDeck(Deck &p1, Deck &p2);
void handleRound(Deck& playerDeck, Deck& computerDeck, int playerCard, int computerCard);
void determineWinner(Deck playerDeck, Deck computerDeck);

int main(){
    srand(time(0));
    int numRounds = 999999;
    int round = 0;
    char styleChoice;
    Deck player;
    Pile playerStack;
    Deck computer;
    shuffleDeck(player, computer);


    cout << "\nWould you like to play for a certain number of rounds? (y/n)";
    cin >> styleChoice;
    if (styleChoice == 'y'){
        cout << "How many rounds would you like to play? \n>";
        cin >> numRounds;
    }
    else return -1;

    
    while (!player.isEmpty() && !computer.isEmpty() && round < numRounds) {
        int playerDecision = 0;
        int playerCard = 0;
        int computerCard = 0;
        int pileCard = 0;
        playerCard = player.Pull();

        std::cout << "The number of cards in Player's deck is: " << player.getNumCards() << "\n";
        std::cout << "The number of cards in Computer's deck is: " << computer.getNumCards() << "\n";

        cout << "------------------------------\n";
        std::cout << "Your Card: " << playerCard << "\n";
        std::cout << "\n1.Play this card \n2.Push to stack \n3.Grab from stack? \n>";
        std::cin >> playerDecision;
        while(playerDecision != 1 && playerDecision != 2 && playerDecision != 3){
            std::cout << "Invalid choice! Please choose 1 or 2 or 3.>" << std::endl;
            std::cin >> playerDecision;
        }

        computerCard = computer.Pull();
        if (playerDecision == 1) { // Play Card
            cout << "------------------------------\n";
            std::cout << "Player's card: " << playerCard << std::endl;
            std::cout << "Computer's card: " << computerCard << std::endl;
            // Determine the winner
            handleRound(player, computer, playerCard, computerCard);

        } else if (playerDecision == 2) { // Push to stack
            cout << "------------------------------\n";
            cout << "You pushed " << playerCard << endl;
            playerStack.push(new Card(playerCard));
            cout << "Size of stack (max 5): " << playerStack.getNumCardsLeft() << endl;
            playerCard = player.Pull();
            std::cout << "Player's new card: " << playerCard << std::endl;
            // Draw a card for the computer
            std::cout << "Computer's card: " << computerCard << std::endl;
            // Determine the winner 
            handleRound(player, computer, playerCard, computerCard);

        } else if(playerDecision == 3) { // Grab from stack
            cout << "------------------------------\n";
            pileCard = playerStack.pop();
            std::cout << "Computer's card: " << computerCard << std::endl;
            if (pileCard != -1){
                cout << "Your new total is: " << playerCard + pileCard<< endl;

                //Special Case of handle round since the player's total is 2 cards
                if (playerCard+pileCard > computerCard) {
                    std::cout << "Player wins the round!" << std::endl;
                    // Add the cards to the bottom of the player's deck
                    player.Add(playerCard);
                    player.Add(pileCard);
                    player.Add(computerCard);
                } else {
                    std::cout << "Computer wins the round!" << std::endl;
                    // Add the cards to the bottom of the computer's deck
                    computer.Add(playerCard);
                    computer.Add(pileCard);
                    computer.Add(computerCard);
                }
            }
            else{
                cout << "Pile empty... continuing as normal\n";

                handleRound(player, computer, playerCard, computerCard);
            }
            
        }
        round++;
    }

    determineWinner(player, computer);

    return 0;
}

void shuffleDeck(Deck &p1, Deck &p2){
    int cards[] = {4,4,4,4,4,4,4,4,4,4,4,4,4};
    int index = 0;
    for (int i = 0; i < 26;){
        index = rand() % 13 + 1;
        if (cards[index-1] != 0){
            if(index == 1){
                p1.Add(index + 14); //Make it so aces have the highest value
            }
            else{p1.Add(index);}
            cards[index-1]--;
            i++;
        }
    }
    for (int i = 0; i < 26;){
        index = rand() % 13 + 1;
        if (cards[index-1] != 0){
            if(index == 1){
                p2.Add(index + 14); //Make it so aces have the highest value
            }
            else{p2.Add(index);}
            cards[index-1]--;
            i++;
        }
    }
}

void handleRound(Deck& player, Deck& computer, int playerCard, int computerCard) {
    int playerTotal = playerCard;
    int computerTotal = computerCard;

    // Determine the winner of the round
    if (playerTotal > computerTotal) {
        std::cout << "########## Player 1 wins the round! ##########" << std::endl;
        // Add the cards to the bottom of the player's deck
        player.Pull();
        computer.Pull();
        player.Add(playerCard);
        player.Add(computerCard);
    } else {
        std::cout << "########## Player 2 wins the round! ##########" << std::endl;
        // Add the cards to the bottom of the computer's deck
        player.Pull();
        computer.Pull();
        computer.Add(playerCard);
        computer.Add(computerCard);
    }
}

// Determine the winner of the game
void determineWinner(Deck player, Deck computer) {
    cout << "------------------------------\n";
    if (player.getNumCards() == computer.getNumCards()) {
        std::cout << "The game ends in a tie!" << std::endl;
    } else if (player.getNumCards() < computer.getNumCards()) {
        std::cout << "Player 2 wins the game!" << std::endl;
    } else {
        std::cout << "Player 1 wins the game!" << std::endl;
    }
    cout << "------------------------------\n";
}