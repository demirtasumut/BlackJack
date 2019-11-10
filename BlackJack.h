//
// Created by Umut on 10.11.2019.
//

#ifndef BLACKJACK_BLACKJACK_H
#define BLACKJACK_BLACKJACK_H

#include <iostream>
#include "Player.h"
#include "Dealer.h"
#include "Deck.h"

#define MAX_PLAYER_COUNT 7

using namespace std;

class BlackJack {
private:
    Player players[MAX_PLAYER_COUNT];
    Dealer dealer;


    void printGameInfo();

    char readSelection(const string &letter);

    void game();

public:
    BlackJack();

    void play();
};


#endif //BLACKJACK_BLACKJACK_H
