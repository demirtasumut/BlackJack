//
// Created by Umut on 8.11.2019.
//

#include "Player.h"

#define INITIAL_CHIPS 100

Player::Player() {
    chips = INITIAL_CHIPS;
    currentBet = 0;
    total = 0;
}

void Player::printHand() {
    cout << getName() << " hand: ";
    for (auto &c : hand)
        cout << c->toString() << " ";
    cout << "Total:" << getHandTotal() << endl;
}

int Player::getHandTotal() {
    total = 0;
    for (auto &c : hand)
        total += c->getNum();

    return total;
}

bool Player::bet(int b) {
    if (getChipsTotal() < b)
        return false;
    currentBet = b;
    chips -= b;
    return true;
}

char Player::move(const string &letter) {
    cout << "Hi " << getName() << "! Hit or Stand? " << endl;
    return utils::readSelection(letter);
}

bool Player::getResult(int dealerHand) {
    return getHandTotal() >= dealerHand;
}

void Player::hit(Card *pCard) {
    hand.push_back(pCard);
    total += pCard->getNum();
}

void Player::printResult() {

}

bool Player::isPlaying() {
    return false;
}

void Player::setResults() {

}

int Player::getChipsTotal() {
    return chips;
}

string Player::getName() {
    return name;
}

void Player::setName(string n) {
    name = n;
}

