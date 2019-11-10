//
// Created by Umut on 8.11.2019.
//

#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include <iostream>
#include <list>
#include "Card.h"

using namespace std;

class Player {
private:
    list<Card *> hand;
    int chips;
    int currentBet;
    int total;

    void updateChips(int c);
public:
    Player();

    int move(const string &letter);
    int getTotal();
    void printHand();

    void bet();

    bool getResult(int dealerHand);

    void hit(Card *pCard);

    void printResult();

    bool isactive();

    void setActive();
};


#endif //BLACKJACK_PLAYER_H
