//
// Created by Umut on 8.11.2019.
//

#ifndef BLACKJACK_DEALER_H
#define BLACKJACK_DEALER_H


#include "Player.h"
#include "Deck.h"

class Dealer : public Player {
private:
    Deck deck;
public:
    Dealer();

    void setCards(Player *pPlayers, int playerCount);
    void openHand();
    Card *getCard();

    void testDealer();

    void printOneCard();
};


#endif //BLACKJACK_DEALER_H
