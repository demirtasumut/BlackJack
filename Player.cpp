//
// Created by Umut on 8.11.2019.
//

#include "Player.h"
#include "Dealer.h"

#define INITIAL_CHIPS 100
#define BLACKJACK_LIMIT 21


Player::Player() {
    chips = INITIAL_CHIPS;
    currentBet = 0;
    total = 0;
    status = 0;
    name = "";
}

void Player::printHand() {
    cout << getName() << " hand: ";
    for (auto &c : hand)
        cout << c->toString() << " ";
    cout << "Total:" << getHandTotal();
    if (getHandTotal() == 21)
        cout << " BlackJack!";
    cout << endl;
}

int Player::getHandTotal() {
    total = 0;
    for (auto &c : hand)
        total += c->getNum();

    return total;
}

bool Player::bet(int b) {
    if (getChipsTotal() < b || b <= 0)
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


    setResults(dealerHand);
    printResult();
    resetHand();

    return getChipsTotal() > 0;
}

void Player::hit(Card *pCard) {
    hand.push_back(pCard);
    total += pCard->getNum();
}

void Player::printResult() {
    cout << getName() << " ";
    switch (status) {
        case -1:
            cout << ", You lost!" << endl;
            break;
        case 0:
            cout << ", It is a draw!" << endl;
            break;
        case 1:
            cout << ", You win!" << endl;
            break;
        default:
            break;
    }
    if (getChipsTotal() == 0) {
        cout << "Sorry " << getName() << ". You are busted!!" << endl;
    }
}

void Player::setResults(int dealerTotal) {

    if (dealerTotal > 21) {
        chips += 2 * getBet();
        status = 1;
    } else if (getHandTotal() > 21) {
        status = -1;
    } else if (getHandTotal() == dealerTotal) {
        chips += getBet();
        status = 0;
    } else if (getHandTotal() > dealerTotal) {
        chips += 2 * getBet();
        status = 1;
    } else {
        status = -1;
    }

    currentBet = 0;
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

void Player::resetHand() {
    Card *c;

    for (auto &card : hand) {
        c = card;
        delete c;
    }
    hand.clear();

}

int Player::getBet() {
    return currentBet;
}

void Player::play(Dealer *dealer) {
    char selection;

    if (getChipsTotal() + getBet()) {    //is player still on the game
        do {
            selection = move("hHsS");
            switch (selection) {
                case 'h':
                case 'H':
                    hit(dealer->getCard());
                    printHand();
                    break;
                case 's':
                case 'S':
                    break;
                default:
                    break;
            }
        } while (getHandTotal() < BLACKJACK_LIMIT && selection != 's' && selection != 'S');
    }
}

void Player::reset() {
    chips = INITIAL_CHIPS;
    currentBet = 0;
    total = 0;
    status = 0;
    name = "";
    resetHand();
}

