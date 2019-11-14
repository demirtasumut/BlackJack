#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BlackJack.h"

using namespace std;

int main() {

    auto *blackJack = new BlackJack();

    blackJack->start();
    delete blackJack;

    return 0;
}