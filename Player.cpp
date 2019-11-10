//
// Created by Umut on 8.11.2019.
//

#include "Player.h"

#define INITIAL_CHIPS 100

void Player::printHand() {

    for (auto &c : hand)
        cout << c->toString() << " ";

}

Player::Player() {
    chips = INITIAL_CHIPS;
    currentBet = 0;
    total = 0;
}

int Player::getTotal() {
    int total = 0;
    for (auto &c : hand)
        total += c->getNum();

    return total;
}

void Player::bet() {

}

int Player::move(const string &letter) {
    (void) letter;
    return 0;
}

bool Player::getResult(int dealerHand) {
    return getTotal() >= dealerHand;
}

void Player::hit(Card *pCard) {
    (void) pCard;
}

void Player::printResult() {

}

bool Player::isactive() {
    return false;
}

void Player::setActive() {

}
