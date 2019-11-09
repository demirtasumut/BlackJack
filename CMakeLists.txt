cmake_minimum_required(VERSION 3.15)
project(BlackJack)

set(CMAKE_CXX_STANDARD 11)

add_executable(BlackJack main.cpp Card.cpp Card.h Deck.cpp Deck.h Player.cpp Player.h Dealer.cpp Dealer.h)