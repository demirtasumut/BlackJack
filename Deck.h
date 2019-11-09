//
// Created by Umut on 8.11.2019.
//

#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include <list>
#include "Card.h"

using namespace std;

class Deck {
private:
    list<Card> cards;
public:
    Deck();
    void resetHand();
    Card getRandomCard();
};


#endif //BLACKJACK_DECK_H
