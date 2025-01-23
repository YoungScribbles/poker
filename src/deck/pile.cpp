#include "pile.h"

Pile::Pile() {
}

Pile::~Pile() {
}

Card Pile::drawTop() {
    if (mCards.empty()) {
        throw;
    }

    // Remove the top card from the pile and return it
    Card ret = mCards.back();
    mCards.pop_back();
    return ret;
}

Card Pile::drawRandom() {
    if (mCards.empty()) {
        throw;
    }

    // Remove a random card from the pile and return it
    int index = rand() % mCards.size();
    Card ret = mCards[index];
    mCards.erase(mCards.begin() + index);
    return ret;
}

void Pile::placeTop(Card card) {
    mCards.push_back(card);
}

void Pile::placeTop(vector<Card> cards) {
    for (auto card : cards) {
        mCards.push_back(card);
    }
}

void Pile::placeTop(Pile pile) {
    while (!pile.empty()) {
        mCards.push_back(pile.drawTop());
    }
}

void Pile::printCards() {
    // Print the cards in the pile
    for (auto it = mCards.begin(); it != mCards.end(); ++it) {
        (*it).print();
    }
}