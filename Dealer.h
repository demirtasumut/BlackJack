//
// Created by Umut on 8.11.2019.
//

#ifndef BLACKJACK_DEALER_H
#define BLACKJACK_DEALER_H


#include "Player.h"
#include "Deck.h"

class Dealer {
private:
    Deck deck;
public:
    void setCards(Player *pPlayer, int playerCount);

    void openHand();

    int getTotal();

    Card *getCard();
};


#endif //BLACKJACK_DEALER_H
