//
// Created by Umut on 8.11.2019.
//

#include "Card.h"

Card::Card(int n, enum Type t) {
    num = n;
    type = t;
}

int Card::getType() {
    return type;
}

int Card::getNum() {
    return num;
}

