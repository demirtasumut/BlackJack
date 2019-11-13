#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BlackJack.h"

using namespace std;

int main() {

    srand(unsigned(time(nullptr)));
    auto *blackJack = new BlackJack();

    blackJack->start();
    delete blackJack;

    return 0;
}