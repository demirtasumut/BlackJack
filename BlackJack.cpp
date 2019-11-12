//
// Created by Umut on 10.11.2019.
//

#include "BlackJack.h"

#define BLACKJACK_LIMIT 21

BlackJack::BlackJack() = default;

void BlackJack::play() {
    bool playGame = true;

    this->printGameInfo();

    do {
        cout << "New Game(N) or Exit(X)" << endl;
        char c = utils::readSelection("NnXxt");

        switch (c) {
            case 'N':
            case 'n':
                this->game();
                break;
            case 'X':
            case 'x':
                playGame = false;
            case 't':
                test();
                break;
            default:
                break;
        }
    } while (playGame);
}

void BlackJack::printGameInfo() {
    cout << "Welcome!" << endl;
    cout << "This is a simple BlackJack Game" << endl;
    cout << "You can play with your friends" << endl;
    cout << "Have fun!!" << endl;
}

void BlackJack::game() {
    int playerCount, dealerHand;
    bool finish = false;
    char pc, selection;
    string name;

    cout << "How many player you will play? (1-7)" << endl;
    pc = utils::readSelection("1234567");
    playerCount = pc - '0';

    for (int i = 0; i < playerCount; i++) {
        cout << "Please enter Player" << i + 1 << " name:";
        cin >> name;
        players[i].setName(name);
    }
    do {

        betPlayers(playerCount);

        dealer.setCards(players, playerCount);
        dealer.printOneCard();

        printPlayersHand(playerCount);

        for (int i = 0; i < playerCount; i++) {
            if (players[i].getChipsTotal() + players[i].getBet()) {    //is player still on the game
                do {
                    selection = players[i].move("hHsS");
                    switch (selection) {
                        case 'h':
                        case 'H':
                            players[i].hit(dealer.getCard());
                            players[i].printHand();
                            break;
                        case 's':
                        case 'S':
                            break;
                        default:
                            break;
                    }
                } while (players[i].getHandTotal() < BLACKJACK_LIMIT && selection != 's' && selection != 'S');
            }
        }
        dealerHand = dealer.openHand();

        for (int i = 0; i < playerCount; i++) {
            finish |= players[i].getResult(dealerHand);
        }
    } while (finish);

}

void BlackJack::test() {

    dealer.testDealer();

}

void BlackJack::printPlayersHand(int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        if (players[i].getChipsTotal() + players[i].getBet())    //is player still on the game
            players[i].printHand();
    }
}

void BlackJack::betPlayers(int playerCount) {
    int bet;

    for (int i = 0; i < playerCount; i++) {
        if (players[i].getChipsTotal()) {  //if player has still chips
            cout << "Hi " << players[i].getName() << "! How much you want to bet? (min 1, max "
                 << players[i].getChipsTotal() << "):";
            cin >> bet;
            while (!players[i].bet(bet)) {
                cout << "Hi " << players[i].getName() << "! You can't bet " << bet << ". Please try again";
                cin >> bet;
            }
            players[i].setBet(bet);
        }
    }
}
