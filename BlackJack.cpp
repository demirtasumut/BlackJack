//
// Created by Umut on 10.11.2019.
//

#include "BlackJack.h"


BlackJack::BlackJack() = default;

void BlackJack::play() {
    bool repeatGame = true;

    this->printGameInfo();

    do {
        cout << "New Game(N) or Exit(X)" << endl;
        char c = this->readSelection("NnXx");

        switch (c) {
            case 'N':
            case 'n':
                this->game();
                break;
            case 'X':
            case 'x':
                repeatGame = false;
            default:
                break;
        }
    } while (repeatGame);
}

void BlackJack::printGameInfo() {
    cout << "Welcome!" << endl;
    cout << "This is a simple BlackJack Game" << endl;
    cout << "You can play with your friends" << endl;
    cout << "Have fun!!" << endl;
}

char BlackJack::readSelection(const string &letter) {
    string s;
    do {
        cout << "Please Select:" << endl;
        cin >> s;
        if (s.length() > 1
            || s.find_first_not_of(letter) != string::npos
                )
            cout << "Wrong Selection Try again";
        else
            break;
    } while (true);
    return s[0];
}

void BlackJack::game() {
    cout << "How many player you will play?" << endl;
    char pc = this->readSelection("1234567");
    int playerCount = pc - '0', selection, dealerHand;
    bool finish = false;
    do {
        for (int i = 0; i < playerCount; i++) {
            this->players[i].bet();
        }

        this->dealer.setCards(this->players, playerCount);

        for (int i = 0; i < playerCount; i++) {
            if (!players[i].isactive())
                continue;
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
        dealerHand = dealer.getTotal();
        for (int i = 0; i < playerCount; i++) {
            finish |= players[i].getResult(dealerHand);
            players[i].printResult();
            players[i].setActive();
        }
    } while (finish);

}
