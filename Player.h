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
    int chips;
    int currentBet;
    int total;
protected:
    string name;
    list<Card *> hand;

    void updateChips(int c);
public:
    Player();

    char move(const string &letter);

    int getHandTotal();
    void printHand();

    bool bet(int b);
    bool getResult(int dealerHand);
    void hit(Card *pCard);
    void printResult();

    bool isPlaying();

    void setResults();

    int getChipsTotal();

    string getName();

    void setName(string basicString);
};


#endif //BLACKJACK_PLAYER_H
