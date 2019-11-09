//
// Created by Umut on 8.11.2019.
//

#include "Player.h"


void Player::printHand() {
    auto c = hand.begin();
    for (; c != hand.end(); c++)
        cout << c->toString() << " ";

}
