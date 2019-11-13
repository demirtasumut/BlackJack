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
                break;
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
    int playerCount, dealerHand = 0;
    bool notFinish = false;
    char selection;
    string name;

    cout << "How many players do want you play? (1-7)" << endl;
    selection = utils::readSelection("1234567");
    playerCount = selection - '0';

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

        if (checPlayersStatus(playerCount))
            dealerHand = dealer.openHand();

        for (int i = 0; i < playerCount; i++) {
            notFinish |= players[i].getResult(dealerHand);
        }
        dealer.resetHand();
        notFinish = checkForContinue(playerCount);


    } while (notFinish);

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
                cin.clear();
                cin.ignore(1);
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

bool BlackJack::checPlayersStatus(int playerCount) {
    bool status = false;
    for (int i = 0; i < playerCount; i++) {
        status |= (players[i].getHandTotal() < 21 && players[i].getHandTotal() > 0);
    }
    return status;
}

bool BlackJack::checkForContinue(int playerCount) {
    bool notFinish = false;
    char selection;

    for (int i = 0; i < playerCount; i++) {
        notFinish |= players[i].getChipsTotal() != 0;
    }
    if (notFinish) {
        cout << "Do you want to continue? (Y/N)" << endl;
        selection = utils::readSelection("yYnN");
        notFinish = !(selection == 'n' || selection == 'N');
    } else {
        cout << "Game over!" << endl;
    }
    return notFinish;
}
