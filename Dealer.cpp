//
// Created by Umut on 8.11.2019.
//

#include "Dealer.h"


Dealer::Dealer() {
    name = "Dealer";
}

void Dealer::openHand() {

}


Card *Dealer::getCard() {
    return nullptr;
}

void Dealer::setCards(Player *players, int playerCount) {

    for (int i = 0; i < playerCount; i++) {
        players[i].hit(deck.getRandomCard());
        players[i].hit(deck.getRandomCard());
    }
    hand.push_back(deck.getRandomCard());
    hand.push_back(deck.getRandomCard());
}

void Dealer::testDealer() {
    deck.testDeck();
}

void Dealer::printOneCard() {

    auto c = hand.begin();
    cout << getName() << " hand: ";
    cout << (*c)->toString() << " ??" << endl;

}
