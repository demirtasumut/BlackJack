//
// Created by Umut on 8.11.2019.
//

#include "Card.h"

Card::Card(int n, enum Face t) {
    num = n;
    face = t;
}

int Card::getFace() {
    return face;
}

int Card::getNum() {
    if (num < 11)
        return num;
    else
        return 10;
}

string Card::toString() {
    string s;
    s = this->toStringNum() + this->toStringFace();
    return s;
}

string Card::toStringFace() {

    string s;

    switch (getFace()) {
        case SPADES:
            s = "\xE2\x99\xA0";
            break;
        case CLUB:
            s = "\xE2\x99\xA3";
            break;
        case HEARTS:
            s = "\xE2\x99\xA5";
            break;
        case DIAMONDS:
            s = "\xE2\x99\xA6";
            break;
        default:
            s = "";
            break;
    }
    return s;
}

string Card::toStringNum() {
    string s;
    int num = this->getNum();

    switch (num) {
        case 1:
            s = string("A");
            break;
        case 11:
            s = string("J");
            break;
        case 12:
            s = string("Q");
            break;
        case 13:
            s = string("K");
            break;
        default:
            s = to_string(num);
    }

    return s;
}

