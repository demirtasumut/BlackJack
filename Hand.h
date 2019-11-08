//
// Created by Umut on 8.11.2019.
//

#ifndef BLACKJACK_HAND_H
#define BLACKJACK_HAND_H

#include <list>
#include "Card.h"

using namespace std;

class Hand {
private:
    list<Card> cards;
public:
    Hand();

    void resetHand();

    Card getRandomCard();
};


#endif //BLACKJACK_HAND_H
