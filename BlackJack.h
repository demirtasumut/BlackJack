//
// Created by Umut on 10.11.2019.
//

#ifndef BLACKJACK_BLACKJACK_H
#define BLACKJACK_BLACKJACK_H

#include <iostream>
#include "Dealer.h"


#define MAX_PLAYER_COUNT 7

using namespace std;

class BlackJack {
private:
    Player players[MAX_PLAYER_COUNT];
    Dealer dealer;

    void printGameInfo();
    void game();

public:
    BlackJack();

    void start();

    void test();

    void printPlayersHand(int playerCount);

    void betPlayers(int count);

    void resetPlayers(int playerCount);

    bool checPlayersStatus(int playerCount);

    bool checkForContinue(int playerCount);
};


#endif //BLACKJACK_BLACKJACK_H
