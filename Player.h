//
// Created by Umut on 8.11.2019.
//

#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include <iostream>
#include <list>
#include "Card.h"

#define BLACKJACK 21

enum ACE {
    NOACE = 0,
    GOTACE,
    INCREASED,
    BJACKEWITHACE,
    DECREASED
};

using namespace std;

class Dealer;

class Player {
private:
    int chips;
    int currentBet;
    bool doubled;
protected:
    string name;
    list<Card *> hand;
    int status;
    ACE ace;
public:
    Player();

    char move(const string &letter);

    int getHandTotal();

    void printHand();

    bool bet(int b);

    bool getResult(int dealerHand);

    void hit(Card *pCard);

    void splitHand();

    void doubleDeal();

    void printResult();

    void setResults(int i);

    int getChipsTotal();

    string getName();

    void setName(string n);

    void resetHand();

    int getBet();

    void play(Dealer *dealer);

    void reset();

    void printHandTotal();
};


#endif //BLACKJACK_PLAYER_H
