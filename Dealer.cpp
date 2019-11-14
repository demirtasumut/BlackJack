//
// Created by Umut on 8.11.2019.
//

#include <thread>
#include <chrono>
#include "Dealer.h"

#define DEALER_HIT_LIMIT 17
#define WAIT_DEALER 1

Dealer::Dealer() {
    name = "Dealer";
}

int Dealer::openHand() {

    while (getHandTotal() < DEALER_HIT_LIMIT)
        hand.push_back(deck.getRandomCard());

    chrono::duration<int, std::milli> timespan(WAIT_DEALER * 1000);
    cout << getName() << " hand: ";
    for (auto &c : hand) {
        cout << c->toString() << " " << flush;
        this_thread::sleep_for(timespan);   //make it handsome :)
    }
    cout << "Total: " << getHandTotal();

    if (getHandTotal() == BLACKJACK)
        cout << " BlackJack";

    cout << endl;
    return getHandTotal();
}


Card *Dealer::getCard() {
    return deck.getRandomCard();
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
