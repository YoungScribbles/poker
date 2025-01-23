
#include <iostream>
#include "card.h"


Card::Card(char s, int v) {
    mSuit = s;
    mValue = v;
}

Card::~Card() {
}

void Card::print() {
    printf("%s of %s\n", val().c_str(), suit().c_str());
}

std::string Card::suit() {
    std::string ret;

    switch (mSuit)
    {
    case 'c':
        ret = "Clubs";
        break;
    case 'd':
        ret = "Diamonds";
        break;
    case 'h':
        ret = "Hearts";
        break;
    case 's':
        ret = "Spades";
        break;
    default:
        ret = "UNKNOWN SUIT";
        break;
    }

    return ret;
}

std::string Card::val() {
    std::string ret;

    switch (mValue)
    {
    case 1:
        ret = "A";
        break;
    case 10:
        ret = "T";
        break;
    case 11:
        ret = "J";
        break;
    case 12:
        ret = "Q";
        break;
    case 13:
        ret = "K";
        break;
    default:
        ret = std::to_string(mValue);
        break;
    }

    return ret;
}