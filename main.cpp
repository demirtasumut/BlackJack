#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BlackJack.h"

using namespace std;

int main() {

    srand(unsigned(time(nullptr)));
    auto *blackJack = new BlackJack();

    cout << "Hello, World!" << std::endl;
    blackJack->play();
    delete blackJack;

    return 0;
}