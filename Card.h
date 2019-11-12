//
// Created by Umut on 8.11.2019.
//

#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

#include <string>
#include "utils.h"

using namespace std;
enum Face {
    HEARTS = 3,     //kupa
    DIAMONDS,       //karo
    CLUB,           //sinek
    SPADES,         //maca
};

class Card {
private:
    int num;
    enum Face face;

    string toStringFace();
    string toStringNum();
public:
    Card(int, enum Face);

    int getNum();
    int getFace();
    string toString();
};


#endif //BLACKJACK_CARD_H
