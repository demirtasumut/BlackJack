//
// Created by Umut on 8.11.2019.
//

#include "Player.h"
#include "Dealer.h"

#define INITIAL_CHIPS 100


Player::Player() {
    chips = INITIAL_CHIPS;
    currentBet = 0;
    status = 0;
    name = "";
    ace = NOACE;
}

void Player::printHand() {
    int handTotal = getHandTotal();

    cout << getName() << " hand: ";
    for (auto &c : hand)
        cout << c->toString() << " ";

    cout << "Total:";

    printHandTotal();

    if (handTotal == BLACKJACK)
        cout << " BlackJack!";
    else if (handTotal > BLACKJACK)
        cout << " You are busted!";
    cout << endl;
}

int Player::getHandTotal() {
    int total = 0;
    ace = NOACE;
    for (auto &c : hand) {
        total += c->getNum();
        if (c->getNum() == 1) {
            ace = GOTACE;
            if (total <= 11 && ace != INCREASED) {
                total += 10;
                ace = INCREASED;
            }
        }

        if (total == BLACKJACK && ace == INCREASED) {
            ace = BJACKEWITHACE;
        }
    }
    if (total > BLACKJACK && ace == INCREASED) {
        total -= 10;
        ace = DECREASED;
    }

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

void Player::printHandTotal() {
    int handTotal = getHandTotal();

    if (ace == INCREASED)
        cout << handTotal - 10 << "/" << handTotal;
    else
        cout << handTotal;
}

void Player::hit(Card *pCard) {
    hand.push_back(pCard);
}

void Player::printResult() {
    switch (status) {
        case -1:
            if (getHandTotal() < BLACKJACK)
                cout << getName() << ", You Lost!" << endl;
            break;
        case 0:
            cout << getName() << ", It is a draw!" << endl;
            break;
        case 1:
            cout << getName() << ", You win!" << endl;
            break;
        default:
            break;
    }
    if (getChipsTotal() == 0) {
        cout << "Sorry " << getName() << ". You are busted!!" << endl;
    }
}

void Player::setResults(int dealerTotal) {


    if (getHandTotal() == BLACKJACK && dealerTotal != BLACKJACK) {    //Blackjack: player wins
        chips += ceil(2.5 * getBet());
        status = 1;
    } else if (getHandTotal() <= BLACKJACK && getHandTotal() == dealerTotal) { // Draw
        chips += getBet();
        status = 0;
    } else if (getHandTotal() < BLACKJACK && getHandTotal() > dealerTotal) {   //player wins
        chips += 2 * getBet();
        status = 1;
    } else if (getHandTotal() > BLACKJACK) {                           // player busted
        status = -1;
    } else if (getHandTotal() < BLACKJACK && dealerTotal > BLACKJACK) {       //dealer busted
        chips += 2 * getBet();
        status = 1;
    } else {
        status = -1;                                            //should not be here!
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
    ace = NOACE;
}

int Player::getBet() {
    return currentBet;
}

void Player::play(Dealer *dealer) {
    char selection;

    if (getHandTotal() >= BLACKJACK)
        return;

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
        } while (getHandTotal() < BLACKJACK && selection != 's' && selection != 'S');
    }
}

void Player::reset() {
    chips = INITIAL_CHIPS;
    currentBet = 0;
    status = 0;
    name = "";
    resetHand();
}

void Player::split() {

}

