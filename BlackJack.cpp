//
// Created by Umut on 10.11.2019.
//

#include "BlackJack.h"


BlackJack::BlackJack() = default;

void BlackJack::start() {
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
    cout << "You can start with your friends" << endl;
    cout << "Have fun!!" << endl;
}

void BlackJack::game() {
    int playerCount, dealerHand;
    bool finish = false;
    char pc;
    string name;

    cout << "How many player you will start? (1-7)" << endl;
    pc = utils::readSelection("1234567");
    playerCount = pc - '0';

    resetPlayers(playerCount);

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
            players[i].play(&dealer);

        }
        dealerHand = dealer.openHand();

        for (int i = 0; i < playerCount; i++) {
            finish |= players[i].getResult(dealerHand);
        }
        dealer.resetHand();
        if (finish) {
            cout << "Do you want to start again?" << endl;
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
        }
    }
}

void BlackJack::resetPlayers(int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        players[i].reset();
    }
}
