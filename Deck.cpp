//
// Created by Umut on 8.11.2019.
//

#include "Deck.h"

#include <random>

Card *Deck::getRandomCard() {
    Card *c = nullptr;
    if (!cards.empty()) {
        c = cards[cards.size() - 1];
    }
    return c;
}

void Deck::resetHand() {
    Card *c;

    for (auto &card : cards) {
        c = card;
        delete c;
    }
    cards.clear();

    for (int f = HEARTS; f <= SPADES; f++) {
        for (int i = 0; i < 13; i++) {
            c = new Card(i, (Face) f);
            cards.push_back(c);
        }
    }
    shuffle(cards.begin(), cards.end(), std::mt19937(std::random_device()()));
}

Deck::Deck() {
    Card *c;

    for (int f = HEARTS; f <= SPADES; f++) {
        for (int i = 0; i < 13; i++) {
            c = new Card(i, (Face) f);
            cards.push_back(c);
        }
    }
    shuffle(cards.begin(), cards.end(), std::mt19937(std::random_device()()));
}
