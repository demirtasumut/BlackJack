//
// Created by Umut on 10.11.2019.
//

#include "BlackJack.h"


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
    int playerCount, selection, dealerHand, bet;
    bool finish = false;
    char pc;
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
        for (int i = 0; i < playerCount; i++) {
            if (players[i].getChipsTotal())  //if player has still chips
                cout << "Hi " << players[i].getName() << "! How much you want to bet? (min 1, max "
                     << players[i].getChipsTotal() << "):";
            cin >> bet;
            while (!players[i].bet(bet)) {
                cout << "Hi " << players[i].getName() << "! You can't bet " << bet << ". Please try again";
                cin >> bet;
            }
        }

        dealer.setCards(players, playerCount);
        dealer.printOneCard();
        for (int i = 0; i < playerCount; i++) {

            players[i].printHand();

            selection = players[i].move("hHsS");
            switch (selection) {
                case 'h':
                case 'H':
                    players[i].hit(dealer.getCard());
                    players[i].printHand();
                    i--;        //it is hit. So the player may want to hit more
                    break;
                case 's':
                case 'S':
                    break;
                default:
                    break;
            }
        }
        dealer.openHand();
        dealerHand = dealer.getHandTotal();
        for (int i = 0; i < playerCount; i++) {
            finish |= players[i].getResult(dealerHand);
            players[i].printResult();
            players[i].setResults();
        }
    } while (finish);

}

void BlackJack::test() {

    dealer.testDealer();

}
