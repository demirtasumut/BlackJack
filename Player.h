//
// Created by Umut on 8.11.2019.
//

#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include <list>
#include "Card.h"

using namespace std;

class Player {
private:
    list<Card> hand;
public:
    void play();

    int getTotal();

    void printHand();
};


#endif //BLACKJACK_PLAYER_H
