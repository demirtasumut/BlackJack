//
// Created by Umut on 8.11.2019.
//

#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H


enum Type {
    CLUB = 0,
    DIAMONDS,
    HEARTS,
    SPADES,
};

class Card {
private:
    int num;
    enum Type type;

public:
    Card(int, enum Type);

    int getNum();

    int getType();
};


#endif //BLACKJACK_CARD_H
